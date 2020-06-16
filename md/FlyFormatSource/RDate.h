// RDate.h: interface for the CRDate class.
//
//////////////////////////////////////////////////////////////////////
#ifndef DATE_CLASS_H
#define DATE_CLASS_H

#include <math.h>
#define  JULDAY_01011975_FROMZERO 2442414
#define  JULDAY_01011975_FROM1900 27395

//EDFDLLPORT class CRDate {
class FLYFORMAT_API CRDate {
	friend class CRMoment;
private:
	unsigned flag_Grig:2;		 // 0:ёлианский, 1:√ригорианский (15.10.1582),
								 // 2:–усский (14.02.1918), 3:всегда √риг (не рекомендуетс€ до н.э.)
	unsigned flag_Access:1;		 // при его установке нельз€	изменить ничего
								 // пока его не сбросишь через SetFlags
	unsigned flag_FieldsIsSet:1; // расчет полей уже производилс€
	unsigned flag_afterGrig:1;   // дата после перехода на √ригорианский
	unsigned flag_366:1;         // признак високосного года
	signed   month_delta:2;      // дл€ уточнени€ номера дн€ года
	unsigned m_Day:5;			 // номер дн€  от 1 до последнего дн€ мес€ца
	unsigned m_Month:4;			 // номер мес€ца от 1 до 12
	signed   m_Year:15;			 // номер года, отрицательный - до нашей эры
	signed   m_JulDay:32;		 // номер юлианского дн€
protected:
	void Clear();
	int  TestFields( bool isExcept ) ;
	void TestAccess( ) ;
	void FieldsException( char* txt = 0 ) ;
	bool PrepareFields( ) ;
public:
	//
	CRDate( ) ;
	CRDate( const int& day,const int& month,const int& year ) ;
	CRDate( const long julDayNumber ) ;
	CRDate( const char* stroka ) ;
   ~CRDate();
	//
	void fromLong  ( const long julDay);
	bool fromString( const char* stroka ) ;
	bool toString  ( char* stroka ) ;
	//
	bool CRDate::GetFlags( int& Flags ) ;
	void CRDate::SetFlags( const int Flags) ;
    //
	bool operator < ( const CRDate &other ) const {return (long)m_JulDay<(long)other.m_JulDay;}
	bool operator <=( const CRDate &other ) const {return (long)m_JulDay<=(long)other.m_JulDay;}
	bool operator > ( const CRDate &other ) const {return (long)m_JulDay>(long)other.m_JulDay;}
	bool operator >=( const CRDate &other ) const {return (long)m_JulDay>=(long)other.m_JulDay;}
	bool operator ==( const CRDate &other ) const {return (long)m_JulDay==(long)other.m_JulDay;}
	bool operator !=( const CRDate &other ) const {return (long)m_JulDay!=(long)other.m_JulDay;}
	long operator - ( const CRDate& other ) const { return (long)m_JulDay-(long)other.m_JulDay;}
	CRDate& operator = ( const CRDate & other) ;
	CRDate  operator - ( const long HowMuch ) const ;
	CRDate  operator + ( const long HowMuch ) const ;
	CRDate& operator-= ( const long HowMuch ) ;
	CRDate& operator+= ( const long HowMuch ) ;
	//
    int  IsValiFields( const int day,const int month,const int year ) ;
	bool GetFields( int* day, int* month, int* year);
	bool SetFields( const int day,const int month,const int year);
	int  WeekDay  ( ) const { return (int)(1+(long)m_JulDay-(long)(floor(((long)m_JulDay+1)/7.0)*7));}
	int  YearDay  ( ) ;

	long julDayNumber( ) const{ return m_JulDay; }
	int  hashcode    ( ) const {return (int)m_JulDay;}
};

#endif // #define DATE_CLASS_H