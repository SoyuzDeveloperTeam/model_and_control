//---------------------------------------------------------------------------

#ifndef sps_frmH
#define sps_frmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tsps_form : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TPanel *sps_ro2;
        TLabel *Label1;
        TPanel *sps_rco2;
        TLabel *Label2;
        TPanel *sps_rh20;
        TLabel *Label3;
        TPanel *sps_rsa;
        TLabel *Label4;
        TPanel *sps_rbo;
        TLabel *Label5;
        TPanel *sps_rob;
        TLabel *Label6;
        TPanel *sps_tsa;
        TLabel *Label7;
        TPanel *sps_tbo;
        TLabel *Label8;
        TPanel *sps_tg;
        TLabel *Label9;
        TGroupBox *GroupBox2;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TPanel *sps_ro21;
        TPanel *sps_ro22;
        TPanel *sps_ro23;
        TGroupBox *GroupBox3;
        TLabel *Label13;
        TLabel *Label14;
        TPanel *sps_rkjo;
        TPanel *sps_pknr;
        TGroupBox *GroupBox4;
        TLabel *Label15;
        TPanel *sps_rsu;
        TGroupBox *GroupBox5;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label23;
        TPanel *sps_rhb1;
        TPanel *sps_rhb2;
        TPanel *sps_rok1;
        TPanel *sps_rok2;
        TPanel *sps_rg1;
        TPanel *sps_rg2;
        TPanel *sps_rfo;
        TPanel *sps_rfg;
        TGroupBox *GroupBox6;
        TLabel *Label24;
        TLabel *Label25;
        TLabel *Label30;
        TLabel *Label31;
        TPanel *sps_rnadd1;
        TPanel *sps_rnadd2;
        TPanel *sps_rper1;
        TPanel *sps_rper2;
        TGroupBox *GroupBox7;
        TLabel *Label26;
        TLabel *Label27;
        TPanel *sps_isb;
        TPanel *sps_inagr;
        TGroupBox *GroupBox8;
        TLabel *Label28;
        TLabel *Label29;
        TPanel *sps_rpo;
        TPanel *sps_tpo;
        TTimer *Timer1;
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tsps_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tsps_form *sps_form;
//---------------------------------------------------------------------------
#endif
