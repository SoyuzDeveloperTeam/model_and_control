#ifndef _CModAstro_H
#define _CModAstro_H
//------------------------------------------------------------------------
#define _MERCURY    0
#define _VENUS      1
#define _BARYCENTER 2
#define _MARS       3
#define _JUPITER    4
#define _SATURN     5
#define _URANUS     6
#define _NEPTUNE    7
#define _PLUTO      8
#define _MOON       9
#define _SUN       10

#include <fcntl.h>

//------------------------------------------------------------------------
// Структура имен астроданных
//------------------------------------------------------------------------
typedef struct ASTRO_DATA
{
	int    Num_AD  = 0;		// Номер астроданных
	string Name_AD = 0;		// Название астроданных
	string Note_AD = 0;		// Примечание
	int BegDATE_AD = 0;		// Время начала и время конца астроданных
	int EndDATE_AD = 0;
	// Конструктор
	ASTRO_DATA() { Clear(); }
	// Функция очистки
	void Clear() { 
		Num_AD=BegDATE_AD=EndDATE_AD=0; Name_AD.erase(); Note_AD.erase();
	}
} _ASTRO_DATA;

//------------------------------------------------------------------------
// Рабочее поле Астрономического Ежегодника
//------------------------------------------------------------------------
typedef struct POLE_AE
{
  // Инициализируемый массив временных допусков
  double  dop[14];
  // Моменты времени, на которые получены параметры АЕ, при предыдущем обращении
  double    t[14];
  // Массивы интерполированных параметров АЕ
  double   qso[3],        //  0. Координаты  Солнца
           qlu[3],        //  1.             Луны
           qup[3],        //  2.             Юпитера
           qsa[3],        //  3.             Сатурна
           qur[3],        //  4.             Урана
           qwe[3],        //  5.             Венеры   АСК 1975.0
           qma[3],        //  6.             Марса
           qne[3],        //  7.             Нептуна
           qme[3],        //  8.             Меркурия
           qpl[3],        //  9.             Плутона
           qpr[3],        // 10. Составляющие матрицы прецессии
           pvz[3],        // 11. Параметры вращения Земли(Ut,x,y), Ut=UT1-TAI
           qnu[3],        // 12. Составл.матрицы нутации (e0,Nf,Ne)
           qze[3],        // 13. Координаты  Земли
           qre[2];        // 14. Редукционные величины G,g
  double   *b[14];        // Массив базовых указателей на выделяемые
                          // через EMU_MALLOC поля оперативных
                          // массивов АЕ  (на заданное кол-во суток)
  char  metod[14];        // Метод, по которому получены
                          // интерполированные параметры :
                          //  metod[i]=0 - i-й параметр по табличному АЕ
                          //           1 - i-й параметр по аналитическому АЕ
  // Конструктор
  POLE_AE() { Clear(); }
  // Функция очистки
  void Clear() { memset(this,0,sizeof(*this));
  }
} _POLE_AE;

//------------------------------------------------------------------------
// Типы барицентрических СК для АЕ
//------------------------------------------------------------------------
#define    BTS_EARTH     0  // Земная барицентрическая СК
#define    BTS_SS        1  // Солнечная барицентрическая СК
//-----------------------------------------------------------------------
struct DE405
   {
      double password;          // контрольное число
      double jd_begin;          // дата начала ежегодника от 1.01.2000
      double jd_end;            // дата конца ежегодника  от 1.01.2000
      short  num_block;         // кол-во блоков
      short  interval;          // интервал, накрываемый блоком
      short  size_block;        // размер блока (кол-во информационных чисел)
      short  structur[13][3];   // структура блока
      // первый индекс масива означает объект (отн. барицентра солн. системы):
      // 0 - меркурий, 1 - венера, 2 - барицентр З-Л, 3 - марс,
      // 4 - юпитер, 5 - сатурн, 6 - уран, 7 - нептун, 8 - плутон,
      // 9 - луна отн. барицентра З-Л, 10 - солнце, 11 - нутация, 12 - либрация
      // для объектов 0-10 по 3 массива (Х,Y,Z), для 11-12 - по 2 массива
      // второй индекс означает:
      // 0 - смещение в блоке
      // 1 - порядок разложения (степень полинома +1)
      // 2 - количество полиномов на интервале
      //     например:
      // structur[3][0]=179 означает, что первый коэффициент полиномов
      // для представления координат марса имеет 179 номер
    };
//-----------------------------------------------------------------------
enum AstroObject { Moon = 0, Sun = 1, Mercury = 2, Venus = 3, Mars = 4,
                   Jove = 5, Saturn = 6, Uranus = 7, Neptune = 8, Pluto = 9,
                   //Nutation = 10, Libration = 11, STime = 12, Precess = 13}
                   Nutation = 10, Libration = 11, STime = 13, Precess = 14,
                   Earth = 12};
