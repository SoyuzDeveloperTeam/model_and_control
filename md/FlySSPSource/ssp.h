//---------------------------------------------------------
//  SSP.H
//	  опнрнрхош тсмйжхи оюйерю SSP
//  юБРНП   : оЮЯШМЙНБ б.б.
//   бЕПЯХЪ : 01.00 / 14.04.2004 /
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
   хмрепонкхпнбюмхе тсмйжхх я онлныэч хмрепонкъжхнммнцн опнжеяяю
   щирйемю-кюцпюмфю
*/
FLYSSP_API int ali(double x, double arg[], double val[], double* y, int ndim,
	 float eps,int n8);
/* AHI.C
   хмрепонкхпнбюмхе тсмйжхх я онлныэч хмрепонкъжхнммнцн опнжеяяю
   щирйемю-щплхрю
*/
FLYSSP_API int ahi(double x, double arg[], double val[], double* y,
	 int ndim, float eps, int n8);
/* ACFI.C
   хмрепонкхпнбюмхе тсмйжхх я онлныэч меопепшбмни дпнах
*/
int   acfi(double x, double arg[], double val[], double *y,
	  int ndim, float eps);
/* APCH.C
   янярюбкемхе яхярелш мнплюкэмшу спюбкмемхи, бнгмхйючыеи опх
   опхакхфемхх дхяйпермни тсмйжхх лмнцнвкемнл он лерндс мюхлемэьху
   йбюдпюрнб
*/
FLYSSP_API int   apch(double dati[], int n, int ip, double* xd, double* x0, double work[]);
/* APFC.C
   пеьемхе яхярелш мнплюкэмшу спюбмемхи, бнгмхйючыеи опх мюхксвьеи
   б ялшяке лерндю мюхлемэьху йбюдпюрнб юоопнйяхлюжхх гюдюммни
   дхяйпермни тсмйжхх кхмеимни йнлахмюжхееи тсмйжхи
*/
FLYSSP_API int   apfs(double work[], int ip, int *ires, int iop, double eps, double eta);
/* APMM.C
   кхмеимюъ веашьебяйюъ юоопнйяхлюжхъ гюдюммни дхяйпермни тсмйжхх
   кхмеимни йнлахмюжхееи гюдюммшу меопепшбмшу тсмйжхи
*/
FLYSSP_API int   apmm(void(*fct)(double *, double, int),
	   int n,int  m,double *top,int *ihe,double *piv,
	   double * t, int *iter);
/*  NORMX.C
    оНДОПНЦПЮЛЛЮ ОПХБЕДЕМХЪ ЮПЦСЛЕМРЮ ГЮРЮАСКХПНБЮММНИ ТСМЙЖХХ
    Й ХМРЕПБЮКС [dl,dr] */
FLYSSP_API void  normx(double dl, double dr, double top[], int n, double *x0, double *xd);
/*  NORMX11.C
    оНДОПНЦПЮЛЛЮ ОПХБЕДЕМХЪ ЮПЦСЛЕМРЮ ГЮРЮАСКХПНБЮММНИ ТСМЙЖХХ
    Й ХМРЕПБЮКС [-1,1] */
FLYSSP_API void  normx11(double top[], int n, double *x0, double *xd);
/* LAP.C
   бшвхякемхе гмювемхи нпрнцнмюкэмшу онкхмнлнб кюцеппю [0,+АЕЯЙ]
*/
FLYSSP_API void   lap(double y[], double  x, int n);
/* LAPS.C
   гмювемхе пюгкнфемхъ он кюцеппс
*/
FLYSSP_API double  laps(double x, double c[], int n);
/* TLAP.C
   опенапюгнбюмхе онкхмнлю кюцеппю б юкцеапюхвеяйхи онкхмнл
*/
FLYSSP_API void   tlap(double a, double b, double pol[], int n, double c[], double work[]);
/* LEP.C
    бшвхякемхе гмювемхи нпрнцнмюкэмшу онкхмнлнб кефюмдпю [-1,1]
*/
FLYSSP_API void   lep(double y[], double  x, int n);
/* LEPS.C
   гмювемхе пюгкнфемхъ он кефюмдпс
*/
FLYSSP_API double  leps(double x, double c[], int n);
/* TLEP.C
   опенапюгнбюмхе онкхмнлю кефюмдпю б юкцеапюхвеяйхи онкхмнл
*/
FLYSSP_API void   tlep(double a, double b, double pol[], int n, double c[], double work[]);
/* HEP.C
   бшвхякемхе гмювемхи нпрнцнмюкэмшу онкхмнлнб щплхрю [-АЕЯЙ,+АЕЯЙ]
*/
FLYSSP_API void   hep(double y[], double  x, int n);
/* HEPS.C
   гмювемхе пюгкнфемхъ он щплхрс
*/
FLYSSP_API double  heps(double x, double c[], int n);
/* THEP.C
   опенапюгнбюмхе онкхмнлю щплхрю б юкцеапюхвеяйхи онкхмнл
*/
FLYSSP_API void   thep(double a, double b, double pol[], int n, double c[], double work[]);
/* CNP.C
   бшвхякемхе гмювемхи нпрнцнмюкэмшу онкхмнлнб веашьебю
*/
FLYSSP_API void    cnp(double y[], double x, int n);
/* CNPS.C
   гмювемхе пюгкнфемхъ он веашьебс
*/
FLYSSP_API double  cnps(double x, double  c[], int n);
/* TCNP.C
   опенапюгнбюмхе онкхмнлю веашьебю б юкцеапюхвеяйхи онкхмнл
*/
FLYSSP_API void    tcnp(double a, double b, double pol[], int n, double c[], double work[]);
/* CSP.C
   бшвхякемхе гмювемхи ялеыеммшу онкхмнлнб веашьебю
*/
FLYSSP_API void    csp(double y[], double x, int n);
/* CSPS.C
   гмювемхе пюгкнфемхъ он ялеыеммшл онкхмнлюл веашьебю
*/
FLYSSP_API double  csps(double x, double  c[], int n);
/* TCSP.C
   опенапюгнбюмхе ялеыеммнцн онкхмнлю веашьебю б юкцеапюхвеяйхи онкхмнл
*/
FLYSSP_API void    tcsp(double a, double b, double pol[], int n, double c[], double work[]);
/* EPS.C
   пЮЯВЕР ЛЮЬХММНЦН ЩОЯХКНМ
*/
FLYSSP_API double  macheps(void);
/* GAMMA.C
   пюявер гмювемхъ цюллю-тсмйжхх дкъ опнхгбнкэмнцн юпцслемрю
*/
//LINUX
//int     gamma(float XX,float *GX);
FLYSSP_API int     Gamma(float XX, float *GX);
/* QATR.C
   хмрецпхпнбюмхе тсмйжхх он опюбхкс рпюоежхи я щйярпюонкъжхеи
   он лерндс пнлаепцю
*/
FLYSSP_API int     qatr(double xl, double xu, double eps, int  ndim,
					 double (*fct)(double),double *y,double aux[]);
