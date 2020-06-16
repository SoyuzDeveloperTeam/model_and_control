//-----------------------------------------------------------------------
// TheJD.h
// А. Николенко 12.11.2018
// 
//-----------------------------------------------------------------------
#if !defined THE_JD_H
#define THE_JD_H

#include <FlyTimeSource\\TheDataTime.h>
#include <FlyTimeSource\\TheDblTime.h>

//-----------------------------------------------------------------------
// Соотношения между различными шкалами времени и дат
#define TheT_MJD_ORIGIN			2400000.5		// Начало отсчёта модифицырованных юлианских дат
												// Юлианские даты эпох 
												// UTC - всемирное время
#define TheT_JD1900				2415021			// 12h 01.01.1900
#define TheT_JD1975				2442414			// 12h 01.01.1975
#define TheT_JD2000				2451545			// 12h 01.01.2000
												// Модифицырованные Юлианские даты эпох 
												// для UTC - всемирное время
#define TheT_MJD1900			15020.5			// 12h 01.01.1900
#define TheT_MJD1975			42413.5			// 12h 01.01.1975
#define TheT_MJD2000			51544.5			// 12h 01.01.2000
#define TheT_MJD1900h0			15020			// 0h  01.01.1900
#define TheT_MJD1975h0			42413			// 0h  01.01.1975
#define TheT_MJD2000h0			51544			// 0h  01.01.2000

#define TheT_DAYTY				365.242198781	// Длительность тропического года эпохи B1900 в днях
#define TheT_DAYJY				365.25			// Длительность юлианского года в днях
#define TheT_DAYJC				36525.0			// Длительность юлианского столетия в днях

#define TheT_JD_J2000toJ1975	9131.0			// Колличество суток (МJD) между эпохами J1975 и J2000
												// Атомное время в ссс между эпохами J1975 и J2000
												// Атомное время больше за счёт замедления вращения Земли
												// От эпохи 1975 года до эпоши 2000 года имело место 
												// 18 скачков секунд координации
#define TheT_IAT_J2000toJ1975	9131.0003703703703703703703703704

#define TheT_LEAP_UTC_1900to1975	-32.0		// Поправка (UTC-IAT) до 1975 года 
#define TheT_LEAP_UTC_1975to2000	-32.0		// Поправка (UTC-IAT) до 2000 года 
#define TheT_TTMIAT					32.184		// Поправка для вычисления земного динамического времени TT
												// TT-IAT = 32.184 ==> TT=IAT+32.184 ; 
extern TheDblTime DblTime_J2000toJ1975 ;

//-----------------------------------------------------------------------
// Обозначение допустимых эпох
enum AGETime { 
	AGE1975  =0,		// эпоха J1975	- начало 12h 01.01.1975
	AGE2000  =1,		// эпоха J2000	- начало 12h 01.01.2000
	AGE2005  =2,		// эпоха J2005	- начало 12h 01.01.2000
	AGECUR   =3,		// текущая истинная эпоха
	AGEAVRCUR=4			// текущая средняя эпоха
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

	// число календарных дней прошедших от даты date1 до date2
	TheDblTime DaysBetweenDates(DATE& date1, DATE& date2);

	// преобразование гражданской даты и часов 
	// в модифицированную юлианскую дату
	TheDblTime DMYHMStoMJD(DATETIME DTUTC, TheDblTime* mjd=nullptr) ; 
	TheDblTime DMYHtoMJD(DATE& date, double* h = nullptr, TheDblTime* mjd = nullptr);
	TheDblTime DMYHtoMJD(int d, int m, int g, double* h = nullptr, TheDblTime* mjd = nullptr);
	// преобразование модифицированной юлианской даты
	// в гражданскую дату и часы 
	DATETIME   MJDtoDMYH  (TheDblTime mjd, DATETIME* DTUTC = nullptr, double* H = nullptr);
	void       MJDtoDMYHMS(TheDblTime mjd, DATETIME& DTUTC);

	TheJD& operator = (TheDblTime mjd) ;
	friend void operator << (TheJD& TJ, TheDblTime mjd) ;
	friend void operator >> (TheDblTime mjd, TheJD& TJ) ;

	// Модифицированная юлианская дата (вместе с дробной частью),
	// то есть в том числе часы
	TheDblTime MJD ;
	// только дробная часть выраженная в часах
	double JDH ;
	// Гражданская (календарная) дата и время
	DATETIMEUTC DTUTC ;
} ;

//-----------------------------------------------------------------------
#endif //#if !defined THE_JD_H
