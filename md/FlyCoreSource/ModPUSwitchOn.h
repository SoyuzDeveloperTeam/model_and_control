//------------------------------------------------------------------------
// ModPUSwitchOn.h
// �. ��������� 15.08.2018
//------------------------------------------------------------------------
#ifndef ModPUSWITCHON_H
#define ModPUSWITCHON_H

#include <iterator>
class ZPUManager ;

//------------------------------------------------------------------------
// ��������� ��������� ����������
//------------------------------------------------------------------------
class FLYCORE_API ZVPU {
public :
	friend ZPUManager ;
	ZVPU() ;
	~ZVPU() ;

	void Clear() ;
	int  Size() ;
	bool isEmpty() ;

	// �������� ������� � ������ 
	ZPUItem* Add(int* ind=nullptr) ;
	void     Add(ZPUItem &I) ;
	void     operator << (ZPUItem &I) ;
	// ������ �������
	int      Set(ZPUItem &I, int ind) ;
	// ������� �������
	int      Del(int ind, int Count=1) ;
	// ������ � ��������� �������
	ZPUItem* Get(int ind) ;

	// ����� ������ ���������
	double TS() ;
	// ����� ����� ���������
	double TE() ;
	// ���������� �������� �� �������
	void   SortItem() ;

protected:
	vector<ZPUItem> U ;
	int             NumDU ;
} ;

#define I_ZVPU vector<ZVPU>::iterator 
FLYCORE_API bool operator < (ZVPU &U1, ZVPU &U2);

//------------------------------------------------------------------------
#endif // #ifndef ModPUSWITCHON_H