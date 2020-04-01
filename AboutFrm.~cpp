//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AboutFrm.h"
#include <vcl\Clipbrd.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutForm *AboutForm;
//---------------------------------------------------------------------------
__fastcall TAboutForm::TAboutForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm::Label2Click(TObject *Sender)
{
Clipboard()->AsText = "soyuz.developer@gmail.com"; // Копируем в буфер адрес электронной почты
}
//---------------------------------------------------------------------------

