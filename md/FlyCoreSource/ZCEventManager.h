//-------------------------------------------------------------------------------
// ZCEventManager.h
// А. Николенко 03.08.2018
//------------------------------------------------------------------------------- 
#ifndef ModEventManager_H
#define ModEventManager_H

#include <FlyCoreSource\\ZNIP.h>

// Максимальное колличество событий модели движения
#define COUNT_ModEvents		100
// Начало пользовательских событий
#define ID_USEREVENT_FIRST	100

// Ксласс модели КА
class  ZMSC ;
// Структура параметров движения - результатов моделирования движения 
// посредством класса ZModKA
struct ZSC_SI ;

//------------------------------------------------------------------------------- 
// Возможные события, наступление которых отслеживавет модель движения
//------------------------------------------------------------------------------- 
enum ModEventName{
	ModEvent_EMPTY = 0,				// Признак отсутствия события ---> отсутствия расчёта параметров	 
	ModEvent_INIT = 1,				// Инициализация МД
	ModEvent_STEP = 2,				// Выполнен один шаг интегрирования	 
	ModEvent_BKSTEP = 3,			// Отшагивание в пределах витка для уточнения чего либо

	ModEvent_DUON = 4,				// 	 
	ModEvent_DUSTEPON = 5,			// 	 
	ModEvent_DUOFF = 6,				// 	 

	ModEvent_VITVU = 7,				// Восходящий узел витка	 
	ModEvent_VITNU = 8,				// Нисходящий узел витка
	ModEvent_HMIN = 9,				// Минимальная высота
	ModEvent_HMAX = 10,				// Максимальная высота
	ModEvent_RMIN = 11,				// Минимальный радиус
	ModEvent_RMAX = 12,				// Максимальный радиус
	ModEvent_SHADOWBEG = 13,		// Начало тени
	ModEvent_SHADOWEND = 14,		// Конец тени

	ModEvent_ONBREAKTIME = 15,		// Достигнут предельный момент времени заданный параметром notFurtherTime в функции GoStepA
	ModEvent_ONTIME = 16,			// Выполнено прогнозирование до витка
	ModEvent_ONVIT = 17,			// Выполнено прогнозирование до заданного момента времени
	ModEvent_ONARG = 18,			// Выполнено прогнозирование до заданного аргумента широты

	ModEvent_ZRVBEG = 100,			// Начало ЗРВ
	ModEvent_ZRVEND = 101,			// Конец ЗРВ
	ModEvent_ZRVPARAM = 102			// Момент прохождения параметра ЗРВ
};

#define ModEvent_BEG ModEvent_VITVU
#define ModEvent_END ModEvent_RMAX

//------------------------------------------------------------------------------- 
// Проверка типа события 
//------------------------------------------------------------------------------- 
// Является ли событие событием Зоны Радиовидимости (засечки характерных точек ЗРВ)
FLYCORE_API bool IsZRVEvent(ModEventName e);
// Является ли событие событием витка (засечки характерных точек витка)
FLYCORE_API bool IsVITEvent(ModEventName e);
// Является ли событие событием подшагивания
FLYCORE_API bool IsGOEvent(ModEventName e);
// Является ли событие событием моделирования работы двигательной установки
FLYCORE_API bool IsDUEvent(ModEventName e);
//
FLYCORE_API bool IsUserEvent(ModEventName e);
//
FLYCORE_API bool IsModEvent(ModEventName e);

// Идентификатор события ЗРВ (начало, конец или параметр)
FLYCORE_API int IDZRVEvent(ModEventName e);
// Индекс НИПа по событию ЗРВ
FLYCORE_API int IndNipZRVEvent(ModEventName e);

//------------------------------------------------------------------------------- 
// Характеристики события 
typedef struct ZMOD_EVENT {
ModEventName	ID ;		// Имя события
double			ta ;		// Время события, атомное в ссс   
double			Value ;		// Числовые характеристики события, для большинства 
double			Value2 ;	// событий не имеют смысла ==> имеют нулевые значения
double			Value3 ;	//
double			Value4 ;	//
long			Value5 ;	//
} _ZMOD_EVENT ;				// 

//------------------------------------------------------------------------------- 
// Контейнер для хранения пошаговых признаков наступления событий
class FLYCORE_API ZCEventCase {
public:
	ZCEventCase() {
		Ipz = nullptr ;
		Ppz = nullptr ; Cpz = nullptr ;
		Ptz = nullptr ; Ctz = nullptr ;
		NI  = nullptr ;
		ZRV = nullptr ;
		CntNip = 0 ; 
		isNeedTestZRV = false;
		isNeedTestVit = false ;
	} ;