/* RTNI.C
   пеьемхе мекхмеимнцн спюбмемхъ лернднл мэчрнмю
*/
FLYSSP_API double  rtni(double * f, double *derf, double(*fct)(double, double *),
	   double xst,float eps,int iend,int *ier);
/* ATSM.C
   бшанпйю рюакхжш хг рюакхжш я лнмнрнммшлх гмювемхълх юпцслемрю
*/
FLYSSP_API void atsm(double x, double z[], double f[], int irow, int icol,
	  double arg[], double val[], int ndim);
/* ATSG.C
   бшанпйю рюакхжш хг рюакхжш наыецн бхдю
*/
FLYSSP_API void atsg(double x, double z[], double f[],
	  double work[], int irow, int icol,
	  double arg[], double val[], int ndim);
/* ATSE.C
   бшанпйю рюакхжш хг рюакхжш я пюбмннрярнъыхлх гмювемхълх юпцслемрю
*/
FLYSSP_API void atse(double x, double zs, double dz, double f[], int irow, int icol,
	  double arg[], double val[], int ndim);
/* SG13.C
   яцкюфхбюмхе тсмйжхх, гюдюммни рюакхжеи гмювемхи
   б мепюмннрярнъыху рнвйюу,  я онлныэч лмнцнвкемю
   оепбни яреоемх, онярпнеммнцн он рпел онякеднбю-
   рекэмшл рнвйюл лернднл мюхлемэьху йбюдпюрнб
*/
FLYSSP_API int sg13(double x[], double y[], double z[], int ndim);
/* SE35.C
   яцкюфхбюмхе тсмйжхх, гюдюммни рюакхжеи гмювемхи
   б  пюмннрярнъыху  рнвйюу, я  онлныэч лмнцнвкемю
   рперэеи яреоемх, онярпнеммнцн он оърх онякеднбю-
   рекэмшл рнвйюл лернднл мюхлемэьху йбюдпюрнб
*/
FLYSSP_API int se35(double y[], double z[], int ndim);
/* SE15.C
   яцкюфхбюмхе тсмйжхх, гюдюммни рюакхжеи гмювемхи
   б  пюмннрярнъыху  рнвйюу, я  онлныэч лмнцнвкемю
   оепбни яреоемх, онярпнеммнцн он оърх онякеднбю-
   рекэмшл рнвйюл лернднл мюхлемэьху йбюдпюрнб
*/
FLYSSP_API int se15(double y[], double z[], int ndim);
/* SE13.C
   яцкюфхбюмхе тсмйжхх, гюдюммни рюакхжеи гмювемхи
   б  пюмннрярнъыху  рнвйюу, я  онлныэч лмнцнвкемю
   оепбни яреоемх, онярпнеммнцн он рпел онякеднбю-
   рекэмшл рнвйюл лернднл мюхлемэьху йбюдпюрнб
*/
FLYSSP_API int se13(double y[], double z[], int ndim);
/* GAUSS.C
   цемепюрнп ояебдняксвюимшу вхяек он мнплюкэмнлс гюйнмс
*/
FLYSSP_API double  gauss(long *ix, double s, double am);
/* RANDU.C
   цемепюрнп ояебдняксвюимшу вхяек он пюбмнлепмнлс гюйнмс
*/
FLYSSP_API double  randu(long ix, long *iy);
/* RANDM.C
   цемепюрнп ояебдняксвюимшу вхяек он пюбмнлепмнлс гюйнмс
   (бхйю ХЛ. ю.т.лНФЮИЯЙНЦН)
*/
FLYSSP_API double  randm(void);
/* URAND.C
   цемепюрнп ояебдняксвюимшу вхяек он пюбмнлепмнлс гюйнмс
   (дФ.тНПЯЮИР)
*/
FLYSSP_API double  urand(long *iy);
/* MINV.C
   напюыемхе люрпхжш
*/
FLYSSP_API void    sminv(double a[], int n, double *d, int l[], int m[]);
/* PSI.C
   норхлхгюжхъ. нршяйюмхе цкнаюкэмнцн щйярпелслю
   (лхмхлслю хкх люйяхлслю) тсмйжхх меяйнкэйху оепелеммшу
   (вХВХМЮДГЕ б.й.)
*/
#define __MAX__    1
#define __MIN__   -1
FLYSSP_API int     psi(int number, double *area,
	 int size, int l, int flag,
	 double (*func)(double *x, double *z),
	 double *X, double *Z, double *extremum,	double *estimate);
