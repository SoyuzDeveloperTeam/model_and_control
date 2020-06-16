//-----------------------------------------------------------------------------
// ZCPrintManager.h
// �. ��������� 03.08.2018
// ���������������� ����������� ��������
//----------------------------------------------------------------------------- 
#ifndef PrintMSC_H
#define PrintMSC_H

#include <FlyHtmlWriter.h>	// ��� ���������������� � ������� Html

#include <FlyCoreSource\\ZMSpaceCraft.h>
#include <FlyCoreSource\\ZCPrintFormat.h>

//----------------------------------------------------------------------------- 
#define MODPR_KA			999
#define MODPR_M				1008
#define MODPRDATE			1
#define MODPRTIME			2
#define MODPRDATETIME		1001
#define MODPR_VIT			3			
#define MODPR_MSSV			4
#define MODPR_Tosk			5			
#define MODPR_H				6
#define MODPR_B				7
#define MODPR_L				8									
#define MODPR_R				9									
#define MODPR_Aosk			10
#define MODPR_eosk			11
#define MODPR_exosk			12
#define MODPR_eyosk			13
						
#define MODPR_V_Tdr			14	
#define MODPR_V_Hsr			15
	
#define MODPR_V_Hmin		16	
#define MODPR_V_HminU		17	
#define MODPR_V_Hmint		18	
#define MODPR_V_HminB		19	
#define MODPR_V_HminL		20
	
#define MODPR_V_Hmax		21	
#define MODPR_V_HmaxU		22	
#define MODPR_V_Hmaxt		23	
#define MODPR_V_HmaxB		24	
#define MODPR_V_HmaxL		25

#define MODPR_V_Rmin		26	
#define MODPR_V_RminU		27	
#define MODPR_V_Rmint		28	
#define MODPR_V_RminB		29	
#define MODPR_V_RminL		30
	
#define MODPR_V_Rmax		31	
#define MODPR_V_RmaxU		32	
#define MODPR_V_Rmaxt		33	
#define MODPR_V_RmaxB		34	
#define MODPR_V_RmaxL		35

#define MODPR_V_VUR			36	
#define MODPR_V_VUH			37	
#define MODPR_V_VUdate		1002	
#define MODPR_V_VUtime		38	
#define MODPR_V_VUdatetime	1003	
#define MODPR_V_VUL			39
#define MODPR_V_VUmssv		1004		

#define MODPR_V_NUR			40	
#define MODPR_V_NUH			41	
#define MODPR_V_NUdate		1005	
#define MODPR_V_NUtime		42	
#define MODPR_V_NUdatetime	1006	
#define MODPR_V_NUL			43	
#define MODPR_V_NUmssv		1007		

#define MODPR_V_DL			44		
#define MODPR_V_DLS			45		
#define MODPR_V_KR			46		

#define MODPR_T_RV75		601	
#define MODPR_T_R75			47	
#define MODPR_T_V75			48	
#define MODPR_T_X75			501
#define MODPR_T_Y75			502
#define MODPR_T_Z75			503
#define MODPR_T_VX75		504
#define MODPR_T_VY75		505
#define MODPR_T_VZ75		506
#define MODPR_T_OSC75		611		
#define MODPR_T_i75			49		
#define MODPR_T_W75			50		
#define MODPR_T_w75			51		
#define MODPR_T_u75			52		

#define MODPR_T_RV00		602	
#define MODPR_T_R00			53		
#define MODPR_T_V00			54		
#define MODPR_T_X00			507
#define MODPR_T_Y00			508
#define MODPR_T_Z00			509
#define MODPR_T_VX00		510
#define MODPR_T_VY00		511
#define MODPR_T_VZ00		512
#define MODPR_T_OSC00		612		
#define MODPR_T_i00			55		
#define MODPR_T_W00			56		
#define MODPR_T_w00			57		
#define MODPR_T_u00			58		

#define MODPR_T_RVTE		603	
#define MODPR_T_RTE			59		
#define MODPR_T_VTE			60		
#define MODPR_T_XTE			513
#define MODPR_T_YTE			514
#define MODPR_T_ZTE			515
#define MODPR_T_VXTE		516
#define MODPR_T_VYTE		517
#define MODPR_T_VZTE		518
#define MODPR_T_OSCTE		613		
#define MODPR_T_iTE			61	
#define MODPR_T_WTE			62		
#define MODPR_T_wTE			63		
#define MODPR_T_uTE			64

