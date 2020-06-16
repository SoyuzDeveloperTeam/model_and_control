// EdfStr.h 
#ifndef EDF_EDFSTR_CLASS_H
#define EDF_EDFSTR_CLASS_H
//--------------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iterator>
#include <vector>
#include <string>
using namespace std ;

//--------------------------------------------------------------------------------
#include <FlyTime.h>
#include <FlyFormat.h>

//--------------------------------------------------------------------------------
#include "EdfDef.h"
#include "EdfType.h"
#include "RGradTime.h"
#include "RMoment.h"
#include "RDate.h"

//--------------------------------------------------------------------------------
#pragma warning (disable: 4996) 
#pragma warning (disable: 4275) 
#pragma warning (disable: 4251) 
//--------------------------------------------------------------------------------
FLYFORMAT_API void CalcDecFromFormat(int oldFormat, int oldLen, int oldDec, int Interval, int newFormat, int& newLen, int& newDec);
//--------------------------------------------------------------------------------
FLYFORMAT_API bool IsValiDate(int d, int m, int g, int* errfield = 0);
FLYFORMAT_API bool IsValiTime(int h, int m, double s, int* errfield = 0, bool fromInterval = 0);
FLYFORMAT_API bool IsValiAngle(int g, int m, double s, int* errfield = 0, bool fromInterval = 0);
//--------------------------------------------------------------------------------
//int ReadSysSeparator    ( char& c, int var ) ;
//int ReadSysDecSeparator ( char& c ) ;
//int ReadSysDateSeparator( char& c ) ;
//int ReadSysTimeSeparator( char& c ) ;
//int ReadSysListSeparator( char& c ) ;
//--------------------------------------------------------------------------------
//int SaveRegBinary( char* Key1, char* Key2, void* data, int size ) ;
//int LoadRegBinary( char* Key1, char* Key2, void* data, int size ) ;
//--------------------------------------------------------------------------------
FLYFORMAT_API void FPTOFPS(FormatProperty& p, FormatPropertySave& ps);
FLYFORMAT_API void FPSTOFP(FormatPropertySave& ps, FormatProperty& p);
FLYFORMAT_API int  GetFirstField(int Format);
//--------------------------------------------------------------------------------
FLYFORMAT_API bool CalcDMVTime(double  TATime, int& D, int& M, int& G, int& H, int& Min, double& S);
FLYFORMAT_API bool CalcTATime(double& TATime, int  D, int  M, int  G, int  H, int  Min, double  S);
FLYFORMAT_API int  GetDecedField(int Format, int Dec);
//--------------------------------------------------------------------------------
#define tgk_zona 0.125

