//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "sps_frm.h"
#include "SPSHead.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tsps_form *sps_form;
int i_sps;
//---------------------------------------------------------------------------
__fastcall Tsps_form::Tsps_form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tsps_form::Timer1Timer(TObject *Sender)
{
//for (i_sps=0;i_sps=38;i_sps++){
//TSpsDataN[i_sps]=SpsDataSt.TSpsParam[i_sps];}
if(TSpsDataN[2]<5){
sps_rh20->Color=clYellow;
sps_rh20->Font->Color=clBlack;
sps_rh20->Caption=TSpsDataN[2];} else
if(TSpsDataN[2]>=4&&TSpsDataN[2]<14.5){
sps_rh20->Color=clBlack;
sps_rh20->Font->Color=clLime;
sps_rh20->Caption=TSpsDataN[2];} else
if(TSpsDataN[2]>14.5&&TSpsDataN[2]>16.3){
sps_rh20->Color=clYellow;
sps_rh20->Font->Color=clBlack;
sps_rh20->Caption=TSpsDataN[2]; } else
if(TSpsDataN[2]>16.3){
sps_rh20->Color=clMaroon;
sps_rh20->Font->Color=clYellow;
sps_rh20->Caption=TSpsDataN[2];
}
}
//---------------------------------------------------------------------------
