//---------------------------------------------------------------------------

#ifndef inpudebugfH
#define inpudebugfH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TNeptDebug : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *PacketNo_write;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label24;
        TLabel *Label25;
        TLabel *Label26;
        TLabel *Label27;
        TLabel *Label28;
        TLabel *Label29;
        TLabel *Label30;
        TLabel *Label31;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *PacketNo_send;
        TLabel *Label35;
        TLabel *Label36;
        TLabel *Label37;
        TLabel *Label38;
        TLabel *Label39;
        TLabel *Label40;
        TLabel *Label41;
        TLabel *Label42;
        TLabel *Label43;
        TLabel *Label44;
        TLabel *Label45;
        TLabel *Label46;
        TLabel *Label47;
        TLabel *Label48;
        TLabel *Label49;
        TLabel *Label50;
        TLabel *Label51;
        TLabel *Label53;
        TLabel *Label54;
        TLabel *Label56;
        TLabel *Label59;
        TPanel *Panel2;
        TLabel *Label64;
        TLabel *Label65;
        TLabel *Label66;
        TLabel *Label67;
        TLabel *Label68;
        TLabel *Label58;
        TLabel *Label60;
        TLabel *Label61;
        TLabel *Label62;
        TLabel *Label63;
        TPanel *Panel3;
        TLabel *Label69;
        TLabel *Label74;
        TLabel *Label75;
        TLabel *Label76;
        TLabel *Label77;
        TLabel *Label78;
        TLabel *Label70;
        TLabel *Label71;
        TLabel *Label72;
        TLabel *Label73;
        TPanel *Panel4;
        TLabel *Label79;
        TLabel *Label80;
        TLabel *Label81;
        TLabel *Label82;
        TLabel *Label83;
        TLabel *Label84;
        TLabel *Label85;
        TLabel *Label86;
        TLabel *Label87;
        TLabel *Label88;
        TLabel *Label89;
        TLabel *Label90;
        TLabel *Label91;
        TLabel *Label92;
        TPanel *Panel5;
        TLabel *Label93;
        TLabel *Label94;
        TLabel *Label95;
        TLabel *Label96;
        TLabel *Label97;
        TLabel *Label98;
        TLabel *Label99;
        TLabel *Label100;
        TLabel *Label101;
        TLabel *Label102;
        TLabel *Label103;
        TLabel *Label104;
        TLabel *Label105;
        TLabel *Label106;
        TLabel *Label107;
        TLabel *Label108;
        TLabel *Label109;
        TLabel *Label110;
        TLabel *Label111;
        TLabel *Label112;
        TLabel *Label113;
        TLabel *Label114;
        TPanel *Panel6;
        TLabel *Label115;
        TLabel *Label116;
        TLabel *Label117;
        TLabel *Label118;
        TLabel *Label119;
        TLabel *Label120;
        TLabel *Label121;
        TLabel *Label122;
        TLabel *Label123;
        TLabel *Label124;
        TPanel *Panel7;
        TLabel *Label125;
        TLabel *Label126;
        TLabel *Label127;
        TLabel *Label128;
        TLabel *Label129;
        TLabel *Label130;
        TLabel *Label131;
        TLabel *Label132;
        TLabel *Label133;
        TLabel *Label134;
        TPanel *Panel8;
        TLabel *Label136;
        TLabel *Label137;
        TLabel *Label135;
        TLabel *Label138;
        TLabel *Label139;
        TLabel *Label140;
        TLabel *Label141;
        TLabel *Label142;
        TLabel *Label143;
        TLabel *Label144;
        TLabel *Label145;
        TLabel *Label146;
        TLabel *Label147;
        TSpeedButton *SpeedButton1;
        TLabel *Label148;
        TLabel *Label149;
        TLabel *Label150;
        TLabel *Label151;
        TLabel *Label152;
        TLabel *Label153;
        TLabel *Label154;
        TLabel *Label155;
        TLabel *Label156;
        TLabel *Label157;
        TLabel *Label158;
        TSpeedButton *SpeedButton2;
        TLabel *Label159;
        TLabel *Label160;
        TLabel *Label161;
        TLabel *Label162;
        TLabel *Label163;
        TLabel *Label164;
        TLabel *Label165;
        TLabel *Label166;
        TLabel *Label167;
        TLabel *Label168;
        TLabel *Label169;
        TSpeedButton *SpeedButton3;
        TLabel *Label170;
        TLabel *Label171;
        TLabel *Label172;
        TLabel *Label173;
        TLabel *Label174;
        TLabel *Label175;
        TLabel *Label176;
        TLabel *Label177;
        TLabel *Label178;
        TLabel *Label179;
        TLabel *Label180;
        TSpeedButton *SpeedButton4;
        TLabel *Label181;
        TLabel *Label182;
        TLabel *Label183;
        TLabel *Label184;
        TLabel *Label185;
        TLabel *Label186;
        TLabel *Label187;
        TLabel *Label188;
        TLabel *Label189;
        TLabel *Label190;
        TLabel *Label191;
        TSpeedButton *SpeedButton5;
        TLabel *Label192;
        TLabel *Label193;
        TLabel *Label194;
        TLabel *Label195;
        TLabel *Label196;
        TLabel *Label197;
        TLabel *Label198;
        TLabel *Label199;
        TLabel *Label200;
        TLabel *Label201;
        TLabel *Label202;
        TSpeedButton *SpeedButton6;
        TLabel *Label203;
        TLabel *Label204;
        TLabel *Label205;
        TLabel *Label206;
        TLabel *Label207;
        TLabel *Label208;
        TLabel *Label209;
        TLabel *Label210;
        TLabel *Label211;
        TLabel *Label212;
        TLabel *Label213;
        TSpeedButton *SpeedButton7;
        TLabel *Label214;
        TLabel *Label215;
        TLabel *Label216;
        TLabel *Label217;
        TLabel *Label218;
        TLabel *Label219;
        TLabel *Label220;
        TLabel *Label221;
        TLabel *Label222;
        TLabel *Label223;
        TLabel *Label224;
        TSpeedButton *SpeedButton8;
        TLabel *Label225;
        TLabel *Label226;
        TLabel *Label227;
        TLabel *Label228;
        TLabel *Label229;
        TLabel *Label230;
        TLabel *Label231;
        TLabel *Label232;
        TLabel *Label233;
        TTabSheet *TabSheet4;
        TPanel *Panel9;
        TLabel *Label235;
        TLabel *Label236;
        TLabel *Label237;
        TLabel *Label238;
        TPanel *Panel10;
        TLabel *Label244;
        TLabel *Label234;
        TLabel *Label239;
        TPanel *Panel11;
        TLabel *Label240;
        TLabel *Label241;
        TPanel *Panel12;
        TLabel *Label242;
        TPanel *Panel13;
        TLabel *Label243;
        TTabSheet *TabSheet5;
        TStaticText *StaticText1;
        TStaticText *StaticText2;
        TLabel *Label245;
        TStaticText *diskru_pr;
        TLabel *Label246;
        TLabel *cn_r_stat_label;
        TPanel *Panel14;
        TLabel *Label247;
        TStaticText *inpu_ob_st;
        TLabel *Label248;
        TLabel *Label249;
        TLabel *Label250;
        TLabel *Label251;
        TLabel *Label252;
        TTimer *inpu_dbg_timer;
        void __fastcall inpu_dbg_timerTimer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TNeptDebug(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNeptDebug *NeptDebug;
//---------------------------------------------------------------------------
#endif
