//---------------------------------------------------------
//  SSP.H
//	  ��������� ������� ������ SSP
//  �����   : �������� �.�.
//   ������ : 01.00 / 14.04.2004 /
//---------------------------------------------------------
#ifndef __SSP_H
#define __SSP_H

#include <FlyMMath.h>

#ifdef FLYSSP_EXPORTS
#define FLYSSP_API __declspec(dllexport)
#else
#define FLYSSP_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

FLYSSP_API double atana(double sina, double cosa);
FLYSSP_API double atank(double argtan, double signcos);

/* ALI.C
   ���������������� ������� � ������� ����������������� ��������
   �������-��������
*/
FLYSSP_API int ali(double x, double arg[], double val[], double* y, int ndim,
	 float eps,int n8);
/* AHI.C
   ���������������� ������� � ������� ����������������� ��������
   �������-������
*/
FLYSSP_API int ahi(double x, double arg[], double val[], double* y,
	 int ndim, float eps, int n8);
/* ACFI.C
   ���������������� ������� � ������� ����������� �����
*/
int   acfi(double x, double arg[], double val[], double *y,
	  int ndim, float eps);
/* APCH.C
   ����������� ������� ���������� ����������, ����������� ���
   ����������� ���������� ������� ����������� �� ������ ����������
   ���������
*/
FLYSSP_API int   apch(double dati[], int n, int ip, double* xd, double* x0, double work[]);
/* APFC.C
   ������� ������� ���������� ���������, ����������� ��� ���������
   � ������ ������ ���������� ��������� ������������� ��������
   ���������� ������� �������� ������������ �������
*/
FLYSSP_API int   apfs(double work[], int ip, int *ires, int iop, double eps, double eta);
/* APMM.C
   �������� ����������� ������������� �������� ���������� �������
   �������� ������������ �������� ����������� �������
*/
FLYSSP_API int   apmm(void(*fct)(double *, double, int),
	   int n,int  m,double *top,int *ihe,double *piv,
	   double * t, int *iter);
/*  NORMX.C
    ������������ ���������� ��������� ���������������� �������
    � ��������� [dl,dr] */
FLYSSP_API void  normx(double dl, double dr, double top[], int n, double *x0, double *xd);
/*  NORMX11.C
    ������������ ���������� ��������� ���������������� �������
    � ��������� [-1,1] */
FLYSSP_API void  normx11(double top[], int n, double *x0, double *xd);
/* LAP.C
   ���������� �������� ������������� ��������� ������� [0,+����]
*/
FLYSSP_API void   lap(double y[], double  x, int n);
/* LAPS.C
   �������� ���������� �� �������
*/
FLYSSP_API double  laps(double x, double c[], int n);
/* TLAP.C
   �������������� �������� ������� � �������������� �������
*/
FLYSSP_API void   tlap(double a, double b, double pol[], int n, double c[], double work[]);
/* LEP.C
    ���������� �������� ������������� ��������� �������� [-1,1]
*/
FLYSSP_API void   lep(double y[], double  x, int n);
/* LEPS.C
   �������� ���������� �� ��������
*/
FLYSSP_API double  leps(double x, double c[], int n);
/* TLEP.C
   �������������� �������� �������� � �������������� �������
*/
FLYSSP_API void   tlep(double a, double b, double pol[], int n, double c[], double work[]);
/* HEP.C
   ���������� �������� ������������� ��������� ������ [-����,+����]
*/
FLYSSP_API void   hep(double y[], double  x, int n);
/* HEPS.C
   �������� ���������� �� ������
*/
FLYSSP_API double  heps(double x, double c[], int n);
/* THEP.C
   �������������� �������� ������ � �������������� �������
*/
FLYSSP_API void   thep(double a, double b, double pol[], int n, double c[], double work[]);
/* CNP.C
   ���������� �������� ������������� ��������� ��������
*/
FLYSSP_API void    cnp(double y[], double x, int n);
/* CNPS.C
   �������� ���������� �� ��������
*/
FLYSSP_API double  cnps(double x, double  c[], int n);
/* TCNP.C
   �������������� �������� �������� � �������������� �������
*/
FLYSSP_API void    tcnp(double a, double b, double pol[], int n, double c[], double work[]);
/* CSP.C
   ���������� �������� ��������� ��������� ��������
*/
FLYSSP_API void    csp(double y[], double x, int n);
/* CSPS.C
   �������� ���������� �� ��������� ��������� ��������
*/
FLYSSP_API double  csps(double x, double  c[], int n);
/* TCSP.C
   �������������� ���������� �������� �������� � �������������� �������
*/
FLYSSP_API void    tcsp(double a, double b, double pol[], int n, double c[], double work[]);
/* EPS.C
   ������ ��������� �������
*/
FLYSSP_API double  macheps(void);
/* GAMMA.C
   ������ �������� �����-������� ��� ������������� ���������
*/
//LINUX
//int     gamma(float XX,float *GX);
FLYSSP_API int     Gamma(float XX, float *GX);
/* QATR.C
   �������������� ������� �� ������� �������� � ��������������
   �� ������ ��������
*/
FLYSSP_API int     qatr(double xl, double xu, double eps, int  ndim,
					 double (*fct)(double),double *y,double aux[]);
