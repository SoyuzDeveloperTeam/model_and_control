//---------------------------------------------------------------------------
/*
  На основании модели КС-020 разработанной Журавлевым А.Г.
  Алгоритмы взяты из патента R U 40514 U 1

Type c_Double = Double;             Const _c_Double = _Double;
Type c_Float = Single;              Const _c_Float = _Single;
Type c_Long = Longint;              Const _c_Long = _Longint;
Type c_Ulong = Longint;             Const _c_Ulong = _Longint;
Type c_Short = integer;             Const _c_Short = _SmallInt;
Type c_Ushort = word;               Const _c_Ushort = _word;
Type c_Char = ShortInt;             Const _c_Char = _ShortInt;
Type c_uchar = Byte;                Const _c_uchar = _Byte;
*/
#ifndef ks020_modelH
#define ks020_modelH
//---------------------------------------------------------------------------

static const unsigned short SmallGlobusTraceWidth = 74; // Шаг для маленького глобуса
static const unsigned short S_Din_DeltaSize = 2; // 1 CRC + 1 Control
static const unsigned short S_Raz_DeltaSize = 3; // 1 CRC + 1 Control + 1 CN_S_Raz
static const unsigned short S_Din_MaxSize = 32*320-2;

// For MIL-1556 - Telemetry Model and DisKRY model

typedef enum{
_S_None,
_S_Fon,
_S_Din,
_S_Cont,
_S_Stat,
_S_Bd,
_S_Raz,
_R_None,
_R_Cont,
_R_Stat,
_R_Bd,
_R_A_16
}tmk_Packets;

typedef enum{
_s_None,
_s_Fon,
_s_Din,
_s_Cont,
_s_Stat,
_s_Bd,
_s_Raz
}tmk_S_Packets;

typedef enum{
_r_None,
_r_Cont,
_r_Stat,
_r_Bd,
_r_A_16
}tmk_R_Packets;


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

typedef ks_Fon_TypePrim ks_Fon_Type;
/*
  Данные вывода (массив а0-разовый)
*/
static unsigned short SmallGlobusTraceType[SmallGlobusTraceWidth-1];

typedef struct{
unsigned char z081;  // Долгота точки восхода (пикселы)
unsigned char z082;  // Долгота точки захода (пикселы)
}ks_Raz_a0_Type;

typedef struct{
  ks_Fon_Type Fon;
}ks_Fon_Record;

//AnsiString TransType_Str[6] = {"NoTrans","НавСближ","ОрбитНав","НавСпуск","ОпрВремя","ОпрБИЛУ"};

static const unsigned short Max_R_Cont_Size = 32-3; //Макс. размер вводимых данных:
                                             // -Упр слово массива
                                             // -Упр слово подмассива
                                             // -контр. сумма

enum{ksbNone,
/* 1 */ ksbMP,        // МП                          "ИНК"  (2Ф44)
/* 2 */ ksbSKD,       // СКД                         "БНО"  (2Ф45)
/* 3 */ ksbDPOBT,     // ДПО-БТ                      "БНО"  (2Ф45)
/* 4 */ ksbBD,        // Возврат к БД                "Транзит" (2Ф47)
/* 5 */ ksbRecAvail,  // Разрешение записи           "СА"   (2Ф25)
/* 6 */ ksbAP,        // АП                          "ИНК"  (2Ф44)
/* 7 */ ksCalibrBilu, // Калибровка БИЛУ             "БИЛУ" (2Ф19)
/* 8 */ ksZaprContIK, // Запрещение контроля ИК      "БИЛУ" (2Ф19)
/* 9 */ ksZaprJustIK  // Запрещение юстировки ИК     "БИЛУ" (2Ф19)
}TKsButtons;

#endif
