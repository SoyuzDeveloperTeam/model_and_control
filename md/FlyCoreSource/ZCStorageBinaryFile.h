//-----------------------------------------------------------------------------
// ZCStorageBinaryFile.h
// Бинарный файл-хранилище ПВЗ
//
// А. Николенко 04.05.2019
//-----------------------------------------------------------------------------
#ifndef _ZCEOP_BINARY_FILE_H
#define _ZCEOP_BINARY_FILE_H

//-----------------------------------------------------------------------------
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

//-----------------------------------------------------------------------------
// Год начиная с которого осуществляется оценка точности прогноза
// ПВЗ, публикуемого IERS
#define EOP_IERS_EST_ORIGIN_Y			2019
// Имя файла-хранилища ПВЗ в двоичном виде 
#define EOP_STORAGE_FILE_NAME			"FlyEopStorage"
// Имя файла-хранилища только прогнозируемых ПВЗ в двоичном виде
#define EOP_PREDICT_FILE_NAME			"FlyEopPredict"
// Имя файла-хранилища оценок точности прогнозирования ПВЗ
#define EOP_ESTIMATE_FILE_NAME			"FlyEopEstimate"
// Имя файла-хранилища локальных алг-х моделей отклонения UTC1-UTC
#define EOP_UTC1UTC_FILE_NAME			"FlyUtc1UtcLocalMod"
// Имя файла-хранилища локальных алг-х моделей координат полюса
#define EOP_PXY_FILE_NAME				"FlyPXYLocalMod"

// Колличество лет за которые сохраняется информация о ПВЗ
// в одном файле бинарного хранилища ПВЗ
#define EOP_STORAGE_FILE_DURATION		10
// Год начиная с которой в бинарном
// хранилище ПВЗ сохраняются данные о ПВЗ.
#define EOP_STORAGE_ORIGIN_Y			1980

//-----------------------------------------------------------------------------
// Структура одной записи массива ПВЗ
struct ZSEopItem {
	float MJD = 0;		// Модифицырованная юлианская дата
	float Xp = 0;		// Координаты полюса в угловых милисекундах
	float Yp = 0;		//
	float UT1mUTC = 0;	// UT1-UTC в милисекундах
	// Данные ПВЗ имеют тип float а не double всвязи с тем что, в публикуемых
	// Международной службой вращения Земли файлах, данные параметры имеют
	// недостаточное для числа double колличество значащих цифр
	char  key = 0;		// Признак достоверности записи:
	//		0 - данные отсутствуют
	//		1 - данные загружены из апосториорного массива данных IERS
	//		2 - результаты прогнозирования IERS
	//		3 - результаты прогнозирования по упрощённой модели
	// Размет структур данного типа
	static int Size;
};

// вектор - контейнер для хранения оперативного массива ПВЗ
// Загружается из хранилища ПВЗ (хранилище в двоичном виде)
typedef vector<ZSEopItem> VZSEop;

//-----------------------------------------------------------------------------
// Частная (или локальная) алгебраическая модель одного параметра в виде
// алгебраического полинома 12-й степени от времени. Время отсчитывается в
// юлианских днях от даты MJD.
struct ZSLocAlgMod {
	float MJD = 0;			// Дата начала частной модели
	float A[13];			// Коэффициенты
	char  PredictPoints = 0;// Число прогнозных точек использованных для
	// создания модели
	// Размет структур данного типа
	static int Size;
};

//-----------------------------------------------------------------------------
// Частная (или локальная) алгебраическая модель двух связанных параметров 
// в виде алгебраических полиномов 12-й степени от времени. Время отсчитывается
// в юлианских днях от даты MJD.
struct ZSLocAlg2Mod {
	float MJD = 0;			// 
	float A[13];			// Коэффициенты первого полинома
	float B[13];			// Коэффициенты второго полинома
	char  PredictPoints = 0;// 
	// Размет структур данного типа
	static int Size;
};

//-----------------------------------------------------------------------------
class ZCStorageBinaryFile {
public:
	ZCStorageBinaryFile();
	~ZCStorageBinaryFile();

	void Close();

	// Двоичный формат файла для быстрой загрузки - длинное имя файла 
	// вместе с каталогом его размещения
	// Type:
	//		0: хранилище ПВЗ
	//		1: хранилище прогнозируемых ПВЗ
	//		2: оценка качества прогнозирования ПВЗ
	// i -  номер файла хранилища, зависит от MJD начала хранимого
	//      массива ПВЗ
	const char* GetBinaryFileName(int i = 0, char Type = 0);

