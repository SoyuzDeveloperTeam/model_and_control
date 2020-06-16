//-----------------------------------------------------------------------
// TheTimes.h
// А. Николенко 12.11.2018
// 
// Всё о времени.
//
// Описание класса УНИВЕРСАЛЬНОГО ВРЕМЕНИ, который позволяет представить 
// время в любом необходимом масштабе и от любого необходимого начала 
// отсчёта, как в виде скаляра, так и в виде календарной даты и времени
//	- Представление времени в различных эпохах и масштабах
//	- Пересчёт времени между различными его представлениями
//	- Хранение времени с удержанием максимального колличества 
//	  значащих цыфр
//-----------------------------------------------------------------------
#if !defined THETIMES_H
#define THETIMES_H

#include <FlyTimeSource\\TheJD.h>
#include <FlyTimeSource\\TheDblTime.h>
#include <FlyTimeSource\\TheUT1UTC.h>

//-----------------------------------------------------------------------
// Структура элемента массива изменения секунды координации UT1 -
// - скачка секунды всемирного времени UT1
// Предполагается что скачёк происходит в момент времени смены 
// указанных суток (D, M, G), а именно вводится дополнительная секунда
// (секунда координации) 
// 23h59m58s, 23h59m59s --- +секунда координации ----> 23h59m60s --->
// далее новые сутки ----> 0h00m00s, 0h00m01s 
// Секунда координации вводится в полночь на Гринвиче, то есть в момент смены
// суток по всемирному времени, соответствекко по ДМВ это будет 3 часа ночи
typedef struct TheLeapSecond {
	double MJD ;		// Мод. юлианская дата скачка секунды	
	int    D ;			// День скачка 
	int    M ;          // Месяц 
	int    G ;          // Год
	double sec ;		// значение секунды координации 
} _TheLeapSecond ;

#define	Count_UTC_IAT_LEAP		28 

//-----------------------------------------------------------------------
typedef struct TheUTC1IAT {
	double MJD ;		// Мод. юлианская дата скачка секунды	
	double msec ;		// Отклонение шкалы времени в милисекундах
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
	// Разница между двумя моментами времени выраженная
	// в целых и дробных долях суток
	friend TheDblTime operator - (TheTimes& T1, TheTimes& T2) ;   

	TheDblTime	iat ;	// [ccc]  Атомное Время
	TheDblTime	UTC ;	// [ccc]  Всемирное координированное время
	TheDblTime	UT1 ;	// [ccc]  Всемирное время UT1
	TheDblTime	TT ;	// [ccc]  
	TheDblTime	TDB ;	// [ccc]  
	double		AT ;	// [JC]   Астрономическое вркмя для вычисления полиномов 
						// апроксимирующих астпроданные, в юлианских столетиях 
						// отсчитанное от эпохи J2000
	double  MST ;		// [град] Среднее солнечное время 
	double  TST ;		// [град] Истинное солнечное время
	double  S ;			// [град] Звёздный угол гринвического меридиана

	DATETIMEDMB DMB ;		// Дикретное московское время
	double      CoordSec ;  // Значение секунды координации

	// поправки UTC к атомному времени - скачки секунд
	static TheLeapSecond IAT_LEAP[Count_UTC_IAT_LEAP+1] ;

protected:
	// Поиск величины скачка "секунды" координации выраженного в секундах
	double FindLeapCoordSec(TheDblTime iat, bool fromJ2000) ;
	void   BuildTDBTTAT() ;
	void   BuildDMB() ;
	void   BuildLeapSec() ;
};

//-----------------------------------------------------------------------
#endif //#if !defined THETIMES_H
