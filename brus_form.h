//---------------------------------------------------------------------------

#ifndef brus_formH
#define brus_formH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tbrus_frm : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TImage *vent_vsk_off;
        TImage *en_ill_vsk_off;
        TImage *boa_sa_osn_off;
        TImage *boa_sa_rez_off;
        TImage *vsa_off;
        TImage *epkrd_rez_off;
        TImage *pod_vsk_off;
        TImage *epkrd_osn_off;
        TImage *boa_sa_osn_on;
        TImage *boa_sa_rez_on;
        TImage *vsa_on;
        TImage *en_ill_vsk_on;
        TImage *vent_vsk_on;
        TImage *pod_vsk_on;
        TImage *epkrd_osn_on;
        TImage *epkrd_rez_on;
        void __fastcall epkrd_osn_offClick(TObject *Sender);
        void __fastcall epkrd_osn_onClick(TObject *Sender);
        void __fastcall epkrd_rez_offClick(TObject *Sender);
        void __fastcall epkrd_rez_onClick(TObject *Sender);
        void __fastcall vsa_offClick(TObject *Sender);
        void __fastcall vsa_onClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tbrus_frm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tbrus_frm *brus_frm;
//---------------------------------------------------------------------------
#endif
