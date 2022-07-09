//---------------------------------------------------------------------------

#ifndef AboutFrmH
#define AboutFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TAboutForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *aboutlabel;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button1;
        TImage *Image1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *ctc_label;
        TLabel *Label5;
        void __fastcall Label2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAboutForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutForm *AboutForm;
//---------------------------------------------------------------------------
#endif
