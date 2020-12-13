//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "graph_a1.h"
#include "kdu_math.h"
#include "arg_header.h"
#include "SPSHead.h"
#include "miscdata/rdc_draph.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tgraphics *graphics;
static int shhh;
static int i_fds;
static int shag_a;
//---------------------------------------------------------------------------
__fastcall Tgraphics::Tgraphics(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------



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