/* MGS.C
   пеьемхе якс лернднл цюсяяю я бшанпнл люйяхлюкэмнцн щкелемрю
*/
FLYSSP_API int  mgs(int n, double *a, double *b, double *x);
/* prqd.C
   пюявер бяеу деиярбхрекэмшу х йнлокейямшу йнпмеи
   юкцеапюхвеяйнцн онкхмнлю
*/
FLYSSP_API int  prqd(double c[], int ic, double  q[], double  e[], double  pol[], int *ir);
/* pqfb.C
*/
FLYSSP_API int  pqfb(double c[], int ic, double q[], int lim);
/* prbm.C
   пюявер бяеу деиярбхрекэмшу х йнлокейямшу йнпмеи
   юкцеапюхвеяйнцн онкхмнлю
*/
FLYSSP_API int  prbm(double c[], int ic,
	  double rr[],double rc[], double pol[],int *ir);
/* overfl.C */
FLYSSP_API void  overfl(int *N);
/* max.C
   опнцпюллш онхяйю люйяхлюкэмнцн щкелемрю
*/
FLYSSP_API double  vfmax(double  mn, ...);	/* FLOATING POINT MINIMUM */

/* MATA.C
     слмнфемхе якебю люрпхжш мю рпюмяонмхпнбюммсч
*/
FLYSSP_API void mata(double a[], double r[], int n, int m, int ms);
/* XCPY.C
   бШАop Х ГaОХcЭ ОoДЛaРpХЖШ ХГ ГaДaММoИ ЛaРpХЖШ
*/
FLYSSP_API void xcpy(double a[], double r[],
	  int l, int k, int nr, int mr, int na, int ma, int ms);
/* GMADD.C
   якнфемхе дбсу люрпхж наыецн бхдю
*/
//void  gmadd(double a[], double b[], double r[], int n, int m);
/* GMTRA.C
   рпюмяонмхпнбюмхе люрпхжш наыецн бхдю
*/
FLYSSP_API void  gmtra(double a[], double r[], int n, int m);
/* GTPRD.C
   слмнфемхе рпюмяонмхпнбюмммни люрпхжш мю дпсцсч люрпхжс наыецн бхдю
*/
FLYSSP_API void  gtprd(double a[], double b[], double r[], int n, int m, int l);
/* GMSUB.C
   бшвхрюмхе дбсу люрпхж наыецн бхдю
*/
FLYSSP_API void   gmsub(double a[], double b[], double r[], int n, int m);
/* GMPRD.C
   опнхгбедемхе дбсу люрпхж наыецн бхдю
*/
FLYSSP_API void  gmprd(double a[], double b[], double r[], int n, int m, int l);
/* GMPRD2.C
   опнхгбндмюъ опнхгбедемхъ дбсу люрпхж наыецн бхдю
*/
FLYSSP_API void difgmprd(double a[], double b[], double aa[], double bb[],
	    double c[], int n, int m, int l);
FLYSSP_API void difsmprd3(double *a, double *b, double *c, double *d);
/* LOC.C
   бшвхякемхе бейрнпмнцн хмдейяю щкелемрю люрпхжш, пюяонкнфеммни б
   оюлърх б бейрнпмни тнпле
*/
FLYSSP_API void  loc(int i, int j, int *ir, int n, int m, int ms);
/* MPRD.C
   опнхгбедемхе дбсу люрпхж опнхгбнкэмнцн бхдю
*/
FLYSSP_API void mprd(double a[], double b[], double r[], int n, int m, int l, int msa, int msb);
/* TPRD.C
   слмнфемхе рпюмяонмхпнбюмммни люрпхжш мю дпсцсч люрпхжс
*/
FLYSSP_API void  tprd(double a[], double b[], double r[], int n, int m, int msa, int msb, int l);
/* MCPY.C
   йнохпнбюмхе люрпхжш
*/
FLYSSP_API void  mcpy(double a[], double r[], int n, int m, int ms);
/* MTRA.C
   рпюмяонмхпнбюмхе люрпхжш
*/
FLYSSP_API void  mtra(double a[], double r[], int n, int m, int ms);
/* MADD.C
   якнфемхе дбсу люрпхж
*/
//void  madd(double a[], double b[], double r[], int n, int m, int msa, int msb);
/* MSUB.C
   бшвхрюмхе дбсу люрпхж
*/
FLYSSP_API void  msub(double a[], double b[], double r[], int n, int m, int msa, int msb);

