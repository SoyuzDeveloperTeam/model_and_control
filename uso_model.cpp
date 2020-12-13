#ifndef USO_MDL
#define USO_MDL
//---------------------------------------------------------------------------
#include "USOData.h"
#include "arg_header.h"
#include "arg_main.cpp"
#include "JouHeader.h"
#include "JouStrings.h"
#include "MainFrm.h"
#include "ssvp_module.cpp"
#include "kdu_math.h"        // ���������� ���
#pragma  hdrstop

#include "uso_model.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

static int i_test;
static bool d2b;


///////////////////////
// � � � � � � � � � //
// � � � � � � � � � //
//   � � � � � � �   //
//   � � � � � � �   //
//   �     �     �   //
///////////////////////


void USO_work(){

// ���� - ������� � //

if(KSP_Booled[0][0]) { // A 1
// 6.5 ��� ��� ��� ������� ������ ���
// 6.7 ��� ������� ������ ��� �� ���� ���� :01:
// ��������� �������� �������� ������ ��� (��� �������� ���)
if(i_test==300) { // ����� �������� 60 ������ = 60000 �� = 300 ������ �� 200 ��
USO_Booled[0][0]=true;   //
JPS(1,"������ ��� �������","","","");
cw_a4[3]=1;
KSP_Booled[0][0] = false;
i_test=0;
}else
i_test++;
}

if(KSP_Booled[0][1]) {  // A 2
if(i_test==300) {
USO_Booled[0][0]=false;
JPS(1,"������ ��� �������","","","");
cw_a4[3]=0;
KSP_Booled[0][1] = false;
i_test=0;
}else
i_test++;
}

if(KSP_Booled[0][2]) {  // A 3   ������ ��� - ���
   KSP_Booled[0][2] = false;
        // ���. ���. ������� ������� ����1 � ����2
        // ��32 ��� ������� ���
        if(USO_Booled[1][2])
        JPS(1,is_sudn,is_kdu,"������ ��� 1 ������     ���",""); else
        JPS(1,is_sudn,is_kdu,"������ ��� 2 ������     ���","");
        USO_Booled[0][1]=true;
}

if(KSP_Booled[0][3]) {  // A 4   ������ ��� - ����
   KSP_Booled[0][3] = false;
        // ����. ���. ����. ������� ����1, ����2
        // ��33 ���� ������� ���
        USO_Booled[0][1]=false;
        if(USO_Booled[1][2])
        JPS(1,is_sudn,is_kdu,"������ ��� 1 ������     ����",""); else
        JPS(1,is_sudn,is_kdu,"������ ��� 2 ������     ����","");
}

if(KSP_Booled[0][4]) { // A 5     ��� ����
   KSP_Booled[0][4] = false;
        // 98 - ���������� ��� (���) �� ����� ����������
        USO_Booled[0][2]=true;
        kdu_sdr = false;
}

if(KSP_Booled[0][5]) { // A 6
   KSP_Booled[0][5] = false;
        // -98 - ����������� ��� (���) � ����� ����������
        USO_Booled[0][2]=false;
        kdu_sdr = true;
}

if(KSP_Booled[0][6]) { // A 7
   KSP_Booled[0][6] = false;
        // 95 ���������� ��� �� ����� ����������
        USO_Booled[0][3]=true;
        kdu_sdd = false;
}

if(KSP_Booled[0][7]) { // A 8
   KSP_Booled[0][7] = false;
        // -95 ����������� ��� � ����� ����������
        USO_Booled[0][3]=false;
        kdu_sdd = true;
}

if(KSP_Booled[0][8]) { // A 9 - ����� ���-�
   KSP_Booled[0][8] = false;
        // ������� � �� ��� "����� ���-�"
        USO_Booled[0][4]=true;
        ba_dpo.b_com = true;
}

// �9 - �����������

if(KSP_Booled[0][10]) { // A 11 - ����� ���-�1
   KSP_Booled[0][10] = false;
        USO_Booled[0][5]=true;
        ba_dpo.m1_com = true;
}



if(KSP_Booled[0][12]) {  // A 13
   // �13 - �����������
        // �������� ��� �� 2,4,6,8.10,12;
        dpo_v_pr[2,4,6,8,10,12]=1;
        USO_Booled[0][6]=true;
        ba_dpo.m2_com = true;
}

if(KSP_Booled[0][14]) { // A 15
   KSP_Booled[0][14] = false;
        // ������ � ���� ������� 100 "����������� ������ ���",
        // ��� ��������� � ����������� ������ ���������� ��� �
        // ��� �� ���� ��������� ������ ��� ������������
        USO_Booled[0][7]=true;
}

if(KSP_Booled[0][16]) {  // A 17
   KSP_Booled[0][16]=false;
        USO_Booled[0][8]=true;
}

// ���� - ������� � //

if(KSP_Booled[1][0]) {  // � 1
   KSP_Booled[1][0]=false;
        // ������� ��� ����
        USO_Booled[0][9]=true;
}

if(KSP_Booled[1][1]) {  // � 2
   KSP_Booled[1][1]=false;
        // ������� ��� ����
        USO_Booled[0][9]=false;
}

if(KSP_Booled[1][2]) {  // � 3
   KSP_Booled[1][2]=false;
        // ������� ��� ����
        USO_Booled[0][10]=true;
}

if(KSP_Booled[1][3]) {  // � 2
   KSP_Booled[1][3]=false;
        // ������� ��� ����
        USO_Booled[0][10]=false;
}

// ���� - ������� � //

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
if(KSP_Booled[2][3]) { // � 4
   KSP_Booled[2][3]  = false;
        USO_Booled[1][3]  = false;
        USO_Booled[11][10]= true;  // �������� ��-7 "2 ������ ���"
}
if(KSP_Booled[2][4]) { // � 5 // ��������� ��-���
   KSP_Booled[2][4]  = false;
        USO_Booled[1][4]  = true;
}
if(KSP_Booled[2][5]) { // � 6 // ��������� ��-���
   KSP_Booled[2][5]  = false;
        USO_Booled[1][4]  = false;
}
if(KSP_Booled[2][6]) { // � 7
   KSP_Booled[2][6]  = false;
        USO_Booled[1][5]  = true;
}
if(KSP_Booled[2][7]) { // � 8
   KSP_Booled[2][7]  = false;
        USO_Booled[1][5]  = false;
}
if(KSP_Booled[2][8]) { // � 9
   KSP_Booled[2][8]  = false;
        USO_Booled[1][6]  = true;
}
if(KSP_Booled[2][10]) { // � 11
   KSP_Booled[2][10]  = false;
        USO_Booled[1][7]  = true;
}

if(KSP_Booled[2][12]) { // � 13
   KSP_Booled[2][12]  = false;
        // 17.26 ������� � ��� "��� ���� �������"
        USO_Booled[1][8]  = true;
        USO_Booled[1][12]  = false; // ���� �������
        USO_Booled[1][9]  = false;  // ���� ������� ��
}
if(KSP_Booled[2][14]) { // � 15
   KSP_Booled[2][14]  = false;
        USO_Booled[1][9]  = true;
        USO_Booled[1][12]  = false;
        USO_Booled[1][8]  = false;
}
if(KSP_Booled[2][16]) { // � 17
   KSP_Booled[2][16]  = false;
        USO_Booled[1][10]  = true;
}
if(KSP_Booled[2][17]) { // � 18
   KSP_Booled[2][17]  = false;
        USO_Booled[1][10]  = false;
}

// ���� - ������� � //

if(KSP_Booled[3][0]) { // � 1  ������� ����� ���
   KSP_Booled[3][0] = false;
        // �������� ������������� �������� ����
        // ������� ���������� �1, ��1, ��
        // ��� �� ������ �� �� - ��������� � �������� �� ��
        // ���������� ��������� �������� ������, ������� ������������
        // �������� ������������� ����� �������� ������ 2��,���1,���2.
        USO_Booled[1][11]=true;
}

if(KSP_Booled[3][1]) { // � 2  ������� ����� ����
   KSP_Booled[3][1] =false;
        // ���������� ���������� �����������
        USO_Booled[1][11]=false;
}

if(KSP_Booled[3][2]) { // � 3  �������
   KSP_Booled[3][2] =false;
        USO_Booled[1][12]=true;
        USO_Booled[1][8] =false;
        USO_Booled[1][9] =false;  // ���� ������� ��
}

if(KSP_Booled[3][3]) { // � 4  �������
   KSP_Booled[3][3] =false;
        USO_Booled[1][12]=false;
        USO_Booled[1][8] =false;
        USO_Booled[1][9] =false;  // ���� ������� ��
}
if(KSP_Booled[3][4]) {  // � 5
   KSP_Booled[3][4] =false;
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
        USO_Booled[1][16]=true; // ������� ������ ����-1
        //-27.2 ���� ��2, ���� � ���-7 "���� ��2"
        USO_Booled[2][0]=false; // ������� ������� ������ ����-2
        //27.3 ��� ��3 (��� ��� ��� ����), ���� � ���-7 "��� ��3"
        //27.9 ������ �� 1 �������� ���
}

if(KSP_Booled[3][10]) {  // � 11 ����-2
   KSP_Booled[3][10] = false;
        //-27.1 ���� ��1, ��������� � ���-7 "���� ��1"
        USO_Booled[1][16]=false;
        //27.2 ��� ��2, ���� � ���-7 "��� ��2"
        USO_Booled[2][0]=true;
        //27.3 ��� ��3 (��� ��� ��� ����), ���� � ���-7 "��� ��3"
        //-27.9 ������ �� 2 �������� ���
}
if(KSP_Booled[3][12]) {  // � 13 ���� ����
   KSP_Booled[3][12] = false;
        //-27.1 ���� ��1, ��������� � ���-7 "���� ��1"
        USO_Booled[1][16]=false;
        //-27.2 ���� ��2, ���� � ���-7 "���� ��2"
        USO_Booled[2][0]=false;
        //-27.3 ���� ��3 , ���� � ���-7 "���� ��3"
}
if(KSP_Booled[3][14]) { // �15
   KSP_Booled[3][14] = false;
        USO_Booled[1][13]=true;
        USO_Booled[1][14]=true;
}

// ���� - ������� � //

if(KSP_Booled[4][0]){  // KSP �1
   KSP_Booled[4][0]=false;
   // ����� ������ ������ ��� �������� �� ���� - ������ �� ���
   USO_Booled[2][5]  = true;
}

if(KSP_Booled[4][6]){  // ��� �7
   KSP_Booled[4][6]=false;
       USO_Booled[2][7]=ssvp_power;  // ���� ���
       JPS(1,is_sudn,is_operator,"������ ������� �� ����","");
}

if(KSP_Booled[4][7]){  // ��� �8
   KSP_Booled[4][7]=false;
       USO_Booled[2][7]=false;  // ���� ����
       JPS(1,is_sudn,is_operator,"������� �� ���� ������","");
}

// ���� - ������� � //

if(KSP_Booled[6][0]) { // �1   ���
   KSP_Booled[6][0] = false;
        USO_Booled[3][6]=true;
        cw_a2[0]=0;
}

if(KSP_Booled[6][1]) { // �2   ���
   KSP_Booled[6][1] = false;
        USO_Booled[3][6]=false;
        cw_a2[0]=1;
}

if(KSP_Booled[6][2]) { // �3 ���
   KSP_Booled[6][2] = false;
        USO_Booled[3][7] = true;
        // �������� ������� ���� + ��020
}

if(KSP_Booled[6][3]) { // �4 ���
   KSP_Booled[6][3] = false;
        USO_Booled[3][7] = false;
}

if(KSP_Booled[6][8]) {  // �9 ������� �����
   KSP_Booled[6][8] = false;
        //USO_Booled[0][8]=false;
        USO_Booled[3][10]=true; // ������� ������� �����
        JPS(1,is_argon,is_operator,"������������ ������� ������� ���������� � ����","");
        USO_Booled[0][1]=true;  // ������ ��� �� ������� �����
        // ��� �� ���������� ����-1 � ���
}

if(KSP_Booled[6][10]) { // �11   -  ���� �����
   KSP_Booled[6][10] = false;
        USO_Booled[3][11]=true;
        JPS(1,is_argon,is_operator,"������� ������� \"����\", ������ ������ ������������.","");
        //     � 9                � 15
        if(USO_Booled[3][11]&&USO_Booled[3][14])
        // �������� �� ����� ����� //
        // 1 - �������� (� ������) � �� ����������� - ������ ��� ���
        argon_takt_pr=1;
        apm=true; //������� ������� �����
}

if(KSP_Booled[6][12]){ // �13  -  ���
   KSP_Booled[6][12] = false;
        USO_Booled[3][12]=true;
        // ��39 ���������� ������������ �������
        // -5.5 ���������� ���1, ���1, ���2, ���2
        kdu_log_pr.eko1 = false;
        kdu_log_pr.ekg1 = false;
        kdu_log_pr.eko2 = false;
        kdu_log_pr.ekg2 = false;
        USO_Booled[3][10]=false; // ������� ������� �����
        USO_Booled[3][11]=false; // ������� ���� �����
                arg_work_pr=0;
                apm=false;
                USO_Booled[11][6] = false;
        USO_Booled[0][1]=false;  // ������� ������
}

if(KSP_Booled[6][14]) { // � 15 - ���� ���
   KSP_Booled[6][14] = false;
        USO_Booled[3][13] = true;   // � 15 ���
        USO_Booled[3][2]  = false;  // �11 ���� �
        USO_Booled[3][3]  = false;  // �13 ���� �
        USO_Booled[3][4]  = false;  // �15 ���� �
        // �������� ��� ������ ��� ��� ����
        JPS(1,is_argon,is_operator,"������� ������ � � �","");
        cw_arg[4]=1;
        //(��� ����� ��� - ��������)
}

if(KSP_Booled[6][16]){ // � 17  - ������� ��������� - ���
   KSP_Booled[6][16] = false;
        USO_Booled[3][14] = true;
}

if(KSP_Booled[6][17]){ // � 18  - ������� ��������� - ����
   KSP_Booled[6][17] = false;
        USO_Booled[3][14] = false;
}

//--\\ ���� - ������� � \\--//

if(KSP_Booled[5][10]){  // KSP �11
   KSP_Booled[5][10] = false;
        // �������� ����� ���� - �
        USO_Booled[3][2]  = true;   // �������� ������ �, ��������� � ����
        USO_Booled[3][3]  = false;
        USO_Booled[3][4]  = false;
        USO_Booled[3][13] = false;
        JPS(1,is_argon,is_operator,"������ ����� �","");

}

if(KSP_Booled[5][12]){  // KSP �13
   KSP_Booled[5][12] = false;
        // �������� ����� ���� - �
   /*     USO_Booled[3][3]  = true;
        USO_Booled[3][2]  = false;
        USO_Booled[3][4]  = false;
        USO_Booled[3][13] = false;
        JPS(1,is_argon,is_operator,"������ ����� �","");   */
}

if(KSP_Booled[5][14]){  // KSP �15
   KSP_Booled[5][14] = false;
   /*     // �������� ����� ���� - �
        USO_Booled[3][4] = true;
        USO_Booled[3][2] = false;
        USO_Booled[3][3] = false;
        USO_Booled[3][13] = false;
        JPS(1,is_argon,is_operator,"������ ����� �","");     */
}

//--\\ ���� - ������� � \\--//

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

//--\\ ���� - ������� � \\--//

if(KSP_Booled[8][0]) { // �1 - �� ��
   KSP_Booled[8][0]=false;
        USO_Booled[1][1]=true;
}

if(KSP_Booled[8][1]) { // �1 - �� ��
   KSP_Booled[8][1]=false;
        USO_Booled[1][1]=false;
}

// ���� - ������� � //

if(KSP_Booled[13][0]) { // � 1
   KSP_Booled[13][0] = false;
        USO_Booled[7][6]=true;
        JPS(1,"\"�������-�\" ������������ � ���.","","","");
}

// ���� - ������� � //

if(KSP_Booled[13][2]) { // � 3
   KSP_Booled[13][2] = false;
        USO_Booled[5][3]=true;
        JPS(1,"������ ������� �� ��� ����","","","");
}

uso_change(USO_Booled);

}

#endif // USO_MDL
