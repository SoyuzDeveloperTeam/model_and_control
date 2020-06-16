//-------------------------------------------------------------------------------
// ZSun.h
// А. Николенко 03.08.2018
//-------------------------------------------------------------------------------
#ifndef _ZSUN_H
#define _ZSUN_H

#define Z_CALCSUN_SIMPLE

typedef struct ZSUN_POINT {
double ta ;			// Атомное время в ссс
double t0 ;			// Время в юлианских столетиях от эпохи J2000 
double E0 ;			// Средний наклон эклиптики к экватору в радианах 
double E0g ;		// Средний наклон эклиптики к экватору в градусах 
double Ls, Bs ;		// Эклиптические долгота и широта в радианах  
double Lsg, Bsg ;	// Эклиптические долгота и широта в градусах 
double alf, dlt ;	// Прямое восхождение и склонение отсчитанные от истинного экватора и равноденствия в радианах
double alfg, dltg ;	// Прямое восхождение и склонение отсчитанные от истинного экватора и равноденствия в градусах
double R ;			// расстояние от Земли до Солнца
double XTES[3] ;	// Абсолютные координаты в текущей эпохе
double X2000[3] ;	// Абсолютные координаты в эпохе 2000 года
} _ZSUN_POINT ;

FLYCORE_API int  ZSunJ2000(double ta, double *Sun, TIMESCALE Scale, 
						   bool notStory = false);
FLYCORE_API int  ZSun(double ta, ZSUN_POINT& SP, TIMESCALE Scale, 
					  bool notStory = false);
FLYCORE_API void ZSunSimple(double ta, TIMESCALE Scale, double *xs, 
							short prizn);

//-------------------------------------------------------------------------------
#endif // #ifndef _ZSUN_H