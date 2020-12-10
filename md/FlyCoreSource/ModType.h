//------------------------------------------------------------------------
// ModType.h
// А. Николенко 03.08.2018
//------------------------------------------------------------------------
#pragma warning(disable:4786)
//------------------------------------------------------------------------
#include <windows.h>
//------------------------------------------------------------------------
#include <math.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <iterator>

//------------------------------------------------------------------------
using namespace std ;
#include "md/FlyCoreSource/ZCDU.h"
#include "md/FlyCoreSource/ZSK.h"

//------------------------------------------------------------------------
#ifndef MODTYPE_H
#define MODTYPE_H

//------------------------------------------------------------------------
// События модели движения
//------------------------------------------------------------------------
#define   MMSG_TDU_ON			1	   // Включение ДУ
#define   MMSG_TDU_STEPON		2	   // Включение ДУ
#define   MMSG_TDU_STEPOFF		4	   // Включение ДУ
#define   MMSG_TDU_OFF			8	   // Выключение ДУ
#define   MMSG_ON_KA_LIGHT		16	   // Начала освещённого участка полёта
#define   MMSG_OFF_KA_LIGHT		32	   // Начало теневого участка полёта
#define   MMSG_INIT_NU		 	64	   // Прошла иницилизация НУ 
#define   MMSG_SET_VECTOR		128	   // Задание нового вектора НУ (переразгон)
#define   MMSG_START			256	   // Начало прогнозирования параметров движения
#define   MMSG_SAVE				512	   // Сохранение текущего состояния модели
#define   MMSG_STEP				1024   // Выполнен шаг интегрирования СДУ движения
#define   MMSG_VITOK			2048   // Начат новый виток
#define   MMSG_RESTORY			4096   // Восстановление состояние модели движения по ранее сохранённым параметрам движения
#define   MMSG_END				8192   // Завершение прогнозирования параметров движения
#define   MMSG_EVENTFIND		16384  // Обнаружено событие МД
#define   MMSG_USEREVENTFIND	32768  // Обнаружено событие МД 
#define   MMSG_USER_1			65536  // 
#define   MMSG_USER_2			131072 // 
#define   MMSG_USER_3			264144 // 
#define   MMSG_USER_4			524288 // 
#define   MMSG_USER_5			1048576// 
//------------------------------------------------------------------------
// Коды ответа
//------------------------------------------------------------------------
#define   RC_OK			0
#define   RC_CANCEL		-1
#define   RC_USEREXIT	50
#define   RC_OUTMEM		999
#define   RC_COUNTITER	900
//#define   RC_
//#define   RC_
//#define   RC_
//#define   RC_
//#define   RC_
//#define   RC_
//#define   RC_
//#define   RC_
//------------------------------------------------------------------------
// Системы топогеодезической привязки
//----------------------------------------------------------------------------
#define    _SKT_GSK       0  // Параметры Земли 1990 года (ПЗ-90)
#define    _SKT_OZE       1  // Общеземной эллипсоид
#define    _SKT_EKR       2  // Эллипсоид Красовского
#define    _SKT_G_K       3  // Система Гаусса-Крюгера
#define    _SKT_ITRF      4  // ITRF
#define    _SKT_WGS84     5  // WGS-84
#define    _SKT_NEU       6  // North East Up
#define    _SKT_GSK_2     7  // ПЗ-90.2

//------------------------------------------------------------------------
// Версии моделей гравитационного поля Земли
// Модели ГПЗ     отсутствует 85 года, 90 года, ПЗ 90.11,  EGM 96 года, EGM 08 года
enum VersionGPZ  {GPZNULL =0, 
				  GPZ85=1, GPZ90=2, GPZ9011=3, 
				  GPZEGM96=4, GPZEGM2008=5,
				  GPZGEMT3=6, GPZJGM3=7};
// Версии моделей атмосферы
enum VersionATM  {// Статические модели
				  ATMNULL =0, ATMSMA62=1, ATMSMA81=2, ATMSMA440181=3,
				  // Динамические модели ГОСТ 25645.115-... различных годов
				  ATMDMAGOST1977=4, ATMDMAGOST1984=5, ATMDMAGOST1990=6, ATMDMAGOST2001=7, ATMDMAGOST2004=8,
				  // MSIS
				  ATMMSIS1990=9, ATMMSIS2000=10} ;
// Версии моделей учёта океанических приливов в разложении гравитационного поля Земли
enum VersionTide {TIDENULL=0, TIDESTEP2=1, TIDEPOSEIDON=2} ;

