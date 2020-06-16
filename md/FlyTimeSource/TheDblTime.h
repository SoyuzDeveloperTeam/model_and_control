//-----------------------------------------------------------------------------
// TheDblTime.h
// А. Николенко 19.11.2018
// 
// Время двойной точности.
// Колличество дней + время в пределах текущего дня в секундах
//-----------------------------------------------------------------------------
#if !defined THE_DBLTIME_H
#define THE_DBLTIME_H

//-----------------------------------------------------------------------------
#include <FlyTimeSource\\TheDataTime.h>

//-----------------------------------------------------------------------------
class FLYTIME_API TheDblTime
{
public :
	TheDblTime(double D, double S) { days = D ; sec = S ; } ;
	TheDblTime(double JD=0) { days = floor(JD) ; sec = 86400.0*(JD-days) ; } ;
	TheDblTime(const TheDblTime& at) { days = at.days ; sec = at.sec ; } ;
	~TheDblTime() {} ;

	double GetDays   () { return(days+sec/86400.0) ; } ;
	double GetSec    () { return(days*86400.0+sec) ; } ;
	double LikeDouble() { return(days+sec/86400.0) ; } ;

	double D1() { return(days) ; } ;
	double D2() { return(sec/86400.0) ; } ;

	// Число ССС, м.б. отрицательным
	double days ;
	// Число секунд от начала суток, всегда положительное число 
	// 0.0 <= sec < 86400.0
	double sec ;

	TheDblTime& operator = (const double t) { 
		days = floor(t);
		sec  = (t - days)*86400.0;
		return *this; 
	}
	TheDblTime& operator = (TheDblTime& T) { 
		days = T.days;
		sec  = T.sec; 
		return *this;
	}     
	TheDblTime& operator+= (const double dt) { 
		days+= dt + sec / 86400;
		double fday = days - floor(days);
		days = floor(days);
		sec  = fday*86400.0;
		return *this;
	}
	TheDblTime& operator+= (TheDblTime& at) { 
		days+= at.days;
		sec += at.sec;
		days+= sec / 86400;
		double fday = days - floor(days);
		days = floor(days);
		sec  = fday*86400.0;
		return *this;
	}
	TheDblTime& operator-= (const double dt)  { 
		*this+= (-dt);
		return *this;
	}  
	TheDblTime& operator-= (TheDblTime& at) { 
		days-= at.days;
		sec -= at.sec;
		if (sec<0) { days -= 1.0; sec += 86400.0; }
		days+= sec / 86400;
		double fday = days - floor(days);
		days = floor(days);
		sec  = fday*86400.0;
		return *this;
	}
	friend TheDblTime operator - (TheDblTime& t1, TheDblTime& t2);
	friend TheDblTime operator - (const double& t1, TheDblTime& t2);
	friend TheDblTime operator - (TheDblTime& t1, const double& t2);
	friend TheDblTime operator + (TheDblTime& t1, TheDblTime& t2);
	friend TheDblTime operator + (const double& t1, TheDblTime& t2);
	friend TheDblTime operator + (TheDblTime& t1, const double& t2);
} ;

//-----------------------------------------------------------------------------
void operator << (DATETIME& DT, TheDblTime& T);
void operator >> (TheDblTime& T, DATETIME& DT);

//-----------------------------------------------------------------------------
void operator << (DATETIMEDMB& DMB, TheDblTime& T);
void operator >> (TheDblTime& T, DATETIMEDMB& DMB);

//-----------------------------------------------------------------------------
void operator << (DATETIMEUTC& UTC, TheDblTime& T);
void operator >> (TheDblTime& T, DATETIMEUTC& UTC);

//-----------------------------------------------------------------------------
TheDblTime operator - (TheDblTime& t1, TheDblTime& t2);
TheDblTime operator - (TheDblTime& t1, const double& t2);

//-----------------------------------------------------------------------------
TheDblTime operator + (TheDblTime& t1, TheDblTime& t2);
TheDblTime operator + (TheDblTime& t1, const double& t2);

//-----------------------------------------------------------------------------
#endif // #if !defined THE_DBLTIME_H
