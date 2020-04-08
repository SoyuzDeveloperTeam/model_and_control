//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "KSPLForm.h"
#include "USOData.h"
#include "main_header.h"
#include "JouHeader.h"         // ��������� ��� �������
#include "JouStrings.h"        // ��������� ���������� ��� �������
#include "bumconnect.cpp"      // ����� � ���
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tksplfrm *ksplfrm;
//---------------------------------------------------------------------------

__fastcall Tksplfrm::Tksplfrm(TComponent* Owner)
        : TForm(Owner)
{
    Application->Icon->Handle = NULL;
    Icon->Handle = NULL;
}

void __fastcall Tksplfrm::ksp_1Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                           // ���� �������� ����� �
KSP_Booled[0][0]=true;                          // ����� ���������� ������� �1 - ������ (���� ������ ������� ���)
SendToBum(0x000002A8, 0, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�1"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� �
KSP_Booled[2][0]=true;                          // ����� ���������� ������� �1 - ������
JPS(1,is_operator,is_miu,is_ksp,"�1"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][0]=true;                          // ����� ���������� ������� �1 - ������
JPS(1,is_operator,is_miu,is_ksp,"�1"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][0]=true;                          // ����� ���������� ������� �1 - ������
JPS(1,is_operator,is_miu,is_ksp,"�1"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][0]=true;
SendToBum(0x0000029A, 1, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"����������");  // ������
} else

