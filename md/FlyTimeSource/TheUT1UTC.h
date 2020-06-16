//-----------------------------------------------------------------------
// TheUT1UTC.h
// �. ��������� 23.11.2018
// 
// ������������� ���������� UTC �� UT1
//-----------------------------------------------------------------------
#if !defined THE_UT1_UTC_H
#define THE_UT1_UTC_H

#include <FlyTimeSource\\TheDblTime.h>

typedef struct UTCAmendmentItem {
	double mjd ;		// ����� ��������� ���� (������ �����)
	double DUT1UTC ;	// �������� �������� UT1-UTC � ������������  	
} _UTCAmendmentItem ;

class FLYTIME_API TheUT1UTC {
public :
	TheUT1UTC() ;
	~TheUT1UTC() ;
	// �������������� ��������
	int Load() ;
	int IsLoad() { return isLoad ; }
	// ���������� ������� ����� UTC � UT1
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

 