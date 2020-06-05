//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "cdn_clock_frm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCDN_CLOCK *CDN_CLOCK;
static int f;
//---------------------------------------------------------------------------
__fastcall TCDN_CLOCK::TCDN_CLOCK(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TCDN_CLOCK::Timer1Timer(TObject *Sender)
{
Label5->Caption=Now().FormatString("hh");
Label1->Caption=Now().FormatString("nn");
Label4->Caption=Now().FormatString("hh");
f++;
Label7->Caption=f;
/* if(Now().FormatString("hh")<12){
Label6->Visible=false;
Label2->Visible=true;} else {
Label6->Visible=true;
Label2->Visible=false; }
if(Now().FormatString("hh")==12){
Label6->Visible=true;
Label2->Visible=false; 
} */
}
//---------------------------------------------------------------------------
