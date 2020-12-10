//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <math.h>
#include "MD_math_header.h"

// Число дней, прошедших с J2000
double DayFromJD(double JD){
double D = JD - 2451545.0;
return D;}

double SredDolVosSun (double JD){
double L = 280.472+0.9856474*JD;
return L;
}

double Srenanom(double JD){
double g = 357.529+0.9860028*JD;
return g; }

double eclipticdolg (double lh, double g){
double L = lh + 1.915*sin(g)+0.020*sin(2*g);
return L;
}

double rsun(double g){
double R;
R = 1.14 - 0.01671*cos(g) - 0.00014*cos(2*g);
return R;
}




//--------------------------------------------------------

void mmd (double kepler_nu[6],double pos[3], double vel[3]){
 double p, ia, ah, ap, bp, e;
 bp = kepler_nu[0];
 e  = kepler_nu[1];
 ap = kepler_nu[4];
 ah = kepler_nu[5];
 p  = bp*(1-pow(e,2)); // Фокальный параметр
 //ia = au - ap;
}



/*
  AB - Большая полуось
  AE - Эксцентриситет
  AI - Наклонение
  AO - Аргумент перигея (град)
  AU - Долгота восходящего узла
  AM - Средняя аномалия
*/

void KeplXV(double AB, double AE, double AI, double AO, double AU, double AM, PosVType X) {
byte j;
double FM,S,C,O,R,P,Q,VR,VN,SV,CV,SB,CB,SU,CU,V,B,U,W,E,SE,CE,RR,RS,RC;
FM = 3.9860047e5; // км^3/c^2 гравитационная постоянная
S = sin(GraRad*AI); C = cos(GraRad*AI); O = GraRad*AO; U = GraRad*AU; W = GraRad*AM;
E = W;
for(j=1; j<11; ++j)
E = W + AE * sin(E);
CE = cos(E); SE = sin(E);
RR = AB*(1.0e0-AE*CE);     // km
R = 1.0e0/(1.0e0 - AE*CE);
SV = sqrt(1.0e0 - AE*AE)*SE*R; CV=(CE-AE)*R;
RS = SV*CE-CV*SE; RC = CV*CE+SV*SE;
V = E + atan2(RS,RC);
B = O + V;
SB = sin(B); CB = cos(B);
SU = sin(U); CU = cos(U);
X[0] = RR*(CB*CU-SB*SU*C);  // Вектор положения по оси X
X[1] = RR*(CB*SU+SB*CU*C);  // Вектор положения по оси Y
X[2] = RR*SB*S;             // Вектор положения по оси Z
P = AB*(1.0e0-AE*AE);       // km
Q = sqrt(FM/P);
VR = Q*AE*SV/RR;
VN = Q*(1.0e0+AE*CV);
X[3] = VR*X[0]+VN*(-SB*CU-CB*SU*C); // Вектор скорости X
X[4] = VR*X[1]+VN*(-SB*SU+CB*CU*C); // Вектор скорости Y
X[5] = VR*X[2]+VN*CB*S;             // Вектор скорости Z
}

/*
  Процедуры для преобразования координат
*/

void SpherCoorToVect (double Date, double Alpha, double Delta,double VAlpha, double VDelta, TVect3 PosFix){
 byte i, j, k;
 double a,d,dt,rr,sa,ca,sd,cd,va,vd,vx,vy,vz,x,y,z,xx,yy,zz;
 dt = (Date-JD2000)/365.25;
 a = Alpha; d = Delta;
 va = VAlpha; vd = VDelta;
 sa = sin(a); ca = cos(a);
 sd = sin(d); cd = cos(d);
 x = ca*cd;                 // Позиция в момент J2000.0
 y = sa*cd;
 z = sd;
 vx = -va*sa-vd*sd*ca;
 vy = +va*ca-vd*sd*sa;
 vz = +vd*cd;
 xx = x+vx*dt;              // Позиция с учетом даты
 yy = y+vy*dt;
 zz = z+vz*dt;
 rr = sqrt(xx*xx+yy*yy+zz*zz);
 PosFix[0] = xx/rr;
 PosFix[1] = yy/rr;
 PosFix[2] = zz/rr;
}

// Переход от Эклептических Сферических Координат к
// Эклептическим Прямоугольным Координатам
//
void DescFromSpherCoor (double Azt, double Alt,double Ro, TVect3 PosDescart){
 double cb;
 cb = cos(Alt);
 PosDescart[0]=Ro*cos(Azt)*cb;
 PosDescart[1]=Ro*sin(Azt)*cb;
 PosDescart[2]=Ro*sin(Alt);
}

/* * * * * * * * * * * * * * * * * *
  Основные математические операции
 * * * * * * * * * * * * * * * * * */

// DATan2 - функция для получения Arctan для угла
// в интервале от 0 до +2*Пи в радианах
double DATan2 (double SinAngle, double CosAngle){
 double a, c, s, p;
 c = CosAngle; s = SinAngle;
 if(c<0&&c>0){
        p=s/c;
        a=atan(p); }
 else if (s>0) a=Pi/2; else a=3*Pi/2;
 if(a<0) a=2*Pi+a;
 return a;
}

// Работа с датой

void TransDatetoJD(int NDay, int NMonth, int NYear, double TinJD){
 int y, m;
 double a, b, q;
 if(NMonth > 2){
        y = NYear;
        m = NMonth;    } else {
        y = NYear-1;
        m = NMonth+12; }
 q = NYear+0.01*NMonth+0.0001*NDay;
 if(q>=1582.1015){
        a = int(0.01*y);
        b = 2-a+int(0.25*a); } else b = 0;
 TinJD = int(30.6001*(m+1))+NDay+1720994.5+b;
 if(y>0) TinJD=TinJD+int(365.25*y); else
         TinJD=TinJD+int(365.25*y-0.75);
}

