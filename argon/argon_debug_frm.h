//---------------------------------------------------------------------------

#ifndef argon_debug_frmH
#define argon_debug_frmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Targ_deb : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox8;
        TLabel *Label59;
        TLabel *Label60;
        TLabel *Label61;
        TLabel *Label62;
        TLabel *Label63;
        TLabel *Label64;
        TLabel *Label65;
        TLabel *Label66;
        TLabel *Label67;
        TLabel *Label68;
        TLabel *Label69;
        TLabel *Label70;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TPanel *Panel1;
        TGroupBox *GroupBox2;
        TListBox *ArgonJou;
        TGroupBox *GroupBox9;
        TLabel *Label30;
        TEdit *addr_ozu;
        TButton *Button14;
        TCheckBox *ind;
        TGroupBox *GroupBox3;
        TComboBox *cw_num_cb;
        TButton *Button13;
        TButton *Button11;
        TComboBox *ctrlword_enter;
        TGroupBox *GroupBox4;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TTimer *Timer1;
        TTimer *Timer2;
        TGroupBox *GroupBox5;
        TLabel *Label51;
        TLabel *Label52;
        TLabel *Label53;
        TLabel *Label54;
        TLabel *Label55;
        TLabel *Label56;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox7;
        TLabel *Label31;
        TLabel *Label32;
        TLabel *Label47;
        TLabel *Label48;
        TLabel *Label49;
        TLabel *Label50;
        TTimer *argon_dt;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TGroupBox *arg_channels_indication;
        TPanel *v_ch;
        TPanel *B_ch;
        TPanel *a_ch;
        TLabel *debug_pusk;
        TLabel *Label8;
        TTimer *Timer3;
        TButton *CH_A;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall argon_dtTimer(TObject *Sender);
        void __fastcall Timer3Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Targ_deb(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Targ_deb *arg_deb;
void mtaj(AnsiString Msg, bool half);
//---------------------------------------------------------------------------
#endif
