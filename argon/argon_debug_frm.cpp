//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "argon_debug_frm.h"
#include "USOData.h"
#include "arg_header.h"
#include "CtrlWord.h"    // Управляющие слова Аргона
#include "JouHeader.h"   // Заголовок для журнала

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Targ_deb *arg_deb;

static int i_flo;

//---------------------------------------------------------------------------
__fastcall Targ_deb::Targ_deb(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Targ_deb::Button11Click(TObject *Sender)
{
if(ctrlword_enter->ItemIndex==0) {  // B1
       if(cw_num_cb->ItemIndex==0)  cw_b1[0] = 1;  else
       if(cw_num_cb->ItemIndex==1)  cw_b1[1] = 1;  else
       if(cw_num_cb->ItemIndex==2)  cw_b1[2] = 1;  else
       if(cw_num_cb->ItemIndex==3)  cw_b1[3] = 1;  else
       if(cw_num_cb->ItemIndex==4)  cw_b1[4] = 1;  else
       if(cw_num_cb->ItemIndex==5)  cw_b1[5] = 1;  else
       if(cw_num_cb->ItemIndex==6)  cw_b1[6] = 1;  else
       if(cw_num_cb->ItemIndex==7)  cw_b1[7] = 1;  else
       if(cw_num_cb->ItemIndex==8)  cw_b1[8] = 1;  else
       if(cw_num_cb->ItemIndex==9)  cw_b1[9] = 1;  else
       if(cw_num_cb->ItemIndex==10) cw_b1[10] = 1;  else
       if(cw_num_cb->ItemIndex==11) cw_b1[11] = 1;  else
       if(cw_num_cb->ItemIndex==12) cw_b1[12] = 1;  else
       if(cw_num_cb->ItemIndex==13) cw_b1[13] = 1;  else
       if(cw_num_cb->ItemIndex==14) cw_b1[14] = 1;  else
       if(cw_num_cb->ItemIndex==15) cw_b1[15] = 1;
        } else
if(ctrlword_enter->ItemIndex==1) {  // B6
       if(cw_num_cb->ItemIndex==0)  cw_b6[0] = 1;  else
       if(cw_num_cb->ItemIndex==1)  cw_b6[1] = 1;  else
       if(cw_num_cb->ItemIndex==2)  cw_b6[2] = 1;  else
       if(cw_num_cb->ItemIndex==3)  cw_b6[3] = 1;  else
       if(cw_num_cb->ItemIndex==4)  cw_b6[4] = 1;  else
       if(cw_num_cb->ItemIndex==5)  cw_b6[5] = 1;  else
       if(cw_num_cb->ItemIndex==6)  cw_b6[6] = 1;  else
       if(cw_num_cb->ItemIndex==7)  cw_b6[7] = 1;  else
       if(cw_num_cb->ItemIndex==8)  cw_b6[8] = 1;  else
       if(cw_num_cb->ItemIndex==9)  cw_b6[9] = 1;  else
       if(cw_num_cb->ItemIndex==10) cw_b6[10] = 1;  else
       if(cw_num_cb->ItemIndex==11) cw_b6[11] = 1;  else
       if(cw_num_cb->ItemIndex==12) cw_b6[12] = 1;  else
       if(cw_num_cb->ItemIndex==13) cw_b6[13] = 1;  else
       if(cw_num_cb->ItemIndex==14) cw_b6[14] = 1;  else
       if(cw_num_cb->ItemIndex==15) cw_b6[15] = 1;
        } else
if(ctrlword_enter->ItemIndex==2) {  // R1
       if(cw_num_cb->ItemIndex==0)  cw_r1[0] = 1;  else
       if(cw_num_cb->ItemIndex==1)  cw_r1[1] = 1;  else
       if(cw_num_cb->ItemIndex==2)  cw_r1[2] = 1;  else
       if(cw_num_cb->ItemIndex==3)  cw_r1[3] = 1;  else
       if(cw_num_cb->ItemIndex==4)  cw_r1[4] = 1;  else
       if(cw_num_cb->ItemIndex==5)  cw_r1[5] = 1;  else
       if(cw_num_cb->ItemIndex==6)  cw_r1[6] = 1;  else
       if(cw_num_cb->ItemIndex==7)  cw_r1[7] = 1;  else
       if(cw_num_cb->ItemIndex==8)  cw_r1[8] = 1;  else
       if(cw_num_cb->ItemIndex==9)  cw_r1[9] = 1;  else
       if(cw_num_cb->ItemIndex==10) cw_r1[10] = 1;  else
       if(cw_num_cb->ItemIndex==11) cw_r1[11] = 1;  else
       if(cw_num_cb->ItemIndex==12) cw_r1[12] = 1;  else
       if(cw_num_cb->ItemIndex==13) cw_r1[13] = 1;  else
       if(cw_num_cb->ItemIndex==14) cw_r1[14] = 1;  else
       if(cw_num_cb->ItemIndex==15) cw_r1[15] = 1;
        }
if(ctrlword_enter->ItemIndex==5) {  // A19
       if(cw_num_cb->ItemIndex==0)  cw_a19[0] = 1;  else
       if(cw_num_cb->ItemIndex==1)  cw_a19[1] = 1;  else
       if(cw_num_cb->ItemIndex==2)  cw_a19[2] = 1;  else
       if(cw_num_cb->ItemIndex==3)  cw_a19[3] = 1;  else
       if(cw_num_cb->ItemIndex==4)  cw_a19[4] = 1;  else
       if(cw_num_cb->ItemIndex==5)  cw_a19[5] = 1;  else
       if(cw_num_cb->ItemIndex==6)  cw_a19[6] = 1;  else
       if(cw_num_cb->ItemIndex==7)  cw_a19[7] = 1;  else
       if(cw_num_cb->ItemIndex==8)  cw_a19[8] = 1;  else
       if(cw_num_cb->ItemIndex==9)  cw_a19[9] = 1;  else
       if(cw_num_cb->ItemIndex==10) cw_a19[10] = 1;  else
       if(cw_num_cb->ItemIndex==11) cw_a19[11] = 1;  else
       if(cw_num_cb->ItemIndex==12) cw_a19[12] = 1;  else
       if(cw_num_cb->ItemIndex==13) cw_a19[13] = 1;  else
       if(cw_num_cb->ItemIndex==14) cw_a19[14] = 1;  else
       if(cw_num_cb->ItemIndex==15) cw_a19[15] = 1;
        }
if(ctrlword_enter->ItemIndex==6) {  // A20
       if(cw_num_cb->ItemIndex==0)  cw_a20[0] = 1;  else
       if(cw_num_cb->ItemIndex==1)  cw_a20[1] = 1;  else
       if(cw_num_cb->ItemIndex==2)  cw_a20[2] = 1;  else
       if(cw_num_cb->ItemIndex==3)  cw_a20[3] = 1;  else
       if(cw_num_cb->ItemIndex==4)  cw_a20[4] = 1;  else
       if(cw_num_cb->ItemIndex==5)  cw_a20[5] = 1;  else
       if(cw_num_cb->ItemIndex==6)  cw_a20[6] = 1;  else
       if(cw_num_cb->ItemIndex==7)  cw_a20[7] = 1;  else
       if(cw_num_cb->ItemIndex==8)  cw_a20[8] = 1;  else
       if(cw_num_cb->ItemIndex==9)  cw_a20[9] = 1;  else
       if(cw_num_cb->ItemIndex==10) cw_a20[10] = 1;  else
       if(cw_num_cb->ItemIndex==11) cw_a20[11] = 1;  else
       if(cw_num_cb->ItemIndex==12) cw_a20[12] = 1;  else
       if(cw_num_cb->ItemIndex==13) cw_a20[13] = 1;  else
       if(cw_num_cb->ItemIndex==14) cw_a20[14] = 1;  else
       if(cw_num_cb->ItemIndex==15) cw_a20[15] = 1;
        }
JPS(1,"ОТЛАДОЧНОЕ: Ввод состояния УС в БЦВК оператором. ",ctrlword_enter->Text+"["+cw_num_cb->Text+"]=","1","");
}
//---------------------------------------------------------------------------
void __fastcall Targ_deb::Button13Click(TObject *Sender)
{
switch(ctrlword_enter->ItemIndex) {
      case  0:  if(cw_num_cb->ItemIndex==0)  cw_b1[0] = 0;  else
                if(cw_num_cb->ItemIndex==1)  cw_b1[1] = 0;  else
                if(cw_num_cb->ItemIndex==2)  cw_b1[2] = 0;  else
                if(cw_num_cb->ItemIndex==3)  cw_b1[3] = 0;  else
                if(cw_num_cb->ItemIndex==4)  cw_b1[4] = 0;  else
                if(cw_num_cb->ItemIndex==5)  cw_b1[5] = 0;  else
                if(cw_num_cb->ItemIndex==6)  cw_b1[6] = 0;  else
                if(cw_num_cb->ItemIndex==7)  cw_b1[7] = 0;  else
                if(cw_num_cb->ItemIndex==8)  cw_b1[8] = 0;  else
                if(cw_num_cb->ItemIndex==9)  cw_b1[9] = 0;  else
                if(cw_num_cb->ItemIndex==10) cw_b1[10] = 0;  else
                if(cw_num_cb->ItemIndex==11) cw_b1[11] = 0;  else
                if(cw_num_cb->ItemIndex==12) cw_b1[12] = 0;  else
                if(cw_num_cb->ItemIndex==13) cw_b1[13] = 0;  else
                if(cw_num_cb->ItemIndex==14) cw_b1[14] = 0;  else
                if(cw_num_cb->ItemIndex==15) cw_b1[15] = 0;
        }  // Слово
if(ctrlword_enter->ItemIndex==5) {
       if(cw_num_cb->ItemIndex==0)  cw_a19[0] = 0;  else
       if(cw_num_cb->ItemIndex==1)  cw_a19[1] = 0;  else
       if(cw_num_cb->ItemIndex==2)  cw_a19[2] = 0;  else
       if(cw_num_cb->ItemIndex==3)  cw_a19[3] = 0;  else
       if(cw_num_cb->ItemIndex==4)  cw_a19[4] = 0;  else
       if(cw_num_cb->ItemIndex==5)  cw_a19[5] = 0;  else
       if(cw_num_cb->ItemIndex==6)  cw_a19[6] = 0;  else
       if(cw_num_cb->ItemIndex==7)  cw_a19[7] = 0;  else
       if(cw_num_cb->ItemIndex==8)  cw_a19[8] = 0;  else
       if(cw_num_cb->ItemIndex==9)  cw_a19[9] = 0;  else
       if(cw_num_cb->ItemIndex==10) cw_a19[10] = 0;  else
       if(cw_num_cb->ItemIndex==11) cw_a19[11] = 0;  else
       if(cw_num_cb->ItemIndex==12) cw_a19[12] = 0;  else
       if(cw_num_cb->ItemIndex==13) cw_a19[13] = 0;  else
       if(cw_num_cb->ItemIndex==14) cw_a19[14] = 0;  else
       if(cw_num_cb->ItemIndex==15) cw_a19[15] = 0;
        }
if(ctrlword_enter->ItemIndex==6) {
       if(cw_num_cb->ItemIndex==0)  cw_a20[0] = 0;  else
       if(cw_num_cb->ItemIndex==1)  cw_a20[1] = 0;  else
       if(cw_num_cb->ItemIndex==2)  cw_a20[2] = 0;  else
       if(cw_num_cb->ItemIndex==3)  cw_a20[3] = 0;  else
       if(cw_num_cb->ItemIndex==4)  cw_a20[4] = 0;  else
       if(cw_num_cb->ItemIndex==5)  cw_a20[5] = 0;  else
       if(cw_num_cb->ItemIndex==6)  cw_a20[6] = 0;  else
       if(cw_num_cb->ItemIndex==7)  cw_a20[7] = 0;  else
       if(cw_num_cb->ItemIndex==8)  cw_a20[8] = 0;  else
       if(cw_num_cb->ItemIndex==9)  cw_a20[9] = 0;  else
       if(cw_num_cb->ItemIndex==10) cw_a20[10] = 0;  else
       if(cw_num_cb->ItemIndex==11) cw_a20[11] = 0;  else
       if(cw_num_cb->ItemIndex==12) cw_a20[12] = 0;  else
       if(cw_num_cb->ItemIndex==13) cw_a20[13] = 0;  else
       if(cw_num_cb->ItemIndex==14) cw_a20[14] = 0;  else
       if(cw_num_cb->ItemIndex==15) cw_a20[15] = 0;
        }
JPS(1,"ОТЛАДОЧНОЕ: Ввод состояния УС в СУБК оператором. ",ctrlword_enter->Text+"["+cw_num_cb->Text+"]=","0","");        
}
//---------------------------------------------------------------------------
void __fastcall Targ_deb::Timer1Timer(TObject *Sender)
{
if(ind->Checked)Label30->Caption=FloatToStr(ArgonMemoryType[i_flo]);
}
//---------------------------------------------------------------------------

void __fastcall Targ_deb::Button14Click(TObject *Sender)
{
if(StrToInt(addr_ozu->Text)<4097)Label30->Caption=FloatToStr(ArgonMemoryType[StrToInt(addr_ozu->Text)]); else
Label30->Caption="Неверный адрес Аргона";
i_flo = StrToInt(addr_ozu->Text);
}
//---------------------------------------------------------------------------

void __fastcall Targ_deb::Timer2Timer(TObject *Sender)
{
if(dynamics.Ex<0.00) Label31->Caption="Ex "+FormatFloat("00.0000",dynamics.Ex); else
                     Label31->Caption="Ex "+FormatFloat(" 00.0000",dynamics.Ex);
if(dynamics.Ey<0.00) Label32->Caption="Ey "+FormatFloat("00.0000",dynamics.Ey); else
                     Label32->Caption="Ey "+FormatFloat(" 00.0000",dynamics.Ey);
if(dynamics.Ez<0.00) Label47->Caption="Ez "+FormatFloat("00.0000",dynamics.Ez); else
                     Label47->Caption="Ez "+FormatFloat(" 00.0000",dynamics.Ez);
if(dynamics.ax<0.00) Label48->Caption="ax "+FormatFloat("00.0000",dynamics.ax); else
                     Label48->Caption="ax "+FormatFloat(" 00.0000",dynamics.ax);
if(dynamics.ay<0.00) Label49->Caption="ay "+FormatFloat("00.0000",dynamics.ay); else
                     Label49->Caption="ay "+FormatFloat(" 00.0000",dynamics.ay);
if(dynamics.az<0.00) Label50->Caption="az "+FormatFloat("00.0000",dynamics.az); else
                     Label50->Caption="az "+FormatFloat(" 00.0000",dynamics.az);
Label54->Caption=IntToStr(irvi_type.mode);
Label55->Caption=IntToStr(irvi_type.addr);
Label56->Caption=IntToStr(irvi_type.value);
}
//---------------------------------------------------------------------------

void __fastcall Targ_deb::argon_dtTimer(TObject *Sender)
{
if(arg_work_pr) Panel1->Caption="ЕСТЬ"; else Panel1->Caption="НЕТ"; // Проверка ввода признака "Работа Аргона"
Label5->Caption="Переменная из БЦВК: "+IntToStr(a_debugger);
Label4->Caption=IntToStr(i_ot_pusk);
Label6->Caption=IntToStr(integer_n);
//USO_Booled[3][3]  = false;
//USO_Booled[3][4]  = false;
if(USO_Booled[3][13]){
 a_ch->Color=clLime;
 B_ch->Color=clLime;
 v_ch->Color=clLime; } else {
 a_ch->Color=clBtnFace;
 B_ch->Color=clBtnFace;
 v_ch->Color=clBtnFace; }
if(USO_Booled[3][2]){
 a_ch->Color=clLime;
 B_ch->Color=clBtnFace;
 v_ch->Color=clBtnFace; } else {
 a_ch->Color=clBtnFace;
 B_ch->Color=clBtnFace;
 v_ch->Color=clBtnFace; }
}
//---------------------------------------------------------------------------

