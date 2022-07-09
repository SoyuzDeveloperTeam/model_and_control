#ifndef _IRVI_FRM
#define _IRVI_FRM
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "JouHeader.h"  // For Jou Work
#include "JouStrings.h"
#include "USOData.h"
#include "main_header.h"
#include "argon/arg_header.h"  // Argon-16 Header
#include "irvi_brfi_frm.h"
#include "argon/arg_main.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TIrBrForm *IrBrForm;
static bool brvi_on;
static bool halfe;

AnsiString IrStrRT(){  //IrviStringRT
AnsiString RTt;
RTt.SubString(1,1) = IrBrForm->i1->Caption;
RTt.SubString(2,1) = IrBrForm->i2->Caption;
RTt.SubString(3,1) = IrBrForm->i3->Caption;
RTt.SubString(4,1) = IrBrForm->i4->Caption;
RTt.SubString(5,1) = IrBrForm->i5->Caption;
RTt.SubString(6,1) = IrBrForm->i6->Caption;
RTt.SubString(7,1) = IrBrForm->i7->Caption;
RTt.SubString(8,1) = IrBrForm->i8->Caption;
RTt.SubString(9,1) = IrBrForm->i9->Caption;
RTt.SubString(10,1) = IrBrForm->i10->Caption;
RTt.SubString(11,1) = IrBrForm->i11->Caption;
RTt.SubString(12,1) = IrBrForm->i12->Caption;
RTt.SubString(13,1) = IrBrForm->i13->Caption;
RTt.SubString(14,1) = IrBrForm->i14->Caption;
return RTt;
}

AnsiString DecToBin(int i){
  if(i==0) return "1111"; else
  if(i==1) return "0111"; else
  if(i==2) return "1011"; else
  if(i==3) return "0011"; else
  if(i==4) return "1101"; else
  if(i==5) return "0101"; else
  if(i==6) return "1001"; else
  if(i==7) return "0001"; else
  if(i==8) return "1110"; else
  if(i==9) return "0110";
}

