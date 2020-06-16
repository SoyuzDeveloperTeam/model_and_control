//--------------------------------------------------------------------------------
// EdftType.h : header file
#ifndef FORMAT_TYPE_H
#define FORMAT_TYPE_H

//--------------------------------------------------------------------------------
typedef struct {
long   idFormat ;
long   idFormatIO ;
double Value ;
char*  String ;
} EDFClipdoardData ;
//--------------------------------------------------------------------------------
typedef struct {
long   idFormat ;
long   idFormatIO ;
double Value ;
char*  String ;
} EDFGridClipdoardDataItem ;
//--------------------------------------------------------------------------------
typedef struct {
int ka ;
int nom ;
int tip ;
int mod ;
int var ;
} NUKEYEDF ;
//--------------------------------------------------------------------------------
typedef struct {
int d ;
int m ;
int g ;
} DMYEDF ;
//--------------------------------------------------------------------------------
typedef struct {
int    h ;
int    m ;
double s ;
} HMSEDF ;
//--------------------------------------------------------------------------------
typedef struct {
int    g ;
int    m ;
double s ;
} GMSEDF ;
//--------------------------------------------------------------------------------
typedef struct {
double Value ;
int    Format ;
int    FormatIO ;
int    FormatMM ;
int    Dec ;
int    Len ;
char   Spr1 ;
char   Spr2 ;
int    Calendar ;
bool   FixedFields ;
char   FixedFirstField ;
char   FixedLastField ;
bool   SpaceLeftField ;
bool   Space ;
bool   Sign ;
bool   NotShowSign ;
bool   Interval ;
double Max ;
double Min ;
//
bool   ArrowKeys ;
int    TestValiVar ;
//
//EdfString TextDim ;
//EdfString TextName ;
//EdfString TextHint ;
} FormatProperty ;
//--------------------------------------------------------------------------------
typedef struct {
double Value ;
int    Format ;
int    FormatIO ;
int    FormatMM ;
int    Dec ;
int    Len ;
char   Spr1 ;
char   Spr2 ;
int    Calendar ;
bool   FixedFields ;
char   FixedFirstField ;
char   FixedLastField ;
bool   SpaceLeftField ;
bool   Space ;
bool   Sign ;
bool   NotShowSign ;
bool   Interval ;
double Max ;
double Min ;
//
bool   ArrowKeys ;
int    TestValiVar ;
//
char   TextDim [ 128 ] ;
char   TextName[ 128 ] ;
char   TextHint[ 128 ] ;
} FormatPropertySave ;
//--------------------------------------------------------------------------------
class EDFFont {
public :
  EDFFont( ) { //Name = "" ; 
	Size = SizeEx = isBold = isItalic = isUnderLine = 0 ; } 
  void Copy( EDFFont& F ) {
	//Name        = F.Name ;
	Size        = F.Size ;
	SizeEx      = F.SizeEx ;
	isBold      = F.isBold ;
	isItalic    = F.isItalic ;
	isUnderLine = F.isUnderLine ;
  } ;
  void Empty( ) {
	//Name        = "" ;
	Size        = 0 ;
	SizeEx      = 0 ;
	isBold      = 0 ;
	isItalic    = 0 ;
	isUnderLine = 0 ;
  } ;

  //EdfString  Name ;       // "" - �� �������� ;  "Courier" - ������ ����� "Courier"
  int        Size ;       // 0  - �� �������� ;  12 - 12 ������� ;
  int        SizeEx ;     // 0  - �� �������� ;  2  - �� 2 ������ ������ ������� ���������� ������ ;  -2 - �� 2 ������ ������ ... ;
  int        isBold ;     // 0  - �� �������� ;  1  - ������ ;     -1   - ��������
  int        isItalic ;   // 0  - �� �������� ;  1  - ������ ;     -1   - ��������
  int        isUnderLine ;// 0  - �� �������� ;  1  - ������ ;     -1   - ��������
} ;
//--------------------------------------------------------------------------------
#endif // #ifndef FORMAT_TYPE_H
