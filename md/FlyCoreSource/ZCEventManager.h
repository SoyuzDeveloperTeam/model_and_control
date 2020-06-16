//-------------------------------------------------------------------------------
// ZCEventManager.h
// �. ��������� 03.08.2018
//------------------------------------------------------------------------------- 
#ifndef ModEventManager_H
#define ModEventManager_H

#include <FlyCoreSource\\ZNIP.h>

// ������������ ����������� ������� ������ ��������
#define COUNT_ModEvents		100
// ������ ���������������� �������
#define ID_USEREVENT_FIRST	100

// ������ ������ ��
class  ZMSC ;
// ��������� ���������� �������� - ����������� ������������� �������� 
// ����������� ������ ZModKA
struct ZSC_SI ;

//------------------------------------------------------------------------------- 
// ��������� �������, ����������� ������� ������������ ������ ��������
//------------------------------------------------------------------------------- 
enum ModEventName{
	ModEvent_EMPTY = 0,				// ������� ���������� ������� ---> ���������� ������� ����������	 
	ModEvent_INIT = 1,				// ������������� ��
	ModEvent_STEP = 2,				// �������� ���� ��� ��������������	 
	ModEvent_BKSTEP = 3,			// ����������� � �������� ����� ��� ��������� ���� ����

	ModEvent_DUON = 4,				// 	 
	ModEvent_DUSTEPON = 5,			// 	 
	ModEvent_DUOFF = 6,				// 	 

	ModEvent_VITVU = 7,				// ���������� ���� �����	 
	ModEvent_VITNU = 8,				// ���������� ���� �����
	ModEvent_HMIN = 9,				// ����������� ������
	ModEvent_HMAX = 10,				// ������������ ������
	ModEvent_RMIN = 11,				// ����������� ������
	ModEvent_RMAX = 12,				// ������������ ������
	ModEvent_SHADOWBEG = 13,		// ������ ����
	ModEvent_SHADOWEND = 14,		// ����� ����

	ModEvent_ONBREAKTIME = 15,		// ��������� ���������� ������ ������� �������� ���������� notFurtherTime � ������� GoStepA
	ModEvent_ONTIME = 16,			// ��������� ��������������� �� �����
	ModEvent_ONVIT = 17,			// ��������� ��������������� �� ��������� ������� �������
	ModEvent_ONARG = 18,			// ��������� ��������������� �� ��������� ��������� ������

	ModEvent_ZRVBEG = 100,			// ������ ���
	ModEvent_ZRVEND = 101,			// ����� ���
	ModEvent_ZRVPARAM = 102			// ������ ����������� ��������� ���
};

#define ModEvent_BEG ModEvent_VITVU
#define ModEvent_END ModEvent_RMAX

//------------------------------------------------------------------------------- 
// �������� ���� ������� 
//------------------------------------------------------------------------------- 
// �������� �� ������� �������� ���� �������������� (������� ����������� ����� ���)
FLYCORE_API bool IsZRVEvent(ModEventName e);
// �������� �� ������� �������� ����� (������� ����������� ����� �����)
FLYCORE_API bool IsVITEvent(ModEventName e);
// �������� �� ������� �������� ������������
FLYCORE_API bool IsGOEvent(ModEventName e);
// �������� �� ������� �������� ������������� ������ ������������ ���������
FLYCORE_API bool IsDUEvent(ModEventName e);
//
FLYCORE_API bool IsUserEvent(ModEventName e);
//
FLYCORE_API bool IsModEvent(ModEventName e);

// ������������� ������� ��� (������, ����� ��� ��������)
FLYCORE_API int IDZRVEvent(ModEventName e);
// ������ ���� �� ������� ���
FLYCORE_API int IndNipZRVEvent(ModEventName e);

//------------------------------------------------------------------------------- 
// �������������� ������� 
typedef struct ZMOD_EVENT {
ModEventName	ID ;		// ��� �������
double			ta ;		// ����� �������, ������� � ���   
double			Value ;		// �������� �������������� �������, ��� ����������� 
double			Value2 ;	// ������� �� ����� ������ ==> ����� ������� ��������
double			Value3 ;	//
double			Value4 ;	//
long			Value5 ;	//
} _ZMOD_EVENT ;				// 