void IrviUSOSt(){
if(brvi_on){
if(!irvi_a){        // If not sign А ("AA" Error)
  //USO_Booled[16]
AnsiString TempStr;
  if(IrBrForm->i1->Caption.IsEmpty()){
   USO_Booled[16][0] = 0;
   USO_Booled[16][1] = 0;
   USO_Booled[16][2] = 0;
   USO_Booled[16][3] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i1->Caption));
   USO_Booled[16][0] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[16][1] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[16][2] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[16][3] = StrToInt(TempStr.SubString(4,1));
  }

  if(IrBrForm->i2->Caption.IsEmpty()){
   USO_Booled[16][4] = 0;
   USO_Booled[16][5] = 0;
   USO_Booled[16][6] = 0;
   USO_Booled[16][7] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i2->Caption));
   USO_Booled[16][4] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[16][5] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[16][6] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[16][7] = StrToInt(TempStr.SubString(4,1));
  }

  if(IrBrForm->i3->Caption.IsEmpty()){
   USO_Booled[16][8] = 0;
   USO_Booled[16][9] = 0;
   USO_Booled[16][10] = 0;
   USO_Booled[16][11] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i3->Caption));
   USO_Booled[16][8] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[16][9] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[16][10] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[16][11] = StrToInt(TempStr.SubString(4,1));
  }

    if(IrBrForm->i4->Caption.IsEmpty()){
   USO_Booled[16][12] = 0;
   USO_Booled[16][13] = 0;
   USO_Booled[16][14] = 0;
   USO_Booled[16][15] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i4->Caption));
   USO_Booled[16][12] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[16][13] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[16][14] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[16][15] = StrToInt(TempStr.SubString(4,1));
  }

    if(IrBrForm->i5->Caption.IsEmpty()){
   USO_Booled[17][0] = 0;
   USO_Booled[17][1] = 0;
   USO_Booled[17][2] = 0;
   USO_Booled[17][3] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i5->Caption));
   USO_Booled[17][0] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[17][1] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[17][2] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[17][3] = StrToInt(TempStr.SubString(4,1));
  }

    if(IrBrForm->i6->Caption.IsEmpty()){
   USO_Booled[17][4] = 0;
   USO_Booled[17][5] = 0;
   USO_Booled[17][6] = 0;
   USO_Booled[17][7] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i6->Caption));
   USO_Booled[17][4] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[17][5] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[17][6] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[17][7] = StrToInt(TempStr.SubString(4,1));
  }

      if(IrBrForm->i7->Caption.IsEmpty()){
   USO_Booled[17][8] = 0;
   USO_Booled[17][9] = 0;
   USO_Booled[17][10] = 0;
   USO_Booled[17][11] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i7->Caption));
   USO_Booled[17][8] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[17][9] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[17][10] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[17][11] = StrToInt(TempStr.SubString(4,1));
  }

      if(IrBrForm->i8->Caption.IsEmpty()){
   USO_Booled[17][12] = 0;
   USO_Booled[17][13] = 0;
   USO_Booled[17][14] = 0;
   USO_Booled[17][15] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i8->Caption));
   USO_Booled[17][12] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[17][13] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[17][14] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[17][15] = StrToInt(TempStr.SubString(4,1));
  }

      if(IrBrForm->i9->Caption.IsEmpty()){
   USO_Booled[18][0] = 0;
   USO_Booled[18][1] = 0;
   USO_Booled[18][2] = 0;
   USO_Booled[18][3] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i9->Caption));
   USO_Booled[18][0] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[18][1] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[18][2] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[18][3] = StrToInt(TempStr.SubString(4,1));
  }

      if(IrBrForm->i10->Caption.IsEmpty()){
   USO_Booled[18][4] = 0;
   USO_Booled[18][5] = 0;
   USO_Booled[18][6] = 0;
   USO_Booled[18][7] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i10->Caption));
   USO_Booled[18][4] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[18][5] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[18][6] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[18][7] = StrToInt(TempStr.SubString(4,1));
  }

        if(IrBrForm->i11->Caption.IsEmpty()){
   USO_Booled[18][8] = 0;
   USO_Booled[18][9] = 0;
   USO_Booled[18][10] = 0;
   USO_Booled[18][11] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i11->Caption));
   USO_Booled[18][8] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[18][9] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[18][10] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[18][11] = StrToInt(TempStr.SubString(4,1));
  }

        if(IrBrForm->i12->Caption.IsEmpty()){
   USO_Booled[18][12] = 0;
   USO_Booled[18][13] = 0;
   USO_Booled[18][14] = 0;
   USO_Booled[18][15] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i12->Caption));
   USO_Booled[18][12] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[18][13] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[18][14] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[18][15] = StrToInt(TempStr.SubString(4,1));
  }

        if(IrBrForm->i13->Caption.IsEmpty()){
   USO_Booled[19][0] = 0;
   USO_Booled[19][1] = 0;
   USO_Booled[19][2] = 0;
   USO_Booled[19][3] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i13->Caption));
   USO_Booled[19][0] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[19][1] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[19][2] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[19][3] = StrToInt(TempStr.SubString(4,1)); }

           if(IrBrForm->i14->Caption.IsEmpty()){
   USO_Booled[19][4] = 0;
   USO_Booled[19][5] = 0;
   USO_Booled[19][6] = 0;
   USO_Booled[19][7] = 0;
  } else {
   TempStr = DecToBin(StrToInt(IrBrForm->i14->Caption));
   USO_Booled[19][4] = StrToInt(TempStr.SubString(1,1));
   USO_Booled[19][5] = StrToInt(TempStr.SubString(2,1));
   USO_Booled[19][6] = StrToInt(TempStr.SubString(3,1));
   USO_Booled[19][7] = StrToInt(TempStr.SubString(4,1));
  }

  if(IrBrForm->i15->Caption.IsEmpty()){
   USO_Booled[19][8] = 0;
   USO_Booled[19][8] = 0;
  } else if(IrBrForm->i15->Caption=="+"){
   USO_Booled[19][8] = 1;
   USO_Booled[19][8] = 0;
  }  else if(IrBrForm->i15->Caption=="-"){
   USO_Booled[19][8] = 0;
   USO_Booled[19][8] = 1;
  }
  } // A
 } //brvi_on
}

