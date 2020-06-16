//------------------------------------------------------------------------------
// MMathDef.h
// А. Николенко 14.03.2019
//------------------------------------------------------------------------------
#ifndef MMATH_DEF_H
#define MMATH_DEF_H
//
#define  VMF_TRANSP           1
#define  VMF_ABS              2
#define  VMF_USESVD           4
#define  VMF_USECOL           8
#define  VMF_USESCALE         16
#define  VMF_USEROTATION      32
#define  VMF_USEITERATIVE     64
#define  VMF_USECHECK         128
//
#define  VMF_ROTATION_DIRUP   1
#define  VMF_ROTATION_AILER   2
#define  VMF_ROTATION_KRILOV  4
#define  VMF_ROTATION_USER    8
#define  VMF_ROTATION_NEXT    16
#define  VMF_ROTATION_X       32
#define  VMF_ROTATION_Y       64
#define  VMF_ROTATION_Z       128

//
#define Size36Dbl	228 
#define Size9Dbl	72
#define Size6Dbl	48
#define Size4Dbl	32
#define Size3Dbl	24
#define Size2Dbl	16

//
//#define ARRAYSIZE  (a)          (sizeof(a)/sizeof(a[0]))
#define SIGN (X)         (X<0.0 ?-1.0:1.0)
#define FOR  (i, ik)     for(i=0; i<ik; i++)
#define FORi (in, ik)    for(int i=in; i<ik; i++)
#define FORK (i, in, ik) for(i=in; i<ik; i++)
#define FORKi(in, ik)    for(int i=in; i<ik; i++)

#define Min(a, b) (((a)<(b)) ? (a):(b))
#define Max(a, b) (((a)>(b)) ? (a):(b))
#define Sign1(X1)          (((X1)<0) ?-1:1)
#define Sign2(X1, X2)      (((X2)<0) ?(-X1):(X1))
#define FlagSet(F1, F2)    ((F1) & (F2))
#define FlagsSet(F1, F2)   (((F1) & (F2)) == (F2))
#define MIN  (a, b) (((a)<(b)) ? (a):(b))
#define MAX  (a, b) (((a)>(b)) ? (a):(b))

/* Constants rounded for 21 decimals. */
#define M_E         2.71828182845904523536
#define M_LOG2E     1.44269504088896340736
#define M_LOG10E    0.434294481903251827651
#define M_LN2       0.693147180559945309417
#define M_LN10      2.30258509299404568402
#define M_DPI       6.283185307179586476925
#define M_PI        3.14159265358979323846
#define M_PI_2      1.57079632679489661923
#define M_PI_4      0.785398163397448309616
#define M_1_PI      0.318309886183790671538
#define M_2_PI      0.636619772367581343076
#define M_1_SQRTPI  0.564189583547756286948
#define M_2_SQRTPI  1.12837916709551257390
#define M_SQRT2     1.41421356237309504880
#define M_SQRT_2    0.707106781186547524401
				//  Градусов в радиане, [град/рад]
#define M_GRARAD	57.29577951308232   
				//  Угловых секунд в радиане [сек/рад]
#define M_SEKRAD	206264.80624709635515647335733078   

#define KU			(180.0/M_PI)

#define _dtkm    1e-4
#define _dtm     1e-7
#define _ccc     86400.0  // секунд в средних солнечных сутках
#define _minut   1440.0   // минут  в средних солнечных сутках
#define _hour    24.0     // часов  в средних солнечных сутках
#define _sec     60.0     // секунд в минуте
#define _dtkmccc 86400.0e-4
#define _dtmccc  86400.0e-7
#define _rad     (M_PI/180.0)

#define del_Jule  36525L	// длительность юлианского столетия 
#define del_DMT   0.125     // Поправка для перехода к ДМВ от UTC 

#define  DTPCor1975		9131.0				   // Дата 1 января 1975 года по отношению к 1 января 2000 года

