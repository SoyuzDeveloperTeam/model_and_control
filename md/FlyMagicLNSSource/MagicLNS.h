//-----------------------------------------------------------------------------
// MagicLNS.h 
// �. ��������� 04.10.2018
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

// ������������ ����� ������������� �����
enum ZESpoOrbType {
	SpoEl=0,   SpohBh=1,   SpoOmiv=2,   SpoDu=3, 
	SpoElSS=4, SpohBhSS=5, SpoOmivSS=6, SpoDuSS=7,
	SpoSh=8,   SpoShSS=9
};

//-----------------------------------------------------------------------------
// ��������� ������� ������ ������� ������� �����
// Struct (S) LNS Node points method (Npm) Parameterization (Par)
//-----------------------------------------------------------------------------
struct ZSLnsNpmPar {
  int	 maxIter = 50;	 // ������������ ����� ��������
  // ���������� �������������� ������������� �������� ������� ���������� 
  // ���������� ��������� ������ ���� ������� ������� �����
  double epsT = 0.001,   // ���
		 epsL = 0.001,   // ����
		 epsdL= 0.0001,  // ���� / ���
		 epsu = 0.001,   // ����
		 epsH = 0.0001,  // ��
		 epsBH= 0.01,    // ����
		 epsa = 0.00001, // ��
		 epse = 0.0001,  //
		 epsw = 0.1;     // ����

  bool   IsValiFaze ;
  char	 isEstimateOrb    = 0,	// ������� ��������� ����� ������ �� ���������
		 isEstimateOrb_e12= 1,	// ������� ��������� ������� ���������������
		 isEstimateOrb_e  = 1,	// ������� ��������� ���������������
		 isEstimateOrb_w  = 1,	// ������� ��������� ��������� �������
		 isEstimateOrb_h  = 1,	// ������� ��������� ������������� ������
		 isEstimateOrb_Bh = 1,	// ������� ��������� ������ ����. ������
		 Epoha    = 2,	// ������� �����.	
		 // ����������� ��������� ���������� ��� ���������������� � �����������.
		 ViewDimT = 0,	// ����������� ������� ��� ����������������.
		 ViewDimL = 1,	// ����������� ������� ��� ����������������.
		 ViewDimdL= 1,	// ... ���������� ����������� ������ ���������� 
		 ViewDimw = 1,	// ���������� ����������������.
		 ViewDimBh= 1,	// ...
		 ViewDimu = 1,	//
		 ViewDimdV= 0,	// ����������� �������� �������� ����� ��� �� � �������.
		 ViewDimdt= 0,	// ����������� ������������ ��������.
		 // ���������� ����������� �������
		 RezSaveNU    = 2,	// ������� ���������� �� 
		 RezSaveNUNom = 1,	//
		 RezSaveNUMod = 0,	//
		 RezSavePULast= 1,	// ������� ���������� ����������� ����. ����������
		 RezUseLHS    = 0,
		 RezSaveFOFrom  = 1,
		 RezSaveFODbl   = 0,
		 // �������������� ���������������� ����������� ������� ������ 
		 // ��������� ������� ������� �����
		 RezSaveDocFull = 1,    // ������� ������������ ������� ���������.
		 RezSaveDocDsk  = 1,    // ���������������� �������� ������.
		 RezSaveDocDU   = 0,    // ���-� ������������� ������������ ���������.
		 RezSaveDocLHS  = 1,    // ���-� ���������� ����� ���.
		 RezSaveDocLHSShort = 0,// ����������� ���������������� ���.
		 RezSaveDocINU  = 1,	// ���-� �������� ��.
		 RezSaveDocINUShort = 0,// ����������� ���������������� �������� ��.
		 RezSaveDocNUR  = 1,	// ���������������� �� � ���.
		 RezSaveDocNURShort = 0,// ����������� ���������������� �� � ���.
		 RezSaveDocRV   = 1,	// ���-� ���������� ��������.
		 RezSaveDocPU   = 1,	// ���-� ����-�� ��������� ����������.
		 RezSaveDocFO   = 1,	// ���-� ���� ������ ��.
		 RezSaveDocSVER = 1;	// ���������������� ������� ��� ������.
  int	 RezUseLHSNum = 1;		// ������������ �� ��������� ����� ���
};

FLYMAGICLNS_API void DefaultParam(ZSLnsNpmPar& P);

