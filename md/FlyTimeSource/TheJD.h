//-----------------------------------------------------------------------
// TheJD.h
// �. ��������� 12.11.2018
// 
//-----------------------------------------------------------------------
#if !defined THE_JD_H
#define THE_JD_H

#include <FlyTimeSource\\TheDataTime.h>
#include <FlyTimeSource\\TheDblTime.h>

//-----------------------------------------------------------------------
// ����������� ����� ���������� ������� ������� � ���
#define TheT_MJD_ORIGIN			2400000.5		// ������ ������� ���������������� ��������� ���
												// ��������� ���� ���� 
												// UTC - ��������� �����
#define TheT_JD1900				2415021			// 12h 01.01.1900
#define TheT_JD1975				2442414			// 12h 01.01.1975
#define TheT_JD2000				2451545			// 12h 01.01.2000
												// ���������������� ��������� ���� ���� 
												// ��� UTC - ��������� �����
#define TheT_MJD1900			15020.5			// 12h 01.01.1900
#define TheT_MJD1975			42413.5			// 12h 01.01.1975
#define TheT_MJD2000			51544.5			// 12h 01.01.2000
#define TheT_MJD1900h0			15020			// 0h  01.01.1900
#define TheT_MJD1975h0			42413			// 0h  01.01.1975
#define TheT_MJD2000h0			51544			// 0h  01.01.2000

#define TheT_DAYTY				365.242198781	// ������������ ������������ ���� ����� B1900 � ����
#define TheT_DAYJY				365.25			// ������������ ���������� ���� � ����
#define TheT_DAYJC				36525.0			// ������������ ���������� �������� � ����

#define TheT_JD_J2000toJ1975	9131.0			// ����������� ����� (�JD) ����� ������� J1975 � J2000
												// ������� ����� � ��� ����� ������� J1975 � J2000
												// ������� ����� ������ �� ���� ���������� �������� �����
												// �� ����� 1975 ���� �� ����� 2000 ���� ����� ����� 
												// 18 ������� ������ �����������
#define TheT_IAT_J2000toJ1975	9131.0003703703703703703703703704

#define TheT_LEAP_UTC_1900to1975	-32.0		// �������� (UTC-IAT) �� 1975 ���� 
#define TheT_LEAP_UTC_1975to2000	-32.0		// �������� (UTC-IAT) �� 2000 ���� 
#define TheT_TTMIAT					32.184		// �������� ��� ���������� ������� ������������� ������� TT
												// TT-IAT = 32.184 ==> TT=IAT+32.184 ; 
extern TheDblTime DblTime_J2000toJ1975 ;

//-----------------------------------------------------------------------
// ����������� ���������� ����
enum AGETime { 
	AGE1975  =0,		// ����� J1975	- ������ 12h 01.01.1975
	AGE2000  =1,		// ����� J2000	- ������ 12h 01.01.2000
	AGE2005  =2,		// ����� J2005	- ������ 12h 01.01.2000
	AGECUR   =3,		// ������� �������� �����
	AGEAVRCUR=4			// ������� ������� �����
	} ;

//-----------------------------------------------------------------------
FLYTIME_API TheDblTime ZFDMYHtoMJD(int d, int m, int g, double* h=nullptr,
								   TheDblTime* mjd=nullptr,
								   DATETIME* DT = nullptr);
FLYTIME_API TheDblTime ZFDMYHtoMJD(DATE& date, double* h = nullptr,
								   TheDblTime* mjd = nullptr, 
								   DATETIME* DT = nullptr);
FLYTIME_API TheDblTime ZFDMYHMStoMJD(DATETIME DTUTC, 
								   TheDblTime* mjd=nullptr);
FLYTIME_API DATETIME   ZFMJDtoDMYH(TheDblTime mjd, DATETIME* DT=nullptr, 
								   double* H=nullptr);
FLYTIME_API TheDblTime ZFDaysBetweenDates(DATE& date1, DATE& date2);

FLYTIME_API void ZFTaToMJD(double ta, double* mjd);
FLYTIME_API void ZFTaToMJD(double ta, TheDblTime* mjd) ;
FLYTIME_API void ZFMJDToTa(double mjd, double* ta);
FLYTIME_API void ZFMJDToTa(TheDblTime& mjd, double* ta);

//-----------------------------------------------------------------------
class FLYTIME_API TheJD {
public :
	TheJD() ;
	~TheJD() ;

	// ����� ����������� ���� ��������� �� ���� date1 �� date2
	TheDblTime DaysBetweenDates(DATE& date1, DATE& date2);

	// �������������� ����������� ���� � ����� 
	// � ���������������� ��������� ����
	TheDblTime DMYHMStoMJD(DATETIME DTUTC, TheDblTime* mjd=nullptr) ; 
	TheDblTime DMYHtoMJD(DATE& date, double* h = nullptr, TheDblTime* mjd = nullptr);
	TheDblTime DMYHtoMJD(int d, int m, int g, double* h = nullptr, TheDblTime* mjd = nullptr);
	// �������������� ���������������� ��������� ����
	// � ����������� ���� � ���� 
	DATETIME   MJDtoDMYH  (TheDblTime mjd, DATETIME* DTUTC = nullptr, double* H = nullptr);
	void       MJDtoDMYHMS(TheDblTime mjd, DATETIME& DTUTC);

	TheJD& operator = (TheDblTime mjd) ;
	friend void operator << (TheJD& TJ, TheDblTime mjd) ;
	friend void operator >> (TheDblTime mjd, TheJD& TJ) ;

	// ���������������� ��������� ���� (������ � ������� ������),
	// �� ���� � ��� ����� ����
	TheDblTime MJD ;
	// ������ ������� ����� ���������� � �����
	double JDH ;
	// ����������� (�����������) ���� � �����
	DATETIMEUTC DTUTC ;
} ;

//-----------------------------------------------------------------------
#endif //#if !defined THE_JD_H
