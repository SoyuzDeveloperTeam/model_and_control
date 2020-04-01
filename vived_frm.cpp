//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "vived_frm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tliftoff_form *liftoff_form;
int d;

//---------------------------------------------------------------------------
__fastcall Tliftoff_form::Tliftoff_form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tliftoff_form::FormShow(TObject *Sender)
{
Chart1->BottomAxis->SetMinMax(0,525);
Chart1->LeftAxis->SetMinMax(0,210);
Series2->AddXY(0,0,clBlack);
Series2->AddXY(10,1.5,clBlack);
Series2->AddXY(20,3,clBlack);
Series2->AddXY(30,4,clBlack);
Series2->AddXY(40,5,clBlack);
Series2->AddXY(50,7,clBlack);
Series2->AddXY(60,10,clBlack);
Series2->AddXY(70,14,clBlack);
Series2->AddXY(80,20,clBlack);
Series2->AddXY(90,26,clBlack);
Series2->AddXY(100,33,clBlack);
Series2->AddXY(110,42,clBlack);
Series2->AddXY(120,50,clBlack);
Series2->AddXY(130,59,clBlack);
Series2->AddXY(140,68,clBlack);
Series2->AddXY(150,76,clBlack);
Series2->AddXY(160,84,clBlack);
Series2->AddXY(170,92,clBlack);
Series2->AddXY(180,99,clBlack);
Series2->AddXY(190,105,clBlack);
Series2->AddXY(200,113,clBlack);
Series2->AddXY(210,119,clBlack);
Series2->AddXY(220,126,clBlack);
Series2->AddXY(230,132,clBlack);
Series2->AddXY(240,139,clBlack);
Series2->AddXY(250,146,clBlack);
Series2->AddXY(260,151,clBlack);
Series2->AddXY(270,158,clBlack);
Series2->AddXY(280,165,clBlack);
Series2->AddXY(290,170,clBlack);
Series2->AddXY(300,176,clBlack);

Series2->AddXY(310,182,clBlack);
Series2->AddXY(320,187,clBlack);
Series2->AddXY(330,191,clBlack);
Series2->AddXY(340,195,clBlack);
Series2->AddXY(350,198,clBlack);
Series2->AddXY(360,200,clBlack);
Series2->AddXY(370,202,clBlack);
Series2->AddXY(380,204,clBlack);
Series2->AddXY(390,205,clBlack);
Series2->AddXY(400,206,clBlack);
Series2->AddXY(410,207,clBlack);
Series2->AddXY(420,207,clBlack);
Series2->AddXY(430,208,clBlack);
Series2->AddXY(440,208,clBlack);
Series2->AddXY(450,208,clBlack);
Series2->AddXY(460,207,clBlack);
Series2->AddXY(470,207,clBlack);
Series2->AddXY(480,206.5,clBlack);
Series2->AddXY(490,206,clBlack);
Series2->AddXY(500,205,clBlack);
Series2->AddXY(510,205,clBlack);
Series2->AddXY(520,205,clBlack);
}
//---------------------------------------------------------------------------

void __fastcall Tliftoff_form::Button1Click(TObject *Sender)
{
//Series1->GetVertAxis->CalcYPosValue(50);
Series1->Clear();
//Series1->AddXY(d,Series1->YValues ,clBlack);
Label3->Caption=IntToStr(Series1->XValues);
}
//---------------------------------------------------------------------------


void __fastcall Tliftoff_form::Timer1Timer(TObject *Sender)
{
d++;
Series1->Clear();
//Series1->AddXY(d,Series1->XValues[0],clBlack);
}
//---------------------------------------------------------------------------