/* RTNI.C
   ������� ����������� ��������� ������� �������
*/
FLYSSP_API double  rtni(double * f, double *derf, double(*fct)(double, double *),
	   double xst,float eps,int iend,int *ier);
/* ATSM.C
   ������� ������� �� ������� � ����������� ���������� ���������
*/
FLYSSP_API void atsm(double x, double z[], double f[], int irow, int icol,
	  double arg[], double val[], int ndim);
/* ATSG.C
   ������� ������� �� ������� ������ ����
*/
FLYSSP_API void atsg(double x, double z[], double f[],
	  double work[], int irow, int icol,
	  double arg[], double val[], int ndim);
/* ATSE.C
   ������� ������� �� ������� � ��������������� ���������� ���������
*/
FLYSSP_API void atse(double x, double zs, double dz, double f[], int irow, int icol,
	  double arg[], double val[], int ndim);
/* SG13.C
   ����������� �������, �������� �������� ��������
   � ��������������� ������,  � ������� ����������
   ������ �������, ������������ �� ���� ���������-
   ������� ������ ������� ���������� ���������
*/
FLYSSP_API int sg13(double x[], double y[], double z[], int ndim);
/* SE35.C
   ����������� �������, �������� �������� ��������
   �  �������������  ������, �  ������� ����������
   ������� �������, ������������ �� ���� ���������-
   ������� ������ ������� ���������� ���������
*/
FLYSSP_API int se35(double y[], double z[], int ndim);
/* SE15.C
   ����������� �������, �������� �������� ��������
   �  �������������  ������, �  ������� ����������
   ������ �������, ������������ �� ���� ���������-
   ������� ������ ������� ���������� ���������
*/
FLYSSP_API int se15(double y[], double z[], int ndim);
/* SE13.C
   ����������� �������, �������� �������� ��������
   �  �������������  ������, �  ������� ����������
   ������ �������, ������������ �� ���� ���������-
   ������� ������ ������� ���������� ���������
*/
FLYSSP_API int se13(double y[], double z[], int ndim);
/* GAUSS.C
   ��������� ��������������� ����� �� ����������� ������
*/
FLYSSP_API double  gauss(long *ix, double s, double am);
/* RANDU.C
   ��������� ��������������� ����� �� ������������ ������
*/
FLYSSP_API double  randu(long ix, long *iy);
/* RANDM.C
   ��������� ��������������� ����� �� ������������ ������
   (���� ��. �.�.����������)
*/
FLYSSP_API double  randm(void);
/* URAND.C
   ��������� ��������������� ����� �� ������������ ������
   (��.�������)
*/
FLYSSP_API double  urand(long *iy);
/* MINV.C
   ��������� �������
*/
FLYSSP_API void    sminv(double a[], int n, double *d, int l[], int m[]);
/* PSI.C
   �����������. ��������� ����������� ����������
   (�������� ��� ���������) ������� ���������� ����������
   (��������� �.�.)
*/
#define __MAX__    1
#define __MIN__   -1
FLYSSP_API int     psi(int number, double *area,
	 int size, int l, int flag,
	 double (*func)(double *x, double *z),
	 double *X, double *Z, double *extremum,	double *estimate);