if (KSP_Let[5]){  // �                             ���� �������� ����� �
KSP_Booled[6][0]=true;                          // ����� ���������� ������� �1 - ������
SendToBum(0x000002BA, 1, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�1"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][0]=true;
SendToBum(0x000002B0, 1, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�1"); } else

if (KSP_Let[7]){  // �
KSP_Booled[8][0]=true;
SendToBum(0x00000281, 1, 0);                     //������� � ��� (�� �� - ���)
JPS(1,is_operator,is_miu,is_ksp,"�1"); }

KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;
}
//---------------------------------------------------------------------------




void __fastcall Tksplfrm::ksp_2Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][1]=true;                          // ����� ���������� ������� �2 - ������
SendToBum(0x000002A8, 1, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�2"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][1]=true;                          // ����� ���������� ������� B2 - ������
JPS(1,is_operator,is_miu,is_ksp,"�2"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][1]=true;                          // ����� ���������� ������� �2 - ������
JPS(1,is_operator,is_miu,is_ksp,"�2"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][1]=true;                          // ����� ���������� ������� �2 - ������
JPS(1,is_operator,is_miu,is_ksp,"�2"); } else   // �������� ������ �������

/* if (KSP_Let[4]){  // �
KSP_Booled[4][1]=true;                          // ������
JPS(1,is_operator,is_miu,is_ksp,"�2"); } else   */

if (KSP_Let[5]){  // �
KSP_Booled[6][1]=true;                          // ����� ���������� ������� �2 - ������
SendToBum(0x000002BA, 0, 0);                    // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�2"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][1]=true;                          // ����� ���������� ������� B2 - ������
SendToBum(0x000002B0, 0, 0);                    // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�2"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][1]=true;                          // ����� ���������� ������� B2 - ������
SendToBum(0x00000281, 0, 0);                    // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�2"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall Tksplfrm::KSP_L_A_imageClick(TObject *Sender)
{
KSP_Let[0]=true;
byte i;
for(i=1; i<=16; i++){
 KSP_Let[i]=false;
}
KSP_L_A->Color=clYellow;
KSP_L_A->Font->Color=clBlack;
KSP_L_A_image->Enabled=false;
KSP_L_V_image->Enabled=false;
KSP_L_G_image->Enabled=false;
KSP_L_D_image->Enabled=false;
KSP_L_J_image->Enabled=false;
KSP_L_I_image->Enabled=false;
KSP_L_K_image->Enabled=false;
KSP_L_L_image->Enabled=false;
ksp_1->Enabled=true;
ksp_2->Enabled=true;
ksp_3->Enabled=true;
ksp_4->Enabled=true;
ksp_5->Enabled=true;
ksp_6->Enabled=true;
ksp_7->Enabled=true;
ksp_8->Enabled=true;
ksp_9->Enabled=true;
ksp_10->Enabled=true;
ksp_11->Enabled=true;
ksp_12->Enabled=true;
ksp_13->Enabled=true;
ksp_14->Enabled=true;
ksp_15->Enabled=true;
ksp_16->Enabled=true;
ksp_17->Enabled=true;
ksp_18->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::KSP_L_V_imageClick(TObject *Sender)
{
KSP_Let[0]=false;
KSP_Let[1]=true;
byte i;
for(i=2; i<=16; i++){
 KSP_Let[i]=false;
}
KSP_L_V->Color=clYellow;
KSP_L_V->Font->Color=clBlack;
KSP_L_A_image->Enabled=false;
KSP_L_V_image->Enabled=false;
KSP_L_G_image->Enabled=false;
KSP_L_D_image->Enabled=false;
KSP_L_J_image->Enabled=false;
KSP_L_I_image->Enabled=false;
KSP_L_K_image->Enabled=false;
KSP_L_L_image->Enabled=false;
ksp_1->Enabled=true;
ksp_2->Enabled=true;
ksp_3->Enabled=true;
ksp_4->Enabled=true;
ksp_5->Enabled=true;
ksp_6->Enabled=true;
ksp_7->Enabled=true;
ksp_8->Enabled=true;
ksp_9->Enabled=true;
ksp_10->Enabled=true;
ksp_11->Enabled=true;
ksp_12->Enabled=true;
ksp_13->Enabled=true;
ksp_14->Enabled=true;
ksp_15->Enabled=true;
ksp_16->Enabled=true;
ksp_17->Enabled=true;
ksp_18->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::KSP_L_G_imageClick(TObject *Sender)
{
KSP_Let[0]=false;
KSP_Let[1]=false;
KSP_Let[2]=true;
byte i;
for(i=3; i<=16; i++){
 KSP_Let[i]=false;
}
KSP_L_G->Color=clYellow;
KSP_L_G->Font->Color=clBlack;
KSP_L_A_image->Enabled=false;
KSP_L_V_image->Enabled=false;
KSP_L_G_image->Enabled=false;
KSP_L_D_image->Enabled=false;
KSP_L_J_image->Enabled=false;
KSP_L_I_image->Enabled=false;
KSP_L_K_image->Enabled=false;
KSP_L_L_image->Enabled=false;
ksp_1->Enabled=true;
ksp_2->Enabled=true;
ksp_3->Enabled=true;
ksp_4->Enabled=true;
ksp_5->Enabled=true;
ksp_6->Enabled=true;
ksp_7->Enabled=true;
ksp_8->Enabled=true;
ksp_9->Enabled=true;
ksp_10->Enabled=true;
ksp_11->Enabled=true;
ksp_12->Enabled=true;
ksp_13->Enabled=true;
ksp_14->Enabled=true;
ksp_15->Enabled=true;
ksp_16->Enabled=true;
ksp_17->Enabled=true;
ksp_18->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::KSP_L_D_imageClick(TObject *Sender)
{
KSP_Let[0]=false;
KSP_Let[1]=false;
KSP_Let[2]=false;
KSP_Let[3]=true;
byte i;
for(i=4; i<=16; i++){
 KSP_Let[i]=false;
}
KSP_L_D->Color=clYellow;
KSP_L_D->Font->Color=clBlack;
KSP_L_A_image->Enabled=false;
KSP_L_V_image->Enabled=false;
KSP_L_G_image->Enabled=false;
KSP_L_D_image->Enabled=false;
KSP_L_J_image->Enabled=false;
KSP_L_I_image->Enabled=false;
KSP_L_K_image->Enabled=false;
KSP_L_L_image->Enabled=false;
ksp_1->Enabled=true;
ksp_2->Enabled=true;
ksp_3->Enabled=true;
ksp_4->Enabled=true;
ksp_5->Enabled=true;
ksp_6->Enabled=true;
ksp_7->Enabled=true;
ksp_8->Enabled=true;
ksp_9->Enabled=true;
ksp_10->Enabled=true;
ksp_11->Enabled=true;
ksp_12->Enabled=true;
ksp_13->Enabled=true;
ksp_14->Enabled=true;
ksp_15->Enabled=true;
ksp_16->Enabled=true;
ksp_17->Enabled=true;
ksp_18->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall Tksplfrm::KSP_L_J_imageClick(TObject *Sender)
{
KSP_Let[0]=false;
KSP_Let[1]=false;
KSP_Let[2]=false;
KSP_Let[3]=false;
KSP_Let[4]=true;
byte i;
for(i=5; i<=16; i++){
 KSP_Let[i]=false;
}
KSP_L_J->Color=clYellow;
KSP_L_J->Font->Color=clBlack;
KSP_L_A_image->Enabled=false;
KSP_L_V_image->Enabled=false;
KSP_L_G_image->Enabled=false;
KSP_L_D_image->Enabled=false;
KSP_L_J_image->Enabled=false;
KSP_L_I_image->Enabled=false;
KSP_L_K_image->Enabled=false;
KSP_L_L_image->Enabled=false;
ksp_1->Enabled=true;
ksp_2->Enabled=true;
ksp_3->Enabled=true;
ksp_4->Enabled=true;
ksp_5->Enabled=true;
ksp_6->Enabled=true;
ksp_7->Enabled=true;
ksp_8->Enabled=true;
ksp_9->Enabled=true;
ksp_10->Enabled=true;
ksp_11->Enabled=true;
ksp_12->Enabled=true;
ksp_13->Enabled=true;
ksp_14->Enabled=true;
ksp_15->Enabled=true;
ksp_16->Enabled=true;
ksp_17->Enabled=true;
ksp_18->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::KSP_L_I_imageClick(TObject *Sender)
{
KSP_Let[0]=false;
KSP_Let[1]=false;
KSP_Let[2]=false;
KSP_Let[3]=false;
KSP_Let[4]=false;
KSP_Let[5]=true;
byte i;
for(i=6; i<=16; i++){
 KSP_Let[i]=false;
}
KSP_L_I->Color=clYellow;
KSP_L_I->Font->Color=clBlack;
KSP_L_A_image->Enabled=false;
KSP_L_V_image->Enabled=false;
KSP_L_G_image->Enabled=false;
KSP_L_D_image->Enabled=false;
KSP_L_J_image->Enabled=false;
KSP_L_I_image->Enabled=false;
KSP_L_K_image->Enabled=false;
KSP_L_L_image->Enabled=false;
ksp_1->Enabled=true;
ksp_2->Enabled=true;
ksp_3->Enabled=true;
ksp_4->Enabled=true;
ksp_5->Enabled=true;
ksp_6->Enabled=true;
ksp_7->Enabled=true;
ksp_8->Enabled=true;
ksp_9->Enabled=true;
ksp_10->Enabled=true;
ksp_11->Enabled=true;
ksp_12->Enabled=true;
ksp_13->Enabled=true;
ksp_14->Enabled=true;
ksp_15->Enabled=true;
ksp_16->Enabled=true;
ksp_17->Enabled=true;
ksp_18->Enabled=true;
}
//---------------------------------------------------------------------------





void __fastcall Tksplfrm::KSP_L_K_imageClick(TObject *Sender)
{
KSP_Let[0]=false;
KSP_Let[1]=false;
KSP_Let[2]=false;
KSP_Let[3]=false;
KSP_Let[4]=false;
KSP_Let[5]=false;
KSP_Let[6]=true;
byte i;
for(i=7; i<=16; i++){
 KSP_Let[i]=false;
}
KSP_L_K->Color=clYellow;
KSP_L_K->Font->Color=clBlack;
KSP_L_A_image->Enabled=false;
KSP_L_V_image->Enabled=false;
KSP_L_G_image->Enabled=false;
KSP_L_D_image->Enabled=false;
KSP_L_J_image->Enabled=false;
KSP_L_I_image->Enabled=false;
KSP_L_K_image->Enabled=false;
KSP_L_L_image->Enabled=false;
ksp_1->Enabled=true;
ksp_2->Enabled=true;
ksp_3->Enabled=true;
ksp_4->Enabled=true;
ksp_5->Enabled=true;
ksp_6->Enabled=true;
ksp_7->Enabled=true;
ksp_8->Enabled=true;
ksp_9->Enabled=true;
ksp_10->Enabled=true;
ksp_11->Enabled=true;
ksp_12->Enabled=true;
ksp_13->Enabled=true;
ksp_14->Enabled=true;
ksp_15->Enabled=true;
ksp_16->Enabled=true;
ksp_17->Enabled=true;
ksp_18->Enabled=true;
}
//---------------------------------------------------------------------------
// ������ ��������� ������������� ���
void __fastcall Tksplfrm::KSPTMRTimer(TObject *Sender)
{
// ��������� ������������� ���
if(USO_Booled[0][0]){  // KSP A1
A1_LABEL->Color=clLime;
A1_LABEL->Font->Color=clBlack;  } else {
A1_LABEL->Color=clGreen;
A1_LABEL->Font->Color=clYellow; }
if(USO_Booled[0][1]){  // KSP A3
A3_LABEL->Color=clLime;
A3_LABEL->Font->Color=clBlack;  } else {
A3_LABEL->Color=clGreen;
A3_LABEL->Font->Color=clYellow; }
if(USO_Booled[0][2]){  // KSP A5
A5_LABEL->Color=clLime;
A5_LABEL->Font->Color=clBlack;  } else {
A5_LABEL->Color=clGreen;
A5_LABEL->Font->Color=clYellow; }
if(USO_Booled[0][3]){  // KSP A7
A7_LABEL->Color=clLime;
A7_LABEL->Font->Color=clBlack;  } else {
A7_LABEL->Color=clGreen;
A7_LABEL->Font->Color=clYellow; }
if(USO_Booled[0][4]){  // KSP A5
A9_LABEL->Color=clLime;
A9_LABEL->Font->Color=clBlack;  } else {
A9_LABEL->Color=clGreen;
A9_LABEL->Font->Color=clYellow; }
if(USO_Booled[0][5]){  // KSP A11
A11_LABEL->Color=clLime;
A11_LABEL->Font->Color=clBlack;  } else {
A11_LABEL->Color=clGreen;
A11_LABEL->Font->Color=clYellow; }
if(USO_Booled[0][6]){  // KSP A13
A13_LABEL->Color=clLime;
A13_LABEL->Font->Color=clBlack;  } else {
A13_LABEL->Color=clGreen;
A13_LABEL->Font->Color=clYellow; }
if(USO_Booled[0][8]){  // KSP A17
A17_LABEL->Color=clLime;
A17_LABEL->Font->Color=clBlack;  } else {
A17_LABEL->Color=clGreen;
A17_LABEL->Font->Color=clYellow; }

if(USO_Booled[1][2]){  // KSP B1
V1_LABEL->Color=clLime;
V1_LABEL->Font->Color=clBlack;  } else {
V1_LABEL->Color=clGreen;
V1_LABEL->Font->Color=clYellow; }
if(USO_Booled[1][3]){  // KSP B3
V3_LABEL->Color=clLime;
V3_LABEL->Font->Color=clBlack;  } else {
V3_LABEL->Color=clGreen;
V3_LABEL->Font->Color=clYellow; }
if(USO_Booled[1][4]){  // KSP B5
V5_LABEL->Color=clLime;
V5_LABEL->Font->Color=clBlack;  } else {
V5_LABEL->Color=clGreen;
V5_LABEL->Font->Color=clYellow; }
if(USO_Booled[1][5]){  // KSP B7
V7_LABEL->Color=clLime;
V7_LABEL->Font->Color=clBlack;  } else {
V7_LABEL->Color=clGreen;
V7_LABEL->Font->Color=clYellow; }
if(USO_Booled[1][7]){  // KSP B11
V11_LABEL->Color=clLime;
V11_LABEL->Font->Color=clBlack;  } else {
V11_LABEL->Color=clGreen;
V11_LABEL->Font->Color=clYellow; }
if(USO_Booled[1][8]){  // KSP B13
V13_LABEL->Color=clLime;
V13_LABEL->Font->Color=clBlack;  } else {
V13_LABEL->Color=clGreen;
V13_LABEL->Font->Color=clYellow; }
if(USO_Booled[1][9]){  // KSP B15
V15_LABEL->Color=clLime;
V15_LABEL->Font->Color=clBlack;  } else {
V15_LABEL->Color=clGreen;
V15_LABEL->Font->Color=clYellow; }
if(USO_Booled[1][10]){  // KSP B17
V17_LABEL->Color=clLime;
V17_LABEL->Font->Color=clBlack;  } else {
V17_LABEL->Color=clGreen;
V17_LABEL->Font->Color=clYellow; }

if(USO_Booled[1][11]){  // KSP �1
G1_LABEL->Color=clLime;
G1_LABEL->Font->Color=clBlack;  } else {
G1_LABEL->Color=clGreen;
G1_LABEL->Font->Color=clYellow; }
if(USO_Booled[1][12]){  // KSP �3
G3_LABEL->Color=clLime;
G3_LABEL->Font->Color=clBlack;  } else {
G3_LABEL->Color=clGreen;
G3_LABEL->Font->Color=clYellow; }
if(USO_Booled[1][13]){  // KSP �5
G5_LABEL->Color=clLime;
G5_LABEL->Font->Color=clBlack;  } else {
G5_LABEL->Color=clGreen;
G5_LABEL->Font->Color=clYellow; }
if(USO_Booled[1][14]){  // KSP �7
G7_LABEL->Color=clLime;
G7_LABEL->Font->Color=clBlack;  } else {
G7_LABEL->Color=clGreen;
G7_LABEL->Font->Color=clYellow; }
if(USO_Booled[1][15]){  // KSP �9
G9_LABEL->Color=clLime;
G9_LABEL->Font->Color=clBlack;  } else {
G9_LABEL->Color=clGreen;
G9_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][0]){  // KSP �11
G11_LABEL->Color=clLime;
G11_LABEL->Font->Color=clBlack;  } else {
G11_LABEL->Color=clGreen;
G11_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][3]){  // KSP �17
G17_LABEL->Color=clLime;
G17_LABEL->Font->Color=clBlack;  } else {
G17_LABEL->Color=clGreen;
G17_LABEL->Font->Color=clYellow; }

if(USO_Booled[2][4]){  // KSP �1
D1_LABEL->Color=clLime;
D1_LABEL->Font->Color=clBlack;  } else {
D1_LABEL->Color=clGreen;
D1_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][5]){  // KSP �3
D3_LABEL->Color=clLime;
D3_LABEL->Font->Color=clBlack;  } else {
D3_LABEL->Color=clGreen;
D3_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][6]){  // KSP �5
D5_LABEL->Color=clLime;
D5_LABEL->Font->Color=clBlack;  } else {
D5_LABEL->Color=clGreen;
D5_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][7]){  // KSP �7
D7_LABEL->Color=clLime;
D7_LABEL->Font->Color=clBlack;  } else {
D7_LABEL->Color=clGreen;
D7_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][8]){  // KSP �9
D9_LABEL->Color=clLime;
D9_LABEL->Font->Color=clBlack;  } else {
D9_LABEL->Color=clGreen;
D9_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][9]){  // KSP �11
D11_LABEL->Color=clLime;
D11_LABEL->Font->Color=clBlack;  } else {
D11_LABEL->Color=clGreen;
D11_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][10]){  // KSP �13
D13_LABEL->Color=clLime;
D13_LABEL->Font->Color=clBlack;  } else {
D13_LABEL->Color=clGreen;
D13_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][11]){  // KSP �15
D15_LABEL->Color=clLime;
D15_LABEL->Font->Color=clBlack;  } else {
D15_LABEL->Color=clGreen;
D15_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][12]){  // KSP �17
D17_LABEL->Color=clLime;
D17_LABEL->Font->Color=clBlack;  } else {
D17_LABEL->Color=clGreen;
D17_LABEL->Font->Color=clYellow; }

