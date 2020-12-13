//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "brus_form.h"
#include "pults_tk.h"
#include "JouHeader.h"         // Заголовок для журнала
#include "JouStrings.h"        // Строковые переменные для журнала
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tbrus_frm *brus_frm;
//---------------------------------------------------------------------------
__fastcall Tbrus_frm::Tbrus_frm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tbrus_frm::epkrd_osn_offClick(TObject *Sender)
{
 brus_key.epkrd_osn=true;
 epkrd_osn_off->Visible=false;
 epkrd_osn_on->Visible=true;
  JPS(1,is_operator,is_brus,"Питание ЭПКРД ОСН          ","ВКЛ");
}
//---------------------------------------------------------------------------

void __fastcall Tbrus_frm::epkrd_osn_onClick(TObject *Sender)
{
 brus_key.epkrd_osn=false;
 epkrd_osn_off->Visible=true;
 epkrd_osn_on->Visible=false;
  JPS(1,is_operator,is_brus,"Питание ЭПКРД ОСН          ","ВЫКЛ");
}
//---------------------------------------------------------------------------

void __fastcall Tbrus_frm::epkrd_rez_offClick(TObject *Sender)
{
 brus_key.epkrd_rez=true;
 epkrd_rez_off->Visible=false;
 epkrd_rez_on->Visible=true;
  JPS(1,is_operator,is_brus,"Питание ЭПКРД РЕЗ          ","ВКЛ");
}
//---------------------------------------------------------------------------

void __fastcall Tbrus_frm::epkrd_rez_onClick(TObject *Sender)
{
 brus_key.epkrd_rez=false;
 epkrd_rez_off->Visible=true;
 epkrd_rez_on->Visible=false;
  JPS(1,is_operator,is_brus,"Питание ЭПКРД РЕЗ          ","ВЫКЛ");
}
//---------------------------------------------------------------------------

void __fastcall Tbrus_frm::vsa_offClick(TObject *Sender)
{
 brus_key.vsa=true;
 vsa_off->Visible=false;
 vsa_on->Visible=true;
  JPS(1,is_operator,is_brus,"ВСА                        ","ВКЛ");
}
//---------------------------------------------------------------------------

void __fastcall Tbrus_frm::vsa_onClick(TObject *Sender)
{
 brus_key.vsa=false;
 vsa_off->Visible=true;
 vsa_on->Visible=false;
  JPS(1,is_operator,is_brus,"ВСА                        ","ВЫКЛ");
}
//---------------------------------------------------------------------------

