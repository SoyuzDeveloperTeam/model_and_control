//---------------------------------------------------------------------------

#ifndef krl_formH
#define krl_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class Tkrl_frm : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *balform1;
        TStatusBar *StatusBar1;
        TEdit *v_num;
        TLabel *Label1;
        TButton *Button1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TLabel *Label3;
        TEdit *Edit3;
        TLabel *Label4;
        TEdit *Edit4;
        TLabel *Label5;
        TEdit *Edit5;
        TLabel *Label6;
        TEdit *Edit6;
        TLabel *Label7;
        TEdit *Edit7;
        TLabel *Label8;
        TEdit *Edit8;
        TLabel *Label9;
        TEdit *Edit9;
        TLabel *Label10;
        TEdit *Edit10;
        TLabel *Label11;
        TEdit *Edit11;
        TLabel *Label12;
        TEdit *Edit12;
        TLabel *Label13;
        TEdit *Edit13;
        TLabel *Label14;
        TEdit *Edit14;
        TLabel *Label15;
        TEdit *Edit15;
        TLabel *Label16;
        TEdit *Edit16;
        TLabel *Label17;
        TEdit *Edit17;
        TLabel *Label18;
        TLabel *Label19;
        TEdit *Edit18;
        TLabel *Label20;
        TEdit *Edit19;
        TLabel *Label21;
        TLabel *Label22;
        TEdit *Edit20;
        TTabSheet *TabSheet1;
        TGroupBox *GroupBox1;
        TSpeedButton *SpeedButton1;
        TStaticText *StaticText1;
        TDateTimePicker *krl_t0;
        TGroupBox *GroupBox2;
        TRadioButton *op;
        TRadioButton *sb;
        TRadioButton *sp;
        TTabSheet *TabSheet2;
        TMemo *Memo1;
        TGroupBox *GroupBox3;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TTabSheet *TabSheet3;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations

        __fastcall Tkrl_frm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tkrl_frm *krl_frm;
//---------------------------------------------------------------------------
#endif
