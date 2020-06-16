//------------------------------------------------------------------------
// ModType.h
// �. ��������� 03.08.2018
//------------------------------------------------------------------------
#pragma warning(disable:4786)
//------------------------------------------------------------------------
#include <windows.h>
//------------------------------------------------------------------------
#include <math.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <iterator>

//------------------------------------------------------------------------
using namespace std ;
#include <FlyCoreSource\\ZCDU.h>
#include <FlyCoreSource\\ZSK.h>

//------------------------------------------------------------------------
#ifndef MODTYPE_H
#define MODTYPE_H

//------------------------------------------------------------------------
// ������� ������ ��������
//------------------------------------------------------------------------
#define   MMSG_TDU_ON			1	   // ��������� ��
#define   MMSG_TDU_STEPON		2	   // ��������� ��
#define   MMSG_TDU_STEPOFF		4	   // ��������� ��
#define   MMSG_TDU_OFF			8	   // ���������� ��
#define   MMSG_ON_KA_LIGHT		16	   // ������ ����������� ������� �����
#define   MMSG_OFF_KA_LIGHT		32	   // ������ �������� ������� �����
#define   MMSG_INIT_NU		 	64	   // ������ ������������ �� 
#define   MMSG_SET_VECTOR		128	   // ������� ������ ������� �� (����������)
#define   MMSG_START			256	   // ������ ��������������� ���������� ��������
#define   MMSG_SAVE				512	   // ���������� �������� ��������� ������
#define   MMSG_STEP				1024   // �������� ��� �������������� ��� ��������
#define   MMSG_VITOK			2048   // ����� ����� �����
#define   MMSG_RESTORY			4096   // �������������� ��������� ������ �������� �� ����� ���������� ���������� ��������
#define   MMSG_END				8192   // ���������� ��������������� ���������� ��������
#define   MMSG_EVENTFIND		16384  // ���������� ������� ��
#define   MMSG_USEREVENTFIND	32768  // ���������� ������� �� 
#define   MMSG_USER_1			65536  // 
#define   MMSG_USER_2			131072 // 
#define   MMSG_USER_3			264144 // 
#define   MMSG_USER_4			524288 // 
#define   MMSG_USER_5			1048576// 
//------------------------------------------------------------------------
// ���� ������
//------------------------------------------------------------------------
#define   RC_OK			0
#define   RC_CANCEL		-1
#define   RC_USEREXIT	50
#define   RC_OUTMEM		999
#define   RC_COUNTITER	900
//#define   RC_
//#define   RC_
//#define   RC_
//#define   RC_
//#define   RC_
//#define   RC_
//#define   RC_
//#define   RC_
//------------------------------------------------------------------------
// ������� ����������������� ��������
//----------------------------------------------------------------------------
#define    _SKT_GSK       0  // ��������� ����� 1990 ���� (��-90)
#define    _SKT_OZE       1  // ���������� ���������
#define    _SKT_EKR       2  // ��������� �����������
#define    _SKT_G_K       3  // ������� ������-�������
#define    _SKT_ITRF      4  // ITRF
#define    _SKT_WGS84     5  // WGS-84
#define    _SKT_NEU       6  // North East Up
#define    _SKT_GSK_2     7  // ��-90.2

//------------------------------------------------------------------------
// ������ ������� ��������������� ���� �����
// ������ ���     ����������� 85 ����, 90 ����, �� 90.11,  EGM 96 ����, EGM 08 ����
enum VersionGPZ  {GPZNULL =0, 
				  GPZ85=1, GPZ90=2, GPZ9011=3, 
				  GPZEGM96=4, GPZEGM2008=5,
				  GPZGEMT3=6, GPZJGM3=7};
// ������ ������� ���������
enum VersionATM  {// ����������� ������
				  ATMNULL =0, ATMSMA62=1, ATMSMA81=2, ATMSMA440181=3,
				  // ������������ ������ ���� 25645.115-... ��������� �����
				  ATMDMAGOST1977=4, ATMDMAGOST1984=5, ATMDMAGOST1990=6, ATMDMAGOST2001=7, ATMDMAGOST2004=8,
				  // MSIS
				  ATMMSIS1990=9, ATMMSIS2000=10} ;
// ������ ������� ����� ������������ �������� � ���������� ��������������� ���� �����
enum VersionTide {TIDENULL=0, TIDESTEP2=1, TIDEPOSEIDON=2} ;