// Луна Солнце
// Меркурий Венера Марс Юпитер Сатурн Уран Нептун Плутон
// Нутация Либрация Прецессия Звездное время
//    при добавлении новых объектов изменить нижеследующий параметр
//const MaxAstroObjectNum = 14; // 13+1(нулевой)
const int MaxAstroObjectNum = 15; // 14+1(нулевой)
//-----------------------------------------------------------------------
// Структура параметров астроданных
typedef struct LastCalc
{
	double        dTA;                // время
	long          NumSysCoord;        // номер координат???
	double        Params[3];          // значения
	LastCalc() { Clear(); }
	void Clear() {
	    memset(this,0,sizeof(*this));
		dTA = - 1.e10;
		NumSysCoord = -1;
	}
} _LastCalc;
//-----------------------------------------------------------------------
class FLYCORE_API CModAstro
{
private:
  // первый индекс масива означает объект (отн. барицентра солн. системы):
  // 0 - меркурий, 1 - венера, 2 - барицентр З-Л, 3 - марс,
  // 4 - юпитер, 5 - сатурн, 6 - уран, 7 - нептун, 8 - плутон,
  // 9 - луна отн. барицентра З-Л, 10 - солнце, 11 - нутация, 12 - либрация
  // для объектов 0-10 по 3 массива (Х,Y,Z), для 11-12 - по 2 массива
  int      Epoc;          // Эпохи : 0 - 2000 г.
                          //         1 - 1975 г.
  int      RazmD;         // размерность 0 - дткм
                          //             1 - км
                          //             2 - м
  int      RazmU;         // размерность 0 - рад
                          //             1 - град
                          //             2 - час
  int      TimeSh;        // Время  0 - Всемирное
                          //        1 - Московское
  double   EpsilonNoCalc; // параметр времени при НЕПРЕВЫШЕНИИ которог расчёт производиться
                          // не будет, а будут переданы прошлые
  int      ModeBTS;       // режим расчёта 0 - барицентр З,   1 - БЦ СС
						  // массив последних рассчитанных значений!
  _LastCalc  LastCalcMass[MaxAstroObjectNum];      
						  // матрица перехода
  void __fastcall AsOutMode(double * massiv);              

public:
  int     NumADC;		// НОМЕР ЕЖЕГОДНИКА ПРИ АВТОМАТИЧЕСКОЙ ИНИЦИАЛИЗАЦИИ!
  string  Note;			// Комментарии

  CModAstro(void);
  CModAstro(int mode);	// Конструктор с установкой режима барицентра
 ~CModAstro(void);
  // Функция расчета по полиномам
  HRESULT Calc_Precesion(double dTA, AstroObject NumTypeData, double *dResult);
  // Функция расчета и получения астроданных заданного типа
  HRESULT Calc_AstroData(const double dTA, AstroObject NumTypeData, long NumSysCoord, double *dResult);
  /* dTA в ССС от 01.01.1975 г.   rezult - 3 параметра */
  /*      NumSysCoord   -1 не переведенные       */
  // Функция расчета звездного времени
  HRESULT Calc_AstroData_Startime(double dTA, double *dResult);
  // Функция расчета прецессии
  HRESULT Calc_AstroData_precess(double dTA, double *dResult);
  short AstroSetFromFile(double *Begin_from2000, double *Interval, char *PathStruct, char *PathFile);
  void AstroRazmSet(int Epockha, int RazmerD, int TimeShkala);
  void AstroRazmGet(int *Epockha, int *RazmerD, int *TimeShkala);
  void AstroRazmSet(int Epockha, int RazmerD, int RazmerU, int TimeShkala);
  void AstroRazmGet(int *Epockha, int *RazmerD, int *RazmerU, int *TimeShkala);
};
//------------------------------------------------------------------------------
//void    preces_IERS(double Tau,double tau,double *u) ;
FLYCORE_API void    CalcNutation(double JD2000, double *x);
FLYCORE_API void    NutationSmooth(double JD2000, double *x);
FLYCORE_API double  SR_E0(double Tae, bool FlagTDT = true);
FLYCORE_API double  sr_E0_IERS(double tau2000);
//void  Calc_Prec_Par(double dIAT_E1, double dIAT_E2, double *dPreces);
//void  Calc_Matr_Prec(double *dPrec, double *dMatrPrec);
//long  Calc_Dif_Matr_Prec(double dIAT_E1, double dIAT_E2, double *dPrec, double *AMatr, double *DMatr = nullptr);
//------------------------------------------------------------------------------
FLYCORE_API long    Calc_Nuta_Par(double dIAT, double *dNutPar);
FLYCORE_API void    Calc_Matr_Nuta(double *dNuta, double *dMatrNuta);
FLYCORE_API long    Calc_Dif_Matr_Nuta(double dIAT, double *dNuta, double *AMatr, double *DMatr = nullptr);
//------------------------------------------------------------------------------
FLYCORE_API long    Calc_StarTime(double dIAT, double *StarTime);
//double  Calc_AverageStarTime(double UT2000);
FLYCORE_API short   FZW(double t, double *zw);
//long    Precess_J2000(double dIAT_D1975, double *u);
//void	preces(double Tau, double tau, double *Precess);
//void	Calc_Matr_Preces_B1975_J2000( double *Matr_B1975_J2000 ) ;
FLYCORE_API long    Calc_Matr_StarTime(double dStarTime, double *AMatr, double *DMatr = nullptr);
//------------------------------------------------------------------------------
FLYCORE_API long    Calc_Matr_PVZ(double dIAT, double *dPVZ, double *AMatr, double *DMatr = nullptr);
FLYCORE_API long    Calc_Matr_PVZ(double *dPVZ, double *AMatr, double *DMatr = nullptr);
//------------------------------------------------------------------------------
//long    Precess_J2000(double dIAT_D1975, double *u);
//------------------------------------------------------------------------------
FLYCORE_API short  AEJG(double t, short N, short mode = 0);
FLYCORE_API short  ANAL_AE(double Tae, short N);
//void   PRECES(double Tae);
FLYCORE_API short  Model_PVZ(double Time_PVZ, double *Xp, double *Yp, double *UT);
//---------------------------------------------------------------------------
FLYCORE_API void fargTIME(double t, double *u, char FlagCalc = 0);
//---------------------------------------------------------------------------
FLYCORE_API int _CalcAstroKoord(double t, int NP);

#endif _CModAstro_H

