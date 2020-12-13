//---------------------------------------------------------------------------

#ifndef inkmodelH
#define inkmodelH
#include "math.h"
//---------------------------------------------------------------------------
float imAlpha = 51.6;       //  Наклонение орбиты
float imFi0 = 46.0;         //  Начальная географич. широта
float imLa0 = 64.0;         //  Начальная географич. долгота
float imPeriod = 92.3*60.0; // Период обращения в секундах
float imPeriodCoef = imPeriod/(24*3600);

double GRAD = M_PI/180.0;
double Alpha = imAlpha*GRAD;
double Fi0 = imFi0*GRAD;
double La0 = imLa0*GRAD;

double FloatMod(double x, double y){
  double i;
  return modf(x/y,&i)*y;
}

void CalcInkF(double t, // Текущее время в секундах
             double La, // Координаты в этот момент времени
             double Fi)
{
 double xLong;
 long int N, K;
  while(t<0) t = t + imPeriod;
  xLong = 360/imPeriod*t;
  La = FloatMod(xLong,360)-180;
  Fi = sin(2*M_PI*xLong/(360*(1-imPeriodCoef)))*52.0;
}

#endif
