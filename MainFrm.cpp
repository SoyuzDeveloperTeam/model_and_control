/***************************************************************************/
/*                  ��� "������������� � ����������"                       */
/*-------------------------------------------------------------------------*/
/* ��� "���" ������������� ��� ������������� �������� �������������        */
/* ������������� ������� ����-��� �� ����������� ������, �����             */
/* �������������� ��������� ��������, � ����� ���������� ������������ �    */
/* ����������� ������ ������� ��� � ��������������, ��� � � ������ ������� */
/* �������� ������� ������ �������������� ���������, ��������� �������     */
/* ����������� � ������ ��.                                                */
/*-------------------------------------------------------------------------*/
/***************************************************************************/
// ������� ������ ���������:
// �������� ������� ��������� �����, ����������, ������ �5 (������ � ���), ������ �2 (������ ���)
//---------------------------------------------------------------------------
#pragma hdrstop
#include <vcl.h>
#include "MainFrm.h"
#include <vector.h>
#include <math.h>
#include <Tlhelp32.h>
//---------------------------------------------------------------------------
/* ��������� */
#include "main_header.h"                // �������� ���������
#include "JouHeader.h"                  // ��������� ��� �������
#include "dta.cpp"                      // ������ ��� ������ � ���
#include "md_m.h"                       // ��������� ����������
#include "ts_header.h"                  // ���������� ��
#include "ICN_header.h"                 // ������ ��� ������ � ����
#include "JouStrings.h"                 // ��������� ���������� ��� �������
#include "SPSHead.h"                    // ������ ��� �.1
#include "USOData.h"                    // ��������� ���
#include "inpu_connect.cpp"             // ����� � ������� ����
#include "main_math.cpp"                // �������������� ������
#include "argon/arg_header.h"           // ���������� �16
#include "argon/CtrlWord.h"             // ����������� ����� ������
#include "argon/arg_kdu_operations.cpp" // Argon-16 ��������� ���
#include "sotr_data.h"                  // ������ ����
#include "DateUtils.hpp"
#include "argon/arg_pks.cpp"            // ��������� ������
#include "bumconnect.cpp"               // ����� � ���
#include "neptun_main.cpp"              // �������� ��������� ��� "������-��"
//---------------------------------------------------------------------------
/* ����� */
#include "vived_frm.cpp"                // ����� ��������� (������)
#include "brus_form.cpp"                // ����� ����
#include "ts_frm.cpp"                   // ����� ��
#include "bfi_formats.cpp"              // ����� "��� ������" ��� �16
#include "bum_sett_frm.cpp"             // ����� ������ ������ ���
#include "toru_frm.cpp"                 // ����� ������ �� ��� ����
#include "EnterNuFrm.cpp"               // ����� ����� ��������� ������� (��)
#include "kdu_data.cpp"                 // ����� ���������� ���
#include "clock_form.cpp"               // ����� ���-744� �������� ���� �� �� ���
#include "JouLogFrm.h"                  // ����� ��������� �������
#include "zakon_upr.cpp"                // ����� ����� ����������
#include "KSPLForm.cpp"                 // ����� ��� �����
#include "KSPPForm.cpp"                 // ����� ��� ������
#include "USOFrm.cpp"                   // ����� ���
#include "cdn_clock_frm.cpp"            // ����� CDN clock MSK
#include "AboutFrm.cpp"                 // ����� "� ���������..."
#include "BkuCFrm.cpp"                  // ����� ���-� "������-�"
#include "irvi_brfi_frm.cpp"            // ����� ����
#include "graph_a1.cpp"                 // ����� ��������
#include "SOTR_frm.cpp"                 // ����� ����
#include "InstructorFormat_Form.cpp"    // ����� ��������������� �������
#include "vku_graph.cpp"                // ����� ��� ��������
#include "iss_per_tp.cpp"               // ������� ��� � ��
#include "argon_debug_frm.cpp"          // ����� ������� ������
#include "debug_bum_frm.cpp"            // ����� ������� ������ � ���
#include "otkazy.cpp"                   // ����� "����� ��������� ������"
// ������� Laptop �� ��� (��)
#include "sm_ssvp_PX.cpp"               // ������ ��:����:+�
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
#define n_act_str 5    //����� ���������� ��������
static AnsiString StrForDebug;

// ��� ������
static int i_test;
static int j_test;
static bool vill_test;
static int f_test;
TDateTime SFD_sec;
double ghjh;
// -- -- -- --

HINSTANCE Lib = LoadLibrary("LIB_BNO.dll");                    // ��������� ���������� �����������

TInit Init = 0;                                                // Make object's
TGetMagData GetMagData = 0;
TGetGravTorqueData GetGravTorqueData = 0;
//---------------------------------------------------------------------------

static int qss;
static int disp[3];
static vector <int> STBv(3);

int test_test_tse;

int image_index;

struct {
int a;
int b;
int c;
}sends;
  int intVariable;
bool startdelay;
bool iniread;

int qwe;

//---------------------------------------------------------------------------
SOCKET SPSSocket_ch1;           // ����� ������ 1 ���
SOCKET SPSSocket_ch2;           // ����� ������ 2 ���
sockaddr_in clientInPU_COM2;      // ��������� ������ ������� ���� 1

const int MAX_BUF_SIZE = 1024;

bool init;            // ������� �������� �������������  (��������� � main?)
int err;
bool con;             // ������� �������� ����������� ��� ��������� ������
bool inpu_com2_connect_pr; // ������� ����� � ����
WORD wVersionRequested;

//---------------------------------------------------------------------------
struct STR_temp *DATA_FROM_MS_mas[12];

