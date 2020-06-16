//-----------------------------------------------------------------------
// ModTime.h
// А. Николенко 03.08.2018
//-----------------------------------------------------------------------
#ifndef MODTIME_H
#define MODTIME_H

#include <FlyTime.h>
#include <FlyTimeSource\\TheDataTime.h>

//-----------------------------------------------------------------------
#define  CCCHMS	SSSTimeToCalendTime
#define  HMSCCC	CalendTimeToSSSTime
#define  AMMA 	DeltaTime

//-----------------------------------------------------------------------
// Структура для представления интервала времени
//-----------------------------------------------------------------------
typedef struct INTTIME {
	bool   z;            // Знак         (true - "+", false - "-")
	unsigned short  h;   // Часы         (0 - 32000)
	unsigned short  m;   // Минуты       (0 - 59)
	unsigned short  s;   // Секунды      (0 - 59)
	double d;            // Доли секунды (  < 1 )
	INTTIME () { Clear(); }
	void Clear()	{	z = false; h = m = s = 0; d = 0;
  }
} _INTTIME;

//---------------------------------------------------------------------------
// Функция преобразования времени из ССС от заданной эпохи в календарное время
FLYTIME_API void    SSSTimeToCalendTime(DATE *EpochDate, double tSSS, DATE *Date, TIME *Time);

//---------------------------------------------------------------------------
// Функция преобразования из календарного времени в ССС от заданной эпохи
FLYTIME_API double  CalendTimeToSSSTime(DATE *EpochDate, DATE *Date, TIME *Time);

//---------------------------------------------------------------------------
// Функция расчета интервала времени в ССС между двумя моментами времени
FLYTIME_API long DeltaTime(short Dir, DATE *dn, double tn, DATE *dk, double *tk, double *DeltaTime);

//---------------------------------------------------------------------------
// Функция преобразования времени от эпохи B1975 во время начала текущего года
FLYTIME_API double  TimeB1975ToYearTime(double dTimeB1975);

//---------------------------------------------------------------------------
// Функция преобразования времени от эпохи J2000 во время начала текущего года
FLYTIME_API double  TimeJ2000ToYearTime(double dTimeJ2000);

//---------------------------------------------------------------------------
// Функция получения интервала между эпохой J2000 и эпохой В1975
FLYTIME_API double  DeltaTime_J2000_B1975();

//---------------------------------------------------------------------------
// Функция получения номера года и дня в году по календарному дню
FLYTIME_API short   CalendDayToYearDay(DATE Date);

//---------------------------------------------------------------------------
// Функция преобразования времени из даты и времени в год с долями
FLYTIME_API void DateTimeToYear(DATE Dt, TIME Tm, double *dYearTime);

//---------------------------------------------------------------------------
// Функция получения календарного дня по номеру года и номеру дня в году
FLYTIME_API DATE   YearDayToCalendDay(short Year, short Day);

//---------------------------------------------------------------------------
// Функция получения календарной даты и времени по Юлианской дате
FLYTIME_API void joulex(double djed, DATE *d_UTC, TIME *t_UTC);

//---------------------------------------------------------------------------
FLYTIME_API short   TA_DMB(short pr, DATE *DMB, TIME *TMB, double *TA);
FLYTIME_API double  TEKTIME(DATE *Tek_Data, TIME *Tek_Bpem);
FLYTIME_API double  TEKTIME_DMV(DATE *Tek_Data, TIME *Tek_Bpem);
FLYTIME_API short   tmsss(long dno, long dtek, double tekvrem, double *tsss, char var_bd);
FLYTIME_API void    T_HMS(double ccc, TIME *t);

//---------------------------------------------------------------------------
FLYTIME_API double JD_Bessel(double JD);
FLYTIME_API void   JD_Bessel(double *JD, double *BD);

//---------------------------------------------------------------------------
FLYTIME_API double tau2000(double time_sss);
FLYTIME_API double t_TDT(double t_TAI);

//---------------------------------------------------------------------------
#endif // #ifndef MODTIME_H

