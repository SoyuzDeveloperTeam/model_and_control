//---------------------------------------------------------------------------

#ifndef spgs_formH
#define spgs_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tspgsfrm : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TImage *Image1;
private:	// User declarations
public:		// User declarations
        __fastcall Tspgsfrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tspgsfrm *spgsfrm;
//---------------------------------------------------------------------------
#endif
