#ifndef _main_header
#define _main_header
//---------------------------------------------------------------------------
/* Заголовки */


/* Директивы */
#define FullDebug              // Режим отладки

static struct{
int i;
}send_trus;

// ВНИМАНИЕ! МОДЕЛЬНАЯ ДАТА-ВРЕМЯ!!!
static TDateTime OnboardModelTime;
static TDateTime data_TSKD;
static TDateTime data_TSKD_m8 = StrToTime("00:08:00");

static String dOUT;
//static int fdh;
static int int_model;

//Half-flag's
static bool arg_half_false[166];
// 1 - Признак "Причаливание"

static bool pr_TSKD;  //Логический признак ТСКД
static AnsiString IrviStringRT;
//int i_takt;

static bool NUotr,      // Признак отработки НУ
     IdCanSend,  // True на момент передачи
     PuskPr;     // Признак выданной команды "ПУСК"
static AnsiString ver_num;
static AnsiString ActVer =
#ifdef FullDebug
"Debug"+ver_num
#else
"Build"+ver_num
#endif
;
static AnsiString SimType = "Отладочная модель";

static AnsiString MainDir = "C:\\Program Files\\SDT\\miu\\data";

// FOR USO SENDER //

static String S_00[4]; // USO SLOVO 00
static int STR_00;
static String S_01[4]; // USO SLOVO 01
static int STR_01;
static String S_02[4]; // USO SLOVO 02
static int STR_02;
static String S_03[4]; // USO SLOVO 03
static int STR_03;
static String S_04[4]; // USO SLOVO 04
static String S_05[4]; // USO SLOVO 05
static String S_06[4]; // USO SLOVO 06
static String S_07[4]; // USO SLOVO 07
static String S_08[4]; // USO SLOVO 08
static String S_09[4]; // USO SLOVO 09
static String S_0A[4]; // USO SLOVO 0A
static String S_0B[4]; // USO SLOVO 01
static String S_0C[4]; // USO SLOVO 01
static String S_0D[4]; // USO SLOVO 01
static String S_0E[4]; // USO SLOVO 01
static String S_0F[4]; // USO SLOVO 01
static String S_10[4]; // USO SLOVO 01
static int STR_10;
static String S_10_out;
static String S_11[4]; // USO SLOVO 01
static int STR_11;
static String S_12[4]; // USO SLOVO 01
static int STR_12;
static String S_13[4]; // USO SLOVO 01
static int STR_13;
static String BinA[4];
static char BinB[4];
static char BinC[4];
static char BinD[4];
static String Bin_USO_10[4];

static bool co_pr;    // Логический признак ЦО

// Для работы с эпохой J2000
// JD 2451545.0


#endif // _main_header
