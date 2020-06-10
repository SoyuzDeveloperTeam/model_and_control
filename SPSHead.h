#include "wtypes.h"
#ifndef __SPSHead
#define __SPSHead
static struct {
unsigned short TSpsParam[38];  } SpsDataSt;
static double TSpsDataN[38];
// Пока double, но в Нептун передавать как Unsigned Short 

static bool CurSpsData; // Признак досстоверности данных с датчиков СПС


#endif
