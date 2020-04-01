//---------------------------------------------------------------------------
#include "kdu_math.h"
#include <vcl.h>
#pragma hdrstop

#include "InstructorFormat_Form.h"
#include "arg_header.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TInstructorFormat_FRM *InstructorFormat_FRM;
//---------------------------------------------------------------------------
__fastcall TInstructorFormat_FRM::TInstructorFormat_FRM(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TInstructorFormat_FRM::Image3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.Ex = 2 * 0.2898 * 2;
dpo_status_bit = 1;
}
//---------------------------------------------------------------------------
void __fastcall TInstructorFormat_FRM::Timer1Timer(TObject *Sender)
{
if(!Wx_data[0]==0){
Wx_data[0]=Wx_data[0]-0.0000998793;
}        
}
//---------------------------------------------------------------------------
void __fastcall TInstructorFormat_FRM::Image3MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.Ex = 0;
dpo_status_bit = 0;        
}
//---------------------------------------------------------------------------
void __fastcall TInstructorFormat_FRM::Timer2Timer(TObject *Sender)
{
Label38->Caption=FormatFloat("000.00",dynamics.ypr);   // Sy
Label41->Caption=FormatFloat("000.00",dynamics.zpr);   // Sz
Label44->Caption=FormatFloat("000.00",dynamics.Spr);   // S
 Label1->Caption=FormatFloat("000.00",dynamics.rs);
 Label3->Caption=FormatFloat("000.00",dynamics.sks);
Label30->Caption=FormatFloat("00.000",dynamics.V);
Label29->Caption=FormatFloat("00.000",dynamics.vby);
Label28->Caption=FormatFloat("00.000",dynamics.vbz);
 Label9->Caption=FormatFloat("00.000",dynamics.uomz);
Label10->Caption=FormatFloat("00.000",dynamics.uomy);
}
//---------------------------------------------------------------------------
void __fastcall TInstructorFormat_FRM::Image4Click(TObject *Sender)
{
//Стрелка вверх (Перемещение вверх ДПО №23 №24)
dpo_status_bit = 1;
dynamics.ay = 2 * 0.01915;

}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image16MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//Стрелка вверх (Перемещение вверх ДПО №23 №24)
dynamics.ay = 2 * 0.01915;
dpo_status_bit = 1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image16MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dpo_status_bit = 0;
dynamics.ay = 0;
}
//---------------------------------------------------------------------------



void __fastcall TInstructorFormat_FRM::Image11MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//Левая стрелка РУД (Перемещение влево ДПо №21 №22)
dpo_status_bit = 1;
dynamics.az = 2 * 0.01897;

}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image11MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dpo_status_bit = 0;
dynamics.az = 0;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image10MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// Разгон (крест - ДПО №14, №16)
dynamics.ax = -0.018 * 2;    // На увеличение скорости
dpo_status_bit = 1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image10MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.ax = 0;    // На увеличение скорости
dpo_status_bit = 0;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image9MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//Торможение (Дпо №17, №18)
dynamics.ax = 2 * 0.01849;
dpo_status_bit=1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image9MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.ax = 0;
dpo_status_bit=0;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image12MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// Правая стрелка РУД (Перемещение вправо ДПо №25 №26)
dynamics.az = -0.01897 * 2;
dpo_status_bit = 1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image12MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.az = 0;
dpo_status_bit = 0;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image5MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.Ey = -0.5923 * 0.5;
dpo_status_bit = 1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image5MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.Ey = 0;
dpo_status_bit = 0;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image8MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.Ez = -0.62063 * 0.5;
dpo_status_bit = 1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image8MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.Ez = 0;
dpo_status_bit = 0;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image4MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.Ex = 2 * -0.2898 * 2;
dpo_status_bit = 1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image4MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.Ex = 0;
dpo_status_bit = 0;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image7MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dpo_status_bit = 1;
dynamics.Ez = 0.62063 * 0.5;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image7MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dpo_status_bit = 0;
dynamics.Ez = 0;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image6MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dpo_status_bit = 1;
dynamics.Ey = 0.5923 * 0.5;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image6MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dpo_status_bit = 0;
dynamics.Ey = 0;
}
//---------------------------------------------------------------------------


