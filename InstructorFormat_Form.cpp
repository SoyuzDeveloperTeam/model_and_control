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
Label66->Caption=FormatFloat("000.00",dynamics.rudkg);
Label38->Caption=FormatFloat("000.00",dynamics.ypr);   // Sy
Label41->Caption=FormatFloat("000.00",dynamics.zpr);   // Sz
Label44->Caption=FormatFloat("000.00",dynamics.Spr);   // S
 Label1->Caption=FormatFloat("000.00",dynamics.rs);    // Дальность от ЦГМ СТМ до ЦСУ СМ РС МКС
 Label3->Caption=FormatFloat("000.00",dynamics.sks);   // их взаимная скорость
Label30->Caption=FormatFloat("00.000",dynamics.V);     // вектор скорости (относительно...?)
Label29->Caption=FormatFloat("00.000",dynamics.vby);
Label28->Caption=FormatFloat("00.000",dynamics.vbz);
theta_tk->Caption=FormatFloat("00.000",dynamics.uomz);
psi_tk->Caption=FormatFloat("00.000",dynamics.uomy);
gamma_tk->Caption=FormatFloat("00.000", dynamics.uomx);
t_pr->Caption=IntToStr(t_prolet[1]);   // Не работает - превратить в время!
}
//---------------------------------------------------------------------------
void __fastcall TInstructorFormat_FRM::Image4Click(TObject *Sender)
{
// РУО Крен правый
// В работе ДПО 23 и 24
dpo_status_bit = 1;         // Признак работы ДПО
dynamics.ay = 2 * 0.01915;  // Ускорение вызываемое работой ДПО (пересчитать для ТМА)
dpo_v_pr[23]=1;  dpo_v_pr[24]=1;  // Признак работы выбранных дпо - перенести в функцию dpo_stbit(dpo_status[28]);
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::rud_upMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//РУД - вверх
//ДПО 23 и 24
dynamics.ay = 2 * 0.01915;
dpo_status_bit = 1;
dpo_v_pr[23]=1;  dpo_v_pr[24]=1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::rud_upMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// РУД Нейтраль
dpo_status_bit = 0;
dynamics.ay = 0;
dpo_v_pr[23]=0;  dpo_v_pr[24]=0;
}
//---------------------------------------------------------------------------



void __fastcall TInstructorFormat_FRM::rud_leftMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//РУД - влево
//В работе ДПО 21 и 22
dpo_status_bit = 1;
dynamics.az = 2 * 0.01897;
dpo_v_pr[21]=1;  dpo_v_pr[22]=1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::rud_leftMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{//РУД - Нейтраль
dpo_status_bit = 0;
dynamics.az = 0;
dpo_v_pr[21]=0;  dpo_v_pr[22]=0;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image10MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{ // Тумблер - Разгон
  // Работа ДПО 14 и 16)
  dpo_status_bit = 1;
dynamics.ax = -0.018 * 2;    // На увеличение скорости
dpo_v_pr[14]=1;  dpo_v_pr[16]=1;  // Признак работы для каждого ДПО
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image10MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{ // Тумблер отпущен
dynamics.ax = 0;
dpo_status_bit = 0;
dpo_v_pr[14]=0;  dpo_v_pr[16]=0;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::tormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{ // Тумблер - Торможение
  // Работа ДПО 17 и 18
dpo_status_bit=1;
dynamics.ax = 2 * 0.01849;
dpo_v_pr[17]=1;  dpo_v_pr[18]=1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::tormMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.ax = 0;
dpo_status_bit=0;
dpo_v_pr[17]=0;  dpo_v_pr[18]=0;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::rud_rightMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//РУД - вправо
//ДПО 25 и 26
dynamics.az = -0.01897 * 2;
dpo_status_bit = 1;
dpo_v_pr[25]=1;  dpo_v_pr[26]=1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::rud_rightMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
dynamics.az = 0;
dpo_status_bit = 0;
dpo_v_pr[25]=0;  dpo_v_pr[26]=0;
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
// Тангаж вверх
// ДПО 
dynamics.Ez = -0.62063 * 0.5;
dpo_status_bit = 1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::Image8MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// РУО Нейтраль
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

void __fastcall TInstructorFormat_FRM::rud_downMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// Руд вниз
// В работе ДПО 19 20
dpo_status_bit = 1;
dynamics.ay = -0.01915 * 2;
dpo_v_pr[19]=1;  dpo_v_pr[20]=1;
}
//---------------------------------------------------------------------------

void __fastcall TInstructorFormat_FRM::rud_downMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
// Руд нейтраль
dpo_status_bit = 0;
dynamics.ay = 0;
dpo_v_pr[19]=0;  dpo_v_pr[20]=0;
}
//---------------------------------------------------------------------------



