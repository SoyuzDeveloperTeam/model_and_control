//---------------------------------------------------------------------------
#pragma hdrstop
#include "arg_irvi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//=========
// ������ � ����

void SetIrvi (unsigned short Mode, unsigned short Addr, unsigned short Value, bool IsOct) {
// ������ - ��������� �� ���� �������� ������������ ���� ����������
//
//  Mode - �����

}

bool CorrectAddr(unsigned short Addr) {
 if (Addr>4096) return false; else
 return true;
}

 