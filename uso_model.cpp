#ifndef USO_MDL
#define USO_MDL
//---------------------------------------------------------------------------
#include "USOData.h"
#include "arg_header.h"
#include "JouHeader.h"
#include "JouStrings.h"
#include "MainFrm.h"
#pragma hdrstop

#include "uso_model.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

static int i_test;
bool d2b;


///////////////////////
// П Р О Ц Е Д У Р А //
// О Б Р А Б О Т К И //
//   Н А Ж А Т И Я   //
//   К Л А В И Ш И   //
//   К     С     П   //
///////////////////////


void USO_work(){

if(KSP_Booled[0][0]) { // A 1
// Временный алгоритм открытия крышки СКД (без проверки ПаО)
if(i_test==80) { // Время открытия 16 секунд = 16000 мс = 80 тактов по 200 мс
USO_Booled[0][0]=true;   //
JPS(1,"Крышка СКД открыта","","","");
KSP_Booled[0][0] = false;
i_test=0;
}else
i_test++;
}

if(KSP_Booled[0][1]) {  // A 2
if(i_test==80) {
USO_Booled[0][0]=false;
JPS(1,"Крышка СКД закрыта","","","");
KSP_Booled[0][1] = false;
i_test=0;
}else
i_test++;
}

if(KSP_Booled[0][2]) {  // A 3   Наддув КДУ - ВКЛ
// Вкл. пит. клапана наддува ЭПКН1 и ЭПКН2
KSP_Booled[0][2] = false;
USO_Booled[0][1]=true;
}

if(KSP_Booled[0][3]) {  // A 4   Наддув КДУ - ВЫКЛ
// Откл. пит. клап. наддува ЭПКН1, ЭПКН2
KSP_Booled[0][3] = false;
USO_Booled[0][1]=false;
}

if(KSP_Booled[0][4]) { // A 5     СДР ОТКЛ
KSP_Booled[0][4] = false;
// 98 - Исключение СДН (СДР) из схемы управления
USO_Booled[0][2]=true;
}

if(KSP_Booled[0][5]) { // A 6
KSP_Booled[0][5] = false;
// -98 - Подключение СДН (СДР) к схеме управления
USO_Booled[0][2]=false; }

if(KSP_Booled[0][6]) { // A 7
KSP_Booled[0][6] = false;
USO_Booled[0][3]=true;
}

if(KSP_Booled[0][7]) { // A 8
KSP_Booled[0][7] = false;
USO_Booled[0][3]=false;
}

if(KSP_Booled[0][8]) { // A 9 - Выбор ДПО-Б
// Команда в БА ДПО "Выбор ДПО-Б"
KSP_Booled[0][8] = false;
USO_Booled[0][4]=true;
}

// А9 - безотбойная

if(KSP_Booled[0][10]) { // A 11 - Выбор ДПО-М1
KSP_Booled[0][10] = false;
USO_Booled[0][5]=true;
}

// А13 - безотбойная

if(KSP_Booled[0][12]) {  // A 13
// Включаем ДПО №№ 2,4,6,8.10,12;
dpo_v_pr[2,4,6,8,10,12]=1;
USO_Booled[0][6]=true;
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
// 17.26 Команда в БСУ "ВКЛ ТЕСТ ДИСПЛЕЙ"
KSP_Booled[2][12]  = false;
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

if(KSP_Booled[3][0]) { // Г 1  Обогрев антен ВКЛ
KSP_Booled[3][0] = false;
// Так же выдаем по КО - перенести в операции по КО
// включается термостат обогрева антенн, который поддерживает
// заданный температурный режим механики антенн 2АО,АСФ1,АСФ2.
USO_Booled[1][11]=true;
}
if(KSP_Booled[3][1]) { // Г 2  Обогрев антен ВЫКЛ
KSP_Booled[3][1] =false;
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
KSP_Booled[3][12] = false;
}
if(KSP_Booled[3][14]) { // Г15
KSP_Booled[3][14] = false;
USO_Booled[1][13]=true;
USO_Booled[1][14]=true;
}

if(KSP_Booled[6][0]) { // И1   ЗДР
KSP_Booled[6][0] = false;
USO_Booled[3][6]=true;
}

if(KSP_Booled[6][1]) { // И2   РРП
KSP_Booled[6][1] = false;
USO_Booled[3][6]=false;
}

if(KSP_Booled[6][2]) { // И3 АКС
   KSP_Booled[6][2] = false;
   USO_Booled[3][7] = true;
   // Включаем питание БИЛУ + КС020
}

if(KSP_Booled[6][3]) { // И4 АКС
   USO_Booled[3][7] = false;
   KSP_Booled[6][3] = false;
}

if(KSP_Booled[6][8]) {  // И9 ПИТАНИЕ ЧАЙКИ
   KSP_Booled[6][8] = false;
   // Посылаем команду в БУМ
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
//apm=true; Признак запуска чайки
}

if(KSP_Booled[6][14]) { // И 15
// Выбираем все каналы АБВ для БЦВК
KSP_Booled[6][14] = false;
USO_Booled[3][2]  = false;  // Ж11 БЦВК а
USO_Booled[3][3]  = false;  // Ж13 БЦВК а
USO_Booled[3][4]  = false;  // Ж15 БЦВК а
USO_Booled[3][13] = true;   // И 15 АБВ
//(ДЛЯ ТЕСТА КСП - РАБОТАЕТ)
}

if(KSP_Booled[5][10]){  // KSP Ж11
KSP_Booled[5][10] = false;
// Выбираем канал БЦВК - А
USO_Booled[3][2]  = true;   // Включаем только А, остальное в ноль
USO_Booled[3][3]  = false;
USO_Booled[3][4]  = false;
USO_Booled[3][13] = false;
}

if(KSP_Booled[5][12]){  // KSP Ж13
KSP_Booled[5][12] = false;
USO_Booled[3][2]  = false;
USO_Booled[3][3]  = true;
USO_Booled[3][4]  = false;
USO_Booled[3][13] = false; }

if(KSP_Booled[5][14]){  // KSP Ж15
KSP_Booled[5][14] = false;
USO_Booled[3][2] = false;
USO_Booled[3][3] = false;
USO_Booled[3][4] = true;
USO_Booled[3][13] = false; }

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

if(KSP_Booled[8][0]) { // Л1 - РО ДК
KSP_Booled[8][0]=false;
USO_Booled[1][1]=true;
         // Разрешение отправки параметров ДК в БУМ
}

if(KSP_Booled[8][1]) { // Л1 - РО ДК
KSP_Booled[8][1]=false;
USO_Booled[1][1]=false;
d2b=false;           // Разрешение отправки параметров ДК в БУМ
}

if(KSP_Booled[13][0]) { // Т 1
KSP_Booled[13][0] = false;
USO_Booled[7][6]=true;
JPS(1,"\"Рассвет-М\" подключается к СЗИ.","","","");
}

if(KSP_Booled[13][2]) { // Н 3
KSP_Booled[13][2] = false;
USO_Booled[5][3]=true;
JPS(1,"Подано питание на УКВ ПРМд","","","");
}
}

#endif // USO_MDL
