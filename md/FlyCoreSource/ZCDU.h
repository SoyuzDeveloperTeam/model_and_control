//-------------------------------------------------------------------------------
// ZCDU.h
// �. ��������� 16.08.2018
//------------------------------------------------------------------------------- 
#ifndef ModDU_H
#define ModDU_H
//
struct ZDUItem {
  double p ;	// ���� ���������			� ���
  double pu ;	// �������� ���� ���������	� �/���
  double ms ;	// ��������� ������			� ��/��� = p/pu
  double t ;	// ����� �������			� ���		
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

	int    ka ;                // ����� ��
	int    n ;                 // ����� ��
	int    k ;                 // ����� �������� �������������
	int    ip ;                // ������� �������� �������������
	int    mu ;                // ����� ��������� �������
	int    Var ;               //
	double mp ;                // ���� ��������� �������
	double mt ;                // ������������ ������������ ��������� �������
	double alfa ;              // ���������� �� � ��������� ��
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


