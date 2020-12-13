#ifndef USO_MDL
#define USO_MDL
//---------------------------------------------------------------------------
#include "USOData.h"
#include "arg_header.h"
#include "arg_main.cpp"
#include "JouHeader.h"
#include "JouStrings.h"
#include "MainFrm.h"
#include "ssvp_module.cpp"
#include "kdu_math.h"        // Переменные КДУ
#pragma  hdrstop

#include "uso_model.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

static int i_test;
static bool d2b;


///////////////////////
// П Р О Ц Е Д У Р А //
// О Б Р А Б О Т К И //
//   Н А Ж А Т И Я   //
//   К Л А В И Ш И   //
//   К     С     П   //
///////////////////////


void USO_work(){

// КСПл - Линейка А //

if(KSP_Booled[0][0]) { // A 1
// 6.5 Вкл шин пит привода крышки СКД
// 6.7 Вкл привода крышки СКД на откр длит :01:
// Временный алгоритм открытия крышки СКД (без проверки ПаО)
if(i_test==300) { // Время открытия 60 секунд = 60000 мс = 300 тактов по 200 мс
USO_Booled[0][0]=true;   //
JPS(1,"Крышка СКД открыта","","","");
cw_a4[3]=1;
KSP_Booled[0][0] = false;
i_test=0;
}else
i_test++;
}

if(KSP_Booled[0][1]) {  // A 2
if(i_test==300) {
USO_Booled[0][0]=false;
JPS(1,"Крышка СКД закрыта","","","");
cw_a4[3]=0;
KSP_Booled[0][1] = false;
i_test=0;
}else
i_test++;
}

if(KSP_Booled[0][2]) {  // A 3   Наддув КДУ - ВКЛ
   KSP_Booled[0][2] = false;
        // Вкл. пит. клапана наддува ЭПКН1 и ЭПКН2
        // ОК32 Вкл наддува КДУ
        if(USO_Booled[1][2])
        JPS(1,is_sudn,is_kdu,"Наддув КДУ 1 Секции     ВКЛ",""); else
        JPS(1,is_sudn,is_kdu,"Наддув КДУ 2 Секции     ВКЛ","");
        USO_Booled[0][1]=true;
}

if(KSP_Booled[0][3]) {  // A 4   Наддув КДУ - ВЫКЛ
   KSP_Booled[0][3] = false;
        // Откл. пит. клап. наддува ЭПКН1, ЭПКН2
        // ОК33 Откл наддува КДУ
        USO_Booled[0][1]=false;
        if(USO_Booled[1][2])
        JPS(1,is_sudn,is_kdu,"Наддув КДУ 1 Секции     ВЫКЛ",""); else
        JPS(1,is_sudn,is_kdu,"Наддув КДУ 2 Секции     ВЫКЛ","");
}

if(KSP_Booled[0][4]) { // A 5     СДР ОТКЛ
   KSP_Booled[0][4] = false;
        // 98 - Исключение СДН (СДР) из схемы управления
        USO_Booled[0][2]=true;
        kdu_sdr = false;
}

if(KSP_Booled[0][5]) { // A 6
   KSP_Booled[0][5] = false;
        // -98 - Подключение СДН (СДР) к схеме управления
        USO_Booled[0][2]=false;
        kdu_sdr = true;
}

if(KSP_Booled[0][6]) { // A 7
   KSP_Booled[0][6] = false;
        // 95 Исключение СДД из схемы управления
        USO_Booled[0][3]=true;
        kdu_sdd = false;
}

if(KSP_Booled[0][7]) { // A 8
   KSP_Booled[0][7] = false;
        // -95 Подключение СДД к схеме управления
        USO_Booled[0][3]=false;
        kdu_sdd = true;
}

if(KSP_Booled[0][8]) { // A 9 - Выбор ДПО-Б
   KSP_Booled[0][8] = false;
        // Команда в БА ДПО "Выбор ДПО-Б"
        USO_Booled[0][4]=true;
        ba_dpo.b_com = true;
}

// А9 - безотбойная

if(KSP_Booled[0][10]) { // A 11 - Выбор ДПО-М1
   KSP_Booled[0][10] = false;
        USO_Booled[0][5]=true;
        ba_dpo.m1_com = true;
}



if(KSP_Booled[0][12]) {  // A 13
   // А13 - безотбойная
        // Включаем ДПО №№ 2,4,6,8.10,12;
        dpo_v_pr[2,4,6,8,10,12]=1;
        USO_Booled[0][6]=true;
        ba_dpo.m2_com = true;
}

if(KSP_Booled[0][14]) { // A 15
   KSP_Booled[0][14] = false;
        // Вводим в СУБК признак 100 "Объединение секций КДУ",
        // что обеспечит в последующем работу двигателей ДПО и
        // СКД от двух топливных секций КДУ одновременно
        USO_Booled[0][7]=true;
}

if(KSP_Booled[0][16]) {  // A 17
   KSP_Booled[0][16]=false;
        USO_Booled[0][8]=true;
}

// КСПп - Линейка Б //

if(KSP_Booled[1][0]) {  // Б 1
   KSP_Booled[1][0]=false;
        // Автомат СЭП откл
        USO_Booled[0][9]=true;
}

if(KSP_Booled[1][1]) {  // Б 2
   KSP_Booled[1][1]=false;
        // Автомат СЭП откл
        USO_Booled[0][9]=false;
}

if(KSP_Booled[1][2]) {  // Б 3
   KSP_Booled[1][2]=false;
        // Автомат СЭП откл
        USO_Booled[0][10]=true;
}

if(KSP_Booled[1][3]) {  // Б 2
   KSP_Booled[1][3]=false;
        // Автомат СЭП откл
        USO_Booled[0][10]=false;
}

// КСПл - Линейка В //

if(KSP_Booled[2][0]) { // В 1
   KSP_Booled[2][0] = false;
        // 5.12 Выбор первой секции наддува КДУ
        USO_Booled[1][2]=true;
        USO_Booled[11][9]=false;  // Гасим ТС-7 "2 секция наддува"
}

if(KSP_Booled[2][1]) { // В 2
   KSP_Booled[2][1] = false;
        // -5.12 Выбор второй секции наддува КДУ
        USO_Booled[1][2]=false;
        USO_Booled[11][9]=true;  // Зажигаем ТС-7 "2 секция наддува"
}

if(KSP_Booled[2][2]) { // В 3
   KSP_Booled[2][2] = false;
        USO_Booled[1][3]=true;
        USO_Booled[11][10]=false;  // Гасим ТС-7 "2 секция КДУ"
}
if(KSP_Booled[2][3]) { // В 4
   KSP_Booled[2][3]  = false;
        USO_Booled[1][3]  = false;
        USO_Booled[11][10]= true;  // Зажигаем ТС-7 "2 секция КДУ"
}
if(KSP_Booled[2][4]) { // В 5 // Закрываем АО-ВКА
   KSP_Booled[2][4]  = false;
        USO_Booled[1][4]  = true;
}
if(KSP_Booled[2][5]) { // В 6 // Открываем АО-ВКА
   KSP_Booled[2][5]  = false;
        USO_Booled[1][4]  = false;
}
if(KSP_Booled[2][6]) { // В 7
   KSP_Booled[2][6]  = false;
        USO_Booled[1][5]  = true;
}
if(KSP_Booled[2][7]) { // В 8
   KSP_Booled[2][7]  = false;
        USO_Booled[1][5]  = false;
}
if(KSP_Booled[2][8]) { // В 9
   KSP_Booled[2][8]  = false;
        USO_Booled[1][6]  = true;
}
if(KSP_Booled[2][10]) { // В 11
   KSP_Booled[2][10]  = false;
        USO_Booled[1][7]  = true;
}

if(KSP_Booled[2][12]) { // В 13
   KSP_Booled[2][12]  = false;
        // 17.26 Команда в БСУ "ВКЛ ТЕСТ ДИСПЛЕЙ"
        USO_Booled[1][8]  = true;
        USO_Booled[1][12]  = false; // Откл Дисплей
        USO_Booled[1][9]  = false;  // Откл Дисплей ТВ
}
if(KSP_Booled[2][14]) { // В 15
   KSP_Booled[2][14]  = false;
        USO_Booled[1][9]  = true;
        USO_Booled[1][12]  = false;
        USO_Booled[1][8]  = false;
}
if(KSP_Booled[2][16]) { // В 17
   KSP_Booled[2][16]  = false;
        USO_Booled[1][10]  = true;
}
if(KSP_Booled[2][17]) { // В 18
   KSP_Booled[2][17]  = false;
        USO_Booled[1][10]  = false;
}

// КСПл - Линейка Г //

if(KSP_Booled[3][0]) { // Г 1  Обогрев антен ВКЛ
   KSP_Booled[3][0] = false;
        // Выдается автоматически системой КУРС
        // Условия исполнения Г1, ОК1, КР
        // Так же выдаем по КО - перенести в операции по КО
        // включается термостат обогрева антенн, который поддерживает
        // заданный температурный режим механики антенн 2АО,АСФ1,АСФ2.
        USO_Booled[1][11]=true;
}

if(KSP_Booled[3][1]) { // Г 2  Обогрев антен ВЫКЛ
   KSP_Booled[3][1] =false;
        // Производим выключение термостатов
        USO_Booled[1][11]=false;
}

if(KSP_Booled[3][2]) { // Г 3  Дисплей
   KSP_Booled[3][2] =false;
        USO_Booled[1][12]=true;
        USO_Booled[1][8] =false;
        USO_Booled[1][9] =false;  // Откл Дисплей ТВ
}

if(KSP_Booled[3][3]) { // Г 4  Дисплей
   KSP_Booled[3][3] =false;
        USO_Booled[1][12]=false;
        USO_Booled[1][8] =false;
        USO_Booled[1][9] =false;  // Откл Дисплей ТВ
}
if(KSP_Booled[3][4]) {  // Г 5
   KSP_Booled[3][4] =false;
        //5.18 Подготовка к вкл ДПО-Б1 (17, 18)
        USO_Booled[1][13]=true;
        // и откл подготовки ДПО-Б2 (27, 28)
        USO_Booled[1][14]=false;
}

if(KSP_Booled[3][6]) {  // Г 7
   KSP_Booled[3][6] = false;
        //5.19 Подготовка к вкл ДПО-Б2 (27, 28)
        USO_Booled[1][14]=true;
        // и откл подготовки ДПО-Б1 (17, 18)
        USO_Booled[1][13]=false;
}

if(KSP_Booled[3][8]) {  // Г 9  КУРС-1
   KSP_Booled[3][8] = false;
        //27.1 Вкл РП1 (реж пит 1 компл), квитанция в БСУ-7 "ВКЛ РП1"
        USO_Booled[1][16]=true; // Признак выбора КУРС-1
        //-27.2 Откл РП2, квит в БСУ-7 "ОТКЛ РП2"
        USO_Booled[2][0]=false; // Снимаем признак выбора КУРС-2
        //27.3 Вкл РП3 (реж пит общ устр), квит в БСУ-7 "ВКЛ РП3"
        //27.9 Перекл на 1 комплект РПК
}

if(KSP_Booled[3][10]) {  // Г 11 КУРС-2
   KSP_Booled[3][10] = false;
        //-27.1 Откл РП1, квитанция в БСУ-7 "ОТКЛ РП1"
        USO_Booled[1][16]=false;
        //27.2 Вкл РП2, квит в БСУ-7 "ВКЛ РП2"
        USO_Booled[2][0]=true;
        //27.3 Вкл РП3 (реж пит общ устр), квит в БСУ-7 "ВКЛ РП3"
        //-27.9 Перекл на 2 комплект РПК
}
if(KSP_Booled[3][12]) {  // Г 13 ОТКЛ КУРС
   KSP_Booled[3][12] = false;
        //-27.1 Откл РП1, квитанция в БСУ-7 "ОТКЛ РП1"
        USO_Booled[1][16]=false;
        //-27.2 Откл РП2, квит в БСУ-7 "ОТКЛ РП2"
        USO_Booled[2][0]=false;
        //-27.3 Откл РП3 , квит в БСУ-7 "ОТКЛ РП3"
}
if(KSP_Booled[3][14]) { // Г15
   KSP_Booled[3][14] = false;
        USO_Booled[1][13]=true;
        USO_Booled[1][14]=true;
}

// КСПл - Линейка Д //

if(KSP_Booled[4][0]){  // KSP Д1
   KSP_Booled[4][0]=false;
   // Можно выдать только при признаке от ССВП - СОСТЫК ЭЛ РАЗ
   USO_Booled[2][5]  = true;
}

if(KSP_Booled[4][6]){  // КСП Д7
   KSP_Booled[4][6]=false;
       USO_Booled[2][7]=ssvp_power;  // ССВП ВКЛ
       JPS(1,is_sudn,is_operator,"Подано питание на ССВП","");
}

if(KSP_Booled[4][7]){  // КСП Д8
   KSP_Booled[4][7]=false;
       USO_Booled[2][7]=false;  // ССВП ВыКЛ
       JPS(1,is_sudn,is_operator,"Питание на ССВП снятно","");
}

// КСПл - Линейка И //

if(KSP_Booled[6][0]) { // И1   ЗДР
   KSP_Booled[6][0] = false;
        USO_Booled[3][6]=true;
        cw_a2[0]=0;
}

if(KSP_Booled[6][1]) { // И2   РРП
   KSP_Booled[6][1] = false;
        USO_Booled[3][6]=false;
        cw_a2[0]=1;
}

if(KSP_Booled[6][2]) { // И3 АКС
   KSP_Booled[6][2] = false;
        USO_Booled[3][7] = true;
        // Включаем питание БИЛУ + КС020
}

if(KSP_Booled[6][3]) { // И4 АКС
   KSP_Booled[6][3] = false;
        USO_Booled[3][7] = false;
}

if(KSP_Booled[6][8]) {  // И9 ПИТАНИЕ ЧАЙКИ
   KSP_Booled[6][8] = false;
        //USO_Booled[0][8]=false;
        USO_Booled[3][10]=true; // Признак питание чайки
        JPS(1,is_argon,is_operator,"Организовано питание контура управления и БЦВК","");
        USO_Booled[0][1]=true;  // Наддув КДУ по питанию Чайки
        // Так же запитываем БДУС-1 и ИКВ
}

if(KSP_Booled[6][10]) { // И11   -  ПУСК ЧАЙКИ
   KSP_Booled[6][10] = false;
        USO_Booled[3][11]=true;
        JPS(1,is_argon,is_operator,"Введена команда \"ПУСК\", запуск режима самопроверки.","");
        //     И 9                И 15
        if(USO_Booled[3][11]&&USO_Booled[3][14])
        // Операции по пуску чайки //
        // 1 - Проверка (в аргоне) и по результатам - запуск или НшС
        argon_takt_pr=1;
        apm=true; //Признак запуска чайки
}

if(KSP_Booled[6][12]){ // И13  -  ОДР
   KSP_Booled[6][12] = false;
        USO_Booled[3][12]=true;
        // ОК39 Отключение динамических режимов
        // -5.5 Отключение ЭКО1, ЭКГ1, ЭКО2, ЭКГ2
        kdu_log_pr.eko1 = false;
        kdu_log_pr.ekg1 = false;
        kdu_log_pr.eko2 = false;
        kdu_log_pr.ekg2 = false;
        USO_Booled[3][10]=false; // Снимаем Питание чайки
        USO_Booled[3][11]=false; // Снимаем Пуск чайки
                arg_work_pr=0;
                apm=false;
                USO_Booled[11][6] = false;
        USO_Booled[0][1]=false;  // Снимаем Наддув
}

if(KSP_Booled[6][14]) { // И 15 - БЦВК АБВ
   KSP_Booled[6][14] = false;
        USO_Booled[3][13] = true;   // И 15 АБВ
        USO_Booled[3][2]  = false;  // Ж11 БЦВК А
        USO_Booled[3][3]  = false;  // Ж13 БЦВК Б
        USO_Booled[3][4]  = false;  // Ж15 БЦВК В
        // Выбираем все каналы АБВ для БЦВК
        JPS(1,is_argon,is_operator,"Выбраны каналы А Б В","");
        cw_arg[4]=1;
        //(ДЛЯ ТЕСТА КСП - РАБОТАЕТ)
}

if(KSP_Booled[6][16]){ // И 17  - ТЕКУЩЕЕ ПОЛОЖЕНИЕ - ВКЛ
   KSP_Booled[6][16] = false;
        USO_Booled[3][14] = true;
}

if(KSP_Booled[6][17]){ // И 18  - ТЕКУЩЕЕ ПОЛОЖЕНИЕ - ОТКЛ
   KSP_Booled[6][17] = false;
        USO_Booled[3][14] = false;
}

//--\\ КСПл - Линейка Ж \\--//

if(KSP_Booled[5][10]){  // KSP Ж11
   KSP_Booled[5][10] = false;
        // Выбираем канал БЦВК - А
        USO_Booled[3][2]  = true;   // Включаем только А, остальное в ноль
        USO_Booled[3][3]  = false;
        USO_Booled[3][4]  = false;
        USO_Booled[3][13] = false;
        JPS(1,is_argon,is_operator,"Выбран канал А","");

}

if(KSP_Booled[5][12]){  // KSP Ж13
   KSP_Booled[5][12] = false;
        // Выбираем канал БЦВК - Б
   /*     USO_Booled[3][3]  = true;
        USO_Booled[3][2]  = false;
        USO_Booled[3][4]  = false;
        USO_Booled[3][13] = false;
        JPS(1,is_argon,is_operator,"Выбран канал Б","");   */
}

if(KSP_Booled[5][14]){  // KSP Ж15
   KSP_Booled[5][14] = false;
   /*     // Выбираем канал БЦВК - В
        USO_Booled[3][4] = true;
        USO_Booled[3][2] = false;
        USO_Booled[3][3] = false;
        USO_Booled[3][13] = false;
        JPS(1,is_argon,is_operator,"Выбран канал В","");     */
}

//--\\ КСПл - Линейка К \\--//

if(KSP_Booled[7][16]) { // К 17
   KSP_Booled[7][16] = false;
        USO_Booled[4][8]=true;
        sp_d_k = 1; // Длинная самопроверка БЦВК
}

if(KSP_Booled[7][17]) { // К 18
   KSP_Booled[7][17] = false;
        USO_Booled[4][8]=false;
        sp_d_k = 0; // Короткая самопроверка БЦВК
}

//--\\ КСПл - Линейка Л \\--//

if(KSP_Booled[8][0]) { // Л1 - РО ДК
   KSP_Booled[8][0]=false;
        USO_Booled[1][1]=true;
}

if(KSP_Booled[8][1]) { // Л1 - РО ДК
   KSP_Booled[8][1]=false;
        USO_Booled[1][1]=false;
}

// КСПп - Линейка Т //

if(KSP_Booled[13][0]) { // Т 1
   KSP_Booled[13][0] = false;
        USO_Booled[7][6]=true;
        JPS(1,"\"Рассвет-М\" подключается к СЗИ.","","","");
}

// КСПп - Линейка Н //

if(KSP_Booled[13][2]) { // Н 3
   KSP_Booled[13][2] = false;
        USO_Booled[5][3]=true;
        JPS(1,"Подано питание на УКВ ПРМд","","","");
}

uso_change(USO_Booled);

}

#endif // USO_MDL