void irvi_clear(void)  // IRVI Clear Indicators Procedure
{
IrBrForm->i1->Caption="";
IrBrForm->i2->Caption="";
IrBrForm->i3->Caption="";
IrBrForm->i4->Caption="";
IrBrForm->i5->Caption="";
IrBrForm->i6->Caption="";
IrBrForm->i7->Caption="";
IrBrForm->i8->Caption="";
IrBrForm->i9->Caption="";
IrBrForm->i10->Caption="";
IrBrForm->i11->Caption="";
IrBrForm->i12->Caption="";
IrBrForm->i13->Caption="";
IrBrForm->i14->Caption="";
IrBrForm->i15->Caption="";
}

void brvi_send (AnsiString i1, AnsiString  i2, AnsiString i3, AnsiString i4,
AnsiString i5,AnsiString i6,AnsiString i7,AnsiString i8,AnsiString i9,AnsiString i10,
AnsiString i11,AnsiString i12,AnsiString i13,AnsiString i14,AnsiString i15) {

// Проверяем програма ли это Аргона
static int br_reg;
// Обработчик пустого ввода
if(i1.IsEmpty()&&i8.IsEmpty()){
IrBrForm->i1->Caption="A";
IrBrForm->i2->Caption="A";
IrBrForm->i3->Caption="A";
IrBrForm->i4->Caption="A";
IrBrForm->i5->Caption="A";
IrBrForm->i6->Caption="A";
IrBrForm->i7->Caption="A";
IrBrForm->i8->Caption="A";
IrBrForm->i9->Caption="A";
IrBrForm->i10->Caption="A";
IrBrForm->i11->Caption="A";
IrBrForm->i12->Caption="A";
IrBrForm->i13->Caption="A";
IrBrForm->i14->Caption="A";
IrBrForm->i15->Caption="";
irvi_a = 1; }

else if(i1=="A"){
int f;
irvi_a = 1;
 if (i3=="") f=1;//Ситуация АА, переводим каретку на И3

}
else {
br_reg = StrToInt(IrBrForm->i1->Caption+IrBrForm->i2->Caption);
int br_in3 = StrToInt(IrBrForm->i3->Caption);
switch(br_reg) // Определение и исполнение введенного режима (Первый фильтр по И1 и И2)
      {
        case 00: /* Приоритетный или принудительный режим выдачи пр-м 1 - 4 */ break;
              switch(br_in3) {
                     case 1: /* Вывод аварийных сообщений */ break;
                     case 2: /* Вывод инструкций */ break;
                     case 3: /* Сервис СКД */ break;
                     case 4: /* Вывод командной информации */
                        int cw_a; // Адрес Управляющего слова
                                if(i4=="0") cw_a=StrToInt(i5+i6+i7);
                           else if(i5=="0") cw_a=StrToInt(i6+i7);break;
                     default: {
                                 IrBrForm->i1->Caption="A";
                                 IrBrForm->i2->Caption="A";
                                 IrBrForm->i3->Caption="A";
                                 IrBrForm->i4->Caption="A";
                                 IrBrForm->i5->Caption="A";
                                 IrBrForm->i6->Caption="A";
                                 IrBrForm->i7->Caption="A";
                                 IrBrForm->i8->Caption="A";
                                 IrBrForm->i9->Caption="A";
                                 IrBrForm->i10->Caption="A";
                                 IrBrForm->i11->Caption="A";
                                 IrBrForm->i12->Caption="A";
                                 IrBrForm->i13->Caption="A";
                                 IrBrForm->i14->Caption="A";
                                 IrBrForm->i15->Caption=""; }
                         } // Switch i3
        case 04: /* Динамический вывод 10-х чисел */ break;
        case 05: /* Динамический вывод 8-х чисел */ break;
        case 10: /* Ввод уставки РУС */   halfe=true; break;
        case 11: /* Ввод уставки АУС 1-й группы */  break;
        case 12: /* Ввод уставки АУС 2-й группы */  break;
        case 14: /* Одиночный ввод 10-х чисел */  break;
        case 15: /* Одиночный ввод 8-х чисел */  break;
        case 17: /* Групповой ввод 10-х чисел */ break;
        case 18: /*  */ break;
        case 21: /* Вывод уставки АУС 1-й группы */ break;
        case 22: /* Вывод уставки АУС 2-й группы */ break;
        case 24: /* Одиночный вывод 10-х чисел */ break;
        case 25: /* Одиночный вывод 8-х чисел */ break;
        case 27: /* Групповой вывод 10-х чисел */ break;
        case 28: /* Групповой вывод 8-х чисел  */break;
        case 30: /* Изменение состояния признака в слове - запись единицы */ break;
        case 31: /* Изменение состояния признака в слове - запись нуля */ break;
        case 40: /*  */ break;
        case 41: /*  */ break;
        case 42: /*  */ break;
        case 43: /*  */ break;
        case 44: /*  */ break;
        case 45: /*  */ break;
        case 46: /*  */ break;
        case 48: /* Сверка времени */ break;
        default: {
IrBrForm->i1->Caption="A";
IrBrForm->i2->Caption="A";
IrBrForm->i3->Caption="A";
IrBrForm->i4->Caption="A";
IrBrForm->i5->Caption="A";
IrBrForm->i6->Caption="A";
IrBrForm->i7->Caption="A";
IrBrForm->i8->Caption="A";
IrBrForm->i9->Caption="A";
IrBrForm->i10->Caption="A";
IrBrForm->i11->Caption="A";
IrBrForm->i12->Caption="A";
IrBrForm->i13->Caption="A";
IrBrForm->i14->Caption="A";
IrBrForm->i15->Caption=""; }
      } // Switch bg_reg
    } // !i1=="A"

} //brvi_send

