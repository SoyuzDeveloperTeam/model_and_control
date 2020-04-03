//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "bfi_formats.h"
#include "bfi_fmts_data.h"
#include "argon/arg_header.h"  // Загогловок А16
#include "argon/CtrlWord.h"
#include "main_header.h"
#include "inpu_connect.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBFI_Simvol_form *BFI_Simvol_form;
int i_takt_asd[10];
//--- Временные переменные для вывода параметров на ВКУ ---------------------
String cw_B1_string;
String B1_string[5];
String B1_forDBG[5];
String B1_bfi;

String cw_B6_string;
String B6_string[5];
String B6_forDBG[5];
String B6_bfi;

String cw_a19_string;
String a19_string[5];
String a19_forDBG[5];
String a19_bfi;
//---------------------------------------------------------------------------
__fastcall TBFI_Simvol_form::TBFI_Simvol_form(TComponent* Owner)
        : TForm(Owner)
{
 f41_emer->Caption="";
 f41_emerN->Caption="";
 f43_emer->Caption="";
 f43_emerN->Caption="";

}
//---------------------------------------------------------------------------
void __fastcall TBFI_Simvol_form::BFIDATATIMERTimer(TObject *Sender)
{

if(cw_b6[13]) act_str_1->Caption=BFI_action_str1[2];  // if prichal...
f41_42->Caption=FormatFloat("0000",ArgonMemoryType[42]);
f41_102->Caption=FormatFloat("0000",ArgonMemoryType[102]);
//f41_A22->Caption=FloatToStr(ArgonMemoryType[112]);

if(dynamics.Ex>0.00) f43_X_plus->Caption="+W"; else
if(dynamics.Ex<0.00) f43_X_plus->Caption="-W"; else
if(dynamics.Ex=0) f43_X_plus->Caption="  ";

if(dynamics.Ey>0.00) f43_Y_plus->Caption="+y"; else
if(dynamics.Ey<0.00) f43_Y_plus->Caption="-y"; else
if(dynamics.Ey=0) f43_Y_plus->Caption="  ";

if(dynamics.Ez>0.00) f43_Z_plus->Caption="+z"; else
if(dynamics.Ez<0.00) f43_Z_plus->Caption="-z"; else
if(dynamics.Ez=0) f43_Z_plus->Caption="  ";

if(USO_Booled[3][7]=false&&dynamics.rs<1000){
 cw_b6[11]=1;
 cw_b6[8]=1;
 bfi_strings.str_1=7;
 if(dynamics.sks<0.001&&dynamics.rs<100)bfi_strings.str_1=8;
}

if(bfi_strings.str_1==1) Label3->Caption=BFI_action_str1[0]; else
if(bfi_strings.str_1==1) Label3->Caption=BFI_action_str1[1]; else
if(bfi_strings.str_1==1) Label3->Caption=BFI_action_str1[2]; else
if(bfi_strings.str_1==1) Label3->Caption=BFI_action_str1[3]; else
if(bfi_strings.str_1==1) Label3->Caption=BFI_action_str1[4]; else
if(bfi_strings.str_1==1) Label3->Caption=BFI_action_str1[5]; else
if(bfi_strings.str_1==1) Label3->Caption=BFI_action_str1[6]; else
if(bfi_strings.str_1==1) Label3->Caption=BFI_action_str1[7]; else
if(bfi_strings.str_1==1) Label3->Caption=BFI_action_str1[8]; else
if(bfi_strings.str_1==1) Label3->Caption=BFI_action_str1[9]; else
if(bfi_strings.str_1==1) Label3->Caption=BFI_action_str1[10]; else
Label3->Caption="";

if(bfi_strings.str_2==1) Label5->Caption=BFI_action_str2[0]; else
if(bfi_strings.str_2==2) Label5->Caption=BFI_action_str2[1]; else
if(bfi_strings.str_2==3) Label5->Caption=BFI_action_str2[2]; else
if(bfi_strings.str_2==4) Label5->Caption=BFI_action_str2[3]; else
if(bfi_strings.str_2==5) Label5->Caption=BFI_action_str2[4]; else
if(bfi_strings.str_2==6) Label5->Caption=BFI_action_str2[5]; else
if(bfi_strings.str_2==7) Label5->Caption=BFI_action_str2[6]; else
if(bfi_strings.str_2==8) Label5->Caption=BFI_action_str2[7]; else
Label5->Caption="";

if(USO_Booled[10][7]) Label27->Caption=BFI_oper2str[0]; else
if(bfi_strings.str_3==2) Label27->Caption=BFI_oper2str[1]; else
if(bfi_strings.str_3==3) Label27->Caption=BFI_oper2str[2]; else
if(bfi_strings.str_3==4) Label27->Caption=BFI_oper2str[3]; else
Label27->Caption="";

Label9->Caption=FloatToStr(dynamics.rasp).sprintf("%07.03f",dynamics.rasp);
Label36->Caption=FloatToStr(dynamics.omzf).sprintf("%06.03f",dynamics.omzf);
Label37->Caption=FloatToStr(dynamics.omyf).sprintf("%06.03f",dynamics.omyf);
//dpo_status_bit =
Label43->Caption=FloatToStr(-dynamics.sks).sprintf("%07.03f",(-dynamics.sks));
Label41->Caption=FloatToStr(dynamics.rs).sprintf("%06.03f",(dynamics.rs));
f46_vtek->Caption=FloatToStr(v_tek_m).sprintf("%06.05f",v_tek_m);
if(cw_b1[12]) f46_tvc->Caption=gc1_time.FormatString("hh.nn.ss"); else
f46_tvc->Caption="00.00.00";
f41_v1v->Caption=FormatFloat("000.00",ArgonMemoryType[41]);
f41_101->Caption=FormatFloat("000.00",ArgonMemoryType[101]);
f41_43->Caption=FormatFloat("0.00000",ArgonMemoryType[43]);
f41_44->Caption=FormatFloat("0.00000",ArgonMemoryType[44]);
f41_45->Caption=FormatFloat("0.00000",ArgonMemoryType[45]);
f41_46->Caption=FormatFloat("0.00000",ArgonMemoryType[46]);
act_str_1->Caption=BFI_action_str1[4];
if(GSO_types==0) GSO_String=""; else
if(GSO_types==1) GSO_String="1"; else
if(GSO_types==2) GSO_String=" 2"; else
if(GSO_types==3) GSO_String="  3"; else
if(GSO_types==4) GSO_String="   4"; else
if(GSO_types==5) GSO_String="    5";
gso->Caption=GSO_String;
TMTPTime->Caption="TN="+OnboardModelTime.FormatString("hh:nn:ss");

if(i_takt_asd[1]==2){
cw_B1_string +=(byte)cw_b1[0];
cw_B1_string +=(byte)cw_b1[1];
cw_B1_string +=(byte)cw_b1[2];
cw_B1_string +=(byte)cw_b1[3];
 B1_forDBG[0] += "0";
 B1_forDBG[0] +=(byte)cw_b1[1];
 B1_forDBG[0] +=(byte)cw_b1[2];
 B1_forDBG[0] +=(byte)cw_b1[3];
cw_B1_string +=(byte)cw_b1[4];
cw_B1_string +=(byte)cw_b1[5];
cw_B1_string +=(byte)cw_b1[6];
 B1_forDBG[1] += "0";
 B1_forDBG[1] +=(byte)cw_b1[4];
 B1_forDBG[1] +=(byte)cw_b1[5];
 B1_forDBG[1] +=(byte)cw_b1[6];
cw_B1_string +=(byte)cw_b1[7];
cw_B1_string +=(byte)cw_b1[8];
cw_B1_string +=(byte)cw_b1[9];
 B1_forDBG[2] += "0";
 B1_forDBG[2] +=(byte)cw_b1[7];
 B1_forDBG[2] +=(byte)cw_b1[8];
 B1_forDBG[2] +=(byte)cw_b1[9];
cw_B1_string +=(byte)cw_b1[10];
cw_B1_string +=(byte)cw_b1[11];
cw_B1_string +=(byte)cw_b1[12];
 B1_forDBG[3] += "0";
 B1_forDBG[3] +=(byte)cw_b1[10];
 B1_forDBG[3] +=(byte)cw_b1[11];
 B1_forDBG[3] +=(byte)cw_b1[12];
cw_B1_string +=(byte)cw_b1[13];
cw_B1_string +=(byte)cw_b1[14];
cw_B1_string +=(byte)cw_b1[15];
 B1_forDBG[4] += "0";
 B1_forDBG[4] +=(byte)cw_b1[13];
 B1_forDBG[4] +=(byte)cw_b1[14];
 B1_forDBG[4] +=(byte)cw_b1[15];
B1_string[0] = (byte)cw_b1[0];
B1_string[1] = XtoY(Trim(B1_forDBG[0]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B1_string[2] = XtoY(Trim(B1_forDBG[1]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B1_string[3] = XtoY(Trim(B1_forDBG[2]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B1_string[4] = XtoY(Trim(B1_forDBG[3]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B1_string[5] = XtoY(Trim(B1_forDBG[4]), StrToIntDef(2, 10), StrToIntDef(16, 10));
f41_B1->Caption=B1_string[0]+"."+B1_string[1]+""+B1_string[2]+""+B1_string[3]+""+B1_string[4]+""+B1_string[5];
B1_string[0] = "";B1_string[1] = "";B1_string[2] = "";B1_string[3] = "";B1_string[4] = "";B1_string[5] = "";
B1_forDBG[0] = "";B1_forDBG[1] = "";B1_forDBG[2] = "";B1_forDBG[3] = "";B1_forDBG[4] = "";cw_B1_string = "";

cw_B6_string +=(byte)cw_b6[0];
cw_B6_string +=(byte)cw_b6[1];
cw_B6_string +=(byte)cw_b6[2];
cw_B6_string +=(byte)cw_b6[3];
 B6_forDBG[0] += "0";
 B6_forDBG[0] +=(byte)cw_b6[1];
 B6_forDBG[0] +=(byte)cw_b6[2];
 B6_forDBG[0] +=(byte)cw_b6[3];
cw_B6_string +=(byte)cw_b6[4];
cw_B6_string +=(byte)cw_b6[5];
cw_B6_string +=(byte)cw_b6[6];
 B6_forDBG[1] += "0";
 B6_forDBG[1] +=(byte)cw_b6[4];
 B6_forDBG[1] +=(byte)cw_b6[5];
 B6_forDBG[1] +=(byte)cw_b6[6];
cw_B6_string +=(byte)cw_b6[7];
cw_B6_string +=(byte)cw_b6[8];
cw_B6_string +=(byte)cw_b6[9];
 B6_forDBG[2] += "0";
 B6_forDBG[2] +=(byte)cw_b6[7];
 B6_forDBG[2] +=(byte)cw_b6[8];
 B6_forDBG[2] +=(byte)cw_b6[9];
cw_B6_string +=(byte)cw_b6[10];
cw_B6_string +=(byte)cw_b6[11];
cw_B6_string +=(byte)cw_b6[12];
 B6_forDBG[3] += "0";
 B6_forDBG[3] +=(byte)cw_b6[10];
 B6_forDBG[3] +=(byte)cw_b6[11];
 B6_forDBG[3] +=(byte)cw_b6[12];
cw_B6_string +=(byte)cw_b6[13];
cw_B6_string +=(byte)cw_b6[14];
cw_B6_string +=(byte)cw_b6[15];
 B6_forDBG[4] += "0";
 B6_forDBG[4] +=(byte)cw_b6[13];
 B6_forDBG[4] +=(byte)cw_b6[14];
 B6_forDBG[4] +=(byte)cw_b6[15];
B6_string[0] = (byte)cw_b6[0];
B6_string[1] = XtoY(Trim(B6_forDBG[0]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B6_string[2] = XtoY(Trim(B6_forDBG[1]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B6_string[3] = XtoY(Trim(B6_forDBG[2]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B6_string[4] = XtoY(Trim(B6_forDBG[3]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B6_string[5] = XtoY(Trim(B6_forDBG[4]), StrToIntDef(2, 10), StrToIntDef(16, 10));
f41_B6->Caption=B6_string[0]+"."+B6_string[1]+""+B6_string[2]+""+B6_string[3]+""+B6_string[4]+""+B6_string[5];
B6_string[0] = "";B6_string[1] = "";B6_string[2] = "";B6_string[3] = "";B6_string[4] = "";B6_string[5] = "";
B6_forDBG[0] = "";B6_forDBG[1] = "";B6_forDBG[2] = "";B6_forDBG[3] = "";B6_forDBG[4] = "";cw_B6_string = "";

cw_a19_string +=(byte)cw_a19[0];
cw_a19_string +=(byte)cw_a19[1];
cw_a19_string +=(byte)cw_a19[2];
cw_a19_string +=(byte)cw_a19[3];
 a19_forDBG[0] += "0";
 a19_forDBG[0] +=(byte)cw_a19[1];
 a19_forDBG[0] +=(byte)cw_a19[2];
 a19_forDBG[0] +=(byte)cw_a19[3];
cw_a19_string +=(byte)cw_a19[4];
cw_a19_string +=(byte)cw_a19[5];
cw_a19_string +=(byte)cw_a19[6];
 a19_forDBG[1] += "0";
 a19_forDBG[1] +=(byte)cw_a19[4];
 a19_forDBG[1] +=(byte)cw_a19[5];
 a19_forDBG[1] +=(byte)cw_a19[6];
cw_a19_string +=(byte)cw_a19[7];
cw_a19_string +=(byte)cw_a19[8];
cw_a19_string +=(byte)cw_a19[9];
 a19_forDBG[2] += "0";
 a19_forDBG[2] +=(byte)cw_a19[7];
 a19_forDBG[2] +=(byte)cw_a19[8];
 a19_forDBG[2] +=(byte)cw_a19[9];
cw_a19_string +=(byte)cw_a19[10];
cw_a19_string +=(byte)cw_a19[11];
cw_a19_string +=(byte)cw_a19[12];
 a19_forDBG[3] += "0";
 a19_forDBG[3] +=(byte)cw_a19[10];
 a19_forDBG[3] +=(byte)cw_a19[11];
 a19_forDBG[3] +=(byte)cw_a19[12];
cw_a19_string +=(byte)cw_a19[13];
cw_a19_string +=(byte)cw_a19[14];
cw_a19_string +=(byte)cw_a19[15];
 a19_forDBG[4] += "0";
 a19_forDBG[4] +=(byte)cw_a19[13];
 a19_forDBG[4] +=(byte)cw_a19[14];
 a19_forDBG[4] +=(byte)cw_a19[15];
a19_string[0] = (byte)cw_a19[0];
a19_string[1] = XtoY(Trim(a19_forDBG[0]), StrToIntDef(2, 10), StrToIntDef(16, 10));
a19_string[2] = XtoY(Trim(a19_forDBG[1]), StrToIntDef(2, 10), StrToIntDef(16, 10));
a19_string[3] = XtoY(Trim(a19_forDBG[2]), StrToIntDef(2, 10), StrToIntDef(16, 10));
a19_string[4] = XtoY(Trim(a19_forDBG[3]), StrToIntDef(2, 10), StrToIntDef(16, 10));
a19_string[5] = XtoY(Trim(a19_forDBG[4]), StrToIntDef(2, 10), StrToIntDef(16, 10));
Label16->Caption=a19_string[0]+"."+a19_string[1]+""+a19_string[2]+""+a19_string[3]+""+a19_string[4]+""+a19_string[5];
a19_string[0] = "";a19_string[1] = "";a19_string[2] = "";a19_string[3] = "";a19_string[4] = "";a19_string[5] = "";
a19_forDBG[0] = "";a19_forDBG[1] = "";a19_forDBG[2] = "";a19_forDBG[3] = "";a19_forDBG[4] = "";cw_a19_string = "";

i_takt_asd[1]=0;
} else i_takt_asd[1]++;
// EmerString
if(cw_TA1[0]){ // Если нет аварий, то...
 f41_emer->Caption=BFI_EmerStr[0];
 f41_emerN->Caption="00";
 f43_emer->Caption=BFI_EmerStr[0];
 f43_emerN->Caption="00"; } else
if(cw_TA1[1]){ // Если есть авария ИКВ-1
 f41_emer->Caption=BFI_EmerStr[1];
 f41_emerN->Caption="01";
 f43_emer->Caption=BFI_EmerStr[1];
 f43_emerN->Caption="01"; } else
if(cw_TA1[2]){ // Если есть авария
 f41_emer->Caption=BFI_EmerStr[2];
 f41_emerN->Caption="02";
 f43_emer->Caption=BFI_EmerStr[2];
 f43_emerN->Caption="02"; }
}
//---------------------------------------------------------------------------








