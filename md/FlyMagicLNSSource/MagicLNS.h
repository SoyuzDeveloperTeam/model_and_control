//-----------------------------------------------------------------------------
// MagicLNS.h 
// А. Николенко 04.10.2018
//-----------------------------------------------------------------------------
#ifndef MAGIC_LNS_H
#define MAGIC_LNS_H

//-----------------------------------------------------------------------------
//#define ESTIMATE_BH_AS_UH

//-----------------------------------------------------------------------------
#define MKN_NIMP_1			1
#define MKN_NIMP_2			2
#define MKN_NIMP_3			3
//
#define MKN_KS_YANTAR		0
#define MKN_KS_KONDOR		1
#define MKN_KS_ARAKS		2
//
#define SPO_ORB_EL			0
#define SPO_ORB_HBH			1
#define SPO_ORB_OMIV		2
#define SPO_ORB_DU			3
#define SPO_ORB_ELSS		4
#define SPO_ORB_HBHSS		5
#define SPO_ORB_OMIVSS		6
#define SPO_ORB_DUSS		7
//
#define SPO_NOTBUILD		0
#define SPO_VARIDPAR_T		1
#define SPO_VARIDPAR_H		2
#define SPO_VARIDPAR_dL		3
#define SPO_VARIDPAR_i		4
#define SPO_VARIDPAR_a		5
//
#define SPO_VARH_MIN		0
#define SPO_VARH_MAX		1
#define SPO_VARH_MID		2
//
#define MKN_PARAM_ORB_t		8192
#define MKN_PARAM_ORB_T		1
#define MKN_PARAM_ORB_L		2
#define MKN_PARAM_ORB_u		4096
#define MKN_PARAM_ORB_dL	4
#define MKN_PARAM_ORB_hs	8
#define MKN_PARAM_ORB_hmax	16
#define MKN_PARAM_ORB_hmin	32
#define MKN_PARAM_ORB_Bh	64
#define MKN_PARAM_ORB_e		128
#define MKN_PARAM_ORB_w		256
#define MKN_PARAM_ORB_a		512
#define MKN_PARAM_ORB_e1	1024
#define MKN_PARAM_ORB_e2	2048
#define MKN_PARAM_ORB_e12	3072

#define M_MAXPU_SIZE 24

#include <FlyCoreSource\ZCDU.h>
#include <assert.h>

// Перечисление типов проектируемых орбит
enum ZESpoOrbType {
	SpoEl=0,   SpohBh=1,   SpoOmiv=2,   SpoDu=3, 
	SpoElSS=4, SpohBhSS=5, SpoOmivSS=6, SpoDuSS=7,
	SpoSh=8,   SpoShSS=9
};

//-----------------------------------------------------------------------------
// Параметры решения задачи методом узловых точек
// Struct (S) LNS Node points method (Npm) Parameterization (Par)
//-----------------------------------------------------------------------------
struct ZSLnsNpmPar {
  int	 maxIter = 50;	 // Максимальное число итераций
  // Точностные характеристики итерационного процесса расчёта параметров 
  // управления движением центра масс методом узловых точек
  double epsT = 0.001,   // сек
		 epsL = 0.001,   // град
		 epsdL= 0.0001,  // град / сут
		 epsu = 0.001,   // град
		 epsH = 0.0001,  // км
		 epsBH= 0.01,    // град
		 epsa = 0.00001, // км
		 epse = 0.0001,  //
		 epsw = 0.1;     // град

  bool   IsValiFaze ;
  char	 isEstimateOrb    = 0,	// признак уточнения формы орбиты на итерациях
		 isEstimateOrb_e12= 1,	// Признак уточнения вектора эксцентриситета
		 isEstimateOrb_e  = 1,	// Признак уточнения эксцентриситета
		 isEstimateOrb_w  = 1,	// Признак уточнения положения перигея
		 isEstimateOrb_h  = 1,	// Признак уточнения экстремальной высоты
		 isEstimateOrb_Bh = 1,	// Признак уточнения широты экст. высоты
		 Epoha    = 2,	// Признак эпохи.	
		 // Размерности различных параметров при документировании и отображении.
		 ViewDimT = 0,	// Размерность периода для документирования.
		 ViewDimL = 1,	// Размерность долготы для документирования.
		 ViewDimdL= 1,	// ... анологично размерности других параметров 
		 ViewDimw = 1,	// подлежащих документированию.
		 ViewDimBh= 1,	// ...
		 ViewDimu = 1,	//
		 ViewDimdV= 0,	// Размерность импульса скорости метры или км в секунду.
		 ViewDimdt= 0,	// Размерность длительности импульса.
		 // Сохранение результатов решения
		 RezSaveNU    = 2,	// Вариант сохранения НУ 
		 RezSaveNUNom = 1,	//
		 RezSaveNUMod = 0,	//
		 RezSavePULast= 1,	// Признак сохранения расчитанной прог. управления
		 RezUseLHS    = 0,
		 RezSaveFOFrom  = 1,
		 RezSaveFODbl   = 0,
		 // Параметризация документирования результатов решения задачи 
		 // коррекции методом узловых точек
		 RezSaveDocFull = 1,    // Признак формирования полного документа.
		 RezSaveDocDsk  = 1,    // Документирование описания задачи.
		 RezSaveDocDU   = 0,    // Док-е характеристик двигательной установки.
		 RezSaveDocLHS  = 1,    // Док-е логической шкалы сил.
		 RezSaveDocLHSShort = 0,// Сокращённое документирование ЛШС.
		 RezSaveDocINU  = 1,	// Док-е исходных НУ.
		 RezSaveDocINUShort = 0,// Сокращённое документирование исходных НУ.
		 RezSaveDocNUR  = 1,	// Документирование НУ с РИК.
		 RezSaveDocNURShort = 0,// Сокращённое документирование НУ с РИК.
		 RezSaveDocRV   = 1,	// Док-е параметров движения.
		 RezSaveDocPU   = 1,	// Док-е расч-ой программы управления.
		 RezSaveDocFO   = 1,	// Док-е форм обмена БИ.
		 RezSaveDocSVER = 1;	// Документирование шаблона для сверки.
  int	 RezUseLHSNum = 1;		// Используемый по умолчанию номер ЛШС
};

FLYMAGICLNS_API void DefaultParam(ZSLnsNpmPar& P);

//-----------------------------------------------------------------------------
// Исходные данные для решения задачи
// Class (C) LNS Node points method (Npm) Job
class FLYMAGICLNS_API ZCLnsNpmJob {
public :
  ZCLnsNpmJob() { } ;
 ~ZCLnsNpmJob() { } ;