/* MGS.C
   ������� ��� ������� ������ � ������� ������������� ��������
*/
FLYSSP_API int  mgs(int n, double *a, double *b, double *x);
/* prqd.C
   ������ ���� �������������� � ����������� ������
   ��������������� ��������
*/
FLYSSP_API int  prqd(double c[], int ic, double  q[], double  e[], double  pol[], int *ir);
/* pqfb.C
*/
FLYSSP_API int  pqfb(double c[], int ic, double q[], int lim);
/* prbm.C
   ������ ���� �������������� � ����������� ������
   ��������������� ��������
*/
FLYSSP_API int  prbm(double c[], int ic,
	  double rr[],double rc[], double pol[],int *ir);
/* overfl.C */
FLYSSP_API void  overfl(int *N);
/* max.C
   ��������� ������ ������������� ��������
*/
FLYSSP_API double  vfmax(double  mn, ...);	/* FLOATING POINT MINIMUM */

/* MATA.C
     ��������� ����� ������� �� �����������������
*/
FLYSSP_API void mata(double a[], double r[], int n, int m, int ms);
/* XCPY.C
   ���op � �a��c� �o��a�p��� �� �a�a��o� �a�p���
*/
FLYSSP_API void xcpy(double a[], double r[],
	  int l, int k, int nr, int mr, int na, int ma, int ms);
/* GMADD.C
   �������� ���� ������ ������ ����
*/
//void  gmadd(double a[], double b[], double r[], int n, int m);
/* GMTRA.C
   ���������������� ������� ������ ����
*/
FLYSSP_API void  gmtra(double a[], double r[], int n, int m);
/* GTPRD.C
   ��������� ������������������ ������� �� ������ ������� ������ ����
*/
FLYSSP_API void  gtprd(double a[], double b[], double r[], int n, int m, int l);
/* GMSUB.C
   ��������� ���� ������ ������ ����
*/
FLYSSP_API void   gmsub(double a[], double b[], double r[], int n, int m);
/* GMPRD.C
   ������������ ���� ������ ������ ����
*/
FLYSSP_API void  gmprd(double a[], double b[], double r[], int n, int m, int l);
/* GMPRD2.C
   ����������� ������������ ���� ������ ������ ����
*/
FLYSSP_API void difgmprd(double a[], double b[], double aa[], double bb[],
	    double c[], int n, int m, int l);
FLYSSP_API void difsmprd3(double *a, double *b, double *c, double *d);
/* LOC.C
   ���������� ���������� ������� �������� �������, ������������� �
   ������ � ��������� �����
*/
FLYSSP_API void  loc(int i, int j, int *ir, int n, int m, int ms);
/* MPRD.C
   ������������ ���� ������ ������������� ����
*/
FLYSSP_API void mprd(double a[], double b[], double r[], int n, int m, int l, int msa, int msb);
/* TPRD.C
   ��������� ������������������ ������� �� ������ �������
*/
FLYSSP_API void  tprd(double a[], double b[], double r[], int n, int m, int msa, int msb, int l);
/* MCPY.C
   ����������� �������
*/
FLYSSP_API void  mcpy(double a[], double r[], int n, int m, int ms);
/* MTRA.C
   ���������������� �������
*/
FLYSSP_API void  mtra(double a[], double r[], int n, int m, int ms);
/* MADD.C
   �������� ���� ������
*/
//void  madd(double a[], double b[], double r[], int n, int m, int msa, int msb);
/* MSUB.C
   ��������� ���� ������
*/
FLYSSP_API void  msub(double a[], double b[], double r[], int n, int m, int msa, int msb);

/* _SQFSOL.C
   ������ ������������ ����� � ������ ���������
   ������������� �� �������
*/
FLYSSP_API double  sqfsolve(double n, double A[], double B[], double d[],
		double dleft[],double dright[],double matr[],
		double tau,int *nmin);

/* APCHA.C
	  ������������� �������� ���������� �������
	  �������������� ���������� �������� C �������������� �������
	  ������� ����������������� �������� */
FLYSSP_API int  apcha(double *top, double *work, int n, int m,
	    int st_max, double *sqkr,double *c,
	    double *xd,double *x0,
	    float eps,float eta);

