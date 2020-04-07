//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KSPPForm.h"
#include "USOData.h"
#include "main_header.h"
#include "JouHeader.h"         // Заголовок для журнала
#include "JouStrings.h"        // Строковые переменные для журнала
#include "bumconnect.cpp"      // Обмен с БУМ
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKSP_right *KSP_right;
//---------------------------------------------------------------------------
__fastcall TKSP_right::TKSP_right(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TKSP_right::KSP_R_B_imageClick(TObject *Sender)
{
KSP_Let[0]=false;
KSP_Let[1]=false;
KSP_Let[2]=false;
KSP_Let[3]=false;
KSP_Let[4]=false;
KSP_Let[5]=false;
KSP_Let[6]=false;
KSP_Let[7]=false;
KSP_Let[8]=true;
byte i;
for(i=9; i<=16; i++){
 KSP_Let[i]=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TKSP_right::KSP_R_N_imageClick(TObject *Sender)
{
KSP_Let[0]=false;
KSP_Let[1]=false;
KSP_Let[2]=false;
KSP_Let[3]=false;
KSP_Let[4]=false;
KSP_Let[5]=false;
KSP_Let[6]=false;
KSP_Let[7]=false;
KSP_Let[8]=false;
KSP_Let[9]=true;
byte i;
for(i=10; i<=16; i++){
 KSP_Let[i]=false;
}
}
//---------------------------------------------------------------------------



void __fastcall TKSP_right::KSP_R_T_imageClick(TObject *Sender)
{
byte i;
for(i=0; i<=12; i++){
 KSP_Let[i]=false;
}
KSP_Let[13]=true;
for(i=14; i<=16; i++){
 KSP_Let[i]=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TKSP_right::KSP_R_P_imageClick(TObject *Sender)
{
KSP_Let[0]=false;
KSP_Let[1]=false;
KSP_Let[2]=false;
KSP_Let[3]=false;
KSP_Let[4]=false;
KSP_Let[5]=false;
KSP_Let[6]=false;
KSP_Let[7]=false;
KSP_Let[8]=false;
KSP_Let[9]=false;
KSP_Let[10]=true;
byte i;
for(i=11; i<=16; i++){
 KSP_Let[i]=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TKSP_right::KSP_R_R_imageClick(TObject *Sender)
{
KSP_Let[0]=false;
KSP_Let[1]=false;
KSP_Let[2]=false;
KSP_Let[3]=false;
KSP_Let[4]=false;
KSP_Let[5]=false;
KSP_Let[6]=false;
KSP_Let[7]=false;
KSP_Let[8]=false;
KSP_Let[9]=false;
KSP_Let[10]=false;
KSP_Let[11]=true;
byte i;
for(i=12; i<=16; i++){
 KSP_Let[i]=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TKSP_right::KSP_R_S_imageClick(TObject *Sender)
{
byte i;
for(i=0; i<=11; i++){
 KSP_Let[i]=false;
}
KSP_Let[12]=true;
for(i=13; i<=16; i++){
 KSP_Let[i]=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TKSP_right::KSP_R_U_imageClick(TObject *Sender)
{
byte i;
for(i=0; i<=13; i++){
 KSP_Let[i]=false;
}
KSP_Let[14]=true;
for(i=15; i<=16; i++){
 KSP_Let[i]=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TKSP_right::KSP_R_F_imageClick(TObject *Sender)
{
byte i;
for(i=0; i<=14; i++){
 KSP_Let[i]=false;
}
KSP_Let[15]=true;
KSP_Let[16]=false;
}
//---------------------------------------------------------------------------

void __fastcall TKSP_right::ksp_1Click(TObject *Sender)
{
if (KSP_Let[8]){ // Б                           // Если выбранна буква А
KSP_Booled[1][0]=true;                          // Тогда выставляем признак А1 - правда
JPS(1,is_operator,is_miu,is_ksp,"А1"); } else   // Логируем выдачу команды

if (KSP_Let[9]){ // Н                              Если выбранна буква В
KSP_Booled[9][0]=true;                          // Тогда выставляем признак В1 - правда
JPS(1,is_operator,is_miu,is_ksp,"В1"); } else   // Логируем выдачу команды

if (KSP_Let[10]){  // П                             Если выбранна буква Г
KSP_Booled[10][0]=true;                          // Тогда выставляем признак Г1 - правда
JPS(1,is_operator,is_miu,is_ksp,"Г1"); } else   // Логируем выдачу команды

if (KSP_Let[11]){  // Р                             Если выбранна буква Д
KSP_Booled[11][0]=true;                          // Тогда выставляем признак Д1 - правда
JPS(1,is_operator,is_miu,is_ksp,"Д1"); } else   // Логируем выдачу команды

if (KSP_Let[12]){  // С
KSP_Booled[12][0]=true;
JPS(1,is_operator,is_miu,is_ksp,"ПЕРЕСВЕТКА");  // Резерв
} else

if (KSP_Let[13]){  // Т                             Если выбранна буква И
KSP_Booled[13][0]=true;                          // Тогда выставляем признак И1 - правда
JPS(1,is_operator,is_miu,is_ksp,"И1"); } else   // Логируем выдачу команды

if (KSP_Let[14]){  // У
KSP_Booled[14][0]=true;
JPS(1,is_operator,is_miu,is_ksp,"К1"); } else

if (KSP_Let[15]){  // Ф
KSP_Booled[15][0]=true;
JPS(1,is_operator,is_miu,is_ksp,"Л1"); }

KSP_R_A->Color=clBlack;
KSP_R_A->Font->Color=clYellow;
KSP_R_V->Color=clBlack;
KSP_R_V->Font->Color=clYellow;
KSP_R_G->Color=clBlack;
KSP_R_G->Font->Color=clYellow;
KSP_R_D->Color=clBlack;
KSP_R_D->Font->Color=clYellow;
KSP_R_J->Color=clBlack;
KSP_R_J->Font->Color=clYellow;
KSP_R_I->Color=clBlack;
KSP_R_I->Font->Color=clYellow;
KSP_R_K->Color=clBlack;
KSP_R_K->Font->Color=clYellow;
KSP_R_L->Color=clBlack;
KSP_R_L->Font->Color=clYellow;
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
KSP_R_B_image->Enabled=true;
KSP_R_N_image->Enabled=true;
KSP_R_P_image->Enabled=true;
KSP_R_R_image->Enabled=true;
KSP_R_S_image->Enabled=true;
KSP_R_T_image->Enabled=true;
KSP_R_U_image->Enabled=true;
KSP_R_F_image->Enabled=true;
}
//---------------------------------------------------------------------------

