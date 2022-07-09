 //---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "kdu_data.h"
#include "kdu_math.h"
//#include "math.hpp"
#include "JouHeader.h"
#include "JouStrings.h"
#include "irvi_brfi_frm.cpp"
#include "argon/arg_header.h"
#include "argon/CtrlWord.h"
#include "SPSHead.h"
// �������� - ��� �� ��� + ��������� ����������
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKDUform *KDUform;
//---------------------------------------------------------------------------
static double skd_sec_ras = 0.535;
static double rhb1_sim = 278.7;
static double rhb2_sim = 277.9;
static bool skd_on_pr;
static innn;

static double xxx;
static TDateTime TimeSKD;
static double v_p;
static int upp;

static bool SkdOnPr;
static int timeed;

static double v_tek;

void RashModel(){
// �������� ������ ���
// ���������� ���������� ������� �������� ������
// �� ����� �� � ������������ ���
dynamics.rasp = dynamics.rasp - 0.535; // ����������� ������ ��� 0.535 ��
if(skd_on_pr)dynamics.rasp_skd = dynamics.rasp_skd - skd_sec_ras;
// ����� //
KDUform->skd_rash->Caption=FormatFloat("000.00",dynamics.rasp_skd);
KDUform->dpo_rash->Caption=FormatFloat("000.00",dynamics.rasp_dpo);
}

//---------------------------------------------------------------------------
__fastcall TKDUform::TKDUform(TComponent* Owner)
        : TForm(Owner)
{
KDUform->Position=poDesktopCenter;
}
//---------------------------------------------------------------------------



void __fastcall TKDUform::skd_startClick(TObject *Sender)
{
cw_a3[0]=1;  // ���������� ������� "��� ���."
JPS(1,is_sudn,is_operator,"��������� ���     ","");
Timer2->Enabled=1;
}
//---------------------------------------------------------------------------

void __fastcall TKDUform::SpeedButton2Click(TObject *Sender)
{
Timer1->Enabled=false;
Timer2->Enabled=false;
cw_a3[0]=0;  // ���������� ������� "��� ����."
cw_a3[1]=0;  // ���������� ������� "��� ����."
}
//---------------------------------------------------------------------------

void __fastcall TKDUform::Button2Click(TObject *Sender)
{

rhb1_sim = rhb1_sim - skd_sec_ras;
rhb1->Caption=FloatToStr(rhb1_sim);
}
//---------------------------------------------------------------------------

void __fastcall TKDUform::Button3Click(TObject *Sender)
{
rhb1_sim = 100;
}
//---------------------------------------------------------------------------

void __fastcall TKDUform::Timer2Timer(TObject *Sender)
{
if(tpl>0.000){
rash = rash + 1.0700006024;              // ������� ������ �������
tk_mass = tk_mass - 1.0700006024;        // ������ ������� ����� �������
v_tek= v_tek + (2951.8016/StrToFloat(tk_mass));     // ������ V���  2951.8016
Label60->Caption=v_tek;
v_tek_m = v_tek;
timeed++;
Label14->Caption=IntToStr(timeed);
Label12->Caption=TimeSKD++;
 data_vtek = v_tek;
 data_num_t = timeed;
fuel_ost->Caption=dynamics.rasp;
//Label51->Caption=dynamics.rasp;
upp--;
Label68->Caption=upp;
}
if(v_tek>v_p){
 JPS(1,is_sudn,is_operator,"���������� ���     ","");
 Timer2->Enabled=false;
 Timer1->Enabled=false;
         // ��� ��� "������ ���"
        ts4_6->Color=clBlack;
        ts4_6->Font->Color=clOlive; }
if(IrBrForm->Panel1->Color==clLime){
  IrBrForm->i1->Caption="0";
  IrBrForm->i2->Caption="0";
  IrBrForm->i3->Caption="3";
}
}
//---------------------------------------------------------------------------

void __fastcall TKDUform::BitBtn1Click(TObject *Sender)
{
Tskd->Date=OnboardModelTime.DateString();
data_TSKD = Tskd->Time;
}
//---------------------------------------------------------------------------

void __fastcall TKDUform::USO_Otr_TimerTimer(TObject *Sender)
{

fuel_ost->Caption=FloatToStr(dynamics.rasp);         // ������������ ������� �������

///////////////////
// Fuel from RUD //
///////////////////
rud_rash->Caption=FloatToStr(dynamics.rudkg);

if(USO_Booled[10][7]){
 ts4_5->Color=clLime;
 ts4_5->Font->Color=clBlack; } else {
 ts4_5->Font->Color=clOlive;
 ts4_5->Color=clBlack;
}

if(USO_Booled[0][1]){
NadduvKdu->Color=clLime;
NadduvKdu->Font->Color=clBlack; } else {
NadduvKdu->Font->Color=clOlive;
NadduvKdu->Color=clBlack;
}
if(ych_Rg15[0]){ // ���� ���� ������� �� ��������� ���
skd_on_pr=1;
//cw_a4[0]=1;
//cw_a4[2]=1;
USO_Booled[10][10] = 1;

ych_Rg15[0]=0;
}
// ���������� �������� "������ ���"
if(USO_Booled[10][10]) {
if(skd_on_pr){
JPS(2,is_miu,is_operator,"������ ���        ","���");   // ���� �������� ���� ��� �� �����
work_st = true;
SkdOnPr=true;                         // ������� "��� ���"
tk_mass = StrToFloat(Edit1->Text);    // ��������� ����� ��
mass_tpk->Caption=FloatToStr(tk_mass);// ������� ����� �� � �����
timeed = 0;                           // �������� �������
Timer1->Enabled=true;
Timer2->Enabled=true;
TimeSKD = Tskd->Time;                 // ����������� ����� � ����
tpl =StrToFloat(fuel->Text);
        // ��� ��� "������ ���"

v_p = StrToFloat(tormimp->Text);
Label66->Caption=FloatToStr(v_p);
upp = 1/(int)(v_p);
Label68->Caption=upp;
Label63->Caption = FloatToStr(tk_mass);  // ������� ����� �������
attitude = Edit2->Text.ToDouble();       // ������

g_tt =  fff*(e_mass/pow((Rz+attitude),2));                                 // ������ ��������� ���������� �������
Label74->Caption=FloatToStr(g_tt);
skd_H = 300*g_tt;
skd_on_pr=0;
} else {
}
ts4_6->Color=clLime;
ts4_6->Font->Color=clBlack; } else {
ts4_6->Font->Color=clOlive;
ts4_6->Color=clBlack;
}

}
//---------------------------------------------------------------------------