#define  k_mu_kms		398600.44			   //  Гравитационная постоянная,          [км**3/cек**2]												 
#define  k_b0			2.97553634058240e+03   //  Гравитационная постоянная,           [дткм**3/ccc**2]
#define  k_c20			-1.08262570000000e-03  //  Коэфф.разложения потенциала Земли,   [дткм**2/ccc**2]
#define  k_omega		6.30038809698000e+00   //  Угловая скорость вращения Земли,     [рад/ccc]
#define  k_rcp			6.37100000000000e-01   //  Средний радиус Земли,                [дткм]
#define  k_a0			6.37813600000000e-01   //  Большая полуось ОЗЭ ,                [дткм]
#define  k_alfa0		3.35282440000000e-03   //  Полярное сжатие ОЗЭ ,
#define  k_alfak		3.35232986926000e-03   //  Полярное сжатие ЭК ,
#define  k_ak			6.37824500000000e-01   //  Большая полуось ЭК ,                 [дткм]
#define  k_ekb			6.69342162180000e-03   //  Квадрат эксцентриситета ЭК,
#define  k_gekw			7.32062499840000e+03   //  Ускорение силы тяжести на экваторе,  [дткм/ccc**2]
#define  k_g0			9.80665                //  Ускорение силы тяжести на экваторе,  [м/c**2]
#define  k_eps			1.96572649767644139	//	 = 1.5*1,31048433178429426  км**5/ сек**2

#define  k_dx			2.50000000000000e-06   //  Смещение центра ЭК отн.центра ОЗЭ ,  [дткм]
#define  k_dy			-1.41000000000000e-05  // 
#define  k_dz			-8.00000000000000e-06  // 
#define  k_cfak			2.59020683712400e+06   //  Скорость света фактическая,          [дткм/ccc]
#define  k_cnom			2.59200000000000e+06   //  Скорость света номинальная,          [дткм/ccc]
#define  k_tmt			2.73790926300000e-03   //  Коэффициенты перехода от солнечного времени к
#define  k_tmf			2.73781190600000e-03   //  звездному в случае фиксированной точки весны
#define  k_rekw			6.37816000000000e-01   //  Экваториальный радиус Земли,         [дткм]
#define  k_threeh		1.25000000000000e-01   //  3 часа,                              [ccc]
#define  k_pi			M_PI				   //  3.14159265358979e+00;   //  Число Пи
#define  k_polpi		M_PI_2				   //  1.57079632679000e+00;   //  Число Пи/2
#define  k_dwapi		M_DPI				   //  6.28318530717000e+00;   //  Число Пи*2
#define  k_t2pi			3*M_PI_2			   //  4.71238897037000e+00;   //  Число Пи*3/2
#define  k_cbc			8.64000000000000e+04   //  Секунд в сутках                      [сек]
#define  k_cbm			1.44000000000000e+03   //  Минут в сутках                       [мин]
#define  k_e0			1.36825000000000e+03   //  Пост. энер. осв.на пов-ти Земли      [(кг дткм**2)/(m**2 ccc**3]
#define  k_gs			9.90693071599657e+08   //  Гелиоцентрическая гравит. пост.      [дткм**3/ссс**2]
#define  k_gl			3.65992110957681e+01   //  Селеноцентрическая гравит. пост.     [дткм**3/ссс**2]
#define  k_qk			8.13005600000000e+01   //  Отношение массы Земли к массе Луны   [ - ]
#define  k_qk2			3.00000000000000e-01   //  Число Лява                           [ - ]
#define  k_ql			4.36332312998585e-02   //  Угол запаздывания приливной волны    [радиан]
#define  k_ae			1.49597900000000e+04   //  Астрономическая единица              [дткм]
#define  k_rcp_c		6.95980000000000e+01   //  Средний радиус Солнца,               [дткм]
#define  k_rcp_l		1.73800000000000e-01   //  Средний радиус Луны,                 [дткм]
#define  k_zona			1.25000000000000e-01   //  Разница зонального времени от Гринвича [ссс]
#define  k_vek			21                     //  Текуший век 
#define  k_vekcme		50                     //  Год контроля смены века
#define  k_dwx			0.00000000000000e+00   //  Орентировка оси X ЭК относительно ОЗЭ [рад]
#define  k_dwy			1.69684788388338E-06   //  Орентировка оси Y ЭК относительно ОЗЭ [рад]
#define  k_dwz			3.19977029532295E-06   //  Орентировка оси Z ЭК относительно ОЗЭ [рад]

