#ifndef bum_connect
#define bum_connect
//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include <winsock.h>            // Для обмена с БУМ
#include <IniFiles.hpp>         // Для работы с файлом конфигурации
#include "bumconnect.h"
#include "JouHeader.h"          // Заголовок для журнала
#include "JouStrings.h"         // Строковые переменные для журнала
#include "winsock_ed.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void Config_init (AnsiString iniName) {  // Процедура инициализации файла конфигурации
ConfFileName = "C:\1231231\Out\miu_config.ini";  // Создаем имя файла конфигурации
MiuConf = new TIniFile(iniName);                                   // Присваиваем
if(FileExists(iniName))                                            // Если такой файл существует, то...
{
JPS(1,"Чтение файла конфигурации...","","","");                         // Логируем о начале процесса чтения файла
WsaIpAddr = MiuConf->ReadString("WSA","main_ip","0.0.0.0");             // Основной айпишник
WsaPortTele = MiuConf->ReadString("WSA","tele_port","2002");
inpu_con_data[0] = WsaIpAddr;
inpu_con_data[3] = MiuConf->ReadString("WSA","ctrl_port","0000");
inpu_con_data[4] = MiuConf->ReadString("WSA","tmtc_port","0000");
inpu_con_data[5] = MiuConf->ReadString("WSA","model_port","0000");
inpu_con_data[1] = MiuConf->ReadString("INPU","inpu1_port_com1","0000");
inpu_con_data[2] = MiuConf->ReadString("INPU","inpu1_port_com2","0000");
} else JPS(3,"Отсутствует файл конфигурации!","","","");

}



void SendToBum (int Cmd,int p1, int p2){
send_tru.i = 0x02000700;
send_tru.s = 0x00001500;
send_tru.aa = ntohl(Cmd);
send_tru.zr = ntohl(p1);
send_tru.c = ntohl(p2);
if(bum_pr){
iResult = send( TeleSocket,(char *)&send_tru,20, 0);   //
if (iResult == SOCKET_ERROR) GetWsaError(iResult);}
}
#endif bum_connect
