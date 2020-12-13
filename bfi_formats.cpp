//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "bfi_formats.h"
#include "bfi_fmts_data.h"
#include "argon/arg_header.h"  // Загогловок А16
#include "kurs_main.cpp"
#include "argon/CtrlWord.h"
#include "main_header.h"
#include "inpu_connect.cpp"
#include "inpuconnect.cpp"
#include "ICN_header.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBFI_Simvol_form *BFI_Simvol_form;

static int i_takt_asd[10];

static String cw_B1_string;
static String B1_string[5];
static String B1_forDBG[5];
static String B1_bfi;

static String cw_B6_string;
static String B6_string[5];
static String B6_forDBG[5];
static String B6_bfi;

static String cw_B10_string;
static String B10_string[5];
static String B10_forDBG[5];
static String B10_bfi;

static String cw_a19_string;
static String a19_string[5];
static String a19_forDBG[5];
static String a19_bfi;

static String cw_A20_string;
static String A20_string[5];
static String A20_forDBG[5];
static String A20_bfi;

static String cw_R1_string;
static String R1_string[5];
static String R1_forDBG[5];
static String R1_bfi;

static String cw_R6_string;
static String R6_string[5];
static String R6_forDBG[5];
static String R6_bfi;

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
////////////////
// EmerString //
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
 f43_emerN->Caption="02"; } else
if(cw_TA1[3]){ // Если есть авария
 f41_emer->Caption=BFI_EmerStr[3];
 f41_emerN->Caption="03";
 f43_emer->Caption=BFI_EmerStr[3];
 f43_emerN->Caption="03"; }
//////////////////////
// Обработчик astr2 //
if(USO_Booled[1][16]) {  // Если есть признак КУРС1...
f43_astr2->Caption=BFI_action_str2[6]; // "КУРС 1"
f44_astr2->Caption=BFI_action_str2[6]; // "КУРС 1"
/* f46_4615 */} else
if(USO_Booled[2][0])  {  // Если есть признак КУРС2...
f43_astr2->Caption=BFI_action_str2[7]; // "КУРС 2"
f44_astr2->Caption=BFI_action_str2[6]; // "КУРС 2"
/* f46_4616 */} else
if(cw_b6[13]) {          // Если введен признак "ПРИЧАЛ"
f43_astr2->Caption=BFI_action_str2[2]; }else{
f43_astr2->Caption=""; f44_astr2->Caption=""; } // При отсутствии признаков из группы 8 - знакоместо пустое "ПРОБЕЛ"

//////////////////////////////////////
// Обработчик "Полуавтомат/Автомат" //
if(av_pav_pr==2) f43_p_a->Caption=BFI_Aut[1]; else
if(av_pav_pr==1) f43_p_a->Caption=BFI_Aut[0]; else f43_p_a->Caption="";

if(prks){ f43_astr1->Caption=BFI_action_str1[1];
          f44_astr1->Caption=BFI_action_str1[1]; }

// Обработчик знакоместа 43.10 (КУРС_1)
if(kurs_zap_t==0) f43_kurs->Caption="";         else if(kurs_zap_t==1) f43_kurs->Caption=BFI_Zap[0]; else
if(kurs_zap_t==3) f43_kurs->Caption=BFI_Zap[2]; else if(kurs_zap_t==3) f43_kurs->Caption=BFI_Zap[3]; else
if(kurs_zap_t==4) f43_kurs->Caption=BFI_Zap[4]; else if(kurs_1_pr[0])  f43_kurs->Caption=BFI_Zap[1];

f41_42->Caption=FormatFloat("0000",ArgonMemoryType[42]);
f41_102->Caption=FormatFloat("0000",ArgonMemoryType[102]);
//f41_A22->Caption=FloatToStr(ArgonMemoryType[112]);

if(dynamics.Ex>=0.01) f43_X_plus->Caption="+W"; else
if(dynamics.Ex<=0.01) f43_X_plus->Caption="-W"; else
if(dynamics.Ex=0) f43_X_plus->Caption="  ";

if(dynamics.Ey>=0.01) f43_Y_plus->Caption="+y"; else
if(dynamics.Ey<=0.01) f43_Y_plus->Caption="-y"; else
if(dynamics.Ey=0) f43_Y_plus->Caption="  ";

if(dynamics.Ez>=0.01) f43_Z_plus->Caption="+z"; else
if(dynamics.Ez<=0.01) f43_Z_plus->Caption="-z"; else
if(dynamics.Ez=0) f43_Z_plus->Caption="  ";