  long& KA () { return( ka [ValiKS()]) ; } ;
  int&  ORB() { return( orb[ValiKS()]) ; } ;
  int&  VAR() { return( var[ValiKS()]) ; } ;
  int&  DU () { return ndu; }
  double& M( int Ks=-1 ) {
    int iks = Ks >= 0 ? Ks : ValiKS( ) ;
    int oldks = ks ; ks = iks ;
    int it = TASK( ) ; ks = oldks ;
    if ( it ) return( m[ iks ] ) ;
    else return( TestM[ iks ] ) ;
  }
  double& P( int Ks=-1 ) {
    int iks = Ks >= 0 ? Ks : ValiKS( ) ;
    int oldks = ks ; ks = iks ;
    int it = TASK( ) ; ks = oldks ;
    if ( it ) return( p[ iks ] ) ;
    else return( TestP[ iks ] ) ;
  }
  // Число импульсов задания
  int COUNTIMP( int Var =-1, int Orb =-1 ) {
    int iv = Var >= 0 ? Var : VAR( ) ;
    int io = Orb >= 0 ? Orb : ORB ( ) ;
    int it = TASK( iv, io ) ;
    int ii = (int)(it/10.0) ;
    ii = ii ? ii : TestNImp[ ks ] ;
    return ii ;
  }
  int*    KEYNU ( ) { return( TASK( ) ? keynu[ ValiKS( ) ] : TestKeyNU[ ValiKS( ) ] ) ; }
  int&    VIT   ( ) { return( TASK( ) ? vit[ ValiKS( ) ] : TestZVit[ ValiKS( ) ] ) ; }
  int&    VITIMP( int ni ) { return( TASK( ) ? vitimp[ ValiKS( ) ][ ni ] : TestVit[ ValiKS( ) ][ ni ] ) ; }
  double& ARGIMP( int ni ) { return( TASK( ) ? uimp[ ValiKS( ) ][ ni ] : TestArg[ ValiKS( ) ][ ni ] ) ; }
  int&    SKIMP ( int ni ) { return( TASK( ) ? skimp[ ValiKS( ) ][ ni ] : TestSk[ ValiKS( ) ][ ni ] ) ; }
  //
  double& MTEST      ( ) { return TestM[ ValiKS( ) ] ; }
  double& PTEST      ( ) { return TestP[ ValiKS( ) ] ; }
  int& COUNTIMPTEST  ( ) { return TestNImp[ ValiKS( ) ] ; }
  int*    KEYNUTEST  ( ) { return TestKeyNU[ ValiKS( ) ] ; }
  int&    VITTEST    ( ) { return TestZVit[ ValiKS( ) ] ; }
  int&    VITIMPTEST ( int ni )    { return TestVit[ ValiKS( ) ][ ni ] ; }
  double& ARGIMPTEST ( int ni )    { return TestArg[ ValiKS( ) ][ ni ] ; }
  int&    SKIMPTEST  ( int ni )    { return TestSk [ ValiKS( ) ][ ni ] ; }
  double& TIMEIMPTEST( int ni )    { return TestTime[ ValiKS( ) ][ ni ] ; }
  double& DVIMPTEST  ( int ni )    { return TestdV[ ValiKS( ) ][ ni ] ; }
  double& DTIMPTEST  ( int ni )    { return Testdt[ ValiKS( ) ][ ni ] ; }
  //
  double& PART ( int Ks=-1 ) { int iks = Ks >= 0 ? Ks : ValiKS(); return(paramT[iks]); }
  double& PARL ( int Ks=-1 ) { int iks = Ks >= 0 ? Ks : ValiKS(); return(paramL[iks]); }
  double& PARu (int Ks = -1) { int iks = Ks >= 0 ? Ks : ValiKS(); return(paramu[iks]); }
  double& PARdL( int Ks=-1 ) { int iks = Ks >= 0 ? Ks : ValiKS(); return(paramdL[iks]); }
  double& PARhs( int Ks=-1 ) { int iks = Ks >= 0 ? Ks : ValiKS(); return(paramhs[iks]); }
  double& PARh ( int Ks=-1 ) { int iks = Ks >= 0 ? Ks : ValiKS(); return(paramh[iks]); }
  double& PARBh( int Ks=-1 ) { int iks = Ks >= 0 ? Ks : ValiKS(); return(paramBh[iks]); }
  char&   PARBv(int Ks = -1) { int iks = Ks >= 0 ? Ks : ValiKS(); return(paramV[iks]); }
  double& PARa ( int Ks=-1 ) { int iks = Ks >= 0 ? Ks : ValiKS(); return(parama[iks]); }
  double& PARe ( int Ks=-1 ) { int iks = Ks >= 0 ? Ks : ValiKS(); return(parame[iks]); }
  double& PARw ( int Ks=-1 ) { int iks = Ks >= 0 ? Ks : ValiKS(); return(paramw[iks]); }
  double& PARt (int Ks = -1) { int iks = Ks >= 0 ? Ks : ValiKS(); return(paramt[iks]); }
  //
  int FINDVARTASK( int Tsk=-1, int Orb=-1 ) {
    int io = Orb>=0 ? Orb:ORB() ;
	Tsk = Tsk>=0 ? Tsk:TASK() ;
    if ( io ) {
      switch( Tsk ) {
        case 10 : return 0 ;
        case 11 : return 1 ;
        case 12 : return 2 ;
        case 13 : return 3 ;
        case 14 : return 4 ;
        case 15 : 
        case 16 : 
        case 17 : 
        case 18 : assert(0) ; 
		//
        case 20 : return 9;
        case 21 : return 10;
        case 22 : return 11;
        case 23 : return 12;
        case 24 : return 13;
        case 25 : return 14;
        case 26 : return 15;
        case 27 : return 16;
        case 28 : return 17;
        case 29 : return 18;
		case 241: return 19;
		//
        case 30 : return 20 ;
        case 31 : return 21 ;
		case 311: return 22;
        case 32 : return 23 ;
        case 33 : return 24 ;
        case 0  : return 25 ;
        default: return-1 ;
      }
    } else {
      switch( Tsk ) {
        case 10 : return 0 ;	
        case 11 : return 1 ;
        case 12 : return 2 ;
        case 13 : return 3 ;
        case 14 : return 4 ;
        case 15 : return 5 ;
        case 16 : return 6 ;
        case 17 : return 7 ;
        case 18 : return 8 ;
		//
        case 20 : return 9 ;
        case 21 : return 10 ;
        case 22 : return 11 ;
        case 23 : return 12 ;
        case 24 : return 13 ;
        case 25 : return 14 ;
        case 26 : return 15 ;
        case 27 : return 16 ;
        case 28 : return 17 ;
        case 29 : return 18 ;
		case 241: return 19;
		//
        case 30 : return 20 ;
        case 31 : return 21 ;
		case 311: return 22;
        case 32 : return 23 ;
        case 33 : return 24 ;
        case 0  : return 25 ;
        default: return-1 ;
      }
    }
  }
  // Условный номер задания по индексу задачи в списке (ватианту)
  int  TASK( int Var=-1, int Orb=-1  ) {
    int iv = Var>=0 ? Var:VAR() ;
    int io = Orb>=0 ? Orb:ORB() ;

    if (io) {
      switch(iv) {
        case 0 : return 10 ;
        case 1 : return 11 ;
        case 2 : return 12 ;
        case 3 : return 13 ;
        case 4 : return 14 ;
		case 5 :
		case 6 :
		case 7 :
		case 8 : assert(0) ;
        case 9 : return 20 ;
        case 10: return 21 ;
        case 11: return 22 ;

        case 12: return 23 ;
        case 13: return 24 ;
        case 14: return 25 ;
        case 15: return 26 ;
        case 16: return 27 ;
        case 17: return 28 ;
        case 18: return 29 ;
		case 19: return 241;
        case 20: return 30 ;
        case 21: return 31 ;
		case 22: return 311;
        case 23: return 32 ;
        case 24: return 33 ;
        case 25: return 0 ;
        default: return-1 ;
      }
    } else {
      switch(iv) {
        case 0 : return 10 ;
        case 1 : return 11 ;
        case 2 : return 12 ;
        case 3 : return 13 ;
        case 4 : return 14 ;
        case 5 : return 15 ;
        case 6 : return 16 ;
        case 7 : return 17 ;
        case 8 : return 18 ;
        case 9 : return 20 ;
        case 10: return 21 ;
        case 11: return 22 ;

        case 12: return 23 ;
        case 13: return 24 ;
        case 14: return 25 ;
        case 15: return 26 ;
        case 16: return 27 ;
        case 17: return 28 ;
        case 18: return 29 ;
		case 19: return 241;
        case 20: return 30 ;
        case 21: return 31 ;
		case 22: return 311;
        case 23: return 32 ;
        case 24: return 33 ;
        case 25: return 0 ;
        default: return-1 ;
      }
    }
  }
  // Допустимость решения по указанному варианту
  bool IsEnableVar( int Var =-1, int Ks =-1 ) {
    int iks= Ks  >= 0 ? Ks : ks ;
    int iv = Var >= 0 ? Var : VAR( ) ;
    int it = TASK( iv ) ;
    int io = ORB( ) ;
    return ( IsEnableTask( it, iks, io ) ) ;
  }
  // Допустимость решения указанной задачи
  bool IsEnableTask( int it, int Ks =-1, int Orb =-1 ) {
    int iks= Ks >= 0 ? Ks  : ks ;
    int io = Orb>= 0 ? Orb : ORB( ) ;
    // Любой КА
    if ( it == 0 || it == 10 || it == 20 || it == 30 ) return 1 ;
    // Янтарь
    if ( ks <= 0 ) {
      if ((it>=11 && it<=13) || (it>=110 && it<=113) || it == 121 || 
	  (it >= 15 && it <= 16 ) ||
      (it==14 && io==0) ||
      (it==21 ) || (it==22 && io==0) ||
	  (it >= 23 && it <= 24) || it == 241 || (it == 25 && io == 0) ||
	  (it >= 26 && it <= 29) || it == 31 || it == 311) return 1;
    }
    // Кондор
    if ( ks == 1 ) {
      if ( ( it >= 11 && it <= 13 ) || it == 121 || ( it == 14 && io  ) ||
	  (it == 21) || (it == 22 && io) || (it >= 23 && it <= 24) || it == 241 ||
      ( it == 25 && io ) || ( it == 26 ) ||
	  (it >= 31 && it <= 33) || (it == 311) ) return 1;
    }
    // Аракс
    if ( ks >= 2 ) {
      if ( ( it >= 15 && it <= 18 ) || ( it >= 27 && it <= 29 ) ) return 1 ;
    }
    return 0 ;
  }
  //
  bool GetVarText( char* Text, int Var =-1, int Orb =-1 ) {
    int io = Orb >= 0 ? Orb : ORB() ;
    int iv = Var >= 0 ? Var : VAR() ;
	// Эллипс e,w
    if ( io == 0 ) { 
      switch( iv ) {
      case 0 : sprintf(Text, "10)  a  + e, w" ) ; break ;
      case 1 : sprintf(Text, "11)  T  + e, w" ) ; break ;
      case 2 : sprintf(Text, "12)  L  + e, w" ) ; break ;
      case 3 : sprintf(Text, "13)  dL + e, w" ) ; break ;
      case 4 : sprintf(Text, "14)  h  + e, w" ) ; break ;
      case 5 : sprintf(Text, "15)  T  + w" ) ; break ;
      case 6 : sprintf(Text, "16)  L  + w" ) ; break ;
      case 7 : sprintf(Text, "17)  T" ) ; break ;
      case 8 : sprintf(Text, "18)  L" ) ; break ;
      case 9 : sprintf(Text, "20)  a,  e, w" ) ; break ;
      case 10: sprintf(Text, "21)  T,  e, w" ) ; break ;
      case 11: sprintf(Text, "22)  Hs, e, w" ) ; break ;
      case 12: sprintf(Text, "23)  dL, e, w" ) ; break ;
      case 13: sprintf(Text, "24)  L, T + e, w" ) ; break ;
      case 14: sprintf(Text, "25)  L, h + e, w" ) ; break ;
      case 15: sprintf(Text, "26)  L, dL + e, w" ) ; break ;
      case 16: sprintf(Text, "27)  L, T + w" ) ; break ;
      case 17: sprintf(Text, "28)  L, T" ) ; break ;
      case 18: sprintf(Text, "29)  L, w" ) ; break ;
	  case 19: sprintf(Text, "241) u, T + e, w"); break;

      case 20: sprintf(Text, "30)  L, a, e, w" ) ; break ;
      case 21: sprintf(Text, "31)  L, T, e, w" ) ; break ;
	  case 22: sprintf(Text, "311) u, T, e, w"); break;
      case 23: sprintf(Text, "32)  L, h, e, w" ) ; break ;
      case 24: sprintf(Text, "33)  L, dL, e, w" ) ; break ;
      case 25: sprintf(Text, "00)  Тест" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    } 
	// Эллипс hBh
    if ( io == 1 ) { 	
      switch( iv ) {
      case 0 : sprintf(Text, "10)  a + h, Bh"  ) ; break ;
      case 1 : sprintf(Text, "11)  T + h, Bh" ) ; break ;
      case 2 : sprintf(Text, "12)  L + h, Bh" ) ; break ;
      case 3 : sprintf(Text, "13)  dL + h, Bh" ) ; break ;
      case 4 : sprintf(Text, "14)  h + Bh" ) ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      case 9 : sprintf(Text, "20)  a, h, Bh" ) ; break ;
      case 10: sprintf(Text, "21)  T, h, Bh" ) ; break ;
      case 11: assert(0) ;
      case 12: sprintf(Text, "23)  dL, h, Bh" ) ; break ;
      case 13: sprintf(Text, "24)  L, T + h, Bh" ) ; break ;
      case 14: sprintf(Text, "25)  L, h + Bh" ) ; break ;
      case 15: sprintf(Text, "26)  L, dL + h, Bh" ) ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: sprintf(Text,  "241) u, T + h, Bh"); break;
      //
      case 20: sprintf(Text, "30)  L, a, e, w" ) ;  break ;
      case 21: sprintf(Text, "31)  L, T, h, Bh" ) ; break ;
	  case 22: sprintf(Text, "311) u, T, h, Bh"); break;
      case 23: sprintf(Text, "32)  L, Hs, h, Bh" ) ; break ;
      case 24: sprintf(Text, "33)  L, dL, h, Bh" ) ; break ;
      case 25: sprintf(Text, "00)  Тест" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    }
	// ОМИВ 
    if ( io == 2 ) { 
      switch( iv ) {
      case 0 : sprintf(Text, "10)  a  + ОМИВ" ) ; break ;
      case 1 : sprintf(Text, "11)  T  + ОМИВ" ) ; break ;
      case 2 : sprintf(Text, "12)  L  + ОМИВ" ) ; break ;
      case 3 : sprintf(Text, "13)  dL + ОМИВ" ) ; break ;
      case 4 : sprintf(Text, "14)  Hs + ОМИВ" ) ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      case 9 : sprintf(Text, "20)  a, ОМИВ" ) ; break ;
      case 10: sprintf(Text, "21)  T, ОМИВ" ) ; break ;
      case 11: sprintf(Text, "22)  Hs, ОМИВ" ) ; break ;
      case 12: sprintf(Text, "23)  dL, ОМИВ" ) ; break ;
      case 13: sprintf(Text, "24)  L, T + ОМИВ" ) ; break ;
      case 14: sprintf(Text, "25)  L, h + ОМИВ" ) ; break ;
      case 15: sprintf(Text, "26)  L, dL + ОМИВ" ) ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: sprintf(Text, "241)  u, T + ОМИВ"); break;
      //
      case 20: sprintf(Text, "30)  L, a, ОМИВ" ) ; break ;
      case 21: sprintf(Text, "31)  L, T, ОМИВ" ) ; break ;
	  case 22: sprintf(Text, "311) u, T, ОМИВ"); break;
      case 23: sprintf(Text, "32)  L, h, ОМИВ" ) ; break ;
      case 24: sprintf(Text, "33)  L, dL,ОМИВ" ) ; break ;
      case 25: sprintf(Text, "00)  Тест" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    } 
    if ( io == 3 ) { 
      switch( iv ) {
      case 0 : sprintf(Text, "10)  a  + ДУ" ) ; break ;
      case 1 : sprintf(Text, "11)  T  + ДУ" ) ; break ;
      case 2 : sprintf(Text, "12)  L  + ДУ" ) ; break ;
      case 3 : sprintf(Text, "13)  dL + ДУ" ) ; break ;
      case 4 : sprintf(Text, "14)  Hs + ДУ" ) ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      case 9 : sprintf(Text, "20)  a, ДУ" ) ; break ;
      case 10: sprintf(Text, "21)  T, ДУ" ) ; break ;
      case 11: sprintf(Text, "22)  Hs, ДУ" ) ; break ;
      case 12: sprintf(Text, "23)  dL, ДУ" ) ; break ;
      case 13: sprintf(Text, "24)  L, T + ДУ" ) ; break ;
      case 14: sprintf(Text, "25)  L, h + ДУ" ) ; break ;
      case 15: sprintf(Text, "26)  L, dL + ДУ" ) ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: sprintf(Text, "241)  u, T + ДУ"); break;
      //
      case 20: sprintf(Text, "30)  L, a, ДУ" ) ; break ;
      case 21: sprintf(Text, "31)  L, T, ДУ" ) ; break ;
	  case 22: sprintf(Text, "311) u, T, ДУ"); break;
      case 23: sprintf(Text, "32)  L, h, ДУ" ) ; break ;
      case 24: sprintf(Text, "33)  L, dL, ДУ" ) ; break ;
      case 25: sprintf(Text, "00)  Тест" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    } 
    return 0 ;
  }
  bool GetVarDsk( char* Text, int Var =-1, int Orb =-1 ) {
    int io = Orb >= 0 ? Orb : ORB() ;
    int iv = Var >= 0 ? Var : VAR() ;
    Text[ 0 ] = '\0' ;
    if ( io == 0 ) {
      switch( iv ) {
      case 0 : sprintf( Text, "Одноимпульсная коррекция\n\
большой полуоси с максимальным приближением\n\
геометрии орбиты к требуемой.\0" ) ; break ;
      case 1 : sprintf( Text, "Одноимпульсная коррекция\n\
драконического периода обращения с максимальным\n\
приближением геометрии орбиты к требуемой.\0" ) ; break ;
      case 2 : sprintf( Text, "Одноимпульсная коррекция\n\
долготы начала заданного витка с максимальным\n\
приближением геометрии орбиты к требуемой.\0" ) ; break ;
      case 3 : sprintf( Text, "Одноимпульсная коррекция\n\
суточного смещения трассы с максимальным\n\
приближением геометрии орбиты к требуемой.\0" ) ; break ;
      case 4 : sprintf( Text, "Одноимпульсная коррекция\n\
минимальной высоты с максимальным приближением\n\
геометрии орбиты к требуемой.\0" ) ; break ;
      case 5 : sprintf( Text, "Одноимпульсная коррекция\n\
драконического периода обращения с максимальным\n\
приближением положения перицентра орбиты к заданному значению.\0" ) ; break ;
      case 6 : sprintf( Text, "Одноимпульсная коррекция\n\
долготы восходящего узла орбиты с максимальным\n\
приближением положения перицентра орбиты к заданному значению.\0" ) ; break ;
      case 7 : sprintf( Text, "Одноимпульсная коррекция\n\
драконического периода обращения.\0" ) ; break ;
      case 8 : sprintf( Text, "Одноимпульсная коррекция долготы\n\
восходящего узла орбиты.\0" ) ; break ;
      //
      case 9 : sprintf( Text, "Двухимпульсная коррекция\n\
большой полуоси и геометрии орбиты на заданном витке\0" ) ; break ;
      case 10: sprintf( Text, "Двухимпульсная коррекция\n\
драконического периода обращения, и геометрии орбиты на заданном витке" ) ; break ;
      case 11: sprintf( Text, "Двухимпульсная коррекция\n\
средней высоты, и геометрии орбиты на заданном витке" ) ; break ;

      case 12: sprintf( Text, "Двухимпульсная коррекция\n\
cуточного дрейфа долготы и геометрии орбиты на заданном витке\0" ) ; break ;
      case 13: sprintf( Text, "Двухимпульсная коррекция\n\
драконического периода обращения и долготы восходящего узлана на заданном витке\n\
с максимальным приближением геометии орбиты к требуемой" ) ; break ;
      case 14: sprintf( Text, "Двухимпульсная коррекция\n\
долготы восходящего узла орбиты и средней высоты на заданном витке\n\
с максимальным приближением геометрии орбиты к требуемой" ) ; break ;
      case 15: sprintf( Text, "Двухимпульсная коррекция\n\
долготы восходящего узла орбиты и дрейфа долготы на заданном витке\n\
с максимальным приближением геометрии орбиты к требуемой" ) ; break ;
      case 16: sprintf( Text, "Двухимпульсная коррекция\n\
долготы восходящего узла орбиты и драконического периода на заданном витке\n\
с максимальным приближением положения перигея к требуемому значению" ) ; break ;
      case 17: sprintf( Text, "Двухимпульсная коррекция\n\
долготы восходящего узла орбиты и драконического периода на заданном витке\0" ) ; break ;
      case 18: sprintf( Text, "Двухимпульсная коррекция\n\
долготы восходящего узла и положения перигея орбиты на заданном витке\0" ) ;            break ;
	  case 19: sprintf(Text, "Двухимпульсная коррекция\n\
драконического периода обращения и аргумента широты на заданном витке\n\
с максимальным приближением геометии орбиты к требуемой"); break;
      //
      case 20: sprintf(Text, "Трехимпульсная коррекция\n\
формирования на заданном витке долготы восходящего узла орбиты,\n\
большой полуоси и геометрии орбиты.\0" ) ; break ;
      case 21: sprintf(Text, "Трехимпульсная коррекция\n\
формирования на заданном витке долготы восходящего узла орбиты,\n\
драконического периода обращения и геометрии орбиты.\0" ) ; break ;
	  case 22: sprintf(Text, "Трехимпульсная коррекция\n\
аргумента широты КА в заданный момент времени,\n\
драконического периода обращения и геометрии орбиты.\0"); break;
      case 23: sprintf(Text, "Трехимпульсная коррекция\n\
формирования на заданном витке долготы восходящего узла орбиты,\n\
средней высоты и геометрии орбиты.\0" ) ; break ;
      case 24: sprintf(Text, "Трехимпульсная коррекция\n\
формирования на заданном витке долготы восходящего узла орбиты,\n\
дрейфа долготы и геометрии орбиты.\0" ) ; break ;
      case 25: sprintf(Text, "Моделирование тестовой коррекции,\n\
с рассчётом параметров движения после каждого импульса и на заданный виток\0" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    }
    if ( io == 1 ) {
      switch( iv ) {
      case 0 : sprintf( Text, "Одноимпульсная коррекция\n\
большой полуоси с максимальным приближением\n\
минимальной высоты и её широты к требуемым значениям\0" ) ; break ;
      case 1 : sprintf( Text, "Одноимпульсная коррекция\n\
драконического периода обращения с максимальным приближением\n\
минимальной высоты и её широты к требуемым значениям\0" ) ; break ;
      case 2 : sprintf( Text, "Одноимпульсная коррекция\n\
долготы начала заданного витка с максимальным приближением\n\
минимальной высоты и её широты к требуемым значениям\0" ) ; break ;
      case 3 : sprintf( Text, "Одноимпульсная коррекция\n\
суточного смещения трассы полёта с максимальным приближением\n\
минимальной высоты и её широты к требуемым значениям\0" ) ; break ;
      case 4 : sprintf( Text, "Одноимпульсная коррекция\n\
минимальной высоты с максимальным приближением\n\
её широты к требуемому значению\0" ) ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      //
      case 9 : sprintf( Text, "Двухимпульсная коррекция\n\
большой полуоси, минимальной высоты и широты минимальной высоты\0" ) ; break ;
      case 10: sprintf( Text, "Двухимпульсная коррекция\n\
драконического периода обращения,\n\
минимальной высоты и широты минимальной высоты" ) ; break ;
      case 11: assert(0) ;
      case 12: sprintf( Text, "Двухимпульсная коррекция\n\
суточного дрейфа долготы, мнимальной высоты и её широты на заданном витке\0" ) ; break ;
      case 13: sprintf( Text, "Двухимпульсная коррекция\n\
драконического периода обращения и долготы восходящего узла орбиты на заданном витке\n\
с максимальным приближением минимальной высоты и её широты к требуемым значениям" ) ; break ;
      case 14: sprintf( Text, "Двухимпульсная коррекция\n\
долготы восходящего узла орбиты и минимальной высоты на заданном витке\n\
с максимальным приближением широты минимальной высоты к требуемомму значению" ) ; break ;
      case 15: sprintf( Text, "Двухимпульсная коррекция\n\
долготы восходящего узла орбиты на заданном витке, минимальной высоты\n\
с максимальным приближением широты минимальной высоты к к заданному значению" ) ;      break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: sprintf(Text, "Двухимпульсная коррекция\n\
драконического периода обращения и аргумента широты на заданном витке\n\
с максимальным приближением минимальной высоты и её широты к требуемым значениям"); break;
      //
      case 20: sprintf( Text, "Трехимпульсная коррекция\n\
формирования на заданном витке долготы восходящего узла орбиты,\n\
большой полуоси, минимальной высоты и широты минимальной высоты.\0" ) ; break ;
      case 21: sprintf( Text, "Трехимпульсная коррекция\n\
формирования на заданном витке долготы восходящего узла,\n\
драконического периода обращения,\n\
минимальной высоты и широты минимальной высоты.\0" ) ; break ;
	  case 22: sprintf(Text, "Трехимпульсная коррекция\n\
аргумента широты КА в заданный момент времени,\n\
драконического периода обращения,\n\
минимальной высоты и широты минимальной высоты.\0"); break;
      case 23: sprintf( Text, "Трехимпульсная коррекция\n\
формирования на заданном витке долготы восходящего узла орбиты,\n\
средней высоты, минимальной высоты и широты минимальной высоты.\0" ) ; break ;
      case 24: sprintf( Text, "Трехимпульсная коррекция\n\
формирования на заданном витке долготы восходящего узла орбиты,\n\
дрейфа долготы, минимальной высоты и широты минимальной высоты.\0" ) ; break ;
      case 25: sprintf( Text, "Моделирование тестовой коррекции,\n\
с рассчётом параметров движения после каждого импульса и на заданный виток\0" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    }
    if ( io == 2 ) {
      switch( iv ) {
      case 0 : sprintf( Text, "Одноимпульсная коррекция\n\
большой полуоси с максимальным приближением\n\
геометрии орбиты к ОМИВ\0" ) ; break ;
      case 1 : sprintf( Text, "Одноимпульсная коррекция\n\
драконического периода обращения с максимальным приближением\n\
геометрии орбиты к ОМИВ\0" ) ; break ;
      case 2 : sprintf( Text, "Одноимпульсная коррекция\n\
долготы начала заданного витка с максимальным приближением\n\
геометрии орбиты к ОМИВ\0" ) ; break ;
      case 3 : sprintf( Text, "Одноимпульсная коррекция\n\
суточного смещения трассы полёта с максимальным приближением\n\
геометрии орбиты к ОМИВ\0" ) ; break ;
      case 4 : sprintf( Text, "Одноимпульсная коррекция\n\
средней высоты с максимальным приближением\n\
геометрии орбиты к ОМИВ\0" ) ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      //
      case 9 : sprintf( Text, "Двухимпульсная коррекция\n\
большой полуоси и геометрии ОМИВ на заданном витке\0" ) ; break ;
      case 10: sprintf( Text, "Двухимпульсная коррекция\n\
драконического периода обращения и геометрии ОМИВ на заданном витке\0" ) ; break ;
      case 11: sprintf( Text, "Двухимпульсная коррекция\n\
средней высоты орбиты и геометрии ОМИВ на заданном витке\0" ) ; break ;
      case 12: sprintf( Text, "Двухимпульсная коррекция\n\
суточного дрейфа долготы и геометрии ОМИВ на заданном витке\0" ) ; break ;
      case 13: sprintf( Text, "Двухимпульсная коррекция\n\
драконического периода обращения и долготы восходящего узла орбиты на заданном витке\n\
с максимальным приближением геометрии орбиты к ОМИВ" ) ; break ;
      case 14: sprintf( Text, "Двухимпульсная коррекция\n\
долготы восходящего узла орбиты и минимальной высоты на заданном витке\n\
с максимальным приближением геометрии орбиты к ОМИВ" ) ; break ;
      case 15: sprintf( Text, "Двухимпульсная коррекция\n\
долготы восходящего узла орбиты и минимальной высоты на заданном витке\n\
с максимальным приближением геометрии орбиты к ОМИВ" ) ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: sprintf(Text, "Двухимпульсная коррекция\n\
драконического периода обращения и аргумента широты на заданном витке\n\
с максимальным приближением геометрии орбиты к ОМИВ"); break;
      //
      case 20: sprintf( Text, "Трехимпульсная коррекция\n\
долготы восходящего узла орбиты на заданном витке,\n\
большой полуоси и геометрии орбиты до ОМИВ.\0" ) ; break ;
      case 21: sprintf( Text, "Трехимпульсная коррекция\n\
долготы восходящего узла орбиты на заданном витке,\n\
драконического периода обращения и геометрии орбиты до ОМИВ.\0" ) ; break ;
	  case 22: sprintf(Text, "Трехимпульсная коррекция\n\
аргумента широты КА в заданный момент времени,\n\
драконического периода обращения и геометрии орбиты до ОМИВ.\0"); break;
      case 23: sprintf( Text, "Трехимпульсная коррекция\n\
долготы восходящего узла орбиты на заданном витке,\n\
средней высоты и геометрии орбиты до ОМИВ.\0" ) ; break ;
      case 24: sprintf( Text, "Трехимпульсная коррекция\n\
долготы восходящего узла орбиты на заданном витке,\n\
суточного смещёния трассы полёта и геометрии орбиты  до ОМИВ.\0" ) ; break ;
      case 25: sprintf( Text, "Моделирование тестовой коррекции,\n\
с рассчётом параметров движения после каждого импульса и на заданный виток\0" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    }
    if ( io == 3 ) {
      switch( iv ) {
      case 0 : sprintf( Text, "Одноимпульсная коррекция\n\
большой полуоси с максимальным приближением\n\
геометрии орбиты к ДУ\0" ) ; break ;
      case 1 : sprintf( Text, "Одноимпульсная коррекция\n\
драконического периода обращения с максимальным приближением\n\
геометрии орбиты к ДУ\0" ) ; break ;
      case 2 : sprintf( Text, "Одноимпульсная коррекция\n\
долготы начала заданного витка с максимальным приближением\n\
геометрии орбиты к ДУ\0" ) ; break ;
      case 3 : sprintf( Text, "Одноимпульсная коррекция\n\
суточного смещения трассы полёта с максимальным приближением\n\
геометрии орбиты к ДУ\0" ) ; break ;
      case 4 : sprintf( Text, "Одноимпульсная коррекция\n\
средней высоты с максимальным приближением\n\
геометрии орбиты к ДУ\0" ) ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      //
      case 9 : sprintf( Text, "Двухимпульсная коррекция :\n\
большой полуоси и геометрии ДУ орбиты\0" ) ; break ;
      case 10: sprintf( Text, "Двухимпульсная коррекция :\n\
драконического периода обращения и геометрии ДУ орбиты\0" ) ; break ;
      case 11: sprintf( Text, "Двухимпульсная коррекция :\n\
средней высоты орбиты и геометрии ДУ орбиты\0" ) ; break ;
      case 12: sprintf( Text, "Двухимпульсная коррекция долготы восходящего узла орбиты \n\
и драконического периода обращения на заданном витке\n\
с максимальным приближением геометрии орбиты к ДУ орбите\0" ) ; break ;
      case 13: sprintf( Text, "Двухимпульсная коррекция\n\
драконического периода обращения и долготы восходящего узла орбиты на заданном витке\n\
с максимальным приближением геометрии орбиты к ДУ" ) ; break ;
      case 14: sprintf( Text, "Двухимпульсная коррекция\n\
долготы восходящего узла орбиты и минимальной высоты на заданном витке\n\
с максимальным приближением геометрии орбиты к ДУ" ) ; break ;
      case 15: sprintf( Text, "Двухимпульсная коррекция\n\
долготы восходящего узла орбиты и минимальной высоты на заданном витке\n\
с максимальным приближением геометрии орбиты к ДУ" ) ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: sprintf(Text, "Двухимпульсная коррекция\n\
драконического периода обращения и аргумента широты на заданном витке\n\
с максимальным приближением геометрии орбиты к ДУ"); break;
      //
      case 20: sprintf( Text, "Трехимпульсная коррекция\n\
долготы восходящего узла орбиты на заданном витке,\n\
большой полуоси и геометрии орбиты до ДУ.\0" ) ; break ;
      case 21: sprintf( Text, "Трехимпульсная коррекция\n\
долготы восходящего узла орбиты на заданном витке,\n\
драконического периода обращения и геометрии орбиты до ДУ.\0" ) ; break ;
	  case 22: sprintf(Text, "Трехимпульсная коррекция\n\
аргумента широты КА в заданный момент времени,\n\
драконического периода обращения и геометрии орбиты до ДУ.\0"); break;
      case 23: sprintf( Text, "Трехимпульсная коррекция\n\
долготы восходящего узла орбиты на заданном витке,\n\
средней высоты и геометрии орбиты до ДУ.\0" ) ; break ;
      case 24: sprintf( Text, "Трехимпульсная коррекция\n\
долготы восходящего узла орбиты на заданном витке,\n\
суточного смещёния трассы полёта и геометрии орбиты до ДУ.\0" ) ; break ;
      case 25: sprintf( Text, "Моделирование тестовой коррекции,\n\
с рассчётом параметров движения после каждого импульса и на заданный виток\0" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    }
    return 0 ;
  }
  //
  bool GetParKorFromVar( int& ParKor, int Var =-1, int Orb =-1 ) {
    int io = Orb >= 0 ? Orb : ORB() ;
    int iv = Var >= 0 ? Var : VAR() ;
    ParKor = 0 ;
    if (io==2 || io==3) {
      switch( iv ) {
      case 0 : ParKor = MKN_PARAM_ORB_a ;  break ;
      case 1 : ParKor = MKN_PARAM_ORB_T ;  break ;
      case 2 : ParKor = MKN_PARAM_ORB_L ;  break ;
      case 3 : ParKor = MKN_PARAM_ORB_dL ; break ;
      case 4 : ParKor = MKN_PARAM_ORB_hs ; break ;
      case 5 : 
      case 6 : 
      case 7 :       
	  case 8 : assert(0) ;
      //
      case 9 : ParKor = MKN_PARAM_ORB_a | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 10: ParKor = MKN_PARAM_ORB_T | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 11: ParKor = MKN_PARAM_ORB_hs | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 12: ParKor = MKN_PARAM_ORB_dL | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 13: ParKor = MKN_PARAM_ORB_T | MKN_PARAM_ORB_L ; break ;
      case 14: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_hs ; break ;
      case 15: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_hs ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: ParKor = MKN_PARAM_ORB_T | MKN_PARAM_ORB_u; break;
      //
      case 20: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_a | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 21: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_T | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
	  case 22: ParKor = MKN_PARAM_ORB_u | MKN_PARAM_ORB_T | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w; break;
      case 23: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_hs| MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 24: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_dL| MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 25: ParKor = 0 ;
      default : return 1 ;
      }
    } 
    if (io==1) {
      switch( iv ) {
      case 0 : ParKor = MKN_PARAM_ORB_a ;  break ;
      case 1 : ParKor = MKN_PARAM_ORB_T ;  break ;
      case 2 : ParKor = MKN_PARAM_ORB_L ;  break ;
      case 3 : ParKor = MKN_PARAM_ORB_dL ; break ;
      case 4 : ParKor = MKN_PARAM_ORB_hmin ;  break ;
      case 5 : 
      case 6 : 
      case 7 :       
	  case 8 : assert(0) ;
      //
      case 9 : ParKor = MKN_PARAM_ORB_a | MKN_PARAM_ORB_hmin | MKN_PARAM_ORB_Bh ; break ;
      case 10: ParKor = MKN_PARAM_ORB_T | MKN_PARAM_ORB_hmin | MKN_PARAM_ORB_Bh ; break ;
	  case 11: assert(0) ;
      case 12: ParKor = MKN_PARAM_ORB_dL| MKN_PARAM_ORB_hmin | MKN_PARAM_ORB_Bh ; break ;
      case 13: ParKor = MKN_PARAM_ORB_T | MKN_PARAM_ORB_L ; break ;
      case 14: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_hmin ; break ;
      case 15: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_hmin ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: ParKor = MKN_PARAM_ORB_T | MKN_PARAM_ORB_u; break;
      //
      case 20: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_a | MKN_PARAM_ORB_hmin | MKN_PARAM_ORB_Bh ; break ;
      case 21: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_T | MKN_PARAM_ORB_hmin | MKN_PARAM_ORB_Bh ; break ;
	  case 22: ParKor = MKN_PARAM_ORB_u | MKN_PARAM_ORB_T | MKN_PARAM_ORB_hmin | MKN_PARAM_ORB_Bh; break;
      case 23: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_hs| MKN_PARAM_ORB_hmin | MKN_PARAM_ORB_Bh ; break ;
      case 24: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_dL| MKN_PARAM_ORB_hmin | MKN_PARAM_ORB_Bh ; break ;
      case 25: ParKor = 0 ;
      default : return 1 ;
      }
    } 
    if (io==0) {
      switch( iv ) {
      case 0 : ParKor = MKN_PARAM_ORB_a ;  break ;
      case 1 : ParKor = MKN_PARAM_ORB_T ;  break ;
      case 2 : ParKor = MKN_PARAM_ORB_L ;  break ;
      case 3 : ParKor = MKN_PARAM_ORB_dL ; break ;
      case 4 : ParKor = MKN_PARAM_ORB_hs ; break ;
      case 5 : ParKor = MKN_PARAM_ORB_T ;  break ;
      case 6 : ParKor = MKN_PARAM_ORB_L ;  break ;
      case 7 : ParKor = MKN_PARAM_ORB_T ;  break ;
      case 8 : ParKor = MKN_PARAM_ORB_L ;  break ;
      //
      case 9 : ParKor = MKN_PARAM_ORB_a | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 10: ParKor = MKN_PARAM_ORB_T | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 11: ParKor = MKN_PARAM_ORB_hs| MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 12: ParKor = MKN_PARAM_ORB_dL| MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 13: ParKor = MKN_PARAM_ORB_T | MKN_PARAM_ORB_L ;  break ;
      case 14: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_hs ; break ;
      case 15: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_dL ; break ;
      case 16: 
      case 17: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_T ; break ;
      case 18: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_w ; break ;
	  case 19: ParKor = MKN_PARAM_ORB_T | MKN_PARAM_ORB_u; break;
      //
      case 20: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_a | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 21: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_T | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
	  case 22: ParKor = MKN_PARAM_ORB_u | MKN_PARAM_ORB_T | MKN_PARAM_ORB_e | MKN_PARAM_ORB_w; break;
      case 23: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_hs| MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 24: ParKor = MKN_PARAM_ORB_L | MKN_PARAM_ORB_dL| MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 25: ParKor = 0 ;
      default : return 1 ;
      }
	}
    return 0 ;
  }
  bool GetAdvParKorFromVar(int& ParKor, int Var=-1, int Orb=-1) {
    int io = Orb>=0 ? Orb:ORB() ;
    int iv = Var>=0 ? Var:VAR() ;
    ParKor = 0 ;
    if ( io == 2 || io == 3 ) {
      switch( iv ) {
      case 0 : 
      case 1 : 
      case 2 : 
      case 3 : 
      case 4 : ParKor = MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      //
      case 9 : 
      case 10: 
      case 11: 
      case 12: ParKor = 0 ; break ;
      case 13: 
      case 14: ParKor = MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 15: ParKor = 0 ; break ; 
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: ParKor = MKN_PARAM_ORB_e | MKN_PARAM_ORB_w; break;
	  //
      case 20: 
      case 21: 
      case 22: 
	  case 23:
      case 24: 
      case 25: ParKor = 0 ; break ;
      default: return 1 ;
      }
    } 
    if ( io == 1 ) {
      switch( iv ) {
      case 0 : 
      case 1 : 
      case 2 : 
      case 3 : ParKor = MKN_PARAM_ORB_hmin | MKN_PARAM_ORB_Bh ; break ;
      case 4 : ParKor = MKN_PARAM_ORB_Bh ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
	  //
      case 9 : 
      case 10: ParKor = 0 ; break ;
      case 11: assert(0) ;
      case 12: ParKor = 0 ; break ;
      case 13: ParKor = MKN_PARAM_ORB_hmin | MKN_PARAM_ORB_Bh ; break ;
      case 14: ParKor = MKN_PARAM_ORB_Bh ; break ;
      case 15: ParKor = 0 ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: ParKor = MKN_PARAM_ORB_hmin | MKN_PARAM_ORB_Bh; break;
	  //
      case 20: 
      case 21: 
      case 22: 
      case 23: 
	  case 24:
      case 25: ParKor = 0 ; break ;
      default : return 1 ;
      }
    }
    if ( io == 0 ) {
      switch( iv ) {
      case 0 : 
      case 1 : 
      case 2 : 
      case 3 : 
      case 4 : ParKor = MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 5 : ParKor = MKN_PARAM_ORB_w ;  break ;
      case 6 : ParKor = MKN_PARAM_ORB_w ;  break ;
      case 7 : ParKor = 0 ;  break ;
      case 8 : ParKor = 0 ;  break ;
	  //
      case 9 : 
      case 10: 
      case 11: 
      case 12: ParKor = 0 ; break ;
      case 13: 
      case 14: ParKor = MKN_PARAM_ORB_e | MKN_PARAM_ORB_w ; break ;
      case 15: ParKor = 0 ; break ;
      case 16: ParKor = MKN_PARAM_ORB_w ; break ;
      case 17: 
      case 18: ParKor = 0 ; break ;
	  case 19: ParKor = MKN_PARAM_ORB_e | MKN_PARAM_ORB_w; break;
      //
      case 20: 
      case 21: 
      case 22: 
      case 23: 
	  case 24:
      case 25: ParKor = 0 ; break ;
      default : return 1 ;
      }
    }
    return 0 ;
  }
  //
  bool Get_a_Value( double& Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_a ) ) return 1 ;
    Val = parama[ ValiKS( ) ] ;
    return 0 ;
  }
  bool Get_T_Value( double& Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_T ) ) return 1 ;
    Val = paramT[ ValiKS( ) ] ;
    return 0 ;
  }
  bool Get_L_Value( double& Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_L ) ) return 1 ;
    Val = paramL[ ValiKS( ) ] ;
    return 0 ;
  }
  bool Get_u_Value(double& Val) {
	  if (!((DemandsKey | SecondDemandsKey) & MKN_PARAM_ORB_u)) return 1;
	  Val = paramu[ValiKS()];
	  return 0;
  }
  bool Get_dL_Value( double& Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_dL ) ) return 1 ;
    Val = paramdL[ ValiKS( ) ] ;
    return 0 ;
  }
  bool Get_hs_Value( double& Val ) {
	if (!((DemandsKey|SecondDemandsKey) & MKN_PARAM_ORB_hs)) return 1 ;
    Val = paramhs[ValiKS()] ;
    return 0 ;
  }
  bool Get_h_Value( double& Val ) {
    //if ( ORB() ) {
    //  if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_hs ) ) return 1 ;
    //} else {
    //  if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_hmin ) ) return 1 ;
    //}
	if (!((DemandsKey|SecondDemandsKey) & MKN_PARAM_ORB_hmin)) return 1 ;
    Val = paramh[ValiKS()] ;
    return 0 ;
  }
  bool Get_Bh_Value( double& Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_Bh ) ) return 1 ;
    Val = paramBh[ ValiKS( ) ] ;
    return 0 ;
  }
  bool Get_Bv_Value( char& Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_Bh ) ) return 1 ;
    Val = paramV[ ValiKS( ) ] ;
    return 0 ;
  }
  bool Get_e_Value( double& Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_e ) ) return 1 ;
    Val = parame[ ValiKS( ) ] ;
    return 0 ;
  }
  bool Get_w_Value( double& Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_w ) ) return 1 ;
    Val = paramw[ ValiKS( ) ] ;
    return 0 ;
  }
  //
  bool Set_a_Value( double Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_a ) ) return 1 ;
    parama[ ValiKS( ) ] = Val ;
    return 0 ;
  }
  bool Set_T_Value( double Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_T ) ) return 1 ;
    paramT[ ValiKS( ) ] = Val ;
    return 0 ;
  }
  bool Set_L_Value( double Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_L ) ) return 1 ;
    paramL[ ValiKS( ) ] = Val;
    return 0 ;
  }
  bool Set_u_Value(double Val) {
	  if (!((DemandsKey | SecondDemandsKey) & MKN_PARAM_ORB_u)) return 1;
	  paramu[ValiKS()] = Val;
	  return 0;
  }
  bool Set_dL_Value( double Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_dL ) ) return 1 ;
    paramdL[ ValiKS( ) ] = Val ;
    return 0 ;
  }
  bool Set_hs_Value( double Val ) {
	if (!((DemandsKey|SecondDemandsKey) & MKN_PARAM_ORB_hs)) return 1 ;
    paramhs[ValiKS()] = Val ;
    return 0 ;
  }
  bool Set_h_Value( double Val ) {
    //if ( ORB() ) {
    //  if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_hs ) ) return 1 ;
    //} else {
    //  if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_hmin ) ) return 1 ;
    //}
	if (!((DemandsKey|SecondDemandsKey) & MKN_PARAM_ORB_hmin)) return 1 ;
    paramh[ValiKS()] = Val ;
    return 0 ;
  }
  bool Set_Bh_Value( double Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_Bh ) ) return 1 ;
    paramBh[ ValiKS( ) ] = Val ;
    return 0 ;
  }
  bool Set_Bv_Value( char Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_Bh ) ) return 1 ;
    paramV[ ValiKS( ) ] = Val ;
    return 0 ;
  }
  bool Set_e_Value( double Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_e ) ) return 1 ;
    parame[ ValiKS( ) ] = Val ;
    return 0 ;
  }
  bool Set_w_Value( double Val ) {
    if ( !( ( DemandsKey | SecondDemandsKey ) & MKN_PARAM_ORB_w ) ) return 1 ;
    paramw[ ValiKS( ) ] = Val ;
    return 0 ;
  }
