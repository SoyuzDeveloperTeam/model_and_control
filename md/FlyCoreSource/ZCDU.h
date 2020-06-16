//-------------------------------------------------------------------------------
// ZCDU.h
// А. Николенко 16.08.2018
//------------------------------------------------------------------------------- 
#ifndef ModDU_H
#define ModDU_H
//
struct ZDUItem {
  double p ;	// Тяга двигателя			в кгс
  double pu ;	// Удельная тяга двигателя	в м/сек
  double ms ;	// Секундный расход			в кг/сек = p/pu
  double t ;	// Время участка			в сек		
};
//

class FLYCORE_API ZCDU {
public :
	ZCDU() { Clear(); };
	~ZCDU(){ Clear(); };
	void Clear() {
		ka = n = k = ip = mu = 0 ; mp = 0 ; mt = 0 ; i = 0 ;
		isNotValiDU = 0 ; isOnlyMain = 0 ; Var = 0 ; isChange = 0 ;
		abrev[0] = '\0' ;
		koment[0] = '\0' ;
		if (i) delete[] i ; i = 0 ;
	}
	void Clone(ZCDU& D) {
		ka   = D.ka ;
		n	 = D.n ;
		k    = D.k ;
		ip   = D.ip ;
		mu   = D.mu ;
		mp   = D.mp ;
		mt   = D.mt ;
		Var  = D.Var ;
		alfa = D.alfa ;
		beta = D.beta ;
		sprintf(abrev,  "%s", D.abrev) ;
		sprintf(koment, "%s", D.koment) ;
		isChange    = 0 ;
		isNotValiDU = D.isNotValiDU ;
		isDimKmS    = D.isDimKmS ;
		isOnlyMain  = D.isOnlyMain ;
		if (i) delete[] i ; i = 0 ;
		i = new ZDUItem[k] ;
		memcpy(i, D.i, k*sizeof(ZDUItem)) ;
	} ;
	void*  PointData() { return((void*)&ka) ; } ;
	int    SizeMainData() { return(6*sizeof(int)+4*sizeof(double)+178+4*sizeof(bool)+sizeof(ZDUItem*)) ; } ;
	int    SizeData () { return( SizeMainData ( ) + k * sizeof( ZDUItem ) ) ; } ;
	void   SetMainTraction(double P) { i[mu].p = mp = P ; }
	double GetMainTraction() { return mp ; }

	int    ka ;                // Номер КА
	int    n ;                 // Номер ДУ
	int    k ;                 // Число участков моделирования
	int    ip ;                // Признак импульса последействия
	int    mu ;                // Номер основного участка
	int    Var ;               //
	double mp ;                // Тяга основного участка
	double mt ;                // Максимальная длительность основного участка
	double alfa ;              // Ориентация ДУ в связанной СК
	double beta ;              //
	char   abrev[50] ;
	char   koment[128] ;
	bool   isChange ;
	bool   isNotValiDU ;
	bool   isDimKmS ;
	bool   isOnlyMain ;
	ZDUItem* i ;
} ;
//
FLYCORE_API int ZFDUFindMain(ZCDU& DU);
FLYCORE_API int ZFisNotValiDU(ZCDU& DU);
//
#endif // #define ModDU_H


