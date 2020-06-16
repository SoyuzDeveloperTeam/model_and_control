//-------------------------------------------------------------------------------
// ZCIntegrator.h
// А. Николенко 03.08.2018
//-------------------------------------------------------------------------------
#ifndef CLASS_ZINTEGRATOR_H
#define CLASS_ZINTEGRATOR_H

//-------------------------------------------------------------------------------
#include <FlyCoreSource\\ZCMemoryKeeper.h>
#include <FlyCoreSource\\ZCExternalEquations.h>

//-------------------------------------------------------------------------------
#define  ID_AILER    1
#define  ID_RUNGE_4  4
#define  ID_RUNGE_8  8
#define  ID_ADAMS_4  104
#define  ID_ADAMS_5  105
#define  ID_ADAMS_6  106
#define  ID_ADAMS_8  108
#define  ID_ADAMS_10 110

//-------------------------------------------------------------------------------
#define  F_RUNA_AUTOSTEP   1
#define  F_RUNA_NOTMAXSTEP 2
#define  F_RUNA_USEBREAK   4
#define  MAX_ADAMS_N	   10

//-------------------------------------------------------------------------------
struct IntegratorCreateStruct {
int    n ;				// Число интегрируемых уравнений
int    RungeType ;		// Вариант метода Рунге-Кутта
int    AdamsType ;		// Вариант метода Адамса
double step ;			// Шаг интегрирования начальный, сек
double step_min ;		// Шаг интегрирования минимальный, сек
double step_max ;		// Шаг интегрирования максимальный, сек 
double step_eps ;		// Точность для выбора шага интегрирования (РК) 
double fixed_step ;		// Величина фиксированного шага, сек, если >0, то разгон отсутствует и интегрирование ведётся с постоянным шагом 
long   flag ;			//
void*  data ;			//
int ( *sph )        ( double*, double*, void* SphData ) ;
int ( *user_break ) ( double*, double* ) ;
int  arg_index ;		// Индекс независимой переменной в векторе состояния 
};

//-------------------------------------------------------------------------------
class FLYCORE_API ZCIntegrator : public ZCExternalEquations, public ZCMemoryKeeper {
public:
	ZCIntegrator(IntegratorCreateStruct* cs = nullptr);
	ZCIntegrator(ZCIntegrator&);
	~ZCIntegrator();

	// Создать, удалить интегратор и проверить корректность создания
    int   Create   ( IntegratorCreateStruct&, double* v = nullptr ) ;
	void  Delete   ( ) ;
    int   IsOkCreate  (void) ;

	// Доступ к текущим значениям вектора фазовых координат
	// x - [время, X, Y, Z, Vx, Vy, Vz, m]
	virtual void  GetVector   (double* x);
	// Доступ к текущим значениям вектора фазовых координат
	// x - [X, Y, Z, Vx, Vy, Vz]
    virtual void  GetVector   (double& t, double* x, double* m=nullptr) ;
	// Доступ к текущим значениям дополнительных переменных интегрируемых
	// посредством внешних уравнений (вертикальное расширение модели).
	virtual void  GetVectorExe(double* x);
	// Задать значения текущего вектора состояния
	virtual int   SetVector   (double* x);
    virtual int   SetVector   (double t, double* x, double m) ;
	// Задать значения дополнительных переменных
	virtual int   SetVectorExe(double* x);

	// Определить текущеее направление интегрирования СДУ
	// 1 - вперёд, -1 - назад
    int   GetDirect   (void) ;
	//  Задать направление интегрирования СДУ
    void  SetDirect   (int) ;

	// Установить состояние интегратора требующее "переразгона"
	// метода Адамса на ближайшем шаге интегрирования СДУ
    void  SetStart    (double start_step=0) ;
	// Задать шаг интегрирования для ближайшего шага.
	// Если используется метод интегрирования с автоматическим 
	// выбором шага, то данный шаг в соответствии с требованиями 
	// точности решения задачи КОши будет уменьшаться или увеличиваться.
    void  SetStep     (double) ;
	// Определить текущий шаг интергрирования, минимальный и максимальный 
	// шаг для процедуры автоматического выбора шага
    void  SetStep     (double, double, double) ;
	// Задать автоматический выбор шага
	// autostep - true	- шаг автоматически выбирается
	//			  false	- шаг постоянный
	void  SetAutoStep (bool autostep=true);

