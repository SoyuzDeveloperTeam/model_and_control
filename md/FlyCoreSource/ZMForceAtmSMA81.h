//-------------------------------------------------------------------------------
// ZMForceAtmSMA81.h
// �. ��������� 03.08.2018
//-------------------------------------------------------------------------------
#ifndef MOD_ATM_SMA_81_H
#define MOD_ATM_SMA_81_H

#include <FlyCoreSource\\ZMForceAtmSMA.h>

class ZMAtmSMA81 : public ZMAtmSMA  {
public:
	ZMAtmSMA81() { };
	~ZMAtmSMA81() { };
	// �� ����� ��������� �������� � ��� - X (x,y,z, Vx,Vy,Vz) � ����  
	// ��������� Ro - ��������� ��������� � ��/�3
	virtual int Calc(double* X, double& Ro) ;
	virtual int Calc4(double H, double& Ro) ;

protected:
} ;

//-------------------------------------------------------------------------------
#endif