/* NDTRI.C
   �������� ������� ����������� �������������
*/
FLYSSP_API int  ndtri(float p, float  *x, float  *d);
/* NDTR.C
   ������� ����������� �������������
*/
FLYSSP_API float  ndtr(float x, float *d);
/*  MSECH.C
    ���������� ���� ������� f(x) �� ��������� [a,b]
    ������� �������-����
*/
FLYSSP_API double msechord(const double a, const double b, int *iter,
		float tol, double (*fuser)(const double ,const void *),
		const void *userdata);
/* QTFG.C
   �������������� �������, �������� �������� � ����������������
   ������, �� ������� ��������
*/
FLYSSP_API void  qtfg(double x[], double y[], double z[], int ndim);
/* QSF.C
   �������������� �������, �������� �������� ��������
   � �������������� ������, �� �������� �������-������
*/
FLYSSP_API void  qsf(double h, double y[], double z[], int ndim);
/* FORIF.C
   ���������� ������������� ����� ������������� �������
*/
FLYSSP_API int  forif(double(*fun)(double), int n, int m,
	    double a[], double b[]);
/* FORIT.C
   ���������� ������������� ����� ������������� �������,
   �������� �������� ��������
*/
FLYSSP_API int  forit(double fnt[], int n, int m, double a[], double b[]);
/* FORITN.C
   ���������� ������������� ����� ������������� �������,
   �������� �������� �������� � ���������������� �����
*/
FLYSSP_API int  foritn(double t[], double fnt[], int n, int m,
	     double a[], double b[], double work[]);
/* TRENDD.C
   �������� ������ ���� Y=FUN(C,X,M) �� �������, �������� ��������
   �������� � ���������������� �����
*/
FLYSSP_API void trendd(double x[], double y[], int n, double c[], int m,
	     double (*fun)(double ,double *,int));
/* TRENDL.C
   ���������� ������������� �������� ���������,
   �������� �������� �������� � ���������������� �����
*/
FLYSSP_API void  trendl(double x[], double y[], int n, double c[]);
/* TRENDLS.C
   ���������� �������� ��������� ������
*/
FLYSSP_API double trendls(double x, double c[], int m);
/* TRENDI.C
   ���������� ������������� ��������� ���� Y=C0+C1/X,
   �������� �������� �������� � ���������������� �����
*/
FLYSSP_API void  trendi(double x[], double y[], int n, double c[]);
/* TRENDIS.C
   ���������� �������� ������ ���� Y=C0+C1/X
*/
FLYSSP_API double trendis(double x, double c[], int m);
/* TRENDQ.C
   ���������� ������������� ��������� ���� Y=C0+C1*X*X,
   �������� �������� �������� � ���������������� �����
*/
FLYSSP_API void  trendq(double x[], double y[], int n, double c[]);
/* TRENDQS.C
   ���������� �������� ������ ���� Y=C0+C1*X*X
*/
FLYSSP_API double trendqs(double x, double c[], int m);

/* MOMEN.C
	    ���������� ������ ������� ��������
*/
FLYSSP_API void  momen(double f[], double ubo[], int nop, double ans[]);
/* MSTR.C
	    ��������� ������� �������� ���������� �������
*/
FLYSSP_API void  mstr(double a[], double r[], int n, int msa, int msr);

/* MSET.C
     ���������� N ������ ������� � ������ S �������� ���� C
*/
FLYSSP_API void *mset(void *s, char unsigned c, int n);
FLYSSP_API void *mcopy(void *dest, const void *src, int n);
/* CCPY.C
   ������������� ������� ������� � ���� �������
*/
FLYSSP_API void ccpy(double a[], int jn, double r[], int n, int m, int ms);
/* RCPY.C
   ������������� ������ ������� � ���� �������
*/
FLYSSP_API void rcpy(double a[], int jn, double r[], int n, int m, int ms);
/*  SADD.C
     �������� ������� �������� ������� �� �������� */
FLYSSP_API void sadd(double a[], double c, double r[], int n, int m, int ms);
/*  SSUB.C
     ��������� ������� �� ������� �������� ������� */