//---------------------------------------------------------------------------
__fastcall TIrBrForm::TIrBrForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TIrBrForm::SpeedButton9Click(TObject *Sender)
{
if(brvi_on)
{
i15->Caption="+";
}
}
//---------------------------------------------------------------------------
void __fastcall TIrBrForm::SpeedButton12Click(TObject *Sender)
{
if(brvi_on)
{
i15->Caption="-";
}
}
//---------------------------------------------------------------------------
void __fastcall TIrBrForm::SpeedButton17Click(TObject *Sender)
{
brvi_on=false;
i1->Caption="";
i2->Caption="";
i3->Caption="";
i4->Caption="";
i5->Caption="";
i6->Caption="";
i7->Caption="";
i8->Caption="";
i9->Caption="";
i10->Caption="";
i11->Caption="";
i12->Caption="";
i13->Caption="";
i14->Caption="";
i15->Caption="";
Panel1->Color=clGreen;
}
//---------------------------------------------------------------------------
void __fastcall TIrBrForm::SpeedButton14Click(TObject *Sender)
{
brvi_on=true;
Panel1->Color=clLime;
}
//---------------------------------------------------------------------------
void __fastcall TIrBrForm::SpeedButton16Click(TObject *Sender)
{
irvi_a = 0;
i1->Caption="";
i2->Caption="";
i3->Caption="";
i4->Caption="";
i5->Caption="";
i6->Caption="";
i7->Caption="";
i8->Caption="";
i9->Caption="";
i10->Caption="";
i11->Caption="";
i12->Caption="";
i13->Caption="";
i14->Caption="";
i15->Caption="";
}
//---------------------------------------------------------------------------
void __fastcall TIrBrForm::isp_btnClick(TObject *Sender)
{
if(brvi_on) { // If BRVI is ON
if(i1->Caption==""&&i2->Caption==""){  // If first and second empty,
i1->Caption=="A";     // Then error-message "AA"
i2->Caption=="A";
JPS(3,is_irvi,is_operator,"АА","");  // and log to jou
} else {              // или (если 1И и 2И не пустые)
AnsiString brvi_msg = i1->Caption+i2->Caption+i3->Caption+i4->Caption+    // Создаем строку текущего состояния И ИРВИ
i5->Caption+i6->Caption+i7->Caption+i8->Caption+i9->Caption+i10->Caption+
i11->Caption+i12->Caption+i13->Caption+i14->Caption+i15->Caption;

JPS(1,is_operator,is_irvi,brvi_msg,"");

Timer1->Enabled=true;  // Включаем таймер задержки индикации

irvi_clear();

irvi_string = brvi_msg; // Присваиваем глобальной переменной значение ИРВИ

ChekIrvi(irvi_string); }}else  // Если БРВИ выключен
JPS(3,is_miu,is_operator,cmd_brvi_error,"");   // Ошибка в Журнал
}
//---------------------------------------------------------------------------
void __fastcall TIrBrForm::SpeedButton1Click(TObject *Sender)
{
if(brvi_on){
USO_BitType[16][3] = 0111;
if(i1->Caption=="")
        i1->Caption="1";
else if(i2->Caption=="")
        i2->Caption="1";
else if(i3->Caption=="")
        i3->Caption="1";
else if(i4->Caption=="")
        i4->Caption="1";
else if(i5->Caption=="")
        i5->Caption="1";
else if(i6->Caption=="")
        i6->Caption="1";
else if(i7->Caption=="")
        i7->Caption="1";
else if(i8->Caption=="")
        i8->Caption="1";
else if(i9->Caption=="")
        i9->Caption="1";
else if(i10->Caption=="")
        i10->Caption="1";
else if(i11->Caption=="")
        i11->Caption="1";
else if(i12->Caption=="")
        i12->Caption="1";
else if(i13->Caption=="")
        i13->Caption="1";
else if(i14->Caption=="")
        i14->Caption="1";
else {}
}
}
//---------------------------------------------------------------------------
void __fastcall TIrBrForm::SpeedButton2Click(TObject *Sender)
{
if(brvi_on){
USO_BitType[16][4] = 1011;
if(i1->Caption=="")
        i1->Caption="2";
else if(i2->Caption=="")
        i2->Caption="2";
else if(i3->Caption=="")
        i3->Caption="2";
else if(i4->Caption=="")
        i4->Caption="2";
else if(i5->Caption=="")
        i5->Caption="2";
else if(i6->Caption=="")
        i6->Caption="2";
else if(i7->Caption=="")
        i7->Caption="2";
else if(i8->Caption=="")
        i8->Caption="2";
else if(i9->Caption=="")
        i9->Caption="2";
else if(i10->Caption=="")
        i10->Caption="2";
else if(i11->Caption=="")
        i11->Caption="2";
else if(i12->Caption=="")
        i12->Caption="2";
else if(i13->Caption=="")
        i13->Caption="2";
else if(i14->Caption=="")
        i14->Caption="2";
else {}
 //fsds
}
}
//---------------------------------------------------------------------------

