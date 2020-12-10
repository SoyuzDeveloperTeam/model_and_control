//---------------------------------------------------------------------------


#pragma hdrstop

#include "md_main.h"
#include "JouHeader.h"
#include "JouStrings.h"

HINSTANCE FlyCoreLib = LoadLibrary("FlyCore.dll");
HINSTANCE FlyChebyshovLib = LoadLibrary("FlyChebyshov.dll");
HINSTANCE FlyFormatLib = LoadLibrary("FlyFormat.dll");
HINSTANCE FlyMMathLib = LoadLibrary("FlyMMath.dll");

typedef void (*TSuitabilityTurnArg)(float &,int &,bool);

typedef void (*TUmpr)() ;

TUmpr umpr = 0;
TSuitabilityTurnArg SuitabilityTurnArg = 0;

//---------------------------------------------------------------------------

void init_md(){
      if( FlyCoreLib >= (HINSTANCE)32 )  // ��������� ���������� ��� ���.�������������
  {

  }


   if( FlyMMathLib >= (HINSTANCE)32 )  // ��������� ���������� ��� ���.�������������
  {
    SuitabilityTurnArg = (TSuitabilityTurnArg)GetProcAddress( FlyMMathLib, "??$SuitabilityTurnArg@MH@@YAXAAMAAH_N@Z");
    umpr = (TUmpr)GetProcAddress( FlyMMathLib, "?umpr@@YAXPAN00@Z");
  }

  if(!umpr)JPS(3,"������ ��������  -  ������ �������� ���������� FlyCore.","","",""); else
  JPS(1,"������ ��������  -  ��������� ���������� FlyCore.","","","");
 //umpr
}

#pragma package(smart_init)
 