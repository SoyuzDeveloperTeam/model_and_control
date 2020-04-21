//---------------------------------------------------------------------------
// timer 1
#include <vcl.h>
#pragma hdrstop

#include "zakon_upr.h"
#include "argon/arg_header.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tzakon_upr_frm *zakon_upr_frm;
/////////////
// Р Я Д Ы //
/////////////
int i_chart;
int i_axis;
//---------------------------------------------------------------------------
__fastcall Tzakon_upr_frm::Tzakon_upr_frm(TComponent* Owner)
        : TForm(Owner)
{


}
//---------------------------------------------------------------------------

void __fastcall Tzakon_upr_frm::FormCreate(TObject *Sender)
{
zakon_uprav->BottomAxis->SetMinMax(0,6000);
zakon_uprav->LeftAxis->SetMinMax(-6,14);
zakon_uprav->Series[6]->AddXY(0, 0, clBlue);
zakon_uprav->Series[6]->AddXY(6000, 0, clBlue);


}
//---------------------------------------------------------------------------
void __fastcall Tzakon_upr_frm::N2Click(TObject *Sender)
{
for(i_chart; i_chart<=31; i_chart++){
zakon_uprav->Series[0]->AddXY(r_m[i_chart], v_b1b2[i_chart], clRed);
zakon_uprav->Series[1]->AddXY(r_m[i_chart], v_k1k2[i_chart], clMaroon);
zakon_uprav->Series[2]->AddXY(r_m[i_chart], v_half_k1k2[i_chart], clRed);
zakon_uprav->Series[3]->AddXY(r_m[i_chart], v_verch[i_chart], clYellow);
zakon_uprav->Series[4]->AddXY(r_m[i_chart], v_sred[i_chart], clGreen);
zakon_uprav->Series[5]->AddXY(r_m[i_chart], v_niz[i_chart], clYellow);
}

}
//---------------------------------------------------------------------------
void __fastcall Tzakon_upr_frm::FormShow(TObject *Sender)
{
for(i_chart; i_chart<=31; i_chart++){
zakon_uprav->Series[0]->AddXY(r_m[i_chart], v_b1b2[i_chart], clRed);
zakon_uprav->Series[1]->AddXY(r_m[i_chart], v_k1k2[i_chart], clMaroon);
zakon_uprav->Series[2]->AddXY(r_m[i_chart], v_half_k1k2[i_chart], clRed);
zakon_uprav->Series[3]->AddXY(r_m[i_chart], v_verch[i_chart], clYellow);
zakon_uprav->Series[4]->AddXY(r_m[i_chart], v_sred[i_chart], clGreen);
zakon_uprav->Series[5]->AddXY(r_m[i_chart], v_niz[i_chart], clYellow);
}        
}
//---------------------------------------------------------------------------
void __fastcall Tzakon_upr_frm::MainFormN3001Click(TObject *Sender)
{
zakon_uprav->BottomAxis->SetMinMax(0,300);
zakon_uprav->LeftAxis->SetMinMax(-1,2);
zakon_uprav->Series[6]->AddXY(0, -1, clBlue);
zakon_uprav->Series[6]->AddXY(300, -1, clBlue);
}
//---------------------------------------------------------------------------
void __fastcall Tzakon_upr_frm::N7501Click(TObject *Sender)
{
zakon_uprav->BottomAxis->SetMinMax(0,750);
zakon_uprav->LeftAxis->SetMinMax(-2.5,5);
zakon_uprav->Series[6]->AddXY(0, -2.5, clBlue);
zakon_uprav->Series[6]->AddXY(750, -2.5, clBlue);
}
//---------------------------------------------------------------------------
void __fastcall Tzakon_upr_frm::N15001Click(TObject *Sender)
{
zakon_uprav->BottomAxis->SetMinMax(0,1500);
zakon_uprav->LeftAxis->SetMinMax(-5,10);
zakon_uprav->Series[6]->AddXY(0, -5, clBlue);
zakon_uprav->Series[6]->AddXY(1500, -5, clBlue);
}
//---------------------------------------------------------------------------
void __fastcall Tzakon_upr_frm::N30001Click(TObject *Sender)
{
zakon_uprav->BottomAxis->SetMinMax(0,3000);
zakon_uprav->LeftAxis->SetMinMax(-5,10);
zakon_uprav->Series[6]->AddXY(0, -5, clBlue);
zakon_uprav->Series[6]->AddXY(3000, -5, clBlue);
}
//---------------------------------------------------------------------------
void __fastcall Tzakon_upr_frm::N60001Click(TObject *Sender)
{
zakon_uprav->BottomAxis->SetMinMax(0,6000);
zakon_uprav->LeftAxis->SetMinMax(-6,14);
zakon_uprav->Series[6]->AddXY(0, -6, clBlue);
zakon_uprav->Series[6]->AddXY(6000, -6, clBlue);
}
//---------------------------------------------------------------------------
void __fastcall Tzakon_upr_frm::Timer1Timer(TObject *Sender)
{
//dopusk_zu.b1b2 = zakon_uprav->Series[0]->YValue(zakon_uprav->Series[7]->);
//dopusk_zu.k1k2 = zakon_uprav->Series[1]->YValue;
//dopusk_zu.halfk = zakon_uprav->Series[2]->YValue;
//dopusk_zu.verch = zakon_uprav->Series[3]->YValue;
//dopusk_zu.sred = zakon_uprav->Series[4]->YValue;
//dopusk_zu.niz = zakon_uprav->Series[5]->YValue;
Series8->Clear();
if(dynamics.sks>0,00001)
zakon_uprav->Series[7]->AddXY(dynamics.rs, dynamics.sks, clGreen); else  // Трасса ТК (при ск на сближение)
zakon_uprav->Series[10]->AddXY(dynamics.rs, dynamics.sks, clGreen);      // Трасса ТК (при ск на расхождение)
zakon_uprav->Series[8]->AddXY(dynamics.rs, dynamics.sks, clGreen);       // Маркер ТК
}
//---------------------------------------------------------------------------
void __fastcall Tzakon_upr_frm::Button1Click(TObject *Sender)
{
Series7->Clear();
Series9->Clear();
Series10->Clear();
}
//---------------------------------------------------------------------------
