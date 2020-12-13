//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "iss_per_tp.h"
// Отладка поиска зависания:
// Отключил таймеры nfqvth 1
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tiss_t_tp *iss_t_tp;
//---------------------------------------------------------------------------
__fastcall Tiss_t_tp::Tiss_t_tp(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tiss_t_tp::FormCreate(TObject *Sender)
{
Chart1->BottomAxis->SetMinMax(0,650);
Chart1->LeftAxis->SetMinMax(0.08,-0.08);
Chart1->Series[0]->AddXY(0,0,clBlack);
Chart1->Series[0]->AddXY(100,0,clBlack);
Chart1->Series[0]->AddXY(200,0,clBlack);
Chart1->Series[0]->AddXY(300,0,clBlack);
Chart1->Series[0]->AddXY(400,0,clBlack);
Chart1->Series[0]->AddXY(500,0,clBlack);
Chart1->Series[0]->AddXY(600,0,clBlack);
Chart1->Series[0]->AddXY(750,0,clBlack);

Chart2->BottomAxis->SetMinMax(0,650);
Chart2->LeftAxis->SetMinMax(4,-4);
Chart2->Series[0]->AddXY(0,0,clBlack);
Chart2->Series[0]->AddXY(100,0,clBlack);
Chart2->Series[0]->AddXY(200,0,clBlack);
Chart2->Series[0]->AddXY(300,0,clBlack);
Chart2->Series[0]->AddXY(400,0,clBlack);
Chart2->Series[0]->AddXY(500,0,clBlack);
Chart2->Series[0]->AddXY(600,0,clBlack);
Chart2->Series[0]->AddXY(750,0,clBlack);
}
//---------------------------------------------------------------------------