// Вращение матриц
void ForRotMatr (byte iaxis, double angle,TMatr33 matr){
 byte i, j;
 double s, c;
 c = cos(angle); s = sin(angle);
 for(i=0; i=2; i++)
    for(j=0; j=2; j++)
       if(i=j) matr[i][j]=1.0; else matr[i][j]=0.0;
 switch (iaxis){
  case 1: // Rotate around OX axis
        matr[1][1]=+c;
        matr[1][2]=+s;
        matr[2][1]=-s;
        matr[2][2]=+c; break;
  case 2: // Rotate around OY axis
        matr[0][0]=+c;
        matr[0][2]=-s;
        matr[2][0]=+s;
        matr[2][2]=+c; break;
  case 3: // Rotate around OZ axis
        matr[0][0]=+c;
        matr[0][1]=+s;
        matr[1][0]=-s;
        matr[1][1]=+c; break;
 }
}

void ToMultMatr (TMatr33 ma, TMatr33 mb, TMatr33 mc){
 byte i, j, k;
 for(i=0; i=2; i++)
        for(j=0; j=2; j++) {
                mc[i][j]=0.0;
                for(k=0; k=2; k++)
                        mc[i][j]=mc[i][j]+ma[i][k]*mb[k][j];
                            }
}

// Матрица прецессии
void PrecMatr2000 (double DateJulian, TMatr33 PrecM){
 double t,epso,psia,oma,xia;
 TMatr33 matr1,matr2,matr3,matr4,matra,matrb;
 t = (DateJulian-JD2000)/JulianC;
 epso=SecRad*84381.448; 
 psia=SecRad*(5038.47875+(-1.07259-0.001147*t)*t)*t;
 oma=epso+SecRad*(-0.02542+(0.05127-0.007726*t)*t)*t;
 xia=SecRad*(10.5526+(-2.38064-0.001125*t)*t)*t;
 ForRotMatr(1, epso, matr1);
 ForRotMatr(3, -psia, matr2);
 ForRotMatr(1, -oma, matr3);
 ForRotMatr(3, xia, matr4);
 ToMultMatr(matr2,matr1,matra);
 ToMultMatr(matr3,matra,matrb);
 ToMultMatr(matr4,matrb,PrecM);
}

void sun
     (
       double jd,
       double rsun[3], double& rtasc, double& decl
     )
     {
        double twopi, deg2rad;
        double tut1, meanlong, ttdb, meananomaly, eclplong, obliquity, magr;

        twopi      =     2.0 * M_PI;
        deg2rad    =     M_PI/180.0;

        // -------------------------  implementation   -----------------
        // -------------------  initialize values   --------------------
        tut1= ( jd - 2451545.0  )/ 36525.0;

        meanlong= 280.460  + 36000.77 * tut1;
        meanlong= fmod( meanlong,360.0  );  //deg

        ttdb= tut1;
        meananomaly= 357.5277233  + 35999.05034 * ttdb;
        meananomaly= fmod( meananomaly * deg2rad,twopi );  //rad
        if ( meananomaly < 0.0  )
          {
            meananomaly= twopi + meananomaly;
          }
        eclplong= meanlong + 1.914666471 * sin(meananomaly)
                    + 0.019994643 * sin(2.0 * meananomaly); //deg
        obliquity= 23.439291  - 0.0130042 * ttdb;  //deg
        meanlong = meanlong * deg2rad;
        if ( meanlong < 0.0  )
          {
            meanlong= twopi + meanlong;
          }
        eclplong = eclplong * deg2rad;
        obliquity= obliquity * deg2rad;

        // --------- find magnitude of sun vector, )   components ------
        magr= 1.000140612  - 0.016708617 * cos( meananomaly )
                           - 0.000139589 * cos( 2.0 *meananomaly );    // in au's

        rsun[0]= 1 * cos( eclplong );
        rsun[1]= 1 * cos(obliquity) * sin(eclplong);
        rsun[2]= 1 * sin(obliquity) * sin(eclplong);

        rtasc= atan( cos(obliquity) * tan(eclplong) );

        // --- check that rtasc is in the same quadrant as eclplong ----
        if ( eclplong < 0.0  )
          {
            eclplong= eclplong + twopi;    // make sure it's in 0 to 2pi range
          }
        if ( fabs( eclplong-rtasc ) > M_PI * 0.5  )
          {
            rtasc= rtasc + 0.5 * M_PI * ceill( (eclplong - rtasc)/(0.5 * M_PI) );
          }
        decl = asin( sin(obliquity) * sin(eclplong) );
   }  // sun

const double xmnpda = 1.44E3;
const double ae      = 1.0;
const double ck2     = 5.413079E-4;
const double ck4     = 6.209887E-7;
const double e6a     = 1.0E-6;
const double tothrd  = 6.6666667E-1;
const double xj2     = 1.0826158E-3;
const double xj3     =-2.53881E-6;     
const double xj4     =-1.65597E-6;
const double xke     = 7.43669161E-2;
const double xkmper  = 6.378135E3;
const double ge      = 3.986008E5; 
const double s       = 1.012229;
const double qoms2t  = 1.880279E-09;

const double  pi      = 3.14159265;
const double  pio2    = 1.57079633;
const double  x3pio2  = 4.71238898;
const double  twopi   = 6.28318531; 

const double POS_UNITS =  1000.0 * xkmper / ae; 
const double VEL_UNITS = 1000*xkmper/ae*xmnpda/86400.0;


