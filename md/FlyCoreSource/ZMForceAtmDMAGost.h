//---------------------------------------------------------------------------
// ZMForceAtmDMAGost.h
// Вычисление плотности динамической атмосферы по ГОСТам
// А. Николенко 07.11.2018
//---------------------------------------------------------------------------
#ifndef ZMForceAtmDMAGost_H
#define ZMForceAtmDMAGost_H

class ZCISAManager;

int CalcModAtm_DMA_GOST(VersionATM vatm, double AtomicTime, double* XYZg, 
						ZCISAManager* ISAManager, double *pdPlotAtm);

//---------------------------------------------------------------------------
#endif //#ifndef ZMForceAtmDMAGost_H