#define MODPR_T_RVTES		604	
#define MODPR_T_RTES		65		
#define MODPR_T_VTES		66	
#define MODPR_T_XTES		519
#define MODPR_T_YTES		520
#define MODPR_T_ZTES		521
#define MODPR_T_VXTES		522
#define MODPR_T_VYTES		523
#define MODPR_T_VZTES		524
#define MODPR_T_OSCTES		614		
#define MODPR_T_iTES		67	
#define MODPR_T_WTES		68		
#define MODPR_T_wTES		69		
#define MODPR_T_uTES		70
		
#define MODPR_T_RVGSC		605	
#define MODPR_T_RGSC		71		
#define MODPR_T_VGSC		72		
#define MODPR_T_XGSC		525
#define MODPR_T_YGSC		526
#define MODPR_T_ZGSC		527
#define MODPR_T_VXGSC		528
#define MODPR_T_VYGSC		529
#define MODPR_T_VZGSC		530

//----------------------------------------------------------------------------- 
enum TypeUPP {UPPint=0, UPPdouble=1, UPPexp=2, UPPTime=3} ;

struct ZSUserPrintParam {
	double  value;
	TypeUPP	type;
	string	name;
	string	namedim;
	string	namehtml;
	string	namedimhtml;
	int		len;
	int		dec;

	ZSUserPrintParam() {
		value= 0.0 ;
		type = UPPint ;
		len  = 0 ;
		dec  = 0 ;
		name = "";
		namedim = "";
		namehtml = "";
		namedimhtml = "";
	}
	ZSUserPrintParam(TypeUPP _type, 
		int _len=6, int _dec=0, 
		char* _name=nullptr, char* _namedim=nullptr,
		char* _namehtml = nullptr, char* _namedimhtml = nullptr) {
		value= 0.0 ;
		type = _type ;
		len  = _len ;
		dec  = _dec ;
		if (_name)		name = _name; 
		else			name = "";
		if (_namedim)	namedim = _namedim; 
		else			namedim = "";
		if (_name)		namehtml = _namehtml;
		else			namehtml = "";
		if (_namedim)	namedimhtml = _namedimhtml;
		else			namedimhtml = "";
	}
};

class FLYCORE_API ZCMPrintKey {
public :
	ZCMPrintKey () { fromVit = true ; isAflat = false ; }
	~ZCMPrintKey() { Clear() ; }

	void FromVitOn () { fromVit = true ; } ;
	void FromVitOff() { fromVit = false ; } ;
	void AflatOn() { isAflat = true ; } 
	void ApeakOn() { isAflat = false ; } 
	bool IsAflat() { return isAflat ; } 

	void Clear  () { P.clear() ; UP.clear() ; }
	void ClearP () { P.clear() ; }
	void ClearUP() { UP.clear() ; }
	int  Size () { return P.size() ; }
	int  SizeU() { return UP.size() ; }
	int  SizeF() { return(UP.size()+P.size()) ; }
	void operator << (int KeyParam) { P.push_back(KeyParam) ; }
	void operator << (ZSUserPrintParam& UserParam) { UP.push_back(UserParam) ; }
	int operator [] (int i)  { return P[i] ; }
	int operator [] (short i){ return P[i] ; }
	int operator [] (long i) { return P[i] ; }
	int operator [] (char i) { return P[i] ; }
	ZSUserPrintParam& UPP(int i) { return UP[i] ; }

	bool fromVit ;
	bool isAflat ;

protected :
	vector<int>	P ;
	vector<ZSUserPrintParam> UP ;
} ;

//----------------------------------------------------------------------------- 
#define MAX_APEAK_COLUMN	8 
#define SIZE_PSB			4 