    void  SetEpsd     (double) ;
    void  SetData     (void*) ;
    void  SetType     (int) ;
    void  SetSph      (int(*)(double*, double*, void* SphData)) ;
    void  SetUserBreak(int(*)(double*, double*)) ;

	//---------------------------------------------------------------------------
	// Шаг заданной длинны
    int StepAdjusted( double step, double* dq = nullptr ) ;
	// Шаг выбираемый автоматически
    int StepSelf( double* dq = nullptr ) ;
	// Интегрирование до заданного значения аргумента (времени)
    int GoToArg( double ) ;

	//---------------------------------------------------------------------------
	ZCIntegrator& operator = (double*);
	ZCIntegrator& operator = (ZCIntegrator&);
	// Доступ к компонентам интегрируемого вектора (текущие значения)
	operator double* ( ) { return m_a ; }
	double& operator []( int    i ) ;
	double& operator []( short  i ) ;
	double& operator []( long   i ) ;
	double& operator []( float  i ) ;
	double& operator []( double i ) ;

public:
	// Процедура вычисления правых частей СДУ
	//		x - вектор фазовых координат t, X, ...Vz, m и плюс дополнительные
	//		    переменные (вертикальное расширение модели).
	//		y - вектор производных всех переменных
	//		    y[0] = 1 !!!! всегда
	//		    y[1] = Vx
	//			. . . . . . . 
	//		    y[6] = ax
	//		    y[7] = ms
	//		    y[8] = . . . начиная с этого элемента производные внешних 
	//				   переменных	  
    virtual int Sph( double* x, double* y ) { if (m_cs.sph) m_cs.sph( x, y, m_cs.data ) ; return 0 ; } ;
	// Задать пользовательскую callback функцию, которая в частности позволяет 
	// прервать вычислительный процесс если вернёт 1. 
    virtual int UserBreak( double* x, double* y ) { return ( m_cs.user_break ? m_cs.user_break( x, y ) : 0 ) ; }
	// "Включить" интегрирование внешних уравнений.
	// NU - вектор начальных условий внешних переменных для текущего момента времени.
	virtual void ExternalEquationsOn (double* NU=nullptr) {
		// "Включаем" внешние уравнения
		ZCExternalEquations::ExternalEquationsOn(NU) ;
		// Копируем НУ для внешних уравнений в конец интегрируемого вектора
		memcpy(&m_a[m_n], NUexe, GetExternalEquationsCount()*sizeof(double)) ;
		// Обнуляем счётчик разгонных групп интегрирования
		CountGI = 0 ;
	}
	void LockBreak  ( ) { m_IsLockBreak = 1 ; }
	void UnlockBreak( ) { m_IsLockBreak = 0 ; }

	// Число интегрируемых уравнений
	// Число уравнений вместе со внешними уравнениями - 
	// с уравнениями "вертикального расширения модели"
	// Если вертикальное расширение модели отсутствует то возвращается
	// число базовых интегрируемых уравнений, то есть 8,
	// в противном случае - 8 + число внешних (дополнительных уравнений)
	int NE() { return (m_n+(IsExtEqOn()?GetExternalEquationsCount():0)) ; }
	// Число базовых уравнений.
	// Таких уравнений всегда будет 8, по крайней мере до тех пор пока
	// не изменится реализация интегратора.
	// Уравнения:
	//		0		- время (правая часть просто равна 1)
	//		1, 2, 3	- декартовые координаты X, Y, Z
	//		4, 5, 6	- скорости Vx, Vy, Vz
	//		7		- уравнение для массы, на активном участке
	//				  правая часть уравнения равна секундному расходу,
	//				  на пассивном участке - 0.
	// Если подойти принципиально к вопросу оптимизации программы по
	// быстродействию, то время и массу можно вывести из состава
	// интегрируемых переменных. Однако это потребует усложнения логики
	// программного кода интегратора
	// !!!! Итак данная функция всегда вернёт число 8 !!!!
	int NM() { return (m_n) ; }

