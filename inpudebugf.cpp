//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "inpudebugf.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNeptDebug *NeptDebug;
//---------------------------------------------------------------------------
__fastcall TNeptDebug::TNeptDebug(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
