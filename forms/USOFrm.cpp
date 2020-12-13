//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "USOFrm.h"
#include "USOData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUsoForm *UsoForm;
//---------------------------------------------------------------------------
__fastcall TUsoForm::TUsoForm(TComponent* Owner)
        : TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TUsoForm::Timer1Timer(TObject *Sender)
{
if(USO_Booled[0][0]) Label22->Caption="I";  else Label22->Caption=".";
if(USO_Booled[0][1]) Label125->Caption="I"; else Label125->Caption=".";
if(USO_Booled[0][2]) Label205->Caption="I"; else Label205->Caption=".";
if(USO_Booled[0][3]) Label285->Caption="I"; else Label285->Caption=".";
}
//---------------------------------------------------------------------------