FLYSSP_API void ssub(double a[], double c, double r[], int n, int m, int ms);
/*  SMPY.C
     ��������� ������� �������� ������� �� ������ */
FLYSSP_API void smpy(double a[], double c, double r[], int n, int m, int ms);
/*  SDIV.C
     ��������� ������� �������� ������� �� ������ */
FLYSSP_API void sdiv(double a[], double c, double r[], int n, int m, int ms);

/* NM.C

*/
FLYSSP_API int nm(const int n, double *x,
		double (*fuser)(const int ,const double *,double *),
		int *iter,
		float  tol,
		double *work);
/* NM1.C

*/
FLYSSP_API int nm1(const int n, double x[],
		double (*fuser)(const int ,const double *,double *),
		int   *iter,
		double  pr[],
		double  *c,
		double  work[]);

/* STPRG.C

*/
FLYSSP_API void stprg(int m, int n, double d[], double xbar[], int idx[],
	   double *pct, int nstep[], double ans[], int l[],
	   double b[], double s[], double t[], int ll[], int *ier);

/* SVD.C ����������� ���������� ������
*/
FLYSSP_API int svd(int m, int n, double a[], double w[], double v[], double work[]);
/* SVDINV.C ��������� ������ ��� (��� ��� ���) ������� ������������ ����������
*/
FLYSSP_API void svdinv(int m, int n, double w[], double v[],
	    int ncomp, double tau,
	    double ainv[]);
/* SVDGINV.C ��������� ���������� ������ ������ ���� ������� ������������ ����������
*/
FLYSSP_API void svdginv(int n, double u[], double w[], double v[],
	    int ncomp, double tau, double ainv[]);
/* SVDLAE.C ������� ��� ��� ��� ������� ������������ ����������
*/
FLYSSP_API void svdlae(int m, int n, double a[], double w[], double v[],
	    double b[],
	    int *ncomp,
	    double *avt, double *tau,
	    double x[],
	    double cond[]);
/* SVDSORT.C ���������� ������������ ����������
*/
FLYSSP_API void svdsort(int m, int n, double a[], double w[], double v[]);
/* SING.C
*/
FLYSSP_API int sing(int m, int n, double *tau,
	 int *ncomp,int nsyst,int masht,double * avt,
	 double a[],double b[],double w[],double *v,double x[],double ainv[],
	 double cond[]);
/*
int  minvsvd(int n, double tau, int teg,
	      double u[], double w[], double v[],
	      double *cond,  double a[]);
*/

/* DGT3.C
    ����������������� �������, �������� �������� ��������
    � ���������������� ������
*/
FLYSSP_API int dgt3(double x[], double y[], double z[], int ndim);
/* DET3.C
    ����������������� �������, �������� �������� ��������
    � �������������� ������, �� �������� �������� ��
    ���� �����
*/
FLYSSP_API int det3(double h, double y[], double z[], int ndim);
/*  DET5.C
    ����������������� �������, �������� �������� ��������
    � �������������� ������, �� �������� �������� ��
    ���� �����
*/
FLYSSP_API int det5(double h, double y[], double z[], int ndim);
/* DCAR.C
    ����������������� ������� � ������ ���������
    ������� ������������� ���������� � ��������
*/
FLYSSP_API double dcar(double x, double h, int ih, double(*fct)(double));
/* DBAR.C
    ����������������� ������� �� ������� ���������
    ������� ������������� ���������� � ��������
*/
FLYSSP_API double dbar(double x, double h, int ih, double(*fct)(double));

/* VCPY.C
	  ����������� �������
*/
//void veccpy(double qout[],double qin[],int sz);
//void veccpy1(double dest[],double src[],int sz);
//void veccpy(double dest[],double src[],int sz);
/* VSUB.C
	  ��������� ���� ��������
*/
FLYSSP_API void vecsub(double dest[], double src1[], double src2[], int sz);

/* SEVAL.C
*/
FLYSSP_API double seval(int n, double u, double x[], double y[],
		      double b[], double c[], double d[]);
/* SPLINE.C
*/
FLYSSP_API void spline(int n, double x[], double y[], double b[], double c[], double d[]);

/* ANW.C
   ������ ��������� �� ������������� �����
*/
FLYSSP_API double Anw(double aw, double bw);
/* FNW.C
   ������ ���� �� ������������� �����
*/
FLYSSP_API double Finw(double aw, double bw);

