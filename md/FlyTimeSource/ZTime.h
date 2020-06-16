//-----------------------------------------------------------------------
// ZTime.h
// �. ��������� 03.08.2018
//-----------------------------------------------------------------------
#ifndef ZTIME_H
#define ZTIME_H

#include <time.h>
#include <FlyTimeSource\\ModTime.h>

//---------------------------------------------------------------------------
// ������� �������
// Acronyms
//		ASD	- Average Sunny Day - ������� ��������� �����
//		JC	- Julian Century    - ��������� �������� 
enum TIMESCALE {
	TIME2000ASD = 0,	// � ��� �� 2000 (0h 01.01.2000)
	TIME1975ASD = 1,	// � ��� �� 1975 (0h 01.01.1975)
	TIMEJ2000JC = 2} ;	// � ��������� ��������� �� J2000 (12h 01.01.2000)

#define DEFTIME_SCALE TIME1975ASD
//---------------------------------------------------------------------------
// ���������� ������� � ������ ����� � � ������ �������� �����������
// ��� ��������������� �������.
//		t	  - ����� �������� � �������� Scale .
//		Scale -	������� �������.
//		ta	  - �� ������ ������� ������ ������� ����� � ��� � �������� 
//			    �������������� ��������� ��������.
//
// ������������ �������� ������ � �������� TIMEJ2000JC
FLYTIME_API double Astro2000Time(double t, TIMESCALE Scale, double* ta = nullptr);

//---------------------------------------------------------------------------
		// ��������� ���� ����				// UT1 - ��������� �����
#define ZJD1900					2415021		// 12h 01.01.1900
#define ZJD1975					2442414		// 12h 01.01.1975
#define ZJD2000					2451545		// 12h 01.01.2000
		// ���������������� ��������� ���� ���� 
		// MJD = JD - 2400000.5
											// UT1 - ��������� �����
#define ZMJD1900				15020.5		// 12h 01.01.1900
#define ZMJD1975				42413.5		// 12h 01.01.1975
#define ZMJD2000				51544.5		// 12h 01.01.2000
#define ZMJD1900h0				15020		// 0h 01.01.1900
#define ZMJD1975h0				42413		// 0h 01.01.1975
#define ZMJD2000h0				51544		// 0h 01.01.2000

#define ZMJD0					2400000.5	// ������ ������� ���������������� ��������� ���
#define ZMJD1975t02000			9131.0		// �������� �JD ����� ������ J2000 � J1975
#define ZDIAT1900to1975			-32.0		// �������� (UTC-IAT) �� 1975 ���� 

//---------------------------------------------------------------------------
// ��� � �������
// �������� ����� ������� ������������ � ������ �������� - ������� ����� ������������� ��
// 0h 01.01.1975 ���� ���������� ������� (�� ���� ������ ��� = 03:00:00 01.01.1975)
// ZTime ��������� ������� ��� ����� � ����� ������ ������������ � 
// �������������� � ��������������� ��������� (��������� ����������������, ������ ������������,
// ����������������,...
class FLYTIME_API ZTime {
public:
	DATE	dDMB;	// ��������� ���������� ����� � ���� 
	TIME	tDMB ;

	double	t ;		  // IAT ������� ����� �� J1975 (0h  01.01.1975)
					  // 0 �������� ������� ������������� 0h 01.01.1975 (UTC)
					  // � 3h 01.01.1975 (���)
	double	t0 ;	  // IAT ������� ����� �� J2000 (12h 01.01.2000)
	double	UTC ;	  // ��������� ���������������� �����
	double	UT1 ;	  // ��������� ����� (UTC-UT1) <= 1 ��� (������ �������� ������� ��������� ����� �� ��������)
	double	TT ;	  // ������ ������������ ����� � ��������� ����.
					  // ���������� �� MJD �� �������� (UTC-IAT). 
					  // ���������� �� �������� ������� �� 32,184 �������.
	double	TDB ;	  // ���������������� ����� � ��������� ����.
	double	MJD ;	  // ���������������� ��������� ���� (MJD = JD-2400000.5) JD - ��������� ���� ����������� �� 01.01.4713 �� ��
	double  dUTCIAT;  // �������� �� ���������� ����������������� ������� � ��������
	double  dUTCUTC1; // �������� (UTC-UT1) � ��������

	ZTime( ) { } ;
	~ZTime( ) { } ;

	void fromTA75  (double tiat75) ;
	void fromTA2000(double tiat2000) ;
	void DMBfromMJD(double mjd, DATE& D, TIME& T);

protected:
	void MJDfromDMB( ) ;
	void UTCfromIAT( ) ;
	void TTfromIAT( ) ;
	void TTfromDMB( ) ;
	void TDBfromTT( ) ;

	// ����� �������� (UTC-IAT) �� �������
	double Get_DIAT(double tiat75) ;
	
	static double Z_DIAT[34] ;
	static int    Z_Count_DIAT ;
	static double Z_DIAT_CurTime ;
	static double Z_DIAT_NextTime ;
	static double Z_DIAT_CurDT ;

public:
	// ���������� ����� ��������� ���� �� �������� ����������� ���� 
	// � ������� (UT1)
	// ����:
	//		dateUT			- ���� (����� ��������� UT1)  
	//		dUT, mUT, gUT	- ���� ����� � ��� (����� ��������� UT1)  
	//		hUT, minUT, sUT - ����, ������, ������� (����� ��������� UT1)  
	// ���������
	//		mjd				- ���������������� ��������� ����
	static double UTCDMYtoMJD(DATE dateUT, double* mjd = nullptr);
	static double UTCDMYtoMJD(int dUT, int mUT, int gUT, double* mjd=nullptr) ;
	static double UTCDMYHtoMJD(int dUT, int mUT, int gUT, double* h=nullptr, double* mjd=nullptr) ;
	static double UTCDMYHMStoMJD(DATETIMEDMB dateUT, double* mjd=nullptr) ;
	static double UTCDMYHMStoMJD(int dUT, int mUT, int gUT, int hUT, int minUT, double sUT, double* mjd=nullptr) ;
	// ���������� ����� ��������� ���� �� �������� ������ �������� �������
	static double AtomicTimetoMJD(double AtomicTime, double* mjd=nullptr) ;
	// ���������� ����������� ���� ���������� ������� ��� 
	// ��������� ����� ��������� ����
	static DATE   MJDtoUTCDMY(double MJD, DATE* dateUT = nullptr);
	// ���������� �������� ������� �� ���������������� ��������� ����
	static double MJDtoAtomicTime(double MJD, double* AtomicTime) ;
} ;

//---------------------------------------------------------------------------
#endif // #ifndef ZTIME_H
