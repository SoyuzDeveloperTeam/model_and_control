#ifndef bum_connect
#define bum_connect
//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <winsock.h>            // ��� ������ � ���
#include <IniFiles.hpp>         // ��� ������ � ������ ������������
#include "bumconnect.h"
#include "JouHeader.h"          // ��������� ��� �������
#include "JouStrings.h"         // ��������� ���������� ��� �������
//---------------------------------------------------------------------------
#pragma package(smart_init)

AnsiString inpu_con_data[8];

TDateTime onboard_dt, dest_s, ob_cur;

static bool start_priz;

static bool bum_pr;             // ������� "� ���"

static TIniFile *MiuConf;       // ���� ������������

static AnsiString WsaIpAddr;    // IP ����� �� ������������
static AnsiString WsaPortTele;  // ���� ������������ �� �������
static AnsiString WsaPortTmtc;
static AnsiString WsaPortModel;
static AnsiString WsaPortCtrl;
static AnsiString ConfFileName;

static int iResult;                    // ���������������� ����������
WSADATA wsaData;                // ��������� Win Socket

// ������ ������ � ���
SOCKET CtrlSocket;              // ����� ������������ ����������
SOCKET TmtcSocket;              // ����� ��������-���������������� ����������
SOCKET ModelSocket;             // ����� ���������� ����������
SOCKET TeleSocket;              // ����� ���������� "������������"

sockaddr_in ctrl_sock;
sockaddr_in tmtc_sock;
sockaddr_in model_sock;
sockaddr_in tele_sock;          // ��������� ������ ������� ���� ��� ����������� � ���������� ������������

struct{                         // ��������� �������� ������� � ���
int i;  //  4
int s;  //  8
int aa; //  16
int zr; //  20
int c;  //  24
}send_tru;


void Config_init (AnsiString iniName) {  // ��������� ������������� ����� ������������
ConfFileName = "C:\1231231\Out\miu_config.ini";  // ������� ��� ����� ������������
MiuConf = new TIniFile(iniName);                                   // �����������
if(FileExists(iniName))                                            // ���� ����� ���� ����������, ��...
{
JPS(1,"������ ����� ������������...","","","");                         // �������� � ������ �������� ������ �����
WsaIpAddr = MiuConf->ReadString("WSA","main_ip","0.0.0.0");             // �������� ��������
WsaPortTele = MiuConf->ReadString("WSA","tele_port","2002");
inpu_con_data[0] = WsaIpAddr;
inpu_con_data[3] = MiuConf->ReadString("WSA","ctrl_port","0000");
inpu_con_data[4] = MiuConf->ReadString("WSA","tmtc_port","0000");
inpu_con_data[5] = MiuConf->ReadString("WSA","model_port","0000");
inpu_con_data[1] = MiuConf->ReadString("INPU","inpu1_port_com1","0000");
inpu_con_data[2] = MiuConf->ReadString("INPU","inpu1_port_com2","0000");
} else JPS(3,"����������� ���� ������������!","","","");

}

//////////////////////////////////
// ���������� ������ ���������� //
//////////////////////////////////
void GetWsaError (int GetLastError) {
      if (GetLastError==8)     JPS(3,"������������ ��������� ������!","","","");
 else if (GetLastError==87)    JPS(3,"���� ��� ��������� ���������� ���������������!","","","");
 else if (GetLastError==995)   JPS(3,"������������� �������� ���� �������� ��-�� �������� ������!","","","");
 else if (GetLastError==10013) JPS(3,"� ������� ���������! ","","","");
 else if (GetLastError==10036) JPS(3,"�������� ��� � ��������! ","","","");
 else if (GetLastError==10037) JPS(3,"�������� ��� �����������! ","","","");
 else if (GetLastError==10038) JPS(3,"�������� � ������� �� ��-������! ��������, ��� ����� ��� ������.","","","");
 else if (GetLastError==10048) JPS(3,"����� ��� ������������! ","","","");
 else if (GetLastError==10049) JPS(3,"�������� �������� IP ������! ������� main_ip � miu_conf.ini","","","");
 else if (GetLastError==10051) JPS(3,"���� ����������� ������� �������� � ������� � ����������� ����.","","","");
 else if (GetLastError==10054) JPS(3,"���������� ������������� ������� ��������� ������!","","","");
 else if (GetLastError==10057) JPS(3,"�������� ����������, �.�. ����� �� ���������!","","","");
 else if (GetLastError==10058) JPS(3,"�������� ����������, �.�. ����� ��� ������!","","","");
 else if (GetLastError==10060) JPS(3,"������� ����������� �� �������, ������ ��� ����� ����������� �������!","","","");
 else if (GetLastError==10061) JPS(3,"� ����������� ���������, ��� ��� ��� �� �������. ��� �������?","","","");
 else if (GetLastError==10062) JPS(3,"�� ���� ��������� ���!","","","");
 else if (GetLastError==11001) JPS(3,"���� �� ������!","","","");
 else if (GetLastError==11003) JPS(3,"������������ ������!","","","");
 else if (GetLastError==11004) JPS(3,"���������� ���, ��� ������ ������ ������������ ����.","","","");
 else if (GetLastError==11017) JPS(3,"QSOS - ������! � QOS ��������� �������� ��� ������������� ����� ������.","","","");
 else if (GetLastError==11018) JPS(3,"������������ �����, ��������� �� ���������� QoS.","","","");
 else JPS(3,"������ �����������! ���: "+IntToStr(GetLastError),"","",""); }

void SendToBum (int Cmd,int p1, int p2){
send_tru.i = 0x02000700;
send_tru.s = 0x00001500;
send_tru.aa = ntohl(Cmd);
send_tru.zr = ntohl(p1);
send_tru.c = ntohl(p2);
if(bum_pr){
iResult = send( TeleSocket,(char *)&send_tru,20, 0);   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());}
}
#endif bum_connect
