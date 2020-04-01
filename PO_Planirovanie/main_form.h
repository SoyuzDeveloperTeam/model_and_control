//---------------------------------------------------------------------------

#ifndef main_formH
#define main_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class Tmainform : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TButton *Button1;
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
private:	// User declarations
public:		// User declarations
        __fastcall Tmainform(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tmainform *mainform;
//---------------------------------------------------------------------------
#endif
