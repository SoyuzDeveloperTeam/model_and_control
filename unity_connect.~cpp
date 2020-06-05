//---------------------------------------------------------------------------
#pragma hdrstop
#include <winsock.h>            // Для обмена с БУМ
#include "unity_connect.h"
#include "JouHeader.h"          // Заголовок для журнала
#include "JouStrings.h"         // Строковые переменные для журнала
#include "dta.cpp"              // Структура передаваемого/получаемого параметра
#include "winsock_ed.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#define DEFAULT_PORT "27015"   // Перенести в конфигурацию

static AnsiString unity_ip;    // UnityIP адрес из конфигурации
static AnsiString unity_port;  // Порт Unity из конфига

int uResult;

SOCKET unity_server;
SOCKADDR_IN addr;

SOCKET acceptS;
SOCKADDR_IN addr_c;
unsigned long ul = 1;

void unity_server_init () {
JPS(1,"Создание сервера для обмена с Юнити","","","");
        addr.sin_addr.s_addr = inet_addr("192.168.92.1");
        //addr.sin_addr.S_un.S_addr = "192.168.92.1";
	addr.sin_port = htons(27019);
	addr.sin_family = AF_INET;
        unity_server = socket(AF_INET, SOCK_STREAM, NULL);
        if (unity_server == SOCKET_ERROR) {
		JPS(3,"Ошибка создания сокета обмена с Юнити! Код: ","","","");
	}
        if (bind(unity_server, (struct sockaddr*)&addr, sizeof(addr)) != SOCKET_ERROR) {
		JPS(1,"Сокет обмена с Юнити успешно связан","","","");
	}
        if (listen(unity_server, SOMAXCONN) != SOCKET_ERROR){
		JPS(4,"Сокет обмена с Юнити переведен в режим прослушивания","","","");
	}
        ioctlsocket(unity_server, FIONBIO,(unsigned long *)&ul);
        }

void handle(){
int addrlen = sizeof(addr_c);
if ((acceptS = accept(unity_server, (struct sockaddr*)&addr_c, &addrlen)) != 0) {

        uResult = recv(unity_server, (char*)&unity_arr, sizeof(unity_arr), 0);
        if(uResult>0) JPS(1,"Error rec with code: "+IntToStr(uResult),"","","");  }
//SClient* client = new SClient(acceptS, addr_c);
}

void send_to_unity(int PT){
unity_arr.signature = 0xD8A73F93;
unity_arr.packet_type = PT;
uResult = send(unity_server,(char *)&unity_arr,sizeof(unity_arr), 0);   //
if (uResult == SOCKET_ERROR) GetWsaError(uResult);
}



