//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "otkazy.h"
#include "bumconnect.cpp"      // Обмен с БУМ
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Totkazy_frm *otkazy_frm;
//---------------------------------------------------------------------------
__fastcall Totkazy_frm::Totkazy_frm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Totkazy_frm::CheckBox16Click(TObject *Sender)
{
if(CheckBox16->Checked){
SendToBum(0x00000108, 4, 1);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
} else {
SendToBum(0x00000108, 4, 0);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
}
//---------------------------------------------------------------------------
void __fastcall Totkazy_frm::CheckBox17Click(TObject *Sender)
{
if(CheckBox17->Checked){
SendToBum(0x00000108, 5, 1);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
} else {
SendToBum(0x00000108, 5, 0);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
}
//---------------------------------------------------------------------------
void __fastcall Totkazy_frm::CheckBox19Click(TObject *Sender)
{
if(CheckBox16->Checked){
SendToBum(0x00000108, 7, 1);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
} else {
SendToBum(0x00000108, 7, 0);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
}
//---------------------------------------------------------------------------
void __fastcall Totkazy_frm::CheckBox22Click(TObject *Sender)
{
if(CheckBox22->Checked){
SendToBum(0x00000184, 2, 1);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
} else {
SendToBum(0x00000184, 0, 0);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
}
//---------------------------------------------------------------------------
void __fastcall Totkazy_frm::CheckBox26Click(TObject *Sender)
{
if(CheckBox26->Checked){
SendToBum(0x00000185, 2, 1);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
} else {
SendToBum(0x00000185, 0, 0);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
}
//---------------------------------------------------------------------------
void __fastcall Totkazy_frm::CheckBox13Click(TObject *Sender)
{
if(CheckBox13->Checked){
SendToBum(0x0000018A, 1, 1);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
} else {
SendToBum(0x0000018A, 1, 0);       //Команда в БУМ ()
iResult = send( TeleSocket,(char *)&send_tru,20, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
}
//---------------------------------------------------------------------------