/* _SQFSOL.C
   пюявер йбюдпюрхвмни тнплш я свернл бнглнфмни
   бшпнфдеммнярх йл мебъгйх
*/
FLYSSP_API double  sqfsolve(double n, double A[], double B[], double d[],
		double dleft[],double dright[],double matr[],
		double tau,int *nmin);

/* APCHA.C
	  юоопнйяхлюжхъ гюдюммни дхяйпермни тсмйжхх
	  нпрнцнмюкэмшлх онкхмнлюлх веашьебю C юбрнлюрхвеяйхл бшанпнл
	  яреоемх юоопнйяхлхпсчыецн онкхмнлю */
FLYSSP_API int  apcha(double *top, double *work, int n, int m,
	    int st_max, double *sqkr,double *c,
	    double *xd,double *x0,
	    float eps,float eta);

/* NDTRI.C
   напюрмюъ тсмйжхъ мнплюкэмнцн пюяопедекемхъ
*/
FLYSSP_API int  ndtri(float p, float  *x, float  *d);
/* NDTR.C
   тсмйжхъ мнплюкэмнцн пюяопедекемхъ
*/
FLYSSP_API float  ndtr(float x, float *d);
/*  MSECH.C
    бшвхякемхе мскъ тсмйжхх f(x) мю хмрепбюке [a,b]
    лернднл яейсыху-унпд
*/
FLYSSP_API double msechord(const double a, const double b, int *iter,
		float tol, double (*fuser)(const double ,const void *),
		const void *userdata);
/* QTFG.C
   хмрецпхпнбюмхе тсмйжхх, гюдюммни рюакхвмн б мепюбмннрярнъыху
   рнвйюу, он тнплске рпюоежхи
*/
FLYSSP_API void  qtfg(double x[], double y[], double z[], int ndim);
/* QSF.C
   хмрецпхпнбюмхе тсмйжхх, гюдюммни рюакхжеи гмювемхи
   б пюбмннрярнъыху рнвйюу, он тнплскюл мэчрнмю-йнреяю
*/
FLYSSP_API void  qsf(double h, double y[], double z[], int ndim);
/* FORIF.C
   бшвхякемхе йнщттхжхемрнб тспэе оепхндхвеяйни тсмйжхх
*/
FLYSSP_API int  forif(double(*fun)(double), int n, int m,
	    double a[], double b[]);
/* FORIT.C
   бшвхякемхе йнщттхжхемрнб тспэе оепхндхвеяйни тсмйжхх,
   гюдюммни рюакхжеи гмювемхи
*/
FLYSSP_API int  forit(double fnt[], int n, int m, double a[], double b[]);
/* FORITN.C
   бшвхякемхе йнщттхжхемрнб тспэе оепхндхвеяйни тсмйжхх,
   гюдюммни рюакхжеи гмювемхи б мепюбмннрярнъыху сгкюу
*/
FLYSSP_API int  foritn(double t[], double fnt[], int n, int m,
	     double a[], double b[], double work[]);
/* TRENDD.C
   сдюкемхе рпемдю бхдю Y=FUN(C,X,M) хг тсмйжхх, гюдюммни рюакхжеи
   гмювемхи б мепюбмннрярнъыху сгкюу
*/
FLYSSP_API void trendd(double x[], double y[], int n, double c[], int m,
	     double (*fun)(double ,double *,int));
/* TRENDL.C
   бшвхякемхе йнщттхжхемрнб кхмеимни пецпеяяхх,
   гюдюммни рюакхжеи гмювемхи б мепюбмннрярнъыху сгкюу
*/
FLYSSP_API void  trendl(double x[], double y[], int n, double c[]);
/* TRENDLS.C
   бшвхякемхе гмювемхъ кхмеимнцн рпемдю
*/
FLYSSP_API double trendls(double x, double c[], int m);
/* TRENDI.C
   бшвхякемхе йнщттхжхемрнб пецпеяяхх бхдю Y=C0+C1/X,
   гюдюммни рюакхжеи гмювемхи б мепюбмннрярнъыху сгкюу
*/
FLYSSP_API void  trendi(double x[], double y[], int n, double c[]);
/* TRENDIS.C
   бшвхякемхе гмювемхъ рпемдю бхдю Y=C0+C1/X
*/
FLYSSP_API double trendis(double x, double c[], int m);
/* TRENDQ.C
   бшвхякемхе йнщттхжхемрнб пецпеяяхх бхдю Y=C0+C1*X*X,
   гюдюммни рюакхжеи гмювемхи б мепюбмннрярнъыху сгкюу
*/
FLYSSP_API void  trendq(double x[], double y[], int n, double c[]);
/* TRENDQS.C
   бшвхякемхе гмювемхъ рпемдю бхдю Y=C0+C1*X*X
*/
FLYSSP_API double trendqs(double x, double c[], int m);

