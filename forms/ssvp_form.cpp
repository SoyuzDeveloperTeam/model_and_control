//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ssvp_form.h"
#include "ssvp_module.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tssvp_frm *ssvp_frm;
//---------------------------------------------------------------------------
__fastcall Tssvp_frm::Tssvp_frm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tssvp_frm::Timer1Timer(TObject *Sender)
{
xod_shtangi++;
xod_sh->Position=xod_shtangi;
s_pos->Caption=IntToStr(xod_sh->Position);
s_pos->Top--;
}
//---------------------------------------------------------------------------
void __fastcall Tssvp_frm::test_btnClick(TObject *Sender)
{
Timer1->Enabled=1;
}
//---------------------------------------------------------------------------
void __fastcall Tssvp_frm::FormCreate(TObject *Sender)
{
ssvp_pas->Canvas->Pen->Color=clBlack;
ssvp_pas->Canvas->MoveTo(20,56);
ssvp_pas->Canvas->LineTo(20,96);
}
//---------------------------------------------------------------------------
