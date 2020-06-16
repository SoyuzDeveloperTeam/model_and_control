//-------------------------------------------------------------------------------
// ZMForceAtm.h
// А. Николенко 03.08.2018
//-------------------------------------------------------------------------------
class ZMAtmSMA ;
class ZCISAManager ;
int ZFCalcSAtm(double t, double* Rgsk, ZLSF& LSF, ZNU& NU, ZMAtmSMA* pAtm, double* UAsk) ;
int ZFCalcDAtm(double t, double* Rgsk, ZLSF& LSF, ZNU& NU, ZCISAManager* m_ISAManager, double* UAsk, double* atmro=nullptr) ;

//-------------------------------------------------------------------------------