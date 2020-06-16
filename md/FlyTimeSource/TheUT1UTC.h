//-----------------------------------------------------------------------
// TheUT1UTC.h
// А. Николенко 23.11.2018
// 
// Моделирование отклонения UTC от UT1
//-----------------------------------------------------------------------
#if !defined THE_UT1_UTC_H
#define THE_UT1_UTC_H

#include <FlyTimeSource\\TheDblTime.h>

typedef struct UTCAmendmentItem {
	double mjd ;		// модиф юлианская дата (начало суток)
	double DUT1UTC ;	// значение разности UT1-UTC в милисекундах  	
} _UTCAmendmentItem ;

class FLYTIME_API TheUT1UTC {
public :
	TheUT1UTC() ;
	~TheUT1UTC() ;
	// Первоначальная загрузка
	int Load() ;
	int IsLoad() { return isLoad ; }
	// Вычисление разницы между UTC и UT1
	int Amendment(TheDblTime& UTC, double& DUT1) ;

protected :
	void CalcFromIndex(double MJD, int Index, double& DUT1) ;

	vector <UTCAmendmentItem> VDltUTC ;
	bool   isLoad ;
	double lastMJD ;
	double BMJD ;
	double EMJD ;
	int    lastIndex ;
	int    CountItems ; 
} ;

#endif // #if !defined THE_UT1_UTC_H

 