if(USO_Booled[2][13]){  // KSP �1
J1_LABEL->Color=clLime;
J1_LABEL->Font->Color=clBlack;  } else {
J1_LABEL->Color=clGreen;
J1_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][14]){  // KSP �3
J3_LABEL->Color=clLime;
J3_LABEL->Font->Color=clBlack;  } else {
J3_LABEL->Color=clGreen;
J3_LABEL->Font->Color=clYellow; }
if(USO_Booled[2][15]){  // KSP �5
J5_LABEL->Color=clLime;
J5_LABEL->Font->Color=clBlack;  } else {
J5_LABEL->Color=clGreen;
J5_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][0]){  // KSP �7
J7_LABEL->Color=clLime;
J7_LABEL->Font->Color=clBlack;  } else {
J7_LABEL->Color=clGreen;
J7_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][1]){  // KSP �9
J9_LABEL->Color=clLime;
J9_LABEL->Font->Color=clBlack;  } else {
J9_LABEL->Color=clGreen;
J9_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][2]){  // KSP �11
J11_LABEL->Color=clLime;
J11_LABEL->Font->Color=clBlack;  } else {
J11_LABEL->Color=clGreen;
J11_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][3]){  // KSP �13
J13_LABEL->Color=clLime;
J13_LABEL->Font->Color=clBlack;  } else {
J13_LABEL->Color=clGreen;
J13_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][4]){  // KSP �15
J15_LABEL->Color=clLime;
J15_LABEL->Font->Color=clBlack;  } else {
J15_LABEL->Color=clGreen;
J15_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][5]){  // KSP �17
J17_LABEL->Color=clLime;
J17_LABEL->Font->Color=clBlack;  } else {
J17_LABEL->Color=clGreen;
J17_LABEL->Font->Color=clYellow; }

