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
//---------------------------------------------------------------------------
#pragma hdrstop
#include <vcl.h>
#include "MainFrm.h"
#include <vector.h>
#include <math.h>
#include <Tlhelp32.h>
#include <windows.h>
#include <mmsystem.h>
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
static TDateTime SFD_sec;
static double ghjh;

static WSADATA wsaData;                // Структура Win Socket
static AnsiString WsaIpAddr;    // IP адрес из конфигурации

static TIniFile *MiuConf;       // Файл конфигурации
static AnsiString ConfFileName;

static AnsiString inpu_con_data[8];
static int iResult;                    // Результатирующая переменная


// -- -- -- --

HINSTANCE Lib = LoadLibrary("LIB_BNO.dll");                    // загружаем библиотеку динамически


TInit Init = 0;                                                // Make object's
TGetMagData GetMagData = 0;
TGetGravTorqueData GetGravTorqueData = 0;
//---------------------------------------------------------------------------

static int qss;
static int disp[3];
static vector <int> STBv(3);

static int image_index;

static struct {
int a;
int b;
int c;
}sends;
static int intVariable;
static bool startdelay;
static bool iniread;

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
PuskPr = true;                     // Вводим признак "Пуск динамики"
ModelDateTime_Timer->Enabled=true; // Запускаем таймер модельного времени
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

void Config_init (AnsiString iniName) {  // Процедура инициализации файла конфигурации
ConfFileName = "C:\1231231\Out\miu_config.ini";  // Создаем имя файла конфигурации
MiuConf = new TIniFile(iniName);                                   // Присваиваем
if(FileExists(iniName))                                            // Если такой файл существует, то...
{
JPS(1,"Чтение файла конфигурации...","","","");                         // Логируем о начале процесса чтения файла
WsaIpAddr = MiuConf->ReadString("WSA","main_ip","0.0.0.0");             // Основной айпишник
inpu_con_data[0] = WsaIpAddr;
inpu_con_data[1] = MiuConf->ReadString("INPU","inpu1_port_com1","0000");
inpu_con_data[2] = MiuConf->ReadString("INPU","inpu1_port_com2","0000");
} else JPS(3,"Отсутствует файл конфигурации!","","","");
}

