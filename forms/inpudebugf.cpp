//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "inpudebugf.h"
#include "ICN_header.h"
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
void __fastcall TNeptDebug::inpu_dbg_timerTimer(TObject *Sender)
{
PacketNo_send->Caption=IntToStr(CounterNo);
}
//---------------------------------------------------------------------------