//------------------------------------------------------------------------------- 
// ��������� ��� �������� ��������� ��������� ����������� �������
class FLYCORE_API ZCEventCase {
public:
	ZCEventCase() {
		Ipz = nullptr ;
		Ppz = nullptr ; Cpz = nullptr ;
		Ptz = nullptr ; Ctz = nullptr ;
		NI  = nullptr ;
		ZRV = nullptr ;
		CntNip = 0 ; 
		isNeedTestZRV = false;
		isNeedTestVit = false ;
	} ;

	~ZCEventCase() {
		CompletZRV() ;
	} ;

	void PreTest() {
		timep = timet ;

		memcpy(Pp, Pt, sizeof(Pt)) ;
		memcpy(Cp, Ct, sizeof(Ct)) ;
		memset(Ip, 0,  sizeof(Ip)) ;
		memset(ie, 0,  sizeof(ie)) ;

		if (CntNip>0) {
			memcpy(Ppz, Ptz, 3*CntNip*sizeof(double)) ;
			memcpy(Cpz, Ctz, 3*CntNip*sizeof(double)) ;
			memset(Ipz, 0,   3*CntNip*sizeof(bool)) ;
		}
	}

	// ����������� ������������� ������������ ������� ���
	// ���� ���������� ������ �������� ���, �� ������
	// ����������� ��� �����
	bool IsNeedTrackingZRV() { return CntNip>0 ? true:false ; }
	int  CountNips() { return CntNip ; } 
	int  INips(int i) { return NI[i] ; }

	// ������ �������� ������� �����
	// ����������� �������� ������� ����� ������������� ��� 
	// ������ �� ������ ������ ���������� �����
	void RunUpVit() {
		FinalityVit() ;
		// ������������� ������� ��������������� ������������ ������� 
		// ����� � ��� ������������� (�� ���� ��� ����������� 
		// � �������� ����) ��������� ������ �������
		isNeedTestVit = true ;
	} ;
	// ��������� ���� ���������� ���������� �������, ����������
	// �� ������������ ������� �����.
	void FinalityVit() {
		memset(Ip, 0, sizeof(Ip)) ;
		memset(Pp, 0, sizeof(Pp)) ;
		memset(Cp, 0, sizeof(Cp)) ;
		timep = 0 ;
		memset(Pt, 0, sizeof(Pt)) ;
		memset(Ct, 0, sizeof(Ct)) ;
		timet = 0 ;
		memset(ie, 0, sizeof(ie)) ;
		// ������������ ������� ��������������� ������������ ������� 
		// ����� � ��� ������������� (�� ���� ��� ����������� 
		// � �������� ����) ��������� ������ �������
		isNeedTestVit = false ;
	} ;
	// ������ �������� ������� ���
	//	CountNip	- ����������� �������������� �����
	//	NipIndexes	- ������� ����� � ������� ������������� � 
	//				  ��������� ����� 
	int RunUpZRV(int CountNip, int* NipIndexes) {
		CntNip = CountNip ;
		Ipz = new bool  [3*CntNip] ; if (!Ipz) return-1 ; 
		Ppz = new double[3*CntNip] ; if (!Ppz) return-1 ; 
		Cpz = new double[3*CntNip] ; if (!Cpz) return-1 ; 
		Ptz = new double[3*CntNip] ; if (!Ptz) return-1 ; 
		Ctz = new double[3*CntNip] ; if (!Ctz) return-1 ; 
		NI  = new int   [CntNip] ;   if (!NI ) return-1 ; 
		ZRV = new ZZRV  [CntNip] ;   if (!ZRV ) return-1 ;  
		memset(Ipz, 0, 3*CntNip*sizeof(bool)) ;
		memset(Ppz, 0, 3*CntNip*sizeof(double)) ;
		memset(Cpz, 0, 3*CntNip*sizeof(double)) ;
		memset(Ptz, 0, 3*CntNip*sizeof(double)) ;
		memset(Ctz, 0, 3*CntNip*sizeof(double)) ;
		memcpy(NI, NipIndexes, CntNip*sizeof(int)) ;
		memset(ZRV, 0, CntNip*sizeof(ZZRV)) ;
		isNeedTestZRV = true ;
		return 0 ;
	} ;
	// ��������� ���� ���������� ���������� �������, ����������
	// �� ������������ ������� ���.
	void FinalityZRV() {
		CntNip = 0 ;
		delete[] Ipz ; Ipz = nullptr ;
		delete[] Ppz ; Ppz = nullptr ;
		delete[] Cpz ; Cpz = nullptr ;
		delete[] Ptz ; Ptz = nullptr ;
		delete[] Ctz ; Ctz = nullptr ;
		delete[] NI  ; NI  = nullptr ;
		delete[] ZRV ; ZRV = nullptr ;
		// ������������ ������� ��������������� ������������ ������� 
		// ��� � ��� ������������� (�� ���� ��� ����������� 
		// � �������� ����) ��������� ������ �������
		isNeedTestZRV = false ;
	} ;
	// ����������� �������� ������� ���
	void CompletZRV() {
		if (Ipz) { delete[] Ipz ; Ipz = nullptr ; }
		if (Ppz) { delete[] Ppz ; Ppz = nullptr ; }
		if (Cpz) { delete[] Cpz ; Cpz = nullptr ; }
		if (Ptz) { delete[] Ptz ; Ptz = nullptr ; }
		if (Ctz) { delete[] Ctz ; Ctz = nullptr ; }
		if (NI ) { delete[] NI ;  NI  = nullptr ; }
		if (ZRV) { delete[] ZRV;  ZRV = nullptr ; }
		CntNip = 0 ;
	} ;