//-----------------------------------------------------------------------------
// �������� ������ ��� ������� ������
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
  // ����� ��������� �������
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
  // �������� ����� ������� �� ������� ������ � ������ (��������)
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
  // ������������ ������� �� ���������� ��������
  bool IsEnableVar( int Var =-1, int Ks =-1 ) {
    int iks= Ks  >= 0 ? Ks : ks ;
    int iv = Var >= 0 ? Var : VAR( ) ;
    int it = TASK( iv ) ;
    int io = ORB( ) ;
    return ( IsEnableTask( it, iks, io ) ) ;
  }
  // ������������ ������� ��������� ������
  bool IsEnableTask( int it, int Ks =-1, int Orb =-1 ) {
    int iks= Ks >= 0 ? Ks  : ks ;
    int io = Orb>= 0 ? Orb : ORB( ) ;
    // ����� ��
    if ( it == 0 || it == 10 || it == 20 || it == 30 ) return 1 ;
    // ������
    if ( ks <= 0 ) {
      if ((it>=11 && it<=13) || (it>=110 && it<=113) || it == 121 || 
	  (it >= 15 && it <= 16 ) ||
      (it==14 && io==0) ||
      (it==21 ) || (it==22 && io==0) ||
	  (it >= 23 && it <= 24) || it == 241 || (it == 25 && io == 0) ||
	  (it >= 26 && it <= 29) || it == 31 || it == 311) return 1;
    }
    // ������
    if ( ks == 1 ) {
      if ( ( it >= 11 && it <= 13 ) || it == 121 || ( it == 14 && io  ) ||
	  (it == 21) || (it == 22 && io) || (it >= 23 && it <= 24) || it == 241 ||
      ( it == 25 && io ) || ( it == 26 ) ||
	  (it >= 31 && it <= 33) || (it == 311) ) return 1;
    }
    // �����
    if ( ks >= 2 ) {
      if ( ( it >= 15 && it <= 18 ) || ( it >= 27 && it <= 29 ) ) return 1 ;
    }
    return 0 ;
  }
  //
  bool GetVarText( char* Text, int Var =-1, int Orb =-1 ) {
    int io = Orb >= 0 ? Orb : ORB() ;
    int iv = Var >= 0 ? Var : VAR() ;
	// ������ e,w
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
      case 25: sprintf(Text, "00)  ����" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    } 
	// ������ hBh
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
      case 25: sprintf(Text, "00)  ����" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    }
	// ���� 
    if ( io == 2 ) { 
      switch( iv ) {
      case 0 : sprintf(Text, "10)  a  + ����" ) ; break ;
      case 1 : sprintf(Text, "11)  T  + ����" ) ; break ;
      case 2 : sprintf(Text, "12)  L  + ����" ) ; break ;
      case 3 : sprintf(Text, "13)  dL + ����" ) ; break ;
      case 4 : sprintf(Text, "14)  Hs + ����" ) ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      case 9 : sprintf(Text, "20)  a, ����" ) ; break ;
      case 10: sprintf(Text, "21)  T, ����" ) ; break ;
      case 11: sprintf(Text, "22)  Hs, ����" ) ; break ;
      case 12: sprintf(Text, "23)  dL, ����" ) ; break ;
      case 13: sprintf(Text, "24)  L, T + ����" ) ; break ;
      case 14: sprintf(Text, "25)  L, h + ����" ) ; break ;
      case 15: sprintf(Text, "26)  L, dL + ����" ) ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: sprintf(Text, "241)  u, T + ����"); break;
      //
      case 20: sprintf(Text, "30)  L, a, ����" ) ; break ;
      case 21: sprintf(Text, "31)  L, T, ����" ) ; break ;
	  case 22: sprintf(Text, "311) u, T, ����"); break;
      case 23: sprintf(Text, "32)  L, h, ����" ) ; break ;
      case 24: sprintf(Text, "33)  L, dL,����" ) ; break ;
      case 25: sprintf(Text, "00)  ����" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    } 
    if ( io == 3 ) { 
      switch( iv ) {
      case 0 : sprintf(Text, "10)  a  + ��" ) ; break ;
      case 1 : sprintf(Text, "11)  T  + ��" ) ; break ;
      case 2 : sprintf(Text, "12)  L  + ��" ) ; break ;
      case 3 : sprintf(Text, "13)  dL + ��" ) ; break ;
      case 4 : sprintf(Text, "14)  Hs + ��" ) ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      case 9 : sprintf(Text, "20)  a, ��" ) ; break ;
      case 10: sprintf(Text, "21)  T, ��" ) ; break ;
      case 11: sprintf(Text, "22)  Hs, ��" ) ; break ;
      case 12: sprintf(Text, "23)  dL, ��" ) ; break ;
      case 13: sprintf(Text, "24)  L, T + ��" ) ; break ;
      case 14: sprintf(Text, "25)  L, h + ��" ) ; break ;
      case 15: sprintf(Text, "26)  L, dL + ��" ) ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: sprintf(Text, "241)  u, T + ��"); break;
      //
      case 20: sprintf(Text, "30)  L, a, ��" ) ; break ;
      case 21: sprintf(Text, "31)  L, T, ��" ) ; break ;
	  case 22: sprintf(Text, "311) u, T, ��"); break;
      case 23: sprintf(Text, "32)  L, h, ��" ) ; break ;
      case 24: sprintf(Text, "33)  L, dL, ��" ) ; break ;
      case 25: sprintf(Text, "00)  ����" ) ; break ;
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
      case 0 : sprintf( Text, "�������������� ���������\n\
������� ������� � ������������ ������������\n\
��������� ������ � ���������.\0" ) ; break ;
      case 1 : sprintf( Text, "�������������� ���������\n\
�������������� ������� ��������� � ������������\n\
������������ ��������� ������ � ���������.\0" ) ; break ;
      case 2 : sprintf( Text, "�������������� ���������\n\
������� ������ ��������� ����� � ������������\n\
������������ ��������� ������ � ���������.\0" ) ; break ;
      case 3 : sprintf( Text, "�������������� ���������\n\
��������� �������� ������ � ������������\n\
������������ ��������� ������ � ���������.\0" ) ; break ;
      case 4 : sprintf( Text, "�������������� ���������\n\
����������� ������ � ������������ ������������\n\
��������� ������ � ���������.\0" ) ; break ;
      case 5 : sprintf( Text, "�������������� ���������\n\
�������������� ������� ��������� � ������������\n\
������������ ��������� ���������� ������ � ��������� ��������.\0" ) ; break ;
      case 6 : sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ � ������������\n\
������������ ��������� ���������� ������ � ��������� ��������.\0" ) ; break ;
      case 7 : sprintf( Text, "�������������� ���������\n\
�������������� ������� ���������.\0" ) ; break ;
      case 8 : sprintf( Text, "�������������� ��������� �������\n\
����������� ���� ������.\0" ) ; break ;
      //
      case 9 : sprintf( Text, "�������������� ���������\n\
������� ������� � ��������� ������ �� �������� �����\0" ) ; break ;
      case 10: sprintf( Text, "�������������� ���������\n\
�������������� ������� ���������, � ��������� ������ �� �������� �����" ) ; break ;
      case 11: sprintf( Text, "�������������� ���������\n\
������� ������, � ��������� ������ �� �������� �����" ) ; break ;

      case 12: sprintf( Text, "�������������� ���������\n\
c�������� ������ ������� � ��������� ������ �� �������� �����\0" ) ; break ;
      case 13: sprintf( Text, "�������������� ���������\n\
�������������� ������� ��������� � ������� ����������� ������ �� �������� �����\n\
� ������������ ������������ �������� ������ � ���������" ) ; break ;
      case 14: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ � ������� ������ �� �������� �����\n\
� ������������ ������������ ��������� ������ � ���������" ) ; break ;
      case 15: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ � ������ ������� �� �������� �����\n\
� ������������ ������������ ��������� ������ � ���������" ) ; break ;
      case 16: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ � �������������� ������� �� �������� �����\n\
� ������������ ������������ ��������� ������� � ���������� ��������" ) ; break ;
      case 17: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ � �������������� ������� �� �������� �����\0" ) ; break ;
      case 18: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� � ��������� ������� ������ �� �������� �����\0" ) ;            break ;
	  case 19: sprintf(Text, "�������������� ���������\n\
�������������� ������� ��������� � ��������� ������ �� �������� �����\n\
� ������������ ������������ �������� ������ � ���������"); break;
      //
      case 20: sprintf(Text, "�������������� ���������\n\
������������ �� �������� ����� ������� ����������� ���� ������,\n\
������� ������� � ��������� ������.\0" ) ; break ;
      case 21: sprintf(Text, "�������������� ���������\n\
������������ �� �������� ����� ������� ����������� ���� ������,\n\
�������������� ������� ��������� � ��������� ������.\0" ) ; break ;
	  case 22: sprintf(Text, "�������������� ���������\n\
��������� ������ �� � �������� ������ �������,\n\
�������������� ������� ��������� � ��������� ������.\0"); break;
      case 23: sprintf(Text, "�������������� ���������\n\
������������ �� �������� ����� ������� ����������� ���� ������,\n\
������� ������ � ��������� ������.\0" ) ; break ;
      case 24: sprintf(Text, "�������������� ���������\n\
������������ �� �������� ����� ������� ����������� ���� ������,\n\
������ ������� � ��������� ������.\0" ) ; break ;
      case 25: sprintf(Text, "������������� �������� ���������,\n\
� ��������� ���������� �������� ����� ������� �������� � �� �������� �����\0" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    }
    if ( io == 1 ) {
      switch( iv ) {
      case 0 : sprintf( Text, "�������������� ���������\n\
������� ������� � ������������ ������������\n\
����������� ������ � � ������ � ��������� ���������\0" ) ; break ;
      case 1 : sprintf( Text, "�������������� ���������\n\
�������������� ������� ��������� � ������������ ������������\n\
����������� ������ � � ������ � ��������� ���������\0" ) ; break ;
      case 2 : sprintf( Text, "�������������� ���������\n\
������� ������ ��������� ����� � ������������ ������������\n\
����������� ������ � � ������ � ��������� ���������\0" ) ; break ;
      case 3 : sprintf( Text, "�������������� ���������\n\
��������� �������� ������ ����� � ������������ ������������\n\
����������� ������ � � ������ � ��������� ���������\0" ) ; break ;
      case 4 : sprintf( Text, "�������������� ���������\n\
����������� ������ � ������������ ������������\n\
� ������ � ���������� ��������\0" ) ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      //
      case 9 : sprintf( Text, "�������������� ���������\n\
������� �������, ����������� ������ � ������ ����������� ������\0" ) ; break ;
      case 10: sprintf( Text, "�������������� ���������\n\
�������������� ������� ���������,\n\
����������� ������ � ������ ����������� ������" ) ; break ;
      case 11: assert(0) ;
      case 12: sprintf( Text, "�������������� ���������\n\
��������� ������ �������, ���������� ������ � � ������ �� �������� �����\0" ) ; break ;
      case 13: sprintf( Text, "�������������� ���������\n\
�������������� ������� ��������� � ������� ����������� ���� ������ �� �������� �����\n\
� ������������ ������������ ����������� ������ � � ������ � ��������� ���������" ) ; break ;
      case 14: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ � ����������� ������ �� �������� �����\n\
� ������������ ������������ ������ ����������� ������ � ����������� ��������" ) ; break ;
      case 15: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ �� �������� �����, ����������� ������\n\
� ������������ ������������ ������ ����������� ������ � � ��������� ��������" ) ;      break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: sprintf(Text, "�������������� ���������\n\
�������������� ������� ��������� � ��������� ������ �� �������� �����\n\
� ������������ ������������ ����������� ������ � � ������ � ��������� ���������"); break;
      //
      case 20: sprintf( Text, "�������������� ���������\n\
������������ �� �������� ����� ������� ����������� ���� ������,\n\
������� �������, ����������� ������ � ������ ����������� ������.\0" ) ; break ;
      case 21: sprintf( Text, "�������������� ���������\n\
������������ �� �������� ����� ������� ����������� ����,\n\
�������������� ������� ���������,\n\
����������� ������ � ������ ����������� ������.\0" ) ; break ;
	  case 22: sprintf(Text, "�������������� ���������\n\
��������� ������ �� � �������� ������ �������,\n\
�������������� ������� ���������,\n\
����������� ������ � ������ ����������� ������.\0"); break;
      case 23: sprintf( Text, "�������������� ���������\n\
������������ �� �������� ����� ������� ����������� ���� ������,\n\
������� ������, ����������� ������ � ������ ����������� ������.\0" ) ; break ;
      case 24: sprintf( Text, "�������������� ���������\n\
������������ �� �������� ����� ������� ����������� ���� ������,\n\
������ �������, ����������� ������ � ������ ����������� ������.\0" ) ; break ;
      case 25: sprintf( Text, "������������� �������� ���������,\n\
� ��������� ���������� �������� ����� ������� �������� � �� �������� �����\0" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    }
    if ( io == 2 ) {
      switch( iv ) {
      case 0 : sprintf( Text, "�������������� ���������\n\
������� ������� � ������������ ������������\n\
��������� ������ � ����\0" ) ; break ;
      case 1 : sprintf( Text, "�������������� ���������\n\
�������������� ������� ��������� � ������������ ������������\n\
��������� ������ � ����\0" ) ; break ;
      case 2 : sprintf( Text, "�������������� ���������\n\
������� ������ ��������� ����� � ������������ ������������\n\
��������� ������ � ����\0" ) ; break ;
      case 3 : sprintf( Text, "�������������� ���������\n\
��������� �������� ������ ����� � ������������ ������������\n\
��������� ������ � ����\0" ) ; break ;
      case 4 : sprintf( Text, "�������������� ���������\n\
������� ������ � ������������ ������������\n\
��������� ������ � ����\0" ) ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      //
      case 9 : sprintf( Text, "�������������� ���������\n\
������� ������� � ��������� ���� �� �������� �����\0" ) ; break ;
      case 10: sprintf( Text, "�������������� ���������\n\
�������������� ������� ��������� � ��������� ���� �� �������� �����\0" ) ; break ;
      case 11: sprintf( Text, "�������������� ���������\n\
������� ������ ������ � ��������� ���� �� �������� �����\0" ) ; break ;
      case 12: sprintf( Text, "�������������� ���������\n\
��������� ������ ������� � ��������� ���� �� �������� �����\0" ) ; break ;
      case 13: sprintf( Text, "�������������� ���������\n\
�������������� ������� ��������� � ������� ����������� ���� ������ �� �������� �����\n\
� ������������ ������������ ��������� ������ � ����" ) ; break ;
      case 14: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ � ����������� ������ �� �������� �����\n\
� ������������ ������������ ��������� ������ � ����" ) ; break ;
      case 15: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ � ����������� ������ �� �������� �����\n\
� ������������ ������������ ��������� ������ � ����" ) ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: sprintf(Text, "�������������� ���������\n\
�������������� ������� ��������� � ��������� ������ �� �������� �����\n\
� ������������ ������������ ��������� ������ � ����"); break;
      //
      case 20: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ �� �������� �����,\n\
������� ������� � ��������� ������ �� ����.\0" ) ; break ;
      case 21: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ �� �������� �����,\n\
�������������� ������� ��������� � ��������� ������ �� ����.\0" ) ; break ;
	  case 22: sprintf(Text, "�������������� ���������\n\
��������� ������ �� � �������� ������ �������,\n\
�������������� ������� ��������� � ��������� ������ �� ����.\0"); break;
      case 23: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ �� �������� �����,\n\
������� ������ � ��������� ������ �� ����.\0" ) ; break ;
      case 24: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ �� �������� �����,\n\
��������� �������� ������ ����� � ��������� ������  �� ����.\0" ) ; break ;
      case 25: sprintf( Text, "������������� �������� ���������,\n\
� ��������� ���������� �������� ����� ������� �������� � �� �������� �����\0" ) ; break ;
      default : Text[ 0 ] = '\0' ; return 1 ;
      }
    }
    if ( io == 3 ) {
      switch( iv ) {
      case 0 : sprintf( Text, "�������������� ���������\n\
������� ������� � ������������ ������������\n\
��������� ������ � ��\0" ) ; break ;
      case 1 : sprintf( Text, "�������������� ���������\n\
�������������� ������� ��������� � ������������ ������������\n\
��������� ������ � ��\0" ) ; break ;
      case 2 : sprintf( Text, "�������������� ���������\n\
������� ������ ��������� ����� � ������������ ������������\n\
��������� ������ � ��\0" ) ; break ;
      case 3 : sprintf( Text, "�������������� ���������\n\
��������� �������� ������ ����� � ������������ ������������\n\
��������� ������ � ��\0" ) ; break ;
      case 4 : sprintf( Text, "�������������� ���������\n\
������� ������ � ������������ ������������\n\
��������� ������ � ��\0" ) ; break ;
      case 5 : 
      case 6 : 
      case 7 : 
      case 8 : assert(0) ;
      //
      case 9 : sprintf( Text, "�������������� ��������� :\n\
������� ������� � ��������� �� ������\0" ) ; break ;
      case 10: sprintf( Text, "�������������� ��������� :\n\
�������������� ������� ��������� � ��������� �� ������\0" ) ; break ;
      case 11: sprintf( Text, "�������������� ��������� :\n\
������� ������ ������ � ��������� �� ������\0" ) ; break ;
      case 12: sprintf( Text, "�������������� ��������� ������� ����������� ���� ������ \n\
� �������������� ������� ��������� �� �������� �����\n\
� ������������ ������������ ��������� ������ � �� ������\0" ) ; break ;
      case 13: sprintf( Text, "�������������� ���������\n\
�������������� ������� ��������� � ������� ����������� ���� ������ �� �������� �����\n\
� ������������ ������������ ��������� ������ � ��" ) ; break ;
      case 14: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ � ����������� ������ �� �������� �����\n\
� ������������ ������������ ��������� ������ � ��" ) ; break ;
      case 15: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ � ����������� ������ �� �������� �����\n\
� ������������ ������������ ��������� ������ � ��" ) ; break ;
      case 16: 
      case 17: 
      case 18: assert(0) ;
	  case 19: sprintf(Text, "�������������� ���������\n\
�������������� ������� ��������� � ��������� ������ �� �������� �����\n\
� ������������ ������������ ��������� ������ � ��"); break;
      //
      case 20: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ �� �������� �����,\n\
������� ������� � ��������� ������ �� ��.\0" ) ; break ;
      case 21: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ �� �������� �����,\n\
�������������� ������� ��������� � ��������� ������ �� ��.\0" ) ; break ;
	  case 22: sprintf(Text, "�������������� ���������\n\
��������� ������ �� � �������� ������ �������,\n\
�������������� ������� ��������� � ��������� ������ �� ��.\0"); break;
      case 23: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ �� �������� �����,\n\
������� ������ � ��������� ������ �� ��.\0" ) ; break ;
      case 24: sprintf( Text, "�������������� ���������\n\
������� ����������� ���� ������ �� �������� �����,\n\
��������� �������� ������ ����� � ��������� ������ �� ��.\0" ) ; break ;
      case 25: sprintf( Text, "������������� �������� ���������,\n\
� ��������� ���������� �������� ����� ������� �������� � �� �������� �����\0" ) ; break ;
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
  // ���� ��������� ���������� �� ������ ����� ����������
  int  DemandsKey;			
  // ���� �������������� (�� ������������) ��������� ���������� 
  // �� ������ ����� ����������
  int  SecondDemandsKey;	
  int  TypeKA;
  int  TypeORB;
  // �������� ������
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
  // ������ ��� �����
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
// ��������� ������ �� �������� ������ �������
// ����������� ����� ������
//-----------------------------------------------------------------------------

// ��� ����������� �����
enum TypeOrbSetPOint { 
	timesetpoin = 0,  // ����� �� ������ ������� �������� �������
	argsetpoint = 1   // ����� �� ������ ������� ���������� ������  
};

//ParamMDT
struct ZSOrbSetPoint {
	ZSOrbSetPoint() { memset(this, 0, sizeof(*this)); }
	TypeOrbSetPOint Type = timesetpoin;
	double t;		// ����� [���]
	double u;		// [����]
	long   Vit;		// �����
	struct {		// ����
	int    d, m, g;
	} Dt ;
	struct {		// �����
	int    h, m, s;
	} Tm;
	double T;		// ������ ������������[���]
	double HBLR[4];	// ������, ������, ������� � ������ 
};					// �� ������ ������� t [��,����]

//-----------------------------------------------------------------------------
// ��������� ������ �� �����
struct ZSLoopFact {
	long   Vit;   // �����
	double t;     // �����
	DATE   Dt;
	TIME   Tt;
	double T;     // ������ ������������� [���]
	double Tss;   // ������ ������������� �������������� [���]
	double dTv;   // ������� �������������� ������� �� �����
	double Hs;    // ������� ������ ������ �� �����
	double dLs;   // �������� �������� ������ �����
	double dLv;   // ����������� ����������
	double L;     // ������� ������ ����� [����]
	double Ns;    // ��������� ������
	double Nvs;   // ����� ��������� �����
	double hmin;  // ����������� ������ [��]
	double Bhmin; // ������ ����������� ������ [����]
	double Uhmin; // �������� ������ ����������� ������
	double hmax;  // ����������� ������ [��]
	double Bhmax; // ������ ����������� ������ [����]
	double Uhmax; // �������� ������ ������������ ������
	double a;     // ������� ������� �� ������ ������ �����
	double e;     // �������������� �� ������ ������ �����
	double e1;    //
	double e2;    //
	double i;     // ���������� �� ������ ������ �����
	double w;     // ��������� ������� �� ������ ������ ����� [����]
	double u;
	double Ro[4]; // ������� � ������� ������
	double up;    // �������� ������ ����������� �� ����� �����
	double tp;    // ����� ����������� �� ����� �����
	// ����������� ����� ������
	ZSOrbSetPoint SP;	
} ;

//-----------------------------------------------------------------------------
// ����������
struct ZSFlightRule {
	int    plane ;				// ����� ��������� �����
	int    n ;					// ����� ���������
	int    sk [M_MAXPU_SIZE] ;	// ���������� ���������
	long   vit[M_MAXPU_SIZE] ;	// ����� ���������
	double u0 [M_MAXPU_SIZE] ;	// ��������� ���������� ��������� (�������� ��������� �������)
	double us [M_MAXPU_SIZE] ;	// ��������� ������ ������ ������� ��������� �������
	double vs [M_MAXPU_SIZE] ;	// 
	double ue [M_MAXPU_SIZE] ;	// ��������� ������ ����� ������� ��������� �������
	double ve [M_MAXPU_SIZE] ;	// 
	bool   uw [M_MAXPU_SIZE] ;	// ������� ���������� �������� � ���������� ������
	double dV [M_MAXPU_SIZE] ;	// �������� �������� ��������� � ������ �������� �������������
	double t  [M_MAXPU_SIZE] ;	// ����� ��������� �� - ������� � ���
	double dt [M_MAXPU_SIZE] ;	// ������������ ������ �� �� ������� ����
	double dts[M_MAXPU_SIZE] ;	// ������������ ������ �� � ��������� �������������
	double tm[M_MAXPU_SIZE] ;	// ������������ ��������� ������� ������ ��
	double alf[M_MAXPU_SIZE] ;
	double bet[M_MAXPU_SIZE] ;
	bool   isFixedArg ;			// ������� ������������� ����������
} ;

//-----------------------------------------------------------------------------
// �������� ����������� �� ��������� �������� �� ����������� ���������,
// �������� �� ������ �� ���������������� ��������.
struct ZSLnsNpmDiffDV { //	���������� ���:  
	double da,		// - ������� �������, [�� /...]; 
		   de,		// - ���������������, [�� /...];  
		   de1,		// - ���������� e1 ������� ���������������, [�� /...]; 
		   de2,		// - ���������� e2 ������� ���������������, [�� /...]; 
		   dw,		// - ��������� ������� ������, [���� /...]; 
		   du,		// - ��������� �� ����� ������, ����, [���� /...]; 
		   dT,		// - �������������� ������� ���������, [��� /...]; 
		   dL,		// - ������� ����������� ���� ������, [���� /...]; 
		   dLsimpl,	// 
		   dLdu,	// - ����������� �� ������� �� ������ �� ��������� 
					// - ���� (��������� ������) �� ����� ������;
		   dhp,		// - ������ ������� ������, [�� /...]; 
		   dha;		// - ������ ������ ������, [�� /...]. 
} ;

//-----------------------------------------------------------------------------
// ��������� ������ ������������� �����������
// � ����������� �� �������� ������ ��������� � ���������� ������ ������ ����� 
// ���� ���� ������� �������������, ���� ������� ������������ ��������� ������� (����),
// ���� ����������� ���������� (��), ���� ��������-���������� (���), �������� ����� 
// �������� ��-��� ��� ����-���.
// ���������� ����� ������ ����� ���� ������������� ��������, ���� ������� ��������,
// ���� ������� ������� ��� �����������. ��������� ��������� ���������� ������ �� ������
// ������.
// �������� ���������� i ������ �� ������� ��������� ������������
// ��������� e+w ��� e1+e2 �� ������� ������������ ��������� ������ ��� ������������ ������������  
// ����� ����� ���������� ���������� ��������������� ������.
// ����� ������� ������� �������������� ����� ������������� ������ ������ ���� �������� � 
// �������� ���������� (e+w ��� e1+e2) � ���������� ��������� ������� ������� ���� ������ 
struct ZSSpoOrb {
	double i,	//
		   T,	// ������������� ������
		   a,	//
		   p,	//
		   e,	//
		   w,
		   e1,	// e * cos( w ) ;
		   e2,	// e * sin( w ) ;
		   uh,	// ������ ������������� ������ (������ ��� ��. ������)
		   Q[6];// ���������� � ���
};

//-----------------------------------------------------------------------------
struct ZSLnsNpmFaultPO {
	double T = 0, // ������������� ������	
		a = 0, //
		p = 0, //
		e = 0, //
		w = 0,
		e1= 0, // e * cos( w ) ;
		e2= 0, // e * sin( w ) ;
		uh= 0, // ������ ������������� ������ (������ ��� ��. ������)
		h = 0, //
		Bh= 0, //
		L = 0, //
		dL= 0; //
};

//-----------------------------------------------------------------------------
// ��������� ������� ������ ������� ����� � ���� ����� ������� ������
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
// ��������� ��������� �������� - �������� ������� ������������� �� ������
// ����� �������������� ���������� �������� ��.
// Class (C) LNS Node points method (Npm) Claim
class FLYMAGICLNS_API ZCLnsNpmClaim {
public :
	ZCLnsNpmClaim()  { Clr(); };
	~ZCLnsNpmClaim() { };
	void* Ptr() { return(this); }
	void  Clr() { memset(Ptr(), 0, Len()); }
	int   Len() { return (sizeof(*this)); }
	//
	int    VarKor,	// �������� ����� ��������: 11,12,13,...,20,21,...,32,33
		   VarOrb,	// ������: ������ (0), ���� (1), �� (2)
		   VarPar,	// �������� ��������: T (0), H�� (1), N��� + dL��� (2), ���������� ��� (3)
		   Vit;		// �������� ������
	double L,		// ��������� �������
		   T,		// ��������� ������ (�������������)
		   Hs,		// ��������� ������
		   Hmax,	// ��������� ������
		   Hmin;	// ��������� ������
	int    VarH,	// ������: ����������� (0), ������������ (1), ������� (2)
		   VarB;	// �����: ���������� (0), ���������� (1)
	double BH,		// ��������� ������ ������������� ������
		   uH,		// �������� ������ ��������� ������ ������������� ������
		   N,		// ��������� ������ (����� ������ � �����)
		   dL,		// ��������� �������� ��������
		   a,		// ��������� �������
		   p,		// ��������� ��������
		   e,		// ��������� ��������������
		   w,		// ��������� ����������� �������
		   e1,		// ��������� ������ ��������������� e*cos(w) e*sin(w)
		   e2, 		//
		   i, 		// ��������� ����������
		   u, 		// ��������� ������������ �������� ������
		   t,		// ��������� ������ ���������
		   Ro[4];	// ������� � ������� ������ ��������� ������
} ;

//-----------------------------------------------------------------------------
// ������ �������� ������
struct ZSMagicLnsSolution {
	ZCLnsNpmJob MZ;			// ������� �� ������� ������
	ZSLnsNpmPar MP;			// �������������� ������
	ZCDU		DU;			// �������� ������������� ������������ ���������
	int			GlobCount;	// ����� �������� �� ������� �������� ������
};

//-----------------------------------------------------------------------------
FLYMAGICLNS_API ZSMagicLnsSolution* CreateMagicLnsSolution();
FLYMAGICLNS_API void FreeMagicLnsSolution(ZSMagicLnsSolution* MS);

FLYMAGICLNS_API void operator << (ZSLoopFact& P, ZSC_VI& FV);
FLYMAGICLNS_API void operator << (ZSLoopFact& P, ZSC_VI* FV);

class ZCPrintManager;

//-----------------------------------------------------------------------------
// ���������������� ����������� ������� ������ ������� ���������� ��������� 
// ��������� �� ��
FLYMAGICLNS_API int  MagicSolutionPrint(
		ZSMagicLnsSolution *MS,		// �������� ����� ��� ������
		ZCPrintManager *PrintMng,	// ��������� ����������������
		FILE        *pf,			// ���� ���������
		ZMSC        &KA,			// ������ ��������.
									// ��������� �������� ��:
		ZSLoopFact  &P1,			// - ����� ������� �������;
		ZSLoopFact  &P2,			// - ����� ������� �������;
		ZSLoopFact  &PN,			// - �� �������� ����� � ��������� �����;
		ZSLoopFact  &PR,			// - ��������� �� �������� �����;
		ZSC_SI      *SI,			// - �� ������ ��������� �����;
		ZSC_VI      *VI,			// - ������������ �� �������� �����.
		ZSFlightRule &U,			// ���-� ����������� ��������� ����������
		ZNU      *RIKNU);			// �� � ���, ��� ������� ��������

//-----------------------------------------------------------------------------
// ������� ����������� ������������ ������� ������� ������ ������� ����������
// ��������� ���������� ��������� �� �� ������ ������� �����
//-----------------------------------------------------------------------------

// ������������� �������� �� � ������ ��������� ���������� ��� ���������
FLYMAGICLNS_API int  ControlImplementation(
		ZMSC &KA,		// ������ ��������.
		ZNU  &NU,		// ��������� ������� �������� ��.
		ZCDU &DU,		// �������� ������������� ������������ ���������.
		ZSFlightRule& U,// ���-� ����������� ��������� ����������.
		ZSC_SI *SI,		// ���-� �������� �� ������ ��������� �����
		ZSC_VI *VI,		// ������������ ���-� �������� �� �������� �����
		ZNU    *RIKNU);	// �� � ���, ��� ������� ��������

// ����� �� ������ ��������� ����� - ��������� ��������� ������� 
// �� �������� �����. ������������� ������� �����
FLYMAGICLNS_API int	 ModelForcingGivenTurn(
		ZCLnsNpmJob &MZ,	// ������� �� ������� ������
		ZMSC		&KA,	// ������ ��������.
		long		vz,		// ��������, ������������ ����� 
		ZSC_SI		&SI,	// ���-� �������� �� ������ ��������� �����
		ZSC_VI		&VI,	// ������������ ���-� �������� �� �������� �����
		ZSLoopFact	&PN);	// �������� ������� ������� ������ ������� ����� 

// ������������ ��������� ��������� �������� ����������
FLYMAGICLNS_API void DemandInit(ZCLnsNpmJob& MZ, ZSLoopFact& PN, ZCLnsNpmClaim &PTN);
FLYMAGICLNS_API void DemandIncrement(ZCLnsNpmJob& MZ, ZSLnsNpmPar& MP, ZCLnsNpmClaim &PTN, 
							ZSLoopFact& PR, ZCLnsNpmClaim &PTT);

// ������������� ������ ���������� ��������� ����������
FLYMAGICLNS_API int  LNSMagicBox(ZSMagicLnsSolution* MS, ZSLoopFact& P1,
	ZSLoopFact& P2, ZSLoopFact& PZ, ZCLnsNpmClaim& PT,
	ZSFlightRule& U);

// �������� ������� ���������� ������������� ����� ������� ������
FLYMAGICLNS_API bool MagicIsNeedBreak(ZSMagicLnsSolution* MS, ZCLnsNpmClaim& PTN,
	ZSLoopFact& PR);

// ������������ ��������� ���������� ��������� �� � ��������� (ZPU PU) 
// ����������� ��� ��������� ���������� ���������� ����� � �������� 
// �������� ����������� ������ ��������. 
// ��������� ������� �������� ������������� ������� ZSFlightRule U,
// �������������� ������������ ��������� ZCDU DU, 
// ��������� ����� �� (double m0).
FLYMAGICLNS_API int  MagicMakePU(int NumPU, double m0, double* dms,
	ZSFlightRule& U, ZCDU& DU, ZPU& PU,
	int is =-1, int ie =-1);

// ���������������� ����������� ����� �������� ������ ������� �����
FLYMAGICLNS_API void MagicPrint(ZSMagicLnsSolution* MS,
	ZCPrintManager* PrintMng, FILE* fp,
	ZSLoopFact& P1, ZSLoopFact& P2, ZSLoopFact& PN,
	ZSLoopFact& PR, ZSFlightRule& U, int NumIter = -1);

//-----------------------------------------------------------------------------
// �������������� ������
//-----------------------------------------------------------------------------
FLYMAGICLNS_API int  MagicBuildSpo(ZCLnsNpmClaim& TZ, ZSSpoOrb& SP, char* Msg = NULL);

//-----------------------------------------------------------------------------
// ������� ����������� ���������� ���������� ���������� ��������� ��
// �� ������ ������� �����
//-----------------------------------------------------------------------------

// ��������������� �������, ������������ � ���������� MagicCalcU... 
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

// ������ ���������� ��� ����-���������� ���������
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

// ������ ���������� ��� ����-���������� ���������
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

// ������ ���������� ��� ���-���������� ���������
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