//-----------------------------------------------------------------------------
// ZEOPManager.h
// Диспетчер параметров вращения Земли (Eath orientation parameters - EOP)
//
//-----------------------------------------------------------------------------
// Диспетчер ПВЗ объект который создаётся только однажды полсле загузки 
// библиотеки модели движения. Все объекты модели ZMSC обращаются к одному 
// и тому же объекту ZEOPManager.
// Любому объекту модели движения, так же как и любой прикладной программе 
// доступна глобальная переменная ZEOPManager EOPMng. 
//
// А. Николенко 06.03.2019
//-----------------------------------------------------------------------------
#ifndef _ZEOPMANAGER_H
#define _ZEOPMANAGER_H

// Имя файла внешнего источника данных ПВЗ - публикуется IERS
#define EOP_IERS_FILE_NAME		"IERS_EOP2000A.txt"
// Имя файла-хранилища ПВЗ в двоичном виде 
#define EOP_STORAGE_FILE_NAME	"FlyEOP.bin"
//
#define MOD_PX_STORAGE_FILE_NAME		"StoragModelPolusX.bin"
#define MOD_PY_STORAGE_FILE_NAME		"StoragModelPolusY.bin"
#define MOD_UT1UTC_STORAGE_FILE_NAME	"StoragModelUTC1mUTC.bin"

#include <FlyTime.h>	// Всё про время

//-----------------------------------------------------------------------------
// Структура одной записи массива ПВЗ
struct ZEOPItem {
	float MJD ;		// Модифицырованная юлианская дата
	float Xp ;		// Координаты полюса в угловых милисекундах
	float Yp ;		//
	float UT1mUTC ;	// UT1-UTC в милисекундах
	// Данные ПВЗ имеют тип float а не double всвязи с тем что, в публикуемых
	// Международной службой вращения Земли файлах, данные параметры имеют
	// недостаточное для числа double колличество значащих цифр
};

// вектор - контейнер для хранения оперативного массива ПВЗ
// Загружается из хранилища ПВЗ (хранилище в двоичном виде)
typedef vector<ZEOPItem> VZEOPItem ;  

class FLYCORE_API ZEOPManager {
public:
	ZEOPManager() ;
	~ZEOPManager() ;

	//----------------------------------------------------------------------------
	// Загрузка апостериорных данных из внешненго истояника
	// Под апостериорными данными понимаются данные публикуемые
	// IERS (уклонение полюса X,Y в угловых милисекундах 
	// и разность UTC1-UTC в милисекундах)
	int  LoadFromIersFormat(bool isNeedSaveToBin=false) ;
	int  LoadFromBin();
	int  Load();
	// Проверка загружена ли априорная информация
	bool IsLoadStorage();
	// Удаление всех данных из оперативного массива (из оперативной памяти)
	void Clear() ;
	// Табличные ПВЗ на заданную модифицированную юлианскую дату
	ZEOPItem& getItemEOP(long Mjd);

	// Построить и сохранить в хранилище множество алгебраических моделей
	// по данным ПВЗ загруженным из внешнего источника в виде дискретной функции
	// Множество моделей строится для интравала заданного атомным временем.
	int MakeAllEopModels(double fromTa, double toTa);
	struct {
		// Структура отчёта о создании локальных алгебраических моделей ПВЗ 
		// по данным из оперативного массива ПВЗ. Если создания моделей не 
		// проводилось то данный отчёт содержит нулевые данные.
		double fromTaNeed;	// Интервал атомного времени на котором необходимо 
		double toTaNeed;	// создать вектор локальных моделей
		double fromTa;		// Интервал атомного времени на котором были 
		double toTa;		// созданы локальные модели
		int	   Count;		// Колличество созданных моделей
		long   Duration;	// Длительность процесса создания в милисекундах
		int    ExitCode;	// Код завершения - ошибка, если всё Ок, то равен 0 
	} EopModelBuildReport;	

	//----------------------------------------------------------------------------
	// Имя файла-архива с параметрами вращения Земли, полученными из
	// внешнего источника

	// Файл в формате IERS - длинное имя файла вместе с каталогом его размещения
	const char* GetIersFileName(const char* notDefaultFileName=nullptr) {		
		IersFileName = DIRINFO;
		IersFileName+= "\\";
		IersFileName+= EOP_IERS_FILE_NAME;
		return IersFileName.c_str();
	}

	// Двоичный формат файла для быстрой загрузки - длинное имя файла 
	// вместе с каталогом его размещения
	const char* GetBinaryFileName() {	
		StorageFileName = DIRINFO;
		StorageFileName+= "\\";
		StorageFileName+= EOP_STORAGE_FILE_NAME;
		return StorageFileName.c_str();
	}

	//----------------------------------------------------------------------------
	// Вычисление ПВЗ либо методом интерполяции по загруженным
	// апостериорным данным, либо по построенной прогностической модели.
	int  Calc(double t, ZEOPItem& P, TIMESCALE Scale = DEFTIME_SCALE);

	// Вычисление параметров прогностической модели по загруженным данным.
	int  BuildForecast(double toTime, TIMESCALE Scale=DEFTIME_SCALE) ;

	// Если априорные данные не загружены, то все 
	// три функции GetTimeXXX возвращают нулевое значение
	// Время начала даннных ПВЗ - время начала таблицы априорных данных
	double GetTimeFirst(TIMESCALE Scale=DEFTIME_SCALE ) ;

	// Время конца даннных ПВЗ - время до которого построена прогностическая
	// модель или время конца таблицы априорных данных, если прогностическая
	// модель не построена
	double GetTimeLast(TIMESCALE Scale=DEFTIME_SCALE ) ;

	// Время конца таблицы априорных данных
	double GetTimeTable(TIMESCALE Scale=DEFTIME_SCALE ) ;

protected:
	// Прогнозирование ПВЗ, применение прогностической модели.
	int Forecast(double t, TIMESCALE Scale=DEFTIME_SCALE) ;

	char* SkipSpace(char* s) ;
	char* SkipToSpace(char* s) ;

	bool  IsForecastBuild ;
	float TimeTableFirst ; 
	float TimeTableLast ; 
	float TimeForecastTo ; 
	float MJDTableFirst ;
	float MJDTableLast ;

	// Оперативный массив с параметрами вращения Земли.
	VZEOPItem EOP ;
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

	// Владелец локальных моделей (алгебраических моделей ПВЗ)
	ZCAlgebraicMdfHolder PxModelHolder;
	ZCAlgebraicMdfHolder PyModelHolder;
	ZCAlgebraicMdfHolder DTModelHolder;

	int    lastFindTableIndex ;
	float  lastFindMJDLeft ;
	float  lastFindMJDRight ;
	double LastFindIAT ;

	// Имя файла внешнего источника данных ПВЗ - публикуется IERS
	string IersFileName;
	// Имя файла-хранилища ПВЗ в двоичном виде 
	string StorageFileName;
} ;

//-----------------------------------------------------------------------------
// Глобальный диспетчер параметров вращения Земли.
// Позволяет любому компоненту любой прикладной программы, загрузившей
// и использующей ядро модели движения FlyCore получить доступ к параметрам 
// вращения Земли. То есть: 
//		- загружать данные параметры из архива, 
//		- строить локальные апроксимирующие модели 
//		  и вести католог данных моделей,
//		- вычислять актуальные значения ПВЗ для заданного момента времени.
FLYCORE_API extern ZEOPManager EOPMng;

//-----------------------------------------------------------------------------
#endif _ZEOPMANAGER_H