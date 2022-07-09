//---------------------------------------------------------------------------


#pragma hdrstop

#include "md_main.h"
#include "JouHeader.h"
#include "JouStrings.h"

HINSTANCE FlyCoreLib = LoadLibrary("libs\\FlyCore.dll");
HINSTANCE FlyChebyshovLib = LoadLibrary("libs\\FlyChebyshov.dll");
HINSTANCE FlyFormatLib = LoadLibrary("libs\\FlyFormat.dll");
HINSTANCE FlyMMathLib = LoadLibrary("libs\\FlyMMath.dll");

typedef void (*TSuitabilityTurnArg)(float &,int &,bool);
typedef void (*TUmpr)() ;
typedef void (*TFC_LoadNU)();          //?LoadNU@@YAHAAUZKEYNU@@AAUZNU@@@Z
typedef void (*TFC_ZFUS)(double t, double *GSC, double *ASC, double *A); //?ZFUS@@YAHNPAN00@Z


TUmpr umpr = 0;
TSuitabilityTurnArg SuitabilityTurnArg = 0;
TFC_ZFUS ZFUS = 0;


//---------------------------------------------------------------------------

void init_md(){
      if( FlyCoreLib >= (HINSTANCE)32 )  // Загружаем библиотеку для мат.моделирования
  {
     ZFUS = (TFC_ZFUS)GetProcAddress(FlyCoreLib,"?ZFUS@@YAHNPAN00@Z");
  }


   if( FlyMMathLib >= (HINSTANCE)32 )  // Загружаем библиотеку для мат.моделирования
  {
    SuitabilityTurnArg = (TSuitabilityTurnArg)GetProcAddress( FlyMMathLib, "??$SuitabilityTurnArg@MH@@YAXAAMAAH_N@Z");
    umpr = (TUmpr)GetProcAddress( FlyMMathLib, "?umpr@@YAXPAN00@Z");
  }

  if(!ZFUS)JPS(3,"Модель Движения  -  Ошибка загрузки библиотеки FlyCore.","","",""); else
  JPS(1,"Модель Движения  -  Загружена библиотека FlyCore.","","","");

  // Налаживаем сетевой обмен с МД
 //umpr
}

#pragma package(smart_init)
