//------------------------------------------------------------------------
// ModPUItem.h
// �. ��������� 15.08.2018
//------------------------------------------------------------------------
#ifndef ModPUITEM_H
#define ModPUITEM_H

#include <iterator>

//------------------------------------------------------------------------
// ������� ��������� ����������
//------------------------------------------------------------------------
typedef enum varPUItem{varPU_ppu, varPU_pms, varPU_pums} ZVARPU ;

struct SPUItem {
	ZVARPU var ;
	double t ;       // ����� ��������� � [���]
	double dt ;      // ������������ ��������� � [���]
	double P ;       // ���� � [���]
	union {
		double Pu ;  // �������� ���� � [���]
		double ms ;  // ��������� ������ ������� [��/���]
	} ;
	double dP ;      // ����������� �� ���� �� ������� ���/���
	union {
		double dPu ; // ����������� �� �������� ���� ��
		double dms ; // ����������� �� �������� ���� [��/���2]
	} ;
	double a ;       // ���������� ��������, �������� [����]
	double b ;       // ������ [����]
	double da ;      // �������� ��������� ������� ����, �� �������� [����/���]
	double db ;      // �������
};

#define ZVarPUpms SPUItem::varPU_pms
#define ZVarPUppu SPUItem::varPU_ppu

//------------------------------------------------------------------------
class FLYCORE_API ZPUItem : public SPUItem {
public :
	ZPUItem() ;
	// ����� ������ ���������
	double TS() ;
	// ����� ����� ���������
	double TE() ;
	// ������ ��������� � ����������� ��
	int CalcARLN (double t, double m, double* Arln, double* pMs=0, double* pP=0, double* pPu=0) ;  
private :
} ;

#define I_ZPUItem vector<ZPUItem>::iterator 

FLYCORE_API bool operator < (const ZPUItem &U1, const ZPUItem &U2);

//------------------------------------------------------------------------
// ��������������� ������������� ������� ������ ��
class FLYCORE_API ZPUI_tauP : public ZPUItem {
public : 
	ZPUI_tauP(double t_, double dt_):ZPUItem() { t=t_ ; dt=dt_ ; }
} ;
//------------------------------------------------------------------------
// ��������������� ������������� ������� ������ ��
class FLYCORE_API ZPUI_tauN : public ZPUItem {
public : 
	ZPUI_tauN(double t_, double dt_):ZPUItem() { t=t_ ; dt=dt_ ; a=180 ; }
} ;
//------------------------------------------------------------------------
// ���������� ������������� ������� ������ ��
class FLYCORE_API ZPUI_normP : public ZPUItem {
public : 
	ZPUI_normP(double t_, double dt_):ZPUItem() { t=t_ ; dt=dt_ ; a=90 ; }
} ;
//------------------------------------------------------------------------
// ���������� ������������� ������� ������ ��
class FLYCORE_API ZPUI_normN : public ZPUItem{
public : 
	ZPUI_normN(double t_, double dt_):ZPUItem() { t=t_ ; dt=dt_ ; a=270 ; }
} ;

//------------------------------------------------------------------------

#endif // #ifndef ModPUITEM_H