//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "JouHeader.h"
#include "JouStrings.h"
#include "toru_frm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Ttoru_pult *toru_pult;
//---------------------------------------------------------------------------
__fastcall Ttoru_pult::Ttoru_pult(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Ttoru_pult::pwr_onClick(TObject *Sender)
{

JPS(1,is_operator,is_pu_bps,cmd_201,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::pwr_offClick(TObject *Sender)
{

JPS(1,is_operator,is_pu_bps,cmd_202,"");
       //
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::prm_rezClick(TObject *Sender)
{

JPS(1,is_operator,is_pu_bps,cmd_203,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::pered_rezClick(TObject *Sender)
{

JPS(1,is_operator,is_pu_bps,cmd_204,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::odrClick(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_205,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::pered_com_offClick(TObject *Sender)
{

JPS(1,is_operator,is_pu_bps,cmd_206,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::ru_onClick(TObject *Sender)
{

JPS(1,is_operator,is_pu_bps,cmd_207,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::ru_offClick(TObject *Sender)
{

JPS(1,is_operator,is_pu_bps,cmd_208,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton6Click(TObject *Sender)
{

if (SpeedButton6->Down==false){
SpeedButton6->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_22B,j_otg);

SpeedButton6->Down=false;
} else if (SpeedButton6->Down==true){
SpeedButton6->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_22B,j_nag);

SpeedButton6->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton9Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_209,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton10Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20A,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton1Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20B,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton2Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20C,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton3Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20D,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton12Click(TObject *Sender)
{
if (SpeedButton12->Down==false){
SpeedButton12->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_22D,j_otg);

SpeedButton12->Down=false;
} else if (SpeedButton12->Down==true){
SpeedButton12->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_22D,j_nag);

SpeedButton12->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton13Click(TObject *Sender)
{
if (SpeedButton13->Down==false){
SpeedButton13->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_22E,j_otg);

SpeedButton13->Down=false;
} else if (SpeedButton13->Down==true){
SpeedButton13->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_22E,j_nag);

SpeedButton13->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton40Click(TObject *Sender)
{
if (SpeedButton40->Down==false){
SpeedButton40->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_22F,j_otg);

SpeedButton40->Down=false;
} else if (SpeedButton40->Down==true){
SpeedButton40->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_22F,j_nag);

SpeedButton40->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton30Click(TObject *Sender)
{
if (SpeedButton30->Down==false){
SpeedButton30->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_230,j_otg);

SpeedButton30->Down=false;
} else if (SpeedButton30->Down==true){
SpeedButton30->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_230,j_nag);

SpeedButton30->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton11Click(TObject *Sender)
{
if (SpeedButton11->Down==false){
SpeedButton11->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_22C,j_otg);

SpeedButton11->Down=false;
} else if (SpeedButton11->Down==true){
SpeedButton11->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_22C,j_nag);

SpeedButton11->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton39Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_22A,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton36Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_227,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton35Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_226,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton34Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_225,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton31Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_222,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton32Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_223,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton33Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_224,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton37Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_228,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton38Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_229,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton4Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20E,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton5Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20F,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton7Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_210,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton8Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_211,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton14Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_212,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton15Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_213,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton16Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_214,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton17Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_215,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton18Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_216,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton19Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_217,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton20Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_218,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton21Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_219,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton22Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21A,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton23Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21B,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton24Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21C,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton25Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21D,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton26Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21E,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton27Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21F,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton28Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_220,"");

}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton29Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_221,"");

}
//---------------------------------------------------------------------------

