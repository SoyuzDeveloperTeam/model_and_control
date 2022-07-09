//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "graph_a1.h"
#include "kdu_math.h"
#include "arg_header.h"
#include "SPSHead.h"
#include "miscdata/rdc_draph.cpp"
#include "ssvp_module.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tgraphics *graphics;
static int shhh;
static int i_fds;
static int shag_a;
TDateTime myDate;
static int t_time;
//---------------------------------------------------------------------------
__fastcall Tgraphics::Tgraphics(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void ssvp_work(){
        if(s_pos>=0) graphics->ssvp_sh->Left=60;
        if(s_pos>=25) graphics->ssvp_sh->Left=65;
        if(s_pos>=50) graphics->ssvp_sh->Left=70;
        if(s_pos>=75) graphics->ssvp_sh->Left=75;
        if(s_pos>=101) graphics->ssvp_sh->Left=80;
        if(s_pos>=126) graphics->ssvp_sh->Left=85;
        if(s_pos>=151) graphics->ssvp_sh->Left=90;
        if(s_pos>=176) graphics->ssvp_sh->Left=95;
        if(s_pos>=202) graphics->ssvp_sh->Left=100;
        if(s_pos>=226) graphics->ssvp_sh->Left=105;
        if(s_pos>=252) graphics->ssvp_sh->Left=110;
        if(s_pos>=276) graphics->ssvp_sh->Left=115;
        if(s_pos>=303) graphics->ssvp_sh->Left=120;
        if(s_pos>=327) graphics->ssvp_sh->Left=125;
        if(s_pos>=353) graphics->ssvp_sh->Left=130;
        if(s_pos>=377) graphics->ssvp_sh->Left=135;
        if(s_pos==404) graphics->ssvp_sh->Left=142;
}

/*
  60  64  68  72  76  80  84  88  92  96  100  104  108  112  116  120  124  128  132  136  140  144  148  152  156

  0                   101                 202                      303                      7

  */

void __fastcall Tgraphics::Timer1Timer(TObject *Sender)
{
i_fds++;
if(work_st){
if(gr_inter->Checked){
shhh = Sh->Text.ToInt();
Chart1->BottomAxis->SetMinMax(data_num_t-shhh,data_num_t);
Chart2->BottomAxis->SetMinMax(data_num_t-shhh,data_num_t);
Chart4->BottomAxis->SetMinMax(data_num_t-shhh,data_num_t);
Chart5->BottomAxis->SetMinMax(data_num_t-shhh,data_num_t);}
Label1->Caption=tk_mass;
Label6->Caption=data_vtek;
Chart1 -> Series[0] -> AddXY(data_num_t ,data_vtek, "", clBlue);
Chart2 -> Series[0] -> AddXY(data_num_t ,tk_mass, "", clLime);
Chart4 -> Series[0] -> AddXY(data_num_t ,rash, "", clLime);
Chart5 -> Series[0] -> AddXY(data_num_t ,tpl, "", clRed);
//Chart6->Series[0]->AddXY(i_fds,TSpsParam[23], "", clLime);
}



}
//---------------------------------------------------------------------------

void __fastcall Tgraphics::N1Click(TObject *Sender)
{
Chart4->CopyToClipboardBitmap();
}
//---------------------------------------------------------------------------

void __fastcall Tgraphics::MenuItem1Click(TObject *Sender)
{
Chart1->CopyToClipboardBitmap();
}
//---------------------------------------------------------------------------


void __fastcall Tgraphics::Timer2Timer(TObject *Sender)
{
// DATE TIME //


// CHK BTN //
if(RadioButton1->Checked)  shag_a = 500;   else
if(RadioButton2->Checked)  shag_a = 300;   else
if(RadioButton3->Checked)  shag_a = 150;   else
if(RadioButton4->Checked)  shag_a = 100;   else
if(RadioButton5->Checked)  shag_a = 50;    else
if(RadioButton6->Checked)  shag_a = 10;    else
if(RadioButton7->Checked)  shag_a = 5;     else
if(RadioButton8->Checked)  shag_a = 1;     else
if(RadioButton9->Checked)  shag_a = 10000; else
if(RadioButton10->Checked) shag_a = 15000; else
if(RadioButton11->Checked) shag_a = 30000; else
if(RadioButton13->Checked) shag_a = 1000;  else
if(RadioButton14->Checked) shag_a = 2500;  else
if(RadioButton15->Checked) shag_a = 5000;  else
if(RadioButton16->Checked) shag_a = 6000;
if(!sled->Checked){   // Обработчик признака "след от трассы"
 Series9->Clear();
 Series6->Clear();    // Очищаем предыдущую позицию маркера
}
Chart7->BottomAxis->SetMinMax(shag_a,-shag_a);
Chart7->LeftAxis->SetMinMax(shag_a,-shag_a);
//                            Ymin   Ymax
Chart8->BottomAxis->SetMinMax(shag_a,-shag_a);
//                          Xmin  Xmax
Chart8->LeftAxis->SetMinMax( -1 , shag_a);

Series6->AddXY(dynamics.zpr,dynamics.ypr,"", clGreen);   // Sy, Sz
Series9->AddXY(dynamics.zpr,dynamics.rs,"", clGreen);   // Sy, Sz

//Series9->AddBubble(30, 30, 1, "", clRed);

// S S V P //
ssvp_work();
//ssvp_chart1->BottomAxis->Minimum = Now();
//ssvp_chart1->BottomAxis->Maximum = IncMinute(Now(), 3);
//hsh_line->AddXY(dynamics.zpr,Now(),"", clGreen); //Ход штанги ССВП
s_pos = TrackBar1->Position;
ssvp_chart1->Series[0]->AddXY(data_num_t ,s_pos, "", clLime);
}
//---------------------------------------------------------------------------


void __fastcall Tgraphics::FormShow(TObject *Sender)
{
//Series10->AddArrow(-2,0,-15,0,clBlue);
//Series10->AddArrow(2,0,15,0,clBlue);
Series7->AddXY(0,0,"", clBlue);                // Null Центр конуса стыковочного узла
Series8->AddXY(0,0,"", clBlue);                // Null Центр конуса стыковочного узла
}
//---------------------------------------------------------------------------

void __fastcall Tgraphics::SpeedButton1Click(TObject *Sender)
{
double x, y;
x = StrToFloat(Edit1->Text);
y = StrToFloat(Edit2->Text);
Series12->AddXY(x,y,"", clBlue);
}
//---------------------------------------------------------------------------






void __fastcall Tgraphics::TrackBar1Change(TObject *Sender)
{
//TrackBar1->Position;
}
//---------------------------------------------------------------------------

void __fastcall Tgraphics::Timer3Timer(TObject *Sender)
{
if(shtanga_w)
t_time++;
}
//---------------------------------------------------------------------------

void __fastcall Tgraphics::Button1Click(TObject *Sender)
{
t_time=0;        
}
//---------------------------------------------------------------------------

void __fastcall Tgraphics::Button2Click(TObject *Sender)
{
shtanga_w=1;
}
//---------------------------------------------------------------------------

