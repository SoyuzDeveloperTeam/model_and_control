/*
  USO Data Head File (UDHF)
  Файл Данных УСО

  ---------

  В Паскале массив сигнализаторов - UsoBuffer:array[0..$13] of Word

  Слово 5 Бит 11($B)
  номер бита $5B

  ---------
  В файле COMMON.INC мы явно видим в самом начале

  Type
    USO_BitType = 0..15;         // Непосредственно массив Бит
    USO_AddrType    = 0..$13;    // Массив слова
    USO_BitAddrType = 0..$13F;
    USO_AddrTypeMain = 0..$0F;
    USO_BufferType = packed array[USO_AddrType] of Word;
    USO_BufferPtr = ^USO_BufferType;
    USO_BufferTypeMain = packed array[USO_AddrTypeMain] of Word;


  т.е. мы имеем 20-ти членный массив
*/
#ifndef _USO_data
#define _USO_data
static unsigned short USO_BT[20];    // Array

static bool argon_takt_pr; // Признак включения Аргона от УСО (ПО КСП)

static bool ruo_pr[6];
static bool rud_pr[6];

//------------------------------------
// For KSP - Letter and Number
static bool KSP_Let[17];  // 17 - потому что отсчет начинается с единицы

//------------------------------------
// Для ПРВИ

static unsigned short USO_BitType[20][4];
static bool USO_Booled[20][16];      // Основной массив для работы с УСО - Факт-квитанция о исполнении команды
static bool KSP_Booled[16][9];       // Массив выдачи команд с КСП (факт выдачи команды с КСП [LETTER] [NUMBER])
/* KSP_Booled
[00] [0 - 8]  А
[01] [0 - 8]  Б
[02] [0 - 8]  В
[03] [0 - 8]  Г
[04] [0 - 8]  Д
[05] [0 - 8]  Ж
[06] [0 - 8]  И
[07] [0 - 8]  К
[08] [0 - 8]  Л
[09] [0 - 8]  Н
[10] [0 - 8]  О
[11] [0 - 8]  П
[12] [0 - 8]  Р
[13] [0 - 8]  С
[14] [0 - 8]  Т
[15] [0 - 8]  У
[16] [0 - 8]  Ф     */
/*
   15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
00
01
02
03
04
05
06
07
08
09
10
11
12
13
14
15
16
17
18
19
*/

static char TableMask[2] = {'.','I'};        // Mask for USO Table Matrix    //

/*
  Логика работы КСП с точки зрения УСО

  - Оператор выдаёт команды (Буква (bool KSP_Let[] и цифра), после чего в
  зависимости от Let\Num выставляется признак KSP_Booled[].
  - В модуле uso_model в главной процедуре обработки всех команд от КСП в
  зависимости от команды КСП и нкоторый второстепенных признаков
  выставляется соответствующее значение для USO_Booled[].
*/



#endif //_USO_data


