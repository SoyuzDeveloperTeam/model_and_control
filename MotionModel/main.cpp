//---------------------------------------------------------------------------

#include <vcl.h>
//#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include <math.h>
#include "DateUtils.hpp"
#include "MD_math_header.h"
#include "math_a.cpp"
TForm1 *Form1;
TDateTime ModelDTime, zeroDT;
double JDate;
void Jou(AnsiString Message){
  Form1->ListBox1->Items->Add(Now().FormatString("[hh:nn:ss.zzz]")+"  "+
  ModelDTime.FormatString("[hh:nn:ss.zzz]")+"  "+Message);
  Form1->ListBox1->Perform(WM_VSCROLL,SB_LINEDOWN,0);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
Jou("Запуск ПО");
dtt->Time=zeroDT;
}
//---------------------------------------------------------------------------



static double vector_r[3]; // Вектор положения
static double vector_v[3]; // Вектор скорости
static double sper_coor[3];// Сферические координаты a b r
static double ed_v_sun[3]; // Единичный вектор на солнце

struct{
static double Fa;          // Ускорение, обусловленное торможением в атмосфере
}uskor;                    // Ускорения

void m_Fa () {
// uskor.Fa =
}

double attitude (TVect3 v_pol){
double out;
out = abs(((sqrt(v_pol[0]*v_pol[0]+v_pol[1]*v_pol[1]+v_pol[2]*v_pol[2]))/1000)-6371);
return out;
}
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
double JulDate;
Jou("Старт отработки входных данных...");
NDateTime NUDT;
TVect3 v_pol, v_vel; // Объявляем вектора положения/скорости
PosVType vecvel;     //
double kd[6];
NUDT.NYear  = StrToInt(dtd->Date.FormatString("yyyy"));
NUDT.NMonth = StrToInt(dtd->Date.FormatString("mm"));
NUDT.NDay   = StrToInt(dtd->Date.FormatString("dd"));
NUDT.NHour  = StrToInt(dtt->Time.FormatString("hh"));
NUDT.NMin   = StrToInt(dtt->Time.FormatString("nn"));
NUDT.NSec   = StrToInt(dtt->Time.FormatString("ss"));
dtd->Time   = dtt->Time;
ModelDTime  = dtd->DateTime;
Jou("Выставленно модельное время. Дата "+ModelDTime.FormatString("dd.mm.yyyy"));
//TransDatetoJD(23, 07, 2005, JDate);
JulDate = DateTimeToJulianDate(ModelDTime);
Jou("Результат перевода в Юлианскую Дату - "+FloatToStr(JulDate));
kd[0] = StrToFloat(Edit1->Text);
kd[1] = StrToFloat(Edit2->Text);
kd[2] = StrToFloat(Edit3->Text);
kd[3] = StrToFloat(Edit4->Text);
kd[4] = StrToFloat(Edit5->Text);
kd[5] = StrToFloat(Edit6->Text);
Jou("Расчет вектора состояния по НУ");
KeplXV(kd[0],kd[1],kd[2],kd[3],kd[4],kd[5],vecvel);
v_pol[0] = vecvel[0];
v_pol[1] = vecvel[1];
v_pol[2] = vecvel[2];
v_vel[0] = vecvel[3];
v_vel[1] = vecvel[4];
v_vel[2] = vecvel[5];
Label4->Caption=FormatFloat("0.0",v_pol[0]);
Label5->Caption=FormatFloat("0.0",v_pol[1]);
Label6->Caption=FormatFloat("0.0",v_pol[2]);
Label10->Caption=FormatFloat("0.0",v_vel[0]);
Label11->Caption=FormatFloat("0.0",v_vel[1]);
Label12->Caption=FormatFloat("0.0",v_vel[2]);
Label16->Caption=FormatFloat("000.0000",attitude(v_vel));
Jou("Нормировка ВС");
// Нормируем
Jou("Вычисляем единичный векор на Солнце в J2000.0");
double vosh, skl;
vosh = StrToFloat(Edit7->Text)*GraRad;
skl  = StrToFloat(Edit8->Text)*GraRad;
//sun(JulDate,ed_v_sun,*vosh,*skl);
}
int i;
//---------------------------------------------------------------------------
void __fastcall TForm1::md_cTimer(TObject *Sender)
{

////////////////////
//  SOYUZ - TMA   //
// MOTION   MODEL //
////////////////////
// 1.1. Calc current date/time
time->Caption=ModelDTime.FormatString("hh:nn:ss.zzz"); // Выводим на форму
double dt = DateTimeToJulianDate(ModelDTime);          // Союздаем юлианскую дату/время
Label32->Caption=FormatFloat("000000.00000",dt);       // Выводим на форму
}
//---------------------------------------------------------------------------

void __fastcall TForm1::start_integerClick(TObject *Sender)
{
md_c->Enabled=true;
time_f->Enabled=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::time_fTimer(TObject *Sender)
{
ModelDTime = ModelDTime + StrToTime("00:00:01");       // Прибавляем к начальному модельному времени шаг интегрирования
}
//---------------------------------------------------------------------------

