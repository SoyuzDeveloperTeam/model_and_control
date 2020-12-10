/* ----------------------------------------------------------- */
/* ---------  SPUTNIX Small Satellite Modeler   -------------- */
/* ----------------------------------------------------------- */

/* This  file is  part  of the  SPUTNIX Small  Satellite  Modeler 
 * C/C++  source  code package.  First public release: 12/04/2013
 * The most fresh version can be found at <http://www.sputnix.ru>
 * Copyright(C) 2001-2013 Stanislav Karpenko <s.o.karpenko@gmail.com>
 * This program is free software;  you can redistribute it and/or
 * modify  it under  the terms of  the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.*/

#include <math.h>

#include "cstools.h"
#include "timetools.h"
#include "mathtools.h"


#define EARTH_F		1.0/298.25		  //WGS84
#define EARTH_A		6378137.0		//WGS84
#define EARTH_E2    2*EARTH_F - EARTH_F*EARTH_F  
//#define XKMPER      6378.135



//=============================================================================--Math tools
static double Modulus(double arg1, double arg2)
{
	double modu;
	modu = arg1 - (long)(arg1/arg2) * arg2;
	if (modu >= 0.0)	return modu;
	else	return modu + arg2;
}


double AcTan(double sinx, double cosx)
{
	double ret;
	if (cosx == 0.0)	{
		if (sinx > 0.0)
			ret = PI/2.0;
		else
			ret = 3.0*PI/2.0;
	}
	else	{
		if (cosx > 0.0)
			ret = atan(sinx/cosx);
		else
			ret = PI + atan(sinx/cosx);
	}
	return ret;
}



//===============================================================================================

void ECI_XYZtoECR_LLA(double mjd, pos_vec* pos, lla_vec* lla)
{
	double lat,lon,alt;
	double theta,r,e2,phi,c;
	
	theta = AcTan(pos->y,pos->x);
	//lon = atan2(pos->x,pos->y) - ThetaG(mjd);
//	if (lon < -PI) lon = lon + TWOPI;
	lon = Modulus(theta - ThetaG(mjd),2.0*PI);
	r = sqrt(sqr(pos->x) + sqr(pos->y));
	e2 = EARTH_F*(2.0 - EARTH_F); //- this is a const ??
	lat = atan2(pos->z,r);
	do	{
		phi = lat;
		c = 1.0/sqrt(1.0 - e2*sqr(sin(phi)));
		lat = atan2(pos->z + EARTH_A*c*e2*sin(phi),r);
	}	while (fabs(lat - phi) > 1E-10);
	alt = r/cos(lat) - EARTH_A*c;

	lla->lon = lon*RAD2DEG;   // radians
	if (lla->lon > 180.0) lla->lon = - 360.0 + lla->lon ;
	//else                  lla->lon;
	lla->lat = lat*RAD2DEG;   // radians
	lla->alt = alt;			// kilometers
}

int CS_ECR_XYZtoTOP_AER(const pos_vec* posv, const lla_vec* llav, int fZenithOnly, aer_vec* aerv)
{

    int			i;          
    double	 norm;		  
    double	 normVec[3];
    double	 slat;		  
    double	 slon;		 
    double	 clat;		 
    double	 clon;		
    double  localVert[3];	 
    double  dotProd;	  				     
    double  projVec[3];	
	pos_vec ecr_top ;
	pos_vec relpos;

	
	//TO DO - check inputs!
	/*** Define slat, slon, clat, clon ***/

    slat = sin(llav->lat*DEG2RAD);
    slon = sin(llav->lon*DEG2RAD);
    clat = cos(llav->lat*DEG2RAD);
    clon = cos(llav->lon*DEG2RAD);

	//calc. relative pos vector
	CS_GEO_LLAtoECR_XYZ(llav,&ecr_top );
	relpos.x = posv->x - ecr_top.x;
	relpos.y = posv->y - ecr_top.y;
	relpos.z = posv->z - ecr_top.z;

    norm = sqrt(relpos.x*relpos.x + relpos.y*relpos.y + relpos.z*relpos.z);
    if (norm == 0.0)
    {
       return 1;
    }

    normVec[0] = relpos.x/norm;
    normVec[1] = relpos.y/norm;
    normVec[2] = relpos.z/norm;
    
    /*** Compute the local vertical vector  ***/

    localVert[0] = clat * clon;
    localVert[1] = clat * slon;
    localVert[2] = slat;
    
    /*** Compute the zenith angle of the vectorECR vector at the look point by
         first performing dot product of the norm of the look point and the
         normalized Input Vector. Then arc-cosine of the dot product gives
         required zenith angle of the vectorECR vector. ***/

    dotProd = localVert[0] * normVec[0] + localVert[1] * normVec[1] + 
		  localVert[2] * normVec[2];

    /*** If vectorECR is at zenith (dotProd > 0.9999999), zenith = 0.0 and the
         azimuth will be indeterminate. In this case set zenith = 0.0, 
	 azimuth = 0.0 (if requested), and return. ***/

    if (dotProd > 0.9999999)   /*  object is at zenith, azimut is invalid ! */
    {
		aerv->el = 90.0;
        aerv->az = 0.0;   
		fZenithOnly = 1;
    }
    else
	{
        aerv->el = (HALFPI - acos(dotProd)) * RAD2DEG;
	}

    if (aerv->el < 0.0)
    {//below horizont
		aerv->az = 0.0; 
		//fZenithOnly = 1; since v.2.2.2
    }
    
    if (!fZenithOnly)
	{
       /* Define projection of the normVec on the Ellipsoid ***/
	    for (i=0; i<3; i++)  projVec[i] = normVec[i] - localVert[i] * dotProd;
	   /* Compute the azimuth of the vectorECR at the look point ***/
        aerv->az = atan2(-projVec[0]*slon + projVec[1]*clon,
			             -slat*(projVec[0]*clon + projVec[1]*slon) + projVec[2]*clat);

		aerv->az *= RAD2DEG;
		if (aerv->az < 0) aerv->az += 360;
    }

	aerv->range = sqrt(relpos.x*relpos.x + relpos.y*relpos.y + relpos.z*relpos.z);

    return 0;
}

