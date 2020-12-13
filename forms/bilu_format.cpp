//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "bilu_format.h"
#include "arg_header.h"
#include "Ctrlword.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "ksdataarr.h"
Tbilu_frm *bilu_frm;
//---------------------------------------------------------------------------
__fastcall Tbilu_frm::Tbilu_frm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall Tbilu_frm::SpeedButton1Click(TObject *Sender)
{
cw_b10[9]=1;
}
//---------------------------------------------------------------------------

void __fastcall Tbilu_frm::bilustTimer(TObject *Sender)
{
//if(bilu_work_pr=1) bst->Caption="еярэ"; else
//bst->Caption="мер";
}
//---------------------------------------------------------------------------

