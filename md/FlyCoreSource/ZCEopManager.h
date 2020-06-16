//-----------------------------------------------------------------------------
// ZCEopManager.h
// Диспетчер параметров вращения Земли (Eath orientation parameters - EOP)
//
//-----------------------------------------------------------------------------
// Диспетчер ПВЗ объект который создаётся только однажды полсле загузки 
// библиотеки модели движения. Все объекты модели ZMSC обращаются к одному 
// и тому же объекту ZCEopManager.
// Любому объекту модели движения, так же как и любой прикладной программе 
// доступна глобальная переменная ZCEopManager CEopMng. 
//
// А. Николенко 01.05.2019
//-----------------------------------------------------------------------------
#ifndef _ZCEOPMANAGER_H
#define _ZCEOPMANAGER_H

// Имя файла внешнего источника данных ПВЗ - публикуется IERS
#define EOP_IERS_FILE_NAME				"IERS_EOP2000A"
// Колличество файлов бинарного хранилища ПВЗ
#define EOP_STORAGE_FILE_COUNT			8
//
#define MOD_PX_STORAGE_FILE_NAME		"StoragModelPolusX.bin"
#define MOD_PY_STORAGE_FILE_NAME		"StoragModelPolusY.bin"
#define MOD_UT1UTC_STORAGE_FILE_NAME	"StoragModelUTC1mUTC.bin"

#include <FlyTime.h>	// Всё про время

//-----------------------------------------------------------------------------
// Структура одной записи заголовка массива частных моделей
struct ZSEopModHeaderItem {
	float MJD;		// Модифицырованная юлианская дата
	int   ShiftMod;	// Смещение начала данных частной модели от начала файла 
	char  State;	// Состояние частной модели
					//		0 - Модель отсутствует
					//		1 - Модель создана по апосткриорным данным 
					//		2 - Модель создана по пронозируемым данным
					//		3 - Модель простейшего прогноза
};

// вектор - контейнер для хранения оперативного массива ПВЗ
// Загружается из хранилища ПВЗ (хранилище в двоичном виде)
typedef vector<ZSEopModHeaderItem> VZSEopModHeader;

//-----------------------------------------------------------------------------
// Структура алгебраической модели
struct ZSAlgLocalMod {
	float MJD;		// Модифицырованная юлианская дата начала модели
	float Days;		// Интервал моделирования
	float A[13];	// Коэффициенты модели 
};

struct ZSEopItem;

class FLYCORE_API ZCEopManager {
public:
	ZCEopManager();
	~ZCEopManager();

	void Clear();

	//----------------------------------------------------------------------------
	// Загрузка апостериорных данных из внешненго истояника
	// Под апостериорными данными понимаются данные публикуемые
	// IERS (уклонение полюса X,Y в угловых милисекундах 
	// и разность UTC1-UTC в милисекундах)
	int ZCEopManager::LoadFromIersFormat(
		// Загружать данные IERS из этого файла
		char* SpecifiedIersFile,
		// Необходимость оценки точности предыдущего прогноза
		bool isNeedVaracitiPredictEst,
		// Сохранять загруженные данные в виде сокращённого текстового формата
		bool isNeedSaveAsShortTxt,
		// Необходимость построения по полученным данным частных алг. моделей
		bool isNeedBuilModels);

	struct {
		// Структура отчёта о загрузке оперативного массива EOP 
		// из внешнего источника в формате IERS или из двоичного хранилища.
		// Если загрузки не было то данный отчёт содержит нулевые данные.
		char source;		// 0 - IERS, 1 - хранилище
		long fromMjd;		// MJD первой записи
		long toMjd;			// MJD последней записи
		long CountItems;	// Колличество загруженных записей
		long Duration;		// Длительность загрузки в милисекундах
		int  ExitCode;		// Код завершения процедуры загрузки, по простому 
	} EopLoadReport;		// говоря ошибка, если всё Ок, то равен 0 

	//----------------------------------------------------------------------------
	int  LoadFromBin();
	
	int  PutHeaderItemToStorage(ZSEopModHeaderItem& I);
	int  PutModToStorage(ZSEopModHeaderItem& I, ZSAlgLocalMod& M);

	//----------------------------------------------------------------------------
	// Преобразование календарной даты и структурированного времени UTC
	// в модифицированную юлианскую дату.
	static int UtcToMjd(DATETIMEUTC& UTC, float& Mjd);
	static int MjdToUtc(float& Mjd, DATETIMEUTC& UTC);

	//static int ZSEopItemSize;

protected:
	int   DecodeIersString(char* S, ZSEopItem* I);
	char* SkipSpace  (char* s);
	char* SkipToSpace(char* s);

	//----------------------------------------------------------------------------
	// Имя файла-архива с параметрами вращения Земли, полученными из
	// внешнего источника

	// Файл в формате IERS - длинное имя файла вместе с каталогом его размещения
	const char* GetIersFileName(const char* notDefaultFileName = nullptr) {
		if (notDefaultFileName && notDefaultFileName[1] == ':') {
			IersFileName = notDefaultFileName;
		}
		else {
			IersFileName = DIRIERSEOP;
			IersFileName += "\\";
			if (notDefaultFileName) IersFileName += notDefaultFileName;
			else {
				IersFileName += EOP_IERS_FILE_NAME;
				IersFileName += ".txt";
		}	}
		return IersFileName.c_str();
	}

	int GetNumBinFile(double Mjd, int j0=0) {
		int j;
		if (Mjd >= MjdF[j0]) {
			for (j = j0; j < EOP_STORAGE_FILE_COUNT - 1; ++j){
				if (Mjd >= MjdF[j] && Mjd < MjdF[j + 1]) break;
			}
		} else {
			if (!j0) return-1;
			for (j = j0; j > 0; --j){
				if (Mjd >= MjdF[j-1] && Mjd < MjdF[j]) break;
			}
			--j;
		}
		return j;
	}

	// Имя файла внешнего источника данных ПВЗ - публикуется IERS
	// Данные о ПВЗ публикуемые IERS можно загрузить по адресу
	// ftp://ftp.iers.org/products/eop/rapid/standard/finals2000A.all
	// ftp://ftp.iers.org/products/eop/rapid/standard/finals2000A.data
	// ftp://ftp.iers.org/products/eop/rapid/standard/finals.data
	// ftp://ftp.iers.org/products/eop/rapid/standard/finals.all
	// ftp://ftp.iers.org/products/eop/rapid/standard/gpsrapid.out
	// ftp://ftp.iers.org/products/eop/rapid/daily/finals2000A.daily
	// ftp://ftp.iers.org/products/eop/rapid/daily/finals.daily

	string IersFileName;

	// MJD начала бинарных файлов с ПВЗ
	// Один файл с ПВЗ содержит данные о ПВЗ за 10 лет
	float MjdF[EOP_STORAGE_FILE_COUNT];
	// MJD начала оценки точности прогнозирования ПВЗ IERS
	float MjdEstEopPredict;
};

//-----------------------------------------------------------------------------
// Глобальный диспетчер параметров вращения Земли.
// Позволяет любому компоненту любой прикладной программы, загрузившей
// и использующей ядро модели движения FlyCore получить доступ к параметрам 
// вращения Земли. То есть: 
//		- загружать данные параметры из архива, 
//		- строить локальные апроксимирующие модели 
//		  и вести католог данных моделей,
//		- вычислять актуальные значения ПВЗ для заданного момента времени.
FLYCORE_API extern ZCEopManager CEopMng;

//-----------------------------------------------------------------------------
#endif _ZEOPMANAGER_H