/* MIN.C
*/
//int    imin(int a,int b);
//long   lmin(long a,long b);
//double fmin(double a,double b);
//double vfmin(double  mn, ... );	/* FLOATING POINT MINIMUM */
//long   vlmin(long  mn, ... );	/* LONG INTEGER MINIMUM */
//int    vmin(int  mn, ... );	/* INTEGER MINIMUM */
/* MAX.C
*/
//int    imax(int a,int b);
//long   lmax(long a,long b);
//double fmax(double a,double b);
//double vfmax(double  mx, ... );	/* FLOATING POINT MAXIMUM */
//long   vlmax(long  mx, ... );	/* LONG INTEGER MAXIMUM */
//int    vimax(int  mx, ... );	/* INTEGER MAXIMUM */

/* APLL.C
     ����������� ������� ���������� ���������, ����������� ��� (���������
     � ������ ������ ���������� ���������) ������������� ��������
     ���������� ������� �������� ������������ �������
*/
FLYSSP_API void apll(void(*ffct)(int, int, int, double *, double *, double *, int *),
	 int n, int ip, double p[], double work[], double dati[],int irr[]);

/* FRAT.C
*/
FLYSSP_API void frat(int i, int n, int m, double p[], double dati[], double *wgt, int ier[]);
/* ARAT.C
   ������������� �������� ���������� ������� ������������ �������� ��
   ������ ���
*/
FLYSSP_API int arat(double dati[], int n, double work[], double p[], int ip, int iq);
/*   PADD.C
     ��o�e��e ���x �o���o�o�
*/
FLYSSP_API void padd(double z[], int *idimz, double x[], int idimx, double y[], int idimy);
/*   PNORM.C
     �op��po��a �e��opa �o������e��o� �o���o�a
*/
FLYSSP_API int pnorm(double x[], int idimx, double eps);
/*   PDIV.C
     �e�e��e o��o�o �o���o�a �a �p��o�
*/
FLYSSP_API int pdiv(double p[], int *idimp, double x[], int idimx, double y[], int idimy,
	 double tol);
/*   PMPY.C
     ��������� o��o�o �o���o�a �a �p��o�
*/
FLYSSP_API void pmpy(double z[], int *idimz, double x[], int idimx, double y[], int idimy);
/*   PSUB.C
     ��������� ������ �o���o�� �� �������
*/
FLYSSP_API void psub(double z[], int *idimz, double x[], int idimx, double y[], int idimy);
/*   PVAL.C
     ������ �������� �o���o�� ��� ��������� (����� �������)
*/
FLYSSP_API double pval(double arg, double x[], int idimx);
/*   POLRT.C
     ����c�e��e �e�c����e����x � �o���e�c��x �op�e� �o���o�a
*/
FLYSSP_API int polrt(double xcof[], double cof[], int m, double rootr[], double rooti[]);
/*   PCLA.C
     MOVE POLYNOMIAL X TO Y
*/
FLYSSP_API void pcla(double y[], int *idimy, double x[], int idimx);
/*   PADDM.C
     ��o�e��e �o���. o��o�o �o���o�a c �o���. �p��o�o ��o�e����� �a ��o�.
*/
FLYSSP_API void paddm(double z[], int *idimz, double x[], int idimx, double fact,
	   double y[], int idimy);
/*   PVSUB.C
     SUBSTITUTE VARIABLE OF A POLYNOMIAL BY ANOTHER POLYNOMIAL
*/
FLYSSP_API void pvsub(double z[], int *idimz, double x[], int idimx, double y[], int idimy,
	   double work1[], double work2[]);
/*   MDIAN1.C
     ������ ���������� �������
     (���������� � �������������� qsort)
*/
FLYSSP_API double mdian1(double x[], int n);
/*   MDIAN2.C
     ������ ���������� �������
     (���������� ������ ���������)
*/
FLYSSP_API double mdian2(double x[], int n);
/*   AVEVAR.C
     ������ ���������� �������� � ��������� (����������� ������)
*/
FLYSSP_API void avevar(double data[], int n, double *ave, double *svar);
/*   MOMENT.C
     ������ ���������� ������������� Mx,M[Mx],Sx,Dx,Ac,Ek
*/
FLYSSP_API int  moment(double data[], int n,
	    double *ave,   // Mx - ������� ��������������
	    double *adev,  //    - ������� ���������� �� Mx
	    double *sdev,  // Sx - ������� ��������������
	    double *svar,  // Dx - ���������
	    double *skew,  // Ac - ����������
	    double *curt); // Ek - �������
