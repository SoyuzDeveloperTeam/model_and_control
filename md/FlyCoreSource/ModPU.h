//------------------------------------------------------------------------
// ModPU.h
// �. ��������� 15.08.2018
//------------------------------------------------------------------------
#ifndef ModPU_H
#define ModPU_H

#include <iterator>
class ZPUManager ;

//------------------------------------------------------------------------
// ��������� ����������
//------------------------------------------------------------------------
class FLYCORE_API ZPU {
public :
	friend ZPUManager ;
	ZPU() ;
	~ZPU() ;

	void Clear() ;
	int  Size() ;
	bool isEmpty() ;

	// �������� ��������� � ������ 
	ZVPU* Add(int* ind=nullptr) ;
	void  Add(ZVPU &I) ;
	void  operator << (const ZVPU &I) ;
	// ������ ���������
	int   Set(ZVPU &I, int ind) ;
	// ������� ���������
	int   Del(int ind, int Count=1) ;
	// ������ � ��������� ���������
	ZVPU* Get(int ind) ;

	// ����� ������ ���������
	double TS() ;
	// ����� ����� ���������
	double TE() ;
	// ���������� �������� �� �������
	void   SortItem() ;

	vector<ZVPU> V ;
	int          NumPU ;
	bool		 IsOn ;		// ������� ���������� ������ ��������� ����������
} ;

//------------------------------------------------------------------------
#endif // #ifndef ModPU_H
