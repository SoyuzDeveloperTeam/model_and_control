//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "forms/CWFrm.h"
#include "argon/CtrlWord.h"             // ”правл€ющие слова јргона - Control words (flags) for argon
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tcwform *cwform;
//---------------------------------------------------------------------------
__fastcall Tcwform::Tcwform(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tcwform::Timer1Timer(TObject *Sender)
{
if(cw_b1[0]==1)  b1_0->Caption="1";  else b1_0->Caption="0";
if(cw_b1[1]==1)  b1_1->Caption="1";  else b1_1->Caption="0";
if(cw_b1[2]==1)  b1_2->Caption="1";  else b1_2->Caption="0";
if(cw_b1[3]==1)  b1_3->Caption="1";  else b1_3->Caption="0";
if(cw_b1[4]==1)  b1_4->Caption="1";  else b1_4->Caption="0";
if(cw_b1[5]==1)  b1_5->Caption="1";  else b1_5->Caption="0";
if(cw_b1[6]==1)  b1_6->Caption="1";  else b1_6->Caption="0";
if(cw_b1[7]==1)  b1_7->Caption="1";  else b1_7->Caption="0";
if(cw_b1[8]==1)  b1_8->Caption="1";  else b1_8->Caption="0";
if(cw_b1[9]==1)  b1_9->Caption="1";  else b1_9->Caption="0";
if(cw_b1[10]==1) b1_10->Caption="1"; else b1_10->Caption="0";
if(cw_b1[11]==1) b1_11->Caption="1"; else b1_11->Caption="0";
if(cw_b1[12]==1) b1_12->Caption="1"; else b1_12->Caption="0";
if(cw_b1[13]==1) b1_13->Caption="1"; else b1_13->Caption="0";
if(cw_b1[14]==1) b1_14->Caption="1"; else b1_14->Caption="0";
if(cw_b1[15]==1) b1_15->Caption="1"; else b1_15->Caption="0";
}
//---------------------------------------------------------------------------