/*   CORR.C
     ������ ������� ��������, ����������� ����������, ���������� �
     ������������� ����������
*/
FLYSSP_API int corr(double  x[],  /* �������� ������� ���������� [n*k] */
	 int     n,    /* ����� ���������� (�����)  */
	 int     k,    /* ����� ����������� �������� (��������)*/
	 double *x_,   /* ������ ������� */
	 double *s_,   /* ������ ��� */
	 double *S,    /* �������������� �������*/
	 double *R     /* �������������� �������*/);
/*   CORRE.C
     ������ ������� ��������, ����������� ����������, ���������� �
     ������������� ����������
*/
FLYSSP_API void corre(int n, int m, double x[],
	   double xbar[],double std[],double rx[],
	   double r[],double b[],double d[],double t[],
	   void (*data)(int, double *) );
/*   ORDER.C
     ������������ �� ������ ������� ���������� ���������
     ������������� ���������� ����� ������������ �����������
     � ������� �������� ���������� ����� ������������ �����������
     � ����� ����������
*/
FLYSSP_API void order(int m, double r[], int ndep, int k, int isave[], double rx[], double ry[]);
/*   MULTR.C
     ������������� �������� ������������� ������ ��� ��������� ����������
     � ��������� ����������� ����������
*/
FLYSSP_API void multr(int n, int k, double xbar[], double std[],
	   double d[], double rx[], double ry[],
	   int isave[], double b[], double sb[],
	   double t[], double ans[]);
/*   MEAN.C
     ������ ����������� �������� �� ������������ �������
*/
FLYSSP_API void mean(double xi, double *Mx, int *n);
/*   SDAD.C
     ������ ������� ������������� ������ � �������� ���������� ���������
     ��� ������� �������� ������������� ��������� �����
*/
FLYSSP_API int sdad(int n, double x[], double y[],
	   double *sdev,double *adev,
	   double sig[],
	   void (*fdata)(int i, double *xi, double *yi) );
/*   FORITG.C
     ���������� �������� ���������� �����
*/
FLYSSP_API double foritg(double t, double f1, int m, double a[], double b[]);
/*   CMPLX.C
     �������� ��� ������������ �������
*/
FLYSSP_API void cmplxadd(double a1[], double a2[], double a[]);
FLYSSP_API void cmplxsub(double a1[], double a2[], double a[]);
FLYSSP_API void cmplxmpy(double a1[], double a2[], double a[]);
FLYSSP_API void cmplxdev(double a1[], double a2[], double a[]);
FLYSSP_API void cmplxeq(double alpha[], double a[]);
/*   CONJ.C
     ����������-����������� �����
*/
FLYSSP_API void conj(double x[], double y[]);

/*   FFTRAN.C
     ������� �������������� ����� (������ � ��������)
*/
FLYSSP_API int fftran(int sign, double t, double *x, int unsigned npow);
/*   FCFAW.C
     ��������� ������������� �� �� ������������ (����������� A)
*/
FLYSSP_API double fcfaw(double x[]);
/*   FCFBW.C
     ��������� ������������� �� �� ������������ (����������� B)
*/
FLYSSP_API double fcfbw(double x[]);
/*   SQF.C
     ������ ������������ ����� ���� C(M,L)=A(M,N)*P(N,K)*S(K,L)+W(M,L)
*/
FLYSSP_API void sqf(double *a, double *p, double *s, double *w,
	 int M, int N, int K, int L, double *c);
/*   SQFT.C
     ������ ������������ ����� ���� C(M,L)=A(M,N)*P(N,K)*tans(S(L,K))+W(M,L)
*/
FLYSSP_API void sqft(double *a, double *p, double *s, double *w,
	   int M, int N, int K, int L, double *c);
