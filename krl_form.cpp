//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "JouHeader.h"
#include "JouStrings.h"
#include "arg_header.h"
#include "krl_form.h"
#include "argon/CtrlWord.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tkrl_frm *krl_frm;
AnsiString krl_u_mode[3]={"ОП","СБ","СП"};
unsigned short nu_type[3];  // Номер записи по каждому режиму
typedef struct{
unsigned short Mode;
AnsiString FLB;
int day, mounth, year, hour, min, second;
int spaceship_number;
TDateTime T0;
bool record_f;
}ustavka;
//---------------------------------------------------------------------------
__fastcall Tkrl_frm::Tkrl_frm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tkrl_frm::SpeedButton1Click(TObject *Sender)
{
cw_a4[11]=1;
ustavka test;
unsigned short i;
if(op->Checked){
i=0;
} else  // OP                 is_mcc
if(sb->Checked){
t_krl_true[0]=1;
i=1;
JPS(2,is_mcc,is_sudn,"Внимание! Идет запись уставочной информации!","");
arg_T0.TimeString()=krl_t0->Time;
nu_type[1]++;
test.Mode=1;
test.spaceship_number=2;
test.T0=krl_t0->Time;
} else
if(sp->Checked){
i=2;
}
cw_a4[11]=0;
JPS(4,is_miu,is_operator,"Уставки на "+krl_u_mode[i]," успешно записаны!");
}
//---------------------------------------------------------------------------


