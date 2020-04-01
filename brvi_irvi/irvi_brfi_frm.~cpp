#ifndef _IRVI_FRM
#define _IRVI_FRM
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "JouHeader.h"
#include "JouStrings.h"
#include "USOData.h"
#include "main_header.h"
#include "argon/arg_header.h"  // Загогловок А16
#include "irvi_brfi_frm.h"
#include "argon/arg_main.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TIrBrForm *IrBrForm;
bool brvi_on;
bool halfe;

void irvi_clear(void)
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
int br_reg;
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
IrBrForm->i15->Caption=""; }

else if(i1=="A"){
int f;
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
void __fastcall TIrBrForm::SpeedButton18Click(TObject *Sender)
{
if(brvi_on) { // Если БРВИ вкл
if(i1->Caption==""&&i2->Caption==""){  // Если первый и второй индикаторы пустые,
i1->Caption=="A";     // Тогда сообщение АА
i2->Caption=="A";
JPS(3,is_irvi,is_operator,"АА","");  // и лог в журнал
} else {              // или (если 1И и 2И не пустые)
AnsiString brvi_msg = i1->Caption+i2->Caption+i3->Caption+i4->Caption+    // Создаем строку текущего состояния И ИРВИ
i5->Caption+i6->Caption+i7->Caption+i8->Caption+i9->Caption+i10->Caption+
i11->Caption+i12->Caption+i13->Caption+i14->Caption+i15->Caption;

//   // Логируем (перенести в обработчик аргона)

//if(i1->Caption=="A") JPS(3,is_irvi,is_operator,brvi_msg,""); else
//                     JPS(1,is_irvi,is_operator,brvi_msg,"");

//} else

JPS(1,is_operator,is_irvi,brvi_msg,"");

Timer1->Enabled=true;  // Включаем таймер задержки индикации

// Обнуляем индикаторы перед индикацией
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

irvi_string = brvi_msg; // Присваиваем глобальной переменной значение ИРВИ

ChekIrvi(irvi_string); }}else  // Если БРВИ выключен
JPS(3,is_miu,is_operator,cmd_brvi_error,"");   // Ошибка в Журнал


////////////////////// И 1
/* if(i1->Caption=="0"){
  // IIII
  S_10[0] = "1111";
  Bin_USO_10[0] = "F";
} else
if(i1->Caption=="1"){
  // .III
  S_10[0] = "0111";
  Bin_USO_10[0] = "7";
} else
if(i1->Caption=="2"){
  // I.II
  S_10[0] = "1011";
  Bin_USO_10[0] = "B";
} else
if(i1->Caption=="3"){
  // ..II
  S_10[0] = "0011";
  Bin_USO_10[0] = "3";
} else
if(i1->Caption=="4"){
  // II.I
  S_10[0] = "1101";
  Bin_USO_10[0] = "D";
} else
if(i1->Caption=="5"){
  // .I.I
  S_10[0] = "0101";
  Bin_USO_10[0] = "5";
} else
if(i1->Caption=="6"){
  // I..I
  S_10[0] = "1001";
  Bin_USO_10[0] = "9";
} else
if(i1->Caption=="7"){
  // ...I
  S_10[0] = "0001";
  Bin_USO_10[0] = "1";
} else
if(i1->Caption=="8"){
  // III.
  S_10[0] = "1110";
  Bin_USO_10[0] = "E";
} else
if(i1->Caption=="9"){
  // .II.
  S_10[0] = "0110";
  Bin_USO_10[0] = "6";
} else
if(i1->Caption=="A"){
  // I.I.
  S_10[0] = "1010";
  Bin_USO_10[0] = "A";
}
////////////////////// И 2
if(i2->Caption=="0"){
  // IIII
  S_10[1] = "1111";
} else
if(i2->Caption=="1"){
  // .III
  S_10[1] = "0111";
} else
if(i2->Caption=="2"){
  // I.II
  S_10[1] = "1011";
} else
if(i2->Caption=="3"){
  // ..II
  S_10[1] = "0011";
} else
if(i2->Caption=="4"){
  // II.I
  S_10[1] = "1101";
} else
if(i2->Caption=="5"){
  // .I.I
  S_10[1] = "0101";
} else
if(i2->Caption=="6"){
  // I..I
  S_10[1] = "1001";
} else
if(i2->Caption=="7"){
  // ...I
  S_10[1] = "0001";
} else
if(i2->Caption=="8"){
  // III.
  S_10[1] = "1110";
} else
if(i2->Caption=="9"){
  // .II.
  S_10[1] = "0110";
} else
if(i2->Caption=="A"){
  // I.I.
  S_10[1] = "1010";
}

////////////////////// И 3
if(i3->Caption=="0"){
  // IIII
  S_10[2] = "1111";
} else
if(i3->Caption=="1"){
  // .III
  S_10[2] = "0111";
} else
if(i3->Caption=="2"){
  // I.II
  S_10[2] = "1011";
} else
if(i3->Caption=="3"){
  // ..II
  S_10[2] = "0011";
} else
if(i3->Caption=="4"){
  // II.I
  S_10[2] = "1101";
} else
if(i3->Caption=="5"){
  // .I.I
  S_10[2] = "0101";
} else
if(i3->Caption=="6"){
  // I..I
  S_10[2] = "1001";
} else
if(i3->Caption=="7"){
  // ...I
  S_10[2] = "0001";
} else
if(i3->Caption=="8"){
  // III.
  S_10[2] = "1110";
} else
if(i3->Caption=="9"){
  // .II.
  S_10[2] = "0110";
} else
if(i3->Caption=="A"){
  // I.I.
  S_10[2] = "1010";
}
////////////////////// И 4
if(i4->Caption=="0"){
  // IIII
  S_10[3] = "1111";
} else
if(i4->Caption=="1"){
  // .III
  S_10[3] = "0111";
} else
if(i4->Caption=="2"){
  // I.II
  S_10[3] = "1011";
} else
if(i4->Caption=="3"){
  // ..II
  S_10[3] = "0011";
} else
if(i4->Caption=="4"){
  // II.I
  S_10[3] = "1101";
} else
if(i4->Caption=="5"){
  // .I.I
  S_10[3] = "0101";
} else
if(i4->Caption=="6"){
  // I..I
  S_10[3] = "1001";
} else
if(i4->Caption=="7"){
  // ...I
  S_10[3] = "0001";
} else
if(i4->Caption=="8"){
  // III.
  S_10[3] = "1110";
} else
if(i4->Caption=="9"){
  // .II.
  S_10[3] = "0110";
} else
if(i4->Caption=="A"){
  // I.I.
  S_10[3] = "1010";
} */
// - 01
// + 10



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


//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
#endif // IRVI