	~ZCEventCase() {
		CompletZRV() ;
	} ;

	void PreTest() {
		timep = timet ;

		memcpy(Pp, Pt, sizeof(Pt)) ;
		memcpy(Cp, Ct, sizeof(Ct)) ;
		memset(Ip, 0,  sizeof(Ip)) ;
		memset(ie, 0,  sizeof(ie)) ;

		if (CntNip>0) {
			memcpy(Ppz, Ptz, 3*CntNip*sizeof(double)) ;
			memcpy(Cpz, Ctz, 3*CntNip*sizeof(double)) ;
			memset(Ipz, 0,   3*CntNip*sizeof(bool)) ;
		}
	}

	// Определение необходимости отслеживания чобытий ЗРВ
	// Если диспетчеру указан перечень НИП, то значит
	// отслеживать ЗРВ нужно
	bool IsNeedTrackingZRV() { return CntNip>0 ? true:false ; }
	int  CountNips() { return CntNip ; } 
	int  INips(int i) { return NI[i] ; }

	// Запуск контроля событий витка
	// Завершается контроль событий витка автоматически при 
	// выходе на момент начала следующего витка
	void RunUpVit() {
		FinalityVit() ;
		// Активирование функции автоматического отслеживания событий 
		// витка и при необходимости (то есть при обнаружении 
		// в пределах шага) уточнения данных событий
		isNeedTestVit = true ;
	} ;
	// Обнуление всех переменных диспетчера событий, отвечающих
	// за отслеживание событий витка.
	void FinalityVit() {
		memset(Ip, 0, sizeof(Ip)) ;
		memset(Pp, 0, sizeof(Pp)) ;
		memset(Cp, 0, sizeof(Cp)) ;
		timep = 0 ;
		memset(Pt, 0, sizeof(Pt)) ;
		memset(Ct, 0, sizeof(Ct)) ;
		timet = 0 ;
		memset(ie, 0, sizeof(ie)) ;
		// Блоуирование функции автоматического отслеживания событий 
		// витка и при необходимости (то есть при обнаружении 
		// в пределах шага) уточнения данных событий
		isNeedTestVit = false ;
	} ;
	// Запуск контроля событий ЗРВ
	//	CountNip	- колличество контролируемых НИПов
	//	NipIndexes	- индексы НИПов в массиве характеристик и 
	//				  координат НИПов 
	int RunUpZRV(int CountNip, int* NipIndexes) {
		CntNip = CountNip ;
		Ipz = new bool  [3*CntNip] ; if (!Ipz) return-1 ; 
		Ppz = new double[3*CntNip] ; if (!Ppz) return-1 ; 
		Cpz = new double[3*CntNip] ; if (!Cpz) return-1 ; 
		Ptz = new double[3*CntNip] ; if (!Ptz) return-1 ; 
		Ctz = new double[3*CntNip] ; if (!Ctz) return-1 ; 
		NI  = new int   [CntNip] ;   if (!NI ) return-1 ; 
		ZRV = new ZZRV  [CntNip] ;   if (!ZRV ) return-1 ;  
		memset(Ipz, 0, 3*CntNip*sizeof(bool)) ;
		memset(Ppz, 0, 3*CntNip*sizeof(double)) ;
		memset(Cpz, 0, 3*CntNip*sizeof(double)) ;
		memset(Ptz, 0, 3*CntNip*sizeof(double)) ;
		memset(Ctz, 0, 3*CntNip*sizeof(double)) ;
		memcpy(NI, NipIndexes, CntNip*sizeof(int)) ;
		memset(ZRV, 0, CntNip*sizeof(ZZRV)) ;
		isNeedTestZRV = true ;
		return 0 ;
	} ;
	// Обнуление всех переменных диспетчера событий, отвечающих
	// за отслеживание событий ЗРВ.
	void FinalityZRV() {
		CntNip = 0 ;
		delete[] Ipz ; Ipz = nullptr ;
		delete[] Ppz ; Ppz = nullptr ;
		delete[] Cpz ; Cpz = nullptr ;
		delete[] Ptz ; Ptz = nullptr ;
		delete[] Ctz ; Ctz = nullptr ;
		delete[] NI  ; NI  = nullptr ;
		delete[] ZRV ; ZRV = nullptr ;
		// Блоуирование функции автоматического отслеживания событий 
		// ЗРВ и при необходимости (то есть при обнаружении 
		// в пределах шага) уточнения данных событий
		isNeedTestZRV = false ;
	} ;
	// Завершенние контроля событий ЗРВ
	void CompletZRV() {
		if (Ipz) { delete[] Ipz ; Ipz = nullptr ; }
		if (Ppz) { delete[] Ppz ; Ppz = nullptr ; }
		if (Cpz) { delete[] Cpz ; Cpz = nullptr ; }
		if (Ptz) { delete[] Ptz ; Ptz = nullptr ; }
		if (Ctz) { delete[] Ctz ; Ctz = nullptr ; }
		if (NI ) { delete[] NI ;  NI  = nullptr ; }
		if (ZRV) { delete[] ZRV;  ZRV = nullptr ; }
		CntNip = 0 ;
	} ;

