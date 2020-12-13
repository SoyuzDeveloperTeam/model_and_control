#ifndef FLY_MODEL
#define FLY_MODEL
//---------------------------------------------------------------------------

#pragma hdrstop

#include "fly_model.h"
#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

int TaskTimePrediction();		// Прогноз с заданным шагом по времени

//int chek_nu(ZNU NU){
  // Проверка НУ на подлинность если хорошо - результат - 0
  // Высота не более 500 км и т.д. после добавления кватернионов нормировку перенести сюда.
//}

double ikv_TwoAlpha(double H){
 // H - Высота орбиты км
 // hr - Высота ИК-горизона 15 км
 // Rz - Радиус земли
 double hr = 15, Rz = 6371;
 double A2;
 A2 = asin(Rz+hr/Rz+H);
 return A2;
}

#endif