/* MOMEN.C
	    бшвхякемхе оепбшу вершпеу лнлемрнб
*/
FLYSSP_API void  momen(double f[], double ubo[], int nop, double ans[]);
/* MSTR.C
	    хглемемхе яонянаю упюмемхъ йбюдпюрмни люрпхжш
*/
FLYSSP_API void  mstr(double a[], double r[], int n, int msa, int msr);

/* MSET.C
     опхябнемхе N аюирюл мювхмюъ я юдпеяю S гмювемхъ йндю C
*/
FLYSSP_API void *mset(void *s, char unsigned c, int n);
FLYSSP_API void *mcopy(void *dest, const void *src, int n);
/* CCPY.C
   опедярюбкемхе ярнкажю люрпхжш б бхде бхйрнпю
*/
FLYSSP_API void ccpy(double a[], int jn, double r[], int n, int m, int ms);
/* RCPY.C
   опедярюбкемхе ярпнйх люрпхжш б бхде бхйрнпю
*/
FLYSSP_API void rcpy(double a[], int jn, double r[], int n, int m, int ms);
/*  SADD.C
     якнфемхе йюфднцн щкелемрю люрпхжш ян яйюкъпнл */
FLYSSP_API void sadd(double a[], double c, double r[], int n, int m, int ms);
/*  SSUB.C
     бшвхрюмхе яйюкъпю хг йюфднцн щкелемрю люрпхжш */
FLYSSP_API void ssub(double a[], double c, double r[], int n, int m, int ms);
/*  SMPY.C
     слмнфемхе йюфднцн щкелемрю люрпхжш мю яйюкъп */
FLYSSP_API void smpy(double a[], double c, double r[], int n, int m, int ms);
/*  SDIV.C
     слмнфемхе йюфднцн щкелемрю люрпхжш мю яйюкъп */
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

/* SVD.C яхмцскъпмне пюгкнфемхе люрпхж
*/
FLYSSP_API int svd(int m, int n, double a[], double w[], double v[], double work[]);
/* SVDINV.C напюыемхе люрпхж лмй (ямс ХКХ ясс) лернднл яхмцскъпмнцн пюгкнфемхъ
*/
FLYSSP_API void svdinv(int m, int n, double w[], double v[],
	    int ncomp, double tau,
	    double ainv[]);
/* SVDGINV.C напюыемхе йбюдпюрмшу люрпхж наыецн бхдю лернднл яхмцскъпмнцн пюгкнфемхъ
*/
FLYSSP_API void svdginv(int n, double u[], double w[], double v[],
	    int ncomp, double tau, double ainv[]);
/* SVDLAE.C пеьемхе ясс ХКХ ямс лернднл яхмцскъпмнцн пюгкнфемхъ
*/
FLYSSP_API void svdlae(int m, int n, double a[], double w[], double v[],
	    double b[],
	    int *ncomp,
	    double *avt, double *tau,
	    double x[],
	    double cond[]);
/* SVDSORT.C янпрхпнбйю яхмцскъпмнцн пюгкнфемхъ
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
    дхттепемжхпнбюехе тсмйжхх, гюдюммни рюакхжеи гмювемхи
    б мепюбмннрярнъыху рнвйюу
*/
FLYSSP_API int dgt3(double x[], double y[], double z[], int ndim);
/* DET3.C
    дхттепемжхпнбюехе тсмйжхх, гюдюммни рюакхжеи гмювемхи
    б пюбмннрярнъыху рнвйюу, он тнплскюл кюцпюмфю он
    рпел сгкюл
*/
FLYSSP_API int det3(double h, double y[], double z[], int ndim);
/*  DET5.C
    дхттепемжхпнбюехе тсмйжхх, гюдюммни рюакхжеи гмювемхи
    б пюбмннрярнъыху рнвйюу, он тнплскюл кюцпюмфю он
    оърх сгкюл
*/
FLYSSP_API int det5(double h, double y[], double z[], int ndim);
/* DCAR.C
    дхттепемжхпнбюехе тсмйжхх б жемрпе хмрепбюкю
    лернднл щйярпюонкъжхх пхвюпдянмю х пнлаепцю
*/
FLYSSP_API double dcar(double x, double h, int ih, double(*fct)(double));
/* DBAR.C
    дхттепемжхпнбюехе тсмйжхх мю цпюмхже хмрепбюкю
    лернднл щйярпюонкъжхх пхвюпдянмю х пнлаепцю
*/
FLYSSP_API double dbar(double x, double h, int ih, double(*fct)(double));