	bool&   IP(int i) { return (i<COUNT_ModEvents ? Ip[i]:Ipz[i-COUNT_ModEvents]) ; }
	double& PP(int i) { return (i<COUNT_ModEvents ? Pp[i]:Ppz[i-COUNT_ModEvents]) ; }
	double& CP(int i) { return (i<COUNT_ModEvents ? Cp[i]:Cpz[i-COUNT_ModEvents]) ; }
	double& PT(int i) { return (i<COUNT_ModEvents ? Pt[i]:Ptz[i-COUNT_ModEvents]) ; }
	double& CT(int i) { return (i<COUNT_ModEvents ? Ct[i]:Ctz[i-COUNT_ModEvents]) ; }

//private:
protected:
	// Признак необходимости отсчлеживания наступления событий ЗРВ
	bool isNeedTestZRV ;
	// Признак необходимости отсчлеживания наступления событий витка
	bool isNeedTestVit ;

	// Данные событий модели движения
	// Признак вычисленного параметра
	bool   Ip[COUNT_ModEvents] ;
	// Дополнительный параметр, контролируемый параметр на предыдущем шаге
	double Pp[COUNT_ModEvents] ;
	double Cp[COUNT_ModEvents] ;
	// Дополнительный параметр, контролируемый на текущем шаге
	double Pt[COUNT_ModEvents] ;
	double Ct[COUNT_ModEvents] ;

	// Данные событий ЗРВ
	// Индексы НИПов в массиве структур, описывающих 
	// координаты и характеристики НИПов.
	int*    NI ;
	// Колличество НИПов
	int     CntNip ;
	// Признак вычисленного параметра
	bool*   Ipz ;
	// Дополнительный параметр, контролируемый параметр на предыдущем шаге
	double* Ppz ;
	double* Cpz ;
	// Дополнительный параметр, контролируемый на текущем шаге
	double* Ptz ;
	double* Ctz ;

protected:
	// Время на предыдущем шаге
	double timep ;
	// Время на текущем шаге
	double timet ;

	// Найденные события на текущем шаге - время, индекс и числовое значение 
	// каждого найденного события.
	// В эти массивы записываются события как модели движения так и события ЗРВ
	ModEventName ie[COUNT_ModEvents] ;	// индекс события 
//	double		 te[COUNT_ModEvents] ;	// время события
	// Общее число найденных событий
	//int	CountFound ; 	

public:
	ZZRV* ZRV ;
} ;

//------------------------------------------------------------------------------- 
class FLYCORE_API ZCEventManager : public ZCEventCase {
public:
	ZCEventManager();
	~ZCEventManager();

	// Проверка факта наступления события на текущем шаге
	int TestEvents(ZMSC* KA, ZSC_SI* SI=nullptr) ;
	// Вычисление значения контролируемых параметров
	int CalcParams(ZMSC* KA, ZSC_SI* SI=nullptr, int indPar=-1, double* P=nullptr, double* D=nullptr) ;

protected:
	// Уточнение события
	int  ClarifyEvent(ZMSC* KA, ModEventName indEvent, ZSC_SI* SI, double* ddh=nullptr) ;
	void PutVITParam (int indI, double Pc, double Dc, int indC, double* P, double* D) ;
	// Проверка, уточнение и архивирование событий ЗРВ
	int  TestZRV     (ZMSC* KA, ZSC_SI& SI, int& i, int& j) ;
	void PostFindZRV (ZMSC* KA, ZSC_SI& SI, ZZRV* Z) ;
} ;

#endif // ModEventManager_H