void __fastcall TIrBrForm::SpeedButton3Click(TObject *Sender)
{
if(brvi_on){
if(i1->Caption=="")
        i1->Caption="3";
else if(i2->Caption=="")
        i2->Caption="3";
else if(i3->Caption=="")
        i3->Caption="3";
else if(i4->Caption=="")
        i4->Caption="3";
else if(i5->Caption=="")
        i5->Caption="3";
else if(i6->Caption=="")
        i6->Caption="3";
else if(i7->Caption=="")
        i7->Caption="3";
else if(i8->Caption=="")
        i8->Caption="3";
else if(i9->Caption=="")
        i9->Caption="3";
else if(i10->Caption=="")
        i10->Caption="3";
else if(i11->Caption=="")
        i11->Caption="3";
else if(i12->Caption=="")
        i12->Caption="3";
else if(i13->Caption=="")
        i13->Caption="3";
else if(i14->Caption=="")
        i14->Caption="3";
else {}
}
}
//---------------------------------------------------------------------------

void __fastcall TIrBrForm::SpeedButton5Click(TObject *Sender)
{
if(brvi_on){

if(i1->Caption=="")
        i1->Caption="4";
else if(i2->Caption=="")
        i2->Caption="4";
else if(i3->Caption=="")
        i3->Caption="4";
else if(i4->Caption=="")
        i4->Caption="4";
else if(i5->Caption=="")
        i5->Caption="4";
else if(i6->Caption=="")
        i6->Caption="4";
else if(i7->Caption=="")
        i7->Caption="4";
else if(i8->Caption=="")
        i8->Caption="4";
else if(i9->Caption=="")
        i9->Caption="4";
else if(i10->Caption=="")
        i10->Caption="4";
else if(i11->Caption=="")
        i11->Caption="4";
else if(i12->Caption=="")
        i12->Caption="4";
else if(i13->Caption=="")
        i13->Caption="4";
else if(i14->Caption=="")
        i14->Caption="4";
else {}
}
}
//---------------------------------------------------------------------------

