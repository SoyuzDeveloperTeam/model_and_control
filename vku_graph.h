//---------------------------------------------------------------------------

#ifndef vku_graphH
#define vku_graphH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <BubbleCh.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class Tvkugraph : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart1;
        TBubbleSeries *Series1;
        TTimer *Timer1;
        TFastLineSeries *Series2;
private:	// User declarations
public:		// User declarations
        __fastcall Tvkugraph(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tvkugraph *vkugraph;
//---------------------------------------------------------------------------
#endif