//------------------------------------------------------------------------
// ���������� ����� ���, �������� �� ���������.
typedef struct ZLSF {
	int			num  = 0;			// ����� �����
	VersionGPZ	vgpz = GPZ90;		// ������� ���
	int			ngpz = 4;			// N ���������� ���
	int			mgpz = 4;			// M ���������� ���
	VersionATM	vatm = ATMSMA81;    // ������� ��������� 
	int			varsp= 0;			// 
	int			vsvd = 0;			// ������� ��������� �������� 
	VersionTide vTide= TIDESTEP2;	// ���� ��������� ��������
	bool		isDU = false;		// ���� ������������ ���������
	bool		isSun = true;       // ���� ������
	bool		isMoon = true;      // ���� ����
	bool		isPlanet[8];		// ���� ������
	ZLSF(int n=0) {
		num = n;
		memset(isPlanet, 0, 8*sizeof(bool)); // ���� ������
	}
	bool IsPlanet() { 
		for(bool b : isPlanet) if (b) return true; 
		return false; 
	}
} _ZLSF ;

//------------------------------------------------------------------------
typedef struct ZKEYNU {
	ZKEYNU() { ka=nom=mod=type=bc=0 ; }
	ZKEYNU(int _ka, int _nom, int _mod, int _type, int _bc) { ka=_ka; nom=_nom; mod=_mod; type=_type; bc=_bc; }
	int ka ;
	int nom ;
	int mod ; 
	int type ;
	int bc ;
} _ZKEYNU ;

//------------------------------------------------------------------------
typedef struct ZNU {
	ZKEYNU   Key ;    // ����� ��
	int      numlsf ; // ����� ���
	SK_TYPE  sk ;     // ����� ������� ���������
	long     vit ;    // �����
	double   t ;      // �����, ���
	double   M0 ;     // ����� ��
	double   MF ;     // ����� �������
	double   X[ 6 ] ; // X Y Z Vx Vy Vz ���  a e i W w u
					  // ����������� ���������, ��������� � ������� �������
					  // �������������� ����, ����/��� � �������
	double   Sb ;     // �������������� ����������� 
	double   Kp ;     // ����������� ��������� ��������
} _ZNU ;

//------------------------------------------------------------------------
typedef struct ZKA {
	int      num ; 
	double   M0 ;        // ����� �� ��� �������
	double   MF ;        // ��������� ����� ������� �� �����
	double   tstart ;    // ����� ������ ���
	int      bpl ;       // ������� ��������� 0 - �������, 1 - XOZ, 2 - YOZ
	double   min_step ;  // ����������� ��� ��������������, ���
	double   max_step ;  // ������������ ��� ��������������, ���
} _ZKA ;

//------------------------------------------------------------------------
class ZMForceGrav ; 

FLYCORE_API int LoadNU(ZKEYNU& Key, ZNU& NU);
FLYCORE_API int DocNU(ZNU& NU, char* FileName = nullptr, FILE* pf = nullptr);
FLYCORE_API int LoadKA(long numKA, ZKA& KA);
FLYCORE_API int LoadLSF(long numLSF, ZLSF& LSF);
FLYCORE_API int LoadGravPole(ZMForceGrav* GPZ, int vgpz, int ng, int mg);
FLYCORE_API int LoadDU(int nka, int ndu, ZCDU& DU);

FLYCORE_API int SaveNU(ZKEYNU& Key, ZNU& NU);
FLYCORE_API int SaveKA(long numKA, ZKA& KA);
FLYCORE_API int SaveLSF(long numLSF, ZLSF& LSF);

//------------------------------------------------------------------------
// ������� ��� ����������� ����������������� ���������� ��� �������� ����,
// ������� �������� �������� � ������������� �������� ���������� STL
// 
// !!!! STL �� �������� ���������������� !!!! 
// 
// ������� ��������������� ��� � ����� ����������� ���������� 
// ����������������� ���������� ������ ���� "������" � �������� ��� 
// ���������.
// 
// � ������ ���������� ������� ������������ ����� ������� ������ -
// - ��������� ������������ ���� �����������
// ��������� � ��������� ������ �������� ���:		
//		CreateSemaphore(...)
//		...
//		vector<...> XXX ;
//		XXX.push_back(...) ;
//		XXX.insert(...) ;
//		... XXX[...] ...
//		...
//		CloseHandle(...) 
// �� ������ �� �� �� ���� ��������� � STL ���������� ��������:
//		FAST_SEMAPFORE_OPEN
// ����� ���������� ���������, ������� ����� ���� ������������ ��������,
// ���������� �������� STL:
//		FAST_SEMAPFORE_CLOSE
//
// ������ � ����� ������ ��� ��������������� �������������� ��������� ��
// ����� �������� ���������� �������������� �������� 
//------------------------------------------------------------------------
#define FAST_SEMAPFORE_OPEN(Name)\
	{\
	HANDLE hsemaph = CreateSemaphore(nullptr, 1, 1, Name) ;\
	WaitForSingleObject(hsemaph, INFINITE) ;\
	{

#define FAST_SEMAPFORE_CLOSE()\
	}\
	ReleaseSemaphore(hsemaph, 1, nullptr) ;\
	CloseHandle(hsemaph) ;\
	}

//------------------------------------------------------------------------
#endif // #ifndef MODTYPE_H
//------------------------------------------------------------------------

