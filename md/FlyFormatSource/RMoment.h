// RMoment.h: interface for the CRMoment class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CMOMENT_CLASS_H 
#define CMOMENT_CLASS_H 

#include "RDate.h"	    
#include "RGradTime.h"	
/*
Данный класс описывает объект, являющийся некоторым
абсолютным  моментом времени. Он позволяет получить
взаимнооднозначное соответствие между любым  другим
моментом времени и величиной  временного интервала,
прошедшего от данного момента. Объект данного клас-
са является некоторй точкой на временной шкале. 
Имеется возможность использования календарного пред-
ставления для обозначения момента.
Календарное представление  дня осуществляет класс CRDate.
Календарное представление времени осуществляет класс CRGradTime.
Клиент может задать набор флагов, влияющих на процесс
перевода, и еденицу измерения интервала времени.
Предусмотрены флаги, учитывающие тип календаря или момент
перехода с Юлианского на Григорианский календарь, вариант
коррекции по таблице поправок UTC-IAT, зональную поправку.
*/

#define TIME_LT  2
#define TIME_UTC 1
#define TIME_IAT 0
#define TIME_UT1 5
#define TIME_TDT 3
#define TIME_TDB 4
#define TIME_DEFAULT  TIME_LT

#define ZONA_DEFAULT 180

class FLYFORMAT_API recordPopIAT
{
	friend class CRMoment ;
protected:
	CRDate date;
	double Millis ;
};

class FLYFORMAT_API CRMoment
{
protected:
	CRMoment( const long Day, const double Millis,const int zn=ZONA_DEFAULT);
public:
	CRMoment( const int zn = ZONA_DEFAULT ) ;
	virtual ~CRMoment( ) ;
	//
	static void ClearTbls();
	//
	CRGradTime operator-(const CRMoment other) const;
	CRMoment   operator+(const CRGradTime tm) const;
	CRMoment   operator-(const CRGradTime tm) const;
	//
	long Get_Zona ( int* Value);
	long Put_Zona ( const int newValue);
	long GetEpoha ( double* Value,const int EpohType);
	long SetEpoha ( const double Value,const int Type);
	long GetFields( int* Day,int* Month,int* Year,int* Hour,	int* Min,int* Sec,double* Millis,int TimeType=TIME_LT ) ;
	long SetFields(int Day,int Month,int Year,int Hour=0,int Min=0,int Sec=0,double Millis=0,int TimeType=TIME_LT ) ;
	//
protected:
	long toUTC( CRDate* dt,CRGradTime* tm ) ;
	static long loadPopIAT();
	long fromUTC();
	//
	static recordPopIAT *tblPopIAT ;
	int        zona ; // в минутах 
	CRGradTime time;
	CRDate     date;
};

#endif // #ifndef CMOMENT_CLASS_H
