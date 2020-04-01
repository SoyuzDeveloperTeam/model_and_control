//---------------------------------------------------------------------------

#ifndef sm_ssvp_PXH
#define sm_ssvp_PXH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ImgList.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tsm_ssvp_plx_frm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *bvs_mode;
        TLabel *Label4;
        TLabel *kruki;
        TLabel *Label6;
        TLabel *upor;
        TLabel *Label8;
        TLabel *kr_p1;
        TLabel *kr_p2;
        TSpeedButton *SpeedButton1;
        TGroupBox *GroupBox1;
        TListBox *ListBox1;
        TGroupBox *GroupBox2;
        TLabel *Label11;
        TListBox *ListBox2;
        TButton *Button1;
        TImageList *il;
        TTimer *Timer1;
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tsm_ssvp_plx_frm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tsm_ssvp_plx_frm *sm_ssvp_plx_frm;
//---------------------------------------------------------------------------
#endif
