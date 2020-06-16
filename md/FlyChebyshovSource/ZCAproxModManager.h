//-------------------------------------------------------------------------------
// ZCAproxMod.h : 
// Диспетчер апроксимирующих моделей
//
// А. Николенко 15.03.2019
//-------------------------------------------------------------------------------
#pragma once
#ifndef ZC_APROX_MOD_MNG_H
#define ZC_APROX_MOD_MNG_H

#include <FlyChebyshovSource\\ZCAproxMod.h>

enum APROX_DATA_TYPE { 
	APR_DATA_POLE = 0, APR_DATA_MUT = 1, APR_DATA_PREC = 2,
	APR_DATA_MOON = 3, APR_DATA_SUN = 4};

class FLYCHEBYSHOV_API ZCAproxModManager
{
public:
	ZCAproxModManager();
	~ZCAproxModManager();

	int InitDefault(double t);
	int Load(double fromTime, double toTime);
	int Save();

protected:
	vector<ZCAproxMod> ModPole;
	vector<ZCAproxMod> ModNut;
	vector<ZCAproxMod> ModPrec;
	vector<ZCAproxMod> ModMoon;
	vector<ZCAproxMod> ModSun;
};

extern ZCAproxModManager AproxMng;

#endif // #ifndef ZC_APROX_MOD_MNG_H