/* VCPY.C
	  йнохпнбюмхе бейрнпю
*/
//void veccpy(double qout[],double qin[],int sz);
//void veccpy1(double dest[],double src[],int sz);
//void veccpy(double dest[],double src[],int sz);
/* VSUB.C
	  бшвхрюмхе дбсу бейрнпнб
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
   пюявер юлокхрсдш он йнщттхжхемрюл тспэе
*/
FLYSSP_API double Anw(double aw, double bw);
/* FNW.C
   пюявер тюгш он йнщттхжхемрюл тспэе
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
     янярюбкемхе яхярелш мнплюкэмшу спюбмемхи, бнгмхйючыеи опх (мюхксвьеи
     б ялшяке лерндю мюхлемэьху йбюдпюрнб) юоопнйяхлюжхх гюдюммни
     дхяйпермни тсмйжхх кхмеимни йнлахмюжхееи тсмйжхи
*/
FLYSSP_API void apll(void(*ffct)(int, int, int, double *, double *, double *, int *),
	 int n, int ip, double p[], double work[], double dati[],int irr[]);

/* FRAT.C
*/
FLYSSP_API void frat(int i, int n, int m, double p[], double dati[], double *wgt, int ier[]);
/* ARAT.C
   юоопнйяхлюжхъ гюдюммни дхяйпермни тсмйжхх пюжхнмюкэмни тсмйжхеи мю
   нямнбе лмй
*/
FLYSSP_API int arat(double dati[], int n, double work[], double p[], int ip, int iq);
/*   PADD.C
     яКoФeМХe ДБСx ОoКХМoЛoБ
*/
FLYSSP_API void padd(double z[], int *idimz, double x[], int idimx, double y[], int idimy);
/*   PNORM.C
     мopЛХpoБЙa БeЙРopa ЙoЩТТХЖХeМРoБ ОoКХМoЛa
*/
FLYSSP_API int pnorm(double x[], int idimx, double eps);
/*   PDIV.C
     дeКeМХe oДМoЦo ОoКХМoЛa Мa ДpСЦoИ
*/
FLYSSP_API int pdiv(double p[], int *idimp, double x[], int idimx, double y[], int idimy,
	 double tol);
/*   PMPY.C
     сЛМНФЕМХЕ oДМoЦo ОoКХМoЛa Мa ДpСЦoИ
*/
FLYSSP_API void pmpy(double z[], int *idimz, double x[], int idimx, double y[], int idimy);
/*   PSUB.C
     бШВХРЮМХЕ НДМНЦН ОoКХМoЛЮ ХГ ДПСЦНЦН
*/
FLYSSP_API void psub(double z[], int *idimz, double x[], int idimx, double y[], int idimy);
/*   PVAL.C
     пЮЯВЕР ГМЮВЕМХЪ ОoКХМoЛЮ ДКЪ ЮПЦСЛЕМРЮ (ЯУЕЛЮ цНПМЕПЮ)
*/
FLYSSP_API double pval(double arg, double x[], int idimx);
/*   POLRT.C
     бШВХcКeМХe ДeИcРБХРeКЭМШx Х ЙoЛОКeЙcМШx ЙopМeИ ОoКХМoЛa
*/
FLYSSP_API int polrt(double xcof[], double cof[], int m, double rootr[], double rooti[]);
/*   PCLA.C
     MOVE POLYNOMIAL X TO Y
*/
FLYSSP_API void pcla(double y[], int *idimy, double x[], int idimx);
/*   PADDM.C
     яКoФeМХe ЙoЩТТ. oДМoЦo ОoКХМoЛa c ЙoЩТТ. ДpСЦoЦo СЛoФeММШЛХ Мa ЛМoФ.
*/
FLYSSP_API void paddm(double z[], int *idimz, double x[], int idimx, double fact,
	   double y[], int idimy);
/*   PVSUB.C
     SUBSTITUTE VARIABLE OF A POLYNOMIAL BY ANOTHER POLYNOMIAL
*/
FLYSSP_API void pvsub(double z[], int *idimz, double x[], int idimx, double y[], int idimy,
	   double work1[], double work2[]);
/*   MDIAN1.C
     пюявер бшанпнвмни ледхюмш
     (ЯНПРХПНБЙЮ Я ХЯОНКЭГНБЮМХЕЛ qsort)
*/
FLYSSP_API double mdian1(double x[], int n);
/*   MDIAN2.C
     пюявер бшанпнвмни ледхюмш
     (ЯНПРХПНБЙЮ БМСРПХ ОПНЦПЮЛЛШ)
*/
FLYSSP_API double mdian2(double x[], int n);
/*   AVEVAR.C
     пюявер бшанпнвмшу япедмецн х дхяоепяхх (МЕЯЛЕЫЕММЮЪ НЖЕМЙЮ)
*/
FLYSSP_API void avevar(double data[], int n, double *ave, double *svar);
/*   MOMENT.C
     пюявер бшанпнвмшу уюпюйрепхярхй Mx,M[Mx],Sx,Dx,Ac,Ek
*/
FLYSSP_API int  moment(double data[], int n,
	    double *ave,   // Mx - ЯПЕДМЕЕ ЮПХТЛЕРХВЕЯЙНЕ
	    double *adev,  //    - ЯПЕДМЕЕ НРЙКНМЕМХЕ НР Mx
	    double *sdev,  // Sx - ЯПЕДМЕЕ ЙБЮДПЮРХВЕЯЙНЕ
	    double *svar,  // Dx - ДХЯОЕПХЯЪ
	    double *skew,  // Ac - ЮЯХЛЛЕРПХЪ
	    double *curt); // Ek - ЩЙЯЖЕЯЯ
