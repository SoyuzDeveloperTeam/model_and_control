//---------------------------------------------------------------------------

#ifndef trassaH
#define trassaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
//---------------------------------------------------------------------------
class Ttrace : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart1;
        TFastLineSeries *Series1;
        TTimer *Timer1;
private:	// User declarations
public:		// User declarations
        __fastcall Ttrace(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Ttrace *trace;
//---------------------------------------------------------------------------
#endif
