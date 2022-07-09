//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "JouLogFrm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TJouLogForm *JouLogForm;
//---------------------------------------------------------------------------
__fastcall TJouLogForm::TJouLogForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TJouLogForm::JouLBDrawItem(TWinControl *Control, int Index,
      TRect &Rect, TOwnerDrawState State)
{

    int clr = (int)(JouLB->Items->Objects[Index]);
    switch(clr)
    {
        case 1: JouLB->Canvas->Brush->Color = clWhite;
                JouLB->Font->Color=clBlack;  break;
        case 2: JouLB->Canvas->Brush->Color = clYellow;
                JouLB->Font->Color=clBlack;  break;
        case 3: JouLB->Canvas->Brush->Color = clRed;
                JouLB->Font->Color=clBlack;  break;
        case 4: JouLB->Canvas->Brush->Color = clLime;
                JouLB->Font->Color=clBlack;  break;
        default:
          JouLB->Canvas->Brush->Color = clLime;
    }
    TCanvas *pCanvas = ((TListBox *)Control)->Canvas;
     if( State.Contains(odSelected) ) {
        pCanvas->Brush->Color = clActiveCaption;
        pCanvas->Font->Color =clBlack;
    }
    JouLB->Canvas->FillRect(Rect);
    JouLB->Canvas->TextOut(Rect.Left, Rect.Top, JouLB->Items->Strings[Index]);
}
//---------------------------------------------------------------------------



void __fastcall TJouLogForm::SpeedButton1Click(TObject *Sender)
{
JouLB->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TJouLogForm::SpeedButton2Click(TObject *Sender)
{
AnsiString filename=Now().FormatString("ddmmyy-hh_mm_ss_")+"JOU_log.mjf";

SJ->FileName=filename;
SJ->Options<<ofPathMustExist << ofOverwritePrompt;
if(SJ->Execute())
JouLB->Items->SaveToFile(SJ->FileName);
}
//---------------------------------------------------------------------------

// *.MJF - MiU Journal File