//----------------------------------------------------------------------------- 
// ��������� ����������������
// ���������� ����� ��� �������� ���������� � ������������ ������� ����������
// �����. ����������� ����������� �������� ��� ��������� ���������� ��� � 
// ���������� � ������� Html.
// �������� Html ����� ��������� ����� ����� ������� �������� CSS � JavaScript
// ��� ����������� Html-���������������� ����������� ����������� FlyHtmlWriter
// ����������� ������ ZCHtmlBuilder . . .
//-----------------------------------------------------------------------------
class FLYCORE_API ZCPrintManager {
public:
	//-------------------------------------------------------------------------
	// �������� ���������� ��������, ���������� ����������������
	ZCMPrintKey   MPK;
	//-------------------------------------------------------------------------
	// ������� ���������������� ������
	ZCPrintFormat MPF;
	// ������-������ - ����� ������ ��� ���� ����������� ����������.
	// ������ ������ ����� ��������� � ����� ����� ������������ ����� �����
	// ����������� �����
	static char CommonFileSticker[64];

protected:
	// "��������" ��� �������� ��������� � Html �������.
	ZCHtmlBuilder* HtmlCreator = nullptr;
	// ��������� �������� � ������� ��������� ���������� ������� ����������
	// �����. ���������� ���������������� � ������ PrePrint ��� ������������� 
	// ����������������. �����, ���� ��� ������ ������ �� ������� 
	// Print____(..., fp), ��������� fp ����� nullptr ��� ������ ����������,
	// ����� ��������� ���������� �������������� ������ � ���� �� ������� 
	// ��������� localFp.
	FILE*     localFp = nullptr;
	// ����� ������ � ����� ����� �������� ���������. ������������
	// � ��������� ��� �������� ������� ���������� ��������������� ��������
	time_t    startTIME = 0, endTIME = 0;
	struct tm start_TM;
	// "��������" � ����� ������������ ���������, ����������� �������������
	// � ����� ������������ ����� (��� ���������� ��� � html)
	// �������� ������������ ���������� ���������� 
	// ����������� ������ SetPrintFileSticker
	// � ����� ������������ ����� ���������� ������ FileSticker ����� 
	// �������������� ���������� ������ CommonFileSticker - ������� ������
	// ��� ���� ����������� ������.
	//
	// ������ ����� ����������� ������:
	//		UserDefineName_CommonFileSticker_FileSticker.txt 
	//		UserDefineName_CommonFileSticker_FileSticker.html
	char FileSticker[128];

	// ����� ��� ������������ ���������� �������� ����������� �� �����
	ZSC_SI PSB[MAX_APEAK_COLUMN];
	// ����� ��� ������������ ������������ ���������� �������� 
	// ����������� �� ������
	ZSC_VI PVB[MAX_APEAK_COLUMN];

	int countPSB = 0;

	string fullTextFileName;
	string fullHtmlFileName;

public :
	ZCPrintManager();
	~ZCPrintManager();

	// ������ ��� ��������� ������ - ���������� � � ������� Html
	const char* GetTextFileName();
	const char* GetHtmlFileName();
	// �������� ����������� ���������� ������������ �������
	void ShowTextFile();
	void ShowHtmlFile();

	// ����� ������� ����� ������ �������� ��������������� 
	// ���������� ��������
	void operator << (int KeyParam) { MPK << KeyParam; }
	void operator << (ZSUserPrintParam& UserParam) { MPK << UserParam; }

	//-------------------------------------------------------------------------
	// ����������� "�������" �����-���������. 
	// ������ ���� FileSticker ���������� ������.
	void SetPrintFileSticker(char* FS = nullptr);

	// ������������� �������� ����������������� � ��������� ����� ���������,
	// � �������� ��������, ��� ��������� �� 
	int PrePrint (ZMSC* pKA, char* 
				  DirMame=nullptr, 
				  char* FileName=nullptr, 
				  FILE** pfp=nullptr, 
				  char* FullName=nullptr) ;

	//-------------------------------------------------------------------------
	// ���������� ����������������, ��� ������������� � ���� 
	// ������������ ����� �������� (cointiter) 
	int PostPrint(FILE** pfp = nullptr, int cointiter = -1);
	// �������� ����� ��������� � ������������� ������� ��������� 
	// ��������������� ��� ����� ��������.
	int ClosePrint(FILE** pfp = nullptr);

	// ���������������� ���������� ��������, ��� ��������� �� (pKA),
	// ��������������� ��������� �������� �� �����-���� ����� (FS), �/���
	// ������������ ��������� �������� ��� ������-���� ����� (FV).
	// ���� ��������� - fp. ���� fp=nullptr, �� ���������������� 
	// ����������� � ���� this->localFp
	int PrintMSC (ZMSC* pKA, ZSC_SI* FS=nullptr, 
				  ZSC_VI* FV=nullptr, FILE* fp=nullptr) ; 
	// ������ ��������� � ����-��������
	int PrintHeaderDoc(char* hd, FILE* fp=nullptr);
	// ���������������� �������� ������
	int PrintText(const char* text, char countCR = 0, FILE* fp = nullptr);
	// ���������������� ��
	int PrintNU(ZNU&  NU, char* Title, int VarPrint=3, FILE* fp=nullptr);
	// ���������������� ���������� ����� ���
	int PrintLSF(ZLSF& LS, int VarPrint=1, FILE* fp=nullptr);

