#ifndef InPUconnect
#define InPUconnect
//---------------------------------------------------------------------------
#pragma hdrstop

#include "inpuconnect.h"
#include <winsock.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)

static int nResult;

SOCKET SPSSocket_ch1;             // ����� ������ 1 ���
SOCKET SPSSocket_ch2;             // ����� ������ 2 ���
sockaddr_in clientInPU_COM2;      // ��������� ������ ������� ���� 1

#endif
