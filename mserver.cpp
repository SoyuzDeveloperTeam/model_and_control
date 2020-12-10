//---------------------------------------------------------------------------
#include <windows.h>
// #include <winsock2.h>
// #include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include "JouHeader.h"          // Заголовок для журнала
#include "JouStrings.h"         // Строковые переменные для журнала
#include "winsock_ed.cpp"

#pragma hdrstop

#include "mserver.h"

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "5449"
#define MCC_PORT "5440"
//---------------------------------------------------------------------------

#pragma package(smart_init)

struct{
int PacketNo;
int proc;
int ess_t;
int hk1_t;
int hk2_t;
int band_type;
bool sg_status[4];
bool sg;
}packet_ser;

    //struct sockaddr_in *result = NULL;
    //struct sockaddr_in *result_mcc = NULL;
    struct sockaddr_in server;
    //struct sockaddr_in p_from_mcc;

char buffer_ss[sizeof(packet_ser)];

int ms_init(){
  JPS(1,"Зaпуск серверa - MCC","","","");
  WSADATA wsaData;
  int iResult;
  int as, ms;

  SOCKET ServerMCCSocket = INVALID_SOCKET;

  as = socket(AF_INET, SOCK_STREAM, 0 );

  int iSendResult;
  char recvbuf[DEFAULT_BUFLEN];
  int recvbuflen = DEFAULT_BUFLEN;

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        JPS(3,"WSAStartup failed with error: ", IntToStr(iResult),"","");
        return 1;
    }

    server.sin_family = AF_INET; /* IP */
    server.sin_addr.s_addr = INADDR_ANY; /* ????? ??????? ????????? */
    server.sin_port = htons(54980); /* ???? */

    iResult = bind(as, (struct sockaddr *) &server, sizeof(server));
    if (iResult == SOCKET_ERROR) GetWsaError(iResult);

    iResult = listen(as, 5);
    if (iResult == SOCKET_ERROR) GetWsaError(iResult);

    do {
     iResult = recv(ms, buffer_ss, sizeof(buffer_ss),0);
     memcpy(buffer_ss, &packet_ser, sizeof(packet_ser));
     ms = accept( as, 0, 0 );
     ZeroMemory( buffer_ss, sizeof(buffer_ss));
     closesocket( ms ); /* ????????? ?????????? ? ???????? */
    } while (iResult > 0);

    JPS(1,"Зaпуск серверa - Зaпущен","","","");

    if (iResult == SOCKET_ERROR) GetWsaError(iResult);
    return 1;
}