	bool&   IP(int i) { return (i<COUNT_ModEvents ? Ip[i]:Ipz[i-COUNT_ModEvents]) ; }
	double& PP(int i) { return (i<COUNT_ModEvents ? Pp[i]:Ppz[i-COUNT_ModEvents]) ; }
	double& CP(int i) { return (i<COUNT_ModEvents ? Cp[i]:Cpz[i-COUNT_ModEvents]) ; }
	double& PT(int i) { return (i<COUNT_ModEvents ? Pt[i]:Ptz[i-COUNT_ModEvents]) ; }
	double& CT(int i) { return (i<COUNT_ModEvents ? Ct[i]:Ctz[i-COUNT_ModEvents]) ; }

//private:
protected:
	// ������� ������������� ������������� ����������� ������� ���
	bool isNeedTestZRV ;
	// ������� ������������� ������������� ����������� ������� �����
	bool isNeedTestVit ;

	// ������ ������� ������ ��������
	// ������� ������������ ���������
	bool   Ip[COUNT_ModEvents] ;
	// �������������� ��������, �������������� �������� �� ���������� ����
	double Pp[COUNT_ModEvents] ;
	double Cp[COUNT_ModEvents] ;
	// �������������� ��������, �������������� �� ������� ����
	double Pt[COUNT_ModEvents] ;
	double Ct[COUNT_ModEvents] ;

	// ������ ������� ���
	// ������� ����� � ������� ��������, ����������� 
	// ���������� � �������������� �����.
	int*    NI ;
	// ����������� �����
	int     CntNip ;
	// ������� ������������ ���������
	bool*   Ipz ;
	// �������������� ��������, �������������� �������� �� ���������� ����
	double* Ppz ;
	double* Cpz ;
	// �������������� ��������, �������������� �� ������� ����
	double* Ptz ;
	double* Ctz ;

protected:
	// ����� �� ���������� ����
	double timep ;
	// ����� �� ������� ����
	double timet ;

	// ��������� ������� �� ������� ���� - �����, ������ � �������� �������� 
	// ������� ���������� �������.
	// � ��� ������� ������������ ������� ��� ������ �������� ��� � ������� ���
	ModEventName ie[COUNT_ModEvents] ;	// ������ ������� 
//	double		 te[COUNT_ModEvents] ;	// ����� �������
	// ����� ����� ��������� �������
	//int	CountFound ; 	

public:
	ZZRV* ZRV ;
} ;

//------------------------------------------------------------------------------- 
class FLYCORE_API ZCEventManager : public ZCEventCase {
public:
	ZCEventManager();
	~ZCEventManager();

	// �������� ����� ����������� ������� �� ������� ����
	int TestEvents(ZMSC* KA, ZSC_SI* SI=nullptr) ;
	// ���������� �������� �������������� ����������
	int CalcParams(ZMSC* KA, ZSC_SI* SI=nullptr, int indPar=-1, double* P=nullptr, double* D=nullptr) ;

protected:
	// ��������� �������
	int  ClarifyEvent(ZMSC* KA, ModEventName indEvent, ZSC_SI* SI, double* ddh=nullptr) ;
	void PutVITParam (int indI, double Pc, double Dc, int indC, double* P, double* D) ;
	// ��������, ��������� � ������������� ������� ���
	int  TestZRV     (ZMSC* KA, ZSC_SI& SI, int& i, int& j) ;
	void PostFindZRV (ZMSC* KA, ZSC_SI& SI, ZZRV* Z) ;
} ;

#endif // ModEventManager_H