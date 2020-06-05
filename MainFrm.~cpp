/***************************************************************************/
/*                  СПО "Моделирование и Управление"                       */
/*-------------------------------------------------------------------------*/
/* СПО "МиУ" предназначено для моделирования движения транспортного        */
/* пилотируемого корабля Союз-ТМА на околоземной орбите, путем             */
/* интегрирования уравнений движения, а также управления перемещением и    */
/* ориентацией модели корабля как в автоматическом, так и в ручном режимах */
/* согласно штатной логике вычислительных устройств, алгоритмы которых     */
/* реализованы в данном ПО.                                                */
/*-------------------------------------------------------------------------*/
/***************************************************************************/
// Отладка поиска зависания:
// Отключил таймеры локальное время, отладочный, таймер №5 (работа с ОЗУ), таймер №2 (иконка БУМ)
//---------------------------------------------------------------------------
#pragma hdrstop
#include <vcl.h>
#include "MainFrm.h"
#include <vector.h>
#include <math.h>
#include <Tlhelp32.h>
//---------------------------------------------------------------------------
/* Заголовки */
#include "MD_math_header.h"
#include "main_header.h"                // Основной заголовок
#include "JouHeader.h"                  // Заголовок для журнала
#include "arg_jou.h"                    // Журнал Аргона
#include "dta.cpp"                      // Данные для обмена с БУМ
#include "md_m.h"                       // Модельные переменные
#include "ts_header.h"                  // Переменные ТС
#include "ICN_header.h"                 // Данные для обмена с ИнПУ
#include "JouStrings.h"                 // Строковые переменные для журнала
#include "SPSHead.h"                    // Данные СПС ч.1
#include "USOData.h"                    // Параметры УСО
#include "uso_model.cpp"                // Модель УСО
#include "inpu_connect.cpp"             // Обмен с моделью ИнПУ
#include "main_math.cpp"                // Математические модели
#include "argon/arg_header.h"           // Загогловок А16
#include "argon/CtrlWord.h"             // Управляющие слова Аргона
#include "argon/arg_kdu_operations.cpp" // Argon-16 программы КДУ
#include "sotr_data.h"                  // Модель СОТР
#include "DateUtils.hpp"
#include "argon/arg_pks.cpp"            // Программы Аргона
#include "bumconnect.cpp"               // Обмен с БУМ
#include "neptun_main.cpp"              // Основные процедуры ПСА "Нептун-МЭ"
#include "unity_connect.cpp"            // Обмен с Юнити
#include "inpuconnect.cpp"              // Обмен с ИнПУ
//---------------------------------------------------------------------------
/* Формы */
//#include "help_form.cpp"                // Форма Поддержи
#include "bilu_format.cpp"              // Форма БИЛУ
#include "vived_frm.cpp"                // Форма Выведение (график)
#include "brus_form.cpp"                // Форма БРУС
#include "ts_frm.cpp"                   // Форма ТС
#include "bfi_formats.cpp"              // Форма "БФИ Символ" для А16
#include "bum_sett_frm.cpp"             // Форма вывода данных БУМ
#include "toru_frm.cpp"                 // Форма пульта ПУ БПС ТОРУ
#include "EnterNuFrm.cpp"               // Форма ввода начальных условий (НУ)
#include "kdu_data.cpp"                 // Форма параметров КДУ
#include "clock_form.cpp"               // Форма БЧК-744К Бортовые Часы на РС МКС
#include "JouLogFrm.h"                  // Форма основного журнала
#include "zakon_upr.cpp"                // Форма Закон Управления
#include "KSPLForm.cpp"                 // Форма КСП левое
#include "KSPPForm.cpp"                 // Форма КСП правое
#include "USOFrm.cpp"                   // Форма УСО
#include "cdn_clock_frm.cpp"            // Форма CDN clock MSK
#include "AboutFrm.cpp"                 // Форма "О программе..."
#include "BkuCFrm.cpp"                  // Форма БКУ-Ц "Символ-Ц"
#include "irvi_brfi_frm.cpp"            // Форма ПРВИ
#include "graph_a1.cpp"                 // Форма графиков
#include "SOTR_frm.cpp"                 // Форма СОТР
#include "InstructorFormat_Form.cpp"    // Форма инструкторского формата
#include "vku_graph.cpp"                // Форма ВКУ графиком
#include "iss_per_tp.cpp"               // Форма Переход МКС в ТП
#include "argon_debug_frm.cpp"          // Форма отладки Аргона
#include "debug_bum_frm.cpp"            // Форма отладки обмена с БУМ
#include "otkazy.cpp"                   // Форма "Отказ Бортоввых Систем"
#include "neptun.cpp"                   // Форма ПСА "Нептун-МЭ" -  ИнПУ1
#include "sps_frm.cpp"                  // Форма СПС
// Форматы Laptop РС МКС (СМ)
#include "sm_ssvp_PX.cpp"               // Формат СМ:ССВП:+Х
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
#define n_act_str 5    //Номер актуальной струтуры
static AnsiString StrForDebug;

// Для тестов  (ОПИСАТЬ!)

static int j_test;
static bool vill_test;
static int f_test;
TDateTime SFD_sec;
static double ghjh;

// -- -- -- --

HINSTANCE Lib = LoadLibrary("LIB_BNO.dll");                    // загружаем библиотеку динамически

TInit Init = 0;                                                // Make object's
TGetMagData GetMagData = 0;
TGetGravTorqueData GetGravTorqueData = 0;
//---------------------------------------------------------------------------

static int qss;
static int disp[3];
static vector <int> STBv(3);

int test_test_tse;

int image_index;

struct {
int a;
int b;
int c;
}sends;
  int intVariable;
bool startdelay;
bool iniread;

static int qwe;

//---------------------------------------------------------------------------



const int MAX_BUF_SIZE = 1024;

static bool init;            // Признак успешной инициализации  (перенести в main?)
static int err;
static bool con;             // Признак удачного подключения для активации кнопок
static bool inpu_com2_connect_pr; // Признак связи с ИнПУ
WORD wVersionRequested;

//---------------------------------------------------------------------------
struct STR_temp *DATA_FROM_MS_mas[12];