/*   BCPY.C
     ����������� ����� ������������� ����� �������
     � ��������� ����� ������ ������������� �������
*/
FLYSSP_API int bcpy(double *a, double *r, int na, int ma, int nr, int mr,
	 int ir,int jr);
/*   GMSMGT.C
     ��������� ������� ������ ���� �� ������������, � ��
     ���������� �� �������� ����������������� ������ ����
*/
FLYSSP_API int gmsmgt(double *a, double *s, int n, int m, double *r, double *d);

/*   PILD.C
     ������ �������� �o���o�a � e�o �po���o��o� ���
     �a�a��o�o ap���e��a
*/
FLYSSP_API void pild(double *poly, double *dval, double arg, double x[], int idimx);

/*   PQSD.C
     PERFORM QUADRATIC SYNTHETIC DIVISION
*/
FLYSSP_API void pqsd(double *a, double *b, double p, double q, double x[], int idimx);
/*   LAGINT.C
     THIS SUBROUTINE PERFORMS LAGRANGIAN INTERPOLATION
*/
FLYSSP_API double lagint(double x[], double y[], int n, double xint);

/*   VUNIT.C
     THIS SUBROUTINE ��������� ��������� ������
*/
FLYSSP_API void vunit(double a[], double b[]);
/*   VMATR.C
     ������� ������� ������� ������ � �������
*/
FLYSSP_API int vmatr(double a[], int na, int ma, double b[], int nb, int mb, int i, int j);

/*   VECSB.C
     �������� ��������, ����������� 3 */
//void vecsb(double a[], double b[], double c[]);
/*   VECAD.C
     ����� ��������, ����������� 3*/
//void vecad(double a[], double b[], double c[]);
/*   MMUL5.C
     ������������ 5-�� ������, ����������� 3*3 */
//void mmul5(double a[], double b[], double c[], double d[],  double e[], double f[]);
/*   MMUL3.C
     ������������ 3-� ������, ����������� 3*3 */
//void mmul3(double a[], double b[], double c[], double d[]);
/*   MMUL2.C
     ������������ 2-� ������, ����������� 3*3 */
//void mmul2(double a[], double b[], double c[]);
/*   MADD5.C
     ����� 5-�� ������, ����������� 3*3 */
//void  madd5(double a[], double b[], double c[], double d[], double e[], double f[]);
/*   MADD4.C
     ����� 4-� ������, ����������� 3*3 */
//void  madd4(double a[], double b[], double c[], double d[], double e[]);
/*   MADD3.C
     ����� 3-� ������, ����������� 3*3 */
//void  madd3(double a[], double b[], double c[], double d[]);
/*   MADD2.C
     ����� 2-� ������, ����������� 3*3 */
//void  madd2(double a[], double b[], double c[]);
/*   ROTAT.C
     ������������� �������.
     ������� �� ���� ������ ������� ������� */
FLYSSP_API void rotat(double theta, int i, double r[]);
/*   DROTT.C
     ������ ����������� ������������� �������.
     ������� �� ���� ������ ������� ������� */
FLYSSP_API void drott(double theta, double dtheta, int i, double dr[]);
/*   DDROT.C
     ������ ����������� ������������� �������.
     ������� �� ���� ������ ������� ������� */
FLYSSP_API void ddrot(double theta, double ddthta, int i, double ddr[]);
/*   D3ROT.C
     ������ ����������� ������������� �������.
     ������� �� ���� ������ ������� ������� */
FLYSSP_API void d3rot(double theta, double d3thet, int i, double d3r[]);
/*   VECRT.C
     ������������ ������� �� ������, ����������� 3.
     ������� � ���������������. */
FLYSSP_API void vecrt(double a[], double v[], double rv[]);

#ifdef __cplusplus
}
#endif

#define IEND	(INT_MAX-1)
#define LEND	(LONG_MAX-1)
#define FEND	(1.e+38-1.)

/* ������� �������� ������ */
#define GENERAL   0      /* ����� ������ �������� */
#define SYMMETRIC 1      /* ������������ */
#define DIAGONAL  2      /* ������������ */

#define for_if(arg) 	((arg)>0. ? 1:((arg)<0. ?-1:0))

#endif /* __SSP_H */

