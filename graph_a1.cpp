//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "graph_a1.h"
#include "kdu_math.h"
#include "SPSHead.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tgraphics *graphics;
int shhh;
int i_fds;
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