if(USO_Booled[3][6]){  // KSP �1
I1_LABEL->Color=clLime;
I1_LABEL->Font->Color=clBlack;  } else {
I1_LABEL->Color=clGreen;
I1_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][7]){  // KSP �3
I3_LABEL->Color=clLime;
I3_LABEL->Font->Color=clBlack;  } else {
I3_LABEL->Color=clGreen;
I3_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][8]){  // KSP �5
I5_LABEL->Color=clLime;
I5_LABEL->Font->Color=clBlack;  } else {
I5_LABEL->Color=clGreen;
I5_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][9]){  // KSP �7
I7_LABEL->Color=clLime;
I7_LABEL->Font->Color=clBlack;  } else {
I7_LABEL->Color=clGreen;
I7_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][10]){  // KSP �9
I9_LABEL->Color=clLime;
I9_LABEL->Font->Color=clBlack;  } else {
I9_LABEL->Color=clGreen;
I9_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][11]){  // KSP �11
I11_LABEL->Color=clLime;
I11_LABEL->Font->Color=clBlack;  } else {
I11_LABEL->Color=clGreen;
I11_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][13]){  // KSP �15
I15_LABEL->Color=clLime;
I15_LABEL->Font->Color=clBlack;  } else {
I15_LABEL->Color=clGreen;
I15_LABEL->Font->Color=clYellow; }
if(USO_Booled[3][14]){  // KSP �17
I17_LABEL->Color=clLime;
I17_LABEL->Font->Color=clBlack;  } else {
I17_LABEL->Color=clGreen;
I17_LABEL->Font->Color=clYellow; }

