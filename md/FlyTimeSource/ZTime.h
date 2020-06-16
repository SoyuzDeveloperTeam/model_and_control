//-----------------------------------------------------------------------
// ZTime.h
// А. Николенко 03.08.2018
//-----------------------------------------------------------------------
#ifndef ZTIME_H
#define ZTIME_H

#include <time.h>
#include <FlyTimeSource\\ModTime.h>

//---------------------------------------------------------------------------
// Масштаб времени
// Acronyms
//		ASD	- Average Sunny Day - средние солнечные сутки
//		JC	- Julian Century    - юлианское столетие 
enum TIMESCALE {
	TIME2000ASD = 0,	// в ссс от 2000 (0h 01.01.2000)
	TIME1975ASD = 1,	// в ссс от 1975 (0h 01.01.1975)
	TIMEJ2000JC = 2} ;	// в юлианских столетиях от J2000 (12h 01.01.2000)

#define DEFTIME_SCALE TIME1975ASD
//---------------------------------------------------------------------------
// Вычисление времени в нужной эпохе и в нужном масштабе необходимых
// для астрономических функций.
//		t	  - Время заданное в масштвбе Scale .
//		Scale -	Масштаб времени.
//		ta	  - По адресу выдаётся всегда атомное время в ссс в масштабе 
//			    интегрирования уравнений движения.
//
// Возвращаемое значение вчегда в масштабе TIMEJ2000JC
FLYTIME_API double Astro2000Time(double t, TIMESCALE Scale, double* ta = nullptr);

//---------------------------------------------------------------------------
		// Юлианские даты эпох				// UT1 - всемирное время
#define ZJD1900					2415021		// 12h 01.01.1900
#define ZJD1975					2442414		// 12h 01.01.1975
#define ZJD2000					2451545		// 12h 01.01.2000
		// Модифицированные юлианские даты эпох 
		// MJD = JD - 2400000.5
											// UT1 - всемирное время
#define ZMJD1900				15020.5		// 12h 01.01.1900
#define ZMJD1975				42413.5		// 12h 01.01.1975
#define ZMJD2000				51544.5		// 12h 01.01.2000
#define ZMJD1900h0				15020		// 0h 01.01.1900
#define ZMJD1975h0				42413		// 0h 01.01.1975
#define ZMJD2000h0				51544		// 0h 01.01.2000

#define ZMJD0					2400000.5	// Начало отсчёта модифицированных юлианских дат
#define ZMJD1975t02000			9131.0		// Интервал МJD между эпохой J2000 и J1975
#define ZDIAT1900to1975			-32.0		// Поправка (UTC-IAT) до 1975 года 

//---------------------------------------------------------------------------
// ВСЕ О ВРЕМЕНИ
// Основное время которое используется в модели движения - атомное время отсчитываемое от
// 0h 01.01.1975 года всемирного времени (на этот момент ДМВ = 03:00:00 01.01.1975)
// ZTime позволяет связать это время с любым другим используемом в 
// баллистических и астрономических рассчетах (всемирное координированное, земное динамическое,
// барицентрическое,...
class FLYTIME_API ZTime {
public:
	DATE	dDMB;	// Дикретное Московское время и дата 
	TIME	tDMB ;

	double	t ;		  // IAT Атомное время от J1975 (0h  01.01.1975)
					  // 0 атомного времени соответствует 0h 01.01.1975 (UTC)
					  // и 3h 01.01.1975 (ДМВ)
	double	t0 ;	  // IAT Атомное время от J2000 (12h 01.01.2000)
	double	UTC ;	  // Всемирное координированное время
	double	UT1 ;	  // Всемирное время (UTC-UT1) <= 1 сек (иногда называют среднее солнечное время на гринвиче)
	double	TT ;	  // Земное динамическое время в юлианских днях.
					  // Отличается от MJD на поправку (UTC-IAT). 
					  // Отличается от атомного времени на 32,184 секунды.
	double	TDB ;	  // Барицентрическое время в юлианских днях.
	double	MJD ;	  // Модифицированная юлианская дата (MJD = JD-2400000.5) JD - юлианская дата отсчитанная от 01.01.4713 до нэ
	double  dUTCIAT;  // Поправка ко всемирному координированному времени в секундах
	double  dUTCUTC1; // Поправка (UTC-UT1) в секундах

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

	// Выбор поправки (UTC-IAT) из таблицы
	double Get_DIAT(double tiat75) ;
	
	static double Z_DIAT[34] ;
	static int    Z_Count_DIAT ;
	static double Z_DIAT_CurTime ;
	static double Z_DIAT_NextTime ;
	static double Z_DIAT_CurDT ;

public:
	// Вычисление модиф юлианской даты на заданную гражданскую дату 
	// и временя (UT1)
	// Дано:
	//		dateUT			- дата (время всемирное UT1)  
	//		dUT, mUT, gUT	- день месяц и год (время всемирное UT1)  
	//		hUT, minUT, sUT - часы, минуты, секунда (время всемирное UT1)  
	// Результат
	//		mjd				- модифицированная юлианская дата
	static double UTCDMYtoMJD(DATE dateUT, double* mjd = nullptr);
	static double UTCDMYtoMJD(int dUT, int mUT, int gUT, double* mjd=nullptr) ;
	static double UTCDMYHtoMJD(int dUT, int mUT, int gUT, double* h=nullptr, double* mjd=nullptr) ;
	static double UTCDMYHMStoMJD(DATETIMEDMB dateUT, double* mjd=nullptr) ;
	static double UTCDMYHMStoMJD(int dUT, int mUT, int gUT, int hUT, int minUT, double sUT, double* mjd=nullptr) ;
	// Вычисление модиф юлианской даты на заданный момент атомного времени
	static double AtomicTimetoMJD(double AtomicTime, double* mjd=nullptr) ;
	// Вычисление гражданской даты всемирного времени для 
	// заданного модиф юлианской даты
	static DATE   MJDtoUTCDMY(double MJD, DATE* dateUT = nullptr);
	// Вычисление атомного времени по модифицырованной юлианской дате
	static double MJDtoAtomicTime(double MJD, double* AtomicTime) ;
} ;

//---------------------------------------------------------------------------
#endif // #ifndef ZTIME_H