void __fastcall TIrBrForm::SpeedButton6Click(TObject *Sender)
{
if(brvi_on){

if(i1->Caption=="")
        i1->Caption="5";
else if(i2->Caption=="")
        i2->Caption="5";
else if(i3->Caption=="")
        i3->Caption="5";
else if(i4->Caption=="")
        i4->Caption="5";
else if(i5->Caption=="")
        i5->Caption="5";
else if(i6->Caption=="")
        i6->Caption="5";
else if(i7->Caption=="")
        i7->Caption="5";
else if(i8->Caption=="")
        i8->Caption="5";
else if(i9->Caption=="")
        i9->Caption="5";
else if(i10->Caption=="")
        i10->Caption="5";
else if(i11->Caption=="")
        i11->Caption="5";
else if(i12->Caption=="")
        i12->Caption="5";
else if(i13->Caption=="")
        i13->Caption="5";
else if(i14->Caption=="")
        i14->Caption="5";
else {}
}
}
//---------------------------------------------------------------------------

void __fastcall TIrBrForm::SpeedButton10Click(TObject *Sender)
{
if(brvi_on){

if(i1->Caption=="")
        i1->Caption="6";
else if(i2->Caption=="")
        i2->Caption="6";
else if(i3->Caption=="")
        i3->Caption="6";
else if(i4->Caption=="")
        i4->Caption="6";
else if(i5->Caption=="")
        i5->Caption="6";
else if(i6->Caption=="")
        i6->Caption="6";
else if(i7->Caption=="")
        i7->Caption="6";
else if(i8->Caption=="")
        i8->Caption="6";
else if(i9->Caption=="")
        i9->Caption="6";
else if(i10->Caption=="")
        i10->Caption="6";
else if(i11->Caption=="")
        i11->Caption="6";
else if(i12->Caption=="")
        i12->Caption="6";
else if(i13->Caption=="")
        i13->Caption="6";
else if(i14->Caption=="")
        i14->Caption="6";
else {}
}
}
//---------------------------------------------------------------------------

void __fastcall TIrBrForm::SpeedButton11Click(TObject *Sender)
{
if(brvi_on){

if(i1->Caption=="")
        i1->Caption="7";
else if(i2->Caption=="")
        i2->Caption="7";
else if(i3->Caption=="")
        i3->Caption="7";
else if(i4->Caption=="")
        i4->Caption="7";
else if(i5->Caption=="")
        i5->Caption="7";
else if(i6->Caption=="")
        i6->Caption="7";
else if(i7->Caption=="")
        i7->Caption="7";
else if(i8->Caption=="")
        i8->Caption="7";
else if(i9->Caption=="")
        i9->Caption="7";
else if(i10->Caption=="")
        i10->Caption="7";
else if(i11->Caption=="")
        i11->Caption="7";
else if(i12->Caption=="")
        i12->Caption="7";
else if(i13->Caption=="")
        i13->Caption="7";
else if(i14->Caption=="")
        i14->Caption="7";
else {}
}
}
//---------------------------------------------------------------------------

void __fastcall TIrBrForm::SpeedButton4Click(TObject *Sender)
{
if(brvi_on){

if(i1->Caption=="")
        i1->Caption="8";
else if(i2->Caption=="")
        i2->Caption="8";
else if(i3->Caption=="")
        i3->Caption="8";
else if(i4->Caption=="")
        i4->Caption="8";
else if(i5->Caption=="")
        i5->Caption="8";
else if(i6->Caption=="")
        i6->Caption="8";
else if(i7->Caption=="")
        i7->Caption="8";
else if(i8->Caption=="")
        i8->Caption="8";
else if(i9->Caption=="")
        i9->Caption="8";
else if(i10->Caption=="")
        i10->Caption="8";
else if(i11->Caption=="")
        i11->Caption="8";
else if(i12->Caption=="")
        i12->Caption="8";
else if(i13->Caption=="")
        i13->Caption="8";
else if(i14->Caption=="")
        i14->Caption="8";
else {}
}
}
//---------------------------------------------------------------------------

