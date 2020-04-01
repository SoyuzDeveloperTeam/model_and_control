//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "JouHeader.h"
#include "JouStrings.h"
#include "toru_frm.h"
#include "bumconnect.cpp"      // Обмен с БУМ
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
//For BUM - 00000201 1 1
JPS(1,is_operator,is_pu_bps,cmd_201,"");
SendToBum(0x00000201, 1, 1);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError()); 
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::pwr_offClick(TObject *Sender)
{
//For BUM - 00000202 1 1
JPS(1,is_operator,is_pu_bps,cmd_202,"");
SendToBum(0x00000202, 1, 1);       //
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::prm_rezClick(TObject *Sender)
{
//For BUM - 00000203 1 1
JPS(1,is_operator,is_pu_bps,cmd_203,"");
SendToBum(0x00000203, 1, 1);       //
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::pered_rezClick(TObject *Sender)
{
//For BUM - 00000204 1 1
JPS(1,is_operator,is_pu_bps,cmd_204,"");
SendToBum(0x00000204, 1, 1);       //
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::odrClick(TObject *Sender)
{
//For BUM - 00000205 1 1
JPS(1,is_operator,is_pu_bps,cmd_205,"");
SendToBum(0x00000205, 1, 1);       //
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::pered_com_offClick(TObject *Sender)
{
//For BUM - 00000206 1 1
JPS(1,is_operator,is_pu_bps,cmd_206,"");
SendToBum(0x00000206, 1, 1);       //
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::ru_onClick(TObject *Sender)
{
//For BUM - 00000207 1 1
JPS(1,is_operator,is_pu_bps,cmd_207,"");
SendToBum(0x00000207, 1, 1);       //
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::ru_offClick(TObject *Sender)
{
//For BUM - 00000208 1 1
JPS(1,is_operator,is_pu_bps,cmd_208,"");
SendToBum(0x00000208, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton6Click(TObject *Sender)
{
//For BUM - 0000022B 1 1
if (SpeedButton6->Down==false){
SpeedButton6->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_22B,j_otg);
SendToBum(0x0000022B, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton6->Down=false;
} else if (SpeedButton6->Down==true){
SpeedButton6->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_22B,j_nag);
SendToBum(0x0000022B, 1, 0);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton6->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton9Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_209,"");
SendToBum(0x00000209, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton10Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20A,"");
SendToBum(0x0000020A, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton1Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20B,"");
SendToBum(0x0000020B, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton2Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20C,"");
SendToBum(0x0000020C, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton3Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20D,"");
SendToBum(0x0000020D, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------


void __fastcall Ttoru_pult::SpeedButton12Click(TObject *Sender)
{
if (SpeedButton12->Down==false){
SpeedButton12->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_22D,j_otg);
SendToBum(0x0000022D, 1, 0);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton12->Down=false;
} else if (SpeedButton12->Down==true){
SpeedButton12->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_22D,j_nag);
SendToBum(0x0000022D, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton12->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton13Click(TObject *Sender)
{
if (SpeedButton13->Down==false){
SpeedButton13->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_22E,j_otg);
SendToBum(0x0000022E, 1, 0);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton13->Down=false;
} else if (SpeedButton13->Down==true){
SpeedButton13->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_22E,j_nag);
SendToBum(0x0000022E, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton13->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton40Click(TObject *Sender)
{
if (SpeedButton40->Down==false){
SpeedButton40->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_22F,j_otg);
SendToBum(0x0000022F, 1, 0);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton40->Down=false;
} else if (SpeedButton40->Down==true){
SpeedButton40->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_22F,j_nag);
SendToBum(0x0000022F, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton40->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton30Click(TObject *Sender)
{
if (SpeedButton30->Down==false){
SpeedButton30->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_230,j_otg);
SendToBum(0x00000230, 1, 0);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton30->Down=false;
} else if (SpeedButton30->Down==true){
SpeedButton30->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_230,j_nag);
SendToBum(0x00000230, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton30->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton11Click(TObject *Sender)
{
if (SpeedButton11->Down==false){
SpeedButton11->AllowAllUp=true;
JPS(1,is_operator,is_pu_bps,cmd_22C,j_otg);
SendToBum(0x0000022C, 1, 0);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton11->Down=false;
} else if (SpeedButton11->Down==true){
SpeedButton11->Down=true;
JPS(1,is_operator,is_pu_bps,cmd_22C,j_nag);
SendToBum(0x0000022C, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
SpeedButton11->AllowAllUp=true;
}
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton39Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_22A,"");
SendToBum(0x0000022A, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton36Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_227,"");
SendToBum(0x00000227, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton35Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_226,"");
SendToBum(0x00000226, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton34Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_225,"");
SendToBum(0x00000225, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton31Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_222,"");
SendToBum(0x00000222, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton32Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_223,"");
SendToBum(0x00000223, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton33Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_224,"");
SendToBum(0x00000224, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton37Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_228,"");
SendToBum(0x00000228, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton38Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_229,"");
SendToBum(0x00000229, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton4Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20E,"");
SendToBum(0x0000020E, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton5Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_20F,"");
SendToBum(0x0000020F, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton7Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_210,"");
SendToBum(0x00000210, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton8Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_211,"");
SendToBum(0x00000211, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton14Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_212,"");
SendToBum(0x00000212, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton15Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_213,"");
SendToBum(0x00000213, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton16Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_214,"");
SendToBum(0x00000214, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton17Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_215,"");
SendToBum(0x00000215, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton18Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_216,"");
SendToBum(0x00000216, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton19Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_217,"");
SendToBum(0x00000217, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton20Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_218,"");
SendToBum(0x00000218, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton21Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_219,"");
SendToBum(0x00000219, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton22Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21A,"");
SendToBum(0x0000021A, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton23Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21B,"");
SendToBum(0x0000021B, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton24Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21C,"");
SendToBum(0x0000021C, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton25Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21D,"");
SendToBum(0x0000021D, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton26Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21E,"");
SendToBum(0x0000021E, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton27Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_21F,"");
SendToBum(0x0000021F, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton28Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_220,"");
SendToBum(0x00000220, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall Ttoru_pult::SpeedButton29Click(TObject *Sender)
{
JPS(1,is_operator,is_pu_bps,cmd_221,"");
SendToBum(0x00000221, 1, 1);       //команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   // Посылаем команду в БУМ
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

