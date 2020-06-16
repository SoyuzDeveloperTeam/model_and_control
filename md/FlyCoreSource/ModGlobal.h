//------------------------------------------------------------------------------
// ModGlobal.h
// А. Николенко 03.08.2018
//------------------------------------------------------------------------------
#ifndef MODGLOBAL_H
#define MODGLOBAL_H
//------------------------------------------------------------------------------

#define RRC if (rc) return rc  

extern FLYCORE_API char DIRFLY[512];
extern FLYCORE_API char DIRFLYINFO[512];
extern FLYCORE_API char DIREGF[512];
extern FLYCORE_API char DIRIERSEOP[512];
extern FLYCORE_API char DIREOPSTORAGE[512];
extern FLYCORE_API char DIRRESULT[512];
extern FLYCORE_API char DIRUOF[512];

FLYCORE_API int FlyGlobalInit();

/*
// Дата 1 января 1975 года по отношению к 1 января 2000 года
extern const double DTPCor1975 ;
extern const double k_sekrad ;
extern const double k_zona ;
extern const double k_mu_kms ; //	
extern const double k_b0 ;     //  Гравитационная постоянная,           [дткм**3/ccc**2]
extern const double k_c20 ;    //  Коэфф.разложения потенциала Земли,   [дткм**2/ccc**2]
extern const double k_omega ;  //  Угловая скорость вращения Земли,     [рад/ccc]
extern const double k_rcp ;    //  Средний радиус Земли,                [дткм]
extern const double k_a0 ;     //  Большая полуось ОЗЭ ,                [дткм]
extern const double k_alfa0 ;  //  Полярное сжатие ОЗЭ ,
extern const double k_alfak ;  //  Полярное сжатие ЭК ,
extern const double k_ak ;     //  Большая полуось ЭК ,                 [дткм]
extern const double k_ekb ;    //  Квадрат эксцентриситета ЭК,
extern const double k_gekw ;   //  Ускорение силы тяжести на экваторе,  [дткм/ccc**2]
extern const double k_g0 ;     //  Ускорение силы тяжести на экваторе,  [м/c**2]
extern const double k_eps ;	   //	

extern const double k_dx;     //  Смещение центра ЭК отн.центра ОЗЭ ,  [дткм]
extern const double k_dy ;    //              --
extern const double k_dz ;    //              --
extern const double k_cfak ;  //  Скорость света фактическая,          [дткм/ccc]
extern const double k_cnom ;  //  Скорость света номинальная,          [дткм/ccc]
extern const double k_tmt ;   //  Коэффициенты перехода от солнечного времени к
extern const double k_tmf ;   //    звездному в случае фиксированной точки весны
extern const double k_rekw ;  //  Экваториальный радиус Земли,         [дткм]
extern const double k_threeh ;//  3 часа,                              [ccc]
extern const double k_pi ;    // +3.14159265358979e+00;   //  Число Пи
extern const double k_polpi ; // +1.57079632679000e+00;   //  Число Пи/2
extern const double k_dwapi ; // +6.28318530717000e+00;   //  Число Пи*2
extern const double k_t2pi ;  // +4.71238897037000e+00;   //  Число Пи*3/2
extern const double k_grarad ;//  Градусов в радиане,                  [град/рад]
extern const double k_sekrad ;//  Угловых секунд в радиане             [сек/рад]
extern const double k_cbc ;   //  Секунд в сутках                      [сек]
extern const double k_cbm ;   //  Минут в сутках                       [мин]
extern const double k_e0 ;    //  Пост. энер. осв.на пов-ти Земли [(кг дткм**2)/(m**2 ccc**3]
extern const double k_gs ;    //  Гелиоцентрическая гравит. пост.      [дткм**3/ссс**2]
extern const double k_gl ;    //  Селеноцентрическая гравит. пост.     [дткм**3/ссс**2]
extern const double k_qk ;    //  Отношение массы Земли к массе Луны   [ - ]
extern const double k_qk2 ;   //  Число Лява                           [ - ]
extern const double k_ql ;    //  Угол запаздывания приливной волны    [радиан]
extern const double k_ae ;    //  Астрономическая единица              [дткм]
extern const double k_rcp_c ; //  Средний радиус Солнца,               [дткм]
extern const double k_rcp_l ; //  Средний радиус Луны,                 [дткм]
extern const double k_zona ;  //  Разница зонального времени от Гринвича [ссс]
extern const double k_vek;    //  Текуший век (сегодня  =  20)
extern const double k_vekcme ;//  Год контроля смены века
extern const double k_dwx ;   //  Орентировка оси X ЭК относительно ОЗЭ [рад]
extern const double k_dwy ;   //  Орентировка оси Y ЭК относительно ОЗЭ [рад]
extern const double k_dwz ;   //  Орентировка оси Z ЭК относительно ОЗЭ [рад]

extern const bool k_Flag_Pril ;    //  Флаг учета приливов в координатах ИС
extern const bool k_Flag_Tekt ;    //  Флаг учета движения тектонических плит в координатах ИС
extern const bool k_Flag_Pvz  ;    //  Флаг неучета ПВЗ при переводах АСК-ГСК
extern const bool k_Flag_Pril_Pvz ;//  Флаг учета ежесуточных приливных поправок ПВЗ
extern const double k_g_jupiter ;  //  Гравит. пост. Юпитера  [дткм**3/ссс**2]
extern const double k_g_saturn ;   //  Гравит. пост. Сатурна  [дткм**3/ссс**2]
extern const double k_g_uran ;     //  Гравит. пост. Урана    [дткм**3/ссс**2]
extern const double k_g_venera ;   //  Гравит. пост. Венеры   [дткм**3/ссс**2]
extern const double k_g_mars ;     //  Гравит. пост. Марса    [дткм**3/ссс**2]
extern const double k_g_neptun ;   //  Гравит. пост. Нептуна  [дткм**3/ссс**2]
extern const double k_g_merkurj ;  //  Гравит. пост. Меркурия [дткм**3/ссс**2]
extern const double k_g_pluton ;   //  Гравит. пост. Плутона  [дткм**3/ссс**2]
*/
//extern const long   DELTA_2000 ;

//-----------------------------------------------------------------------
extern double* mJ2000_B1975 ;
extern double* mgrzab ;

extern double  Global_m2000_75[9] ;

struct POLE_AE ;
extern POLE_AE* Wae ;
//---------------------------------------------------------------------------
FLYCORE_API void  ClearErrorsMSG();
FLYCORE_API int   CountErrorsMSG();
FLYCORE_API int   CountWarningsMSG();
FLYCORE_API void  AddErrorMSG(char* Msg);
FLYCORE_API void  AddWarningMSG(char* Msg);
FLYCORE_API const char* GetErrorMsg(int i);
FLYCORE_API const char* GetWarningMsg(int i);
//---------------------------------------------------------------------------
#endif // #ifndef MODGLOBAL_H