AnsiString sendText;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
MainForm->Caption="Симулятор Союз-ТМА  |  Версия: "+ActVer;
StatusBar->Panels->Items[2]->Text="O";
init=false;
con=false;
//startdelay=true;
err = WSAStartup(wVersionRequested, &wsaData);
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::pusk_btnClick(TObject *Sender)
{ // Операции по нажатию кнопки "ПУСК"
if(bum_pr){                        // Есл есть признак обмена с БУМ, то...
p_sost_from_bum->Enabled=true;
start_priz = true;                 // признак запуска для бум
SendToBum(0x00000301, 2, 1); }     //Пуск динамики - команда в БУМ ()
PuskPr = true;                     // Вводим признак "Пуск динамики"
ModelDateTime_Timer->Enabled=true; // Запускаем таймер модельного времени (он и задает модельное время при отсутствии БУМ - иначе выводим от БУМа)
MainTimer->Enabled=true;           // Запуск глобального обработчика команд. Разрешение КСП, УСО и т.д.
ChekTSKD->Enabled=true;            // Обработчик операций СКД
pusk_btn->Enabled=false;           // Блокируем кнопку "ПУСК" во избежание сбоев при повторной выдаче в динамике.
//Timer6->Enabled=true;
JPS(1,is_operator,is_miu,"Пуск моделирования","");
arg_tst->Enabled=true;
StatusBar->Panels->Items[0]->Text="Запущен процесс моделирования...";
// Если этот комплект выступает в режиме сервера желательно блокировать кнопку "ПУСК" у клиентов
// и переименовывать ее в кнопку "подключится"
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N3Click(TObject *Sender)
{
ts_form->Show();  //Запуск формы "ТС"
}
//---------------------------------------------------------------------------
//void GetStructFromBUM(struct STR_temp* s)   // Получить от БУМа структуру параметров
//{
//memcpy((void *)s,(void *)&DATA_FROM_MS_mas[n_act_str],sizeof(STR_temp));
//}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N14Click(TObject *Sender)
{ // Запуск формы ТОРУ
toru_pult->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N1Click(TObject *Sender)      // Ввод НУ
{
EnterNuForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N15Click(TObject *Sender)     // Параметры КДУ
{
KDUform->Show();
}
//----------------------------------------//
// Процедуры по закрытию формы оператором //
//----------------------------------------//
void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
un_serv->Active=false;
if(PuskPr){ // Если на момент закрытия введен признак "Пуск динамики", то...
if(         // Выводим MessageBox
Application->MessageBox(
"Запущен процесс моделирования! \nВсе равно выйти?",
"Внимание!",
MB_YESNO|
MB_ICONINFORMATION) == IDNO){
Abort();
}
} // if PuskPr
WSACleanup();  // Так же в любом случае закрываем все сокеты
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N16Click(TObject *Sender)
{
clock_frm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N7Click(TObject *Sender)
{
JouLogForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button4Click(TObject *Sender)
{
if(bum_pr){
SendToBum(0x00000301, 2, 0);       // Пауза динамики - команда в БУМ ()
start_priz = false;                // Снимаем признак запуска БУМа
dk_to_bum->Enabled=false;           // Разрешение отправки параметров ДК в БУМ
p_sost_from_bum->Enabled=false;}
PuskPr = false;
ModelDateTime_Timer->Enabled=false;
MainTimer->Enabled=false;
ArgonTakt->Enabled=false;
//Timer6->Enabled=false;
pusk_btn->Enabled=true;
JPS(1,is_operator,is_miu,"Пауза моделирования","");
StatusBar->Panels->Items[0]->Text="Пауза процесса моделирования.";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TclConnected(TObject *Sender)
{
StatusBar->Panels->Items[0]->Text="["+Now().FormatString("hh.mm.ss.zzz")+"]  -  Подключен";
}
//---------------------------------------------------------------------------

char buff[5]={72,101,108, 108, 111};

void __fastcall TMainForm::N21Click(TObject *Sender)
{
BkuC->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N12Click(TObject *Sender)
{
AboutForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button6Click(TObject *Sender)
{
        iResult = closesocket(CtrlSocket);
        if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
        iResult = closesocket(TmtcSocket);
        if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
        iResult = closesocket(ModelSocket);
        if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
        iResult = closesocket(TeleSocket);
        if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
        bum_pr = 0;
        init_->Enabled=true;
        if(with_unity->Checked){  // Если введен признак "With Unity"
        unity_s_h->Enabled=false;
        } // with_unity
        JPS(3, "Внимание: Сокеты обмена с БУМ закрыт!", "", "", "");
}
//---------------------------------------------------------------------------
/////////////////////////////////////////
// Таймер текущего времени (локального //
//-------------------------------------//
// Запуск автоматом по запуску МиУ     //
/////////////////////////////////////////
void __fastcall TMainForm::LocalTimeTimerTimer(TObject *Sender)
{
LocalTime->Caption=Now().FormatString("hh:mm:ss");  // Вывод текущего времени ПК
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::kspl_loadClick(TObject *Sender)  // Запуск Формата КСПл
{
ksplfrm->Show();
}

//------------------------------------------------//
// П Р О Ц Е Д У Р А   И Н И Ц И А Л И З А Ц И И  //
//------------------------------------------------//
VOID __fastcall TMainForm::init_Click(TObject *Sender)
{
JPS(1,is_operator,is_miu,"Запущен процесс инициализации.","");

// Подготовка структуры параметров от ДК для БУМ-МС
dk_mass.str_1 = 0x02000700;
dk_mass.str_2 = 0x00001500;
dk_mass.cmd   = 0x00200101;
dk_mass.size  = ntohl(48);

  if( Lib >= (HINSTANCE)32 )  // Загружаем библиотеку для мат.моделирования
  {
    Init = (TInit)GetProcAddress( Lib, "_Init");
    GetMagData = (TGetMagData)GetProcAddress( Lib, "_GetMagData" );
    GetGravTorqueData = (TGetGravTorqueData)GetProcAddress( Lib, "_GetGravTorqueData" );
  }

  if( !GetMagData || !Init || !GetGravTorqueData)                // Проверяем загрузилась ли библа
   JPS(3,"","","Ошибка загрузки библиотеки МиОП BNO.",""); else {
   JPS(1,"","","Загруженна библиотека МиОП BNO.","");
   Init();
   JPS(1,"","","МиОП BNO инициализирован.",""); }

Config_init(ExtractFilePath(Application->ExeName)+"miu_config.ini");  // Инициализация файла конфигурации

if(!WithoutBum->Checked){ // Если нет признака "Без БУМ"
bum_pr = true;
/*
  Операция попытки подключения должна повторятся
  циклично до момента установки соеденения с БУМ.

  Создаем последовательно все сокеты обмена с БУМ
  ----------
  В конфигурации симулятора инициализация должна
  проводится автоматически по запуску симулятора.
  Журналирование должно идти в консоль, а так же в консоль сервера.
*/
JPS(1,"Начало инициализации протокола обмена с БУМ","","","");  // Логируем о начале
}
//---------//
// 1.1.1. Инициализация Winsock //

iResult = WSAStartup(MAKEWORD(2,2), &wsaData); // Инициализируем...
	if (iResult != 0)                      // Обработчик ошибки инициализации
	{
		JPS(3,"Ошибка инициализации WinSock! Код: "+IntToStr(err),"","","");
		WSACleanup();
	}
        if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
                JPS(3,"Не удалось подгрузить актуальную версию Winsock.dll","","","");
                WSACleanup(); }  else {        // Если удачная инициализация и подключение библы, то...
                JPS(1,"Загруженна библиотека Winsock.dll","","","");}

//---------//
// 1.1.2. Объявление сокетов подключения к БУМ

CtrlSocket = socket(AF_INET, // Семейство адресов Интернет-протокола версии 4 (IPv4).
                 SOCK_DGRAM, // Этот тип сокета использует протокол пользовательских дейтаграмм (UDP)
                IPPROTO_UDP  // Протокол пользовательских дейтаграмм (UDP).
                );           // Сокет управляющего интерфейса
TmtcSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);           // Сокет КТМ
ModelSocket= socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);           // Сокет Model
TeleSocket = socket(AF_INET, // Семейство адресов Интернет-протокола версии 4 (IPv4).
                SOCK_STREAM, // Этот тип сокета использует протокол управления передачей (TCP)
                IPPROTO_TCP  // Протокол управления передачей (TCP).
                );           // Сокет телеоператор

StatusBar->Panels->Items[2]->Text="И  П";   // Текущее состояние МиУ И - Инициализация, П - протокол

//---------//
// 1.1.3. Подготовка структуры связи сокета с сервером

// inet_addr((unsigned char)MiuConf->ReadString("WSA","main_ip","0.0.0.0"))
// "вынимаем" из файла конфигурации актуальные данные
AnsiString fdsfd = MiuConf->ReadString("WSA","main_ip","0.0.0.0");
char * ipaddress = fdsfd.c_str(); // Актуальный IP адрес (должнен быть так же указан в конфиге БУМа и БММ)

// Teleoperator
tele_sock.sin_family = AF_INET;                    // Семейство адресов Интернет-протокола версии 4 (IPv4).
tele_sock.sin_addr.s_addr = inet_addr(ipaddress);  //
tele_sock.sin_port = htons(WsaPortTele.ToInt());   // То же + делать проверку на соответствие в конфиге БУМа

// TMTC
tmtc_sock.sin_family = AF_INET;                    // Всегда равно AF_INET !
tmtc_sock.sin_addr.s_addr = inet_addr(ipaddress);  //
tmtc_sock.sin_port = htons(inpu_con_data[4].ToInt());     // То же + делать проверку на соответствие в конфиге БУМа

// Модельный интерфейс (СКГИ)
model_sock.sin_family = AF_INET;                   // Всегда равно AF_INET !
model_sock.sin_addr.s_addr = inet_addr(ipaddress); //
model_sock.sin_port = htons(inpu_con_data[5].ToInt());                // То же + делать проверку на соответствие в конфиге БУМа

// Сокет управляющего интерфейса
ctrl_sock.sin_family = AF_INET;                    // Всегда равно AF_INET !
ctrl_sock.sin_addr.s_addr = inet_addr(ipaddress);  //
ctrl_sock.sin_port = htons(inpu_con_data[3].ToInt());                 // То же + делать проверку на соответствие в конфиге БУМа

//---------//
// 1.1.4. Попытка подключения к серверу
if(!WithoutBum->Checked){
/* iResult = bind(CtrlSocket,  (SOCKADDR *) & ctrl_sock,  sizeof (ctrl_sock));  // Подключаемся
        if (iResult == SOCKET_ERROR) { GetWsaError(WSAGetLastError());  } else { JPS(4,"БУМ - Есть подключение к командному интерфейсу","","","");  }
iResult = bind(TmtcSocket,  (SOCKADDR *) & tmtc_sock,  sizeof (tmtc_sock));
        if (iResult == SOCKET_ERROR) { GetWsaError(WSAGetLastError());  } else { JPS(4,"БУМ - Есть подключение к КТМ интерфейсу","","",""); }
iResult = bind(ModelSocket, (SOCKADDR *) & model_sock, sizeof (model_sock));
        if (iResult == SOCKET_ERROR) { GetWsaError(WSAGetLastError());  } else { JPS(4,"БУМ - Есть подключение к модельному интерфейсу","","","");  }  */
iResult = connect(TeleSocket,  (SOCKADDR *) & tele_sock,  sizeof (tele_sock));
        if (iResult == SOCKET_ERROR) { GetWsaError(WSAGetLastError());  } else { // Если подключение успешно, то...
          JPS(4,"БУМ - Есть подключение к интерфейсу Телеоператор","","","");
          JPS(4,"Подключение к БУМ - Успешно","","","");
          init=true;      // Выставляем признак успешной инициализации подключения - можно посылать команды
          //ModelStatusPicList->GetBitmap(1, bum_status_pic->Picture->Bitmap);
          con=true;
          //SocketTeleConnectTimer->Enabled=false;
          }         // Выставляем признак успешного подключения
StatusBar->Panels->Items[2]->Text="И  О";                 // Меняем статус МИУ на О - Отправка команды
}
if(WithoutBum->Checked){
 init=true;
 con=true;
}

if(with_unity->Checked){  // Если введен признак "With Unity"
unity_server_init ();
unity_s_h->Enabled=true;
} // with_unity

JPS(1,"Подготовка начальных параметров СУБК","","","");
//  Расчет парабол для закона управления
r_m[0] = 200;
r_m[1] = 205;
r_m[2] = 215;
r_m[3] = 225;
r_m[4] = 250;
r_m[5] = 275;
r_m[6] = 300;
r_m[7] = 350;
r_m[8] = 400;
r_m[9] = 500;
r_m[10] = 600;
r_m[11] = 700;
r_m[12] = 800;
r_m[13] = 900;
r_m[14] = 1000;
r_m[15] = 1500;
r_m[16] = 1600;
r_m[17] = 1700;
r_m[18] = 1800;
r_m[19] = 1900;
r_m[20] = 2000;
r_m[21] = 2100;
r_m[22] = 2200;
r_m[23] = 2300;
r_m[24] = 2400;
r_m[25] = 2500;
r_m[26] = 2600;
r_m[27] = 2700;
r_m[28] = 2800;
r_m[29] = 2900;
r_m[30] = 3000;
r_m[31] = 5000;

int isd = 0;

for(isd; isd<=31; isd++){   // Производим расчет парабол для ЗУ
v_verch[isd] = sqrt( 2 * ax_verh *(r_m[isd]-200));
v_b1b2[isd] = sqrt( 2 * ax_b1b2 *(r_m[isd]-200));
v_k1k2[isd] = sqrt( 2 * ax_k1k2 *(r_m[isd]-200));
v_half_k1k2[isd] = sqrt( 2 * ax_half *(r_m[isd]-200));
v_verch[isd] = sqrt( 2 * ax_verh *(r_m[isd]-200));
v_sred[isd] = sqrt( 2 * ax_sred *(r_m[isd]-200));
v_niz[isd] = sqrt( 2 * ax_nijn *(r_m[isd]-200));
}

// Выставляем начальные признаки для работы СУДН
arg_work_pr = 0;
tResult = 2; // Нет теста А16
/*
  +-------------------------------------+
  |  2. Инициализация обмена с ИнПУ     |
  +-------------------------------------+

  +-------------------------------------+
  |  2.1. Запуск клиента Сом1 и Сом2    |
  +-------------------------------------+
*/
if(sps_model->Checked)                  // Если есть признак "Обмен с ИнПУ"
inpu_com2_connect->Enabled=true;        // Запускаем таймер подключения к ИнПУ
else JPS(1,"Внимание: Инициализация без обмена с ИнПУ","","","");

if(init){   // Если есть признак инициализации, то...
init_->Enabled=false;
Button9->Enabled=true;
Button4->Enabled=true;
Button6->Enabled=true;
if(WithoutBum->Checked){
 JPS(1,"","","Автономный вариант без моделей","");
}
JPS(1,"Процедура инициализации завершена. ","","","");
StatusBar->Panels->Items[0]->Text="Процедура инициализации завершена. Ожидание отработки начальных условий...";
} else
JPS(3,"Процедура инициализации не завершена. Код: "+IntToStr(WSAGetLastError()),"","","");
}

void __fastcall TMainForm::SPSClientDisconnected(TObject *Sender)
{
JPS(1,"СПС Отключен. ","","","");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N22Click(TObject *Sender)
{
bum_settings->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N4Click(TObject *Sender)
{
UsoForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer2Timer(TObject *Sender)
{
if(con){                        // Если есть признак подключения
if(!WithoutBum->Checked){       // Если нет влага "Без БУМ"
bum_status_pic->Invalidate();   // Обновляем иконку-статус БУМ
bum_status_pic->Invalidate();
bum_status_pic->Invalidate();
ModelStatusPicList->GetBitmap(1, bum_status_pic->Picture->Bitmap);
}
Timer2->Enabled=false; }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
ver_num=" 1.0.1.54";              // Переделать - выводить версию из атрибутов
// --- Выставляем начальное состояние иконок моделей --- //
ModelStatusPicList->GetBitmap(0, bum_status_pic->Picture->Bitmap);
ModelStatusPicList->GetBitmap(0, inpu_status_pic->Picture->Bitmap);
ModelStatusPicList->GetBitmap(0, argon_status_pic->Picture->Bitmap);
ModelStatusPicList->GetBitmap(0, SpsStatusPic->Picture->Bitmap);
ModelStatusPicList->GetBitmap(0, bum_status_pic->Picture->Bitmap);
image_index = 0;
IdCanSend = false;
PuskPr = false;  
CO_light->Color=StringToColor("0x45607B");     // Цвет фона ЦО
StatusBar->Panels->Items[0]->Text="МиУ запущен. Ожидание инициализации...";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N24Click(TObject *Sender)
{
graphics->Show();
}
//---------------------------------------------------------------------------
//-----------------------------------------------//
// К О М А Н Д А   Н А   О Т Р А Б О Т К У   Н У //
//-----------------------------------------------//
void __fastcall TMainForm::Button9Click(TObject *Sender)
{
double q_mks[4], q_tk[4];
JPS(1,is_operator,is_miu,"Выдана команда - отработка НУ.","");

  // НУ для модели КУРСа и БЦВК
  SpsSend->Enabled=true;
  i_takt = 0;
  dynamics.rs = StrToFloat(EnterNuForm->ro_init->Text);      // Дальность начальная
  dynamics.sks = StrToFloat(EnterNuForm->ro_dot_init->Text); // Скорость начальная
  dynamics.modV = sqrt(dynamics.sks*dynamics.sks+dynamics.vbok*dynamics.vbok); // Модуль скорости
  dynamics.omy = StrToFloat(EnterNuForm->Edit63->Text);      // Угловая скорость ЛВ рыскание
  dynamics.omz = StrToFloat(EnterNuForm->Edit64->Text);      // Угловая скорость ЛВ тангаж
  dynamics.uomy = 0;                                         // Угол начальный
  dynamics.uomz = 0;                                         // Угол начальный
  dynamics.rasp = StrToFloat(EnterNuForm->tk_toplivo->Text); // Топливо ТПК
  //dynamics.vbok = sqrt((dynamics.omy*dynamics.omy+dynamics.omz*dynamics.omz)*0,017453*0,017453*dynamics.rs*dynamics.rs);
  dynamics.sks = -dynamics.sks;                              // Скорость с учетом унарного минуса
  // Set model Data and Time from NU form
  EnterNuForm->SetModelDatePicker->Time = EnterNuForm->SetModelTimePicker->Time;
  OnboardModelTime = EnterNuForm->SetModelDatePicker->Date;  // Выставляем модельное дату/время
  onboard_dt = OnboardModelTime;                             // Создаем штамп времени для работы с БУМ
  onboardTimeLabel->Caption=OnboardModelTime.FormatString("hh:nn:ss");
  // ntohl
  // Тип корабля (тренажёра)
  if(EnterNuForm->obj_tgk->Checked) NU_temp.n_tr=ntohl(0); else
  if(EnterNuForm->obj_tpk->Checked) NU_temp.n_tr=ntohl(1); else {
  JPS(1,is_miu,"Коле       Ты серьёзно? Решил выбрать МЛМ? Хе-хе...","","");
  if(EnterNuForm->obj_mlm->Checked) NU_temp.n_tr=ntohl(2);  }
  // Параметр Дата-время (модельное)
  NU_temp.nu_day  =ntohl(StrToInt(OnboardModelTime.FormatString("dd")));
  NU_temp.nu_month=ntohl(StrToInt(OnboardModelTime.FormatString("mm")));
  NU_temp.nu_year =ntohl(StrToInt(OnboardModelTime.FormatString("yyyy")));
  NU_temp.nu_hour =ntohl(StrToInt(OnboardModelTime.FormatString("hh")));
  NU_temp.nu_min  =ntohl(StrToInt(OnboardModelTime.FormatString("nn")));
  NU_temp.nu_sec  =ntohl(StrToInt(OnboardModelTime.FormatString("ss")-3));

  // -- ISS DATA -- //
  // Вектор положения ц.м. в J2000
  NU_temp.vec_j2000_mks[0]=StrToFloat(EnterNuForm->iss_pos_x->Text)*1000;
  NU_temp.vec_j2000_mks[1]=StrToFloat(EnterNuForm->iss_pos_y->Text)*1000;
  NU_temp.vec_j2000_mks[2]=StrToFloat(EnterNuForm->iss_pos_z->Text)*1000;
  // Скорость ц.м. в J2000
  NU_temp.vel_j2000_mks[0]=StrToFloat(EnterNuForm->iss_vel_x->Text);
  NU_temp.vel_j2000_mks[1]=StrToFloat(EnterNuForm->iss_vel_y->Text);
  NU_temp.vel_j2000_mks[2]=StrToFloat(EnterNuForm->iss_vel_z->Text);
  // Компоненты кватерниона разворота ССК РС относительно J2000
  // Расчитывать из углов ориентации (уточнить!)
  /* double q_mksn[4];
  double eiler_nu[3];
  eiler_nu[0] = StrToFloat(EnterNuForm->ang_gamma_iss->Text)*GraRad;
  eiler_nu[1] = StrToFloat(EnterNuForm->ang_psi_iss->Text)*GraRad;
  eiler_nu[2] = StrToFloat(EnterNuForm->ang_thetta_iss->Text)*GraRad;
  kgpt(eiler_nu[0],eiler_nu[1],eiler_nu[2],
       &q_mks[0],&q_mks[2],&q_mks[3],&q_mksn[4]);
       JPS(1,"Q_mks[0] = "+FloatToStr(q_mks[0]),"","","");
       JPS(1,"Q_mks[1] = "+FloatToStr(q_mks[1]),"","","");
       JPS(1,"Q_mks[2] = "+FloatToStr(q_mks[2]),"","","");
       JPS(1,"Q_mks[3] = "+FloatToStr(q_mks[3]),"","","");
  norm_q(q_mks,q_mksn);   // Нормируем
       JPS(1,"Q_mks[0] norm = "+FloatToStr(q_mksn[0]),"","","");
       JPS(1,"Q_mks[1] norm = "+FloatToStr(q_mksn[1]),"","","");
       JPS(1,"Q_mks[2] norm = "+FloatToStr(q_mksn[2]),"","","");
       JPS(1,"Q_mks[3] norm = "+FloatToStr(q_mksn[3]),"","","");  */
  //NU_temp.Q_mks[0] =  1;
  //NU_temp.Q_mks[1] =  0;
  //NU_temp.Q_mks[2] =  0;
  //NU_temp.Q_mks[3] =  0;
  // Вектор угловой скорости МКС относительно J2000 в проекциях на ССК РС
  NU_temp.w_j2000_mks[0]=StrToFloat(EnterNuForm->w_x_iss->Text)*GraRad;
  NU_temp.w_j2000_mks[1]=StrToFloat(EnterNuForm->w_y_iss->Text)*GraRad;
  NU_temp.w_j2000_mks[0]=StrToFloat(EnterNuForm->w_z_iss->Text)*GraRad;
  // Координаты Ц.М. МКС в РС (уточнить по поводу ввода НУ)
  NU_temp.vec_mks_PC[0]=StrToFloat(EnterNuForm->cm_x_iss->Text);
  NU_temp.vec_mks_PC[1]=StrToFloat(EnterNuForm->cm_y_iss->Text);
  NU_temp.vec_mks_PC[2]=StrToFloat(EnterNuForm->cm_z_iss->Text);
  // Масса МКС
  NU_temp.m_mk=StrToFloat(EnterNuForm->mass_iss->Text);
  // Массив моментов инерции МКС
  NU_temp.mi_mks[0][0]=StrToFloat(EnterNuForm->Jxx_iss->Text);
  NU_temp.mi_mks[1][1]=StrToFloat(EnterNuForm->Jyy_iss->Text);
  NU_temp.mi_mks[2][2]=StrToFloat(EnterNuForm->Jzz_iss->Text);
  NU_temp.mi_mks[0][1]=StrToFloat(EnterNuForm->Jxy_iss->Text);
  NU_temp.mi_mks[1][2]=StrToFloat(EnterNuForm->Jyz_iss->Text);
  NU_temp.mi_mks[2][0]=StrToFloat(EnterNuForm->Jzx_iss->Text);
  //NU_temp.mi_mks[0][2]=StrToFloat(EnterNuForm->Jxz_iss->Text);
  //NU_temp.mi_mks[1][0]=StrToFloat(EnterNuForm->Jyx_iss->Text);
  //NU_temp.mi_mks[2][1]=StrToFloat(EnterNuForm->Jzy_iss->Text);

  // -- ТК DATA -- //
  // Вектор положения ц.м. в J2000
  NU_temp.vec_j2000_tk[0]=StrToFloat(EnterNuForm->tk_pos_x->Text)*1000;
  NU_temp.vec_j2000_tk[1]=StrToFloat(EnterNuForm->tk_pos_y->Text)*1000;
  NU_temp.vec_j2000_tk[2]=StrToFloat(EnterNuForm->tk_pos_z->Text)*1000;
  // Скорость ц.м. в J2000
  NU_temp.vel_j2000_tk[0]=StrToFloat(EnterNuForm->tk_vel_x->Text);
  NU_temp.vel_j2000_tk[1]=StrToFloat(EnterNuForm->tk_vel_y->Text);
  NU_temp.vel_j2000_tk[2]=StrToFloat(EnterNuForm->tk_vel_z->Text);
  // Компоненты кватерниона разворота ССК ТК относительно J2000
        // Расчитывать из углов ориентации
  double q_tkn[4];
  kgpt(StrToFloat(EnterNuForm->ang_psi_tk->Text),  // Формируем
       StrToFloat(EnterNuForm->ang_thetta_tk->Text),
       StrToFloat(EnterNuForm->ang_gamma_tk->Text),
       &q_tk[0],&q_tk[2],&q_tk[3],&q_tk[4]);
  norm_q(q_tk,q_tkn);   // Нормируем
  NU_temp.Q_tk[0]= 1;   // Qs
  NU_temp.Q_tk[1]= 0;   // Qx
  NU_temp.Q_tk[2]= 0;   // Qy
  NU_temp.Q_tk[3]= 0;   // Qz
  // Вектор угловой скорости ТК относительно J2000 в проекциях на ССК ТК
  NU_temp.w_j2000_tk[0]=StrToFloat(EnterNuForm->w_x_tk->Text)*GraRad;
  NU_temp.w_j2000_tk[1]=StrToFloat(EnterNuForm->w_y_tk->Text)*GraRad;
  NU_temp.w_j2000_tk[0]=StrToFloat(EnterNuForm->w_z_tk->Text)*GraRad;
  // Координаты Ц.М. ТК в ТГК/ТПК (уточнить по поводу ввода НУ)
  NU_temp.vec_tk_TPK[0]=StrToFloat(EnterNuForm->cm_x_tk->Text);
  NU_temp.vec_tk_TPK[1]=StrToFloat(EnterNuForm->cm_y_tk->Text);
  NU_temp.vec_tk_TPK[2]=StrToFloat(EnterNuForm->cm_z_tk->Text);
  // Масса ТК
  NU_temp.m_tk=StrToFloat(EnterNuForm->mass_tk->Text);
  // Массив моментов инерции ТК
  NU_temp.mi_tk[0][0]=StrToFloat(EnterNuForm->Jxx_tk->Text);
  NU_temp.mi_tk[1][1]=StrToFloat(EnterNuForm->Jyy_tk->Text);
  NU_temp.mi_tk[2][2]=StrToFloat(EnterNuForm->Jzz_tk->Text);
  NU_temp.mi_tk[0][1]=StrToFloat(EnterNuForm->Jxy_tk->Text);
  NU_temp.mi_tk[1][2]=StrToFloat(EnterNuForm->Jyz_tk->Text);
  NU_temp.mi_tk[2][0]=StrToFloat(EnterNuForm->Jzx_tk->Text);
  //NU_temp.mi_tk[0][2]=StrToFloat(EnterNuForm->Jxz_tk->Text);
  //NU_temp.mi_tk[1][0]=StrToFloat(EnterNuForm->Jyx_tk->Text);
  //NU_temp.mi_tk[2][1]=StrToFloat(EnterNuForm->Jzy_tk->Text);
  // Запас топлива ТК
  NU_temp.nu_com_zapas=StrToFloat(EnterNuForm->tk_toplivo->Text);

  // Режим стабилизации МКС
  if(EnterNuForm->r_st_free->Checked)  NU_temp.r_st_mks=ntohl(0); else
  if(EnterNuForm->r_st_tp->Checked)    NU_temp.r_st_mks=ntohl(1); else
  if(EnterNuForm->r_st_osk->Checked)   NU_temp.r_st_mks=ntohl(2); else
  if(EnterNuForm->r_st_wconst->Checked)NU_temp.r_st_mks=ntohl(3);
  // Номер СУ к которому пристыкован ТК (при состыкованом состоянии)
  NU_temp.nu_otor_switch_styk_dk=ntohl(EnterNuForm->docking_uz->ItemIndex);

  // Номер СУ к которому выполняется причаливание (для ДК)
  NU_temp.n_su_4_dk=ntohl(EnterNuForm->dk_su->ItemIndex);

  // Признак состыкованного состояния ТК и МКС
  if(EnterNuForm->docking_pr->Checked) NU_temp.pr_doking=ntohl(1); else NU_temp.pr_doking=ntohl(0);

  // "Признак МЛМ" (признак несбывшихся мечт)
  if(EnterNuForm->sm_dp_so->Checked) NU_temp.nu_mlm_sost=ntohl(1); else
  if(EnterNuForm->sm_dp_mlm->Checked) NU_temp.nu_mlm_sost=ntohl(2);
  // Начальный режим работы СУДН
  if(EnterNuForm->avtsbl_pr->Checked) NU_temp.nr_sudn =ntohl(1); else
  if(EnterNuForm->roak_pr->Checked)   NU_temp.nr_sudn =ntohl(2); else
  if(EnterNuForm->rodk_pr->Checked)   NU_temp.nr_sudn =ntohl(3);
  NU_temp.vec_solar[0] = 0.234678763256245;      // Единичный вектор на солнце в J2000 - расчитывать при отработке  (получаем в алгоритме расчета элементов)
  NU_temp.vec_solar[1] = -0.945676544665;
  NU_temp.vec_solar[2] = 0.67276567569899;

J[0]=NU_temp.mi_tk[0][0];
J[1]=NU_temp.mi_tk[0][1];
J[2]=NU_temp.mi_tk[0][2];
J[3]=NU_temp.mi_tk[1][0];
J[4]=NU_temp.mi_tk[1][1];
J[5]=NU_temp.mi_tk[1][2];
J[6]=NU_temp.mi_tk[2][0];
J[7]=NU_temp.mi_tk[2][1];
J[8]=NU_temp.mi_tk[2][2];

// -- НУ для остальных систем/моделей --
// Записываем параметры СОТР
SpsDataSt.TSpsParam[20] = 2300.0;
SpsDataSt.TSpsParam[14] = 2200.0;
SpsDataSt.TSpsParam[14] = 2200.0;
//SpsDataSt.TSpsParam[25] = 180.50;
SpsDataSt.TSpsParam[26] = 180.90;
SpsDataSt.TSpsParam[21] = 2670.09;
SpsDataSt.TSpsParam[22] = 2670.13;
SpsDataSt.TSpsParam[13] = 230.0;
SpsDataSt.TSpsParam[10] = 230.0;
SpsDataSt.TSpsParam[19] = 7000.0;
SpsDataSt.TSpsParam[3] = 0.0;

NUotr = true; // Добавить обработку начальных условий на соответствие (верефикация)

// выставка начального состояния БС
if(USO_Booled[1][2]) USO_Booled[11][9] = false; else USO_Booled[11][9]=true;
if(USO_Booled[1][3]) USO_Booled[11][10]= false; else USO_Booled[11][10]=true;
a2_upr = -0.037; // Ускорение в продольном канале
a3_upr = 0.5 * 6.8 * 6.8 / (3000 - 200); // Ускорение параболы верхней границы закона
a4_upr = 0.00395;

struct{
int i;
int s;
int aa;
int ddd;
unsigned long a_a;
unsigned long b_a;
unsigned long b_b;
unsigned long b_c;
unsigned long c_a;
unsigned long c_b;
unsigned long c_c;
}assa;

if(bum_pr){
NU_temp.i = 0x02000700;
NU_temp.s = 0x00001500;
NU_temp.aa = ntohl(0x00100101);
NU_temp.ddd = ntohl(500);
iResult = send( TeleSocket,(char *)&NU_temp,524, 0  );        //
if (iResult == SOCKET_ERROR) { GetWsaError(WSAGetLastError()); } else {
StatusBar->Panels->Items[0]->Text="Выдана команда - отработка НУ! Ожидание запуска моделирования...";  }
iResult = recv( TeleSocket,(char *)&PS_tk_iss,1025, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError()); else JPS(1,is_bum,is_miu,"Полученно начальное состояние","");  } else
StatusBar->Panels->Items[0]->Text="Выдана команда - отработка НУ! Ожидание запуска моделирования...";
// получать подтверждение от БУМ //
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::PuskRgPrTimer(TObject *Sender)
{
if(con&&init&&NUotr){
  pusk_btn->Enabled=true;
  PuskRgPr->Enabled=false;
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N25Click(TObject *Sender)
{
sotr->Show();
}
//---------------------------------------------------------------------------
u_long iMode = 1;
void __fastcall TMainForm::inpu_com2_connectTimer(TObject *Sender)
{
if(!inpu_com2_connect_pr){
// Создание сокета подключениея к ИнПУ
SPSSocket_ch1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
// Подготовка структуры связи сокета с сервером
char * ipaddress = inpu_con_data[0].c_str(); // Current IP from INI config
int portdata = StrToInt(inpu_con_data[2]);
clientInPU_COM2.sin_family = AF_INET;
clientInPU_COM2.sin_addr.s_addr = inet_addr(ipaddress);
clientInPU_COM2.sin_port = htons(portdata);
iResult = connect(SPSSocket_ch1, (SOCKADDR *) & clientInPU_COM2, sizeof (clientInPU_COM2));
  if (iResult == SOCKET_ERROR)
  {
  qwe++;
  // Действия по ошибке соеденения
  } else {
inpu_com2_connect_pr=true;
inpu_com2_connect->Enabled=false;
JPS(4,"Процесс инициализации обмена с ИнПУ завершен успешно.","","","");
iResult = ioctlsocket(SPSSocket_ch1, FIONBIO, &iMode);
arg_tst->Enabled;
inpu_status_pic->Invalidate();
ModelStatusPicList->GetBitmap(1, inpu_status_pic->Picture->Bitmap);
}
}
//Label19->Caption="Счетчик ошибок соединения: "+IntToStr(qwe);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button7Click(TObject *Sender)
{
send_to_unity(5);
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::arg_tstTimer(TObject *Sender)
{
 CounterNo++;                                        // Номер пакета +1
PacketHeaderType.Signature = PacketSignatureR;      // Сигнатура пакета
PacketHeaderType.No = CounterNo;                    // Номер пакета
PacketHeaderType.Size = sizeof(USO_BT);             // Размер пакета = размер буфера УСО
PacketHeaderType.PacketID = PacketIDtype(idUso);    // USO


// Побитовое сложение
// Слово "00"
/*
   Переменая          Слово  Буква          Значение   */
S_00[0]+= (int)USO_Booled[0][0];  //  00F - KSP A1
S_00[0]+= (int)USO_Booled[0][1];  //  00E - KSP A3
S_00[0]+= (int)USO_Booled[0][2];  //  00D - KSP A5
S_00[0]+= (int)USO_Booled[0][3];  //  00C - KSP A7

S_00[1]+= (int)USO_Booled[0][4];  //  00B - KSP A9
S_00[1]+= (int)USO_Booled[0][5];  //  00A - KSP A11
S_00[1]+= (int)USO_Booled[0][6];  //  009 - KSP A13
S_00[1]+= (int)USO_Booled[0][7];  //  008 - KSP A15

S_00[2]+= (int)USO_Booled[0][8];  //  007 - KSP A17
S_00[2]+= (int)USO_Booled[0][9];  //  006 - KSP b1
S_00[2]+= (int)USO_Booled[0][10]; //  005 - KSP b3
S_00[2]+= (int)USO_Booled[0][11]; //  004 - KSP b5

S_00[3]+= (int)USO_Booled[0][12]; //  003 - KSP b7
S_00[3]+= (int)USO_Booled[0][13]; //  002 - KSP b9
S_00[3]+= (int)USO_Booled[0][14]; //  001 - KSP b11
S_00[3]+= (int)USO_Booled[0][15]; //  000 - KSP b13

/* Слово 00 */
BinA[0]=XtoY(Trim(S_00[0]), StrToIntDef(2, 10), StrToIntDef(16, 10));
BinA[1]=XtoY(Trim(S_00[1]), StrToIntDef(2, 10), StrToIntDef(16, 10));
BinA[2]=XtoY(Trim(S_00[2]), StrToIntDef(2, 10), StrToIntDef(16, 10));
BinA[3]=XtoY(Trim(S_00[3]), StrToIntDef(2, 10), StrToIntDef(16, 10));

/* Слово 10 */
//Bin_USO_10[0]=XtoY(Trim(S_10[0]), StrToIntDef(2, 10), StrToIntDef(16, 10));  // ИРВИ - И1
//Bin_USO_10[1]=XtoY(Trim(S_10[1]), StrToIntDef(2, 10), StrToIntDef(16, 10));  // ИРВИ - И2
//Bin_USO_10[2]=XtoY(Trim(S_10[2]), StrToIntDef(2, 10), StrToIntDef(16, 10));  // ИРВИ - И3
//Bin_USO_10[3]=XtoY(Trim(S_10[3]), StrToIntDef(2, 10), StrToIntDef(16, 10));  // ИРВИ - И4

dOUT = "0x"+BinA[0]+BinA[1]+BinA[2]+BinA[3];                             // 00
//S_10_out = "0x"+Bin_USO_10[0]+Bin_USO_10[1]+Bin_USO_10[2]+Bin_USO_10[3]; // 10

STR_00 = StrToInt(dOUT);
//STR_10 = StrToInt(S_10_out);

USO_BT[0] = STR_00;
//USO_BT[16] = STR_10;
iResult = send(SPSSocket_ch1,(char *)&PacketHeaderType,9, 0  );       // Посылаем заголовок пакета
iResult = send(SPSSocket_ch1,(char *)&USO_BT,sizeof(USO_BT), 0  );    // Посылаем пакет
for (int i=0; i<3; i++)                                               // Clear S_
{
S_00[i]="0";
}
/*
*/
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N5Click(TObject *Sender)   // KSP Right
{
KSP_right->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::CentralLightBlinkTimer(TObject *Sender)  // Таймер промигивания ЦО
{
if(co_priz){
if(Cl_blink){
CO_light->Color=StringToColor("0x45607B");
Cl_blink=false;} else {
CO_light->Color=clRed;
Cl_blink=true;
}
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MainTimerTimer(TObject *Sender)
{
mass_tk_full = NU_temp.m_tk + dynamics.rasp;  // Расчет текущей массы ТК

Label15->Caption=tResult;   // Результатирующая переменная для проведения внутренних тестов Аргона (почеу она тут?)

Label13->Caption=(ob_cur-onboard_dt).FormatString("hh:nn:ss");

USO_Booled[10][7] = dpo_status_bit;
if(USO_Booled[12][7])YzS1[0]=1;
///////////////////
// Обработчик ТА //
///////////////////
if(cw_TA08[1]) JPS(3,is_sudn,is_operator,str_TA_08[1],""); else
if(cw_TA08[2]) JPS(3,is_sudn,is_operator,str_TA_08[2],""); else
if(cw_TA08[3]) JPS(3,is_sudn,is_operator,str_TA_08[3],""); else
if(cw_TA08[4]) JPS(3,is_sudn,is_operator,str_TA_08[4],""); else
if(cw_TA08[5]) JPS(3,is_sudn,is_operator,str_TA_08[5],""); else
if(cw_TA08[6]) JPS(3,is_sudn,is_operator,str_TA_08[6],""); else
if(cw_TA08[7]) JPS(3,is_sudn,is_operator,str_TA_08[7],""); else
if(cw_TA08[8]) JPS(3,is_sudn,is_operator,str_TA_08[8],""); else
if(cw_TA08[9]) JPS(3,is_sudn,is_operator,str_TA_08[9],""); else
if(cw_TA08[10]) JPS(3,is_sudn,is_operator,str_TA_08[10],""); else
if(cw_TA08[11]) JPS(3,is_sudn,is_operator,str_TA_08[11],""); else
if(cw_TA08[12]) JPS(3,is_sudn,is_operator,str_TA_08[12],""); else
if(cw_TA08[13]) JPS(3,is_sudn,is_operator,str_TA_08[13],""); else
if(cw_TA08[14]) JPS(3,is_sudn,is_operator,str_TA_08[14],""); else
if(cw_TA08[15]) JPS(3,is_sudn,is_operator,str_TA_08[15],"");

///////////////////
// Обработчик CА //
///////////////////
if(cw_SA[10]) JPS(3,is_sudn,is_operator,CA_EMER[10],""); else
if(cw_SA[11]) JPS(3,is_sudn,is_operator,CA_EMER[11],""); else
if(cw_SA[12]) JPS(3,is_sudn,is_operator,CA_EMER[12],""); else
if(cw_SA[13]) JPS(3,is_sudn,is_operator,CA_EMER[13],""); else
if(cw_SA[14]) JPS(3,is_sudn,is_operator,CA_EMER[14],""); else
if(cw_SA[15]) JPS(3,is_sudn,is_operator,CA_EMER[15],"");

tskd_time_label->Caption="ТСКД = "+data_TSKD.FormatString("hh:nn:ss.zzz");
Label42->Caption="Гибкое время t1: "+gc1_time.FormatString("hh:nn:ss.zzz");
if(testb->ItemIndex==0) GSO_types=0; else
if(testb->ItemIndex==1) GSO_types=1; else
if(testb->ItemIndex==2) GSO_types=2; else
if(testb->ItemIndex==3) GSO_types=3; else
if(testb->ItemIndex==4) GSO_types=4; else
if(testb->ItemIndex==5) GSO_types=5;

USO_work(); // Обработчик команд с КСП в УСО - Translate KSP cmd to USO bool flags

if(apm)     // if argon ready flag is true, then...
ArgonTakt->Enabled=true; else
ArgonTakt->Enabled=false;


}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ModelDateTime_TimerTimer(TObject *Sender)
{
OnboardModelTime=OnboardModelTime+StrToTime("00:00:01");
onboardTimeLabel->Caption=OnboardModelTime.FormatString("hh:nn:ss");
Label45->Caption="Время до ТСКД-:08: = "+gc1_time.FormatString("hh:nn:ss");
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N26Click(TObject *Sender)
{
BFI_Simvol_form->Show();
}
//---------------------------------------------------------------------------
// Т а к т   А р г о н а
void __fastcall TMainForm::ArgonTaktTimer(TObject *Sender)
{
if(USO_Booled[3][10]){   // Если есть признак питания чайки
if(!arg_work_pr){        // Если нет признака работы Аргона (состояние самопроверки) - перенести в отдельную функцию
// Проводим самопроверку - self_test.
// Если результат удвлетворительный, выставляем соответствующие признаки
// Добавить самопроверку по каналам АБВ (внутри self_test_)

   if(sp_d_k==1) {  // Если выбрана длинная самопроверка (1 минута - t), то...
      JPS(1,is_argon,is_operator,"Проведение длинной самопроверки...","");
      if(t==300) tResult = self_test_long(); else t++; } else

   if(sp_d_k==0) {  // Если выбрана короткая самопроверка (5 секунд), то...
      JPS(1,is_argon,is_operator,"Проведение короткой самопроверки...","");
     if(t==25) tResult = self_test_short(); else t++; }

//Label22->Caption=IntToStr(t); // Тактов самопроверки

// По окончанию теста считываем результат - если = 0, то тест прошел удачно и тогда
if(self_test_pr) {          // Если есть признак окончания теста
JPS(1,is_argon,is_operator,"Самопроверка окончена. Значение tResult = "+IntToStr(tResult),"");

        // РЕЗУЛЬТАТ 0
        if(tResult==0){                   // выставляем соответствующие признаки...
         USO_Booled[11][6]=true;}         // Выставляем признак БЦВК Готов на ТСЭ

        // РЕЗУЛЬТАТ 1
        else if(tResult==1){              // Если во время теста произошла ошибка (Result != 0), тогда
        JPS(3,is_argon,is_operator,"Самопроверка завершена с ошибкой. Значение tResult = "+IntToStr(tResult),"");
         arg_acc_handler(tResult);        // Вызываем обработчик ошибок Аргона
         ArgonTakt->Enabled=false;}       // Прекращаем работу БЦВК

       // ВЕРНЫЙ РЕЗУЛЬТАТ
        if(USO_Booled[11][6]){            // Если есть готовность БЦВК, то...
          arg_work_pr = true;             // Признак работы Аргона (по нему происходит запуск)
          USO_Booled[11][7]=true;         // Выставляем "ОСК" для ТСЭ (от кого?)
          test_test_tse=0;                // ?
        // Так же выставляем заявку на Программу Установки Начальных Условий (ПУНУ)
         }


         } //self_test_pr
} else {
// Р А Б О Т А   А Р Г О Н А //
//if(rygim==1){   // Если есть признак режима движения, то...
i_ot_pusk++; // Счетчик тактов БЦВК
// В СУД "Чайка-3" по началу каждого такта происходит самоконтроль (СК) - self_check

//---------//
// П У Н У //
// Программа Установки Начальных Условий //
//=======================================//
// Если есть заявка на ПУНУ, то...


// Блок Жесткой программы -


//
/*****************************************/
// Б Л О К   И Н Т Е Г Р И Р О В А Н И Я //
// П А Р А М Е Т Р О В   Д В И Ж Е Н И Я //
/*****************************************/
if(i_tok==5){
integer_n++;
dynamics.rs0 = dynamics.rs;
dynamics.sks0 = dynamics.sks;
dynamics.omy0 = dynamics.omy;
dynamics.omz0 = dynamics.omz;
///////////////////////////////
//                           //
// А. Обслуживание динамики  //
//                           ////////////////////////////////////////////
// Начинать расчет при введенных признаках - (описать список признаков //
/////////////////////////////////////////////////////////////////////////

////////////
// Аварии //
////////////
dynamics.Y2 = pow((2 * dynamics.ax1 * (dynamics.rs - 202)),0.5);

if(dynamics.sks > dynamics.Y2){
Panel1->Caption="ОПАСНО |V|>9 m/s";
Panel1->Font->Color=clRed;
} else {
Panel1->Caption="НЕТ";
Panel1->Font->Color=clYellow;
}

// Подпрограмма Контроля Расхода (КОРА)
// Контроль расхода на сближение осуществляется только на дальнем уч-ке сбл (признак?).
// Производим постоянное сравнивание распологаемого ресурса (R)
// и прогнозируемого Rп расходов топлива на ориентацию ЦМ в режиме СБ
// если R - Rп < 3,5 кг, то формируем ИН 05 "Нет ресурса для СБ" и вводим
// признак cw_a23[0]=1; "Запрет коррекции". При этом, если по КРЛ ввести новое
// значение уставки BR, то при превышении разности между распологаемым и прогнозируемым
// расходами величины 14 кг запрет коррекции снимается

if(dynamics.rasp < 20){
Panel1->Caption="ДОСТИГНУТ ГО !";
Panel1->Font->Color=clRed;
// Так же на ИРВИ
} else {
Panel1->Caption="НЕТ";
Panel1->Font->Color=clYellow;
}

if(dynamics.rs<1){
JPS(4,is_miu,is_operator,"Есть касание! Начало формирования протокола.","");
//rygim=0;

}

if(dynamics.rs<10&&dynamics.sks>1){
Panel1->Caption="Большая скорость n\на малой дальности!";
Panel1->Font->Color=clRed;
} else {
Panel1->Caption="НЕТ";
Panel1->Font->Color=clYellow;
}

if(dynamics.rs<0,00){
Panel1->Caption="Касание!";
Panel1->Font->Color=clLime;
} else {
Panel1->Caption="НЕТ";
Panel1->Font->Color=clYellow;}

///////////////////////////////////
// Расчет расхода топлива от РУД //
///////////////////////////////////
//                   Линейное ускорение             Боковое по Y                   Боковое по Z
dynamics.rudkg = ((dynamics.ax*0.046/0.01849)+(dynamics.ay*0.046/0.01915)+abs(dynamics.az*0.046/0.01897));

///////////////////////////////////////////
// Расчет расхода топлива от компенсации //
// вращения при боковом перемещении      //
///////////////////////////////////////////
dynamics.kvkg = -((0.209 * 0.046 * dynamics.ay / 0.0383 / 0.621) + (0.209 * 0.046 * dynamics.az / 0.03794 / 0.592));

/////////////////////////////////////////
// Общий расход топлива (на вычитание) //
/////////////////////////////////////////
//              ОБЩ.ТОПЛИВО               РУД              ВпБП            РУО               РУО               РУО
dynamics.rasp = dynamics.rasp - (dynamics.rudkg + dynamics.kvkg + dynamics.ruokgx + dynamics.ruokgy + dynamics.ruokgz);

////////////////////////////////////////////////////
// Алгоритмы расчета параметров движения с учетом //
// боковых скоростей для заданной траектории.     //
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=//
// Расчет радиальной дальности //  Версия  0.001  //
////////////////////////////////////////////////////
//                      (Дальность нулевая минус время умноженное на скорость нулевую) в квадрате плюс
dynamics.rs = pow((pow((dynamics.rs0 - ht * dynamics.sks0),2) +
pow((ht * dynamics.rs0 * 0.017453),2) *
(dynamics.omy0 * dynamics.omy0 + dynamics.omz0 * dynamics.omz0)),0.5);

////////////////////////////////////////////////////
// Расчет радиальной скорости  //  Версия  0.001  //
////////////////////////////////////////////////////
dynamics.sks = ht * (dynamics.axd + dynamics.axruo - dynamics.ax) + (dynamics.rs0 * dynamics.sks0 - ht *
(pow(dynamics.sks0,2) + (pow(dynamics.omy,2) + pow(dynamics.omz,2)) * pow((0.017453 * dynamics.rs0),2))) / dynamics.rs;

///////////////////////////////////////////////
// Расчет угловой скорости линии визирования //
// по горизонтали (ось OY) и по тангажу (OZ) //
///////////////////////////////////////////////
dynamics.omy = dynamics.omy0 * pow((dynamics.rs0 / dynamics.rs),2) + 57.3 * dynamics.az / dynamics.rs;
dynamics.omz = dynamics.omz0 * pow((dynamics.rs0 / dynamics.rs),2) + 57.3 * dynamics.ay / dynamics.rs;

dynamics.omyf = (dynamics.omy * cos(dynamics.uomx * 0.017454) + dynamics.omz * sin(dynamics.uomx * 0.017454));
dynamics.omzf = (dynamics.omz * cos(dynamics.uomx * 0.017454) - dynamics.omy * sin(dynamics.uomx * 0.017454));

dynamics.omzx = (dynamics.omz * cos(dynamics.Ex * 0.017454) + dynamics.omy * sin(dynamics.Ex * 0.017454));
dynamics.omyx = (dynamics.omy * cos(dynamics.Ex * 0.017454) - dynamics.omz * sin(dynamics.Ex * 0.017454));
////////////////////////////
// Дополнительные расчеты //
////////////////////////////
dynamics.V = pow(pow((pow(dynamics.sks, 2) + dynamics.vb),2),0.5);
dynamics.axd = abs(dynamics.ay * 0.157959) + abs(dynamics.az * 0.157924) + abs(dynamics.az * 0.157924) + abs(dynamics.az * 0.157924);

////////////////////
// Расчет промаха //
////////////////////
//                (Омега Z * Ро)*(Омега Z * Ро)  *   ???    /  Вектор скорости
dynamics.ypr = pow(dynamics.omz * dynamics.rs,2) * 0.017453 / dynamics.V;   //  Sy
dynamics.zpr = pow(dynamics.omy * dynamics.rs,2) * 0.017453 / dynamics.V;   //  Sz
dynamics.Spr = dynamics.rs * dynamics.vb / dynamics.V;                      //  S

//Линейный промах = dynamics.rs/sqrt(pow(dynamics.sks/,2)+1)

////////////////////////////
// Расчет времени пролета //
////////////////////////////

t_prolet[0] = abs(dynamics.rs * abs(dynamics.sks)/pow(dynamics.V,2));
t_prolet[1] = t_prolet[0]/86400;


//////////////////////////////
// Расчет боковых скоростей //
//////////////////////////////
dynamics.vby = dynamics.omz * dynamics.rs * 0.017453;
dynamics.vbz = dynamics.omy * dynamics.rs * 0.017453;

//////////////////  25 * 0.9 *
// Расчет углов //
//////////////////

dynamics.uomy = dynamics.uomy + (dynamics.omy + dynamics.Ey); // угол =  1 сек*омега у
dynamics.uomz = dynamics.uomz + (dynamics.omz + dynamics.Ez); // угол  от омеги z + вращение ТПК
dynamics.uomx = dynamics.uomx + dynamics.Ex;                             // угол  от  вращения ТПК

//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*

///////////////////////////////
// Вычисление относительной  //
//   дальности по прогнозу   //
///////////////////////////////

//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*

//////+///////////////////////////////+//////
//=//   Б Л О К   А Л Г О Р Т И М О В   //=//
//+//   А В Т О М А Т И Ч Е С К О Г О   //+//
//=//        У П Р А В Л Е Н И Я        //=//
//////+///////////////////////////////+//////

///////////////////////////////////////////
// Подпрограммы стабилизации и коррекции //
///////////////////////////////////////////
if(argon_auto_contr){
 if(dynamics.omz>0.001) dynamics.Ez = -0.62063 * 0.5; else dynamics.Ez = 0;
}


//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*//*
i_tok = 0;
} else i_tok=i_tok++; // Что бы интегрирование было с шагом в секунду
// Задача = сделать шаг интегрирования 0.100 мс
// а шаг отображения на форматах (не ИнПУ) так как удобно оператору

if(cw_b1[12]) USO_Booled[12][7]=1; else USO_Booled[12][7]=0;

 if(cw_b1[12]&&!USO_Booled[3][7]){
if(YzS1[0]&&YzS1[1]==0){ // Если есть заявка на "Присваивание"
 f_test++;
 Label46->Caption="Состояние заявки на присваивание: "+IntToStr(f_test);
 YzS1[1]=1;
}
}

/////////////////////////////  USO_Booled[1][16] КУРС1
//*************************//  USO_Booled[2][0]  КУРС2
//** РАБОТА С РТС "КУРС" **//
//*************************//
/////////////////////////////
// if(Время бортовое > Т1)
// if(заявка на программу КУРС) (в любом месте?)
// формируем признак cw_b6[6]=1; и выдаем команду на (USO_Booled[2][0]=true; КУРС2) включение невыбранного
// комплекта КУРС, а так же в систему КУРС выдаем команду "вращение"
// на БФИ "КУРС2" "ВРАЩЕН"

vill_test=1;
// Start integer if I9 and I11 = true
//i_takt++;


///////////////////////////////
// Обработчик ввода признака //
//    ИНДИКАТОРНЫЙ РЕЖИМ     //
///////////////////////////////
if(cw_b1[7]) { // If "IR" true
 // Вводим запрет на формирование управляющих импульсов на ДПО
 // Вводим запрет на формирование ГСО
 // Вводим запрет на контроль расхода топлива
 // Вводим запрет на контроль ориентации в ОСК
 // Вводим запрет на динамический контроль
}

/* Отладочные обработчики признаков */
if(cw_b6[13]) { // "Разрешение причаливания"
// Гасим "ЗАВ КОН" (почему?)
// Так же команда в БУМ
if(!WithoutBum->Checked&&!arg_half_false[1]){
JPS(4,"ОТЛАДОЧНОЕ: Прошла команда в СУБК \"Причаливание\", запуск процедуры...","","","");
SendToBum(0x0000029D, 1, 1);
arg_half_false[1]=true;}
}

if(USO_Booled[0][0]){  // Check Open SKD S001.1
if(pr_TSKD){ // Если Время.борт = ТСКД  S001
  JPS(4,"ОТЛАДОЧНОЕ: Прошла команда в СУБК \"Включение СКД\", запуск S001.1","","","");
  arg_du_on_skd();
  pr_TSKD = false;
} // S001
} // S001.1
} // else !arg_work_pr
} // SUDN Power
}
//-----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+--
//----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---
//---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+----

void __fastcall TMainForm::N27Click(TObject *Sender)
{
InstructorFormat_FRM->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button12Click(TObject *Sender)
{
cw_b6[11] = 1; // Docking integer flag
cw_b6[14] = 0; // Разрешение сближения по концу ГЦ
cw_b6[8] = 1;  // Разрешение сближения
GSO_types=2;
JPS(4,is_operator,is_miu,"ОТЛАДОЧНОЕ - КУРС - Причаливание","");

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ChekTSKDTimer(TObject *Sender)
{

if(OnboardModelTime.TimeString()==data_TSKD.TimeString()&&cw_b1[12]){     // Как лучше опрашивать? Перемена мест влияет?
 pr_TSKD=1;
 ChekTSKD->Enabled=false;
} else {
arg_test_pr++;
}
}
//---------------------------------------------------------------------------

double _SinSps (double Min, double Max, double TimeDiv){
double _SinO;
 _SinO  = (Max+Min)/2+(Max-Min)/2*sin(t/TimeDiv);
 return _SinO;
}


void __fastcall TMainForm::N28Click(TObject *Sender)
{
zakon_upr_frm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Button5Click(TObject *Sender)
{
argon_auto_contr = true;
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N29Click(TObject *Sender)
{
vkugraph->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N30Click(TObject *Sender)
{
iss_t_tp->Show();
}
//---------------------------------------------------------------------------




void __fastcall TMainForm::N32Click(TObject *Sender)
{
brus_frm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N33Click(TObject *Sender)
{
liftoff_form->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N20Click(TObject *Sender)
{
sm_ssvp_plx_frm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::SpsSendTimer(TObject *Sender)
{
if(inpu_com2_connect_pr){
CounterNo++;
PacketHeaderType.Signature = PacketSignatureR;
PacketHeaderType.No = CounterNo;
PacketHeaderType.Size = sizeof(SpsDataSt.TSpsParam);
PacketHeaderType.PacketID = PacketIDtype(idData);   // SPS Data
//int *p_dta = &SpsDataSt;
iResult = send(SPSSocket_ch1,(char *)&PacketHeaderType,9, 0  );
iResult = send(SPSSocket_ch1,(char *)&SpsDataSt,sizeof(SpsDataSt), 0  );
Label72->Caption="Пакетов СПС: "+IntToStr(CounterNo); }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button15Click(TObject *Sender)
{
SpsDataSt.TSpsParam[StrToInt(sps_num->Text)]=StrToInt(Edit1->Text);
TSpsDataN[StrToInt(sps_num->Text)]=StrToInt(Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button16Click(TObject *Sender)
{
if(inpu_com2_connect_pr){      // If InPU COM2 connect flag trute...
CounterNo++;                   // Add Pack Num
PacketHeaderType.Signature = PacketSignatureR;
PacketHeaderType.No = CounterNo;
PacketHeaderType.Size = sizeof(wpControlCodeTypeN);
PacketHeaderType.PacketID = PacketIDtype(idControl);   // Control Packet
packett.CodeType=wpControlCodeTypeN(wpIshod);
//packett.DataType=SoundType(sndEmergency);
iResult = send(SPSSocket_ch1,(char *)&PacketHeaderType,9, 0  );
iResult = send(SPSSocket_ch1,(char *)&packett,2, 0  );   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N161Click(TObject *Sender)
{
arg_deb->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N35Click(TObject *Sender)
{
bum_debug->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::p_sost_from_bumTimer(TObject *Sender)
{
SendToBum(0x00102101, 907, 0);       //Команда в БУМ ()
iResult = recv( TeleSocket,(char *)&PS_tk_iss,1025, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button1Click(TObject *Sender)
{
PS_tk_iss.fd_1=ntohl(0xcacacaca);
PS_tk_iss.fd_2=ntohl(0xb4b4b4b4);
PS_tk_iss.fd_3=ntohl(123);
PS_tk_iss.fd_4=ntohl(123);
PS_tk_iss.fd_5=ntohl(123);
PS_tk_iss.fd_6=ntohl(123);
PS_tk_iss.tk_type=ntohl(1);
PS_tk_iss.model_sec=ntohl(6578);
PS_tk_iss.milisec_ost=ntohl(987);
PS_tk_iss.vec_j2000_mks[0]=0x7feffffc57ca82ae;
PS_tk_iss.vec_j2000_mks[1]=0x7feffffc57ca82ae;
PS_tk_iss.vec_j2000_mks[2]=0x7feffffc57ca82ae;
PS_tk_iss.sun_vec[0]=0x7feffffc57ca82ae;
PS_tk_iss.sun_vec[1]=0x7feffffc57ca82ae;
PS_tk_iss.sun_vec[2]=0x7feffffc57ca82ae;
PS_tk_iss.vec_tk_TPK[0]=0xc57ca82ae;
PS_tk_iss.vec_tk_TPK[1]=0xc57ca82ae;
PS_tk_iss.vec_tk_TPK[2]=0xc57ca82ae;
PS_tk_iss.t_to_pt=123456789876;
PS_tk_iss.pr_t_pt=1;
PS_tk_iss.fara_pr=ntohl(3);
PS_tk_iss.tv_pr=ntohl(4);
PS_tk_iss.dpo_h[0]=0x7feffffc57ca82ae;
PS_tk_iss.tv_pr=ntohl(9);
PS_tk_iss.iss_tp_pr=3;
PS_tk_iss.CIFC_Wdis[0]=0xDADADADA;
PS_tk_iss.bsr_RUO[0]=0xAFAFAFAF;
PS_tk_iss.bsr_RUO[1]=0xBABABABA;
PS_tk_iss.bsr_RUO[2]=0xAFAFAFAF;
iResult = send( TeleSocket,(char *)&PS_tk_iss,1000, 0  );   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button10Click(TObject *Sender)
{
SendToBum(StrToInt(Edit5->Text),StrToInt(Edit6->Text),StrToInt(Edit7->Text));       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N37Click(TObject *Sender)
{
otkazy_frm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button2Click(TObject *Sender)
{
if(bum_pr){
SendToBum(0x00000301, 0, 0);       // Останов динамики - команда в БУМ (останов БММ)
dk_to_bum->Enabled=false;           // Разрешение отправки параметров ДК в БУМ
p_sost_from_bum->Enabled=false;}
start_priz = false;
PuskPr = false;
ModelDateTime_Timer->Enabled=false;
MainTimer->Enabled=false;
ArgonTakt->Enabled=false;
//Timer6->Enabled=false;
pusk_btn->Enabled=true;
arg_tst->Enabled=false;
JPS(1,is_operator,is_miu,"Стоп моделирования","");
StatusBar->Panels->Items[0]->Text="Процесс моделирования остановлен.";
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N38Click(TObject *Sender)
{
IrBrForm->Show();  // Форма ПРВИ
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::Button11Click(TObject *Sender)
{
dk_mass.dk_per[0]=StrToFloat(Edit11->Text);
dk_mass.dk_per[1]=StrToFloat(Edit10->Text);
dk_mass.dk_per[2]=StrToFloat(Edit9->Text);
dk_mass.dk_ori[0]=StrToFloat(Edit8->Text);
dk_mass.dk_ori[1]=StrToFloat(Edit4->Text);
dk_mass.dk_ori[2]=StrToFloat(Edit2->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::dk_to_bumTimer(TObject *Sender)
{
iResult = send( TeleSocket,(char *)&dk_mass,sizeof(dk_mass), 0);   //
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button13Click(TObject *Sender)
{
co_priz=0;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::unity_s_hTimer(TObject *Sender)
{
handle();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::un_servExecute(TIdPeerThread *AThread)
{
un_serv->Bindings->Items[0]->Recv(&unity_arr,sizeof(&unity_arr),0);
if(unity_arr.signature==0xD8A73F93)JPS(2,"Пакет удачно получен!","","","");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::un_servConnect(TIdPeerThread *AThread)
{
JPS(1,"Клиент Юнити подключен... Ожидаю квитанции инициализации клиента.","","","");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::un_servDisconnect(TIdPeerThread *AThread)
{
JPS(1,"Клиент Юнити отключён...","","","");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button14Click(TObject *Sender)
{
unity_arr.signature=0xD8A73F93;
un_serv->Bindings->Items[0]->Send((char *)&unity_arr,sizeof(&unity_arr),0);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button17Click(TObject *Sender)
{
double ver_vec_iss, ver_vel_iss, ver_vec_tk, ver_vel_tk;
double vz_d, vz_s;
double ver_v2tk[3], ver_v2iss[3], v3_o_iss, v3_o_tk ;
ver_vec_iss = sqrt(NU_temp.vec_j2000_mks[0]*NU_temp.vec_j2000_mks[0] +
NU_temp.vec_j2000_mks[1]*NU_temp.vec_j2000_mks[1] +
NU_temp.vec_j2000_mks[2]*NU_temp.vec_j2000_mks[2]);
JPS(1,"Результат нормировки вектора положения МКС: "+FloatToStr(ver_vec_iss),"","","");
ver_vel_iss = sqrt(pow(NU_temp.vel_j2000_mks[0],2) +
pow(NU_temp.vel_j2000_mks[1],2) +
pow(NU_temp.vel_j2000_mks[2],2));
JPS(1,"Результат нормировки вектора скорости МКС: "+FloatToStr(ver_vel_iss),"","","");
ver_vec_tk = sqrt(NU_temp.vec_j2000_tk[0]*NU_temp.vec_j2000_tk[0] +
NU_temp.vec_j2000_tk[1]*NU_temp.vec_j2000_tk[1] +
NU_temp.vec_j2000_tk[2]*NU_temp.vec_j2000_tk[2]);
JPS(1,"Результат нормировки вектора положения ТК: "+FloatToStr(ver_vec_tk),"","","");
ver_vel_tk = sqrt(NU_temp.vel_j2000_tk[0]*NU_temp.vel_j2000_tk[0] +
NU_temp.vel_j2000_tk[1]*NU_temp.vel_j2000_tk[1] +
NU_temp.vel_j2000_tk[2]*NU_temp.vel_j2000_tk[2]);
JPS(1,"Результат нормировки вектора скорости ТК: "+FloatToStr(ver_vel_tk),"","","");
vz_d = ver_vec_iss - ver_vec_tk;
JPS(1,"Расстояние: "+FloatToStr(vz_d)," м","","");
vz_s = ver_vel_iss - ver_vel_tk;
JPS(1,"Скорость взаимная: "+FloatToStr(vz_s)," м/с","","");
ver_v2iss[0]=NU_temp.vec_j2000_mks[0]*NU_temp.vel_j2000_mks[0];
ver_v2iss[1]=NU_temp.vec_j2000_mks[1]*NU_temp.vel_j2000_mks[1];
ver_v2iss[2]=NU_temp.vec_j2000_mks[2]*NU_temp.vel_j2000_mks[2];
ver_v2tk[0]=NU_temp.vec_j2000_tk[0]*NU_temp.vel_j2000_tk[0];
ver_v2tk[1]=NU_temp.vec_j2000_tk[1]*NU_temp.vel_j2000_tk[1];
ver_v2tk[2]=NU_temp.vec_j2000_tk[2]*NU_temp.vel_j2000_tk[2];
v3_o_iss=sqrt(ver_v2iss[0]*ver_v2iss[0]+ver_v2iss[1]*ver_v2iss[1]+ver_v2iss[2]*ver_v2iss[2]);
JPS(1,"Результат нормировки вектора П: "+FloatToStr(v3_o_iss),"","","");
if((ver_vec_iss<1000)||(ver_vel_iss<1000)||(ver_vec_tk<1000)||(ver_vel_tk<1000))
JPS(3,"Верификация параметра НУ не пройдена!","","",""); else
JPS(2,"Верификация параметра НУ пройдена!","","","");
}
//---------------------------------------------------------------------------



TPacketHeader PH;

void __fastcall TMainForm::InpuRecvTimer(TObject *Sender)
{
if(inpu_com2_connect_pr){
nResult = recv(SPSSocket_ch1,(char *)&PH,12, 0);
if(PH.Signature==0x71AF5D13){
 if(PH.PacketID==8)
 if(PH.PacketID==3) JPS(1,is_inpu1,is_miu,"Получен статусный пакет ","");
 if(PH.PacketID==4) { JPS(1,is_inpu1,is_miu,"Получен контрольный пакет "+IntToStr(PH.CodeType),"");

        if(PH.CodeType==9){JPS(1,is_operator,is_inpu1,"Команда КСП     "+IntToStr(PH.DataType1)," "+IntToStr(PH.DataType2));
        KSP_Booled[PH.DataType1][PH.DataType2-1]=true;}
        if(PH.CodeType==10){JPS(1,is_operator,is_inpu1,"Нажата клавиша ПРВИ "+IntToStr(PH.DataType1)," "+IntToStr(PH.DataType2));
        }
        if(PH.CodeType==10){JPS(1,is_operator,is_inpu1,"Сообщение о телеметрии"+IntToStr(PH.DataType1)," "+IntToStr(PH.DataType2));
        }

 }
}}
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N110Click(TObject *Sender)
{
inpu_1->Show();      // Загрузка ИнПУ-1
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::debug_statusClick(TObject *Sender)
{
/**************************/
/* РАБОТА С СТАТУСОМ БУМа */
/**************************/
bool message_status[2];           // Message BUM Status booled - recode for good work!
if(!debug_status->Checked) {
if(message_status[1]==0){
JPS(3,is_operator,is_miu,"ВНИМАНИЕ!!! Режим отладки снят!","");
message_status[1]=1;}
message_status[0] = 0;
debug_panel->Visible=false;    // Скрываем отладочную панель
WithoutBum->Visible=false;
model_status_pics->Width=241;
} 
if(debug_status->Checked){     // Если введен признак отладки
debug_panel->Visible=true;
if(message_status[0]==0){
message_status[1] = 0;
JPS(3,is_operator,is_miu,"ВНИМАНИЕ!!! Введен режим отладки!","");
message_status[0]=1;}
model_status_pics->Width=177;  // Меняем размер окна состояния моделей
}
 // Меняем размер окна состояния моделей
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N40Click(TObject *Sender)
{
sps_form->Show(); // SPS Form 
}
//---------------------------------------------------------------------------
int blabla;

void __fastcall TMainForm::bum_statusTimer(TObject *Sender)
{
//if(bilu_work_pr==true){
//Label8->Caption="Введен "+IntToStr(blabla);
//blabla++;}else
//Label8->Caption="Не Введен "+IntToStr(blabla);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::biluClick(TObject *Sender)
{
bilu_frm->Show();
}
//---------------------------------------------------------------------------


