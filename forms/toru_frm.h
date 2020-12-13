//---------------------------------------------------------------------------

#ifndef toru_frmH
#define toru_frmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Ttoru_pult : public TForm
{
__published:	// IDE-managed Components
        TImage *toru_back;
        TSpeedButton *pwr_on;
        TSpeedButton *pwr_off;
        TSpeedButton *odr;
        TSpeedButton *pered_com_off;
        TSpeedButton *ru_on;
        TSpeedButton *ru_off;
        TSpeedButton *SpeedButton6;
        TSpeedButton *pered_rez;
        TSpeedButton *prm_rez;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        TSpeedButton *SpeedButton12;
        TSpeedButton *SpeedButton13;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton14;
        TSpeedButton *SpeedButton15;
        TSpeedButton *SpeedButton16;
        TSpeedButton *SpeedButton17;
        TSpeedButton *SpeedButton18;
        TSpeedButton *SpeedButton19;
        TSpeedButton *SpeedButton20;
        TSpeedButton *SpeedButton21;
        TSpeedButton *SpeedButton22;
        TSpeedButton *SpeedButton23;
        TSpeedButton *SpeedButton24;
        TSpeedButton *SpeedButton25;
        TSpeedButton *SpeedButton26;
        TSpeedButton *SpeedButton27;
        TSpeedButton *SpeedButton28;
        TSpeedButton *SpeedButton29;
        TSpeedButton *SpeedButton30;
        TSpeedButton *SpeedButton31;
        TSpeedButton *SpeedButton32;
        TSpeedButton *SpeedButton33;
        TSpeedButton *SpeedButton34;
        TSpeedButton *SpeedButton35;
        TSpeedButton *SpeedButton36;
        TSpeedButton *SpeedButton37;
        TSpeedButton *SpeedButton38;
        TSpeedButton *SpeedButton39;
        TSpeedButton *SpeedButton40;
        TPanel *pow_a;
        TPanel *pow_b;
        void __fastcall pwr_onClick(TObject *Sender);
        void __fastcall pwr_offClick(TObject *Sender);
        void __fastcall prm_rezClick(TObject *Sender);
        void __fastcall pered_rezClick(TObject *Sender);
        void __fastcall odrClick(TObject *Sender);
        void __fastcall pered_com_offClick(TObject *Sender);
        void __fastcall ru_onClick(TObject *Sender);
        void __fastcall ru_offClick(TObject *Sender);
        void __fastcall SpeedButton6Click(TObject *Sender);
        void __fastcall SpeedButton9Click(TObject *Sender);
        void __fastcall SpeedButton10Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall SpeedButton12Click(TObject *Sender);
        void __fastcall SpeedButton13Click(TObject *Sender);
        void __fastcall SpeedButton40Click(TObject *Sender);
        void __fastcall SpeedButton30Click(TObject *Sender);
        void __fastcall SpeedButton11Click(TObject *Sender);
        void __fastcall SpeedButton39Click(TObject *Sender);
        void __fastcall SpeedButton36Click(TObject *Sender);
        void __fastcall SpeedButton35Click(TObject *Sender);
        void __fastcall SpeedButton34Click(TObject *Sender);
        void __fastcall SpeedButton31Click(TObject *Sender);
        void __fastcall SpeedButton32Click(TObject *Sender);
        void __fastcall SpeedButton33Click(TObject *Sender);
        void __fastcall SpeedButton37Click(TObject *Sender);
        void __fastcall SpeedButton38Click(TObject *Sender);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall SpeedButton5Click(TObject *Sender);
        void __fastcall SpeedButton7Click(TObject *Sender);
        void __fastcall SpeedButton8Click(TObject *Sender);
        void __fastcall SpeedButton14Click(TObject *Sender);
        void __fastcall SpeedButton15Click(TObject *Sender);
        void __fastcall SpeedButton16Click(TObject *Sender);
        void __fastcall SpeedButton17Click(TObject *Sender);
        void __fastcall SpeedButton18Click(TObject *Sender);
        void __fastcall SpeedButton19Click(TObject *Sender);
        void __fastcall SpeedButton20Click(TObject *Sender);
        void __fastcall SpeedButton21Click(TObject *Sender);
        void __fastcall SpeedButton22Click(TObject *Sender);
        void __fastcall SpeedButton23Click(TObject *Sender);
        void __fastcall SpeedButton24Click(TObject *Sender);
        void __fastcall SpeedButton25Click(TObject *Sender);
        void __fastcall SpeedButton26Click(TObject *Sender);
        void __fastcall SpeedButton27Click(TObject *Sender);
        void __fastcall SpeedButton28Click(TObject *Sender);
        void __fastcall SpeedButton29Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Ttoru_pult(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Ttoru_pult *toru_pult;
//---------------------------------------------------------------------------
#endif