public :
  int Flags(char Var=0) { if (Var==1) return DemandsKey ; if (Var==2) return SecondDemandsKey ; return (DemandsKey|SecondDemandsKey) ; } ;
  //
  bool ContA   (char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_a) ? true : false; }
  bool ContT   (char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_T) ? true : false; }
  bool ContL   (char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_L) ? true : false; }
  bool Contu   (char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_u) ? true : false; }
  bool ContDL  (char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_dL) ? true : false; }
  bool ContHs  (char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_hs) ? true : false; }
  bool ContHmax(char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_hmax) ? true : false; }
  bool ContHmin(char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_hmin) ? true : false; }
  bool ContH   (char VarFlags = 0) { return (Flags(VarFlags)&(ORB() ? MKN_PARAM_ORB_hs : MKN_PARAM_ORB_hmin)) ? true : false; }
  bool ContBH  (char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_Bh) ? true : false; }
  bool ContE   (char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_e) ? true : false; }
  bool ContW   (char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_w) ? true : false; }
  bool ContE1  (char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_e1) ? true : false; }
  bool ContE2  (char VarFlags = 0) { return (Flags(VarFlags)&MKN_PARAM_ORB_e2) ? true : false; }
  bool ContE12 (char VarFlags = 0) { return ((Flags(VarFlags)&MKN_PARAM_ORB_e1) && (Flags(VarFlags)&MKN_PARAM_ORB_e2)); }
  //

