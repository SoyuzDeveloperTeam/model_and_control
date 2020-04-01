//---------------------------------------------------------------------------

#ifndef sepformH
#define sepformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tsep_form : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TButton *Button1;
        TLabel *Label8;
        TLabel *Label9;
private:	// User declarations
public:		// User declarations
        __fastcall Tsep_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tsep_form *sep_form;
//---------------------------------------------------------------------------
#endif
