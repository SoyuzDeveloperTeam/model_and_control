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
TPanel *panel;
    TColor cvet[2];

void spsdemo(){
//sps_form->sps_ro2->Caption="";
}
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

/* if(TSpsDataN[2]<5){
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
}  */


    for(int ind,i=0;i<ComponentCount;i++)
     if(Components[i]->ClassNameIs("TPanel"))
      if((ind=Components[i]->Name.SubString(7,2).ToIntDef(0))>0) // if name sps_rh...
   {
    panel = (TPanel*)Components[i];  ind--;
    cvet[0]=clMaroon; cvet[1]=clYellow;
    if(TSpsDataN[ind] <= 16.3) { cvet[0]=clYellow; cvet[1]=clBlack; }
    if(TSpsDataN[ind] <= 14.5) { cvet[0]=clBlack; cvet[1]=clLime; }
    if(TSpsDataN[ind] <= 5.0 ) { cvet[0]=clYellow; cvet[1]=clBlack; }
    panel->Color=cvet[0];
    panel->Font->Color=cvet[1];
    panel->Caption=TSpsDataN[ind];
   }

}
//---------------------------------------------------------------------------
/* SPS STRUCT
5 - Theta_1
6 - Psi_1
7 - Gamma_1
8 - Theta_2
9 - Psi_2
10 - Gamma_2

∆≈À“€… - TXD
 – - RXD
«≈À - GND
Œ–¿Õ - RTS
BLACK - CTS

*/