protected :
  int ValiKS( ) { if ( ks < 0 ) return 0 ; if ( ks > 2 ) return 2 ; return ks ; }

public :
  //
  int   SizeID () { return(sizeof(*this) - 6 * sizeof(int)); }
  void* PointID() { return((void*)&ks); }
  //
  int  DemandsKeyBreak;
  int  SecondDemandsKeyBreak;
  // Ключ требуемых параметров на правом конце траектории
  int  DemandsKey;			
  // Ключ дополнительных (не обязательных) требуемых параметров 
  // на правом конце траектории
  int  SecondDemandsKey;	
  int  TypeKA;
  int  TypeORB;
  // Исходные данные
  int  ks;
  int  subks;
  int  ndu;
  long ka[3];
  int  orb[3];
  int  var[3];
  //
  double parama[3];
  double paramT[3];
  double paramL[3];
  double paramdL[3];
  double paramhs[3];
  double paramh[3];
  double paramBh[3];
  char   paramV[3];
  double parame[3];
  double paramw[3];
  double paramu[3];
  double paramt[3];
  double m[3];
  double p[3];
  //
  char   varimpid;
  //
  int    keynu[3][4];
  int    vit[3];
  int    vitimp[3][3];
  int    skimp[3][3];
  double uimp[3][3];
  // Данные для теста
  char   TestVar ;
  int    TestKeyNU[3][4];
  int    TestNImp[3];
  int    TestZVit[3];
  int    TestSk[3][3];
  int    TestVit[3][3];
  double TestArg[3][3];
  double TestTime[3][3];
  double TestdV[3][3];
  double Testdt[3][3];
  double TestM[3];
  double TestP[3];
} ;