// Алгоритм перенести в соотвутствующую подрограмму Аргона (T0 ?)
/* if(USO_Booled[3][7]=false&&dynamics.rs<1000){  // Если нет акселерометра и дальность менее 1 км, то...
 cw_b6[11]=1;
 cw_b6[8]=1;
 bfi_strings.str_1=7;
 if(dynamics.sks<0.001&&dynamics.rs<100)bfi_strings.str_1=8; } */ // BILU TEST - LEX 20200406

////////////////////////
// Обработчик ВКЛ ДПО //
if(USO_Booled[10][7]) Label27->Caption=BFI_oper2str[0]; else
if(bfi_strings.str_3==2) Label27->Caption=BFI_oper2str[1]; else
if(bfi_strings.str_3==3) Label27->Caption=BFI_oper2str[2]; else
if(bfi_strings.str_3==4) Label27->Caption=BFI_oper2str[3]; else
Label27->Caption="";

/////////////////////////////////
// Обработчик знакоместа 43.13 //
if(bezop_bfi==0) f43_bezop->Caption=""; else if(bezop_bfi==1) f43_bezop->Caption=BFI_Bezop[0]; else
if(bezop_bfi==2) f43_bezop->Caption=BFI_Bezop[1]; else if(bezop_bfi==3) f43_bezop->Caption=BFI_Bezop[2]; else
if(bezop_bfi==4) f43_bezop->Caption=BFI_Bezop[3]; else if(bezop_bfi==5) f43_bezop->Caption=BFI_Bezop[4]; else
if(bezop_bfi==6) f43_bezop->Caption=BFI_Bezop[5]; else if(bezop_bfi==7) f43_bezop->Caption=BFI_Bezop[6];

////////////////
// Формат Ф43 //
f43_ro->Caption=FormatFloat("00.000",dynamics.rs/1000);                        // Дальность для формата Ф43
if(dynamics.sks<0)
f43_rod->Caption=FormatFloat(" 000.00",-dynamics.sks); else                    // Скорость для формата Ф43
if(dynamics.sks>0)f43_rod->Caption=FormatFloat("000.00",-dynamics.sks); else
if(dynamics.sks==0,000000)f43_rod->Caption=" 000.00";
f43_resurs->Caption=FormatFloat("000.0",dynamics.rasp);                        // Ресур
f43_omzf->Caption=FloatToStr(dynamics.omzx).sprintf("%06.03f",dynamics.omzx);
f43_omyf->Caption=FloatToStr(dynamics.omyx).sprintf("%06.03f",dynamics.omyx);

f46_vtek->Caption=FloatToStr(v_tek_m).sprintf("%06.05f",v_tek_m);
if(cw_b1[12]) f46_tvc->Caption=gc1_time.FormatString("hh.nn.ss"); else
f46_tvc->Caption="00.00.00";
f41_v1v->Caption=FormatFloat("000.00",ArgonMemoryType[41]);
f41_101->Caption=FormatFloat("000.00",ArgonMemoryType[101]);
f41_43->Caption=FormatFloat("#.#####",ArgonMemoryType[43]);
f41_44->Caption=FormatFloat("0.00000",ArgonMemoryType[44]);
f41_45->Caption=FormatFloat("0.00000",ArgonMemoryType[45]);
f41_46->Caption=FormatFloat("0.00000",ArgonMemoryType[46]);

// Обработчик строки ГСО (пересмотреть)
if(GSO_types==0) GSO_String="     "; else
if(GSO_types==1) GSO_String="1    "; else
if(GSO_types==2) GSO_String=" 2   "; else
if(GSO_types==3) GSO_String="  3  "; else
if(GSO_types==4) GSO_String="   4 "; else
if(GSO_types==5) GSO_String="    5";
f42_gso->Caption=GSO_String; f43_gso->Caption=GSO_String;
f44_gso->Caption=GSO_String; f45_gso->Caption=GSO_String;

//////////////////////////////////
// Время Московское (модельное) //
BFI_TimeString = "TN="+OnboardModelTime.FormatString("hh:nn:ss");
f41_time->Caption=BFI_TimeString; f42_time->Caption=BFI_TimeString;
f43_time->Caption=BFI_TimeString; f44_time->Caption=BFI_TimeString;
f45_time->Caption=BFI_TimeString; f46_time->Caption=BFI_TimeString;

// Вывод Т0
if(t_krl_true[0])
f41_t0->Caption="T0="+arg_T0.FormatString("hh:nn:ss"); else
f41_t0->Caption="T0=";

if(t_krl_true[1])
f41_t1->Caption=arg_T1.FormatString("hh:nn:ss"); else
f41_t1->Caption="";

