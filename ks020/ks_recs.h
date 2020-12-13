#ifndef ks_recs
#define ks_recs

typedef struct{
  unsigned short z1161;  // Nmax - Максимальная перегрузка      десятые g0  0..999
  unsigned short z1162;
  unsigned short z1163;
  unsigned short z1166;
}TRaz_02;

//  массив ввода         - TInp_##
//  разовый массив       - TRaz_## (Всегда наследует (TInp_##))
//  динамический массив  - TDin_##

static const unsigned short SmallGlobusTraceWidth = 74; // Шаг для маленького глобуса
static const unsigned short S_Din_DeltaSize = 2; // 1 CRC + 1 Control
static const unsigned short S_Raz_DeltaSize = 3; // 1 CRC + 1 Control + 1 CN_S_Raz
static const unsigned short S_Din_MaxSize = 32*320-2;
static const int TraceArrayLength = 100;

enum{
SmallGlobus_No, //0 -  фоновая
BigGlobus_No,   //1 -  ИНК
BNO_No,         //2 -  БНО
AUS_No,         //3 -  АУС
RUS_No,         //4 -  РУС
VC_No,          //5 -  ВЕКТОР
Spusk_No,       //6 -  СПУСК
SA_No,          //7 -  СА
Nip_No,         //8 -  НИП
Transit_No,     //9 -  ТРАНЗИТ
Manevr_No,      //10 - МАНЕВР
Kontr_No        //11 - КОНТР
#ifdef Bilu
,Bilu_No        //12 - БИЛУ
#endif
}ksFormats;

static unsigned short SmallGlobusTraceType[SmallGlobusTraceWidth-1];

/*
  Фоновая инфорация.
  Данные вывода (массив а1-фоновый) 8 слов
*/

typedef struct{
short LongDeg;             // z150 - долгота подспутниковой точки
short LatDeg;              // z151 - широта подспутниковой точки
unsigned short LongPix;    // z180 - долгота подспутниковой точки (пикселы)
unsigned short RadioH;     // z170 - часы времени зоны РВ
unsigned short RadioM;     // z181 - минуты  времени зоны РВ
unsigned short RadioS;     // z182 - секунды времени зоны РВ
unsigned short SunH;       // z171 - часы времени восхода-захода
unsigned short SunM;       // z183 - минуты  времени восхода-захода
unsigned short SunS;       // z184 - секунды времени восхода-захода
unsigned short z185;       // z185 - сообщение о ВС
unsigned short z186;       // z186 - сообщение
unsigned short z187;       // z187 - сообщение
unsigned short DetachSign; // z188 - признак разделения
}ks_Fon_TypePrim;

#endif //ks_recs
 