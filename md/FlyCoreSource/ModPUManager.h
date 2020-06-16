//------------------------------------------------------------------------
// ModPUManager.h
// �. ��������� 15.08.2018
//------------------------------------------------------------------------
#ifndef ModPUMANAGER_H
#define ModPUMANAGER_H

#include <iterator>
#include <FlyCoreSource\\ModPUItem.h>
#include <FlyCoreSource\\ModPUSwitchOn.h>
#include <FlyCoreSource\\ModPU.h>

//------------------------------------------------------------------------
// �������� �������� ����������
//------------------------------------------------------------------------
#define MAX_PU_COUNT_MOD 36 

class FLYCORE_API ZPUManager {
public :
	ZPUManager() ;
	~ZPUManager() ;
	void Init() ;

	// ������� ��� ����������� ��������� ����������
	void Clear() ;
	// �������� ������� ������ � ���������� ��������
	bool isEmpty() ;
	// ����������� ������������� �������� ����������
	int  Size() ;
	// �������� ��������� ���������� � ������ 
	int  Add(ZPU &I) ;
	ZPU* Add(int* ind=nullptr) ;
	void operator << (ZPU &I) ;
	// ������ ��������� ����������
	int  Set(ZPU &I, int ind) ;
	// ������� ��������� ����������
	int  Del(int ind=-1) ;
	// ������ � �������� ��������� ����������
	ZPU* Get(int ind) ;

	// ��������� �� �� 
	int LoadFromBD(int ka, int pu, ZPU &I) { return 0 ; } 
	// ��������� � �� 
	int SaveToBD  (int ka, int pu, ZPU &I) { return 0 ; } 

	// �������� ������� ����� ������� �� ��� � �������� ���������� ���� ��������������
	int  TimeCheckForStep(double t, int dir, long* IDDUMSG=nullptr, double* maxstep=nullptr) ; 
	//int  TimeCheckPostStep(double t, int dir, long& IDMSG) ;
	// ����� ���� ��������
	void ClearIndex() ;
	// ���������� �������� � ����������� ��������� ����� ������� �� ���
	void Indexing(double t, int dir) ;
	// ��������� ����� ������� �� ���
	void GetTimePoint(int& Key, double& PrevT, double& NextT, long& PrevIDMSG, long& NextIDMSG) ;
	// ������ ��������� ��� ������ ������ ���
	int  CalcRLN(double t, double m, double* arln, double* pMs) ;

protected :
	// ����������� ������ �������� ����������
	ZPU PU[MAX_PU_COUNT_MOD] ;
	// ����� ������������� �������� ���������� 
	int Count ;
	// ������� ��������
	int    IndexVN[MAX_PU_COUNT_MOD] ;
	int    IndexVP[MAX_PU_COUNT_MOD] ;
	int    IndexV [MAX_PU_COUNT_MOD] ;
	int    IndexU [MAX_PU_COUNT_MOD] ;
	double TIndex ;

	// ������ ������� ������� ������ ������ ��� (���������, ���������� �� ��� ������, ����� ���������� ������� �� ���������)
	double NextTimePoint ;
	double PrevTimePoint ;
	int    TimePointKey ;

	long PrevIDMSG ;
	long NextIDMSG ;
	long CurIDMSG ;
} ;

//------------------------------------------------------------------------
#endif // #ifndef ModPUMANAGER_H