if(t_krl_true[2])
f41_t2->Caption=arg_T2.FormatString("hh:nn:ss"); else
f41_t2->Caption="";

if(t_krl_true[3])
f41_t3->Caption=arg_T3.FormatString("hh:nn:ss"); else
f41_t3->Caption="";
/////////////////////////
// Перевод УС из 2 в 8 //
if(i_takt_asd[1]==2){
cw_B1_string +=(byte)cw_b1[0];  cw_B1_string +=(byte)cw_b1[1];
cw_B1_string +=(byte)cw_b1[2];  cw_B1_string +=(byte)cw_b1[3];
 B1_forDBG[0] += "0";           B1_forDBG[0] +=(byte)cw_b1[1];
 B1_forDBG[0] +=(byte)cw_b1[2]; B1_forDBG[0] +=(byte)cw_b1[3];
cw_B1_string +=(byte)cw_b1[4];  cw_B1_string +=(byte)cw_b1[5];
cw_B1_string +=(byte)cw_b1[6];
 B1_forDBG[1] += "0";           B1_forDBG[1] +=(byte)cw_b1[4];
 B1_forDBG[1] +=(byte)cw_b1[5]; B1_forDBG[1] +=(byte)cw_b1[6];
cw_B1_string +=(byte)cw_b1[7];  cw_B1_string +=(byte)cw_b1[8];
cw_B1_string +=(byte)cw_b1[9];
 B1_forDBG[2] += "0";           B1_forDBG[2] +=(byte)cw_b1[7];
 B1_forDBG[2] +=(byte)cw_b1[8]; B1_forDBG[2] +=(byte)cw_b1[9];
cw_B1_string +=(byte)cw_b1[10]; cw_B1_string +=(byte)cw_b1[11];
cw_B1_string +=(byte)cw_b1[12];
 B1_forDBG[3] += "0";           B1_forDBG[3] +=(byte)cw_b1[10];
 B1_forDBG[3] +=(byte)cw_b1[11];B1_forDBG[3] +=(byte)cw_b1[12];
cw_B1_string +=(byte)cw_b1[13]; cw_B1_string +=(byte)cw_b1[14];
cw_B1_string +=(byte)cw_b1[15];
 B1_forDBG[4] += "0";           B1_forDBG[4] +=(byte)cw_b1[13];
 B1_forDBG[4] +=(byte)cw_b1[14];B1_forDBG[4] +=(byte)cw_b1[15];
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

cw_B10_string +=(byte)cw_b10[0];
cw_B10_string +=(byte)cw_b10[1];
cw_B10_string +=(byte)cw_b10[2];
cw_B10_string +=(byte)cw_b10[3];
 B10_forDBG[0] += "0";
 B10_forDBG[0] +=(byte)cw_b10[1];
 B10_forDBG[0] +=(byte)cw_b10[2];
 B10_forDBG[0] +=(byte)cw_b10[3];
cw_B10_string +=(byte)cw_b10[4];
cw_B10_string +=(byte)cw_b10[5];
cw_B10_string +=(byte)cw_b10[6];
 B10_forDBG[1] += "0";
 B10_forDBG[1] +=(byte)cw_b10[4];
 B10_forDBG[1] +=(byte)cw_b10[5];
 B10_forDBG[1] +=(byte)cw_b10[6];
cw_B10_string +=(byte)cw_b10[7];
cw_B10_string +=(byte)cw_b10[8];
cw_B10_string +=(byte)cw_b10[9];
 B10_forDBG[2] += "0";
 B10_forDBG[2] +=(byte)cw_b10[7];
 B10_forDBG[2] +=(byte)cw_b10[8];
 B10_forDBG[2] +=(byte)cw_b10[9];
cw_B10_string +=(byte)cw_b10[10];
cw_B10_string +=(byte)cw_b10[11];
cw_B10_string +=(byte)cw_b10[12];
 B10_forDBG[3] += "0";
 B10_forDBG[3] +=(byte)cw_b10[10];
 B10_forDBG[3] +=(byte)cw_b10[11];
 B10_forDBG[3] +=(byte)cw_b10[12];
cw_B10_string +=(byte)cw_b10[13];
cw_B10_string +=(byte)cw_b10[14];
cw_B10_string +=(byte)cw_b10[15];
 B10_forDBG[4] += "0";
 B10_forDBG[4] +=(byte)cw_b10[13];
 B10_forDBG[4] +=(byte)cw_b10[14];
 B10_forDBG[4] +=(byte)cw_b10[15];
B10_string[0] = (byte)cw_b10[0];
B10_string[1] = XtoY(Trim(B10_forDBG[0]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B10_string[2] = XtoY(Trim(B10_forDBG[1]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B10_string[3] = XtoY(Trim(B10_forDBG[2]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B10_string[4] = XtoY(Trim(B10_forDBG[3]), StrToIntDef(2, 10), StrToIntDef(16, 10));
B10_string[5] = XtoY(Trim(B10_forDBG[4]), StrToIntDef(2, 10), StrToIntDef(16, 10));
f41_B10->Caption=B10_string[0]+"."+B10_string[1]+""+B10_string[2]+""+B10_string[3]+""+B10_string[4]+""+B10_string[5];
B10_string[0] = "";B10_string[1] = "";B10_string[2] = "";B10_string[3] = "";B10_string[4] = "";B10_string[5] = "";
B10_forDBG[0] = "";B10_forDBG[1] = "";B10_forDBG[2] = "";B10_forDBG[3] = "";B10_forDBG[4] = "";cw_B10_string = "";

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
f43_c->Caption=a19_string[0]+"."+a19_string[1]+""+a19_string[2]+""+a19_string[3]+""+a19_string[4]+""+a19_string[5];
a19_string[0] = "";a19_string[1] = "";a19_string[2] = "";a19_string[3] = "";a19_string[4] = "";a19_string[5] = "";
a19_forDBG[0] = "";a19_forDBG[1] = "";a19_forDBG[2] = "";a19_forDBG[3] = "";a19_forDBG[4] = "";cw_a19_string = "";

cw_R1_string +=(byte)cw_r1[0];
cw_R1_string +=(byte)cw_r1[1];
cw_R1_string +=(byte)cw_r1[2];
cw_R1_string +=(byte)cw_r1[3];
 R1_forDBG[0] += "0";
 R1_forDBG[0] +=(byte)cw_r1[1];
 R1_forDBG[0] +=(byte)cw_r1[2];
 R1_forDBG[0] +=(byte)cw_r1[3];
cw_R1_string +=(byte)cw_r1[4];
cw_R1_string +=(byte)cw_r1[5];
cw_R1_string +=(byte)cw_r1[6];
 R1_forDBG[1] += "0";
 R1_forDBG[1] +=(byte)cw_r1[4];
 R1_forDBG[1] +=(byte)cw_r1[5];
 R1_forDBG[1] +=(byte)cw_r1[6];
cw_R1_string +=(byte)cw_r1[7];
cw_R1_string +=(byte)cw_r1[8];
cw_R1_string +=(byte)cw_r1[9];
 R1_forDBG[2] += "0";
 R1_forDBG[2] +=(byte)cw_r1[7];
 R1_forDBG[2] +=(byte)cw_r1[8];
 R1_forDBG[2] +=(byte)cw_r1[9];
cw_R1_string +=(byte)cw_r1[10];
cw_R1_string +=(byte)cw_r1[11];
cw_R1_string +=(byte)cw_r1[12];
 R1_forDBG[3] += "0";
 R1_forDBG[3] +=(byte)cw_r1[10];
 R1_forDBG[3] +=(byte)cw_r1[11];
 R1_forDBG[3] +=(byte)cw_r1[12];
cw_R1_string +=(byte)cw_r1[13];
cw_R1_string +=(byte)cw_r1[14];
cw_R1_string +=(byte)cw_r1[15];
 R1_forDBG[4] += "0";
 R1_forDBG[4] +=(byte)cw_r1[13];
 R1_forDBG[4] +=(byte)cw_r1[14];
 R1_forDBG[4] +=(byte)cw_r1[15];
R1_string[0] = (byte)cw_r1[0];
R1_string[1] = XtoY(Trim(R1_forDBG[0]), StrToIntDef(2, 10), StrToIntDef(16, 10));
R1_string[2] = XtoY(Trim(R1_forDBG[1]), StrToIntDef(2, 10), StrToIntDef(16, 10));
R1_string[3] = XtoY(Trim(R1_forDBG[2]), StrToIntDef(2, 10), StrToIntDef(16, 10));
R1_string[4] = XtoY(Trim(R1_forDBG[3]), StrToIntDef(2, 10), StrToIntDef(16, 10));
R1_string[5] = XtoY(Trim(R1_forDBG[4]), StrToIntDef(2, 10), StrToIntDef(16, 10));
f41_R1->Caption=R1_string[0]+"."+R1_string[1]+""+R1_string[2]+""+R1_string[3]+""+R1_string[4]+""+R1_string[5];
R1_string[0] = "";R1_string[1] = "";R1_string[2] = "";R1_string[3] = "";R1_string[4] = "";R1_string[5] = "";
R1_forDBG[0] = "";R1_forDBG[1] = "";R1_forDBG[2] = "";R1_forDBG[3] = "";R1_forDBG[4] = "";cw_R1_string = "";

cw_R6_string +=(byte)cw_r6[0];
cw_R6_string +=(byte)cw_r6[1];
cw_R6_string +=(byte)cw_r6[2];
cw_R6_string +=(byte)cw_r6[3];
 R6_forDBG[0] += "0";
 R6_forDBG[0] +=(byte)cw_r6[1];
 R6_forDBG[0] +=(byte)cw_r6[2];
 R6_forDBG[0] +=(byte)cw_r6[3];
cw_R6_string +=(byte)cw_r6[4];
cw_R6_string +=(byte)cw_r6[5];
cw_R6_string +=(byte)cw_r6[6];
 R6_forDBG[1] += "0";
 R6_forDBG[1] +=(byte)cw_r6[4];
 R6_forDBG[1] +=(byte)cw_r6[5];
 R6_forDBG[1] +=(byte)cw_r6[6];
cw_R6_string +=(byte)cw_r6[7];
cw_R6_string +=(byte)cw_r6[8];
cw_R6_string +=(byte)cw_r6[9];
 R6_forDBG[2] += "0";
 R6_forDBG[2] +=(byte)cw_r6[7];
 R6_forDBG[2] +=(byte)cw_r6[8];
 R6_forDBG[2] +=(byte)cw_r6[9];
cw_R6_string +=(byte)cw_r6[10];
cw_R6_string +=(byte)cw_r6[11];
cw_R6_string +=(byte)cw_r6[12];
 R6_forDBG[3] += "0";
 R6_forDBG[3] +=(byte)cw_r6[10];
 R6_forDBG[3] +=(byte)cw_r6[11];
 R6_forDBG[3] +=(byte)cw_r6[12];
cw_R6_string +=(byte)cw_r6[13];
cw_R6_string +=(byte)cw_r6[14];
cw_R6_string +=(byte)cw_r6[15];
 R6_forDBG[4] += "0";
 R6_forDBG[4] +=(byte)cw_r6[13];
 R6_forDBG[4] +=(byte)cw_r6[14];
 R6_forDBG[4] +=(byte)cw_r6[15];
R6_string[0] = (byte)cw_r6[0];
R6_string[1] = XtoY(Trim(R6_forDBG[0]), StrToIntDef(2, 10), StrToIntDef(16, 10));
R6_string[2] = XtoY(Trim(R6_forDBG[1]), StrToIntDef(2, 10), StrToIntDef(16, 10));
R6_string[3] = XtoY(Trim(R6_forDBG[2]), StrToIntDef(2, 10), StrToIntDef(16, 10));
R6_string[4] = XtoY(Trim(R6_forDBG[3]), StrToIntDef(2, 10), StrToIntDef(16, 10));
R6_string[5] = XtoY(Trim(R6_forDBG[4]), StrToIntDef(2, 10), StrToIntDef(16, 10));
f41_R6->Caption=R6_string[0]+"."+R6_string[1]+""+R6_string[2]+""+R6_string[3]+""+R6_string[4]+""+R6_string[5];
R6_string[0] = "";R6_string[1] = "";R6_string[2] = "";R6_string[3] = "";R6_string[4] = "";R6_string[5] = "";
R6_forDBG[0] = "";R6_forDBG[1] = "";R6_forDBG[2] = "";R6_forDBG[3] = "";R6_forDBG[4] = "";cw_R6_string = "";



i_takt_asd[1]=0;
} else i_takt_asd[1]++;

}
//---------------------------------------------------------------------------
void __fastcall TBFI_Simvol_form::formatsChange(TObject *Sender)
{
// Send to InPU cmd 41 change format BFI
struct{
byte CodeType;
unsigned short DataType;
}packet;
CounterNo++;                                        // Номер пакета +1
PacketHeaderType.Signature = PacketSignatureR;      // Сигнатура пакета
PacketHeaderType.No = CounterNo;                    // Номер пакета
PacketHeaderType.Size = sizeof(wpControlCodeTypeN); // Размер пакета = размер буфера УСО
PacketHeaderType.PacketID = PacketIDtype(idControl);    // USO
packet.CodeType = wpControlCodeTypeN(wpBfiFormat);
packet.DataType = 1;
nResult = send(SPSSocket_ch1,(char *)&PacketHeaderType,9, 0  );
nResult = send(SPSSocket_ch1,(char *)&packet,6, 0  );
}
//---------------------------------------------------------------------------

