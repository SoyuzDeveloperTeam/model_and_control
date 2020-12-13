//---------------------------------------------------------------------------
/*
  �� ��������� ������ ��-020 ������������� ���������� �.�.
  ��������� ����� �� ������� R U 40514 U 1

Type c_Double = Double;             Const _c_Double = _Double;
Type c_Float  = Single;             Const _c_Float  = _Single;
Type c_Long   = Longint;            Const _c_Long   = _Longint;
Type c_Ulong  = Longint;            Const _c_Ulong  = _Longint;
Type c_Short  = integer;            Const _c_Short  = _SmallInt;
Type c_Ushort = word;               Const _c_Ushort = _word;
Type c_Char   = ShortInt;           Const _c_Char   = _ShortInt;
Type c_uchar  = Byte;               Const _c_uchar  = _Byte;
*/
#ifndef ks020_modelH
#define ks020_modelH
#include "ks_recs.h"
//---------------------------------------------------------------------------



// For MIL-1556 - Telemetry Model and DisKRY model

typedef enum{
_S_None,
_S_Fon,
_S_Din,
_S_Cont,
_S_Stat,
_S_Bd,
_S_Raz,
_R_None,
_R_Cont,
_R_Stat,
_R_Bd,
_R_A_16
}tmk_Packets;

typedef enum{
_s_None,
_s_Fon,
_s_Din,
_s_Cont,
_s_Stat,
_s_Bd,
_s_Raz
}tmk_S_Packets;

typedef enum{
_r_None,
_r_Cont,
_r_Stat,
_r_Bd,
_r_A_16
}tmk_R_Packets;




typedef ks_Fon_TypePrim ks_Fon_Type;
/*
  ������ ������ (������ �0-�������)
*/


typedef struct{
unsigned char z081;  // ������� ����� ������� (�������)
unsigned char z082;  // ������� ����� ������ (�������)
}ks_Raz_a0_Type;

typedef struct{
  ks_Fon_Type Fon;
}ks_Fon_Record;

//AnsiString TransType_Str[6] = {"NoTrans","��������","��������","��������","��������","�������"};

static const unsigned short Max_R_Cont_Size = 32-3; //����. ������ �������� ������:
                                             // -��� ����� �������
                                             // -��� ����� ����������
                                             // -�����. �����

enum{ksbNone,
/* 1 */ ksbMP,        // ��                          "���"     (2�44)
/* 2 */ ksbSKD,       // ���                         "���"     (2�45)
/* 3 */ ksbDPOBT,     // ���-��                      "���"     (2�45)
/* 4 */ ksbBD,        // ������� � ��                "�������" (2�47)
/* 5 */ ksbRecAvail,  // ���������� ������           "��"      (2�25)
/* 6 */ ksbAP,        // ��                          "���"     (2�44)
/* 7 */ ksCalibrBilu, // ���������� ����             "����"    (2�19)
/* 8 */ ksZaprContIK, // ���������� �������� ��      "����"    (2�19)
/* 9 */ ksZaprJustIK  // ���������� ��������� ��     "����"    (2�19)
}TKsButtons;

#endif