//--------------------------------------------------------------------------------
class FLYFORMAT_API CFormatString  {
public :
    CFormatString ( ) ;
	CFormatString ( const CFormatString& F ) ;
   ~CFormatString ( ) ;
    void Clone( const CFormatString& F ) ;
    // Создание шаблона формата редактируемого параметра
    void FormatedType( int TypeFormat, double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void Formated    ( int Format, double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    //
    void FormatedNumber     ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedFixed      ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedFloat      ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedInt        ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedBool       ( double Value = 0 ) ;
    void FormatedBoolYN     ( double Value = 0 ) ;
    void FormatedBoolIns    ( double Value = 0 ) ;
    void FormatedBool01     ( double Value = 0 ) ;
    void FormatedDate       ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedDateTime   ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedGrad       ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedRad        ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedGMS        ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedVitGrad    ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedVitRad     ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedVitGMS     ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedTime       ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedTimeHMS    ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedTimeSSSHMS ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedTimeMiliSec( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedTimeSec    ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedTimeMin    ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedTimeHour   ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    void FormatedTimeSSS    ( double Value = 0, int FormatIO = EDF_NOTFORMAT ) ;
    // Создание шаблона ключей НУ
    void FormatedKeyNu      ( double Value = 0, bool isFull = 1 ) ;
    // Создание шаблона произвольного набора ключей
    void FormatedCustomKey  ( int* Len, int KeyCount, int* Key = 0 ) ;
    // Создание шаблона выбора альтернативы
    void FormatedAlt        ( char** AltString, int AltCount, double Value = 0 ) ;
    void FormatedAlt        ( vector<EdfString>& AltString, double Value = 0 ) ;
#if defined(_MFC_VER) || defined(INC_VCL)
    void FormatedAlt        ( vector<string>& AltString, double Value = 0 ) ;
#endif
    //
    // Формат редактируемого параметра
    bool SetFormat( int Format, bool isUpdate = 1 ) ;
    int  GetFormat( ) ;
    // Формат обмена данными с элементом редактирования
    bool SetFormatIODefault( ) ;
    bool SetFormatIO( int Format ) ;
    int  GetFormatIO( ) ;
	//
    int  GetTypeFormat ( int Format =-1 ) ;
    // Полный набор свойств и форматов элемента редактирования
    void GetFormatProperty( FormatProperty& ) ;
    void SetFormatProperty( FormatProperty& ) ;
    // Изменение отдельных свойств формата
    bool SetDec            ( int  Dec ) ;
    int  GetDec            ( ) ;
    bool SetLen            ( int  Len ) ;
    int  GetLen            ( ) ;
    bool SetKeyNULenKa     ( int  Len ) ;
    int  GetKeyNULenKa     ( ) ;
    bool SetKeyNULenNom    ( int  Len ) ;
    int  GetKeyNULenNom    ( ) ;
    void SetSign           ( bool Sign ) ;
    bool GetSign           ( ) ;
    void SetNotShowSign    ( bool NotShowSign ) ;
    bool GetNotShowSign    ( ) ;
    void SetInterval       ( bool Interval ) ;
    bool GetInterval       ( ) ;
    void SetFixedFields    ( bool FixedFields ) ;
    bool GetFixedFields    ( ) ;
    void SetFixedFirstField( bool FixedFirstField ) ;
    bool GetFixedFirstField( ) ;
    void SetFixedLastField ( bool FixedLastField ) ;
    bool GetFixedLastField ( ) ;
    void SetSeparator      ( char c ) ;
    char GetSeparator      ( ) ;
    void SetSeparatorDec   ( char c ) ;
    char GetSeparatorDec   ( ) ;
    void SetLongSeparator  ( bool LongSeparator ) ;
    bool GetLongSeparator  ( ) ;
    // Максимальное и минимальное значение редактируемого параметра в формате "FormatMM"
    void GetMaxMin ( double& Max, double& Min, int& Format ) ;
    void SetMaxMin ( double  Max, double  Min, int  Format = EDF_NOTFORMAT ) ;
    // Текстовая строка
    char* GetText  ( ) ;
    bool  SetText  ( char*, int* dl = 0 ) ;
    bool  SetText  ( EdfString& s ) { return( SetText( EdfPointString( s ), 0 ) ) ; } ;
	int	  GetDataText(char* s) ;
	int   GetTimeText(char* s) ;
//#if defined(_MFC_VER) || defined(INC_VCL)
//    bool  SetText  ( string& s ) { return( SetText( ( char* )s.c_str( ), 0 ) ) ; } ;
//#endif
    // Значение редактируемого параметра в формате "FormatIO"
    bool    SetValue ( double, int FormatIO = EDF_NOTFORMAT ) ;
    double  GetValue ( int FormatIO = EDF_NOTFORMAT ) ;
    bool    SetDate  ( const DATE& d ) ;
    DATE   GetDate  ( ) ;
    bool    SetTime  ( const TIME& t ) ;
    TIME   GetTime  ( ) ;
    bool    SetDateTime( const DATE& d, const TIME& t ) ;
    bool    GetDateTime( DATE& d, TIME& t ) ;
	//----------------------------------------------------------------------------
    void operator >> ( double&       x ) { x = GetValue( ) ; }
    void operator << ( const double& x ) { SetValue( x ) ; }
    void operator >> ( float&        x ) { x = ( float )GetValue( ) ; }
    void operator << ( const float&  x ) { SetValue( x ) ; }
    void operator >> ( long&         x ) { x = ( long )GetValue( ) ; }
    void operator << ( const long&   x ) { SetValue( x ) ; }
    void operator >> ( short&        x ) { x = ( short )GetValue( ) ; }
    void operator << ( const short&  x ) { SetValue( x ) ; }
    void operator >> ( int&          x ) { x = ( int )GetValue( ) ; }
    void operator << ( const int&    x ) { SetValue( x ) ; }
    void operator >> ( DATE&        x ) { x = GetDate( ) ; }
    void operator << ( const DATE&  x ) { SetDate( x ) ; }
    void operator >> ( TIME&        x ) { x = GetTime( ) ; }
    void operator << ( const TIME   x ) { SetTime( x ) ; }
    //----------------------------------------------------------------------------
    void operator >> ( char* s ) { sprintf( s, "%s\0", GetText( ) ) ; }
    void operator << ( const char* s ) { SetText( ( char* )s ) ; }
    void operator >> ( EdfString& s ) { s = GetText( ) ; }
    void operator << ( const EdfString& s ) { SetText( EdfPointString( s ) ) ; }
#if defined(_MFC_VER) || defined(INC_VCL)
    void operator >> ( string& s ) { s = GetText( ) ; }
    void operator << ( const string& s ) { SetText( ( char* )s.c_str( ) ) ; }
#endif
	//----------------------------------------------------------------------------
	double operator = ( const double& x ) { SetValue( x ) ; return m_Value ; }
	float  operator = ( const float&  x ) { SetValue( x ) ; return ( float )m_Value ; }
	short  operator = ( const short&  x ) { SetValue( x ) ; return ( short )m_Value ; }
	long   operator = ( const long&   x ) { SetValue( x ) ; return ( long  )m_Value ; }
	int    operator = ( const int&    x ) { SetValue( x ) ; return ( int   )m_Value ; }
    void   operator = ( const char*   s ) { SetText( ( char* )s ) ; }
    void   operator = ( const EdfString& s ) { SetText( EdfPointString( s ) ) ; }
#if defined(_MFC_VER) || defined(INC_VCL)
    void   operator = ( const string& s ) { SetText( ( char* )s.c_str( ) ) ; }
#endif
	//----------------------------------------------------------------------------
	operator double ( ) {  double x = GetValue( ) ; return x ; } 
	operator float  ( ) {  float  x = ( float )GetValue( ) ; return x ; } 
	operator short  ( ) {  short  x = ( short )GetValue( ) ; return x ; } 
	operator long   ( ) {  long   x = ( long  )GetValue( ) ; return x ; } 
	operator int    ( ) {  int    x = ( int   )GetValue( ) ; return x ; } 
	operator char*  ( ) {  return ( GetText( )  ) ; } 
	//----------------------------------------------------------------------------
    int    GetAltCount    ( ) ;
    void   SetAltCount    ( int AltCount ) ;
    int    GetAltCountDrop( ) ;
    void   SetAltCountDrop( int AltCountDrop ) ;
	char*  GetAltText     ( int index ) ;
	//----------------------------------------------------------------------------
    //
    bool   SetValueSign   (  double s ) ;
    bool   ChangeValueSign( ) ; 
    // гггммдд.0 Только для EDF_DMY
    double GetDMYPK ( int TypePK = 0 ) ;         
    void   GetDMYPK ( char* s, int TypePK = 0 ) ;
    void   SetDMYPK ( double, int TypePK = 0 ) ;
    void   SetDMYPK ( char*, int TypePK = 0  ) ;
    // ччммсс,dddddd Только для EDF_DMYHMS и всех форматов времени
    double GetHMSPK ( ) ;        
    void   SetHMSPK ( double ) ;
    // Только для EDF_DMY и EDF_DMYHMS
    DMYEDF GetDMY   ( ) ;
    void   SetDMY   ( DMYEDF ) ;
    // Только для EDF_DMYHMS и всех форматов времени
    HMSEDF GetHMS   ( ) ;        
    void   SetHMS   ( HMSEDF ) ;
    // Только для форматов угловых величин
    GMSEDF GetGMS   ( ) ;        
    void   SetGMS   ( GMSEDF ) ;
    // Только для EDF_DMYHMS
    void   GetDMYHMS( DMYEDF& d, HMSEDF& t ) ;
    void   SetDMYHMS( DMYEDF  d, HMSEDF  t ) ;
    // кккнннттммбб.0 Только для EDF_KEYNU и EDF_KEYNUFULL
    double GetNuKeyPK( ) ;
    void   SetNuKeyPK( double ) ;
    // Только для EDF_KEYNU и EDF_KEYNUFULL
    NUKEYEDF GetNuKey( ) ;
    void     SetNuKey( const NUKEYEDF& k ) ;

	//void GetNuKey( _KEY_NU& K ) ;
	//void SetNuKey( const _KEY_NU& K ) ;
    //
    //void SetCustomKey( int* Key ) ;
    //void GetCustomKey( int* Key ) ;
    //
    // Код ошыбки последней проверки корректности данных  
    int  GetCheckingCode( ) { return m_CheckingCode ; }
    void SetCheckingCode( int Code ) { m_CheckingCode = Code ; }
    // Код ошыбки последней установки данных  
    int  GetBuildCode( ) { return m_BuildCode ; }
    // Проверка корректности данных
    bool Checking       ( int* Field = 0, int* inMaxMin = 0 ) ;
    bool CheckingFields ( ) ;
    bool CheckingMaxMin ( ) ;
    // Установка режима автоматического отображения изменений формата
    // По умолчанию - включён
    void SetAutoChangeApply( bool isAutoChangeApply ) ;
    bool GetAutoChangeApply( ) ;
    // Обновить текстовую строку в соответствии с введёнными изменениями формата
    void FormatChangeApply ( bool isForce = 1 ) ;
    //
protected :
    bool CheckingFieldsInEditTime( bool isFast = 0 ) ;
    void PostFormated( FormatProperty& p, double Value, int FormatIO ) ;
	void Init( ) ;
	//
public :
    // Создание шаблона формата редактируемого параметра
    // Число
    void FormatedNumber      ( FormatProperty& p ) ;
    void FormatedFixed       ( FormatProperty& p ) ;
    void FormatedFloat       ( FormatProperty& p ) ;
    // Целое
    void FormatedInt         ( FormatProperty& p ) ;
    // Битовое значение
    void FormatedBool        ( FormatProperty& p ) ;
    void FormatedBoolYN      ( FormatProperty& p ) ;
    void FormatedBoolIns     ( FormatProperty& p ) ;
    void FormatedBool01      ( FormatProperty& p ) ;
    void FormatedCheck       ( FormatProperty& p, int Var ) ;
    // Дата   Дата-время
    void FormatedDate        ( FormatProperty& p ) ;
    void FormatedDateTime    ( FormatProperty& p ) ;
    // Угловые величины
    void FormatedGrad        ( FormatProperty& p ) ;
    void FormatedRad         ( FormatProperty& p ) ;
    void FormatedGMS         ( FormatProperty& p ) ;
    void FormatedVitGrad     ( FormatProperty& p ) ;
    void FormatedVitRad      ( FormatProperty& p ) ;
    void FormatedVitGMS      ( FormatProperty& p ) ;
    // Временные параметры
    void FormatedTime        ( FormatProperty& p ) ;
    void FormatedTimeHMS     ( FormatProperty& p ) ;
    void FormatedTimeSSSHMS  ( FormatProperty& p ) ;
    void FormatedTimeMiliSec ( FormatProperty& p ) ;
    void FormatedTimeSec     ( FormatProperty& p ) ;
    void FormatedTimeMin     ( FormatProperty& p ) ;
    void FormatedTimeHour    ( FormatProperty& p ) ;
    void FormatedTimeSSS     ( FormatProperty& p ) ;
    // Набор ключей НУ
    void FormatedKeyNu       ( FormatProperty& p, bool isFull ) ;
    // Произвольный набор ключей
    void FormatedCustomKey   ( FormatProperty& p ) ;
    //
protected :
    void ChangeIP              ( int, int ) ;
public :
    void BuildFromData         ( ) ;
    bool BuildFromString       ( char* str = 0, int* dl = 0, bool TestLeftZero = 0, bool TestRightZero = 1, bool isNotSetText = 0 ) ;
    bool BuildFieldsFromString ( char* str = 0, int* dl = 0, bool TestLeftZero = 0 ) ;
    void BuildSubString        ( int, char*, bool TestRightZero = 1 ) ;
    void BuildTamplete         ( ) ;
    void BuildTampleteCustomKey( int* Len = 0, int KeyCount = 0 ) ;
    void BuildStringFromFields ( bool TestRightZero = 1 ) ;
    void BuildFieldsFromData   ( ) ;
    bool BuildValue            ( int& inMaxMin, char* Text = 0, int Flag = 0 ) ;
    bool BuildValueFromFields  ( int& inMaxMin ) ;
protected :
    void TestFildTamplete      ( int i ) ;
    bool FieldMaxMin           ( int, double&, double& ) ;
    void CalcNS                ( int m_Len, int& dl ) ;
    void CalcNS1               ( int m_Len, int& dl ) ;
    //
    void  SetAltString( char** AltString, int AltCount, int AltCountDrop = 12 ) ;
	void  SetAltString( vector<EdfString>& AltString, int AltCountDrop = 12 ) ;
#if defined(_MFC_VER) || defined(INC_VCL)
	void  SetAltString( vector<string>& AltString, int AltCountDrop = 12 ) ;
#endif
    void  DelAltString( ) ;
    //
    void  SetFieldsValue( int* Fields ) ;
    void  GetFieldsValue( int* Fields ) ;
public :
    // Проверка корректности введённой величины
    bool  IsValiValue ( int& Field, int& inMaxMin, int Flag = 0 ) ;
    bool  IsValiField ( int& Field ) ;
    int   IsValiMaxMin(  ) ;
    //
protected :
    void  SetFild ( double ) ;
    int   GetFild ( int pos ) ;
    int   GetDFild( int pos ) ;
    void  ValiPos ( int f = 0, int pos =-1 ) ;
    int   GetPos  ( int& pos ) ;
    void  SetPos  ( int pos  ) ;
    bool  NextPrevField( bool np ) ;
    //
    static bool isSysSetLoad ;
    static char SysSepDec ;
    static char SysSepDate ;
    static char SysSepTime ;
    static char SysSepList ;
    //
    char   m_Text[ 256 ] ;    // Текстовая строка для отображения
    int    m_Pos ;            // позиция курсора
    int    m_s ;              // Признак знака
    int    m_np ;             // число полей
    int    m_ip[ 2 ][ 7 ] ;   // граници полей
    int    m_lp[ 7 ] ;        // максимальная длина полей
    double m_f [ 7 ] ;        // значение полей
    bool   m_fp[ 7 ] ;        // признак фиксированной длины
    bool   m_bisNeedSetText ; //
    // Даные для работы с выбором альтернатив
    char** m_AltString ;
    int    m_AltCount ;
    int    m_AltCountDrop ;
    double m_Value ;
    int  m_Dec ;
    int  m_Len ;
    char m_Spr1 ;
    char m_Spr2 ;
    int  m_Format ;
    int  m_FormatIO ;
    int  m_FormatMM ;
    int  m_Calendar ;
    bool m_FixedFields ;
    char m_FixedFirstField ;
    char m_FixedLastField ;
    bool m_SpaceLeftField ;
    bool m_Space ;
    bool m_Sign ;
    bool m_NotShowSign ;
    bool m_Interval ;
    double m_Max ;
    double m_Min ;
    //
    bool  m_bErrorSetFocus ;
    int   m_NewField ;
    int   m_OldField ;
    //
    unsigned long m_BindFlag ;
    bool  m_isAutoChangeApply ;
    //
    int  m_UndoBufSize ;
    //
    bool m_ArrowKeys ;
    int  m_TestValiVar ;
    bool m_ValiSetData ;
    //
    bool m_isRO ;
    int  m_CheckingCode ;
    int  m_BuildCode ;
    int  dl_BuildFromText ;
    //
    virtual void Beep( ) { }
    //
public :
    virtual void  SetEditText ( ){ }
    virtual void  GetEditText ( ){ }
    virtual void  SetEditSel  ( int  start, int  end ) { }
    virtual void  GetEditSel  ( int& start, int& end ) { start = end = 0 ; }
    virtual void  SetEditHint ( char* TextHint )       { }
    virtual char* GetEditHint ( )                      { return 0 ; }
    virtual void  SetEditName ( char* Name )           { }
    virtual char* GetEditName ( )                      { return 0 ; }
    virtual void  SetEditDim  ( char* Dim )            { }
    virtual char* GetEditDim  ( )                      { return 0 ; }
    virtual void  SetEditFocus( void )                 { }
    virtual void  SetLabels   ( char* Name, char* Dim = 0, char* Hint = 0 ) {
		if ( Name ) SetEditName( Name ) ;
		if ( Dim  ) SetEditDim ( Dim ) ;
		if ( Hint ) SetEditHint( Hint ) ;
    }
} ;

//--------------------------------------------------------------------------------
FLYFORMAT_API void operator << (double& d, CFormatString& FS);
FLYFORMAT_API void operator >> (double& d, CFormatString& FS);
FLYFORMAT_API void operator << (float&  d, CFormatString& FS);
FLYFORMAT_API void operator >> (float&  d, CFormatString& FS);
FLYFORMAT_API void operator << (short&  d, CFormatString& FS);
FLYFORMAT_API void operator >> (short&  d, CFormatString& FS);
FLYFORMAT_API void operator << (long&   d, CFormatString& FS);
FLYFORMAT_API void operator >> (long&   d, CFormatString& FS);
FLYFORMAT_API void operator << (int&    d, CFormatString& FS);
FLYFORMAT_API void operator >> (int&    d, CFormatString& FS);
FLYFORMAT_API void operator << (DATE&  d, CFormatString& FS);
FLYFORMAT_API void operator >> (DATE&  d, CFormatString& FS);
FLYFORMAT_API void operator << (TIME&  d, CFormatString& FS);
FLYFORMAT_API void operator >> (TIME&  d, CFormatString& FS);

//--------------------------------------------------------------------------------
class ZString{
public: 
	ZString() {

	}
	~ZString() {

	}

	operator char*   () { return((char*)s.c_str()); }
	operator string* () { return &s; }
	operator string& () { return s; }
	char* Get() const {	return((char*)s.c_str()); }
	void  Set(const char* cs) { s = cs ? cs : ""; }

private:
	string s;
};
	
FLYFORMAT_API ZString& operator << (ZString& s, const char* cs);
FLYFORMAT_API ZString& operator >> (ZString& s, char* const cs);

//--------------------------------------------------------------------------------
FLYFORMAT_API int GetDeCEdfWinield(int Format, int Dec);
//--------------------------------------------------------------------------------
#endif  // #ifndef EDF_EDFSTR_CLASS_H
