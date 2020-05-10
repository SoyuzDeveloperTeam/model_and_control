//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#pragma argsused

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
        return 1;
}

int TestFunction(int a, int b){
int q = a+b;
        return a;
}

int TestFunction2(int a, int b){
        return a+b;
}
//---------------------------------------------------------------------------
 