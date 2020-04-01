//---------------------------------------------------------------------------

#ifndef iss_per_tpH
#define iss_per_tpH
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
//---------------------------------------------------------------------------
class Tiss_t_tp : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart1;
        TFastLineSeries *Series1;
        TTimer *Timer1;
        TLabel *Label1;
        TLabel *Label2;
        TGroupBox *GroupBox1;
        TLabel *Label3;
        TPanel *Panel1;
        TPanel *Panel2;
        TLabel *Label4;
        TGroupBox *GroupBox2;
        TLabel *Label5;
        TLabel *Label6;
        TPanel *Panel3;
        TPanel *Panel4;
        TGroupBox *GroupBox3;
        TLabel *Label7;
        TLabel *Label8;
        TPanel *Panel5;
        TPanel *Panel6;
        TButton *Button1;
        TLabel *Label9;
        TLabel *Label10;
        TChart *Chart2;
        TFastLineSeries *FastLineSeries1;
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tiss_t_tp(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tiss_t_tp *iss_t_tp;
//---------------------------------------------------------------------------
#endif
