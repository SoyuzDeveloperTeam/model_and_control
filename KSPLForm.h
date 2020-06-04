//---------------------------------------------------------------------------

#ifndef KSPLFormH
#define KSPLFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tksplfrm : public TForm
{
__published:	// IDE-managed Components
        TSpeedButton *ksp_1;
        TSpeedButton *ksp_2;
        TSpeedButton *ksp_3;
        TSpeedButton *ksp_4;
        TSpeedButton *ksp_5;
        TSpeedButton *ksp_6;
        TSpeedButton *ksp_7;
        TSpeedButton *ksp_8;
        TSpeedButton *ksp_9;
        TSpeedButton *ksp_10;
        TSpeedButton *ksp_11;
        TSpeedButton *ksp_12;
        TSpeedButton *ksp_13;
        TSpeedButton *ksp_14;
        TSpeedButton *ksp_15;
        TSpeedButton *ksp_16;
        TSpeedButton *ksp_17;
        TSpeedButton *ksp_18;
        TLabel *A1_LABEL;
        TLabel *A3_LABEL;
        TLabel *A5_LABEL;
        TLabel *A7_LABEL;
        TLabel *A9_LABEL;
        TLabel *A11_LABEL;
        TLabel *A13_LABEL;
        TLabel *A15_LABEL;
        TLabel *A17_LABEL;
        TLabel *V1_LABEL;
        TLabel *V3_LABEL;
        TLabel *V5_LABEL;
        TLabel *V7_LABEL;
        TLabel *V9_LABEL;
        TLabel *V11_LABEL;
        TLabel *V13_LABEL;
        TLabel *V15_LABEL;
        TLabel *V17_LABEL;
        TLabel *G1_LABEL;
        TLabel *G3_LABEL;
        TLabel *G5_LABEL;
        TLabel *G7_LABEL;
        TLabel *G9_LABEL;
        TLabel *G11_LABEL;
        TLabel *G13_LABEL;
        TLabel *G15_LABEL;
        TLabel *G17_LABEL;
        TLabel *D1_LABEL;
        TLabel *D3_LABEL;
        TLabel *D5_LABEL;
        TLabel *D7_LABEL;
        TLabel *D9_LABEL;
        TLabel *D11_LABEL;
        TLabel *D13_LABEL;
        TLabel *D15_LABEL;
        TLabel *D17_LABEL;
        TLabel *J1_LABEL;
        TLabel *J3_LABEL;
        TLabel *J5_LABEL;
        TLabel *J7_LABEL;
        TLabel *J9_LABEL;
        TLabel *J11_LABEL;
        TLabel *J13_LABEL;
        TLabel *J15_LABEL;
        TLabel *J17_LABEL;
        TLabel *I1_LABEL;
        TLabel *I3_LABEL;
        TLabel *I5_LABEL;
        TLabel *I7_LABEL;
        TLabel *I9_LABEL;
        TLabel *I11_LABEL;
        TLabel *I13_LABEL;
        TLabel *I15_LABEL;
        TLabel *I17_LABEL;
        TLabel *K1_LABEL;
        TLabel *K3_LABEL;
        TLabel *K5_LABEL;
        TLabel *K7_LABEL;
        TLabel *K9_LABEL;
        TLabel *K11_LABEL;
        TLabel *K13_LABEL;
        TLabel *K15_LABEL;
        TLabel *K17_LABEL;
        TLabel *L1_LABEL;
        TLabel *L3_LABEL;
        TLabel *L5_LABEL;
        TLabel *L7_LABEL;
        TLabel *L9_LABEL;
        TLabel *L11_LABEL;
        TLabel *L13_LABEL;
        TLabel *L15_LABEL;
        TLabel *L17_LABEL;
        TShape *Shape1;
        TTimer *S;
        TPanel *KSP_L_V;
        TImage *KSP_L_V_image;
        TPanel *KSP_L_A;
        TImage *KSP_L_A_image;
        TPanel *KSP_L_D;
        TImage *KSP_L_D_image;
        TPanel *KSP_L_G;
        TImage *KSP_L_G_image;
        TPanel *KSP_L_I;
        TImage *KSP_L_I_image;
        TPanel *KSP_L_J;
        TImage *KSP_L_J_image;
        TPanel *KSP_L_L;
        TImage *KSP_L_L_image;
        TPanel *KSP_L_K;
        TImage *KSP_L_K_image;
        TShape *Shape2;
        TShape *Shape3;
        TShape *Shape4;
        TShape *Shape5;
        TShape *Shape6;
        TShape *Shape7;
        TShape *Shape8;
        TShape *Shape9;
        TShape *Shape10;
        TShape *Shape11;
        TShape *Shape12;
        TShape *Shape13;
        TShape *Shape14;
        TShape *Shape15;
        TShape *Shape16;
        TShape *Shape17;
        TShape *Shape18;
        TShape *Shape19;
        TShape *Shape20;
        TShape *Shape21;
        TShape *Shape22;
        TShape *Shape23;
        TShape *Shape24;
        TShape *Shape25;
        TShape *Shape26;
        TShape *Shape27;
        TShape *Shape28;
        TShape *Shape29;
        TShape *Shape30;
        TShape *Shape31;
        TShape *Shape32;
        TShape *Shape33;
        TShape *Shape34;
        TShape *Shape35;
        TShape *Shape36;
        TShape *Shape37;
        TShape *Shape38;
        TShape *Shape39;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        TImage *Image4;
        TImage *Image5;
        TImage *Image6;
        TImage *Image7;
        void __fastcall ksp_1Click(TObject *Sender);
        void __fastcall ksp_2Click(TObject *Sender);
        void __fastcall KSP_L_A_imageClick(TObject *Sender);
        void __fastcall KSP_L_V_imageClick(TObject *Sender);
        void __fastcall KSP_L_G_imageClick(TObject *Sender);
        void __fastcall KSP_L_D_imageClick(TObject *Sender);
        void __fastcall KSP_L_J_imageClick(TObject *Sender);
        void __fastcall KSP_L_I_imageClick(TObject *Sender);
        void __fastcall KSP_L_K_imageClick(TObject *Sender);
        void __fastcall STimer(TObject *Sender);
        void __fastcall ksp_3Click(TObject *Sender);
        void __fastcall KSP_L_L_imageClick(TObject *Sender);
        void __fastcall ksp_4Click(TObject *Sender);
        void __fastcall ksp_5Click(TObject *Sender);
        void __fastcall ksp_6Click(TObject *Sender);
        void __fastcall ksp_7Click(TObject *Sender);
        void __fastcall ksp_8Click(TObject *Sender);
        void __fastcall ksp_9Click(TObject *Sender);
        void __fastcall ksp_10Click(TObject *Sender);
        void __fastcall ksp_11Click(TObject *Sender);
        void __fastcall ksp_12Click(TObject *Sender);
        void __fastcall ksp_13Click(TObject *Sender);
        void __fastcall ksp_14Click(TObject *Sender);
        void __fastcall ksp_15Click(TObject *Sender);
        void __fastcall ksp_16Click(TObject *Sender);
        void __fastcall ksp_17Click(TObject *Sender);
        void __fastcall ksp_18Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tksplfrm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tksplfrm *ksplfrm;
//---------------------------------------------------------------------------
#endif
