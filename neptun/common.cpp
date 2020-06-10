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
"Опрос навигации сближения",
"Опрос орбитальной навигации",
"Опрос навигации спуска",
"Опрос времени",
"Опрос БИЛУ"}; */

enum{
argNone,
argUrgent,      // AAnn - Срочные аварии
                // 001xxnn  Текущие аварии
argSuppose, // 00: предполагаемые аварии
argIKV_1,   // 01: ИКВ-1
argIKV_2,   // 02: ИКВ-2
argBDUS1_1, // 03: БДУС1-1
argBDUS1_2, // 04: БДУС1-2
argDPO_B,   // 05: ДПО-Б
argDPO_M1,  // 06: ДПО-М1
argDPO_M2,  // 07: ДПО-М2
argSKD,     // 08: СКД (ДПО-Б)
argKDU,     // 09: КДУ
argAcc_1,   // 10: акселерометры 1
argSB,      // 11: СБ
argKURS_1,  // 12: КУРС-1
argKURS_2,  // 13: КУРС-2
argAcc_2,   // 14: акселерометры 2
argAcc_3,   // 15: акселерометры 3
argHints        // 00200nn  Инструкции
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