if(USO_Booled[4][0]){  // KSP �1
K1_LABEL->Color=clLime;
K1_LABEL->Font->Color=clBlack;  } else {
K1_LABEL->Color=clGreen;
K1_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][1]){  // KSP �3
K3_LABEL->Color=clLime;
K3_LABEL->Font->Color=clBlack;  } else {
K3_LABEL->Color=clGreen;
K3_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][2]){  // KSP �5
K5_LABEL->Color=clLime;
K5_LABEL->Font->Color=clBlack;  } else {
K5_LABEL->Color=clGreen;
K5_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][3]){  // KSP �7
K7_LABEL->Color=clLime;
K7_LABEL->Font->Color=clBlack;  } else {
K7_LABEL->Color=clGreen;
K7_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][5]){  // KSP �11
K11_LABEL->Color=clLime;
K11_LABEL->Font->Color=clBlack;  } else {
K11_LABEL->Color=clGreen;
K11_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][6]){  // KSP �13
K13_LABEL->Color=clLime;
K13_LABEL->Font->Color=clBlack;  } else {
K13_LABEL->Color=clGreen;
K13_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][7]){  // KSP �15
K15_LABEL->Color=clLime;
K15_LABEL->Font->Color=clBlack;  } else {
K15_LABEL->Color=clGreen;
K15_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][8]){  // KSP �17
K17_LABEL->Color=clLime;
K17_LABEL->Font->Color=clBlack;  } else {
K17_LABEL->Color=clGreen;
K17_LABEL->Font->Color=clYellow; }

