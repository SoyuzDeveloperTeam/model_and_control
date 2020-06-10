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
        TGroupBox *model_status_pics;
        TImageList *ModelStatusPicList;
        TLabel *bum_st_label;
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
        TMenuItem *N22;
        TLabel *Label10;
        TImage *SpsStatusPic;
        TMenuItem *N4;
        TMenuItem *N23;
        TMenuItem *N24;
        TImage *bum_status_pic;
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
        TMenuItem *N35;
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
        TButton *Button15;
        TMenuItem *N36;
        TMenuItem *N37;
        TButton *Button2;
        TGroupBox *GroupBox9;
        TEdit *Edit5;
        TLabel *Label7;
        TEdit *Edit6;
        TEdit *Edit7;
        TButton *Button10;
        TLabel *Label9;
        TLabel *Label14;
        TButton *Button3;
        TLabel *Label12;
        TLabel *Label13;
        TMenuItem *N38;
        TSpeedButton *SpeedButton1;
        TButton *Button7;
        TButton *Button1;
        TEdit *Edit2;
        TEdit *Edit4;
        TEdit *Edit8;
        TEdit *Edit9;
        TEdit *Edit10;
        TEdit *Edit11;
        TButton *Button11;
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
        TCheckBox *WithoutBum;
        TButton *Button6;
        TCheckBox *with_unity;
        TTimer *bum_status;
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
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall LocalTimeTimerTimer(TObject *Sender);
        void __fastcall kspl_loadClick(TObject *Sender);
        void __fastcall init_Click(TObject *Sender);
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
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall N161Click(TObject *Sender);
        void __fastcall N35Click(TObject *Sender);
        void __fastcall p_sost_from_bumTimer(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall N37Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall N38Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall dk_to_bumTimer(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall unity_s_hTimer(TObject *Sender);
        void __fastcall un_servExecute(TIdPeerThread *AThread);
        void __fastcall un_servConnect(TIdPeerThread *AThread);
        void __fastcall un_servDisconnect(TIdPeerThread *AThread);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall InpuRecvTimer(TObject *Sender);
        void __fastcall N110Click(TObject *Sender);
        void __fastcall debug_statusClick(TObject *Sender);
        void __fastcall N40Click(TObject *Sender);
        void __fastcall bum_statusTimer(TObject *Sender);
        void __fastcall biluClick(TObject *Sender);
        void __fastcall ssvpClick(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall ArgonTaktTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
