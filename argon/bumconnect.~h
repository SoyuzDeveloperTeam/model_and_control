//---------------------------------------------------------------------------

#ifndef bumconnectH
#define bumconnectH
//---------------------------------------------------------------------------
static AnsiString inpu_con_data[8];

static TDateTime onboard_dt, dest_s, ob_cur;

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
static WSADATA wsaData;                // Структура Win Socket

// Сокеты обмена с БУМ
static SOCKET CtrlSocket;              // Сокет управляющего интерфейса
static SOCKET TmtcSocket;              // Сокет Командно-телеметрического интерфейса
static SOCKET ModelSocket;             // Сокет модельного интерфейса
static SOCKET TeleSocket;              // Сокет интерфейса "Телеоператор"

static sockaddr_in ctrl_sock;
static sockaddr_in tmtc_sock;
static sockaddr_in model_sock;
static sockaddr_in tele_sock;          // Структура адреса сервера БУМа для подключения к интерфейсу Телеоператор

static struct{                         // Структура отправки команды в БУМ
int i;  //  4
int s;  //  8
int aa; //  16
int zr; //  20
int c;  //  24
}send_tru;
#endif