int CS_ECI_XYZtoECR_XYZ(const pos_vec* pposECI, double mjdDOI, pos_vec* pposECR)
{
	double gast;

	gast = TC_MJDtoGAST(mjdDOI);
	rotateVec1Axis((double*)pposECI, -gast, 3, (double*)pposECR);

	return 0;

}

int CS_ECR_XYZtoECI_XYZ(const pos_vec* pposECR, double mjdDOI, pos_vec* pposECI)
{
	double gast;

	gast = TC_MJDtoGAST(mjdDOI);
	rotateVec1Axis((double*)pposECR, -gast, 3, (double*)pposECI); // Check sign! 26012012!!!

	return 0;
}


int CS_GEO_LLAtoECR_XYZ(const lla_vec* plla, pos_vec* pposECR)
{
	const double equatRad_A=6378137.0;        /* equatorial radius */
	const double polarRad_C=6356752.314245;    /* polar radius */
	const double flatFac=3.35281068123811075E-3;

	double  distOfPoint;    /* distance of point from Earth's axis */
    double  recip;          /* reciprocal of the radius of curvature in a
                                    plane orthogonal to the meridian */
	double sinlat;
	
	sinlat = sin(plla->lat*DEG2RAD);
	/* compute the reciprocal of the radius of curvature in a plane orthogonal
       to the meridian */

    recip = 1.0 / sqrt(1 - (2*flatFac - flatFac*flatFac) * sinlat * sinlat);
    distOfPoint = ((equatRad_A * recip) + plla->alt) * cos(plla->lat *DEG2RAD);
    
    /* calculate the ECR coordinates */

    /* calculate the x coordinate */
    pposECR->x = distOfPoint * cos(plla->lon *DEG2RAD);

    /* calculate the y coordinate */
    pposECR->y = distOfPoint * sin(plla->lon *DEG2RAD);

    /* calculate the z coordinate */
    pposECR->z = ((equatRad_A * (1-flatFac) * (1-flatFac) * recip) + plla->alt) *  sinlat;

	return 0;
}

int CS_GEO_LLAtoECI_XYZ(const lla_vec* lla, double mjdDOI, pos_vec* pposECI)
{
	double gast;
	pos_vec posECR;
	gast = TC_MJDtoGAST(mjdDOI);
	CS_GEO_LLAtoECR_XYZ(lla,&posECR);
	rotateVec1Axis((double*)&posECR, -gast, 3, (double*)pposECI);
	return 0;
}

int CS_ECI_XYZtoTOP_AER(const pos_vec* ppopECI,const lla_vec* pllaTopoCenter, double mjdDOI, aer_vec* paer)
{
//	pos_vec posECR_TopCenter;
	pos_vec posECR_Obj;
	
//	CS_GEO_LLAtoECR_XYZ(pllaTopoCenter,&posECR_TopCenter);
	CS_ECI_XYZtoECR_XYZ(ppopECI,mjdDOI,&posECR_Obj);
	//calc the object's rel. vector in place of posECR_Obj
	return CS_ECR_XYZtoTOP_AER(&posECR_Obj,pllaTopoCenter,0,paer);
	//
}

int CS_LLAtoQbliqueLLA(const lla_vec* llaPole, const lla_vec* lla, lla_vec* llaPrim)
{
	double x,y,z;
	double rot[3][3]; //col,row
	double stLat = - (HALFPI - llaPole->lat* DEG2RAD);
	double xn,yn,zn;
	//
	x = cos(lla->lat *  DEG2RAD) * cos(lla->lon *  DEG2RAD);
	y = cos(lla->lat *  DEG2RAD) * sin(lla->lon *  DEG2RAD);
	z = sin(lla->lat *  DEG2RAD);
	//
	rot[0][0] =   cos(llaPole->lon * DEG2RAD)*cos(stLat); //1 row
	rot[0][1] =   - sin(llaPole->lon * DEG2RAD);
	rot[0][2] =   - cos(llaPole->lon * DEG2RAD)*sin(stLat);
	rot[1][0] =  sin(llaPole->lon * DEG2RAD)*cos(stLat); //2 row
	rot[1][1] =   cos(llaPole->lon * DEG2RAD);
	rot[1][2] = - sin(llaPole->lon * DEG2RAD)*sin(stLat);
	rot[2][0] =  sin(stLat);            //3 row
	rot[2][1] =   0.0;
	rot[2][2] =   cos(stLat);
	//
	xn = x*rot[0][0] + y*rot[0][1] + z*rot[0][2];
	yn = x*rot[1][0] + y*rot[1][1] + z*rot[1][2];
	zn = x*rot[2][0] + y*rot[2][1] + z*rot[2][2];
	//
	llaPrim->lat = asin(zn) * RAD2DEG;
	llaPrim->lon = atan2(yn,xn)* RAD2DEG;

	return 0;
}



