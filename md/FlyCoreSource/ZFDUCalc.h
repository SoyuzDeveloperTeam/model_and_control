//-------------------------------------------------------------------------------
// ZFDUCalc.h
// А. Николенко 16.08.2018
//------------------------------------------------------------------------------- 
#ifndef ModDUCalc_H
#define ModDUCalc_H

#include <FlyCoreSource\\ModPUItem.h>
#include <FlyCoreSource\\ModPUSwitchOn.h>
#include <FlyCoreSource\\ModPU.h>
#include <FlyCoreSource\\ZCDU.h>

//------------------------------------------------------------------------------
#define M_MAXCOUNT_IMP 48

struct ZP {
  int    N ;                          // Номер в БД
  int    count ;                      // Число включений
  int    sk  [M_MAXCOUNT_IMP] ;       // Ориентация по включениям
  int    vit [M_MAXCOUNT_IMP] ;       // Витки (на момент включения ДУ)
  double t   [M_MAXCOUNT_IMP] ;       // Моменты включения ДУ
  double dtk [M_MAXCOUNT_IMP] ;       // Длительности работы (до отсечки)
  double dts [M_MAXCOUNT_IMP] ;       // Длительности работы (суммарная)
  double dtm [M_MAXCOUNT_IMP] ;       // Длительности работы (основного участка)
  double alfa[M_MAXCOUNT_IMP] ;       // Ориентация ДУ
  double beta[M_MAXCOUNT_IMP] ;       //
  char   isOnlyMain[M_MAXCOUNT_IMP] ; //
  int    numLhs ;
};

//------------------------------------------------------------------------------
FLYCORE_API int ZFPUCalcTimeMainFromdG(double m0, ZCDU& du, double* pdV1,
						  double* pdV2, double* pdt1, double* pdt2, 
						  double* pdms, double* pmk, double& tm, char* errmsg);
FLYCORE_API int ZFPUCalcTimeMainFromdV(double m0, ZCDU& du, double* pdV1,
						  double* pdV2, double* pdt1, double* pdt2, 
						  double* pdms, double* pmk, double& tm, char* errmsg);
FLYCORE_API int ZFPUCalcTimeMainFromAlldV(double m0, ZCDU& du, double* pdV1,
						  double* pdV2, double* pdt1, double* pdt2, 
						  double* pdms, double* pmk, double& tm, char* errmsg);
FLYCORE_API int ZFPUCalcTimeMainFromTime(double m0, ZCDU& du, double* pdV1,
						  double* pdV2, double* pdt1, double* pdt2, 
						  double* pdms, double* pmk, double& tm, char* errmsg);
FLYCORE_API int ZFPUCalcTimeMain(int var, double m0, ZCDU& du, double* pdV1,
						  double* pdV2, double* pdt1, double* pdt2, 
						  double* pdms, double* pmk, double& tm, char* errmsg);

FLYCORE_API int ZFPUBuild(ZCDU& DU, ZP& P, ZPU& PU);

//------------------------------------------------------------------------------
#endif // #ifndef ModDUCalc_H

