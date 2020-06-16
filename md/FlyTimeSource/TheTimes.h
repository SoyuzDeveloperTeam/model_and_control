//-----------------------------------------------------------------------
// TheTimes.h
// �. ��������� 12.11.2018
// 
// �� � �������.
//
// �������� ������ �������������� �������, ������� ��������� ����������� 
// ����� � ����� ����������� �������� � �� ������ ������������ ������ 
// �������, ��� � ���� �������, ��� � � ���� ����������� ���� � �������
//	- ������������� ������� � ��������� ������ � ���������
//	- �������� ������� ����� ���������� ��� ���������������
//	- �������� ������� � ���������� ������������� ����������� 
//	  �������� ����
//-----------------------------------------------------------------------
#if !defined THETIMES_H
#define THETIMES_H

#include <FlyTimeSource\\TheJD.h>
#include <FlyTimeSource\\TheDblTime.h>
#include <FlyTimeSource\\TheUT1UTC.h>

//-----------------------------------------------------------------------
// ��������� �������� ������� ��������� ������� ����������� UT1 -
// - ������ ������� ���������� ������� UT1
// �������������� ��� ������ ���������� � ������ ������� ����� 
// ��������� ����� (D, M, G), � ������ �������� �������������� �������
// (������� �����������) 
// 23h59m58s, 23h59m59s --- +������� ����������� ----> 23h59m60s --->
// ����� ����� ����� ----> 0h00m00s, 0h00m01s 
// ������� ����������� �������� � ������� �� ��������, �� ���� � ������ �����
// ����� �� ���������� �������, �������������� �� ��� ��� ����� 3 ���� ����
typedef struct TheLeapSecond {
	double MJD ;		// ���. ��������� ���� ������ �������	
	int    D ;			// ���� ������ 
	int    M ;          // ����� 
	int    G ;          // ���
	double sec ;		// �������� ������� ����������� 
} _TheLeapSecond ;

#define	Count_UTC_IAT_LEAP		28 

//-----------------------------------------------------------------------
typedef struct TheUTC1IAT {
	double MJD ;		// ���. ��������� ���� ������ �������	
	double msec ;		// ���������� ����� ������� � ������������
} _TheUTC1IAT ;

//-----------------------------------------------------------------------
extern TheUT1UTC UT1UTC ;

//-----------------------------------------------------------------------
class FLYTIME_API TheTimes : public TheJD
{
public:
	TheTimes();
	TheTimes(const TheTimes& T);
	virtual ~TheTimes();

	double IAT() ;
	void   fromIAT(TheDblTime&  t) ;
	void   fromUTC(TheDblTime&  utc) ;
	void   fromUTC(DATETIMEUTC& utc) ;
	void   fromDMB(DATETIMEDMB& dmv) ;

	void operator << (DATETIMEUTC& utc) { fromUTC(utc) ; }
	void operator << (DATETIMEDMB& dmv) { fromDMB(dmv) ; }
	void operator << (TheDblTime&  iat) { fromIAT(iat) ; }

	TheTimes& operator = (TheDblTime t ) ;   
	TheTimes& operator = (TheTimes&  T ) ;   
	TheTimes& operator+= (TheDblTime dt) ;   
	TheTimes& operator-= (TheDblTime dt) ;   

	friend TheTimes operator + (TheTimes& T, TheDblTime dt) ;   
	friend TheTimes operator + (TheDblTime dt, TheTimes& T) ;   
	friend TheTimes operator - (TheTimes& T, TheDblTime dt) ;   
	friend TheTimes operator - (TheDblTime dt, TheTimes& T) ;   
	// ������� ����� ����� ��������� ������� ����������
	// � ����� � ������� ����� �����
	friend TheDblTime operator - (TheTimes& T1, TheTimes& T2) ;   

	TheDblTime	iat ;	// [ccc]  ������� �����
	TheDblTime	UTC ;	// [ccc]  ��������� ���������������� �����
	TheDblTime	UT1 ;	// [ccc]  ��������� ����� UT1
	TheDblTime	TT ;	// [ccc]  
	TheDblTime	TDB ;	// [ccc]  
	double		AT ;	// [JC]   ��������������� ����� ��� ���������� ��������� 
						// ��������������� ������������, � ��������� ��������� 
						// ����������� �� ����� J2000
	double  MST ;		// [����] ������� ��������� ����� 
	double  TST ;		// [����] �������� ��������� �����
	double  S ;			// [����] ������� ���� ������������� ���������

	DATETIMEDMB DMB ;		// ��������� ���������� �����
	double      CoordSec ;  // �������� ������� �����������

	// �������� UTC � �������� ������� - ������ ������
	static TheLeapSecond IAT_LEAP[Count_UTC_IAT_LEAP+1] ;

protected:
	// ����� �������� ������ "�������" ����������� ����������� � ��������
	double FindLeapCoordSec(TheDblTime iat, bool fromJ2000) ;
	void   BuildTDBTTAT() ;
	void   BuildDMB() ;
	void   BuildLeapSec() ;
};

//-----------------------------------------------------------------------
#endif //#if !defined THETIMES_H
