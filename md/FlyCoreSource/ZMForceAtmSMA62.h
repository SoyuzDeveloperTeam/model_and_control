//-------------------------------------------------------------------------------
// ZMForceAtmSMA62.h
// А. Николенко 03.08.2018
//-------------------------------------------------------------------------------
#ifndef MOD_ATM_SMA_62_H
#define MOD_ATM_SMA_62_H

#include <FlyCoreSource\\ZMForceAtmSMA.h>

class ZMAtmSMA62 : public ZMAtmSMA  {
public:
	ZMAtmSMA62() { };
	~ZMAtmSMA62() { };
	// На входе параметры движения в ГСК - X (x,y,z, Vx,Vy,Vz) в дткм  
	// Результат Ro - плотность атмосферы к кг/м3
	virtual int Calc(double* X, double& Ro) ;
	virtual int Calc4(double H, double& Ro) ;
protected:
} ;

//-------------------------------------------------------------------------------
#endif