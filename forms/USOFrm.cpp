//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "USOFrm.h"
#include "USOData.h"
#include "main_header.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUsoForm *UsoForm;
//---------------------------------------------------------------------------
__fastcall TUsoForm::TUsoForm(TComponent* Owner)
        : TForm(Owner)
{


}
//---------------------------------------------------------------------------

void IrviMaker(){
 if(IrviStringRT.SubString(1,1).IsEmpty()) UsoForm->Label357->Caption="_"; else
  UsoForm->Label357->Caption=IrviStringRT.SubString(1,1);
 if(IrviStringRT.SubString(2,1).IsEmpty()) UsoForm->Label357->Caption="_"; else
  UsoForm->Label357->Caption=IrviStringRT.SubString(2,1);
}

AnsiString MakeOct(bool UsoBool1, bool UsoBool2, bool UsoBool3, bool UsoBool4){
 if(UsoBool1==0&&UsoBool2==0&&UsoBool3==0&&UsoBool4==0) return "0"; else
 if(UsoBool1==0&&UsoBool2==0&&UsoBool3==0&&UsoBool4==1) return "1"; else
 if(UsoBool1==0&&UsoBool2==0&&UsoBool3==1&&UsoBool4==0) return "2"; else
 if(UsoBool1==0&&UsoBool2==0&&UsoBool3==1&&UsoBool4==1) return "3"; else
 if(UsoBool1==0&&UsoBool2==1&&UsoBool3==0&&UsoBool4==0) return "4"; else
 if(UsoBool1==0&&UsoBool2==1&&UsoBool3==0&&UsoBool4==1) return "5"; else
 if(UsoBool1==0&&UsoBool2==1&&UsoBool3==1&&UsoBool4==0) return "6"; else
 if(UsoBool1==0&&UsoBool2==1&&UsoBool3==1&&UsoBool4==1) return "7"; else
 if(UsoBool1==1&&UsoBool2==0&&UsoBool3==0&&UsoBool4==0) return "8"; else
 if(UsoBool1==1&&UsoBool2==0&&UsoBool3==0&&UsoBool4==1) return "0"; else
 if(UsoBool1==1&&UsoBool2==0&&UsoBool3==1&&UsoBool4==0) return "A"; else
 if(UsoBool1==1&&UsoBool2==0&&UsoBool3==1&&UsoBool4==1) return "B"; else
 if(UsoBool1==1&&UsoBool2==1&&UsoBool3==0&&UsoBool4==0) return "C"; else
 if(UsoBool1==1&&UsoBool2==1&&UsoBool3==0&&UsoBool4==1) return "D"; else
 if(UsoBool1==1&&UsoBool2==1&&UsoBool3==1&&UsoBool4==0) return "E"; else
 if(UsoBool1==1&&UsoBool2==1&&UsoBool3==1&&UsoBool4==1) return "F";
}

AnsiString IrviStr_sy(bool USOBlock[4]){
 if(USOBlock[0]==0&&USOBlock[1]==0&&USOBlock[2]==0&&USOBlock[3]==0) return "0"; else
 if(USOBlock[0]==0&&USOBlock[1]==1&&USOBlock[2]==1&&USOBlock[3]==1) return "1"; else
 if(USOBlock[0]==1&&USOBlock[1]==0&&USOBlock[2]==1&&USOBlock[3]==1) return "2"; else
 if(USOBlock[0]==0&&USOBlock[1]==0&&USOBlock[2]==1&&USOBlock[3]==1) return "3"; else
 if(USOBlock[0]==0&&USOBlock[1]==0&&USOBlock[2]==0&&USOBlock[3]==0) return "4"; else
 if(USOBlock[0]==0&&USOBlock[1]==0&&USOBlock[2]==0&&USOBlock[3]==0) return "5"; else
 if(USOBlock[0]==0&&USOBlock[1]==0&&USOBlock[2]==0&&USOBlock[3]==0) return "6"; else
 if(USOBlock[0]==0&&USOBlock[1]==0&&USOBlock[2]==0&&USOBlock[3]==0) return "7"; else
 if(USOBlock[0]==0&&USOBlock[1]==0&&USOBlock[2]==0&&USOBlock[3]==0) return "8"; else
 if(USOBlock[0]==0&&USOBlock[1]==0&&USOBlock[2]==0&&USOBlock[3]==0) return "9";
 }

//void(

void irvitos(AnsiString Ind, bool UB[4]){
 if(Ind=="0"){ UB[0]=0; UB[1]=0; UB[2]=0; UB[0]=0;} else
 if(Ind=="1"){ UB[0]=0; UB[1]=1; UB[2]=1; UB[0]=1;} else
 if(Ind=="2"){ UB[0]=1; UB[1]=0; UB[2]=1; UB[0]=1;} else
 if(Ind=="3"){ UB[0]=0; UB[1]=0; UB[2]=1; UB[0]=1;} else
 if(Ind=="4"){ UB[0]=1; UB[1]=1; UB[2]=0; UB[0]=1;} else
 if(Ind=="5"){ UB[0]=0; UB[1]=1; UB[2]=0; UB[0]=1;} else
 if(Ind=="6"){ UB[0]=1; UB[1]=0; UB[2]=0; UB[0]=1;} else
 if(Ind=="7"){ UB[0]=0; UB[1]=0; UB[2]=0; UB[0]=1;} else
 if(Ind=="8"){ UB[0]=1; UB[1]=1; UB[2]=1; UB[0]=0;} else
 if(Ind=="9"){ UB[0]=0; UB[1]=1; UB[2]=1; UB[0]=0;}
}

