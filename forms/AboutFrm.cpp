//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AboutFrm.h"
#include "MainFrm.h"
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
Clipboard()->AsText = "misha.smiryagin.sdt@gmail.com"; // Копируем в буфер адрес электронной почты
ctc_label->Visible=1;
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
ctc_label->Visible=0;        
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::Button1Click(TObject *Sender)
{
AboutForm->Close();
}
//---------------------------------------------------------------------------

void __fastcall TAboutForm::FormCreate(TObject *Sender)
{
Label5->Caption="Version: "+GetWVersion();
}
//---------------------------------------------------------------------------

