#ifndef ICN_header
#define ICN_header
#include "wtypes.h"
#include "vector.h"
// InPU Connect Data

static const unsigned long PacketSignatureR = 0x71AF5D13;  // Сигнатура пакета - packet signature

static struct {
long Signature;         // Сигнатура пакета - packet signature
unsigned short No;      // Номер пакета - packet number
unsigned short Size;    // Размер пакета - packet size
byte PacketID;          // PacketID - b
}PacketHeaderType;

typedef struct {
long Signature;         // Сигнатура пакета
unsigned short No;      // Номер пакета
unsigned short Size;    // Размер пакета
byte PacketID;          // PacketID - b
byte CodeType;
byte DataType1;
byte DataType2;
}TPacketHeader;

static struct {
int i;
byte a;
byte b;
} nupara;

static int arg_test_pr;

static struct {
byte CodeType;
unsigned short DataType;
}packett;

static struct {
byte smech;
} sm;

static struct {
byte time_A;
byte time_B;
byte time_C;
}DT;

static struct {
unsigned short CRC;
}PacketFooterType;

static unsigned short CounterNo;

typedef
enum {
    /* 01 */   sndNone,
    /* 02 */   sndWarning,
    /* 03 */   sndEmergency
} SoundType;

typedef
enum { idNone,
    /* 01 */   idData,            //
    /* 02 */   idChannels,        //
    /* 03 */   idStatus,          //
    /* 04 */   idControl,         //
    /* 05 */   id05,              //
    /* 06 */   idUso,             //
    /* 07 */   idDate,            //
    /* 08 */   idIdle,            //
    /* 09 */   idTime,            //
    /* 0A */   id_0A,             //
    /* 0B */   idSpsInfo,         //
    /* 0C */   idFullCalibration, //
               idLast}PacketIDtype ;
               
typedef
enum{       wpCodeNone,
    /* 01 */  wpCodePacketSet,
    /* 02 */  wp02,
    /* 03 */  wpResetStatus,
    /* 04 */  wpInpuOnFlag,
    /* 05 */  wpKey,
    /* 06 */  wp6,
    /* 07 */  wp7,
    /* 08 */  wpKpk,
    /* 09 */  wpKSP,
    /* 10 */  wpBRWI,
    /* 11 */  wpStartRemote,
    /* 12 */  wpEndRemote,
    /* 13 */  wpTimeKs020,
    /* 14 */  wpSirt,
    /* 15 */  wpScreenOff,
    /* 16 */  wp_10,
    /* 17 */  wpClearEprom,
    /* 18 */  wp12,
    /* 19 */  wpSound,
    /* 20 */  wpInpuOnOff,
    /* 21 */  wpPodgIp,
    /* 22 */  wpOpowOnOff,
    /* 23 */  wpPutTlm,
    /* 24 */  wpTimeRate,
    /* 25 */  wpGetSpsInfo,
    /* 26 */  wpSoundOffPressed,
    /* 27 */  wpReqestDateTime,
    /* 28 */  wpTransit,
    /* 29 */  wpBrwiOnAction,
    /* 30 */  wpAvailBo,
    /* 31 */  wpNipAvail,
    /* 32 */  wpStdAtmos,
    /* 33 */  wpFlag,
    /* 34 */  wpIshod,
    /* 35 */  wpCheckTS,
    /* 36 */  wpSoundSign,
    /* 37 */  wpSoundRes,
    /* 38 */  wpCalibrAcq,
    /* 39 */  wpLockPelengOff,
    /* 40 */  wpDoCopyCalibr,
    /* 41 */  wpBfiFormat,
          wpLast} wpControlCodeTypeN;

static enum{
bfiFormatNone,                       // Отсутствие формата
bfiFormat41,bfiFormat42,bfiFormat43, // Штатные форматы
bfiFormat44,bfiFormat45,bfiFormat46, // Штатные форматы
bfiFormatRus,                        // Формат РУС
bfiFormatBlack                       // Черный экран
}bfiFormatType;

#endif