void Irvo2Uso(AnsiString IrviStr){
bool USOBT[4];
if(IrviStr.SubString(1,1)=="0"){
 irvitos("0",USOBT);
 USO_Booled[10][0] = USOBT[0]; USO_Booled[10][1] = USOBT[1];
 USO_Booled[10][2] = USOBT[2]; USO_Booled[10][3] = USOBT[3];} else
if(IrviStr.SubString(1,1)=="1"){
 irvitos("1",USOBT);
 USO_Booled[10][0] = USOBT[0]; USO_Booled[10][1] = USOBT[1];
 USO_Booled[10][2] = USOBT[2]; USO_Booled[10][3] = USOBT[3];}
}

AnsiString MakeOctS(int s){
AnsiString out;
out = MakeOct(USO_Booled[s][0],USO_Booled[s][1],USO_Booled[s][2],USO_Booled[s][3])+
MakeOct(USO_Booled[s][4],USO_Booled[s][5],USO_Booled[s][6],USO_Booled[s][7])+
MakeOct(USO_Booled[s][8],USO_Booled[s][9],USO_Booled[s][10],USO_Booled[s][11])+
MakeOct(USO_Booled[s][12],USO_Booled[s][13],USO_Booled[s][14],USO_Booled[s][15]);
return out;
}

void MakeOctStr(int LabelN, int s){ // 24-43
((TLabel*)UsoForm->Components[LabelN])->Caption = MakeOctS(s);
}
void usoworker_t(bool USOBool,int LabelN){
if(USOBool)
((TLabel*)UsoForm->Components[LabelN])->Caption = "I"; else
((TLabel*)UsoForm->Components[LabelN])->Caption = ".";
}

void MakeUSO(int s, int n){
usoworker_t(USO_Booled[s][0],n);n++;
usoworker_t(USO_Booled[s][1],n);n++;
usoworker_t(USO_Booled[s][2],n);n++;
usoworker_t(USO_Booled[s][3],n);n++;
usoworker_t(USO_Booled[s][4],n);n++;
usoworker_t(USO_Booled[s][5],n);n++;
usoworker_t(USO_Booled[s][6],n);n++;
usoworker_t(USO_Booled[s][7],n);n++;
usoworker_t(USO_Booled[s][8],n);n++;
usoworker_t(USO_Booled[s][9],n);n++;
usoworker_t(USO_Booled[s][10],n);n++;
usoworker_t(USO_Booled[s][11],n);n++;
usoworker_t(USO_Booled[s][12],n);n++;
usoworker_t(USO_Booled[s][13],n);n++;
usoworker_t(USO_Booled[s][14],n);n++;
usoworker_t(USO_Booled[s][15],n);
}

void __fastcall TUsoForm::Timer1Timer(TObject *Sender)
{

MakeOctStr(24,0);
MakeOctStr(25,1);
MakeOctStr(26,2);
MakeOctStr(27,3);
MakeOctStr(28,4);
MakeOctStr(29,5);
MakeOctStr(30,6);
MakeOctStr(31,7);
MakeOctStr(32,8);
MakeOctStr(33,9);
MakeOctStr(34,10);
MakeOctStr(35,11);
MakeOctStr(36,12);
MakeOctStr(37,13);
MakeOctStr(38,14);
MakeOctStr(39,15);
MakeOctStr(40,16);
MakeOctStr(41,17);
MakeOctStr(42,18);
MakeOctStr(43,19);

MakeUSO(0,44);
MakeUSO(1,60);
MakeUSO(2,76);
MakeUSO(3,92);
MakeUSO(4,108);
MakeUSO(5,124);
MakeUSO(6,140);
MakeUSO(7,156);
MakeUSO(8,172);
MakeUSO(9,188);
MakeUSO(10,204);
MakeUSO(11,220);
MakeUSO(12,236);
MakeUSO(13,252);
MakeUSO(14,268);
MakeUSO(15,284);
MakeUSO(16,300);
MakeUSO(17,316);
MakeUSO(18,332);
MakeUSO(19,348);
//MakeUSO(20,364);
IrviMaker();
Irvo2Uso(IrviStringRT);
}
//---------------------------------------------------------------------------

void __fastcall TUsoForm::Button1Click(TObject *Sender)
{
usoworker_t(CB->Checked,StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------
/*
   44   45   46   47      48   49   50   51      52   53   54   55     56   57   58   59
   60
   76

*/
void __fastcall TUsoForm::Button2Click(TObject *Sender)
{
USO_Booled[uso_b->ItemIndex][uso_s->ItemIndex]=uso_p->ItemIndex;
}
//---------------------------------------------------------------------------

