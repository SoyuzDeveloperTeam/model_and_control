//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "bum_sett_frm.h"
#include "bumconnect.cpp"
#include "md_m.h"              // Модельные переменные (структура m_math)
#include "stdio.h"
#include "dta.cpp"
#include "JouStrings.h"                 // Строковые переменные для журнала
#include "JouHeader.h"                  // Заголовок для журнала
#include <math.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tbum_settings *bum_settings;
static int ddss;
//---------------------------------------------------------------------------
__fastcall Tbum_settings::Tbum_settings(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

static bool isk_pr;

unsigned int m_second, m_min, m_hour, s_sec;
static AnsiString model_time;
void __fastcall Tbum_settings::bum_descTimer(TObject *Sender)
{
Label161->Caption=PS_tk_iss.CIFC_bt[0];
//Label162->Caption=ntohf(PS_tk_iss.CIFC_bt[1]);
Label163->Caption=FloatToStr(PS_tk_iss.CIFC_bt[2]);

Label165->Caption=FormatFloat("0.000000",PS_tk_iss.CIFC_Ug_bt[0]);
Label166->Caption=FormatFloat("0.000000",PS_tk_iss.CIFC_Ug_bt[1]);
Label167->Caption=FormatFloat("0.000000",PS_tk_iss.CIFC_Ug_bt[2]);
Label161->Caption=FormatFloat("0.000000",PS_tk_iss.CIFC_bt[0]);
Label162->Caption=FormatFloat("0.000000",PS_tk_iss.CIFC_bt[1]);
Label163->Caption=FormatFloat("0.000000",PS_tk_iss.CIFC_bt[2]);
Label169->Caption=FormatFloat("0.000000",PS_tk_iss.CIFC_Wdis[0]);
Label170->Caption=FormatFloat("0.000000",PS_tk_iss.CIFC_Wdis[1]);
Label171->Caption=FormatFloat("0.000000",PS_tk_iss.CIFC_Wdis[2]);

// Промах
Label156->Caption=htonl(PS_tk_iss.promah_pr);
// Вектор на Солнце
if(IsNan(PS_tk_iss.sun_vec[0]))sun_vector_x->Caption="***"; else
sun_vector_x->Caption=FloatToStr(PS_tk_iss.sun_vec[0]);
if(IsNan(PS_tk_iss.sun_vec[1]))sun_vector_y->Caption="***"; else
sun_vector_y->Caption=FloatToStr(htonl(PS_tk_iss.sun_vec[1]));
if(IsNan(PS_tk_iss.sun_vec[2]))sun_vector_z->Caption="***"; else
sun_vector_z->Caption=FloatToStr(PS_tk_iss.sun_vec[2]);
// Шаг отображения
bum_desc->Interval=StrToInt(desc->Text);
// Свето-теневая обстановка
if(ntohl(PS_tk_iss.pr_t_pt)==0)Label134->Caption="СВЕТ"; else
if(ntohl(PS_tk_iss.pr_t_pt)==1)Label134->Caption="ТЕНЬ"; else
if(ntohl(PS_tk_iss.pr_t_pt)==2)Label134->Caption="ПОЛУТЕНЬ";
// Время до вх. п-т
Label136->Caption=ntohl(PS_tk_iss.t_to_pt);
// Время до выхода из п-т
Label138->Caption=ntohl(PS_tk_iss.t_ot_pt);
// Команды в БАДПО
Label101->Caption=ntohl(PS_tk_iss.badpo_perm[0]);  // Команды на перемещение по оси Х
Label147->Caption=ntohl(PS_tk_iss.badpo_perm[1]);  // Команды на перемещение по оси Y
Label150->Caption=ntohl(PS_tk_iss.badpo_perm[2]);  // Команды на перемещение по оси Z
Label144->Caption=ntohl(PS_tk_iss.badpo_orie[0]);  // Команды на ориентацию  по оси Х
Label148->Caption=ntohl(PS_tk_iss.badpo_orie[1]);  // Команды на ориентацию  по оси Y
Label151->Caption=ntohl(PS_tk_iss.badpo_orie[2]);  // Команды на ориентацию  по оси Z
// Признак фары
if(ntohl(PS_tk_iss.fara_pr)==0) Label155->Caption="Выключена"; else
if(ntohl(PS_tk_iss.fara_pr)==1) Label155->Caption="Включена";
// Признак ТВ
Label153->Caption=ntohl(PS_tk_iss.tv_pr);
// Скорость МКС
if(IsNan(PS_tk_iss.vel_j2000_mks[0]))Label107->Caption="***"; else
Label107->Caption=FloatToStr(PS_tk_iss.vel_j2000_mks[0]);
if(IsNan(PS_tk_iss.vel_j2000_mks[1]))Label106->Caption="***"; else
Label106->Caption=FloatToStr(PS_tk_iss.vel_j2000_mks[1]);
if(IsNan(PS_tk_iss.vel_j2000_mks[2]))Label105->Caption="***"; else
Label105->Caption=FloatToStr(PS_tk_iss.vel_j2000_mks[2]);
// Положение МКС в 2000
Label104->Caption=FloatToStr(PS_tk_iss.vec_j2000_mks[0]/1000);
Label103->Caption=FloatToStr(PS_tk_iss.vec_j2000_mks[1]/1000);
Label102->Caption=FloatToStr(PS_tk_iss.vec_j2000_mks[2]/1000);
// Положение ТК в 2000
Label36->Caption=FloatToStr(PS_tk_iss.vec_j2000_tk[0]/1000);
Label35->Caption=FloatToStr(PS_tk_iss.vec_j2000_tk[1]/1000);
Label34->Caption=FloatToStr(PS_tk_iss.vec_j2000_tk[2]/1000);
// Объект управления
if(htonl(PS_tk_iss.tk_type)==0)bum_object->Caption="Прогресс-МС"; else
if(htonl(PS_tk_iss.tk_type)==1)bum_object->Caption="Союз-МС"; else
if(htonl(PS_tk_iss.tk_type)==2)bum_object->Caption="МЛМ";
// Признак перехода МКС в ТП
if(htonl(PS_tk_iss.iss_tp_pr)==0)Label130->Caption="Не завершен"; else
if(htonl(PS_tk_iss.iss_tp_pr)==1){Label130->Caption="Завершен"; if(!isk_pr){
isk_pr=true; JPS(1,is_bum,is_operator,"Смена ориентации МКС ","     ИСКт");}}
// Дата-время
//m_second = htonl(PS_tk_iss.model_sec);
//m_min  = m_second/60;
//m_hour = m_second/60/60;
//s_sec  = m_second%60;
//dest_s = StrToTime(IntToStr(m_hour)+":"+IntToStr(m_min)+":"+IntToStr(s_sec));
//time_from_bum->Caption=(onboard_dt + dest_s).FormatString("hh:nn:ss");
//ob_cur = StrToTime(time_from_bum->Caption);
Label132->Caption=htonl(PS_tk_iss.milisec_ost);
// Текущая тяга СКД
Label140->Caption=FloatToStr(PS_tk_iss.skd_h);
// Расход СКД (с начала режима)
Label142->Caption=FloatToStr(PS_tk_iss.skd_rash);
// Кватернион разворота ТК
q_ssk_tk_0->Caption=FloatToStr(PS_tk_iss.Q_tk[0]);
q_ssk_tk_1->Caption=FloatToStr(PS_tk_iss.Q_tk[1]);
q_ssk_tk_2->Caption=FloatToStr(PS_tk_iss.Q_tk[2]);
q_ssk_tk_3->Caption=FloatToStr(PS_tk_iss.Q_tk[3]);
// Кватернион разворота МКС
Label97->Caption=FloatToStr(PS_tk_iss.Q_mks[0]);
Label98->Caption=FloatToStr(PS_tk_iss.Q_mks[1]);
Label99->Caption=FloatToStr(PS_tk_iss.Q_mks[2]);
Label100->Caption=FloatToStr(PS_tk_iss.Q_mks[3]);
//-----
Label157->Caption=IntToStr(PS_tk_iss.tv_pr);
}
//---------------------------------------------------------------------------

void __fastcall Tbum_settings::FormCreate(TObject *Sender)
{
bum_10->Active=true;
}
//---------------------------------------------------------------------------


void __fastcall Tbum_settings::Timer1Timer(TObject *Sender)
{
Label68->Caption=WsaPortTele;
}
//---------------------------------------------------------------------------
int sssqqq;
void __fastcall Tbum_settings::Timer2Timer(TObject *Sender)
{

if(start_priz){
iResult = recv(TeleSocket,(char *)&fdd, sizeof(fdd), 0);
if (iResult == SOCKET_ERROR) GetWsaError(WSAGetLastError());
if(fdd.a==352452868){
sssqqq++;
Label61->Caption=IntToStr(sssqqq);
//Label76->Caption=IntToStr(fdd.model_sec);
//Label77->Caption=IntToStr(fdd.milisec_ost);
}
} // start_priz
}
//---------------------------------------------------------------------------

void __fastcall Tbum_settings::Button2Click(TObject *Sender)
{
ddss=StrToInt(Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall Tbum_settings::Button3Click(TObject *Sender)
{
;
if(hhm->ItemIndex==0) PS_tk_iss.skd_rash=htons(0x3f80aa3d5b614084); else
if(hhm->ItemIndex==1) PS_tk_iss.skd_rash=htonl(0x3f80aa3d5b614084); else
if(hhm->ItemIndex==2) PS_tk_iss.skd_rash=ntohs(0x3f80aa3d5b614084); else
if(hhm->ItemIndex==3) PS_tk_iss.skd_rash=ntohl(0x3f80aa3d5b614084); else
if(hhm->ItemIndex==4) PS_tk_iss.skd_rash=0x3f80aa3d5b614084;
}
//---------------------------------------------------------------------------