if(USO_Booled[1][1]){  // KSP �1
L1_LABEL->Color=clLime;
L1_LABEL->Font->Color=clBlack;  } else {
L1_LABEL->Color=clGreen;
L1_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][10]){  // KSP �3
L3_LABEL->Color=clLime;
L3_LABEL->Font->Color=clBlack;  } else {
L3_LABEL->Color=clGreen;
L3_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][11]){  // KSP �5
L5_LABEL->Color=clLime;
L5_LABEL->Font->Color=clBlack;  } else {
L5_LABEL->Color=clGreen;
L5_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][12]){  // KSP �7
L7_LABEL->Color=clLime;
L7_LABEL->Font->Color=clBlack;  } else {
L7_LABEL->Color=clGreen;
L7_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][13]){  // KSP �9
L9_LABEL->Color=clLime;
L9_LABEL->Font->Color=clBlack;  } else {
L9_LABEL->Color=clGreen;
L9_LABEL->Font->Color=clYellow; }
if(USO_Booled[4][15]){  // KSP �13
L13_LABEL->Color=clLime;
L13_LABEL->Font->Color=clBlack;  } else {
L13_LABEL->Color=clGreen;
L13_LABEL->Font->Color=clYellow; }
if(USO_Booled[5][0]){  // KSP �15
L15_LABEL->Color=clLime;
L15_LABEL->Font->Color=clBlack;  } else {
L15_LABEL->Color=clGreen;
L15_LABEL->Font->Color=clYellow; }
if(USO_Booled[5][1]){  // KSP �17
L17_LABEL->Color=clLime;
L17_LABEL->Font->Color=clBlack;  } else {
L17_LABEL->Color=clGreen;
L17_LABEL->Font->Color=clYellow; }
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_3Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][2]=true;                          // ����� ���������� ������� �3 - ������
JPS(1,is_operator,is_miu,is_ksp,"�3"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][2]=true;                          // ����� ���������� ������� B3 - ������
JPS(1,is_operator,is_miu,is_ksp,"�3"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][2]=true;                          // ����� ���������� ������� �3 - ������
SendToBum(0x00000296, 1, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�3"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][2]=true;                          // ����� ���������� ������� �3 - ������
JPS(1,is_operator,is_miu,is_ksp,"�3"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][2]=true;                          // ����� ���������� ������� �3 - ������
JPS(1,is_operator,is_miu,is_ksp,"�3"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][2]=true;                          // ����� ���������� ������� �3 - ������
SendToBum(0x000002AE, 1, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�3"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][2]=true;                          // ����� ���������� ������� �3 - ������
SendToBum(0x000002B1, 1, 1);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�3"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][2]=true;                          // ����� ���������� ������� �3 - ������
JPS(1,is_operator,is_miu,is_ksp,"�3"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::KSP_L_L_imageClick(TObject *Sender)
{
KSP_Let[0]=false;
KSP_Let[1]=false;
KSP_Let[2]=false;
KSP_Let[3]=false;
KSP_Let[4]=false;
KSP_Let[5]=false;
KSP_Let[6]=false;
KSP_Let[7]=true;
byte i;
for(i=8; i<=16; i++){
 KSP_Let[i]=false;
}
KSP_L_L->Color=clYellow;
KSP_L_L->Font->Color=clBlack;
KSP_L_A_image->Enabled=false;
KSP_L_V_image->Enabled=false;
KSP_L_G_image->Enabled=false;
KSP_L_D_image->Enabled=false;
KSP_L_J_image->Enabled=false;
KSP_L_I_image->Enabled=false;
KSP_L_K_image->Enabled=false;
KSP_L_L_image->Enabled=false;
ksp_1->Enabled=true;
ksp_2->Enabled=true;
ksp_3->Enabled=true;
ksp_4->Enabled=true;
ksp_5->Enabled=true;
ksp_6->Enabled=true;
ksp_7->Enabled=true;
ksp_8->Enabled=true;
ksp_9->Enabled=true;
ksp_10->Enabled=true;
ksp_11->Enabled=true;
ksp_12->Enabled=true;
ksp_13->Enabled=true;
ksp_14->Enabled=true;
ksp_15->Enabled=true;
ksp_16->Enabled=true;
ksp_17->Enabled=true;
ksp_18->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_4Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][3]=true;                          // ����� ���������� ������� �4 - ������
JPS(1,is_operator,is_miu,is_ksp,"�4"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][3]=true;                          // ����� ���������� ������� B4 - ������
JPS(1,is_operator,is_miu,is_ksp,"�4"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][3]=true;                          // ����� ���������� ������� �4 - ������
JPS(1,is_operator,is_miu,is_ksp,"�4"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][3]=true;                          // ����� ���������� ������� �4 - ������
JPS(1,is_operator,is_miu,is_ksp,"�4"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][3]=true;                          // ����� ���������� ������� �4 - ������
JPS(1,is_operator,is_miu,is_ksp,"�4"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][3]=true;                          // ����� ���������� ������� �4 - ������
SendToBum(0x000002AE, 0, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�4"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][3]=true;                          // ����� ���������� ������� �4 - ������
JPS(1,is_operator,is_miu,is_ksp,"�4"); } else   // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_5Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][4]=true;                          // ����� ���������� ������� �5 - ������
JPS(1,is_operator,is_miu,is_ksp,"�5"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][4]=true;                          // ����� ���������� ������� B5 - ������
SendToBum(0x00000295, 1, 0);                    // ������� � ��� (��-��� ���� - ������)
JPS(1,is_operator,is_miu,is_ksp,"�5"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][4]=true;                          // ����� ���������� ������� �5 - ������
SendToBum(0x00000289, 1, 1);                    // ������� � ��� (��-��� ���� - ������)
JPS(1,is_operator,is_miu,is_ksp,"�5"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][4]=true;                          // ����� ���������� ������� �5 - ������
JPS(1,is_operator,is_miu,is_ksp,"�5"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][4]=true;                          // ����� ���������� ������� �5 - ������
JPS(1,is_operator,is_miu,is_ksp,"�5"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][4]=true;                          // ����� ���������� ������� �5 - ������
JPS(1,is_operator,is_miu,is_ksp,"�5"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][4]=true;                          // ����� ���������� ������� �5 - ������
JPS(1,is_operator,is_miu,is_ksp,"�5"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][4]=true;                          // ����� ���������� ������� �5 - ������
JPS(1,is_operator,is_miu,is_ksp,"�5"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_6Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][5]=true;                          // ����� ���������� ������� �6 - ������
JPS(1,is_operator,is_miu,is_ksp,"�6"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][5]=true;                          // ����� ���������� ������� B6 - ������
SendToBum(0x00000295, 1, 1);                    //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�6"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][5]=true;                          // ����� ���������� ������� �6 - ������
JPS(1,is_operator,is_miu,is_ksp,"�6"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][5]=true;                          // ����� ���������� ������� �6 - ������
JPS(1,is_operator,is_miu,is_ksp,"�6"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][5]=true;                          // ����� ���������� ������� �6 - ������
JPS(1,is_operator,is_miu,is_ksp,"�6"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][5]=true;                          // ����� ���������� ������� �6 - ������
JPS(1,is_operator,is_miu,is_ksp,"�6"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_7Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][6]=true;                          // ����� ���������� ������� �7 - ������
JPS(1,is_operator,is_miu,is_ksp,"�7"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][6]=true;                          // ����� ���������� ������� B7 - ������
SendToBum(0x00000283, 1, 1);                    // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�7"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][6]=true;                          // ����� ���������� ������� �7 - ������
JPS(1,is_operator,is_miu,is_ksp,"�7"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][6]=true;                          // ����� ���������� ������� �7 - ������
JPS(1,is_operator,is_miu,is_ksp,"�7"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][6]=true;                          // ����� ���������� ������� �7 - ������
SendToBum(0x00000293, 1, 0);                    // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�7"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][6]=true;                          // ����� ���������� ������� �7 - ������
SendToBum(0x0000029F, 1, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�7"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][6]=true;                          // ����� ���������� ������� �7 - ������
JPS(1,is_operator,is_miu,is_ksp,"�7"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][6]=true;                          // ����� ���������� ������� �7 - ������
JPS(1,is_operator,is_miu,is_ksp,"�7"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_8Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][7]=true;                          // ����� ���������� ������� �8 - ������
JPS(1,is_operator,is_miu,is_ksp,"�8"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][7]=true;                          // ����� ���������� ������� B8 - ������
SendToBum(0x00000283, 1, 0);                    // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�8"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][7]=true;                          // ����� ���������� ������� �8 - ������
JPS(1,is_operator,is_miu,is_ksp,"�8"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][7]=true;                          // ����� ���������� ������� �8 - ������
JPS(1,is_operator,is_miu,is_ksp,"�8"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][7]=true;                          // ����� ���������� ������� �8 - ������
SendToBum(0x0000029F, 0, 0);                    // ������� � ��� (����� ��)
JPS(1,is_operator,is_miu,is_ksp,"�8"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][7]=true;                          // ����� ���������� ������� �8 - ������
JPS(1,is_operator,is_miu,is_ksp,"�8"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][7]=true;                          // ����� ���������� ������� �8 - ������
JPS(1,is_operator,is_miu,is_ksp,"�8"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_9Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][8]=true;                          // ����� ���������� ������� �9 - ������
JPS(1,is_operator,is_miu,is_ksp,"�9"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][8]=true;                          // ����� ���������� ������� B9 - ������
JPS(1,is_operator,is_miu,is_ksp,"�9"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][8]=true;                          // ����� ���������� ������� �9 - ������
JPS(1,is_operator,is_miu,is_ksp,"�9"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][8]=true;                          // ����� ���������� ������� �9 - ������
JPS(1,is_operator,is_miu,is_ksp,"�9"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][8]=true;                          // ����� ���������� ������� �9 - ������
JPS(1,is_operator,is_miu,is_ksp,"�9"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][8]=true;                          // ����� ���������� ������� �9 - ������
JPS(1,is_operator,is_miu,is_ksp,"�9"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][8]=true;                          // ����� ���������� ������� �9 - ������
JPS(1,is_operator,is_miu,is_ksp,"�9"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][8]=true;                          // ����� ���������� ������� �9 - ������
JPS(1,is_operator,is_miu,is_ksp,"�9"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_10Click(TObject *Sender)
{
/* if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][9]=true;                          // ����� ���������� ������� �10 - ������
JPS(1,is_operator,is_miu,is_ksp,"�10"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][9]=true;                          // ����� ���������� ������� B10 - ������
JPS(1,is_operator,is_miu,is_ksp,"�10"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][9]=true;                          // ����� ���������� ������� �10 - ������
JPS(1,is_operator,is_miu,is_ksp,"�10"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][9]=true;                          // ����� ���������� ������� �10 - ������
JPS(1,is_operator,is_miu,is_ksp,"�10"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][9]=true;                          // ����� ���������� ������� �10 - ������
JPS(1,is_operator,is_miu,is_ksp,"�10"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
I9_LABEL->Color=clGreen;
I9_LABEL->Font->Color=clYellow;
KSP_Booled[6][9]=true;                          // ����� ���������� ������� �10 - ������
JPS(1,is_operator,is_miu,is_ksp,"�10"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][9]=true;                          // ����� ���������� ������� �10 - ������
JPS(1,is_operator,is_miu,is_ksp,"�10"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][9]=true;                          // ����� ���������� ������� �10 - ������
JPS(1,is_operator,is_miu,is_ksp,"�10"); }        // �������� ������ �������
*/
// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_11Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][10]=true;                          // ����� ���������� ������� �11 - ������
JPS(1,is_operator,is_miu,is_ksp,"�11"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][10]=1;                          // ����� ���������� ������� B11 - ������
JPS(1,is_operator,is_miu,is_ksp,"�11"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][10]=1;                          // ����� ���������� ������� �11 - ������
JPS(1,is_operator,is_miu,is_ksp,"�11"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][10]=1;                          // ����� ���������� ������� �11 - ������
JPS(1,is_operator,is_miu,is_ksp,"�11"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][10]=1;                          // ����� ���������� ������� �11 - ������
SendToBum(0x000002B6, 1, 1);                  //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�11"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][10]=1;                          // ����� ���������� ������� �11 - ������
SendToBum(0x000002A0, 1, 1);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�11"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][10]=1;                          // ����� ���������� ������� �11 - ������
JPS(1,is_operator,is_miu,is_ksp,"�11"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][10]=1;                          // ����� ���������� ������� �11 - ������
JPS(1,is_operator,is_miu,is_ksp,"�11"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_12Click(TObject *Sender)
{
/* if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][11]=true;                          // ����� ���������� ������� �12 - ������
JPS(1,is_operator,is_miu,is_ksp,"�12"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][11]=true;                          // ����� ���������� ������� B12 - ������
JPS(1,is_operator,is_miu,is_ksp,"�12"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][11]=true;                          // ����� ���������� ������� �12 - ������
JPS(1,is_operator,is_miu,is_ksp,"�12"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][11]=true;                          // ����� ���������� ������� �12 - ������
JPS(1,is_operator,is_miu,is_ksp,"�12"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][11]=true;                          // ����� ���������� ������� �12 - ������
JPS(1,is_operator,is_miu,is_ksp,"�12"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][11]=true;                          // ����� ���������� ������� �12 - ������
JPS(1,is_operator,is_miu,is_ksp,"�12"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][11]=true;                          // ����� ���������� ������� �12 - ������
JPS(1,is_operator,is_miu,is_ksp,"�12"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][11]=true;                          // ����� ���������� ������� �12 - ������
JPS(1,is_operator,is_miu,is_ksp,"�12"); }        // �������� ������ �������
*/
// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_13Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][12]=true;                          // ����� ���������� ������� �13 - ������
JPS(1,is_operator,is_miu,is_ksp,"�13"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][12]=true;                          // ����� ���������� ������� B13 - ������
JPS(1,is_operator,is_miu,is_ksp,"�13"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][12]=true;                          // ����� ���������� ������� �13 - ������
SendToBum(0x000002AA, 1, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�13"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][12]=true;                          // ����� ���������� ������� �13 - ������
SendToBum(0x000002A6, 1, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�13"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][12]=true;                          // ����� ���������� ������� �13 - ������
SendToBum(0x000002B7, 1, 0);       //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�13"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][12]=true;                          // ����� ���������� ������� �13 - ������
SendToBum(0x000002A1, 1, 0);                     //������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�13"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][12]=true;                          // ����� ���������� ������� �13 - ������
JPS(1,is_operator,is_miu,is_ksp,"�13"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][12]=true;                          // ����� ���������� ������� �13 - ������
JPS(1,is_operator,is_miu,is_ksp,"�13"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_14Click(TObject *Sender)
{
/* if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][13]=true;                          // ����� ���������� ������� �14 - ������
JPS(1,is_operator,is_miu,is_ksp,"�14"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][13]=true;                          // ����� ���������� ������� B14 - ������
JPS(1,is_operator,is_miu,is_ksp,"�14"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][13]=true;                          // ����� ���������� ������� �14 - ������
JPS(1,is_operator,is_miu,is_ksp,"�14"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][13]=true;                          // ����� ���������� ������� �14 - ������
JPS(1,is_operator,is_miu,is_ksp,"�14"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][13]=true;                          // ����� ���������� ������� �14 - ������
JPS(1,is_operator,is_miu,is_ksp,"�14"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][13]=true;                          // ����� ���������� ������� �14 - ������
JPS(1,is_operator,is_miu,is_ksp,"�14"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][13]=true;                          // ����� ���������� ������� �14 - ������
JPS(1,is_operator,is_miu,is_ksp,"�14"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][13]=true;                          // ����� ���������� ������� �14 - ������
JPS(1,is_operator,is_miu,is_ksp,"�14"); }        // �������� ������ �������
*/
// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_15Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                               ���� �������� ����� �
KSP_Booled[0][14]=true;                          // ����� ���������� ������� �15 - ������
JPS(1,is_operator,is_miu,is_ksp,"�15"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                               ���� �������� ����� B
KSP_Booled[2][14]=true;                          // ����� ���������� ������� B15 - ������
SendToBum(0x00000297, 1, 0);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�15"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                              ���� �������� ����� �
KSP_Booled[3][14]=true;                          // ����� ���������� ������� �15 - ������
SendToBum(0x00000286, 1, 0);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�15"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                              ���� �������� ����� �
KSP_Booled[4][14]=true;                          // ����� ���������� ������� �15 - ������
JPS(1,is_operator,is_miu,is_ksp,"�15"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][14]=true;                          // ����� ���������� ������� �15 - ������
SendToBum(0x000002B8, 1, 1);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�15"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][14]=true;                          // ����� ���������� ������� �15 - ������
SendToBum(0x000002B9, 1, 1);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�15"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][14]=true;                          // ����� ���������� ������� �15 - ������
JPS(1,is_operator,is_miu,is_ksp,"�15"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][14]=true;                          // ����� ���������� ������� �15 - ������
JPS(1,is_operator,is_miu,is_ksp,"�15"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_16Click(TObject *Sender)
{
/* if (KSP_Let[0]){ // �                              ���� �������� ����� �
KSP_Booled[0][15]=true;                          // ����� ���������� ������� �16 - ������
JPS(1,is_operator,is_miu,is_ksp,"�16"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                              ���� �������� ����� B
KSP_Booled[2][15]=true;                          // ����� ���������� ������� B16 - ������
JPS(1,is_operator,is_miu,is_ksp,"�16"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                             ���� �������� ����� �
KSP_Booled[3][15]=true;                          // ����� ���������� ������� �16 - ������
JPS(1,is_operator,is_miu,is_ksp,"�16"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                             ���� �������� ����� �
KSP_Booled[4][15]=true;                          // ����� ���������� ������� �16 - ������
JPS(1,is_operator,is_miu,is_ksp,"�16"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][15]=true;                          // ����� ���������� ������� �16 - ������
JPS(1,is_operator,is_miu,is_ksp,"�16"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][15]=true;                          // ����� ���������� ������� �16 - ������
JPS(1,is_operator,is_miu,is_ksp,"�16"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][15]=true;                          // ����� ���������� ������� �16 - ������
JPS(1,is_operator,is_miu,is_ksp,"�16"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][15]=true;                          // ����� ���������� ������� �16 - ������
JPS(1,is_operator,is_miu,is_ksp,"�16"); }        // �������� ������ �������
*/
// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_17Click(TObject *Sender)
{
if (KSP_Let[0]){ // �                               ���� �������� ����� �
KSP_Booled[0][16]=true;                          // ����� ���������� ������� �16 - ������
JPS(1,is_operator,is_miu,is_ksp,"�17"); } else   // �������� ������ �������

if (KSP_Let[1]){ // �                               ���� �������� ����� B
KSP_Booled[2][16]=true;                          // ����� ���������� ������� B16 - ������
SendToBum(0x00000280, 1, 0);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�17"); } else   // �������� ������ �������

if (KSP_Let[2]){  // �                              ���� �������� ����� �
KSP_Booled[3][16]=true;                          // ����� ���������� ������� �16 - ������
SendToBum(0x000002A6, 0, 0);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�17"); } else   // �������� ������ �������

if (KSP_Let[3]){  // �                              ���� �������� ����� �
KSP_Booled[4][16]=true;                          // ����� ���������� ������� �16 - ������
JPS(1,is_operator,is_miu,is_ksp,"�17"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][16]=true;                          // ����� ���������� ������� �16 - ������
SendToBum(0x000002BB, 1, 0);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�17"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][16]=true;                          // ����� ���������� ������� �17 - ������
SendToBum(0x000002BC, 1, 0);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�17"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][16]=true;                          // ����� ���������� ������� �17 - ������
JPS(1,is_operator,is_miu,is_ksp,"�17"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][16]=true;                          // ����� ���������� ������� �17 - ������
SendToBum(0x00000282, 1, 1);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�17"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall Tksplfrm::ksp_18Click(TObject *Sender)
{
if (KSP_Let[1]){ // �                               ���� �������� ����� B
KSP_Booled[2][17]=true;                          // ����� ���������� ������� B16 - ������
SendToBum(0x00000280, 0, 0);                     // ������� � ��� (��� - ������)
JPS(1,is_operator,is_miu,is_ksp,"�18"); } else   // �������� ������ �������

if (KSP_Let[4]){  // �
KSP_Booled[5][17]=true;                          // ����� ���������� ������� �16 - ������
SendToBum(0x000002BB, 0, 0);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�18"); } else   // �������� ������ �������

if (KSP_Let[5]){  // �
KSP_Booled[6][17]=true;                          // ����� ���������� ������� �16 - ������
SendToBum(0x000002BC, 0, 0);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�18"); } else   // �������� ������ �������

if (KSP_Let[6]){  // �
KSP_Booled[7][17]=true;                          // ����� ���������� ������� �16 - ������
JPS(1,is_operator,is_miu,is_ksp,"�18"); } else   // �������� ������ �������

if (KSP_Let[7]){  // �
KSP_Booled[8][17]=true;                          // ����� ���������� ������� �16 - ������
SendToBum(0x00000282, 1, 0);                     // ������� � ��� ()
JPS(1,is_operator,is_miu,is_ksp,"�18"); }        // �������� ������ �������

// ���������� ���� ������ ���
KSP_L_A->Color=clBlack;
KSP_L_A->Font->Color=clYellow;
KSP_L_V->Color=clBlack;
KSP_L_V->Font->Color=clYellow;
KSP_L_G->Color=clBlack;
KSP_L_G->Font->Color=clYellow;
KSP_L_D->Color=clBlack;
KSP_L_D->Font->Color=clYellow;
KSP_L_J->Color=clBlack;
KSP_L_J->Font->Color=clYellow;
KSP_L_I->Color=clBlack;
KSP_L_I->Font->Color=clYellow;
KSP_L_K->Color=clBlack;
KSP_L_K->Font->Color=clYellow;
KSP_L_L->Color=clBlack;
KSP_L_L->Font->Color=clYellow;
// ��������� �����
ksp_1->Enabled=false;
ksp_2->Enabled=false;
ksp_3->Enabled=false;
ksp_4->Enabled=false;
ksp_5->Enabled=false;
ksp_6->Enabled=false;
ksp_7->Enabled=false;
ksp_8->Enabled=false;
ksp_9->Enabled=false;
ksp_10->Enabled=false;
ksp_11->Enabled=false;
ksp_12->Enabled=false;
ksp_13->Enabled=false;
ksp_14->Enabled=false;
ksp_15->Enabled=false;
ksp_16->Enabled=false;
ksp_17->Enabled=false;
ksp_18->Enabled=false;
// ��������� ����� �����
KSP_L_A_image->Enabled=true;
KSP_L_V_image->Enabled=true;
KSP_L_G_image->Enabled=true;
KSP_L_D_image->Enabled=true;
KSP_L_J_image->Enabled=true;
KSP_L_I_image->Enabled=true;
KSP_L_K_image->Enabled=true;
KSP_L_L_image->Enabled=true;
}
//---------------------------------------------------------------------------

