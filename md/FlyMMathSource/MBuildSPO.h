#ifndef M_BUILD_SPO_HEADER
#define M_BUILD_SPO_HEADER

//------------------------------------------------------------------------------
//
FLYMMATH_API int MBuildOMIV_a(double i, double a, double& T, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildOMIV_T(double i, double T, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildOMIV_hs(double i, double hs, double& T, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildOMIV_dL(double i, double N, double dL, double&  T, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildOMIV_NsNv(double i, double Ns, double Nv, double& T, double& p, double& e1, double& e2, char* Msg = 0);
//------------------------------------------------------------------------------
FLYMMATH_API int MBuildDU_a(double i, double a, double& T, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildDU_T(double i, double T, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildDU_hs(double i, double hs, double& T, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildDU_dL(double i, double N, double dL, double&  T, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildDU_NsNv(double i, double Ns, double Nv, double& T, double& p, double& e1, double& e2, char* Msg = 0);
//------------------------------------------------------------------------------
FLYMMATH_API int MBuildEL_ahBh(double i, double a, double he, int Varh, double Bhe, int VarBh, double& p, double& e1, double& e2, double& uhe, char* Msg = NULL);
FLYMMATH_API int MBuildEL_ThBh(double i, double T, double he, int Varh, double Bhe, int VarBh, double& p, double& e1, double& e2, double& uhe, char* Msg = NULL);
FLYMMATH_API int MBuildEL_HshBh(double i, double hs, double he, int Varh, double Bhe, int VarBh, double& p, double& e1, double& e2, double& uhe, char* Msg = NULL);
FLYMMATH_API int MBuildEL_dLhBh(double i, double N, double dL, double he, int Varh, double Bhe, int VarBh, double& T, double& p, double& e1, double& e2, double& uhe, char* Msg = NULL);

FLYMMATH_API int MBuildEL_a(double i, double a, double e, double w, double& T, double& p, double& e1, double& e2, char* Msg = NULL);
FLYMMATH_API int MBuildEL_dLew(double i, double N, double dL, double e1, double e2, double&  T, double& p, double& uhe, char* Msg = NULL);
FLYMMATH_API int MBuildEL_NsNv(double i, double Ns, double Nv, double he, int Varh, double Bhe, int VarBh, double& T, double& p, double& e1, double& e2, double& uhe, char* Msg = NULL);
FLYMMATH_API int MBuildEL_hs(double i, double  hs, double e1, double e2, double& T, double& p, char* Msg = NULL);
//------------------------------------------------------------------------------
//
FLYMMATH_API int MBuildSSOMIV_a(double a, double& i, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildSSOMIV_T(double T, double& i, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildSSOMIV_hs(double hs, double& T, double& i, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildSSOMIV_dL(double N, double dL, double&  T, double& i, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildSSOMIV_NsNv(double Ns, double Nv, double& T, double& i, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildSSOMIV_i(double i, double& T, double& p, double& e1, double& e2, char* Msg = 0);
//------------------------------------------------------------------------------
FLYMMATH_API int MBuildSSDU_a(double a, double& i, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildSSDU_T(double T, double& i, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildSSDU_hs(double hs, double& T, double& i, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildSSDU_dL(double N, double dL, double&  T, double& i, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildSSDU_NsNv(double Ns, double Nv, double& T, double& i, double& p, double& e1, double& e2, char* Msg = 0);
FLYMMATH_API int MBuildSSDU_i(double i, double& T, double& p, double& e1, double& e2, char* Msg = 0);
//------------------------------------------------------------------------------
FLYMMATH_API int MBuildSSEL_a(double a, double  e, double w, double& T, double& p, double& e1, double& e2, double& uhe, char* Msg = 0);
FLYMMATH_API int MBuildSSEL_T(double T, double he, int Varh, double Bhe, int VarBh, double& i, double& p, double& e1, double& e2, double& uhe, char* Msg = 0);
FLYMMATH_API int MBuildSSEL_dL(double N, double dL, double he, int Varh, double Bhe, int VarBh, double& T, double& i, double& p, double& e1, double& e2, double& uhe, char* Msg = 0);
FLYMMATH_API int MBuildSSEL_NsNv(double Ns, double Nv, double he, bool Varh, double Bhe, bool VarBh, double& T, double& i, double& p, double& e1, double& e2, double& uhe, char* Msg = 0);
FLYMMATH_API int MBuildSSEL_i(double i, double he, int Varh, double Bhe, int VarBh, double& T, double& p, double& e1, double& e2, double& uhe, char* Msg = 0);
FLYMMATH_API int MBuildSSEL_iew(double i, double  e, double w, double& T, double& p, double& e1, double& e2, double& uhe, char* Msg = 0);
//------------------------------------------------------------------------------
FLYMMATH_API double MATC00(double T);
FLYMMATH_API int    MATC20(double i, double e1, double e2, double T, double& a);
FLYMMATH_API double MTAC00(double a);
FLYMMATH_API double MAdLC00(double i, double dL, double N);
FLYMMATH_API double ME1B20(double i, double p);
FLYMMATH_API double MdaddLC00(double a, double N, double ddL);
FLYMMATH_API double MdadciC00(double a, double dci);
FLYMMATH_API double MdadTC00(double dT, double a);
FLYMMATH_API double MTdrB20(double i, double e1, double e2, double* pp, double* pa);
FLYMMATH_API double MdLTB20(double i, double T, double N, double p);
FLYMMATH_API int    MHminmax(double i, double p, double e1, double e2, double& hmin, double& hmax, double* umin = 0, double* umax = 0);
//------------------------------------------------------------------------------
#endif // #ifndef M_BUILD_SPO_HEADER