//-----------------------------------------------------------------------------
// Параметры орбиты на заданный момент времени
// Характерная точка орбиты
//-----------------------------------------------------------------------------

// Тип характерной точки
enum TypeOrbSetPOint { 
	timesetpoin = 0,  // Точка на орбите задаётся моментом времени
	argsetpoint = 1   // Точка на орбите задаётся аргументом широты  
};

//ParamMDT
struct ZSOrbSetPoint {
	ZSOrbSetPoint() { memset(this, 0, sizeof(*this)); }
	TypeOrbSetPOint Type = timesetpoin;
	double t;		// Время [ссс]
	double u;		// [град]
	long   Vit;		// Виток
	struct {		// Дата
	int    d, m, g;
	} Dt ;
	struct {		// Время
	int    h, m, s;
	} Tm;
	double T;		// Период оскулирующий[сек]
	double HBLR[4];	// Высота, широта, долгота и радиус 
};					// на момент времени t [км,град]

//-----------------------------------------------------------------------------
// Параметры орбиты на витке
struct ZSLoopFact {
	long   Vit;   // Виток
	double t;     // Время
	DATE   Dt;
	TIME   Tt;
	double T;     // Период драконический [сек]
	double Tss;   // Период драконический среднесуточный [сек]
	double dTv;   // Падение драконического периода за виток
	double Hs;    // Средняя высота орбиты на витке
	double dLs;   // Суточное смещение трассы полёта
	double dLv;   // Межвитковое расстояние
	double L;     // Долгота начала витка [град]
	double Ns;    // кратность орбиты
	double Nvs;   // Номер суточного витка
	double hmin;  // Минимальная высота [км]
	double Bhmin; // Широта минимальной высоты [град]
	double Uhmin; // Аргумент широты минимальной высоты
	double hmax;  // Минимальная высота [км]
	double Bhmax; // Широта минимальной высоты [град]
	double Uhmax; // Аргумент широты максимальной высоты
	double a;     // большая полуось на момент начала витка
	double e;     // Эксцентриситет на момент начала витка
	double e1;    //
	double e2;    //
	double i;     // наклонение на момент начала витка
	double w;     // Положение перигея на момент начала витка [град]
	double u;
	double Ro[4]; // радиусы в узловых точках
	double up;    // аргумент широты характерной на витке точки
	double tp;    // время характерной на витке точки
	// Характерная точка орбиты
	ZSOrbSetPoint SP;	
} ;

