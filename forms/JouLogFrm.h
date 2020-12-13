//---------------------------------------------------------------------------

#ifndef JouLogFrmH
#define JouLogFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
#include <DBGrids.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TJouLogForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TListBox *JouLB;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton1;
        TSaveDialog *SJ;
        void __fastcall JouLBDrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TJouLogForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TJouLogForm *JouLogForm;
//---------------------------------------------------------------------------
#endif