void __fastcall TIrBrForm::SpeedButton7Click(TObject *Sender)
{
if(brvi_on){

if(i1->Caption=="")
        i1->Caption="9";
else if(i2->Caption=="")
        i2->Caption="9";
else if(i3->Caption=="")
        i3->Caption="9";
else if(i4->Caption=="")
        i4->Caption="9";
else if(i5->Caption=="")
        i5->Caption="9";
else if(i6->Caption=="")
        i6->Caption="9";
else if(i7->Caption=="")
        i7->Caption="9";
else if(i8->Caption=="")
        i8->Caption="9";
else if(i9->Caption=="")
        i9->Caption="9";
else if(i10->Caption=="")
        i10->Caption="9";
else if(i11->Caption=="")
        i11->Caption="9";
else if(i12->Caption=="")
        i12->Caption="9";
else if(i13->Caption=="")
        i13->Caption="9";
else if(i14->Caption=="")
        i14->Caption="9";
else {}
}
}
//---------------------------------------------------------------------------

void __fastcall TIrBrForm::SpeedButton8Click(TObject *Sender)
{
if(brvi_on){
USO_BitType[16][4] = 1111;
if(i1->Caption=="")
        i1->Caption="0";
else if(i2->Caption=="")
        i2->Caption="0";
else if(i3->Caption=="")
        i3->Caption="0";
else if(i4->Caption=="")
        i4->Caption="0";
else if(i5->Caption=="")
        i5->Caption="0";
else if(i6->Caption=="")
        i6->Caption="0";
else if(i7->Caption=="")
        i7->Caption="0";
else if(i8->Caption=="")
        i8->Caption="0";
else if(i9->Caption=="")
        i9->Caption="0";
else if(i10->Caption=="")
        i10->Caption="0";
else if(i11->Caption=="")
        i11->Caption="0";
else if(i12->Caption=="")
        i12->Caption="0";
else if(i13->Caption=="")
        i13->Caption="0";
else if(i14->Caption=="")
        i14->Caption="0";
else {}
}

}
//---------------------------------------------------------------------------

void __fastcall TIrBrForm::SpeedButton15Click(TObject *Sender)
{
if(brvi_on){
if(i14->Caption.Length()==1)
        i14->Caption="";
else if(i13->Caption.Length()==1)
        i13->Caption="";
else if(i12->Caption.Length()==1)
        i12->Caption="";
else if(i11->Caption.Length()==1)
        i11->Caption="";
else if(i10->Caption.Length()==1)
        i10->Caption="";
else if(i9->Caption.Length()==1)
        i9->Caption="";
else if(i8->Caption.Length()==1)
        i8->Caption="";
else if(i7->Caption.Length()==1)
        i7->Caption="";
else if(i6->Caption.Length()==1)
        i6->Caption="";
else if(i5->Caption.Length()==1)
        i5->Caption="";
else if(i4->Caption.Length()==1)
        i4->Caption="";
else if(i3->Caption.Length()==1)
        i3->Caption="";
else if(i2->Caption.Length()==1)
        i2->Caption="";
else if(i1->Caption.Length()==1)
        i1->Caption="";
}
}
//---------------------------------------------------------------------------



void __fastcall TIrBrForm::irvi_send_tTimer(TObject *Sender)
{
Timer1->Enabled=false;
if(!irvi_err){
i1->Caption=irvi_string.SubString(1,1);
i2->Caption=irvi_string.SubString(2,1);
i3->Caption=irvi_string.SubString(3,1);
i4->Caption=irvi_string.SubString(4,1);
i5->Caption=irvi_string.SubString(5,1);
i6->Caption=irvi_string.SubString(6,1);
i7->Caption=irvi_string.SubString(7,1);
i8->Caption=irvi_string.SubString(8,1);
i9->Caption=irvi_string.SubString(9,1);
i10->Caption=irvi_string.SubString(10,1);
i11->Caption=irvi_string.SubString(11,1);
i12->Caption=irvi_string.SubString(12,1);
i13->Caption=irvi_string.SubString(13,1);
i14->Caption=irvi_string.SubString(14,1);
i15->Caption=irvi_string.SubString(15,1);} else {
i1->Caption="A";
i2->Caption="A";
i3->Caption="";
i4->Caption="";
i5->Caption="";
i6->Caption="";
i7->Caption="";
i8->Caption="";
i9->Caption="";
i10->Caption="";
i11->Caption="";
i12->Caption="";
i13->Caption="";
i14->Caption="";
i15->Caption="";
}
irvi_send_t->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TIrBrForm::Timer1Timer(TObject *Sender)
{

irvi_send_t->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TIrBrForm::USOtTimer(TObject *Sender)
{
//IrviUSOSt();
IrviStringRT = IrStrRT();
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#endif // IRVI
