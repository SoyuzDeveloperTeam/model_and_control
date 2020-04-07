//---------------------------------------------------------------------------

#ifndef KSPPFormH
#define KSPPFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TKSP_right : public TForm
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
        TLabel *N1_LABEL;
        TLabel *N3_LABEL;
        TLabel *N5_LABEL;
        TLabel *N7_LABEL;
        TLabel *N9_LABEL;
        TLabel *N11_LABEL;
        TLabel *N13_LABEL;
        TLabel *N15_LABEL;
        TLabel *N17_LABEL;
        TLabel *B1_LABEL;
        TLabel *B3_LABEL;
        TLabel *B5_LABEL;
        TLabel *B7_LABEL;
        TLabel *B9_LABEL;
        TLabel *B11_LABEL;
        TLabel *B13_LABEL;
        TLabel *B15_LABEL;
        TLabel *B17_LABEL;
        TLabel *P1_LABEL;
        TLabel *P3_LABEL;
        TLabel *P5_LABEL;
        TLabel *P7_LABEL;
        TLabel *P9_LABEL;
        TLabel *P11_LABEL;
        TLabel *P13_LABEL;
        TLabel *P15_LABEL;
        TLabel *P17_LABEL;
        TLabel *R1_LABEL;
        TLabel *R3_LABEL;
        TLabel *R5_LABEL;
        TLabel *R7_LABEL;
        TLabel *R9_LABEL;
        TLabel *R11_LABEL;
        TLabel *R13_LABEL;
        TLabel *R15_LABEL;
        TLabel *R17_LABEL;
        TLabel *S1_LABEL;
        TLabel *S3_LABEL;
        TLabel *S5_LABEL;
        TLabel *S7_LABEL;
        TLabel *S9_LABEL;
        TLabel *S11_LABEL;
        TLabel *S13_LABEL;
        TLabel *S15_LABEL;
        TLabel *S17_LABEL;
        TLabel *T1_LABEL;
        TLabel *T3_LABEL;
        TLabel *T5_LABEL;
        TLabel *T7_LABEL;
        TLabel *T9_LABEL;
        TLabel *T11_LABEL;
        TLabel *T13_LABEL;
        TLabel *T15_LABEL;
        TLabel *T17_LABEL;
        TLabel *U1_LABEL;
        TLabel *U3_LABEL;
        TLabel *U5_LABEL;
        TLabel *U7_LABEL;
        TLabel *U9_LABEL;
        TLabel *U11_LABEL;
        TLabel *U13_LABEL;
        TLabel *U15_LABEL;
        TLabel *U17_LABEL;
        TLabel *F1_LABEL;
        TLabel *F3_LABEL;
        TLabel *F5_LABEL;
        TLabel *F7_LABEL;
        TLabel *F9_LABEL;
        TLabel *F11_LABEL;
        TLabel *F13_LABEL;
        TLabel *F15_LABEL;
        TLabel *F17_LABEL;
        TShape *Shape1;
        TPanel *KSP_R_N;
        TImage *KSP_R_N_image;
        TPanel *KSP_R_B;
        TImage *KSP_R_B_image;
        TPanel *KSP_R_R;
        TImage *KSP_R_R_image;
        TPanel *KSP_R_P;
        TImage *KSP_R_P_image;
        TPanel *KSP_R_T;
        TImage *KSP_R_T_image;
        TPanel *KSP_R_S;
        TImage *KSP_R_S_image;
        TPanel *KSP_R_F;
        TImage *KSP_R_F_image;
        TPanel *KSP_R_U;
        TImage *KSP_R_U_image;
        TTimer *KSPTMR;
        TShape *Shape2;
        TShape *Shape3;
        TShape *Shape4;
        TShape *Shape5;
        void __fastcall KSP_R_B_imageClick(TObject *Sender);
        void __fastcall KSP_R_N_imageClick(TObject *Sender);
        void __fastcall KSP_R_T_imageClick(TObject *Sender);
        void __fastcall KSP_R_P_imageClick(TObject *Sender);
        void __fastcall KSP_R_R_imageClick(TObject *Sender);
        void __fastcall KSP_R_S_imageClick(TObject *Sender);
        void __fastcall KSP_R_U_imageClick(TObject *Sender);
        void __fastcall KSP_R_F_imageClick(TObject *Sender);
        void __fastcall ksp_1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TKSP_right(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKSP_right *KSP_right;
//---------------------------------------------------------------------------
#endif