//-----------------------------------------------------------------------------
// Управление
struct ZSFlightRule {
	int    plane ;				// Номер выбранной схемы
	int    n ;					// Число импульсов
	int    sk [M_MAXPU_SIZE] ;	// Ориантация импульсов
	long   vit[M_MAXPU_SIZE] ;	// Витки импульсов
	double u0 [M_MAXPU_SIZE] ;	// Аргументы приложения импульсов (середина активного участка)
	double us [M_MAXPU_SIZE] ;	// Аргументы широты начала каждого активного участка
	double vs [M_MAXPU_SIZE] ;	// 
	double ue [M_MAXPU_SIZE] ;	// Аргументы широты конца каждого активного участка
	double ve [M_MAXPU_SIZE] ;	// 
	bool   uw [M_MAXPU_SIZE] ;	// Признак приложения импульса в перицентре орбиты
	double dV [M_MAXPU_SIZE] ;	// Импульсы скорости суммарные с учетом импульса последействия
	double t  [M_MAXPU_SIZE] ;	// Время включения ДУ - атомное в ссс
	double dt [M_MAXPU_SIZE] ;	// Длительность работы ДУ до отсечки тяги
	double dts[M_MAXPU_SIZE] ;	// Длительность работы ДУ с импульсом последействия
	double tm[M_MAXPU_SIZE] ;	// Длительность основного участка работы ДУ
	double alf[M_MAXPU_SIZE] ;
	double bet[M_MAXPU_SIZE] ;
	bool   isFixedArg ;			// Признак фиксированных аргументов
} ;