	// Открытие/создание файла-хранилища с номером NumFile и 
	// типом Type. Дата начала массива ПВЗ - fromMJD. 
	int Open(int   NumFile  = 0, 
			 char  Type     = 0, 
			 float fromMJD  = 0, 
			 int   ItemSize = 17);

	// Чтение записи о ПВЗ на дату I.MJD
	// Если данные в хранилище есть и они прочитаны то возвращяется true,
	// иначе - false.
	bool operator >> (void* const I) ;

	// Запись ПВЗ в хранилище для даты I.MJD
	ZCStorageBinaryFile& operator << (const void* I);

	// Размер хранилища в байтах
	unsigned long GetFSize() const;
	// Размер хранилища в байтах
	unsigned long GetISize() const;
	// Колличество записей в хранилище
	unsigned long GetCountItems() const;
	// Имя файла-хранилища
	const char*   GetFileName() const;

	// Разиер одной записи хранилища
	//static unsigned int ZSEopItemSize;

private:
	// Запись countItems нулевых структур с ПВЗ в конец файла File
	void  WriteEmptyEopItems(int addCountItems);
	// Извлечение Юлианской даты по адресу записи
	float GetItemMjd(void* I) const;

	fstream File;
	string  FullName;
	char    NumFileInStorage;
	char*	IMemory;
	unsigned long FSize;
	unsigned long CountItems;
	unsigned long Mjd0;
	unsigned long ISize;
};

//-----------------------------------------------------------------------------
class ZCEopIersBinFile : public ZCStorageBinaryFile {
public:
	// Открытие/создание файла-хранилища с номером NumFile. 
	// Дата начала массива ПВЗ - fromMJD. 
	int Open(int NumFile = 0, float fromMJD = 0){
		return (ZCStorageBinaryFile::Open(NumFile, 0, fromMJD, ZSEopItem::Size));
	}
	bool operator >> (ZSEopItem& I) {
		return(*((ZCStorageBinaryFile*)this) >> &I);

	}
	ZCEopIersBinFile& operator << (ZSEopItem& I) {
		*((ZCStorageBinaryFile*)this) << &I;
		return *this;
	}
};

//-----------------------------------------------------------------------------
class ZCEopPredictBinFile : public ZCEopIersBinFile {
public:
	// Открытие/создание файла-хранилища с номером NumFile. 
	// Дата начала массива ПВЗ - fromMJD. 
	int Open(int NumFile = 0, float fromMJD = 0){
		return (ZCStorageBinaryFile::Open(NumFile, 1, fromMJD, ZSEopItem::Size));
	}
};

//-----------------------------------------------------------------------------
class ZCEopEstimateBinFile : public ZCEopIersBinFile {
public:
	// Открытие/создание файла-хранилища с номером NumFile. 
	// Дата начала массива ПВЗ - fromMJD. 
	int Open(int NumFile = 0, float fromMJD = 0){
		return (ZCStorageBinaryFile::Open(NumFile, 2, fromMJD, ZSEopItem::Size));
	}
};

class ZCPxyModBinFile : public ZCStorageBinaryFile {
public:
	// Открытие/создание файла-хранилища с номером NumFile. 
	// Дата начала массива ПВЗ - fromMJD. 
	int Open(int NumFile = 0, float fromMJD = 0){
		return (ZCStorageBinaryFile::Open(NumFile, 3, fromMJD, ZSLocAlg2Mod::Size));
	}
	bool operator >> (ZSLocAlg2Mod& I) {
		return(*((ZCStorageBinaryFile*)this) >> &I);

	}
	ZCPxyModBinFile& operator << (ZSLocAlg2Mod& I) {
		*((ZCStorageBinaryFile*)this) << &I;
		return *this;
	}
};

class ZCUtc1ModBinFile : public ZCStorageBinaryFile {
public:
	// Открытие/создание файла-хранилища с номером NumFile. 
	// Дата начала массива ПВЗ - fromMJD. 
	int Open(int NumFile = 0, float fromMJD = 0){
		return (ZCStorageBinaryFile::Open(NumFile, 4, fromMJD, ZSLocAlgMod::Size));
	}
	bool operator >> (ZSLocAlgMod& I) {
		return(*((ZCStorageBinaryFile*)this) >> &I);

	}
	ZCUtc1ModBinFile& operator << (ZSLocAlgMod& I) {
		*((ZCStorageBinaryFile*)this) << &I;
		return *this;
	}
};

//-----------------------------------------------------------------------------
#endif // #ifndef _ZCEOP_BINARY_FILE_H

