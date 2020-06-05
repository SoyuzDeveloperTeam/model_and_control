#ifndef InPUconnect
#define InPUconnect
//---------------------------------------------------------------------------
#pragma hdrstop

#include "inpuconnect.h"
#include <winsock.h>
//---------------------------------------------------------------------------

#pragma package(smart_init)

static int nResult;

SOCKET SPSSocket_ch1;             // Сокет канала 1 СПС
SOCKET SPSSocket_ch2;             // Сокет канала 2 СПС
sockaddr_in clientInPU_COM2;      // Структура адреса сервера ИнПУ 1

#endif
