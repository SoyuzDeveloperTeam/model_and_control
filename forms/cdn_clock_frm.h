//---------------------------------------------------------------------------

#ifndef cdn_clock_frmH
#define cdn_clock_frmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TCDN_CLOCK : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TTimer *Timer1;
        TLabel *Label6;
        TLabel *Label7;
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TCDN_CLOCK(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCDN_CLOCK *CDN_CLOCK;
//---------------------------------------------------------------------------
#endif