AnsiString sendText;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
MainForm->Caption="��������� ����-���  |  ������: "+ActVer;
StatusBar->Panels->Items[2]->Text="O";
init=false;
con=false;
//startdelay=true;
err = WSAStartup(wVersionRequested, &wsaData);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::pusk_btnClick(TObject *Sender)
{
if(bum_pr){
p_sost_from_bum->Enabled=true;
dk_to_bum->Enabled=true;            // ���������� �������� ���������� �� � ���
SendToBum(0x00000301, 2, 1); }      //���� �������� - ������� � ��� ()
PuskPr = true;                     // ������ ������� "���� ��������"
start_priz = true;                 // ������� ��� ���
ModelDateTime_Timer->Enabled=true; // ��������� ������ ���������� ������� (�� � ������ ��������� ����� ��� ���������� ��� - ����� ������� �� ����)
MainTimer->Enabled=true;           // ������ ����������� ����������� ������. ���������� ���, ��� � �.�.
ChekTSKD->Enabled=true;            // ���������� �������� ���
pusk_btn->Enabled=false;           // ��������� ������ "����" �� ��������� ����� ��� ��������� ������ � ��������.
Timer6->Enabled=true;
JPS(1,is_operator,is_miu,"���� �������������","");
StatusBar->Panels->Items[0]->Text="������� ������� �������������...";
// ���� ���� �������� ��������� � ������ ������� ���������� ����������� ������ "����" � ��������
// � ��������������� �� � ������ "�����������"
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N3Click(TObject *Sender)
{
ts_form->Show();  //������ ����� "��"
}
//---------------------------------------------------------------------------
//void GetStructFromBUM(struct STR_temp* s)   // �������� �� ���� ��������� ����������
//{
//memcpy((void *)s,(void *)&DATA_FROM_MS_mas[n_act_str],sizeof(STR_temp));
//}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N14Click(TObject *Sender)
{
toru_pult->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N1Click(TObject *Sender)      // ���� ��
{
EnterNuForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N15Click(TObject *Sender)     // ��������� ���
{
KDUform->Show();
}
//----------------------------------------//
// ��������� �� �������� ����� ���������� //
//----------------------------------------//
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
if(PuskPr){ // ���� �� ������ �������� ������ ������� "���� ��������", ��...
if(         // ������� MessageBox
Application->MessageBox(
"������� ������� �������������! \n��� ����� �����?",
"��������!",
MB_YESNO|
MB_ICONINFORMATION) == IDNO){
Abort();
}
} // if PuskPr
WSACleanup();  // ��� �� � ����� ������ ��������� ��� ������
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N16Click(TObject *Sender)
{
clock_frm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N7Click(TObject *Sender)
{
JouLogForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button4Click(TObject *Sender)
{
if(bum_pr){
SendToBum(0x00000301, 2, 0);       //����� �������� - ������� � ��� ()
dk_to_bum->Enabled=true;           // ���������� �������� ���������� �� � ���
p_sost_from_bum->Enabled=false;}
start_priz = false;
PuskPr = false;
ModelDateTime_Timer->Enabled=false;
MainTimer->Enabled=false;
ArgonTakt->Enabled=false;
Timer6->Enabled=false;
pusk_btn->Enabled=true;
JPS(1,is_operator,is_miu,"����� �������������","");
StatusBar->Panels->Items[0]->Text="����� �������� �������������.";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TclConnected(TObject *Sender)
{
StatusBar->Panels->Items[0]->Text="["+Now().FormatString("hh.mm.ss.zzz")+"]  -  ���������";
}
//---------------------------------------------------------------------------

char buff[5]={72,101,108, 108, 111};

void __fastcall TMainForm::N21Click(TObject *Sender)
{
BkuC->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N12Click(TObject *Sender)
{
AboutForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button6Click(TObject *Sender)
{
        iResult = closesocket(CtrlSocket);
        if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
        iResult = closesocket(TmtcSocket);
        if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
        iResult = closesocket(ModelSocket);
        if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
        iResult = closesocket(TeleSocket);
        if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
        bum_pr = 0;
        init_->Enabled=true;
        JPS(3, "��������: ������ ������ � ��� ������!", "", "", "");
}
//---------------------------------------------------------------------------
/////////////////////////////////////////
// ������ �������� ������� (���������� //
//-------------------------------------//
// ������ ��������� �� ������� ���     //
/////////////////////////////////////////
void __fastcall TMainForm::LocalTimeTimerTimer(TObject *Sender)
{
LocalTime->Caption=Now().FormatString("hh:mm:ss");  // ����� �������� ������� ��
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::kspl_loadClick(TObject *Sender)  // ������ ������� ����
{
ksplfrm->Show();
}

//------------------------------------------------//
// � � � � � � � � �   � � � � � � � � � � � � �  //
//------------------------------------------------//
VOID __fastcall TMainForm::init_Click(TObject *Sender)
{
JPS(1,is_operator,is_miu,"������� ������� �������������.","");

// ���������� ��������� ���������� �� �� ��� ���-��
dk_mass.str_1 = 0x02000700;
dk_mass.str_2 = 0x00001500;
dk_mass.cmd   = 0x00200101;
dk_mass.size  = ntohl(48);

  if( Lib >= (HINSTANCE)32 )  // ��������� ���������� ��� ���.�������������
  {
    Init = (TInit)GetProcAddress( Lib, "_Init");
    GetMagData = (TGetMagData)GetProcAddress( Lib, "_GetMagData" );
    GetGravTorqueData = (TGetGravTorqueData)GetProcAddress( Lib, "_GetGravTorqueData" );
  }

  if( !GetMagData || !Init || !GetGravTorqueData)                // ��������� ����������� �� �����
   JPS(3,"","","������ �������� ���������� ���� BNO.",""); else {
   JPS(1,"","","���������� ���������� ���� BNO.","");
   Init();
   JPS(1,"","","���� BNO ���������������.",""); }

Config_init(ExtractFilePath(Application->ExeName)+"miu_config.ini");  // ������������� ����� ������������

if(!WithoutBum->Checked){ // ���� ��� �������� "��� ���"
bum_pr = true;
/*
  �������� ������� ����������� ������ ����������
  �������� �� ������� ��������� ���������� � ���.

  ������� ��������������� ��� ������ ������ � ���
  ----------
  � ������������ ���������� ������������� ������
  ���������� ������������� �� ������� ����������.
  �������������� ������ ���� � �������, � ��� �� � ������� �������.
*/
JPS(1,"������ ������������� ��������� ������ � ���","","","");  // �������� � ������
}
//---------//
// 1.1.1. ������������� Winsock //

iResult = WSAStartup(MAKEWORD(2,2), &wsaData); // ��������������...
	if (iResult != 0)                      // ���������� ������ �������������
	{
		JPS(3,"������ ������������� WinSock! ���: "+IntToStr(err),"","","");
		WSACleanup();
	}
        if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
                JPS(3,"�� ������� ���������� ���������� ������ Winsock.dll","","","");
                WSACleanup(); }  else {        // ���� ������� ������������� � ����������� �����, ��...
                JPS(1,"���������� ���������� Winsock.dll","","","");}

//---------//
// 1.1.2. ���������� ������� ����������� � ���

CtrlSocket = socket(AF_INET, // ��������� ������� ��������-��������� ������ 4 (IPv4).
                 SOCK_DGRAM, // ���� ��� ������ ���������� �������� ���������������� ���������� (UDP)
                IPPROTO_UDP  // �������� ���������������� ���������� (UDP).
                );           // ����� ������������ ����������
TmtcSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);           // ����� ���
ModelSocket= socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);           // ����� Model
TeleSocket = socket(AF_INET, // ��������� ������� ��������-��������� ������ 4 (IPv4).
                SOCK_STREAM, // ���� ��� ������ ���������� �������� ���������� ��������� (TCP)
                IPPROTO_TCP  // �������� ���������� ��������� (TCP).
                );           // ����� ������������

StatusBar->Panels->Items[2]->Text="�  �";   // ������� ��������� ��� � - �������������, � - ��������

//---------//
// 1.1.3. ���������� ��������� ����� ������ � ��������

// inet_addr((unsigned char)MiuConf->ReadString("WSA","main_ip","0.0.0.0"))
// "��������" �� ����� ������������ ���������� ������
AnsiString fdsfd = MiuConf->ReadString("WSA","main_ip","0.0.0.0");
char * ipaddress = fdsfd.c_str(); // ���������� IP ����� (������� ���� ��� �� ������ � ������� ���� � ���)

// Teleoperator
tele_sock.sin_family = AF_INET;                    // ��������� ������� ��������-��������� ������ 4 (IPv4).
tele_sock.sin_addr.s_addr = inet_addr(ipaddress);  //
tele_sock.sin_port = htons(WsaPortTele.ToInt());   // �� �� + ������ �������� �� ������������ � ������� ����

// TMTC
tmtc_sock.sin_family = AF_INET;                    // ������ ����� AF_INET !
tmtc_sock.sin_addr.s_addr = inet_addr(ipaddress);  //
tmtc_sock.sin_port = htons(inpu_con_data[4].ToInt());     // �� �� + ������ �������� �� ������������ � ������� ����

// ��������� ��������� (����)
model_sock.sin_family = AF_INET;                   // ������ ����� AF_INET !
model_sock.sin_addr.s_addr = inet_addr(ipaddress); //
model_sock.sin_port = htons(inpu_con_data[5].ToInt());                // �� �� + ������ �������� �� ������������ � ������� ����

// ����� ������������ ����������
ctrl_sock.sin_family = AF_INET;                    // ������ ����� AF_INET !
ctrl_sock.sin_addr.s_addr = inet_addr(ipaddress);  //
ctrl_sock.sin_port = htons(inpu_con_data[3].ToInt());                 // �� �� + ������ �������� �� ������������ � ������� ����

//---------//
// 1.1.4. ������� ����������� � �������
if(!WithoutBum->Checked){
/* iResult = bind(CtrlSocket,  (SOCKADDR *) & ctrl_sock,  sizeof (ctrl_sock));  // ������������
        if (iResult == SOCKET_ERROR) { GetWsaError(WSAGetLastError());  } else { JPS(4,"��� - ���� ����������� � ���������� ����������","","","");  }
iResult = bind(TmtcSocket,  (SOCKADDR *) & tmtc_sock,  sizeof (tmtc_sock));
        if (iResult == SOCKET_ERROR) { GetWsaError(WSAGetLastError());  } else { JPS(4,"��� - ���� ����������� � ��� ����������","","",""); }
iResult = bind(ModelSocket, (SOCKADDR *) & model_sock, sizeof (model_sock));
        if (iResult == SOCKET_ERROR) { GetWsaError(WSAGetLastError());  } else { JPS(4,"��� - ���� ����������� � ���������� ����������","","","");  }  */
iResult = connect(TeleSocket,  (SOCKADDR *) & tele_sock,  sizeof (tele_sock));
        if (iResult == SOCKET_ERROR) { GetWsaError(WSAGetLastError());  } else { // ���� ����������� �������, ��...
          JPS(4,"��� - ���� ����������� � ���������� ������������","","","");
          JPS(4,"����������� � ��� - �������","","","");
          init=true;      // ���������� ������� �������� ������������� ����������� - ����� �������� �������
          //ModelStatusPicList->GetBitmap(1, bum_status_pic->Picture->Bitmap);
          con=true;
          //SocketTeleConnectTimer->Enabled=false;
          }         // ���������� ������� ��������� �����������
StatusBar->Panels->Items[2]->Text="�  �";                 // ������ ������ ��� �� � - �������� �������
}
if(WithoutBum->Checked){
 init=true;
 con=true;
}

JPS(1,"���������� ��������� ���������� ����","","","");
//  ������ ������� ��� ������ ����������
r_m[0] = 200;
r_m[1] = 205;
r_m[2] = 215;
r_m[3] = 225;
r_m[4] = 250;
r_m[5] = 275;
r_m[6] = 300;
r_m[7] = 350;
r_m[8] = 400;
r_m[9] = 500;
r_m[10] = 600;
r_m[11] = 700;
r_m[12] = 800;
r_m[13] = 900;
r_m[14] = 1000;
r_m[15] = 1500;
r_m[16] = 1600;
r_m[17] = 1700;
r_m[18] = 1800;
r_m[19] = 1900;
r_m[20] = 2000;
r_m[21] = 2100;
r_m[22] = 2200;
r_m[23] = 2300;
r_m[24] = 2400;
r_m[25] = 2500;
r_m[26] = 2600;
r_m[27] = 2700;
r_m[28] = 2800;
r_m[29] = 2900;
r_m[30] = 3000;
r_m[31] = 5000;

int isd = 0;

for(isd; isd<=31; isd++){   // ���������� ������ ������� ��� ��
v_verch[isd] = sqrt( 2 * ax_verh *(r_m[isd]-200));
v_b1b2[isd] = sqrt( 2 * ax_b1b2 *(r_m[isd]-200));
v_k1k2[isd] = sqrt( 2 * ax_k1k2 *(r_m[isd]-200));
v_half_k1k2[isd] = sqrt( 2 * ax_half *(r_m[isd]-200));
v_verch[isd] = sqrt( 2 * ax_verh *(r_m[isd]-200));
v_sred[isd] = sqrt( 2 * ax_sred *(r_m[isd]-200));
v_niz[isd] = sqrt( 2 * ax_nijn *(r_m[isd]-200));
}

// ���������� ��������� �������� ��� ������ ����
arg_work_pr = 0;
tResult = 2; // ��� ����� �16
/*
  +-------------------------------------+
  |  2. ������������� ������ � ����     |
  +-------------------------------------+

  +-------------------------------------+
  |  2.1. ������ ������� ���1 � ���2    |
  +-------------------------------------+
*/
if(sps_model->Checked)                  // ���� ���� ������� "����� � ����"
inpu_com2_connect->Enabled=true;        // ��������� ������ ����������� � ����
else JPS(1,"��������: ������������� ��� ������ � ����","","","");

if(init){   // ���� ���� ������� �������������, ��...
init_->Enabled=false;
Button9->Enabled=true;
Button4->Enabled=true;
Button6->Enabled=true;
if(WithoutBum->Checked){
 JPS(1,"","","���������� ������� ��� �������","");
}
JPS(1,"��������� ������������� ���������. ","","","");
StatusBar->Panels->Items[0]->Text="��������� ������������� ���������. �������� ��������� ��������� �������...";
} else
JPS(3,"��������� ������������� �� ���������. ���: "+IntToStr(WSAGetLastError()),"","","");
}

void __fastcall TMainForm::SPSClientDisconnected(TObject *Sender)
{
JPS(1,"��� ��������. ","","","");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N22Click(TObject *Sender)
{
bum_settings->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N4Click(TObject *Sender)
{
UsoForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer2Timer(TObject *Sender)
{
if(con){                        // ���� ���� ������� �����������
if(!WithoutBum->Checked){       // ���� ��� ����� "��� ���"
bum_status_pic->Invalidate();   // ��������� ������-������ ���
bum_status_pic->Invalidate();
bum_status_pic->Invalidate();
ModelStatusPicList->GetBitmap(1, bum_status_pic->Picture->Bitmap);
}
Timer2->Enabled=false; }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
ver_num=" 1.0.1.43";              // ���������� - �������� ������ �� ���������
// --- ���������� ��������� ��������� ������ ������� --- //
ModelStatusPicList->GetBitmap(0, bum_status_pic->Picture->Bitmap);
ModelStatusPicList->GetBitmap(0, inpu_status_pic->Picture->Bitmap);
ModelStatusPicList->GetBitmap(0, argon_status_pic->Picture->Bitmap);
ModelStatusPicList->GetBitmap(0, SpsStatusPic->Picture->Bitmap);
ModelStatusPicList->GetBitmap(0, bum_status_pic->Picture->Bitmap);
image_index = 0;
IdCanSend = false;
PuskPr = false;  
CO_light->Color=StringToColor("0x45607B");     // ���� ���� ��
StatusBar->Panels->Items[0]->Text="��� �������. �������� �������������...";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N24Click(TObject *Sender)
{
graphics->Show();
}
//---------------------------------------------------------------------------
void kptg_fnu(double psi,double tet,double gam,double *c0,double *c1,double *c2,double *c3)
{
double sp,cp,st,ct,sg,cg;
sp=sin(psi/2.0);
cp=cos(psi/2.0);
st=sin(tet/2.0);
ct=cos(tet/2.0);
sg=sin(gam/2.0);
cg=cos(gam/2.0);
*c0=cp*ct*cg-sp*st*sg;
*c1=sp*st*cg+cp*ct*sg;
*c2=sp*ct*cg+cp*st*sg;
*c3=cp*st*cg-sp*ct*sg;
}
//-----------------------------------------------//
// � � � � � � �   � �   � � � � � � � � �   � � //
//-----------------------------------------------//
void __fastcall TMainForm::Button9Click(TObject *Sender)
{
double q_mks[4], q_tk[4];
JPS(1,is_operator,is_miu,"������ ������� - ��������� ��.","");
  // �� ��� ������ ����� � ����
  SpsSend->Enabled=true;
  i_takt = 0;
  dynamics.rs = StrToFloat(EnterNuForm->ro_init->Text);      // ��������� ���������
  dynamics.sks = StrToFloat(EnterNuForm->ro_dot_init->Text); // �������� ���������
  dynamics.omy = StrToFloat(EnterNuForm->Edit63->Text);      //
  dynamics.omz = StrToFloat(EnterNuForm->Edit64->Text);      //
  dynamics.uomy = 0;                                         //
  dynamics.uomz = 0;                                         //
  dynamics.rasp = StrToFloat(EnterNuForm->tk_toplivo->Text); // ������� ���
  // Set model Data and Time from NU form
  EnterNuForm->SetModelDatePicker->Time = EnterNuForm->SetModelTimePicker->Time;
  OnboardModelTime = EnterNuForm->SetModelDatePicker->Date;  // ���������� ��������� ����/�����
  onboard_dt = OnboardModelTime;                             // ������� ����� ������� ��� ������ � ���
  onboardTimeLabel->Caption=OnboardModelTime.FormatString("hh:nn:ss");
  // ntohl
  // ��� ������� (��������)
  if(EnterNuForm->obj_tgk->Checked) NU_temp.n_tr=ntohl(0); else
  if(EnterNuForm->obj_tpk->Checked) NU_temp.n_tr=ntohl(1); else {
  JPS(1,is_miu,"����       �� ��������? ����� ������� ���? ��-��...","","");
  if(EnterNuForm->obj_mlm->Checked) NU_temp.n_tr=ntohl(2);  }
  // �������� ����-����� (���������)
  NU_temp.nu_day  =ntohl(StrToInt(OnboardModelTime.FormatString("dd")));
  NU_temp.nu_month=ntohl(StrToInt(OnboardModelTime.FormatString("mm")));
  NU_temp.nu_year =ntohl(StrToInt(OnboardModelTime.FormatString("yyyy")));
  NU_temp.nu_hour =ntohl(StrToInt(OnboardModelTime.FormatString("hh")));
  NU_temp.nu_min  =ntohl(StrToInt(OnboardModelTime.FormatString("nn")));
  NU_temp.nu_sec  =ntohl(StrToInt(OnboardModelTime.FormatString("ss")-3));

  // -- ISS DATA -- //
  // ������ ��������� �.�. � J2000
  NU_temp.vec_j2000_mks[0]=StrToFloat(EnterNuForm->iss_pos_x->Text)*1000;
  NU_temp.vec_j2000_mks[1]=StrToFloat(EnterNuForm->iss_pos_y->Text)*1000;
  NU_temp.vec_j2000_mks[2]=StrToFloat(EnterNuForm->iss_pos_z->Text)*1000;
  // �������� �.�. � J2000
  NU_temp.vel_j2000_mks[0]=StrToFloat(EnterNuForm->iss_vel_x->Text);
  NU_temp.vel_j2000_mks[1]=StrToFloat(EnterNuForm->iss_vel_y->Text);
  NU_temp.vel_j2000_mks[2]=StrToFloat(EnterNuForm->iss_vel_z->Text);
  // ���������� ����������� ��������� ��� �� ������������ J2000
  // ����������� �� ����� ���������� (��������!)
 // kptg_fnu(StrToFloat(EnterNuForm->ang_psi_iss->Text),
 //          StrToFloat(EnterNuForm->ang_thetta_iss->Text),
 //          StrToFloat(EnterNuForm->ang_gamma_iss->Text),
 //          &q_mks[0],&q_mks[2],&q_mks[3],&q_mks[4]);
  NU_temp.Q_mks[0] =  0.9992133378982547;//ntohl(q_mks[0]);
  NU_temp.Q_mks[1] =  0.0077055334113538;//ntohl(q_mks[1]);
  NU_temp.Q_mks[2] = -0.0172779280692339;//ntohl(q_mks[2]);
  NU_temp.Q_mks[3] = -0.0348548266385634;//ntohl(q_mks[3]);
  // ������ ������� �������� ��� ������������ J2000 � ��������� �� ��� ��
  NU_temp.w_j2000_mks[0]=StrToFloat(EnterNuForm->w_x_iss->Text);
  NU_temp.w_j2000_mks[1]=StrToFloat(EnterNuForm->w_y_iss->Text);
  NU_temp.w_j2000_mks[0]=StrToFloat(EnterNuForm->w_z_iss->Text);
  // ���������� �.�. ��� � �� (�������� �� ������ ����� ��)
  NU_temp.vec_mks_PC[0]=StrToFloat(EnterNuForm->cm_x_iss->Text);
  NU_temp.vec_mks_PC[1]=StrToFloat(EnterNuForm->cm_y_iss->Text);
  NU_temp.vec_mks_PC[2]=StrToFloat(EnterNuForm->cm_z_iss->Text);
  // ����� ���
  NU_temp.m_mk=StrToFloat(EnterNuForm->mass_iss->Text);
  // ������ �������� ������� ���
  NU_temp.mi_mks[0][0]=StrToFloat(EnterNuForm->Jxx_iss->Text);
  NU_temp.mi_mks[1][1]=StrToFloat(EnterNuForm->Jyy_iss->Text);
  NU_temp.mi_mks[2][2]=StrToFloat(EnterNuForm->Jzz_iss->Text);
  NU_temp.mi_mks[0][1]=StrToFloat(EnterNuForm->Jxy_iss->Text);
  NU_temp.mi_mks[1][2]=StrToFloat(EnterNuForm->Jyz_iss->Text);
  NU_temp.mi_mks[2][0]=StrToFloat(EnterNuForm->Jzx_iss->Text);
  //NU_temp.mi_mks[0][2]=StrToFloat(EnterNuForm->Jxz_iss->Text);
  //NU_temp.mi_mks[1][0]=StrToFloat(EnterNuForm->Jyx_iss->Text);
  //NU_temp.mi_mks[2][1]=StrToFloat(EnterNuForm->Jzy_iss->Text);

  // -- �� DATA -- //
  // ������ ��������� �.�. � J2000
  NU_temp.vec_j2000_tk[0]=StrToFloat(EnterNuForm->tk_pos_x->Text)*1000;
  NU_temp.vec_j2000_tk[1]=StrToFloat(EnterNuForm->tk_pos_y->Text)*1000;
  NU_temp.vec_j2000_tk[2]=StrToFloat(EnterNuForm->tk_pos_z->Text)*1000;
  // �������� �.�. � J2000
  NU_temp.vel_j2000_tk[0]=StrToFloat(EnterNuForm->tk_vel_x->Text);
  NU_temp.vel_j2000_tk[1]=StrToFloat(EnterNuForm->tk_vel_y->Text);
  NU_temp.vel_j2000_tk[2]=StrToFloat(EnterNuForm->tk_vel_z->Text);
  // ���������� ����������� ��������� ��� �� ������������ J2000
        // ����������� �� ����� ����������
  NU_temp.Q_tk[0]=0.06356357343;   // Qs
  NU_temp.Q_tk[1]=1;   // Qx
  NU_temp.Q_tk[2]=0.77777;   // Qy
  NU_temp.Q_tk[3]=0;   // Qz
  // ������ ������� �������� �� ������������ J2000 � ��������� �� ��� ��
  NU_temp.w_j2000_tk[0]=StrToFloat(EnterNuForm->w_x_tk->Text);
  NU_temp.w_j2000_tk[1]=StrToFloat(EnterNuForm->w_y_tk->Text);
  NU_temp.w_j2000_tk[0]=StrToFloat(EnterNuForm->w_z_tk->Text);
  // ���������� �.�. �� � ���/��� (�������� �� ������ ����� ��)
  NU_temp.vec_tk_TPK[0]=StrToFloat(EnterNuForm->cm_x_tk->Text);
  NU_temp.vec_tk_TPK[1]=StrToFloat(EnterNuForm->cm_y_tk->Text);
  NU_temp.vec_tk_TPK[2]=StrToFloat(EnterNuForm->cm_z_tk->Text);
  // ����� ��
  NU_temp.m_tk=StrToFloat(EnterNuForm->mass_tk->Text);
  // ������ �������� ������� ��
  NU_temp.mi_tk[0][0]=StrToFloat(EnterNuForm->Jxx_tk->Text);
  NU_temp.mi_tk[1][1]=StrToFloat(EnterNuForm->Jyy_tk->Text);
  NU_temp.mi_tk[2][2]=StrToFloat(EnterNuForm->Jzz_tk->Text);
  NU_temp.mi_tk[0][1]=StrToFloat(EnterNuForm->Jxy_tk->Text);
  NU_temp.mi_tk[1][2]=StrToFloat(EnterNuForm->Jyz_tk->Text);
  NU_temp.mi_tk[2][0]=StrToFloat(EnterNuForm->Jzx_tk->Text);
  //NU_temp.mi_tk[0][2]=StrToFloat(EnterNuForm->Jxz_tk->Text);
  //NU_temp.mi_tk[1][0]=StrToFloat(EnterNuForm->Jyx_tk->Text);
  //NU_temp.mi_tk[2][1]=StrToFloat(EnterNuForm->Jzy_tk->Text);
  // ����� ������� ��
  NU_temp.nu_com_zapas=StrToFloat(EnterNuForm->tk_toplivo->Text);

  // ����� ������������ ���
  if(EnterNuForm->r_st_free->Checked)  NU_temp.r_st_mks=ntohl(0); else
  if(EnterNuForm->r_st_tp->Checked)    NU_temp.r_st_mks=ntohl(1); else
  if(EnterNuForm->r_st_osk->Checked)   NU_temp.r_st_mks=ntohl(2); else
  if(EnterNuForm->r_st_wconst->Checked)NU_temp.r_st_mks=ntohl(3);
  // ����� �� � �������� ����������� �� (��� ������������ ���������)
  NU_temp.nu_otor_switch_styk_dk=ntohl(EnterNuForm->docking_uz->ItemIndex);

  // ����� �� � �������� ����������� ������������ (��� ��)
  NU_temp.n_su_4_dk=ntohl(EnterNuForm->dk_su->ItemIndex);

  // ������� �������������� ��������� �� � ���
  if(EnterNuForm->docking_pr->Checked) NU_temp.pr_doking=ntohl(1); else NU_temp.pr_doking=ntohl(0);

  // "������� ���" (������� ����������� ����)
  if(EnterNuForm->sm_dp_so->Checked) NU_temp.nu_mlm_sost=ntohl(1); else
  if(EnterNuForm->sm_dp_mlm->Checked) NU_temp.nu_mlm_sost=ntohl(2);
  // ��������� ����� ������ ����
  if(EnterNuForm->avtsbl_pr->Checked) NU_temp.nr_sudn =ntohl(1); else
  if(EnterNuForm->roak_pr->Checked)   NU_temp.nr_sudn =ntohl(2); else
  if(EnterNuForm->rodk_pr->Checked)   NU_temp.nr_sudn =ntohl(3);
  NU_temp.vec_solar[0] = 5555;      // ������ �� ������ � J2000 - ����������� ��� ���������  (�������� � ��������� ������� ���������)
  NU_temp.vec_solar[1] = 5555;
  NU_temp.vec_solar[2] = 5555;

J[0]=NU_temp.mi_tk[0][0];
J[1]=NU_temp.mi_tk[0][1];
J[2]=NU_temp.mi_tk[0][2];
J[3]=NU_temp.mi_tk[1][0];
J[4]=NU_temp.mi_tk[1][1];
J[5]=NU_temp.mi_tk[1][2];
J[6]=NU_temp.mi_tk[2][0];
J[7]=NU_temp.mi_tk[2][1];
J[8]=NU_temp.mi_tk[2][2];

// -- �� ��� ��������� ������/������� --
// ���������� ��������� ����
SpsDataSt.TSpsParam[20] = 2300.0;
SpsDataSt.TSpsParam[14] = 2200.0;
SpsDataSt.TSpsParam[14] = 2200.0;
//SpsDataSt.TSpsParam[25] = 180.50;
SpsDataSt.TSpsParam[26] = 180.90;
SpsDataSt.TSpsParam[21] = 2670.09;
SpsDataSt.TSpsParam[22] = 2670.13;
SpsDataSt.TSpsParam[13] = 230.0;
SpsDataSt.TSpsParam[10] = 230.0;
SpsDataSt.TSpsParam[19] = 7000.0;
SpsDataSt.TSpsParam[3] = 0.0;

NUotr = true; // �������� ��������� ��������� ������� �� ������������

struct{
int i;
int s;
int aa;
int ddd;
unsigned long a_a;
unsigned long b_a;
unsigned long b_b;
unsigned long b_c;
unsigned long c_a;
unsigned long c_b;
unsigned long c_c;
}assa;

if(bum_pr){
NU_temp.i = 0x02000700;
NU_temp.s = 0x00001500;
NU_temp.aa = ntohl(0x00100101);
NU_temp.ddd = ntohl(500);
iResult = send( TeleSocket,(char *)&NU_temp,524, 0  );        //
if (iResult == SOCKET_ERROR) { GetWsaError(WSAGetLastError()); } else {
StatusBar->Panels->Items[0]->Text="������ ������� - ��������� ��! �������� ������� �������������...";  }
iResult = recv( TeleSocket,(char *)&PS_tk_iss,1025, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError()); else JPS(1,is_bum,is_miu,"��������� ��������� ���������","");  } else
StatusBar->Panels->Items[0]->Text="������ ������� - ��������� ��! �������� ������� �������������...";
// �������� ������������� �� ��� //
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::PuskRgPrTimer(TObject *Sender)
{
if(con&&init&&NUotr){
  pusk_btn->Enabled=true;
  PuskRgPr->Enabled=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N25Click(TObject *Sender)
{
sotr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::inpu_com2_connectTimer(TObject *Sender)
{
if(!inpu_com2_connect_pr){
// �������� ������ ������������ � ����
SPSSocket_ch1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
// ���������� ��������� ����� ������ � ��������
char * ipaddress = inpu_con_data[0].c_str(); // Current IP from INI config
int portdata = StrToInt(inpu_con_data[2]);
clientInPU_COM2.sin_family = AF_INET;
clientInPU_COM2.sin_addr.s_addr = inet_addr(ipaddress);
clientInPU_COM2.sin_port = htons(portdata);
iResult = connect(SPSSocket_ch1, (SOCKADDR *) & clientInPU_COM2, sizeof (clientInPU_COM2));
  if (iResult == SOCKET_ERROR)
  {
  qwe++;
  // �������� �� ������ ����������
  } else {
inpu_com2_connect_pr=true;
inpu_com2_connect->Enabled=false;
JPS(4,"������� ������������� ������ � ���� �������� �������.","","","");
arg_tst->Enabled;
inpu_status_pic->Invalidate();
ModelStatusPicList->GetBitmap(1, inpu_status_pic->Picture->Bitmap);
}
}
//Label19->Caption="������� ������ ����������: "+IntToStr(qwe);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button7Click(TObject *Sender)
{
CentralLightBlink->Enabled=true;
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::arg_tstTimer(TObject *Sender)
{
 CounterNo++;                                        // ����� ������ +1
PacketHeaderType.Signature = PacketSignatureR;      // ��������� ������
PacketHeaderType.No = CounterNo;                    // ����� ������
PacketHeaderType.Size = sizeof(USO_BT);             // ������ ������ = ������ ������ ���
PacketHeaderType.PacketID = PacketIDtype(idUso);    // USO


// ��������� ��������
// ����� "00"
/*
   ���������          �����  �����          ��������   */
S_00[0]+= (int)USO_Booled[0][0];  //  00F - KSP A1
S_00[0]+= (int)USO_Booled[0][1];  //  00E - KSP A3
S_00[0]+= (int)USO_Booled[0][2];  //  00D - KSP A5
S_00[0]+= (int)USO_Booled[0][3];  //  00C - KSP A7

S_00[1]+= (int)USO_Booled[0][4];  //  00B - KSP A9
S_00[1]+= (int)USO_Booled[0][5];  //  00A - KSP A11
S_00[1]+= (int)USO_Booled[0][6];  //  009 - KSP A13
S_00[1]+= (int)USO_Booled[0][7];  //  008 - KSP A15

S_00[2]+= (int)USO_Booled[0][8];  //  007 - KSP A17
S_00[2]+= (int)USO_Booled[0][9];  //  006 - KSP b1
S_00[2]+= (int)USO_Booled[0][10]; //  005 - KSP b3
S_00[2]+= (int)USO_Booled[0][11]; //  004 - KSP b5

S_00[3]+= (int)USO_Booled[0][12]; //  003 - KSP b7
S_00[3]+= (int)USO_Booled[0][13]; //  002 - KSP b9
S_00[3]+= (int)USO_Booled[0][14]; //  001 - KSP b11
S_00[3]+= (int)USO_Booled[0][15]; //  000 - KSP b13

/* ����� 00 */
BinA[0]=XtoY(Trim(S_00[0]), StrToIntDef(2, 10), StrToIntDef(16, 10));
BinA[1]=XtoY(Trim(S_00[1]), StrToIntDef(2, 10), StrToIntDef(16, 10));
BinA[2]=XtoY(Trim(S_00[2]), StrToIntDef(2, 10), StrToIntDef(16, 10));
BinA[3]=XtoY(Trim(S_00[3]), StrToIntDef(2, 10), StrToIntDef(16, 10));

/* ����� 10 */
//Bin_USO_10[0]=XtoY(Trim(S_10[0]), StrToIntDef(2, 10), StrToIntDef(16, 10));  // ���� - �1
//Bin_USO_10[1]=XtoY(Trim(S_10[1]), StrToIntDef(2, 10), StrToIntDef(16, 10));  // ���� - �2
//Bin_USO_10[2]=XtoY(Trim(S_10[2]), StrToIntDef(2, 10), StrToIntDef(16, 10));  // ���� - �3
//Bin_USO_10[3]=XtoY(Trim(S_10[3]), StrToIntDef(2, 10), StrToIntDef(16, 10));  // ���� - �4

dOUT = "0x"+BinA[0]+BinA[1]+BinA[2]+BinA[3];                             // 00
//S_10_out = "0x"+Bin_USO_10[0]+Bin_USO_10[1]+Bin_USO_10[2]+Bin_USO_10[3]; // 10

STR_00 = StrToInt(dOUT);
//STR_10 = StrToInt(S_10_out);

USO_BT[0] = STR_00;
//USO_BT[16] = STR_10;
iResult = send(SPSSocket_ch1,(char *)&PacketHeaderType,9, 0  );       // �������� ��������� ������
iResult = send(SPSSocket_ch1,(char *)&USO_BT,sizeof(USO_BT), 0  );    // �������� �����
for (int i=0; i<3; i++)                                               // Clear S_
{
S_00[i]="0";
}
/*
*/
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N5Click(TObject *Sender)   // KSP Right
{
//ksppfrm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::CentralLightBlinkTimer(TObject *Sender)  // ������ ������������ ��
{
if(co_priz){
if(Cl_blink){
CO_light->Color=StringToColor("0x45607B");
Cl_blink=false;} else {
CO_light->Color=clRed;
Cl_blink=true;
}
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MainTimerTimer(TObject *Sender)
{
Label13->Caption=(ob_cur-onboard_dt).FormatString("hh:nn:ss");
USO_Booled[10][7] = dpo_status_bit;
if(USO_Booled[12][7])YzS1[0]=1;
///////////////////
// ���������� �� //
///////////////////
if(cw_TA08[1]) JPS(3,is_sudn,is_operator,str_TA_08[1],""); else
if(cw_TA08[2]) JPS(3,is_sudn,is_operator,str_TA_08[2],""); else
if(cw_TA08[3]) JPS(3,is_sudn,is_operator,str_TA_08[3],""); else
if(cw_TA08[4]) JPS(3,is_sudn,is_operator,str_TA_08[4],""); else
if(cw_TA08[5]) JPS(3,is_sudn,is_operator,str_TA_08[5],""); else
if(cw_TA08[6]) JPS(3,is_sudn,is_operator,str_TA_08[6],""); else
if(cw_TA08[7]) JPS(3,is_sudn,is_operator,str_TA_08[7],""); else
if(cw_TA08[8]) JPS(3,is_sudn,is_operator,str_TA_08[8],""); else
if(cw_TA08[9]) JPS(3,is_sudn,is_operator,str_TA_08[9],""); else
if(cw_TA08[10]) JPS(3,is_sudn,is_operator,str_TA_08[10],""); else
if(cw_TA08[11]) JPS(3,is_sudn,is_operator,str_TA_08[11],""); else
if(cw_TA08[12]) JPS(3,is_sudn,is_operator,str_TA_08[12],""); else
if(cw_TA08[13]) JPS(3,is_sudn,is_operator,str_TA_08[13],""); else
if(cw_TA08[14]) JPS(3,is_sudn,is_operator,str_TA_08[14],""); else
if(cw_TA08[15]) JPS(3,is_sudn,is_operator,str_TA_08[15],"");

///////////////////
// ���������� C� //
///////////////////
if(cw_SA[10]) JPS(3,is_sudn,is_operator,CA_EMER[10],""); else
if(cw_SA[11]) JPS(3,is_sudn,is_operator,CA_EMER[11],""); else
if(cw_SA[12]) JPS(3,is_sudn,is_operator,CA_EMER[12],""); else
if(cw_SA[13]) JPS(3,is_sudn,is_operator,CA_EMER[13],""); else
if(cw_SA[14]) JPS(3,is_sudn,is_operator,CA_EMER[14],""); else
if(cw_SA[15]) JPS(3,is_sudn,is_operator,CA_EMER[15],"");

tskd_time_label->Caption="���� = "+data_TSKD.FormatString("hh:nn:ss.zzz");
Label42->Caption="������ ����� t1: "+gc1_time.FormatString("hh:nn:ss.zzz");
if(testb->ItemIndex==0) GSO_types=0; else
if(testb->ItemIndex==1) GSO_types=1; else
if(testb->ItemIndex==2) GSO_types=2; else
if(testb->ItemIndex==3) GSO_types=3; else
if(testb->ItemIndex==4) GSO_types=4; else
if(testb->ItemIndex==5) GSO_types=5;

// Only for KSP test
/////////////////////////////////////////////
// � � � � � � � � �   � � � � � �   � � � //
/////////////////////////////////////////////
if(KSP_Booled[0][0]) { // A 1
// ��������� �������� �������� ������ ��� (��� �������� ���)
if(i_test==80) { // ����� �������� 16 ������ = 16000 �� = 80 ������ �� 200 ��
USO_Booled[0][0]=true;   //
JPS(1,"������ ��� �������","","","");
KSP_Booled[0][0] = false;
i_test=0;
}else
i_test++;
}

if(KSP_Booled[0][1]) {  // A 2
if(i_test==80) {
USO_Booled[0][0]=false;
JPS(1,"������ ��� �������","","","");
KSP_Booled[0][1] = false;
i_test=0;
}else
i_test++;
}

if(KSP_Booled[0][2]) {  // A 3   ������ ��� - ���
KSP_Booled[0][2] = false;
USO_Booled[0][1]=true;
}

if(KSP_Booled[0][3]) {  // A 4   ������ ��� - ����
KSP_Booled[0][3] = false;
USO_Booled[0][1]=false;
}

if(KSP_Booled[0][4]) { // A 5     ��� ����
KSP_Booled[0][4] = false;
// 98 - ���������� ��� (���) �� ����� ����������
USO_Booled[0][2]=true;
}

if(KSP_Booled[0][5]) { // A 6
KSP_Booled[0][5] = false;
// -98 - ����������� ��� (���) � ����� ����������
USO_Booled[0][2]=false; }

if(KSP_Booled[0][6]) { // A 7
KSP_Booled[0][6] = false;
USO_Booled[0][3]=true;
}

if(KSP_Booled[0][7])  // A 8
USO_Booled[0][3]=false;

if(KSP_Booled[0][8])  // A 9
USO_Booled[0][4]=true;

if(KSP_Booled[0][9])  // A 10
USO_Booled[0][4]=false;

if(KSP_Booled[0][10]) { // A 11
KSP_Booled[0][10] = false;
USO_Booled[0][5]=true;
}

if(KSP_Booled[0][11]) { // A 12
KSP_Booled[0][11] = false;
USO_Booled[0][5]=false;
}

if(KSP_Booled[0][12])  // A 13
USO_Booled[0][6]=true;

if(KSP_Booled[0][13])  // A 14
USO_Booled[0][6]=false;

if(KSP_Booled[0][14])  // A 15
USO_Booled[0][7]=true;

if(KSP_Booled[0][15])  // A 16
USO_Booled[0][7]=false;

if(KSP_Booled[0][16])  // A 17
USO_Booled[0][8]=true;

if(KSP_Booled[0][17])  // A 18
USO_Booled[0][8]=false;

if(KSP_Booled[2][0]) { // � 1
KSP_Booled[2][0] = false;
// 5.12 ����� ������ ������ ������� ���
USO_Booled[1][2]=true;
USO_Booled[11][9]=false;  // ����� ��-7 "2 ������ �������"
}

if(KSP_Booled[2][1]) { // � 2
KSP_Booled[2][1] = false;
// -5.12 ����� ������ ������ ������� ���
USO_Booled[1][2]=false;
USO_Booled[11][9]=true;  // �������� ��-7 "2 ������ �������"
}

if(KSP_Booled[2][2]) { // � 3
KSP_Booled[2][2] = false;
USO_Booled[1][3]=true;
USO_Booled[11][10]=false;  // ����� ��-7 "2 ������ ���"
}

if(KSP_Booled[2][2]) { // � 4
KSP_Booled[2][2] = false;
USO_Booled[1][3]=false;
USO_Booled[11][10]=true;  // P�������� ��-7 "2 ������ ���"
}

if(KSP_Booled[3][0]) { // � 1
KSP_Booled[3][0] = false;
USO_Booled[1][11]=true;
}

if(KSP_Booled[3][1]) { // � 2
KSP_Booled[3][1] = false;
USO_Booled[1][11]=false;
}

if(KSP_Booled[3][4]) {  // � 5
KSP_Booled[3][4] = false;
//5.18 ���������� � ��� ���-�1 (17, 18)
USO_Booled[1][13]=true;
// � ���� ���������� ���-�2 (27, 28)
USO_Booled[1][14]=false;
}

if(KSP_Booled[3][6]) {  // � 7
KSP_Booled[3][6] = false;
//5.19 ���������� � ��� ���-�2 (27, 28)
USO_Booled[1][14]=true;
// � ���� ���������� ���-�1 (17, 18)
USO_Booled[1][13]=false;
}

if(KSP_Booled[3][8]) {  // � 9  ����-1
KSP_Booled[3][8] = false;
//27.1 ��� ��1 (��� ��� 1 �����), ��������� � ���-7 "��� ��1"
USO_Booled[1][15]=true; // ������� ������ ����-1
//-27.2 ���� ��2, ���� � ���-7 "���� ��2"
USO_Booled[2][0]=false; // ������� ������� ������ ����-2
//27.3 ��� ��3 (��� ��� ��� ����), ���� � ���-7 "��� ��3"
//27.9 ������ �� 1 �������� ���
}

if(KSP_Booled[3][10]) {  // � 11 ����-2
KSP_Booled[3][10] = false;
//-27.1 ���� ��1, ��������� � ���-7 "���� ��1"
USO_Booled[1][15]=false;
//27.2 ��� ��2, ���� � ���-7 "��� ��2"
USO_Booled[2][0]=true;
//27.3 ��� ��3 (��� ��� ��� ����), ���� � ���-7 "��� ��3"
//-27.9 ������ �� 2 �������� ���
KSP_Booled[3][10] = false;
}

if(KSP_Booled[3][12]) {  // � 13 ���� ����
KSP_Booled[3][12] = false;
//-27.1 ���� ��1, ��������� � ���-7 "���� ��1"
USO_Booled[1][15]=false;
//-27.2 ���� ��2, ���� � ���-7 "���� ��2"
USO_Booled[2][0]=false;
//-27.3 ���� ��3 , ���� � ���-7 "���� ��3"
KSP_Booled[3][12] = false;
}

if(KSP_Booled[3][14]) { // �15
KSP_Booled[3][14] = false;
USO_Booled[1][13]=true;
USO_Booled[1][14]=true;
}

if(KSP_Booled[6][0]) { // �1   ���
KSP_Booled[6][0] = false;
USO_Booled[3][6]=true;
}

if(KSP_Booled[6][1]) { // �2   ���
KSP_Booled[6][1] = false;
USO_Booled[3][6]=false;
}

if(KSP_Booled[6][2]) { // �3 ���
KSP_Booled[6][2] = false;
// �������� ������� ���� + ��020
USO_Booled[3][7]=true;
}

if(KSP_Booled[6][3]) { // �4 ���
KSP_Booled[6][3] = false;
USO_Booled[3][7]=false;
}

if(KSP_Booled[6][8]) {  // �9 ������� �����
KSP_Booled[6][8] = false;
// �������� ������� � ���
//USO_Booled[0][8]=false;
USO_Booled[3][10]=true; // ������� ������� �����
USO_Booled[0][1]=true;  // ������ ��� �� ������� �����
// ��� �� ���������� ����-1 � ���
}

if(KSP_Booled[6][10]) { // �11   -  ���� �����
KSP_Booled[6][10] = false;
USO_Booled[3][11]=true;
//     � 9                � 15
//if(USO_Booled[3][11]&&USO_Booled[3][14])
// �������� �� ����� ����� //
// 1 - �������� (� ������) � �� ����������� - ������ ��� ���
ArgonTakt->Enabled=true;  // ������

}

if(KSP_Booled[5][10]){  // KSP �11
KSP_Booled[5][10] = false;
USO_Booled[3][2] = true;
USO_Booled[3][3] = false;
USO_Booled[3][4] = false;
USO_Booled[3][13] = false; }
if(KSP_Booled[5][12]){  // KSP �13
KSP_Booled[5][12] = false;
USO_Booled[3][2] = false;
USO_Booled[3][3] = true;
USO_Booled[3][4] = false;
USO_Booled[3][13] = false; }
if(KSP_Booled[5][14]){  // KSP �15
KSP_Booled[5][14] = false;
USO_Booled[3][2] = false;
USO_Booled[3][3] = false;
USO_Booled[3][4] = true;
USO_Booled[3][13] = false; }
if(KSP_Booled[6][14]) { // � 15
KSP_Booled[6][14] = false;
USO_Booled[3][2]=false;
USO_Booled[3][3]=false;
USO_Booled[3][4]=false;
USO_Booled[3][13]=true;  }


if(KSP_Booled[7][16]) { // � 17
KSP_Booled[7][16] = false;
USO_Booled[4][8]=true;
sp_d_k = 1; // ������� ������������ ����
}

if(KSP_Booled[7][17]) { // � 18
KSP_Booled[7][17] = false;
USO_Booled[4][8]=false;
sp_d_k = 0; // �������� ������������ ����
}

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ModelDateTime_TimerTimer(TObject *Sender)
{
OnboardModelTime=OnboardModelTime+StrToTime("00:00:01");
onboardTimeLabel->Caption=OnboardModelTime.FormatString("hh:nn:ss");
Label45->Caption="����� �� ����-:08: = "+gc1_time.FormatString("hh:nn:ss");
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N26Click(TObject *Sender)
{
BFI_Simvol_form->Show();
}
//---------------------------------------------------------------------------
// � � � �   � � � � � �
void __fastcall TMainForm::ArgonTaktTimer(TObject *Sender)
{
if(!arg_work_pr){        // ���� ��� �������� ������ ������ (��������� ������������) - ��������� � ��������� �������
// �������� ������������ - self_test. ���� ��������� �����������������, ���������� ��������������� ��������
   if(sp_d_k==1) {  // ���� ������� ������� ������������ (1 ������ - t), ��...
      if(t==300) tResult = self_test_long(); else t++; } else
   if(sp_d_k==0) {  // ���� ������� �������� ������������ (5 ������), ��...
      if(t==25)  tResult = self_test_short();else t++; }
Label22->Caption=IntToStr(t);
// �� ��������� ����� ��������� ��������� - ���� = 0, �� ���� ������ ������ � �����
if(self_test_pr) {          // ���� ���� ������� ��������� �����
if(tResult==0){             // ���������� ��������������� ��������...
   USO_Booled[11][6]=true;} // ���������� ������� ���� ����� �� ���
else if(!tResult==0){       // ���� �� ����� ����� ��������� ������ (Result != 0), �����
   arg_acc_handler(tResult);// �������� ���������� ������ ������
   ArgonTakt->Enabled=false;}// ���������� ������ ����
if(USO_Booled[11][6]){      // ���� ���� ���������� ����, ��...
   arg_work_pr = true;      // ������� ������ ������ (�� ���� ���������� ������)
   USO_Booled[11][7]=true;  // ���������� "���" ��� ��� (�� ����?)
   test_test_tse=0;         // ?
 // ��� �� ���������� ������ �� ��������� ��������� ��������� ������� (����)
 }
 } //self_test_pr
} else {
// � ��� "�����-3" �� ������ ������� ����� ���������� ������������ (��) - self_check

//---------//
// � � � � //
// ��������� ��������� ��������� ������� //
//=======================================//
// ���� ���� ������ �� ����, ��...


// ���� ������� ��������� -


//
/*****************************************/
// � � � �   � � � � � � � � � � � � � � //
// � � � � � � � � � �   � � � � � � � � //
/*****************************************/
if(i_tok==5){
///////////////////////////////
//                           //
// �. ������������ ��������  //
//                           ////////////////////////////////////////////
// �������� ������ ��� ��������� ��������� - (������� ������ ��������� //
/////////////////////////////////////////////////////////////////////////

////////////
// ������ //
////////////
dynamics.Y2 = pow((2 * dynamics.ax1 * (dynamics.rs - 202)),0.5);

if(dynamics.sks > dynamics.Y2){
Panel1->Caption="������ |V|>9 m/s";
Panel1->Font->Color=clRed;
} else {
Panel1->Caption="���";
Panel1->Font->Color=clYellow;
}

if(dynamics.rasp < 20){
Panel1->Caption="��������� �� !";
Panel1->Font->Color=clRed;
} else {
Panel1->Caption="���";
Panel1->Font->Color=clYellow;
}

if(dynamics.rs<10&&dynamics.sks>1){
Panel1->Caption="������� �������� n\�� ����� ���������!";
Panel1->Font->Color=clRed;
} else {
Panel1->Caption="���";
Panel1->Font->Color=clYellow;
}

/* ������

///////////////////////////////////
// ������ ������� ������� �� ��� //
///////////////////////////////////
dynamics.rudkg = abs(dynamics.ax*0.046/0.01849)+abs(dynamics.ay*0.046/0.01915)+abs(dynamics.az*0.046/0.01897);

///////////////////////////////////////////
// ������ ������� ������� �� ����������� //
// �������� ��� ������� �����������      //
///////////////////////////////////////////
dynamics.kvkg = abs(0.209 * 0.046 * dynamics.ay / 0.0383 / 0.621) + abs(0.209 * 0.046 * dynamics.az / 0.03794 / 0.592);

/////////////////////////////////////////
// ����� ������ ������� (�� ���������) //
/////////////////////////////////////////
//                                         ���             ����             ���               ���               ���
dynamics.rasp = dynamics.rasp - (dynamics.rudkg + dynamics.kvkg + dynamics.ruokgx + dynamics.ruokgy + dynamics.ruokgz);

////////////////////////////////////////////////////
// ��������� ������� ���������� �������� � ������ //
// ������� ��������� ��� �������� ����������.     //
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// ������ ���������� ��������� //  ������  0.001  //
////////////////////////////////////////////////////
dynamics.rs = pow((pow((dynamics.rs - ht * dynamics.sks),2) + pow((ht * dynamics.rs * 0.017453),2) *
(dynamics.omy * dynamics.omy + dynamics.omz * dynamics.omz)),0.5);

////////////////////////////////////////////////////
// ������ ���������� ��������  //  ������  0.001  //
////////////////////////////////////////////////////
dynamics.sks = ht * (dynamics.axd + dynamics.axruo - dynamics.ax) + (dynamics.rs * dynamics.sks - ht *
(pow(dynamics.sks,2) + (pow(dynamics.omy,2) + pow(dynamics.omz,2)) * pow((0.017453 * dynamics.rs),2))) / dynamics.rs;

///////////////////////////////////////////////
// ������ ������� �������� ����� ����������� //
// �� ����������� (��� OY) � �� ������� (OZ) //
///////////////////////////////////////////////
dynamics.omy = dynamics.omy * pow((dynamics.rs / dynamics.rs),2) + 57.3 * dynamics.az / dynamics.rs;
dynamics.omz = dynamics.omz * pow((dynamics.rs / dynamics.rs),2) + 57.3 * dynamics.ay / dynamics.rs;

dynamics.omyf = (dynamics.omy * cos(dynamics.uomx * 0.017454) + dynamics.omz * sin(dynamics.uomx * 0.017454));
dynamics.omzf = (dynamics.omz * cos(dynamics.uomx * 0.017454) - dynamics.omy * sin(dynamics.uomx * 0.017454));

////////////////////////////
// �������������� ������� //
////////////////////////////
dynamics.V = pow(pow((pow(dynamics.sks, 2) + dynamics.vb),2),0.5);
dynamics.axd = abs(dynamics.ay * 0.157959) + abs(dynamics.az * 0.157924) + abs(dynamics.az * 0.157924) + abs(dynamics.az * 0.157924);

////////////////////
// ������ ������� //
////////////////////
dynamics.ypr = pow(dynamics.omz * dynamics.rs,2) * 0.017453 / dynamics.V;   //  Sy
dynamics.zpr = pow(dynamics.omy * dynamics.rs,2) * 0.017453 / dynamics.V;   //  Sz
dynamics.Spr = dynamics.rs * dynamics.vb / dynamics.V;                      //  S

//////////////////////////////
// ������ ������� ��������� //
//////////////////////////////
dynamics.vby = dynamics.omz * dynamics.rs * 0.017453;
dynamics.vbz = dynamics.omy * dynamics.rs * 0.017453;

//////////////////
// ������ ����� //
//////////////////

dynamics.uomy = dynamics.uomy + 25 * 0.9 * (dynamics.omy + dynamics.Ey); // ���� =  1 ���*����� �
dynamics.uomz = dynamics.uomz + 25 * 0.9 * (dynamics.omz + dynamics.Ez); // ����  �� ����� z + �������� ���
dynamics.uomx = dynamics.uomx + dynamics.Ex;                             // ����  ��  �������� ���

//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*

///////////////////////////////
// ���������� �������������  //
//   ��������� �� ��������   //
///////////////////////////////

������ */ 

//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*

//////+///////////////////////////////+//////
//=//   � � � �   � � � � � � � � � �   //=//
//+//   � � � � � � � � � � � � � � �   //+//
//=//        � � � � � � � � � �        //=//
//////+///////////////////////////////+//////

///////////////////////////////////////////
// ������������ ������������ � ��������� //
///////////////////////////////////////////
if(argon_auto_contr){
 if(dynamics.omz>0.001) dynamics.Ez = -0.62063 * 0.5; else dynamics.Ez = 0;
}

//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*

} else i_tok++; // ��� �� �������������� ���� � ����� � �������

if(cw_b1[12]) USO_Booled[12][7]=1; else USO_Booled[12][7]=0;

if(cw_b1[12]&&!USO_Booled[3][7]){
if(YzS1[0]&&YzS1[1]==0){ // ���� ���� ������ �� "������������"
 f_test++;
 Label46->Caption="��������� ������ �� ������������: "+IntToStr(f_test);
 YzS1[1]=1;
}
}

vill_test=1;
// Start integer if I9 and I11 = true
//i_takt++;


///////////////////////////////
// ���������� ����� �������� //
//    ������������ �����     //
///////////////////////////////
if(cw_b1[7]) { // If "IR" true
 // ������ ������ �� ������������ ����������� ��������� �� ���
 // ������ ������ �� ������������ ���
 // ������ ������ �� �������� ������� �������
 // ������ ������ �� �������� ���������� � ���
 // ������ ������ �� ������������ ��������
}

/* ���������� ����������� ��������� */
if(cw_b6[13]) { // "���������� ������������"
// ����� "��� ���" (������?)
// ��� �� ������� � ���
if(!WithoutBum->Checked&&!arg_half_false[1]){
JPS(4,"����������: ������ ������� � ���� \"������������\", ������ ���������...","","","");
SendToBum(0x0000029D, 1, 1);
arg_half_false[1]=true;}
}

if(USO_Booled[0][0]){  // Check Open SKD S001.1
if(pr_TSKD){ // ���� �����.���� = ����  S001
  JPS(4,"����������: ������ ������� � ���� \"��������� ���\", ������ S001.1","","","");
  arg_du_on_skd();
  pr_TSKD = false;
} // S001
} // S001.1
} // else !arg_work_pr
}
//-----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+--
//----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---
//---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+----

void __fastcall TMainForm::N27Click(TObject *Sender)
{
InstructorFormat_FRM->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button12Click(TObject *Sender)
{
cw_b6[11] = 1; // Docking integer flag
cw_b6[14] = 0; // ���������� ��������� �� ����� ��
cw_b6[8] = 1;  // ���������� ���������
GSO_types=2;
JPS(4,is_operator,is_miu,"���������� - ���� - ������������","");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ChekTSKDTimer(TObject *Sender)
{

if(OnboardModelTime.TimeString()==data_TSKD.TimeString()&&cw_b1[12]){     // ��� ����� ����������? �������� ���� ������?
 pr_TSKD=1;
 ChekTSKD->Enabled=false;
} else {
arg_test_pr++;
}
}
//---------------------------------------------------------------------------

double _SinSps (double Min, double Max, double TimeDiv){
double _SinO;
 _SinO  = (Max+Min)/2+(Max-Min)/2*sin(t/TimeDiv);
 return _SinO;
}


void __fastcall TMainForm::N28Click(TObject *Sender)
{
zakon_upr_frm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Button5Click(TObject *Sender)
{
argon_auto_contr = true;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N29Click(TObject *Sender)
{
vkugraph->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N30Click(TObject *Sender)
{
iss_t_tp->Show();
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::N32Click(TObject *Sender)
{
brus_frm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N33Click(TObject *Sender)
{
liftoff_form->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N20Click(TObject *Sender)
{
sm_ssvp_plx_frm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::SpsSendTimer(TObject *Sender)
{
if(inpu_com2_connect_pr){
CounterNo++;
PacketHeaderType.Signature = PacketSignatureR;
PacketHeaderType.No = CounterNo;
PacketHeaderType.Size = sizeof(SpsDataSt.TSpsParam);
PacketHeaderType.PacketID = PacketIDtype(idData);   // SPS Data
//int *p_dta = &SpsDataSt;
iResult = send(SPSSocket_ch1,(char *)&PacketHeaderType,9, 0  );
iResult = send(SPSSocket_ch1,(char *)&SpsDataSt,sizeof(SpsDataSt), 0  );
Label72->Caption="������� ���: "+IntToStr(CounterNo); }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button15Click(TObject *Sender)
{
SpsDataSt.TSpsParam[StrToInt(sps_num->Text)]=StrToInt(Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button16Click(TObject *Sender)
{
if(inpu_com2_connect_pr){
CounterNo++;
PacketHeaderType.Signature = PacketSignatureR;
PacketHeaderType.No = CounterNo;
PacketHeaderType.Size = sizeof(wpControlCodeTypeN);
PacketHeaderType.PacketID = PacketIDtype(idControl);   // Control Packet
packett.CodeType=wpControlCodeTypeN(wpIshod);
//packett.DataType=SoundType(sndEmergency);
iResult = send(SPSSocket_ch1,(char *)&PacketHeaderType,9, 0  );
iResult = send(SPSSocket_ch1,(char *)&packett,2, 0  );   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N161Click(TObject *Sender)
{
arg_deb->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N35Click(TObject *Sender)
{
bum_debug->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::p_sost_from_bumTimer(TObject *Sender)
{
SendToBum(0x00102101, 907, 0);       //������� � ��� ()
iResult = recv( TeleSocket,(char *)&PS_tk_iss,1025, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button1Click(TObject *Sender)
{
PS_tk_iss.fd_1=ntohl(0xcacacaca);
PS_tk_iss.fd_2=ntohl(0xb4b4b4b4);
PS_tk_iss.fd_3=ntohl(123);
PS_tk_iss.fd_4=ntohl(123);
PS_tk_iss.fd_5=ntohl(123);
PS_tk_iss.fd_6=ntohl(123);
PS_tk_iss.tk_type=ntohl(1);
PS_tk_iss.model_sec=ntohl(6578);
PS_tk_iss.milisec_ost=ntohl(987);
PS_tk_iss.vec_j2000_mks[0]=0x7feffffc57ca82ae;
PS_tk_iss.vec_j2000_mks[1]=0x7feffffc57ca82ae;
PS_tk_iss.vec_j2000_mks[2]=0x7feffffc57ca82ae;
PS_tk_iss.sun_vec[0]=0x7feffffc57ca82ae;
PS_tk_iss.sun_vec[1]=0x7feffffc57ca82ae;
PS_tk_iss.sun_vec[2]=0x7feffffc57ca82ae;
PS_tk_iss.vec_tk_TPK[0]=0xc57ca82ae;
PS_tk_iss.vec_tk_TPK[1]=0xc57ca82ae;
PS_tk_iss.vec_tk_TPK[2]=0xc57ca82ae;
PS_tk_iss.t_to_pt=123456789876;
PS_tk_iss.pr_t_pt=1;
PS_tk_iss.fara_pr=ntohl(3);
PS_tk_iss.tv_pr=ntohl(4);
PS_tk_iss.dpo_h[0]=0x7feffffc57ca82ae;
PS_tk_iss.tv_pr=ntohl(9);
PS_tk_iss.iss_tp_pr=3;
PS_tk_iss.CIFC_Wdis[0]=0xDADADADA;
PS_tk_iss.bsr_RUO[0]=0xAFAFAFAF;
PS_tk_iss.bsr_RUO[1]=0xBABABABA;
PS_tk_iss.bsr_RUO[2]=0xAFAFAFAF;
iResult = send( TeleSocket,(char *)&PS_tk_iss,1000, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button10Click(TObject *Sender)
{
SendToBum(StrToInt(Edit5->Text),StrToInt(Edit6->Text),StrToInt(Edit7->Text));       //������� � ��� ()
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N37Click(TObject *Sender)
{
otkazy_frm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button2Click(TObject *Sender)
{
if(bum_pr){
SendToBum(0x00000301, 0, 0);       //����� �������� - ������� � ��� ()
dk_to_bum->Enabled=true;           // ���������� �������� ���������� �� � ���
p_sost_from_bum->Enabled=false;}
start_priz = false;
PuskPr = false;
ModelDateTime_Timer->Enabled=false;
MainTimer->Enabled=false;
ArgonTakt->Enabled=false;
Timer6->Enabled=false;
pusk_btn->Enabled=true;
JPS(1,is_operator,is_miu,"���� �������������","");
StatusBar->Panels->Items[0]->Text="������� ������������� ����������.";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N38Click(TObject *Sender)
{
IrBrForm->Show();  // ����� ����
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::Button11Click(TObject *Sender)
{
dk_mass.dk_per[0]=StrToFloat(Edit11->Text);
dk_mass.dk_per[1]=StrToFloat(Edit10->Text);
dk_mass.dk_per[2]=StrToFloat(Edit9->Text);
dk_mass.dk_ori[0]=StrToFloat(Edit8->Text);
dk_mass.dk_ori[1]=StrToFloat(Edit4->Text);
dk_mass.dk_ori[2]=StrToFloat(Edit2->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dk_to_bumTimer(TObject *Sender)
{
iResult = send( TeleSocket,(char *)&dk_mass,sizeof(dk_mass), 0);   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button13Click(TObject *Sender)
{
co_priz=0;        
}
//---------------------------------------------------------------------------

