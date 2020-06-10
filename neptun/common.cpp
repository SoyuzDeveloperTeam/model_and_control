//---------------------------------------------------------------------------
#ifndef commonM
#define commonM

#pragma hdrstop

#include "common.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

static enum{
R_Stat_NoPoll,
R_Stat_ApproachNavPoll,
R_Stat_OrbitalNavPoll,
R_Stat_LandingNavPoll,
R_Stat_TimePoll,
R_Stat_BiluPoll
}TransitType;

/* static AnsiString TransitNameStr[5] = {
"����� ��������� ���������",
"����� ����������� ���������",
"����� ��������� ������",
"����� �������",
"����� ����"}; */

enum{
argNone,
argUrgent,      // AAnn - ������� ������
                // 001xxnn  ������� ������
argSuppose, // 00: �������������� ������
argIKV_1,   // 01: ���-1
argIKV_2,   // 02: ���-2
argBDUS1_1, // 03: ����1-1
argBDUS1_2, // 04: ����1-2
argDPO_B,   // 05: ���-�
argDPO_M1,  // 06: ���-�1
argDPO_M2,  // 07: ���-�2
argSKD,     // 08: ��� (���-�)
argKDU,     // 09: ���
argAcc_1,   // 10: ������������� 1
argSB,      // 11: ��
argKURS_1,  // 12: ����-1
argKURS_2,  // 13: ����-2
argAcc_2,   // 14: ������������� 2
argAcc_3,   // 15: ������������� 3
argHints        // 00200nn  ����������
}ArgonMessageGroupType;

typedef enum {
NIP_MSK,
NIP_SPB,
NIP_DJS,
NIP_PPK,
NIP_KLP,
NIP_BRN,
NIP_USK,
NIP_ULD,
NIP_DRY,
NIP_WAL,
NIP_WHS,
NIP_MHX,
NIP_TUL,
NIP_PAR,
NIP_SR1,
NIP_SR2
}NipType;



#endif