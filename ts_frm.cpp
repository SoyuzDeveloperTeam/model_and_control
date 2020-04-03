//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
// Отладка поиска зависания:
// Отключил таймеры Timer1
#include "ts_frm.h"
#include "ts_header.h"
#include "USOData.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tts_form *ts_form;
//---------------------------------------------------------------------------
__fastcall Tts_form::Tts_form(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tts_form::Timer1Timer(TObject *Sender)  // Таймер Индикации
{
// ТС1
if(USO_Booled[9][2]) // Авария Носителя
        {
         ts1_1->Color=clRed;
        } else ts1_1->Color=clMaroon;
if(USO_Booled[9][5]) // Сработал ТД
        {
         ts1_2->Color=clRed;
        } else ts1_2->Color=clMaroon;
/* if(TS1_pr[2]) // Резерв
        {
         ts1_3->Color=clRed;
        } else ts1_3->Color=clMaroon;
if(TS1_pr[3]) // Резерв
        {
         ts1_4->Color=clRed;
        } else ts1_4->Color=clMaroon;  */
if(USO_Booled[9][4]) // Рпо падает
        {
         ts1_5->Color=clRed;
        } else ts1_5->Color=clMaroon;
if(USO_Booled[9][7]) // Авария ДК
        {
         ts1_6->Color=clRed;
        } else ts1_6->Color=clMaroon;
// ТС2
if(USO_Booled[9][8]) // Rsa PADAET
        {
         ts2_1->Color=clRed;
        } else ts2_1->Color=clMaroon;
if(USO_Booled[9][11]) // R400 mm r
        {
         ts2_2->Color=clRed;
        } else ts2_2->Color=clMaroon;
if(USO_Booled[9][9])  // Razgerm
        {
         ts2_3->Color=clRed;
        } else ts2_3->Color=clMaroon;
if(USO_Booled[9][12]) // SostVozd
        {
         ts2_4->Color=clRed;
        } else ts2_4->Color=clMaroon;
if(USO_Booled[9][10])
        {
         ts2_5->Color=clRed;
        } else ts2_5->Color=clMaroon;
if(USO_Booled[9][13])
        {
         ts2_6->Color=clRed;
        } else ts2_6->Color=clMaroon;
// ТС3
if(USO_Booled[9][14])
        {
         ts3_1->Color=clYellow;
        } else ts3_1->Color=clOlive;
if(USO_Booled[10][1])
        {
         ts3_2->Color=clYellow;
        } else ts3_2->Color=clOlive;
if(TS3_pr[2])
        {
         ts3_3->Color=clYellow;
        } else ts3_3->Color=clOlive;
if(TS3_pr[3])
        {
         ts3_4->Color=clYellow;
        } else ts3_4->Color=clOlive;
if(TS3_pr[4])
        {
         ts3_5->Color=clYellow;
        } else ts3_5->Color=clOlive;
if(TS3_pr[5])
        {
         ts3_6->Color=clYellow;
        } else ts3_6->Color=clOlive;
// ТС4
if(TS4_pr[0])
        {
         ts4_1->Color=clLime;
        } else ts4_1->Color=clGreen;
if(TS4_pr[1])
        {
         ts4_2->Color=clLime;
        } else ts4_2->Color=clGreen;
if(TS4_pr[2])
        {
         ts4_3->Color=clLime;
        } else ts4_3->Color=clGreen;
if(TS4_pr[3])
        {
         ts4_4->Color=clLime;
        } else ts4_4->Color=clGreen;
if(USO_Booled[10][7])  // Работа ДПО
        {
         ts4_5->Color=clLime;
        } else ts4_5->Color=clGreen;
if(USO_Booled[10][10]) // Работа СКД
        {
         ts4_6->Color=clLime;
        } else ts4_6->Color=clGreen;
// ТС5
if(TS5_pr[0])
        {
         ts5_1->Color=clYellow;
        } else ts5_1->Color=clOlive;
if(TS5_pr[1])
        {
         ts5_2->Color=clYellow;
        } else ts5_2->Color=clOlive;
if(TS5_pr[2])
        {
         ts5_3->Color=clYellow;
        } else ts5_3->Color=clOlive;
if(TS5_pr[3])
        {
         ts5_4->Color=clYellow;
        } else ts5_4->Color=clOlive;
if(TS5_pr[4])
        {
         ts5_5->Color=clYellow;
        } else ts5_5->Color=clOlive;
if(TS5_pr[5])
        {
         ts5_6->Color=clYellow;
        } else ts5_6->Color=clOlive;
// ТС6
if(TS6_pr[0])
        {
         ts6_1->Color=clYellow;
        } else ts6_1->Color=clOlive;
if(TS6_pr[1])
        {
         ts6_2->Color=clYellow;
        } else ts6_2->Color=clOlive;
if(TS6_pr[2])
        {
         ts6_3->Color=clYellow;
        } else ts6_3->Color=clOlive;
if(TS6_pr[3])
        {
         ts6_4->Color=clYellow;
        } else ts6_4->Color=clOlive;
if(TS6_pr[4])
        {
         ts6_5->Color=clYellow;
        } else ts6_5->Color=clOlive;
if(TS6_pr[5])
        {
         ts6_6->Color=clYellow;
        } else ts6_6->Color=clOlive;
// ТС7
if(USO_Booled[11][6])   // Argon Ready
        {
         ts7_1->Color=clLime;
        } else ts7_1->Color=clGreen;
if(USO_Booled[11][9])   // 2 nadduv section
        {
         ts7_2->Color=clLime;
        } else ts7_2->Color=clGreen;
if(USO_Booled[11][7])   // OSK
        {
         ts7_3->Color=clLime;
        } else ts7_3->Color=clGreen;
if(USO_Booled[11][10])  // 2 section KDU
        {
         ts7_4->Color=clLime;
        } else ts7_4->Color=clGreen;
if(USO_Booled[11][8])   // GSO
        {
         ts7_5->Color=clLime;
        } else ts7_5->Color=clGreen;
if(USO_Booled[11][11])
        {
         ts7_6->Color=clLime;
        } else ts7_6->Color=clGreen;
// TC8
if(TS8_pr[0])
        {
         ts8_1->Color=clLime;
        } else ts8_1->Color=clGreen;
if(TS8_pr[1])
        {
         ts8_2->Color=clLime;
        } else ts8_2->Color=clGreen;
if(TS8_pr[2])
        {
         ts8_3->Color=clLime;
        } else ts8_3->Color=clGreen;
if(TS8_pr[3])
        {
         ts8_4->Color=clLime;
        } else ts8_4->Color=clGreen;
if(TS8_pr[4])
        {
         ts8_5->Color=clLime;
        } else ts8_5->Color=clGreen;
if(TS8_pr[5])
        {
         ts8_6->Color=clLime;
        } else ts8_6->Color=clGreen;
// ДОП 1
if(DOP1_pr[0])
        {
         tsa1->Color=clLime;
        } else tsa1->Color=clGreen;
if(DOP1_pr[1])
        {
         tsa2->Color=clLime;
        } else tsa2->Color=clGreen;
if(USO_Booled[12][7])
        {
         tsa3->Color=clLime;
        } else tsa3->Color=clGreen;
if(DOP1_pr[3])
        {
         tsa4->Color=clLime;
        } else tsa4->Color=clGreen;
if(USO_Booled[12][10])
        {
         tsa5->Color=clLime;
        } else tsa5->Color=clGreen;
if(DOP1_pr[5])
        {
         tsa6->Color=clLime;
        } else tsa6->Color=clGreen;
// ДОП2
if(DOP2_pr[0])
        {
         tsb1->Color=clLime;
        } else tsb1->Color=clGreen;
if(DOP2_pr[1])
        {
         tsb2->Color=clLime;
        } else tsb2->Color=clGreen;
if(DOP2_pr[2])
        {
         tsb3->Color=clLime;
        } else tsb3->Color=clGreen;
if(DOP2_pr[3])
        {
         tsb4->Color=clLime;
        } else tsb4->Color=clGreen;
if(DOP2_pr[4])
        {
         tsb5->Color=clLime;
        } else tsb5->Color=clGreen;
if(DOP2_pr[5])
        {
         tsb6->Color=clLime;
        } else tsb6->Color=clGreen;
}
//---------------------------------------------------------------------------