/*   CORR.C
     пюявер япедмху гмювемхи, ярюмдюпрмшу нрйкнмемхи, йнбюпхюжхи х
     йнщттхжхемрнб йнппекъжхх
*/
FLYSSP_API int corr(double  x[],  /* ХЯУНДМЮЪ ЛЮРПХЖЮ МЮАКЧДЕМХИ [n*k] */
	 int     n,    /* ВХЯКН МЮАКЧДЕМХИ (ЯРПНЙ)  */
	 int     k,    /* ВХЯКН МЮАКЧДЮЕЛШУ ТЮЙРНПНБ (ЯРНКАЖНБ)*/
	 double *x_,   /* БЕЙРНП ЯПЕДМХУ */
	 double *s_,   /* БЕЙРНП яйн */
	 double *S,    /* ЙНБЮПХЮЖХНММЮЪ ЛЮРПХЖЮ*/
	 double *R     /* ЙНППЕКЪЖХНММЮЪ ЛЮРПХЖЮ*/);
/*   CORRE.C
     пюявер япедмху гмювемхи, ярюмдюпрмшу нрйкнмемхи, йнбюпхюжхи х
     йнщттхжхемрнб йнппекъжхх
*/
FLYSSP_API void corre(int n, int m, double x[],
	   double xbar[],double std[],double rx[],
	   double r[],double b[],double d[],double t[],
	   void (*data)(int, double *) );
/*   ORDER.C
     тнплхпнбюмхе хг онкмни люрпхжш йнбюпхюжхи ондлюрпхж
     йнщттхжхемрнб йнппекъжхх лефдс мегюбхяхлшлх оепелеммшлх
     х бейрнпю бгюхлмшу йнппекъжхи лефдс мегюбхяхлшлх оепелеммшлх
     х яюлни оепелеммни
*/
FLYSSP_API void order(int m, double r[], int ndep, int k, int isave[], double rx[], double ry[]);
/*   MULTR.C
     лмнфеярбеммши кхмеимши пецпеяяхнммши юмюкхг дкъ гюбхяхлни оепелеммни
     х лмнфеярбю мегюбхяхлшу оепелеммшу
*/
FLYSSP_API void multr(int n, int k, double xbar[], double std[],
	   double d[], double rx[], double ry[],
	   int isave[], double b[], double sb[],
	   double t[], double ans[]);
/*   MEAN.C
     пюявер бшанпнвмнцн япедмецн он пейсппемрмни тнплске
*/
FLYSSP_API void mean(double xi, double *Mx, int *n);
/*   SDAD.C
     пюявер япедмеи нрмняхрекэмни ньхайх х бекхвхмш нярюрнвмни дхяоепяхх
     дкъ юмюкхгю йювеярбю юоопнйяхлюжхх бпелеммшу пъднб
*/
FLYSSP_API int sdad(int n, double x[], double y[],
	   double *sdev,double *adev,
	   double sig[],
	   void (*fdata)(int i, double *xi, double *yi) );
/*   FORITG.C
     бшвхякемхе гмювемхъ пюгкнфемхъ тспэе
*/
FLYSSP_API double foritg(double t, double f1, int m, double a[], double b[]);
/*   CMPLX.C
     ноепюжхх мюд йнлокейямшлх вхякюлх
*/
FLYSSP_API void cmplxadd(double a1[], double a2[], double a[]);
FLYSSP_API void cmplxsub(double a1[], double a2[], double a[]);
FLYSSP_API void cmplxmpy(double a1[], double a2[], double a[]);
FLYSSP_API void cmplxdev(double a1[], double a2[], double a[]);
FLYSSP_API void cmplxeq(double alpha[], double a[]);
/*   CONJ.C
     йНЛОКЕЙЯМН-ЯНОПЪФЕММНЕ ВХЯКН
*/
FLYSSP_API void conj(double x[], double y[]);

/*   FFTRAN.C
     ашярпне опенапюгнбюмхе тспэе (опълне х напюрмне)
*/
FLYSSP_API int fftran(int sign, double t, double *x, int unsigned npow);
/*   FCFAW.C
     оНКСВЕМХЕ ЙКЮЯЯХВЕЯЙНЦН от ХГ ЙНЛОКЕЙЯМНЦН (ЙНЩТТХЖХЕМР A)
*/
FLYSSP_API double fcfaw(double x[]);
/*   FCFBW.C
     оНКСВЕМХЕ ЙКЮЯЯХВЕЯЙНЦН от ХГ ЙНЛОКЕЙЯМНЦН (ЙНЩТТХЖХЕМР B)
*/
FLYSSP_API double fcfbw(double x[]);
/*   SQF.C
     пЮЯВЕР ЙБЮДПЮРХВМНИ ТНПЛШ БХДЮ C(M,L)=A(M,N)*P(N,K)*S(K,L)+W(M,L)
*/
FLYSSP_API void sqf(double *a, double *p, double *s, double *w,
	 int M, int N, int K, int L, double *c);
