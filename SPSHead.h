#include "wtypes.h"
#ifndef __SPSHead
#define __SPSHead
struct {
unsigned short TSpsParam[38];  } SpsDataSt;
// Пока double, но в Нептун передавать как Unsigned Short 

static bool CurSpsData; // Признак досстоверности данных с датчиков СПС


#endif
