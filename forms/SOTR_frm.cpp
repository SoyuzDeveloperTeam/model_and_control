//---------------------------------------------------------------------------
// model timer
#include <vcl.h>
#pragma hdrstop

#include "SOTR_frm.h"
#include "sotr_model.cpp"
#include "sotr_data.h"
#include "SPSHead.h"
#include "USOData.h"
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tsotr *sotr;

//---------------------------------------------------------------------------
__fastcall Tsotr::Tsotr(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Label59Click(TObject *Sender)
{
rrg_pr[0] = true;
rrg_pr[1] = false;
rrg_pr[2] = false;
rrg_8->Visible=false;
rrg_16->Visible=false;
rrg_4->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Label60Click(TObject *Sender)
{
rrg_pr[0] = false;
rrg_pr[1] = true;
rrg_pr[2] = false;
rrg_8->Visible=true;
rrg_16->Visible=false;
rrg_4->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Label75Click(TObject *Sender)
{
rrg_pr[0] = false;
rrg_pr[1] = false;
rrg_pr[2] = true;
rrg_8->Visible=false;
rrg_16->Visible=true;
rrg_4->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Label76Click(TObject *Sender)
{
str_off_pc->Visible = true;
str_min_pc->Visible = false;
str_max_pc->Visible = false;
str_pr[0] = true;
str_pr[1] = false;
str_pr[2] = false;
}
//---------------------------------------------------------------------------



void __fastcall Tsotr::Label82Click(TObject *Sender)
{
cond_bo->Visible=true;
cond_sa->Visible=false;
cond[0]=true;
cond[1]=false;
}
//---------------------------------------------------------------------------


void __fastcall Tsotr::vsa_offClick(TObject *Sender)
{
vsa_off->Visible=false;
vsa_on->Visible=true;
vsa_pr=true;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::vsa_onClick(TObject *Sender)
{
vsa_off->Visible=true;
vsa_on->Visible=false;
vsa_pr=false;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::vent_vsk_offClick(TObject *Sender)
{
vent_vsk_off->Visible=false;
vent_vsk_on->Visible=true;
vent_vsk_pr=true;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::vent_vsk_onClick(TObject *Sender)
{
vent_vsk_off->Visible=true;
vent_vsk_on->Visible=false;
vent_vsk_pr=false;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::en_vsk_offClick(TObject *Sender)
{
en_vsk_off->Visible=false;
en_vsk_on->Visible=true;
en_vsk_pr=true;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::en_vsk_onClick(TObject *Sender)
{
en_vsk_off->Visible=true;
en_vsk_on->Visible=false;
en_vsk_pr=false;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Label79Click(TObject *Sender)
{
str_off_pc->Visible = false;
str_min_pc->Visible = true;
str_max_pc->Visible = false;
str_pr[0] = false;
str_pr[1] = true;
str_pr[2] = false;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Label80Click(TObject *Sender)
{
str_off_pc->Visible = false;
str_min_pc->Visible = false;
str_max_pc->Visible = true;
str_pr[0] = false;
str_pr[1] = false;
str_pr[2] = true;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Label83Click(TObject *Sender)
{
cond_bo->Visible=false;
cond_sa->Visible=true;
cond[0]=false;
cond[1]=true;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::modelTimer(TObject *Sender)
{
//bymass++;
//balon_sa->Caption=FloatToSrt(SpsDataSt.TSpsParam[20]);

//if(i_takt==0){
 //TSpsParam[23]=740;
 //i_takt=1;
//}
if(!ksd_pr[2])
{
 //SPS_DataType.P_bo=10*(sin(SPS_DataType.P_bo));
 //bo_pressure->Caption=SPS_DataType.P_bo;
}
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Image3Click(TObject *Sender)
{
ksd_eu->Visible=false;
ksd_open->Visible=true;
ksd_close->Visible=false;
ksd_pr[0]=false;
ksd_pr[1]=true;
ksd_pr[2]=false;
}
//---------------------------------------------------------------------------


void __fastcall Tsotr::Image2Click(TObject *Sender)
{
ksd_eu->Visible=true;
ksd_open->Visible=false;
ksd_close->Visible=false;
ksd_pr[0]=true;
ksd_pr[1]=false;
ksd_pr[2]=false;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Image4Click(TObject *Sender)
{
ksd_eu->Visible=false;
ksd_open->Visible=false;
ksd_close->Visible=true;
ksd_pr[0]=false;
ksd_pr[1]=false;
ksd_pr[2]=true;
}
//---------------------------------------------------------------------------


void __fastcall Tsotr::input_sps_dataClick(TObject *Sender)
{
TSpsDataN[13]=StrToFloat(Tsa_input->Text);
TSpsDataN[10]=StrToFloat(Tbo_input->Text);
TSpsDataN[12]=StrToFloat(Tpo_input->Text);
TSpsDataN[19]=StrToFloat(Psa_input->Text);
// и  далее весь СПС по такому же принципу
}
//---------------------------------------------------------------------------





void __fastcall Tsotr::USOTimerTimer(TObject *Sender)
{
if(USO_Booled[9][10])
        {
         ts2_5->Color=clRed;
        } else ts2_5->Color=clMaroon;
if(USO_Booled[9][13])
        {
         ts2_6->Color=clRed;
        } else ts2_6->Color=clMaroon;

}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Button1Click(TObject *Sender)
{
KSP_Booled[14][2]=true;
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Button2Click(TObject *Sender)
{
KSP_Booled[14][3]=true;        
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Button4Click(TObject *Sender)
{
KSP_Booled[14][4]=true;        
}
//---------------------------------------------------------------------------

void __fastcall Tsotr::Button3Click(TObject *Sender)
{
KSP_Booled[14][5]=true;        
}
//---------------------------------------------------------------------------