	// Принудительный переразгон методов интегрирования
	void Restart() { CountGI = 0 ; } ;
	bool IsRestart () { return(CountGI>0?false:true) ; } 
	bool IsStarting() { 
		if (m_cs.AdamsType>0) return(CountGI<AdmN?true:false) ; 
		else return false ; 
	} 

private:
	// Для одношаговых методов
    int   CreateRK  ( ) ;
    int   IsOkData  (IntegratorCreateStruct& ) ;
	// Проверка корректности шага интегрирования, проверка на соответствие 
	// максимальному и минимальному шагу
    void  ValiStep  (double&) ;
	// Один шаг интегратора методом Эйлера 
    void  Step1     (double*, double*) ;
	// Один шаг интегратора методом Рунге-Кутта 4-го порядка
    void  StepRK4   (double*, double*, double step=0, bool SkipStepSelectiom=false) ;
	// Один шаг интегратора методом Рунге-Кутта 8-го порядка
    void  StepRK8   (double*, double*, double step=0, bool SkipStepSelectiom=false)  ;
	// Вычисление нового нага в методе Рунге-Кутта 8-го порядка в случае
	// интегрирования с переменным шагом
    void  NewStepRK8(double*, double*, double*, double&, double, double&);
	// Для метода Адамса
    int  CreateAdm  ( ) ;
public:
	// Вычисление коэффициентов метода интегрирования СДУ Адамса заданного
	// порядка (N)
	//		Kpredict - коэффициенты предиктора,
	//		Kcorrect - коэффициенты корректора,
	// ну или интерполяции и экстраполяции если вам угодно.
	void CalcAdamsI (int n, double* k, double& I) ;
	void CalcAdamsKf(int N, double* Kpredict, double* Kcorrect) ;
	// Один шаг метода адамса, пока реализуется только метод адамса 8-го порядка
	// но ограничений на использование 5-го, 10-го или 12-го порядка нет.
	// Коэффициэнты любого порядка вычисляются при помощи функции CalcAdamsKf
	void StepAdams  (double* dq) ;

	// Правые части
	int SphExe( double* x, double* y ) { 
		// Расчёт правых частей ДУ модели движения
		int rc = Sph(x, y) ; if (rc) return rc ; 	
		//-----------------------------------------------------------------------
		// Расчет ПЧ дополнительных "пользовательских" ДУ
		if (!rc && IsExtEqOn()) {
			Xexe = &x[m_n] ; Yexe = &y[m_n] ;
			// Реализация интегрирования "внешних" дифференциальных уравнений
			// Если в классе производном от модели движения перегружена данная функция
			// то она будет вызвана, что даст возможность рассчёта правых частей "внешних" ДУ 
			rc = ExternalSph(x[0], &x[1], Xexe, Yexe) ; if (rc) return rc ; 	
			// Реализация моделирования "внешних" возмущающих факторов
			// Если в классе производном от модели движения перегружена данная функция
			// то она будет вызвана, что даст возможность учёта "внешних" возмущающих факторов 
			// Соответствующие поправки в производные параметров движения добавляются (+=)
			// в вектор y.
			int N = NE() ;
			rc = ExternalForces(x[0], &x[1], &y[1], N-1) ; if (rc) return rc ; 	 
		} else { Xexe = Yexe = nullptr ; } 
		return rc ;   
	}   

public:
    IntegratorCreateStruct m_cs ;
	int      m_n ;			// Число интегрируемых уравнений
	int      m_N ;			// Число интегрируемых уравнений вместе с дополнительными
	double*  m_a ;			// Интегрируемый вектор 
    double   m_step ;		// Текущий шаг интегрирования	 
    int      m_ok_nu ;		//
	int      m_IsLockBreak ;//
    double   m_up ;			//

private:
	// Массивы и переменные метода РК
    double   m_eps  ;	// Параметры точности для автоматического выбора
    double   m_eps2 ;	// шага в методе РК8
    double*  m_x ;		// Промежуточное решение для РК
    double** m_d ;		// Промежуточное ПЧ для РК
    int      m_ns ;		// Размер буфера m_d под промежуточные правые части в одношаговых методах

	// Массивы и переменные метода Адамса
	double AdmStep ;	// Текущий шаг метода Адамса
	double AdmStepMax ;	// Максимальный шаг метода Адамса	
	double AdmStepMin ;	// Минимальный шаг метода Адамса - он же шаг разгона
	double AdmEps1 ;	// Допустимые точности для принятия решения об удвоении или делении шага  
	double AdmEps2 ;
	int    AdmN ;		// Корлличество узлов в методе Адамса
	int	   CountGI ;	// Колличество рассчитанных ПЧ - групп интегрирования

	double  Kpredict[MAX_ADAMS_N] ;	// Коэффициенты предиктора  
	double  Kcorrect[MAX_ADAMS_N] ;	// Коэффициенты корректора

protected: 
	bool    m_IsWasStepCutDown ;
	double* GI[2*MAX_ADAMS_N+1] ;	// Группы интегрирования
} ;

//-------------------------------------------------------------------------------
#endif
