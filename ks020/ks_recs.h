#ifndef ks_recs
#define ks_recs

typedef struct{
  unsigned short z1161;  // Nmax - ������������ ����������      ������� g0  0..999
  unsigned short z1162;
  unsigned short z1163;
  unsigned short z1166;
}TRaz_02;

//  ������ �����         - TInp_##
//  ������� ������       - TRaz_## (������ ��������� (TInp_##))
//  ������������ ������  - TDin_##

static const unsigned short SmallGlobusTraceWidth = 74; // ��� ��� ���������� �������
static const unsigned short S_Din_DeltaSize = 2; // 1 CRC + 1 Control
static const unsigned short S_Raz_DeltaSize = 3; // 1 CRC + 1 Control + 1 CN_S_Raz
static const unsigned short S_Din_MaxSize = 32*320-2;
static const int TraceArrayLength = 100;

enum{
SmallGlobus_No, //0 -  �������
BigGlobus_No,   //1 -  ���
BNO_No,         //2 -  ���
AUS_No,         //3 -  ���
RUS_No,         //4 -  ���
VC_No,          //5 -  ������
Spusk_No,       //6 -  �����
SA_No,          //7 -  ��
Nip_No,         //8 -  ���
Transit_No,     //9 -  �������
Manevr_No,      //10 - ������
Kontr_No        //11 - �����
#ifdef Bilu
,Bilu_No        //12 - ����
#endif
}ksFormats;

static unsigned short SmallGlobusTraceType[SmallGlobusTraceWidth-1];

/*
  ������� ���������.
  ������ ������ (������ �1-�������) 8 ����
*/

typedef struct{
short LongDeg;             // z150 - ������� �������������� �����
short LatDeg;              // z151 - ������ �������������� �����
unsigned short LongPix;    // z180 - ������� �������������� ����� (�������)
unsigned short RadioH;     // z170 - ���� ������� ���� ��
unsigned short RadioM;     // z181 - ������  ������� ���� ��
unsigned short RadioS;     // z182 - ������� ������� ���� ��
unsigned short SunH;       // z171 - ���� ������� �������-������
unsigned short SunM;       // z183 - ������  ������� �������-������
unsigned short SunS;       // z184 - ������� ������� �������-������
unsigned short z185;       // z185 - ��������� � ��
unsigned short z186;       // z186 - ���������
unsigned short z187;       // z187 - ���������
unsigned short DetachSign; // z188 - ������� ����������
}ks_Fon_TypePrim;

#endif //ks_recs
 