//------------------------------------------------------------------------
// Логическая шкала сил, значение по умолчанию.
// ОБЬЯВИТЬ ПРИ ИНИЦИАЛИЗАЦИИ!!!
typedef struct ZLSF {
	int			num;//  = 0;			// Номер шкалы
	VersionGPZ	vgpz;// = GPZ90;		// вариант ГПЗ
	int			ngpz;// = 4;			// N разложения ГПЗ
	int			mgpz;// = 4;			// M разложения ГПЗ
	VersionATM	vatm;// = ATMSMA81;    // вариант атмосферы
	int			varsp;//= 0;			//
	int			vsvd;// = 0;			// Вариант светового давления
	VersionTide vTide;//= TIDESTEP2;	// учёт приливных эффектов
	bool		isDU;// = false;		// учёт двигательной установки
	bool		isSun;// = true;       // учёт Солнца
	bool		isMoon;// = true;      // учёт Луны
	bool		isPlanet[8];		// учёт планет
	ZLSF(int n=0) {
		num = n;
		memset(isPlanet, 0, 8*sizeof(bool)); // учёт планет
	}
	bool IsPlanet() { 
		for(bool b : isPlanet) if (b) return true;
		return false; 
	}
} _ZLSF ;

//------------------------------------------------------------------------
typedef struct ZKEYNU {
	ZKEYNU() { ka=nom=mod=type=bc=0 ; }
	ZKEYNU(int _ka, int _nom, int _mod, int _type, int _bc) { ka=_ka; nom=_nom; mod=_mod; type=_type; bc=_bc; }
	int ka ;
	int nom ;
	int mod ; 
	int type ;
	int bc ;
} _ZKEYNU ;

//------------------------------------------------------------------------
typedef struct ZNU {
	ZKEYNU   Key ;    // ключи НУ
	int      numlsf ; // номер ЛШС
	SK_TYPE  sk ;     // ноиер системы координат
	long     vit ;    // виток
	double   t ;      // время, ссс
	double   M0 ;     // масса КА
	double   MF ;     // масса топлива
	double   X[ 6 ] ; // X Y Z Vx Vy Vz или  a e i W w u
					  // размерности координат, скоростей и угловых величин
					  // соответственно дткм, дткм/ссс и радианы
	double   Sb ;     // Баллистический коэффициент 
	double   Kp ;     // Коэффициент светового давления
} _ZNU ;

//------------------------------------------------------------------------
typedef struct ZKA {
	int      num ; 
	double   M0 ;        // Масса КА без топлива
	double   MF ;        // Начальная масса топлива на борту
	double   tstart ;    // Время старта ссс
	int      bpl ;       // Базовая плоскость 0 - экватор, 1 - XOZ, 2 - YOZ
	double   min_step ;  // минимальный шаг интегрирования, сек
	double   max_step ;  // максимальный шаг интегрирования, сек
} _ZKA ;

//------------------------------------------------------------------------
class ZMForceGrav ; 

FLYCORE_API int LoadNU(ZKEYNU& Key, ZNU& NU);
FLYCORE_API int DocNU(ZNU& NU, char* FileName = nullptr, FILE* pf = nullptr);
FLYCORE_API int LoadKA(long numKA, ZKA& KA);
FLYCORE_API int LoadLSF(long numLSF, ZLSF& LSF);
FLYCORE_API int LoadGravPole(ZMForceGrav* GPZ, int vgpz, int ng, int mg);
FLYCORE_API int LoadDU(int nka, int ndu, ZCDU& DU);

FLYCORE_API int SaveNU(ZKEYNU& Key, ZNU& NU);
FLYCORE_API int SaveKA(long numKA, ZKA& KA);
FLYCORE_API int SaveLSF(long numLSF, ZLSF& LSF);

//------------------------------------------------------------------------
// Макросы для организации потокобезапасного выполнения тех участков кода,
// которые содержат создание и использование объектов библиотеки STL
// 
// !!!! STL не является потокобезопасной !!!! 
// 
// Поэтому соответствующий код с целью дальнейшего возможного 
// распараллеливания вычислений должен быть "обёрнут" в семафоры или 
// мьютнексы.
// 
// В рамках настоящего проекта используется самый простой способ -
// - окружение критического кода семаформами
// Выглядеть в оригинале должно примерно так:		
//		CreateSemaphore(...)
//		...
//		vector<...> XXX ;
//		XXX.push_back(...) ;
//		XXX.insert(...) ;
//		... XXX[...] ...
//		...
//		CloseHandle(...) 
// До какого бы то ни было обращения к STL необходимо написать:
//		FAST_SEMAPFORE_OPEN
// После последнего оператора, включая вызов всех деструкторов объектов,
// содержащих элементы STL:
//		FAST_SEMAPFORE_CLOSE
//
// Только в таком случае при многопоточности вычислительные процедуры не
// будут являться источником исключительных ситуаций 
//------------------------------------------------------------------------
#define FAST_SEMAPFORE_OPEN(Name)\
	{\
	HANDLE hsemaph = CreateSemaphore(nullptr, 1, 1, Name) ;\
	WaitForSingleObject(hsemaph, INFINITE) ;\
	{

#define FAST_SEMAPFORE_CLOSE()\
	}\
	ReleaseSemaphore(hsemaph, 1, nullptr) ;\
	CloseHandle(hsemaph) ;\
	}

//------------------------------------------------------------------------
#endif // #ifndef MODTYPE_H
//------------------------------------------------------------------------

