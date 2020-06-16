//---------------------------------------------------------------------------
// ZMForceAtmMsis.h
// ������ ��������� ��������� �� ������� MSIS-90 ��� MSIS-2000
//---------------------------------------------------------------------------
#ifndef ZMForceAtmMsis_H
#define ZMForceAtmMsis_H

class ZCISAManager;
//
// HBL		- HBL[0] ������ � ��, HBL[1] ������ � ����, HBL[2] ������� � ���� 
// pdPlotAtm- ��������� ��������� � ��/�3 
FLYCORE_API int CalcModAtm_DMA_MSIS(VersionATM vatm, double ta, double* HBL, 
									ZCISAManager* ISAManager,
								    double *pdPlotAtm);
//
// ta		- ������� ����� � ��� �� 1975 �����
// ALT		- ������ � ��
// GLAT		- ������ � ��������
// GLONG	- ������� � ��������
// F107A	- ������ F107 ���������� �� ��������� 90 �����
// F107		- ������ F107
// AP		-
// pdPlotAtm- ��������� ��������� � ��/�3 
FLYCORE_API int DMA_MSIS_1990(double ta, double ALT,
							  double GLAT, double GLONG, double F107A,
							  double F107, double AP[], double *pdPlotAtm) ;
FLYCORE_API int DMA_MSIS_2000(double ta, double ALT,
							  double GLAT, double GLONG, double F107A,
							  double F107, double AP[], double *pdPlotAtm) ;

//---------------------------------------------------------------------------
#endif //#ifndef ZMForceAtmMsis_H