//-----------------------------------------------------------------------------
// Значения производных от элементов движения по некоторпому параметру,
// например по величи не трансверсального импульса.
struct ZSLnsNpmDiffDV { //	Производны для:  
	double da,		// - большой полуоси, [км /...]; 
		   de,		// - эксцентриситета, [бр /...];  
		   de1,		// - компоненты e1 вектора эксцентриситета, [бр /...]; 
		   de2,		// - компоненты e2 вектора эксцентриситета, [бр /...]; 
		   dw,		// - положения перигея орбиты, [град /...]; 
		   du,		// - положения КА вдоль орбиты, фазы, [град /...]; 
		   dT,		// - драконического периода обращения, [сек /...]; 
		   dL,		// - долготы восходящего узла орбиты, [град /...]; 
		   dLsimpl,	// 
		   dLdu,	// - производная от долготы ВУ орбиты по изменению 
					// - фазы (аргумента широты) КА вдоль орбиты;
		   dhp,		// - высоты перигея орбиты, [км /...]; 
		   dha;		// - высоты апогея орбиты, [км /...]. 
} ;

//-----------------------------------------------------------------------------
// Параметры орбиты проектируемой специальной
// В зависимости от решаемой задачи требуемая в результате менёвра орбита может 
// быть либо простой эллиптической, либо орбитой минимального изменения высооты (ОМИВ),
// либо динамически устойчивой (ДУ), либо солнечно-синхронной (ССО), возможны также 
// варианты ДУ-ССО или ОМИВ-ССО.
// Задаваться такая орбита может либо драконическим периодом, либо большой полуосью,
// либо высотой средней или минимальной. Остальные параметры выбираются исходя из класса
// орбиты.
// Например наклонение i исходя из условия солнечной синхронности
// геометрия e+w или e1+e2 из условия минимального изменения высоты или динамической устойчивости  
// Такой выбор параметров называется проектированием орбмты.
// Самый простой вариант проектирования когда эллиптическая орбита задана свим периодом и 
// частично геометрией (e+w или e1+e2) и необходимо вычислить большую полуось этой орбиты 
struct ZSSpoOrb {
	double i,	//
		   T,	// Драконический период
		   a,	//
		   p,	//
		   e,	//
		   w,
		   e1,	// e * cos( w ) ;
		   e2,	// e * sin( w ) ;
		   uh,	// широта экстремальной высоты (только для эл. орбиты)
		   Q[6];// координаты в ГСК
};

//-----------------------------------------------------------------------------
struct ZSLnsNpmFaultPO {
	double T = 0, // Драконический период	
		a = 0, //
		p = 0, //
		e = 0, //
		w = 0,
		e1= 0, // e * cos( w ) ;
		e2= 0, // e * sin( w ) ;
		uh= 0, // широта экстремальной высоты (только для эл. орбиты)
		h = 0, //
		Bh= 0, //
		L = 0, //
		dL= 0; //
};

//-----------------------------------------------------------------------------
// Структура невязок метода узловых точек в этих самых узловых точках
struct ZSLnsNpmFault {
	double l   = 0,
		   dR1 = 0,
		   dR2 = 0,
		   dRs = 0,
		   dR0 = 0,
		   u0  = 0,
		   de1 = 0,
		   de2 = 0;
};

//-----------------------------------------------------------------------------
// Требуемые параметры движения - описание условий накладываемых на правый
// конец оптимизируемой траектории движения КА.
// Class (C) LNS Node points method (Npm) Claim
class FLYMAGICLNS_API ZCLnsNpmClaim {
public :
	ZCLnsNpmClaim()  { Clr(); };
	~ZCLnsNpmClaim() { };
	void* Ptr() { return(this); }
	void  Clr() { memset(Ptr(), 0, Len()); }
	int   Len() { return (sizeof(*this)); }
	//
	int    VarKor,	// Условный номер варианта: 11,12,13,...,20,21,...,32,33
		   VarOrb,	// Орбита: эллипс (0), ОМИВ (1), ДУ (2)
		   VarPar,	// Заданный параметр: T (0), Hср (1), Nсут + dLсут (2), Наклонение ССО (3)
		   Vit;		// Заданный вииток
	double L,		// Требуемая долгота
		   T,		// Требуемый период (Драконический)
		   Hs,		// Требуемая высота
		   Hmax,	// Требуемая высота
		   Hmin;	// Требуемая высота
	int    VarH,	// высота: минимальная (0), максимальная (1), средняя (2)
		   VarB;	// ветвь: восходящая (0), нисходящая (1)
	double BH,		// Требуемая широта экстримальной высоты
		   uH,		// Аргумент широты требуемой широта экстримальной высоты
		   N,		// Кратность орбиты (число витков в сутки)
		   dL,		// Требуемое суточное смещение
		   a,		// Требуемая полуось
		   p,		// Фокальный параметр
		   e,		// Требуемый эксцентриситет
		   w,		// Требуемое пололожение перигея
		   e1,		// Требуемый вектор эксцентриситета e*cos(w) e*sin(w)
		   e2, 		//
		   i, 		// Требуемое наклонение
		   u, 		// Требуемый оскулирующий аргумент широты
		   t,		// Требуемый момент оскуляции
		   Ro[4];	// Радиусы в узловых точках тредуемой орбиты
} ;