	//-------------------------------------------------------------------------
	// "��������������", �� ���� � ������, ���������������� ���������� ��������
	//		pKA - ������ �������� (��) ��� ������� ����������� ����������������,
	//		FS  - ��������� �������� �� ������� ������ �������,
	//		FV  - ��������� �������� �� ������� �����
	//		fp  - ��������� ���� � ������� �������� ����������.
	int PrintAflatMSC(ZMSC* pKA, 
					  ZSC_SI* FS=nullptr, ZSC_VI* FV=nullptr,
					  FILE* fp=nullptr);
	// "������������", �� ���� � �������, ���������������� ���������� ��������
	int PrintApeakMSC(ZMSC* pKA, 
					  ZSC_SI* FS=nullptr, ZSC_VI* FV=nullptr,
					  FILE* fp=nullptr);

	//-------------------------------------------------------------------------
	// ������������ � ��������� �������������� �����, ���������� 
	// ��������� ������ ���������� ��������.
	int  PrintLineMSC(FILE* fp=nullptr); 
	// ������������ � ��������� �������������� �����, ���������� 
	// ��������� ������ ���������� ��������, �������������� �������������.
	void PrintAflatLineMSC(FILE* fp=nullptr); 
	// ������������ � ��������� �������������� �����, ���������� 
	// ��������� ������ ���������� ��������, ��������������� �����������
	void PrintApeakLineMSC(FILE* fp=nullptr); 
	// ���������������� �������������� �����.
	void PrintLine(FILE* fp=nullptr);

	//-------------------------------------------------------------------------
	// ���������������� ������������ ���������� (�������������) �����
	void PrintVitPoint(FILE* fp, ZSC_VP& VP) ;

	//-------------------------------------------------------------------------
	// ������ � ��������� ������.
	// ��������� ���������� �������� �������� ���������� ���������� � ������
	// �����, ����� ��������� ���������� ����������������.
	//-------------------------------------------------------------------------
	// ������ � ��������� �� ��������� ��������� ���� ���������
	FILE* TextFile() { return localFp; }
	// ������ � ��������� �� "��������" Html-�����
	ZCHtmlBuilder* HtmlFile() { return HtmlCreator; }

protected:
	//-------------------------------------------------------------------------
	// �������� ����� ����� ���������, � �������� ��������, ��� ��������� ��
	void GetPrintLongName(ZMSC* pKA,
		char* DirMame  = nullptr,
		char* FileName = nullptr,
		char* LNF  = nullptr,
		char* LNF2 = nullptr,
		char* LNF3 = nullptr,
		char* LND  = nullptr);
	// �������� � �������� ����� ���������, � �������� ��������, 
	// ��� ��������� �� 
	int OpenPrintLongName(ZMSC* pKA,
		char* DirMame  = nullptr,
		char* FileName = nullptr,
		FILE** pfp     = nullptr,
		char* FullName = nullptr);


	void PrintAflatLineMSChtml();
	void PrintAflatLineMSCtext(FILE* fp = nullptr);
	int PrintApeakMSChtml(ZMSC* pKA, ZSC_SI* FS, ZSC_VI* FV);
	int PrintApeakMSCtext(ZMSC* pKA, ZSC_SI* FS, ZSC_VI* FV, FILE* fp=nullptr);
	int PrintAflatMSChtml(ZMSC* pKA, ZSC_SI* FS, ZSC_VI* FV);
	int PrintAflatMSCtext(ZMSC* pKA, ZSC_SI* FS, ZSC_VI* FV, FILE* fp = nullptr);

	void TablApeakHtmlGroupHeader(Z�HtmlItem& I, const int j,
								 const char* caption, const int countPSB);
	void TablApeakHtmlGroupHBLRH(Z�HtmlItem& I, const int  j,
								 const bool forH, const bool forMax, 
								 const int  countPSB);
	void TablApeakHtmlGroupCoord(Z�HtmlItem& I, const int  j, const int  k,
								 const int  countPSB);
} ;

//-----------------------------------------------------------------------------
#define PZCPrintManager ZTSelfRemovPointer<ZCPrintManager>

FLYCORE_API void SmartPrintfI(FILE*pf, char* sf, int I, bool isTwoDest=false);
FLYCORE_API void SmartPrintfL(FILE*pf, char* sf, long L, bool isTwoDest = false);
FLYCORE_API void SmartPrintfD(FILE*pf, char* sf, double D, bool isTwoDest = false);
FLYCORE_API void SmartPrintfS(FILE*pf, char* sf, char* S, bool isTwoDest = false);
FLYCORE_API void SmartPrintfS(FILE*pf, char* S, bool isTwoDest = false);

//------------------------------------------------------------------------------- 
#endif // #ifndef PrintMSC_H
