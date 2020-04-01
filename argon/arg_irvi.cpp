//---------------------------------------------------------------------------
#pragma hdrstop
#include "arg_irvi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//=========
// Работа с ИРВИ

void SetIrvi (unsigned short Mode, unsigned short Addr, unsigned short Value, bool IsOct) {
// Задача - выставить на ИРВИ значения передаваемые этой процедурой
//
//  Mode - режим

}

bool CorrectAddr(unsigned short Addr) {
 if (Addr>4096) return false; else
 return true;
}

 