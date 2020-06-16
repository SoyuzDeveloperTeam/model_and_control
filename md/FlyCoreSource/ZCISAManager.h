//-------------------------------------------------------------------------------
// ModISAManager.h
// ј. Ќиколенко 29.08.2018
// ƒиспетчер индексов солнечной активности.
// ѕредназначен дл€ загрузки из вне массивов индексов —ј, формировани€ их значений
// на заданный момент времени по этим массивам и/или прогнозировани€ индексов 
// на заданный момент времени и предоставлени€ данных значений модели движени€
// с целю расчЄта параметров динамичекой атмосыеры
//------------------------------------------------------------------------------- 
#ifndef ZCISAManager_H
#define ZCISAManager_H

enum ISATYPE {Isanullptrl=0, IsaPost=1, IsaForecast=2, IsaFixed=3} ;

typedef struct ISAITEM {
	ISATYPE type ;
	double  MJD ; 
	double  F107 ;
	double  F81 ;
	double  KP ;
} _ISAITEM ;

class FLYCORE_API ZCISAManager {
public:
	ZCISAManager();
	~ZCISAManager();

	ISAITEM ISA() ;
	double  F107() ;
	double  F81() ;
	double  AP() ;
	double  KP() ;
	double  ApKp(double Ap) ;
	double  KpAp(double Kp) ;

	int     UpdateToTime(double ta, double tau=0) ; 
	int     SelectFrom(double ta) ;
	int     AverageF107t0F81(double ta, int count=81, double tau=0) ;  

private:
	int    Init() ;
	int    Load() ;
	int    Forecast() ;

	double MJDBegin ; 
	double MJDEnd ; 
	double MJDEndForecast ; 

	bool   isInit ;    
	long   lastind ; 
	double lastta ;
	double lastF107 ;
	double lastF81 ;
	double lastKP ;
} ;

//------------------------------------------------------------------------------- 
#endif // #ifndef ZCISAManager_H
