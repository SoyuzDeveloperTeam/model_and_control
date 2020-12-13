//---------------------------------------------------------------------------

#ifndef clock_formH
#define clock_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class Tclock_frm : public TForm
{
__published:	// IDE-managed Components
        TTimer *Timer1;
        TLabel *hour_1;
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *ind_8;
        TLabel *ind_7;
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
        TImage *sw_off;
        TImage *sw_on;
        TSpeedButton *SpeedButton1;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall sw_offClick(TObject *Sender);
        void __fastcall sw_onClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tclock_frm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tclock_frm *clock_frm;
//---------------------------------------------------------------------------
#endif