void __fastcall TMainForm::N12Click(TObject *Sender)
{
AboutForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::close_socketClick(TObject *Sender)
{
        init_->Enabled=true;
        if(with_unity->Checked){  // Если введен признак "With Unity"
        unity_s_h->Enabled=false;
                               }  // with_unity
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

if(md_status->Checked) { // Если выбрана работа с МД
fly_model_pr = 1; // Разрешаем работу всех процедур МД
JPS(1,"","","Начало инициализации модели движения...","");
#define FLY_LINK_CORE {\
#pragma message ("    Подключение библиотеки FlyCore...")\
#pragma comment(lib, "FlyCore.lib")\
}
init_md();
// Инициализация МД

} // md_status
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

StatusBar->Panels->Items[2]->Text="И  П";   // Текущее состояние МиУ И - Инициализация, П - протокол

//---------//
// 1.1.3. Подготовка структуры связи сокета с сервером

// inet_addr((unsigned char)MiuConf->ReadString("WSA","main_ip","0.0.0.0"))
// "вынимаем" из файла конфигурации актуальные данные
AnsiString fdsfd = MiuConf->ReadString("WSA","main_ip","0.0.0.0");
char * ipaddress = fdsfd.c_str(); // Актуальный IP адрес

                 // То же + делать проверку на соответствие в конфиге БУМа

//---------//
// 1.1.4. Попытка подключения к серверу

 init=true;
 con=true;

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

rdc_init(); // Инициализация данных для графиков определения расстояния до цели
graphics->Series13->AddXY(rdc_sm_dsm[0],0.5,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[1],1,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[2],1.5,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[3],2,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[4],2.5,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[5],3,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[6],3.5,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[7],4,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[8],4.5,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[9],5,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[10],5.5,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[11],6,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[12],6.5,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[13],7,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[14],7.5,"",clBlack);
graphics->Series13->AddXY(rdc_sm_dsm[15],8,"",clBlack);

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
close_socket->Enabled=true;
 JPS(1,"","","Автономный вариант без моделей","");
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


//---------------------------------------------------------------------------

void __fastcall TMainForm::N4Click(TObject *Sender)
{
UsoForm->Show();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
ver_num=" 1.0.1.56";              // Переделать - выводить версию из атрибутов
// --- Выставляем начальное состояние иконок моделей --- //
ModelStatusPicList->GetBitmap(0, inpu_status_pic->Picture->Bitmap);
ModelStatusPicList->GetBitmap(0, argon_status_pic->Picture->Bitmap);
ModelStatusPicList->GetBitmap(0, SpsStatusPic->Picture->Bitmap);
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
  /* kgpt(StrToFloat(EnterNuForm->ang_psi_tk->Text),  // Формируем    !!! sqrt: DOMAIN error !!!
       StrToFloat(EnterNuForm->ang_thetta_tk->Text),
       StrToFloat(EnterNuForm->ang_gamma_tk->Text),
       &q_tk[0],&q_tk[2],&q_tk[3],&q_tk[4]);
  norm_q(q_tk,q_tkn);   // Нормируем   */
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

// -- НУ для остальных систем/моделей --  ONLY FOR DEBUG !!!
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

}

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
PlaySound("Data\\Sound\\nept_co.wav", NULL, SND_ASYNC);   // Звук ЦО
}
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MainTimerTimer(TObject *Sender)
{
mass_tk_full = NU_temp.m_tk + dynamics.rasp;  // Расчет текущей массы ТК

Label15->Caption=tResult;   // Результатирующая переменная для проведения внутренних тестов Аргона (почеу она тут?)


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
// Т а к т   А р г о н а//-----+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+--
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
// Debug timer 
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

void __fastcall TMainForm::sps_rec_btnClick(TObject *Sender)
{
SpsDataSt.TSpsParam[StrToInt(sps_num->Text)]=StrToInt(Edit1->Text);   // Для Нептуна
TSpsDataN[StrToInt(sps_num->Text)]=StrToInt(Edit1->Text);             // Для МиУ
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

//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TMainForm::ArgonTaktTimer(TObject *Sender)
{
  argon_takt();//StartArgon
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::debug_statusClick(TObject *Sender)
{
bool message_status[2];           // Message Status booled - recode for good work!
if(!debug_status->Checked) {
if(message_status[1]==0){
JPS(3,is_operator,is_miu,"ВНИМАНИЕ!!! Режим отладки снят!","");
message_status[1]=1;}
message_status[0] = 0;
debug_panel->Visible=false;    // Скрываем отладочную панель
model_status_pics->Width=177;
} 
if(debug_status->Checked){     // Если введен признак отладки
debug_panel->Visible=true;
if(message_status[0]==0){
message_status[1] = 0;
JPS(3,is_operator,is_miu,"ВНИМАНИЕ!!! Введен режим отладки!","");
message_status[0]=1;}
model_status_pics->Width=241;  // Меняем размер окна состояния моделей;
}
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpeedButton1Click(TObject *Sender)
{
krl_frm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::tk_prvi_btnClick(TObject *Sender)
{
IrBrForm->Show(); // Load format IRVI
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button13Click(TObject *Sender)
{
co_priz=0;
CO_light->Color=StringToColor("0x45607B");
Cl_blink=false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::co_test_btnClick(TObject *Sender)
{
double ret_r;
ret_r = ikv_TwoAlpha(300);
Label21->Caption=FormatFloat("",ret_r);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DebugTimerTimer(TObject *Sender)
{
AnsiString l;
if(USO_Booled[3][2]) l="A - -"; else
if(USO_Booled[3][3]) l="- Б -"; else
if(USO_Booled[3][4]) l="- - В"; else
if(USO_Booled[3][13])l="A Б В"; else l="- - -";
arg_ch->Caption=l;
debug_int_a->Caption=BoolToStr(KSP_Booled[5][10],false);
debug_int_b->Caption=BoolToStr(KSP_Booled[5][12],false);
debug_int_c->Caption=BoolToStr(KSP_Booled[5][14],false);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ssvpClick(TObject *Sender)
{
ssvp_frm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N110Click(TObject *Sender)
{
inpu_1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N38Click(TObject *Sender)
{
NeptDebug->Show();
}
//---------------------------------------------------------------------------