//-----------------------------------------------------------------------------
// Данные решаемой задачи
struct ZSMagicLnsSolution {
	ZCLnsNpmJob MZ;			// Задание на решение задачи
	ZSLnsNpmPar MP;			// Параметризация задачи
	ZCDU		DU;			// Описание характеристик двигательной установки
	int			GlobCount;	// Число итераций за которые решается задача
};

//-----------------------------------------------------------------------------
FLYMAGICLNS_API ZSMagicLnsSolution* CreateMagicLnsSolution();
FLYMAGICLNS_API void FreeMagicLnsSolution(ZSMagicLnsSolution* MS);

FLYMAGICLNS_API void operator << (ZSLoopFact& P, ZSC_VI& FV);
FLYMAGICLNS_API void operator << (ZSLoopFact& P, ZSC_VI* FV);

class ZCPrintManager;

//-----------------------------------------------------------------------------
// Документирование результатов решения задачи расчёта параметров управлени 
// движением ЦМ КА
FLYMAGICLNS_API int  MagicSolutionPrint(
		ZSMagicLnsSolution *MS,		// Исходные данны для задачи
		ZCPrintManager *PrintMng,	// Диспетчер документирования
		FILE        *pf,			// файл документа
		ZMSC        &KA,			// Модель движения.
									// Параметры движения КА:
		ZSLoopFact  &P1,			// - после первого имульса;
		ZSLoopFact  &P2,			// - после второго имульса;
		ZSLoopFact  &PN,			// - на заданном витке в пассивном полёте;
		ZSLoopFact  &PR,			// - расчётные на заданном витке;
		ZSC_SI      *SI,			// - на начало заданного витка;
		ZSC_VI      *VI,			// - интегральные на заданном витке.
		ZSFlightRule &U,			// Пар-ы расчитанной программы управления
		ZNU      *RIKNU);			// НУ с РИК, для каждого импульса

//-----------------------------------------------------------------------------
// Функции реализующие итерационный процесс решения задачи расчёта параметров
// программы управления движением КА по методу узловых точек
//-----------------------------------------------------------------------------

// Моделирование движения КА с учётом программы управления его движением
FLYMAGICLNS_API int  ControlImplementation(
		ZMSC &KA,		// Модель движения.
		ZNU  &NU,		// Начальные условия движения КА.
		ZCDU &DU,		// Описание характеристик двигательной установки.
		ZSFlightRule& U,// Пар-ы расчитанной программы управления.
		ZSC_SI *SI,		// Пар-ы движения на начало заданного витка
		ZSC_VI *VI,		// Интегральные пар-ы движения на заданном витке
		ZNU    *RIKNU);	// НУ с РИК, для каждого импульса

// Выход на начало заданного витка - начальные параметры движния 
// на заданный виток. Моделирование данного витка
FLYMAGICLNS_API int	 ModelForcingGivenTurn(
		ZCLnsNpmJob &MZ,	// Задание на решение задачи
		ZMSC		&KA,	// Модель движения.
		long		vz,		// Заданный, моделируемый виток 
		ZSC_SI		&SI,	// Пар-ы движения на начало заданного витка
		ZSC_VI		&VI,	// Интегральные пар-ы движения на заданном витке
		ZSLoopFact	&PN);	// Значение краевых условий метода узловых точек 

// Формирование структуры начальных заданных параметров
FLYMAGICLNS_API void DemandInit(ZCLnsNpmJob& MZ, ZSLoopFact& PN, ZCLnsNpmClaim &PTN);
FLYMAGICLNS_API void DemandIncrement(ZCLnsNpmJob& MZ, ZSLnsNpmPar& MP, ZCLnsNpmClaim &PTN, 
							ZSLoopFact& PR, ZCLnsNpmClaim &PTT);

// Аналитический расчёт параметров программы управления
FLYMAGICLNS_API int  LNSMagicBox(ZSMagicLnsSolution* MS, ZSLoopFact& P1,
	ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT,
	ZSFlightRule& U);

// Проверка условия завершения итерационного цикла решения задачи
FLYMAGICLNS_API bool MagicIsNeedBreak(ZSMagicLnsSolution* MS, ZCLnsNpmClaim& PTN,
	ZSLoopFact& PR);

// Формирование программы управления движением КА в структуре (ZPU PU) 
// необходимой для численной реализации траектории полёта с активным 
// участком посредством модели движения. 
// Исходными данными являются аналитическое решение ZSFlightRule U,
// характеристики двигательной установки ZCDU DU, 
// начальная масса КА (double m0).
FLYMAGICLNS_API int  MagicMakePU(int NumPU, double m0, double* dms,
	ZSFlightRule& U, ZCDU& DU, ZPU& PU,
	int is =-1, int ie =-1);

// Документирование результатов одной итерации метода узловых точек
FLYMAGICLNS_API void MagicPrint(ZSMagicLnsSolution* MS,
	ZCPrintManager* PrintMng, FILE* fp,
	ZSLoopFact& P1, ZSLoopFact& P2, ZSLoopFact& PN,
	ZSLoopFact& PR, ZSFlightRule& U, int NumIter = -1);

//-----------------------------------------------------------------------------
// Проектирование орбиты
//-----------------------------------------------------------------------------
FLYMAGICLNS_API int  MagicBuildSpo(ZCLnsNpmClaim& TZ, ZSSpoOrb& SP, char* Msg = NULL);

//-----------------------------------------------------------------------------
// Функции реализующие вычисление параметров управления движением КА
// по методу узловых точек
//-----------------------------------------------------------------------------

// Вспомогательные функции, используемые в процедурах MagicCalcU... 
FLYMAGICLNS_API int  MagicCalcR(double i, double p, double e1, double e2, double* R);
FLYMAGICLNS_API int  MagicCalcMishit(double i, double p, double e1, double e2, 
							 ZSLoopFact& P1, ZSLoopFact& PZ, double* Rt, ZSLnsNpmFault& P);
FLYMAGICLNS_API int  MagicCalcMishitUKondor(double uf, double tf, double tN, 
							 double Tpr, double& du);

FLYMAGICLNS_API int  MagicCalcDifDV(double a, double e, double i, double w, 
							 double u, double up, double dN, ZSLnsNpmDiffDV& D);
FLYMAGICLNS_API int  MagicUT1(ZSMagicLnsSolution* MS, int dN, int kp, double dtQ1, 
							  ZSLoopFact& P1, double u1, double *V1, double *PV1);
FLYMAGICLNS_API int  MagicUT2(ZSMagicLnsSolution* MS, int dN1, int dN2, int kp, 
					          int pru, double dtQ1, double dtQ2, double u1, double u2, 
							  ZSLoopFact& P1, ZSLoopFact& P2, 
							  double *V1, double *V2, double *PV1, double *PV2);
FLYMAGICLNS_API int  MagicIZM(ZSMagicLnsSolution* MS, double a0, double e0, double i0, 
							  double w0, int dN, double u1, double V1, ZSLnsNpmDiffDV& DP);
FLYMAGICLNS_API int  MagicAD12FromHBh(ZSMagicLnsSolution* MS, 
							  ZSLoopFact& P1, ZSLoopFact& PZ, ZCLnsNpmClaim& PT,
							  double& A1, double& A2, double& D1, double& D2);

// Расчёт управлений для одно-импульсных коррекций
FLYMAGICLNS_API int MagicCalcU10(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU11(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU12(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU13(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU14(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU15(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU16(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU17(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU18(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);

// Расчёт управлений для двух-импульсных коррекций
FLYMAGICLNS_API int MagicCalcU20(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT, 
							ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU21(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT, 
							ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU22(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT, 
							ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU23(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT, 
							ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU24(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT, 
							ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU241(ZSMagicLnsSolution* MS, ZSLoopFact& P1,
							ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT,
							ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU25(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT, 
							ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU26(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT, 
							ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU27(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT, 
							ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU28(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT, 
							ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU29(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT, 
							ZSFlightRule& U);

// Расчёт управлений для трёх-импульсных коррекций
FLYMAGICLNS_API int MagicCalcU30(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU31(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU311(ZSMagicLnsSolution* MS, ZSLoopFact& P1,
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU32(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);
FLYMAGICLNS_API int MagicCalcU33(ZSMagicLnsSolution* MS, ZSLoopFact& P1, 
							ZSLoopFact& PZ, ZCLnsNpmClaim& PT, ZSFlightRule& U);

//-----------------------------------------------------------------------------
#endif // #define MAGIC_LNS_H