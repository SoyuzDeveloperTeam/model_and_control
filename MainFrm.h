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
        TGroupBox *GroupBox1;
        TImageList *ModelStatusPicList;
        TLabel *Label1;
        TImage *inpu_status_pic;
        TLabel *Label2;
        TLabel *Label3;
        TImage *argon_status_pic;
        TTimer *Timer3;
        TGroupBox *GroupBox4;
        TSpeedButton *SpeedButton1;
        TMenuItem *LAPTOP1;
        TMenuItem *N17;
        TMenuItem *N18;
        TMenuItem *N19;
        TMenuItem *N20;
        TMenuItem *N21;
        TTimer *LocalTimeTimer;
        TSpeedButton *SpeedButton2;
        TGroupBox *GroupBox5;
        TTimer *SocketTeleConnect;
        TGroupBox *GroupBox6;
        TLabel *LocalTime;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *onboardTimeLabel;
        TMenuItem *N22;
        TLabel *Label10;
        TImage *SpsStatusPic;
        TButton *Button7;
        TMenuItem *N4;
        TLabel *Label14;
        TMenuItem *N23;
        TMenuItem *N24;
        TIdDateTimeStamp *IdDateTimeStamp1;
        TImage *bum_status_pic;
        TTimer *PuskRgPr;
        TMenuItem *N25;
        TTimer *inpu_com2_connect;
        TLabel *Label18;
        TMemo *Memo1;
        TTimer *Timer4;
        TPanel *CO_light;
        TTimer *CentralLightBlink;
        TTimer *MainTimer;
        TTimer *arg_tst;
        TIdUDPClient *kl;
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
        TLabel *Label8;
        TLabel *Label46;
        TLabel *Label20;
        TLabel *Label4;
        TMenuItem *N29;
        TMenuItem *N30;
        TLabel *Label21;
        TTimer *DebugTimer;
        TLabel *Label22;
        TGroupBox *GroupBox10;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TMenuItem *N31;
        TMenuItem *N32;
        TMenuItem *N33;
        TTimer *SpsSend;
        TButton *Button16;
        TEdit *Edit2;
        TLabel *Label75;
        TButton *Button17;
        TLabel *Label76;
        TLabel *Label77;
        TEdit *Edit3;
        TMenuItem *N34;
        TMenuItem *N161;
        TMenuItem *N35;
        TTimer *dk_to_bum;
        TButton *Button1;
        TTimer *Timer6;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label15;
        TButton *Button10;
        TEdit *Edit5;
        TEdit *Edit6;
        TEdit *Edit7;
        TGroupBox *GroupBox3;
        TCheckBox *sps_model;
        TButton *init_;
        TCheckBox *WithoutBum;
        TButton *Button6;
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
        TButton *Button15;
        TMenuItem *N36;
        TMenuItem *N37;
        TButton *Button2;
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
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall LocalTimeTimerTimer(TObject *Sender);
        void __fastcall kspl_loadClick(TObject *Sender);
        void __fastcall init_Click(TObject *Sender);
        void __fastcall SPSClientConnected(TObject *Sender);
        void __fastcall SPSClientDisconnected(TObject *Sender);
        void __fastcall N22Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall N24Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall PuskRgPrTimer(TObject *Sender);
        void __fastcall N25Click(TObject *Sender);
        void __fastcall inpu_com2_connectTimer(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall arg_tstTimer(TObject *Sender);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall Timer4Timer(TObject *Sender);
        void __fastcall CentralLightBlinkTimer(TObject *Sender);
        void __fastcall MainTimerTimer(TObject *Sender);
        void __fastcall ModelDateTime_TimerTimer(TObject *Sender);
        void __fastcall N26Click(TObject *Sender);
        void __fastcall ArgonTaktTimer(TObject *Sender);
        void __fastcall N27Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall ChekTSKDTimer(TObject *Sender);
        void __fastcall N28Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall N29Click(TObject *Sender);
        void __fastcall N30Click(TObject *Sender);
        void __fastcall DebugTimerTimer(TObject *Sender);
        void __fastcall N32Click(TObject *Sender);
        void __fastcall N33Click(TObject *Sender);
        void __fastcall N20Click(TObject *Sender);
        void __fastcall SpsSendTimer(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall N161Click(TObject *Sender);
        void __fastcall N35Click(TObject *Sender);
        void __fastcall dk_to_bumTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall N37Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
