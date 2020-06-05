//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "clock_form.h"
#include "main_header.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tclock_frm *clock_frm;
TDateTime secundomer;
TDateTime TStartM;
static int cc=0;
static int SSD_st;
//---------------------------------------------------------------------------
__fastcall Tclock_frm::Tclock_frm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tclock_frm::Timer1Timer(TObject *Sender)
{
if(SSD_st==3){
ind_7->Caption=Now().FormatString("dd")[1];
ind_8->Caption=Now().FormatString("dd")[2];
Label9->Caption="-";
//Label8->Caption=OnboardModelTime
if(Now().DayOfWeek()==1)Label8->Caption=7; else
Label8->Caption=Now().DayOfWeek()-1;} else if(SSD_st==1){
secundomer = secundomer + (1.0/(24*3600));
ind_7->Caption=secundomer.FormatString("nn")[1];
ind_8->Caption=secundomer.FormatString("nn")[2];
Label9->Caption=secundomer.FormatString("ss")[1];
Label8->Caption=secundomer.FormatString("ss")[2];
} else if (SSD_st==1) {
  
}
hour_1->Caption=Now().FormatString("hh")[1];
Label1->Caption=Now().FormatString("hh")[2];
Label3->Caption=Now().FormatString("nn")[1];
Label2->Caption=Now().FormatString("nn")[2];
Label5->Caption=Now().FormatString("ss")[1];
Label4->Caption=Now().FormatString("ss")[2];
}
//---------------------------------------------------------------------------
void __fastcall Tclock_frm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Timer1->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall Tclock_frm::FormShow(TObject *Sender)
{
hour_1->Font->Color=StringToColor("0x291D65");   // I 1
Label1->Font->Color=StringToColor("0x291D65");  // I 2
Label2->Font->Color=StringToColor("0x291D65");   //
Label3->Font->Color=StringToColor("0x291D65");
Label4->Font->Color=StringToColor("0x291D65");
Label5->Font->Color=StringToColor("0x291D65");
ind_8->Font->Color=StringToColor("0x291D65");
ind_7->Font->Color=StringToColor("0x291D65");
Label8->Font->Color=StringToColor("0x291D65");
Label9->Font->Color=StringToColor("0x291D65");
Label10->Font->Color=StringToColor("0x291D65");  // z I 1
Label11->Font->Color=StringToColor("0x291D65");  // z I 7
Label12->Font->Color=StringToColor("0x291D65");  // z I 8
Label13->Font->Color=StringToColor("0x291D65");  // z I 9
Label14->Font->Color=StringToColor("0x291D65");
Label15->Font->Color=StringToColor("0x291D65");
Label16->Font->Color=StringToColor("0x291D65");
Label17->Font->Color=StringToColor("0x291D65");
Label18->Font->Color=StringToColor("0x291D65");
Label19->Font->Color=StringToColor("0x291D65");

}
//---------------------------------------------------------------------------

void __fastcall Tclock_frm::sw_offClick(TObject *Sender)
{
Timer1->Enabled=true;
sw_off->Visible=false;
sw_on->Visible=true;
hour_1->Font->Color=StringToColor("0x3210FE");
Label1->Font->Color=StringToColor("0x3210FE");
Label3->Font->Color=StringToColor("0x3210FE");
Label2->Font->Color=StringToColor("0x3210FE");
Label5->Font->Color=StringToColor("0x3210FE");
Label4->Font->Color=StringToColor("0x3210FE");
ind_7->Font->Color=StringToColor("0x3210FE");
ind_8->Font->Color=StringToColor("0x3210FE");
Label9->Font->Color=StringToColor("0x3210FE");
Label8->Font->Color=StringToColor("0x3210FE");
}
//---------------------------------------------------------------------------

void __fastcall Tclock_frm::sw_onClick(TObject *Sender)
{
hour_1->Font->Color=StringToColor("0x291D65");
Label1->Font->Color=StringToColor("0x291D65");
Label2->Font->Color=StringToColor("0x291D65");
Label3->Font->Color=StringToColor("0x291D65");
Label4->Font->Color=StringToColor("0x291D65");
Label5->Font->Color=StringToColor("0x291D65");
ind_8->Font->Color=StringToColor("0x291D65");  //Label6->Caption="8";
ind_7->Font->Color=StringToColor("0x291D65"); // Label7->Caption="8";
Label8->Font->Color=StringToColor("0x291D65"); // Label8->Caption="8";
Label9->Font->Color=StringToColor("0x291D65"); // Label9->Caption="8";
Label10->Font->Color=StringToColor("0x291D65");// Label10->Caption="8"; // z I 1
Label11->Font->Color=StringToColor("0x291D65"); //Label11->Caption="8"; // z I 7
Label12->Font->Color=StringToColor("0x291D65"); //Label12->Caption="8"; // z I 8
Label13->Font->Color=StringToColor("0x291D65"); //Label13->Caption="8"; // z I 9
Label14->Font->Color=StringToColor("0x291D65");// Label14->Caption="8";
Label15->Font->Color=StringToColor("0x291D65");// Label15->Caption="8";
Label16->Font->Color=StringToColor("0x291D65");// Label16->Caption="8";
Label17->Font->Color=StringToColor("0x291D65");// Label17->Caption="8";
Label18->Font->Color=StringToColor("0x291D65");// Label18->Caption="8";
Label19->Font->Color=StringToColor("0x291D65");// Label19->Caption="8";
Timer1->Enabled=false;
sw_on->Visible=false;
sw_off->Visible=true;
}
//---------------------------------------------------------------------------


void __fastcall Tclock_frm::FormCreate(TObject *Sender)
{
SSD_st = 3;
}
//---------------------------------------------------------------------------

void __fastcall Tclock_frm::SpeedButton1Click(TObject *Sender)
{
if(SSD_st==1) {SSD_st=2; secundomer = secundomer - secundomer;}else
if(SSD_st==2) SSD_st=3; else
if(SSD_st==3) SSD_st=1;
}
//---------------------------------------------------------------------------


