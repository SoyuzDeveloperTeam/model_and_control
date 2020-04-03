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
//---------------------------------------------------------------------------
#pragma package(smart_init)

AnsiString inpu_con_data[8];

TDateTime onboard_dt, dest_s, ob_cur;

static bool start_priz;

static bool bum_pr;             // Признак "С БУМ"

static TIniFile *MiuConf;       // Файл конфигурации

static AnsiString WsaIpAddr;    // IP адрес из конфигурации
static AnsiString WsaPortTele;  // Порт телеоператор из конфига
static AnsiString WsaPortTmtc;
static AnsiString WsaPortModel;
static AnsiString WsaPortCtrl;
static AnsiString ConfFileName;

static int iResult;                    // Результатирующая переменная
WSADATA wsaData;                // Структура Win Socket

// Сокеты обмена с БУМ
SOCKET CtrlSocket;              // Сокет управляющего интерфейса
SOCKET TmtcSocket;              // Сокет Командно-телеметрического интерфейса
SOCKET ModelSocket;             // Сокет модельного интерфейса
SOCKET TeleSocket;              // Сокет интерфейса "Телеоператор"

sockaddr_in ctrl_sock;
sockaddr_in tmtc_sock;
sockaddr_in model_sock;
sockaddr_in tele_sock;          // Структура адреса сервера БУМа для подключения к интерфейсу Телеоператор

struct{                         // Структура отправки команды в БУМ
int i;  //  4
int s;  //  8
int aa; //  16
int zr; //  20
int c;  //  24
}send_tru;


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

//////////////////////////////////
// Обработчик ошибок соеденения //
//////////////////////////////////
void GetWsaError (int GetLastError) {
      if (GetLastError==8)     JPS(3,"Недостаточно доступной памяти!","","","");
 else if (GetLastError==87)    JPS(3,"Один или несколько параметров недействительны!","","","");
 else if (GetLastError==995)   JPS(3,"Перекрывающая операция была отменена из-за закрытия сокета!","","","");
 else if (GetLastError==10013) JPS(3,"В доступе отказанно! ","","","");
 else if (GetLastError==10036) JPS(3,"Операция уже в процессе! ","","","");
 else if (GetLastError==10037) JPS(3,"Операция уже выполняется! ","","","");
 else if (GetLastError==10038) JPS(3,"Операция с сокетом на не-сокете! Возможно, что сокет уже закрыт.","","","");
 else if (GetLastError==10048) JPS(3,"Адрес уже используется! ","","","");
 else if (GetLastError==10049) JPS(3,"Неверное значение IP адреса! Проверь main_ip в miu_conf.ini","","","");
 else if (GetLastError==10051) JPS(3,"Была предпринята попытка операции с сокетом в недоступной сети.","","","");
 else if (GetLastError==10054) JPS(3,"Соединение принудительно закрыто удаленным хостом!","","","");
 else if (GetLastError==10057) JPS(3,"Операция невозможна, т.к. сокет не подключен!","","","");
 else if (GetLastError==10058) JPS(3,"Отправка невозможна, т.к. сокет уже закрыт!","","","");
 else if (GetLastError==10060) JPS(3,"Попытка подключения не удалась, потому что время подключения истекло!","","","");
 else if (GetLastError==10061) JPS(3,"В подключении отказанно, так как БУМ не ответил. БУМ запущен?","","","");
 else if (GetLastError==10062) JPS(3,"Не могу перевести имя!","","","");
 else if (GetLastError==11001) JPS(3,"Хост не найден!","","","");
 else if (GetLastError==11003) JPS(3,"Неисправимая ошибка!","","","");
 else if (GetLastError==11004) JPS(3,"Допустимое имя, нет записи данных запрощенного типа.","","","");
 else if (GetLastError==11017) JPS(3,"QSOS - ошибка! В QOS обнаружен неверный или несовместимый поток данных.","","","");
 else if (GetLastError==11018) JPS(3,"Недопустимый буфер, зависящий от провайдера QoS.","","","");
 else JPS(3,"Ошибка подключения! Код: "+IntToStr(GetLastError),"","",""); }

void SendToBum (int Cmd,int p1, int p2){
send_tru.i = 0x02000700;
send_tru.s = 0x00001500;
send_tru.aa = ntohl(Cmd);
send_tru.zr = ntohl(p1);
send_tru.c = ntohl(p2);
if(bum_pr){
iResult = send( TeleSocket,(char *)&send_tru,20, 0);   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());}
}
#endif bum_connect
