//---------------------------------------------------------------------------

#ifndef vived_frmH
#define vived_frmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tliftoff_form : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart1;
        TFastLineSeries *Series2;
        TEdit *Edit1;
        TEdit *Edit2;
        TButton *Button1;
        TLabel *Label1;
        TLabel *Label2;
        TPointSeries *Series1;
        TLabel *Label3;
        TTimer *Timer1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tliftoff_form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tliftoff_form *liftoff_form;
//---------------------------------------------------------------------------
#endif
