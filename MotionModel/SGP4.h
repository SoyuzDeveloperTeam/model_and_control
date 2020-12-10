// SGP4Propagator.h : Declaration of the CSL_SGP4Propagator

#ifndef __SL_SGP4PROPAGATOR_H_
#define __SL_SGP4PROPAGATOR_H_

#include <string.h>
#include "cstools.h"

/////////////////////////////////////////////////////////////////////////////
// CSL_SGP4Propagator
class CSL_SGP4Propagator
{
public:
	CSL_SGP4Propagator()
	{
		memset(&(m_orb),0,sizeof(m_orb));
		m_orb.xno = 10.0;
		strcpy( _bstrName,"");
		strcpy(_bstrTLE,"");
	}

// ISL_SGP4Propagator
public:
	bool get_OrbitElements(/*[out, retval]*/ SL_ORBELEMENTS *pVal);
	bool putref_OrbitElements(/*[in]*/ SL_ORBELEMENTS* newVal);
	bool put_OrbitElement(int ElementID, /*[in]*/ double newVal);
	bool getEpoch(/*[out,retval,ref]*/double* pmjdEpoch);
	bool getOrbitNumber(/*[in]*/ double doi, /*[out,retval,ref]*/ unsigned long* pnorbit);
	bool getECIStateVectors(/*[in]*/ double doi,/*[out,byref]*/ pos_vec* pPosVector,/*[out,byref]*/vel_vec *pVelVector);
//	STDMETHOD(getPosition)(/*[in]*/ VARIANT var_doi, /*[out,retval]*/ IDispatch** pIPosition );
	bool getECIPositionVar(/*[in]*/ double doi,/*[out,retval]*/ pos_vec* pVpos);
	bool getECIPosition(double doi, double* X,double* Y,double* Z);
	bool initFromName(char* bstrSOName, char* bstrInitSource, double mjdDOI);
	
private:

    SL_ORBELEMENTS		m_orb;
	char _bstrName[100];
	char _bstrTLE[512];
	
	int  ASCorDESC(double t0,double t1);

	int	 SGP4(int iflag,double dt, pos_vec* pos, vel_vec* vel);
	// SGP static stuff
	double beta, coef, eeta, delm, delo, aodp, capu, xmdf, aynl, elsq, 
	    temp, eosq, rdot, cosu, sinu, coef1, t2cof, t3cof, t4cof, t5cof, 
	    temp1, temp2, temp3, temp4, temp5, temp6, cos2u, sin2u, a, e;
    int i;
	double xno;
    double r, u;
    double betal, betao, omega, ecose, delmo, aycof, tcube, esine, 
	    a3ovk2, tempa, cosik, tempe, cosio, etasq, xmcof, xlcof;
    int isimp;
    double a1, sinio, x3thm1, qoms24, c2, c1, xnodp, c3, x1mth2, c4, c5, 
	    xmdot, x1m5th, psisq, sinmo, x7thm1, d2, d3, d4, xnode, templ, s4,
	     tfour, rfdot, xinck, rdotk, betao2, sinuk, cosuk, sinik, theta2;
    double theta4, xhdot1, ao, pl, omgadf, rk, uk, xl, xn, delomg, 
	    omgcof, perige, ux, uy, uz, vx, xnodcf, xnoddf, vy, vz, xnodek, 
	    omgdot, rfdotk, cosnok, cosepw, sinnok, sinepw, xnodot, pinvsq, 
	    eta, axn, ayn, epw, tsi, xll, xmp, tsq, xlt, xmx, xmy, del1, c1sq;
};

#endif //__SL_SGP4PROPAGATOR_H_
