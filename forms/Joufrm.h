//---------------------------------------------------------------------------

#ifndef JoufrmH
#define JoufrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TJouForm : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
        __fastcall TJouForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TJouForm *JouForm;
//---------------------------------------------------------------------------
#endif
