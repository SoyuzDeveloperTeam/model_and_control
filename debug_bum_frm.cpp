//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "dta.cpp"
#include "debug_bum_frm.h"
#include "bumconnect.cpp"      // Обмен с БУМ

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tbum_debug *bum_debug;


//---------------------------------------------------------------------------
__fastcall Tbum_debug::Tbum_debug(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tbum_debug::Button1Click(TObject *Sender)
{
 p_1->Caption=  IntToStr(htonl(NU_temp.n_tr));
 p_2->Caption=  IntToStr(htonl(NU_temp.nu_day));
 p_3->Caption=  IntToStr(htonl(NU_temp.nu_month));
 p_4->Caption=  IntToStr(htonl(NU_temp.nu_year));
 p_5->Caption=  IntToStr(htonl(NU_temp.nu_hour));
 p_6->Caption=  IntToStr(htonl(NU_temp.nu_min));
 p_7->Caption=  IntToStr(htonl(NU_temp.nu_sec));
 p_8->Caption=FormatFloat("0000.00000000",NU_temp.vec_j2000_mks[0]);
 p_9->Caption=FormatFloat("0000.00000000",NU_temp.vec_j2000_mks[1]);
p_10->Caption=FormatFloat("0000.00000000",NU_temp.vec_j2000_mks[2]);
p_11->Caption=FormatFloat("0000.00000000",NU_temp.vel_j2000_mks[0]);
p_12->Caption=FormatFloat("0000.00000000",NU_temp.vel_j2000_mks[1]);
p_13->Caption=FormatFloat("0000.00000000",NU_temp.vel_j2000_mks[2]);
p_14->Caption=FormatFloat("0000.00000000",NU_temp.Q_mks[0]);
p_15->Caption=FormatFloat("0000.00000000",NU_temp.Q_mks[1]);
p_16->Caption=FormatFloat("0000.00000000",NU_temp.Q_mks[2]);
p_17->Caption=FormatFloat("0000.00000000",NU_temp.Q_mks[3]);
p_18->Caption=FormatFloat("0000.00000000",NU_temp.w_j2000_mks[0]);
p_19->Caption=FormatFloat("0000.00000000",NU_temp.w_j2000_mks[1]);
p_20->Caption=FormatFloat("0000.00000000",NU_temp.w_j2000_mks[2]);
p_21->Caption=FormatFloat("0000.00000000",NU_temp.vec_mks_PC[0]);
p_22->Caption=FormatFloat("0000.00000000",NU_temp.vec_mks_PC[1]);
p_23->Caption=FormatFloat("0000.00000000",NU_temp.vec_mks_PC[2]);
p_24->Caption=FormatFloat("0000.00000000",NU_temp.m_mk);
p_25->Caption=FormatFloat("0000.00000000",NU_temp.mi_mks[0][0]);
p_26->Caption=FormatFloat("0000.00000000",NU_temp.mi_mks[0][1]);
p_27->Caption=FormatFloat("0000.00000000",NU_temp.mi_mks[0][2]);
p_28->Caption=FormatFloat("0000.00000000",NU_temp.mi_mks[1][0]);
p_29->Caption=FormatFloat("0000.00000000",NU_temp.mi_mks[1][1]);
p_30->Caption=FormatFloat("0000.00000000",NU_temp.mi_mks[1][2]);
p_31->Caption=FormatFloat("0000.00000000",NU_temp.mi_mks[2][0]);
p_32->Caption=FormatFloat("0000.00000000",NU_temp.mi_mks[2][1]);
p_33->Caption=FormatFloat("0000.00000000",NU_temp.mi_mks[2][2]);
p_34->Caption=FormatFloat("0000.00000000",NU_temp.vec_j2000_tk[0]);
p_35->Caption=FormatFloat("0000.00000000",NU_temp.vec_j2000_tk[1]);
p_36->Caption=FormatFloat("0000.00000000",NU_temp.vec_j2000_tk[2]);
p_37->Caption=FormatFloat("0000.00000000",NU_temp.vel_j2000_tk[0]);
p_38->Caption=FormatFloat("0000.00000000",NU_temp.vel_j2000_tk[1]);
p_39->Caption=FormatFloat("0000.00000000",NU_temp.vel_j2000_tk[2]);
p_40->Caption=FormatFloat("0000.00000000",NU_temp.Q_tk[0]);
p_41->Caption=FormatFloat("0000.00000000",NU_temp.Q_tk[1]);
p_42->Caption=FormatFloat("0000.00000000",NU_temp.Q_tk[2]);
p_43->Caption=FormatFloat("0000.00000000",NU_temp.Q_tk[3]);
p_44->Caption=FormatFloat("0000.00000000",NU_temp.w_j2000_tk[0]);
p_45->Caption=FormatFloat("0000.00000000",NU_temp.w_j2000_tk[1]);
p_46->Caption=FormatFloat("0000.00000000",NU_temp.w_j2000_tk[2]);
p_47->Caption=FormatFloat("0000.00000000",NU_temp.vec_tk_TPK[0]);
p_48->Caption=FormatFloat("0000.00000000",NU_temp.vec_tk_TPK[1]);
p_49->Caption=FormatFloat("0000.00000000",NU_temp.vec_tk_TPK[2]);
p_50->Caption=FormatFloat("0000.00000000",NU_temp.m_tk);
p_51->Caption=FormatFloat("0000.00000000",NU_temp.mi_tk[0][0]);
p_52->Caption=FormatFloat("0000.00000000",NU_temp.mi_tk[0][1]);
p_53->Caption=FormatFloat("0000.00000000",NU_temp.mi_tk[0][2]);
p_54->Caption=FormatFloat("0000.00000000",NU_temp.mi_tk[1][0]);
p_55->Caption=FormatFloat("0000.00000000",NU_temp.mi_tk[1][1]);
p_56->Caption=FormatFloat("0000.00000000",NU_temp.mi_tk[1][2]);
p_57->Caption=FormatFloat("0000.00000000",NU_temp.mi_tk[2][0]);
p_58->Caption=FormatFloat("0000.00000000",NU_temp.mi_tk[2][1]);
p_59->Caption=FormatFloat("0000.00000000",NU_temp.mi_tk[2][2]);
p_60->Caption=FormatFloat("0000.00000000",NU_temp.vec_solar[0]);
p_61->Caption=FormatFloat("0000.00000000",NU_temp.vec_solar[1]);
p_62->Caption=FormatFloat("0000.00000000",NU_temp.vec_solar[2]);
p_63->Caption=IntToStr(htonl(NU_temp.r_st_mks));
p_65->Caption=IntToStr(htonl(NU_temp.nu_otor_switch_styk_dk));
p_66->Caption=FormatFloat("0000.00000000",NU_temp.nu_com_zapas);
p_67->Caption=IntToStr(htonl(NU_temp.pr_doking));
p_68->Caption=IntToStr(htonl(NU_temp.nu_mlm_sost));
p_69->Caption=IntToStr(htonl(NU_temp.nr_sudn));
}
//---------------------------------------------------------------------------
void __fastcall Tbum_debug::Button2Click(TObject *Sender)
{
SendToBum(0x00000310, 1, 1);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button3Click(TObject *Sender)
{
SendToBum(0x00000311, 1, 0);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button4Click(TObject *Sender)
{
SendToBum(0x00000311, 1, 1);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button5Click(TObject *Sender)
{
SendToBum(0x00000311, 1, 2);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button6Click(TObject *Sender)
{
SendToBum(0x00000311, 1, 3);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button7Click(TObject *Sender)
{
SendToBum(0x00000311, 2, 0);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button8Click(TObject *Sender)
{
SendToBum(0x00000311, 2, 1);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button9Click(TObject *Sender)
{
SendToBum(0x00200101, 48, 0x11221100);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button10Click(TObject *Sender)
{
SendToBum(0x00000312, 1, 1);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button11Click(TObject *Sender)
{
SendToBum(0x00000313, 1, 1);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button12Click(TObject *Sender)
{
SendToBum(0x0000028E, 1, 1);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button13Click(TObject *Sender)
{
SendToBum(0x0000029D, 1, 1);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button14Click(TObject *Sender)
{
SendToBum(0x0000029B, 1, 1);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button15Click(TObject *Sender)
{
SendToBum(0x00000185, 2, 1);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Timer1Timer(TObject *Sender)
{
if(start_priz){
 ListBox1->Items->Add("-> Paket N "+FormatFloat("0000000000",htonl(PS_tk_iss.fd_6))+" Read in "+Now().FormatString("hh:nn:ss.zzz"));
 // +" Read in "+Now().FormatString("hh:nn:ss.zzz")+" - is correct"
ListBox1->Perform(WM_VSCROLL,SB_LINEDOWN,0);
}
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button16Click(TObject *Sender)
{
SendToBum(0x0000029B, 0, 0);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

void __fastcall Tbum_debug::Button17Click(TObject *Sender)
{
SendToBum(0x00000185, 0, 0);       //Команда в БУМ ()
}
//---------------------------------------------------------------------------

