//---------------------------------------------------------------------------

#ifndef ssvp_formH
#define ssvp_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tssvp_frm : public TForm
{
__published:	// IDE-managed Components
        TProgressBar *xod_sh;
        TTimer *Timer1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *s_pos;
        TButton *test_btn;
        TPanel *Panel1;
        TPaintBox *ssvp_pas;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall test_btnClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tssvp_frm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tssvp_frm *ssvp_frm;
//---------------------------------------------------------------------------
#endif
