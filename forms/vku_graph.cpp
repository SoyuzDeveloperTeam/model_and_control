//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "vku_graph.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tvkugraph *vkugraph;
//---------------------------------------------------------------------------
__fastcall Tvkugraph::Tvkugraph(TComponent* Owner)
        : TForm(Owner)
{
Chart1->BottomAxis->SetMinMax(-600,600);
Chart1->LeftAxis->SetMinMax(-600,600);
Chart1->Series[1]->AddXY(-600,0,clWhite);
Chart1->Series[1]->AddXY(0,0,clWhite);
Chart1->Series[1]->AddXY(600,0,clWhite);
Chart1->Series[1]->AddXY(0,0,clWhite);
Chart1->Series[1]->AddXY(0,-600,clWhite);
Chart1->Series[1]->AddXY(0,0,clWhite);
Chart1->Series[1]->AddXY(0,600,clWhite);
Chart1->Series[1]->AddXY(0,0,clWhite);
}
//---------------------------------------------------------------------------