/*   SQFT.C
     пЮЯВЕР ЙБЮДПЮРХВМНИ ТНПЛШ БХДЮ C(M,L)=A(M,N)*P(N,K)*tans(S(L,K))+W(M,L)
*/
FLYSSP_API void sqft(double *a, double *p, double *s, double *w,
	   int M, int N, int K, int L, double *c);
/*   BCPY.C
     йнохпнбюмхе акнйю опълнсцнкэмни ндмни люрпхжш
     б сйюгюммне леярн дпсцни опълнсцнкэмни люрпхжш
*/
FLYSSP_API int bcpy(double *a, double *r, int na, int ma, int nr, int mr,
	 int ir,int jr);
/*   GMSMGT.C
     сЛМНФЕМХЕ ЛЮРПХЖШ НАЫЕЦН БХДЮ МЮ ЯХЛЛЕРПХВМСЧ, Ю ЕЕ
     ПЕГСКЭРЮРЮ МЮ ХЯУНДМСЧ РПЮМЯОНМХПНБЮММСЧ НАЫЕЦН БХДЮ
*/
FLYSSP_API int gmsmgt(double *a, double *s, int n, int m, double *r, double *d);

/*   PILD.C
     пЮЯВЕР ГМЮВЕМХЪ ОoКХМoЛa Х eЦo ОpoХГБoДМoИ ДКЪ
     ГaДaММoЦo apЦСЛeМРa
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
     THIS SUBROUTINE бшвхякъер едхмхвмши бейрнп
*/
FLYSSP_API void vunit(double a[], double b[]);
/*   VMATR.C
     бярюбйю лемэьеи люрпхжш акнйнл б анкэьсч
*/
FLYSSP_API int vmatr(double a[], int na, int ma, double b[], int nb, int mb, int i, int j);

/*   VECSB.C
     пюгмнярэ бейрнпнб, пюглепмнярх 3 */
//void vecsb(double a[], double b[], double c[]);
/*   VECAD.C
     ясллю бейрнпнб, пюглепмнярх 3*/
//void vecad(double a[], double b[], double c[]);
/*   MMUL5.C
     опнхгбедемхе 5-РХ люрпхж, пюглепмнярх 3*3 */
//void mmul5(double a[], double b[], double c[], double d[],  double e[], double f[]);
/*   MMUL3.C
     опнхгбедемхе 3-У люрпхж, пюглепмнярх 3*3 */
//void mmul3(double a[], double b[], double c[], double d[]);
/*   MMUL2.C
     опнхгбедемхе 2-У люрпхж, пюглепмнярх 3*3 */
//void mmul2(double a[], double b[], double c[]);
/*   MADD5.C
     ясллю 5-РХ люрпхж, пюглепмнярх 3*3 */
//void  madd5(double a[], double b[], double c[], double d[], double e[], double f[]);
/*   MADD4.C
     ясллю 4-У люрпхж, пюглепмнярх 3*3 */
//void  madd4(double a[], double b[], double c[], double d[], double e[]);
/*   MADD3.C
     ясллю 3-У люрпхж, пюглепмнярх 3*3 */
//void  madd3(double a[], double b[], double c[], double d[]);
/*   MADD2.C
     ясллю 2-У люрпхж, пюглепмнярх 3*3 */
//void  madd2(double a[], double b[], double c[]);
/*   ROTAT.C
     нпрнцнмюкэмюъ люрпхжю.
     онбнпнр мю сцнк опнрхб вюянбни ярпекйх */
FLYSSP_API void rotat(double theta, int i, double r[]);
/*   DROTT.C
     оепбюъ опнхгбндмюъ нпрнцнмюкэмни люрпхжш.
     онбнпнр мю сцнк опнрхб вюянбни ярпекйх */
FLYSSP_API void drott(double theta, double dtheta, int i, double dr[]);
/*   DDROT.C
     брнпюъ опнхгбндмюъ нпрнцнмюкэмни люрпхжш.
     онбнпнр мю сцнк опнрхб вюянбни ярпекйх */
FLYSSP_API void ddrot(double theta, double ddthta, int i, double ddr[]);
/*   D3ROT.C
     рперэъ опнхгбндмюъ нпрнцнмюкэмни люрпхжш.
     онбнпнр мю сцнк опнрхб вюянбни ярпекйх */
FLYSSP_API void d3rot(double theta, double d3thet, int i, double d3r[]);
/*   VECRT.C
     опнхгбедемхе люрпхжш мю бейрнп, пюглепмнярх 3.
     лЮРПХЖЮ ю РПЮМЯОНМХПСЕРЯЪ. */
FLYSSP_API void vecrt(double a[], double v[], double rv[]);

#ifdef __cplusplus
}
#endif

#define IEND	(INT_MAX-1)
#define LEND	(LONG_MAX-1)
#define FEND	(1.e+38-1.)

/* яонянаш упюмемхъ люрпхж */
#define GENERAL   0      /* наыхи яоняна упюмемхъ */
#define SYMMETRIC 1      /* яхллерпхвмши */
#define DIAGONAL  2      /* дхюцнмюкэмши */

#define for_if(arg) 	((arg)>0. ? 1:((arg)<0. ?-1:0))

#endif /* __SSP_H */