#define  k_g_jupiter	945906.3002000	//  Гравит. пост. Юпитера  [дткм**3/ссс**2]
#define  k_g_saturn		283225.4230000	//  Гравит. пост. Сатурна  [дткм**3/ссс**2]
#define  k_g_uran		43256.1020000	//  Гравит. пост. Урана    [дткм**3/ссс**2]
#define  k_g_venera		2425.0579000	//  Гравит. пост. Венеры   [дткм**3/ссс**2]
#define  k_g_mars		319.7118400		//  Гравит. пост. Марса    [дткм**3/ссс**2]
#define  k_g_neptun		51034.4830000	//  Гравит. пост. Нептуна  [дткм**3/ссс**2]
#define  k_g_merkurj	164.4687000		//  Гравит. пост. Меркурия [дткм**3/ссс**2]
#define  k_g_pluton		7.3276157		//  Гравит. пост. Плутона  [дткм**3/ссс**2]

// Разница в ссс между датой начала отсчёта времени 1975 года и эпохой 2000 (01.01.2000)
#define  DELTA_2000		-9131L


#define tgk_B20   (-k_c20*k_a0*k_a0*k_b0)
#define tgk_T2B20 (-1.5*k_c20*k_a0*k_a0*k_b0)
#define tgk_G0    (k_gekw*1.e7/k_cbc/k_cbc) 
#define del_TDT   32.184				// Поправка от эфемеридного времени к атомному 
#define J_ask0    -0.2500074352204		// Эпоха B1975.0 от J2000.0
#define J_ask1    -0.25					// Эпоха  1975.0 от J2000.0

#define	DTCH(M,L,K) (floor((M)/(K))-floor(floor((M)/(K))/(L))*(L))
// Дробная часть от деления M на K
#define	DTCHL(M,K)  ((M)-floor((M)/(K))*(K))

#define	TIME_IN_CCC -1
#define	CCC_INTIME  1

//---------------------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

extern FLYMMATH_API double EpsMZ;

//---------------------------------------------------------------------------
FLYMMATH_API double MAX3(double a, double b, double c);
FLYMMATH_API double MIN3(double a, double b, double c);
FLYMMATH_API double MAX4(double a, double b, double c, double d);
FLYMMATH_API double MIN4(double a, double b, double c, double d);
FLYMMATH_API double AMAX3(double a, double b, double c);
FLYMMATH_API double AMIN3(double a, double b, double c);
FLYMMATH_API double AMAX4(double a, double b, double c, double d);
FLYMMATH_API double AMIN4(double a, double b, double c, double d);
FLYMMATH_API double Inf_sup(const double X1, const double x, const double X2);

//---------------------------------------------------------------------------
FLYMMATH_API double TO_KM(double dtkm);
FLYMMATH_API double TO_DTKM(double km);
FLYMMATH_API double TO_KMS(double dtkmsss);
FLYMMATH_API double TO_DTKMSSS(double kms);
FLYMMATH_API double TO_RAD(double grad);
FLYMMATH_API double TO_GRAD(double rad);
FLYMMATH_API void   VASK_TO_KM(double* RV);
FLYMMATH_API void   VASK_TO_DTKM(double* RV);
FLYMMATH_API void   VOSK_TO_RAD(double* O);
FLYMMATH_API void   VOSK_TO_GRAD(double* O);

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
#endif // #ifndef MMATH_DEF_H
