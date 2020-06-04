//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fdgd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int a, b;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
a=StrToInt(a1->Text);
b=StrToInt(b1->Text);
xuy->Caption=a+b;
}
//---------------------------------------------------------------------------
