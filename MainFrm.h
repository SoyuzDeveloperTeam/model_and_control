//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <ExtCtrls.hpp>
#include <ScktComp.hpp>
#include <Sockets.hpp>
#include <Menus.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include <ComCtrls.hpp>
#include <Graphics.hpp>
#include <ImgList.hpp>
#include <Buttons.hpp>
#include <IdTCPServer.hpp>
#include <IdDateTimeStamp.hpp>
//-----------------------------------------------------------------------------
/* Заголовки */
#include "MD_math_header.h"
#include "main_header.h"                // Основной заголовок - main Header
#include "JouHeader.h"                  // Заголовок для журнала - Header for Journal
#include "arg_jou.h"                    // Журнал Аргона - argon journal
#include "dta.cpp"                      // Данные для обмена с БУМ - BUM data
#include "md_m.h"                       // Модельные переменные - Model data
#include "ts_header.h"                  // Переменные ТС - TC data
#include "ICN_header.h"                 // Данные для обмена с ИнПУ - data ffor connect with InPU
#include "JouStrings.h"                 // Строковые переменные для журнала - String's for JPS loging funtion
#include "SPSHead.h"                    // Данные СПС ч.1 - SPS Data Part 1
#include "USOData.h"                    // Параметры УСО - USO Data
#include "uso_model.cpp"                // Модель УСО - USO Model
#include "inpu_connect.cpp"             // Обмен с моделью ИнПУ - For connect with InPU
#include "main_math.cpp"                // Математические модели - Math Models
#include "argon/arg_header.h"           // Загогловок А16 - argon header #2 (?)
#include "argon/CtrlWord.h"             // Управляющие слова Аргона - Control words (flags) for argon
#include "argon/arg_kdu_operations.cpp" // Argon-16 программы КДУ
#include "sotr_data.h"                  // Модель СОТР
#include "DateUtils.hpp"
#include "fly_model.cpp"                // Модель движения
#include "ssvp_module.h"                // Признаки ССВП
#include "argon/arg_pks.cpp"            // Программы Аргона - Argon Programs
#include "neptun_main.cpp"              // Основные процедуры ПСА "Нептун-МЭ" - Main proc for Neptune model
#include "unity_connect.cpp"            // Обмен с Юнити - Connect with Unity
#include "inpuconnect.cpp"              // Обмен с ИнПУ  - Connect with InPU
#include "md_main.cpp"                  // Motion Model
#include "DConvert.cpp"                 // CW Convert Bool[16] to Oct
#include "miscdata/rdc_draph.cpp"       // Функции графиков определения расстояния до цели
#include "fly_model.cpp"
//---------------------------------------------------------------------------
/* Формы */
//#include "help_form.cpp"              // Форма Поддержи - Help Form
#include "bilu_format.cpp"              // Форма БИЛУ - BILU form
#include "vived_frm.cpp"                // Форма Выведение (график) - "LiftOff" chart
#include "brus_form.cpp"                // Форма БРУС - BRUS form
#include "ts_frm.cpp"                   // Форма ТС - TS Form
#include "bfi_formats.cpp"              // Форма "БФИ Символ" для А16 - BFI Data monitor ith VKU form
#include "bum_sett_frm.cpp"             // Форма вывода данных БУМ  - Data from BUM form
#include "toru_frm.cpp"                 // Форма пульта ПУ БПС ТОРУ - TORU Pult form
#include "EnterNuFrm.cpp"               // Форма ввода начальных условий (НУ)
#include "kdu_data.cpp"                 // Форма параметров КДУ
#include "clock_form.cpp"               // Форма БЧК-744К Бортовые Часы на РС МКС
#include "JouLogFrm.h"                  // Форма основного журнала
#include "ssvp_form.cpp"                // Форма ССВП - Процессуальная
#include "zakon_upr.cpp"                // Форма Закон Управления
#include "KSPLForm.cpp"                 // Форма КСП левое
#include "KSPPForm.cpp"                 // Форма КСП правое
#include "USOFrm.cpp"                   // Форма УСО
#include "krl_form.cpp"                 // Форма КРЛ
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
#include "inpudebugf.cpp"               // Форма отладки обмена с ИнПУ
#include "otkazy.cpp"                   // Форма "Отказ Бортоввых Систем"
#include "neptun.cpp"                   // Форма ПСА "Нептун-МЭ" -  ИнПУ1
#include "sps_frm.cpp"                  // Форма СПС
#include "CWFrm.cpp"                    // Форма Contrl Word (debug)
// Форматы Laptop РС МКС (СМ)
#include "sm_ssvp_PX.cpp"               // Формат СМ:ССВП:+Х
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox2;
        TButton *pusk_btn;
        TButton *Button4;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *kspl_load;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N10;
        TMenuItem *N11;
        TMenuItem *N12;
        TMenuItem *N13;
        TMenuItem *N14;
        TTimer *ArgonTakt;
        TButton *Button9;
        TMenuItem *N15;
        TTimer *Timer2;
        TMenuItem *N16;
        TStatusBar *StatusBar;
        TGroupBox *model_status_pics;
        TImageList *ModelStatusPicList;
        TImage *inpu_status_pic;
        TLabel *Label2;
        TLabel *Label3;
        TImage *argon_status_pic;
        TMenuItem *LAPTOP1;
        TMenuItem *N17;
        TMenuItem *N18;
        TMenuItem *N19;
        TMenuItem *N20;
        TMenuItem *N21;
        TTimer *LocalTimeTimer;
        TGroupBox *debug_panel;
        TGroupBox *GroupBox6;
        TLabel *LocalTime;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *onboardTimeLabel;
        TLabel *Label10;
        TImage *SpsStatusPic;
        TMenuItem *N4;
        TMenuItem *N23;
        TMenuItem *N24;
        TTimer *PuskRgPr;
        TMenuItem *N25;
        TTimer *inpu_com2_connect;
        TPanel *CO_light;
        TTimer *CentralLightBlink;
        TTimer *MainTimer;
        TTimer *arg_tst;
        TComboBox *hhm;
        TTimer *ModelDateTime_Timer;
        TMenuItem *N26;
        TMenuItem *N27;
        TComboBox *testb;
        TLabel *tskd_time_label;
        TLabel *Label42;
        TButton *Button12;
        TTimer *ChekTSKD;
        TTimer *villt;
        TLabel *Label45;
        TMenuItem *N28;
        TPanel *Panel1;
        TLabel *Label46;
        TLabel *Label20;
        TLabel *Label4;
        TMenuItem *N29;
        TMenuItem *N30;
        TGroupBox *GroupBox10;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TMenuItem *N31;
        TMenuItem *N32;
        TMenuItem *N33;
        TTimer *SpsSend;
        TButton *Button16;
        TEdit *Edit3;
        TMenuItem *N34;
        TMenuItem *N161;
        TTimer *p_sost_from_bum;
        TGroupBox *GroupBox7;
        TButton *Button8;
        TButton *Button5;
        TCheckBox *CheckBox1;
        TGroupBox *GroupBox8;
        TLabel *Label72;
        TLabel *Label73;
        TEdit *sps_num;
        TLabel *Label74;
        TEdit *Edit1;
        TButton *sps_rec_btn;
        TMenuItem *N36;
        TMenuItem *N37;
        TButton *Button2;
        TButton *Button3;
        TLabel *Label12;
        TLabel *Label13;
        TMenuItem *tk_prvi_btn;
        TSpeedButton *SpeedButton1;
        TButton *Button7;
        TButton *Button1;
        TTimer *dk_to_bum;
        TButton *Button13;
        TTimer *unity_s_h;
        TIdTCPServer *un_serv;
        TButton *Button14;
        TButton *Button17;
        TTimer *InpuRecv;
        TMenuItem *N39;
        TMenuItem *N110;
        TCheckBox *debug_status;
        TGroupBox *GroupBox3;
        TCheckBox *sps_model;
        TButton *init_;
        TButton *close_socket;
        TCheckBox *with_unity;
        TMenuItem *N40;
        TLabel *Label1;
        TLabel *Label8;
        TLabel *Label11;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TMenuItem *bilu;
        TMenuItem *ssvp;
        TPopupMenu *PopupMenu1;
        TMenuItem *N41;
        TMenuItem *N42;
        TMenuItem *N43;
        TCheckBox *md_status;
        TMenuItem *N44;
        TButton *set_lang;
        TButton *co_test_btn;
        TLabel *Label18;
        TLabel *arg_ch;
        TTimer *DebugTimer;
        TLabel *Label19;
        TLabel *debug_int_a;
        TLabel *debug_int_b;
        TLabel *debug_int_c;
        TTrackBar *TrackBar1;
        TLabel *Label21;
        TMenuItem *N38;
        void __fastcall pusk_btnClick(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N14Click(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall N15Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall N16Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall TclConnected(TObject *Sender);
        void __fastcall N21Click(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall close_socketClick(TObject *Sender);
        void __fastcall LocalTimeTimerTimer(TObject *Sender);
        void __fastcall kspl_loadClick(TObject *Sender);
        void __fastcall init_Click(TObject *Sender);
        void __fastcall SPSClientDisconnected(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N24Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall PuskRgPrTimer(TObject *Sender);
        void __fastcall N25Click(TObject *Sender);
        void __fastcall inpu_com2_connectTimer(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall arg_tstTimer(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall CentralLightBlinkTimer(TObject *Sender);
        void __fastcall MainTimerTimer(TObject *Sender);
        void __fastcall ModelDateTime_TimerTimer(TObject *Sender);
        void __fastcall N26Click(TObject *Sender);
        void __fastcall N27Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall ChekTSKDTimer(TObject *Sender);
        void __fastcall N28Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall N29Click(TObject *Sender);
        void __fastcall N30Click(TObject *Sender);
        void __fastcall N32Click(TObject *Sender);
        void __fastcall N33Click(TObject *Sender);
        void __fastcall N20Click(TObject *Sender);
        void __fastcall SpsSendTimer(TObject *Sender);
        void __fastcall sps_rec_btnClick(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall N161Click(TObject *Sender);
        void __fastcall ArgonTaktTimer(TObject *Sender);
        void __fastcall debug_statusClick(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall tk_prvi_btnClick(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall co_test_btnClick(TObject *Sender);
        void __fastcall DebugTimerTimer(TObject *Sender);
        void __fastcall ssvpClick(TObject *Sender);
        void __fastcall N110Click(TObject *Sender);
        void __fastcall N38Click(TObject *Sender);
        //void __fastcall N38Click(TObject *Sender);
        //void __fastcall Button11Click(TObject *Sender);
        //void __fastcall dk_to_bumTimer(TObject *Sender);
        //void __fastcall Button13Click(TObject *Sender);
        //void __fastcall unity_s_hTimer(TObject *Sender);
        //void __fastcall un_servExecute(TIdPeerThread *AThread);
        //void __fastcall un_servConnect(TIdPeerThread *AThread);
        //void __fastcall un_servDisconnect(TIdPeerThread *AThread);
        //void __fastcall Button14Click(TObject *Sender);
        //void __fastcall Button17Click(TObject *Sender);
        //void __fastcall InpuRecvTimer(TObject *Sender);
        //void __fastcall N110Click(TObject *Sender);
        //void __fastcall debug_statusClick(TObject *Sender);
        //void __fastcall N40Click(TObject *Sender);
        //void __fastcall bum_statusTimer(TObject *Sender);
        //void __fastcall biluClick(TObject *Sender);
        //void __fastcall ssvpClick(TObject *Sender);
        //void __fastcall SpeedButton1Click(TObject *Sender);
        //void __fastcall ArgonTaktTimer(TObject *Sender);
        //void __fastcall N44Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
