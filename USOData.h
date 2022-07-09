/*
  USO Data Head File (UDHF)
  ���� ������ ���

  ---------

  � ������� ������ �������������� - UsoBuffer:array[0..$13] of Word

  ����� 5 ��� 11($B)
  ����� ���� $5B

  ---------
  � ����� COMMON.INC �� ���� ����� � ����� ������

  Type
    USO_BitType = 0..15;         // ��������������� ������ ���
    USO_AddrType    = 0..$13;    // ������ �����
    USO_BitAddrType = 0..$13F;
    USO_AddrTypeMain = 0..$0F;
    USO_BufferType = packed array[USO_AddrType] of Word;
    USO_BufferPtr = ^USO_BufferType;
    USO_BufferTypeMain = packed array[USO_AddrTypeMain] of Word;


  �.�. �� ����� 20-�� ������� ������
*/
#ifndef _USO_data
#define _USO_data
static unsigned short USO_BT[20];    // Array

static bool argon_takt_pr; // ������� ��������� ������ �� ��� (�� ���)

static bool ruo_pr[6];
static bool rud_pr[6];

//------------------------------------
// For KSP - Letter and Number
static bool KSP_Let[17];  // 17 - ������ ��� ������ ���������� � �������

//------------------------------------
// ��� ����

static unsigned short USO_BitType[20][4];
static bool USO_Booled[20][16];      // �������� ������ ��� ������ � ��� - ����-��������� � ���������� �������
static bool KSP_Booled[16][9];       // ������ ������ ������ � ��� (���� ������ ������� � ��� [LETTER] [NUMBER])
/* KSP_Booled
[00] [0 - 8]  �
[01] [0 - 8]  �
[02] [0 - 8]  �
[03] [0 - 8]  �
[04] [0 - 8]  �
[05] [0 - 8]  �
[06] [0 - 8]  �
[07] [0 - 8]  �
[08] [0 - 8]  �
[09] [0 - 8]  �
[10] [0 - 8]  �
[11] [0 - 8]  �
[12] [0 - 8]  �
[13] [0 - 8]  �
[14] [0 - 8]  �
[15] [0 - 8]  �
[16] [0 - 8]  �     */
/*
   15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
00
01
02
03
04
05
06
07
08
09
10
11
12
13
14
15
16
17
18
19
*/

static char TableMask[2] = {'.','I'};        // Mask for USO Table Matrix    //

/*
  ������ ������ ��� � ����� ������ ���

  - �������� ����� ������� (����� (bool KSP_Let[] � �����), ����� ���� �
  ����������� �� Let\Num ������������ ������� KSP_Booled[].
  - � ������ uso_model � ������� ��������� ��������� ���� ������ �� ��� �
  ����������� �� ������� ��� � �������� �������������� ���������
  ������������ ��������������� �������� ��� USO_Booled[].
*/



#endif //_USO_data


