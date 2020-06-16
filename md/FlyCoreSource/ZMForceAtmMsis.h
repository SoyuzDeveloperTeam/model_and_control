//---------------------------------------------------------------------------
// ZMForceAtmMsis.h
// Расчет плотности атмосферы по моделям MSIS-90 или MSIS-2000
//---------------------------------------------------------------------------
#ifndef ZMForceAtmMsis_H
#define ZMForceAtmMsis_H

class ZCISAManager;
//
// HBL		- HBL[0] высота в км, HBL[1] широта в град, HBL[2] долгота в град 
// pdPlotAtm- плотность атмосферы в кг/м3 
FLYCORE_API int CalcModAtm_DMA_MSIS(VersionATM vatm, double ta, double* HBL, 
									ZCISAManager* ISAManager,
								    double *pdPlotAtm);
//
// ta		- атомное время в ссс от 1975 годда
// ALT		- высота в км
// GLAT		- широта в градусах
// GLONG	- долгота в градусах
// F107A	- индекс F107 осреднённый на интервале 90 суток
// F107		- индекс F107
// AP		-
// pdPlotAtm- плотность атмосферы в кг/м3 
FLYCORE_API int DMA_MSIS_1990(double ta, double ALT,
							  double GLAT, double GLONG, double F107A,
							  double F107, double AP[], double *pdPlotAtm) ;
FLYCORE_API int DMA_MSIS_2000(double ta, double ALT,
							  double GLAT, double GLONG, double F107A,
							  double F107, double AP[], double *pdPlotAtm) ;

//---------------------------------------------------------------------------
#endif //#ifndef ZMForceAtmMsis_H
