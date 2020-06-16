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
	unsigned flag_Grig:2;		 // 0:���������, 1:������������� (15.10.1582),
								 // 2:������� (14.02.1918), 3:������ ���� (�� ������������� �� �.�.)
	unsigned flag_Access:1;		 // ��� ��� ��������� ������	�������� ������
								 // ���� ��� �� �������� ����� SetFlags
	unsigned flag_FieldsIsSet:1; // ������ ����� ��� ������������
	unsigned flag_afterGrig:1;   // ���� ����� �������� �� �������������
	unsigned flag_366:1;         // ������� ����������� ����
	signed   month_delta:2;      // ��� ��������� ������ ��� ����
	unsigned m_Day:5;			 // ����� ���  �� 1 �� ���������� ��� ������
	unsigned m_Month:4;			 // ����� ������ �� 1 �� 12
	signed   m_Year:15;			 // ����� ����, ������������� - �� ����� ���
	signed   m_JulDay:32;		 // ����� ���������� ���
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