void __fastcall TKDUform::BitBtn2Click(TObject *Sender)
{
deltavt_1 = StrToFloat(tormimp->Text);
// ���� ���, ���� �� ������ ���
// �������������� �������
if(ArgonMemoryType[41]==0.0) ArgonMemoryType[41] = StrToFloat(tormimp->Text); else
ArgonMemoryType[101] = StrToFloat(tormimp->Text);
}
//---------------------------------------------------------------------------



void __fastcall TKDUform::FormCreate(TObject *Sender)
{
SDR1_label->Hint="������ = 24 ���/��2 \n     ";
SDR2_label->Hint="������ = 24 ���/��2 \n     ";
DRO1_label->Hint="������ ������� ���������� \n������: 000.00 ��";
DRG1_label->Hint="������ ������� �������� \n������: 000.00 ��";
}
//---------------------------------------------------------------------------



void __fastcall TKDUform::sps_dataTimer(TObject *Sender)
{
kdu_dhb1->Caption=FormatFloat("000.000",SpsDataSt.TSpsParam[21]);
kdu_dhb2->Caption=FormatFloat("000.000",SpsDataSt.TSpsParam[22]);
Label113->Caption=FormatFloat("000.000",SpsDataSt.TSpsParam[25]);
Label116->Caption=FormatFloat("000.000",SpsDataSt.TSpsParam[26]);
Label114->Caption=FormatFloat("000.000",SpsDataSt.TSpsParam[31]);
Label115->Caption=FormatFloat("000.000",SpsDataSt.TSpsParam[32]);
}
//---------------------------------------------------------------------------

void __fastcall TKDUform::kdu_math_tTimer(TObject *Sender)
{
// ��������� � ������ ���
// �������� �������� ��� ���������� �������� ������� � � �
// ������ ����������� �� ���� ��������, ������� ������� ��������� ���.
// �������� ���������� �� ������� �������
if(USO_Booled[0][1]){ // ���� ���� ������� �������� ������� ������ ��� (��32), ��...
// ��������� ���� ��������� ������
if(SpsDataSt.TSpsParam[25]<14&&SpsDataSt.TSpsParam[31]<14){                         // ���� �������� � ����� � � � ������ ���������, ��
SpsDataSt.TSpsParam[21] = SpsDataSt.TSpsParam[21] - 0.01;        // �������� �� ����� �������
SpsDataSt.TSpsParam[25] = SpsDataSt.TSpsParam[25] + 0.200745;
//SpsDataSt.TSpsParam[25] = math_nad
SpsDataSt.TSpsParam[31] = SpsDataSt.TSpsParam[31] + 0.200753;
}
}
}
//---------------------------------------------------------------------------



////////////////////////////////////////////////
// ��������� ��������� ��� ������������� ���  //
////////////////////////////////////////////////
/*

   ������� ���������� ����� = 2078 (������ / (��������� � �������))

   ��������� �����	0.179 (????????? / ???? 3)

   

*/

/* ������� ������ ������� ��� */
void __fastcall TKDUform::kdu_timerTimer(TObject *Sender)
{
rash_ob->Caption=FormatFloat("000.000",dynamics.rasp);              // ������ ����� (��)
Label42->Caption=FormatFloat("000.000000000000000",dynamics.rudkg);
Label49->Caption=FormatFloat("000.000000000000000",dynamics.kvkg);
/* �������� ������ ��� (������ ����������)
����� ���     ������� �� �����            */
dpo1->Visible=dpo_v_pr[1];      dpo2->Visible=dpo_v_pr[2];
dpo3->Visible=dpo_v_pr[3];      dpo4->Visible=dpo_v_pr[4];
dpo5->Visible=dpo_v_pr[5];      dpo6->Visible=dpo_v_pr[6];
dpo7->Visible=dpo_v_pr[7];      dpo8->Visible=dpo_v_pr[8];
dpo9->Visible=dpo_v_pr[9];      dpo10->Visible=dpo_v_pr[10];
dpo11->Visible=dpo_v_pr[11];    dpo12->Visible=dpo_v_pr[12];
dpo12->Visible=dpo_v_pr[13];    dpo14->Visible=dpo_v_pr[14];
dpo15->Visible=dpo_v_pr[15];    dpo16->Visible=dpo_v_pr[16];
dpo17->Visible=dpo_v_pr[17];    dpo18->Visible=dpo_v_pr[18];
dpo19->Visible=dpo_v_pr[19];    dpo20->Visible=dpo_v_pr[20];
dpo21->Visible=dpo_v_pr[21];    dpo22->Visible=dpo_v_pr[22];
dpo23->Visible=dpo_v_pr[23];    dpo24->Visible=dpo_v_pr[24];
dpo25->Visible=dpo_v_pr[25];    dpo26->Visible=dpo_v_pr[26];
dpo27->Visible=dpo_v_pr[27];    dpo28->Visible=dpo_v_pr[28];

}
//---------------------------------------------------------------------------







