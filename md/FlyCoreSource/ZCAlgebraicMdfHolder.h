//-----------------------------------------------------------------------------
// ZCAlgebraicMdfHolder.h
// А. Николенко 01.04.2019
//
// Владелец коллекции локальных алгебраических моделей 
// апроксимирующих дискретно функцию, заданную набором значений аргумента 
// и самой функции.
//-----------------------------------------------------------------------------
#ifndef ZC_ALGEBRAIC_MDF_MANAGER_H
#define ZC_ALGEBRAIC_MDF_MANAGER_H

class ZCAlgebraicModDF;

typedef struct ZSStorageEOPHeaderItem {
	double			MJD;
	unsigned long	shiftData;
} _ZSStorageEOPHeaderItem ;

class FLYCORE_API ZCAlgebraicMdfHolder {
public:
	ZCAlgebraicMdfHolder() {
		CI = -1;
		ItVM = VM.end();
		TimeFrame = 93;
		TimeFrameType = 1;
		TimeFrameMargin = 2;
		StorageName = "AprMod.bin";
	}

	~ZCAlgebraicMdfHolder() {
		VM.clear();
	}

	//-------------------------------------------------------------------------
	// Поиск среди загруженных модели актуальной для момента времени t 
	int FindMod(double t, ZCAlgebraicMDF* MS, ZCAlgebraicMDF* MC = nullptr);
	// Поиск в коллекции моделей (в оперативном массиве локальных моделей)
	int FindModInCollection(double t, ZCAlgebraicMDF* MC=nullptr);
	// Поиск в хранеилище (долгосрочном архиве локальных моделей - файл или БД)
	//		MS - модель найденная в хранилище
	//		MC - модель найденная в коллекции
	int FindModInStorage(double t, ZCAlgebraicMDF* MS);

	//-------------------------------------------------------------------------
	// Создание новой полиномиальной модели по значениям дискретной функции
	// Значения дискретной функции получаются посредством метода
	// LoadDFfromTime
	//int NewMod(double t);
	// Непосредственная генерация апроксимирующей модели - 
	// вычисление коэффициэнтов полинома Чебышёва
	int BuildNewMod(double* T, double* Y, int N);

	//-------------------------------------------------------------------------
	// Вычисления значения текущей полиномиальной модели
	int Calc(double t, double& F);
	int Calc(double t, float& F);

	//-------------------------------------------------------------------------
	// Методы загрузки значений дискретной функции
	//-------------------------------------------------------------------------
	//virtual int LoadDFfromTime(double fromTime, double toTime,
	//						   double** T, double** Y, int& N);

	//-------------------------------------------------------------------------
	// Методы обмена полиномиальными моделями с хранилищем моделей
	//-------------------------------------------------------------------------

	// Сохранить в хранилище все созданные или загруженные ранее 
	// локальные модели
	int SaveToStorage(vector<ZCAlgebraicMDF>* LVM=nullptr);

	// Обновить хранилище моделей новыми сгенерированными моделями.
	// Модели, имеющие признак isGenerated равный true будут помещены в
	// хранилище локальных моделей.
	int UpdateStorage(vector<ZCAlgebraicMDF>* LVM = nullptr, 
					  bool LikeMove=false);

	// Загрузить из хранилища все имеющиеся там полиномиальные модели
	int LoadFromStorage(vector<ZCAlgebraicMDF>* LVM = nullptr);

	// Загрузить из хранилища полиномиальную модель актуальную 
	// для времени fromTime 
	int LoadFromStorage(double fromTime);

	// Загрузить из хранилища одну или несколько полиномиальных  
	// моделей актуальных для интервала времени 
	// от fromTime до toTime.
	int LoadFromStorage(double fromTime, double toTime);

	// Имя файла-хранилища
	void SetStorageName(const char* Name) { StorageName = Name; }
	const char* GetStorageName() { return StorageName.c_str(); }
	const char* GetFileStorageName() { 
		StorageFileName = DIRINFO;
		StorageFileName+= "\\";
		StorageFileName+= StorageName;
		return StorageFileName.c_str();
	}

	// Длинна тайм-фрейма - область определения создаваемых локальных
	// полиномиальных моделей.
	void SetTimeFrameType(char TFT) { 
		TimeFrameType = TFT; 
		switch (TFT) {
		case 0: TimeFrame = 32; break;
		case 1: TimeFrame = 93; break;
		case 2: TimeFrame = 186; break;
		case 3: TimeFrame = 367; break;
		default: assert(0);
		}
	}
	char GetTimeFrameType() { return TimeFrameType; }
	long GetTimeFrame() { return TimeFrame; }

	// Вычисление момента начала тайм фрейма содержащего момент времени t,
	// заданный модифицированной юлианской датой, если fromMjd=true, или
	// атомным временем если fromMjd=false. 
	double FindTimeFrameBeg(double t, bool fromMjd = false);

protected:
	// Текущий индекс актульной полиномиальной модели
	int CI;
	// Массив полиномиальных моделей
	vector<ZCAlgebraicMDF> VM;
	// Итератор текущей полиномиальной модели
	vector<ZCAlgebraicMDF>::iterator ItVM;

	// Длительность временного фрейма на котором будет определена каждая
	// полиномиальная модель.
	long TimeFrame;
	char TimeFrameType;
	// Поля Тайм фрейма для исключения погрешностей на краях фрейма.
	long TimeFrameMargin;
	// Имя файла-хранилища ПВЗ в двоичном виде 
	string StorageName;
	string StorageFileName;
};

//-----------------------------------------------------------------------------
#endif // #ifndef ZC_ALGEBRAIC_MDF_MANAGER_H