//---------------------------------------------------------------------------

#ifndef sm_ssvp_plxH
#define sm_ssvp_plxH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class Tsm_ssvpX : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TSpeedButton *SpeedButton1;
        TImageList *il;
        TListBox *ListBox1;
        TListBox *ListBox2;
        TButton *Button1;
        TLabel *Label11;
private:	// User declarations
public:		// User declarations
        __fastcall Tsm_ssvpX(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tsm_ssvpX *sm_ssvpX;
//---------------------------------------------------------------------------
#endif
