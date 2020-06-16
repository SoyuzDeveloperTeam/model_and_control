//-----------------------------------------------------------------------------
// ZEOPManager.h
// ��������� ���������� �������� ����� (Eath orientation parameters - EOP)
//
//-----------------------------------------------------------------------------
// ��������� ��� ������ ������� �������� ������ ������� ������ ������� 
// ���������� ������ ��������. ��� ������� ������ ZMSC ���������� � ������ 
// � ���� �� ������� ZEOPManager.
// ������ ������� ������ ��������, ��� �� ��� � ����� ���������� ��������� 
// �������� ���������� ���������� ZEOPManager EOPMng. 
//
// �. ��������� 06.03.2019
//-----------------------------------------------------------------------------
#ifndef _ZEOPMANAGER_H
#define _ZEOPMANAGER_H

// ��� ����� �������� ��������� ������ ��� - ����������� IERS
#define EOP_IERS_FILE_NAME		"IERS_EOP2000A.txt"
// ��� �����-��������� ��� � �������� ���� 
#define EOP_STORAGE_FILE_NAME	"FlyEOP.bin"
//
#define MOD_PX_STORAGE_FILE_NAME		"StoragModelPolusX.bin"
#define MOD_PY_STORAGE_FILE_NAME		"StoragModelPolusY.bin"
#define MOD_UT1UTC_STORAGE_FILE_NAME	"StoragModelUTC1mUTC.bin"

#include <FlyTime.h>	// �� ��� �����

//-----------------------------------------------------------------------------
// ��������� ����� ������ ������� ���
struct ZEOPItem {
	float MJD ;		// ���������������� ��������� ����
	float Xp ;		// ���������� ������ � ������� ������������
	float Yp ;		//
	float UT1mUTC ;	// UT1-UTC � ������������
	// ������ ��� ����� ��� float � �� double ������ � ��� ���, � �����������
	// ������������� ������� �������� ����� ������, ������ ��������� �����
	// ������������� ��� ����� double ����������� �������� ����
};

// ������ - ��������� ��� �������� ������������ ������� ���
// ����������� �� ��������� ��� (��������� � �������� ����)
typedef vector<ZEOPItem> VZEOPItem ;  

class FLYCORE_API ZEOPManager {
public:
	ZEOPManager() ;
	~ZEOPManager() ;

	//----------------------------------------------------------------------------
	// �������� ������������� ������ �� ��������� ���������
	// ��� �������������� ������� ���������� ������ �����������
	// IERS (��������� ������ X,Y � ������� ������������ 
	// � �������� UTC1-UTC � ������������)
	int  LoadFromIersFormat(bool isNeedSaveToBin=false) ;
	int  LoadFromBin();
	int  Load();
	// �������� ��������� �� ��������� ����������
	bool IsLoadStorage();
	// �������� ���� ������ �� ������������ ������� (�� ����������� ������)
	void Clear() ;
	// ��������� ��� �� �������� ���������������� ��������� ����
	ZEOPItem& getItemEOP(long Mjd);

	// ��������� � ��������� � ��������� ��������� �������������� �������
	// �� ������ ��� ����������� �� �������� ��������� � ���� ���������� �������
	// ��������� ������� �������� ��� ��������� ��������� ������� ��������.
	int MakeAllEopModels(double fromTa, double toTa);
	struct {
		// ��������� ������ � �������� ��������� �������������� ������� ��� 
		// �� ������ �� ������������ ������� ���. ���� �������� ������� �� 
		// ����������� �� ������ ����� �������� ������� ������.
		double fromTaNeed;	// �������� �������� ������� �� ������� ���������� 
		double toTaNeed;	// ������� ������ ��������� �������
		double fromTa;		// �������� �������� ������� �� ������� ���� 
		double toTa;		// ������� ��������� ������
		int	   Count;		// ����������� ��������� �������
		long   Duration;	// ������������ �������� �������� � ������������
		int    ExitCode;	// ��� ���������� - ������, ���� �� ��, �� ����� 0 
	} EopModelBuildReport;	

	//----------------------------------------------------------------------------
	// ��� �����-������ � ����������� �������� �����, ����������� ��
	// �������� ���������

	// ���� � ������� IERS - ������� ��� ����� ������ � ��������� ��� ����������
	const char* GetIersFileName(const char* notDefaultFileName=nullptr) {		
		IersFileName = DIRINFO;
		IersFileName+= "\\";
		IersFileName+= EOP_IERS_FILE_NAME;
		return IersFileName.c_str();
	}

	// �������� ������ ����� ��� ������� �������� - ������� ��� ����� 
	// ������ � ��������� ��� ����������
	const char* GetBinaryFileName() {	
		StorageFileName = DIRINFO;
		StorageFileName+= "\\";
		StorageFileName+= EOP_STORAGE_FILE_NAME;
		return StorageFileName.c_str();
	}

	//----------------------------------------------------------------------------
	// ���������� ��� ���� ������� ������������ �� �����������
	// ������������� ������, ���� �� ����������� ��������������� ������.
	int  Calc(double t, ZEOPItem& P, TIMESCALE Scale = DEFTIME_SCALE);

	// ���������� ���������� ��������������� ������ �� ����������� ������.
	int  BuildForecast(double toTime, TIMESCALE Scale=DEFTIME_SCALE) ;

	// ���� ��������� ������ �� ���������, �� ��� 
	// ��� ������� GetTimeXXX ���������� ������� ��������
	// ����� ������ ������� ��� - ����� ������ ������� ��������� ������
	double GetTimeFirst(TIMESCALE Scale=DEFTIME_SCALE ) ;

	// ����� ����� ������� ��� - ����� �� �������� ��������� ���������������
	// ������ ��� ����� ����� ������� ��������� ������, ���� ���������������
	// ������ �� ���������
	double GetTimeLast(TIMESCALE Scale=DEFTIME_SCALE ) ;

	// ����� ����� ������� ��������� ������
	double GetTimeTable(TIMESCALE Scale=DEFTIME_SCALE ) ;

protected:
	// ��������������� ���, ���������� ��������������� ������.
	int Forecast(double t, TIMESCALE Scale=DEFTIME_SCALE) ;

	char* SkipSpace(char* s) ;
	char* SkipToSpace(char* s) ;

	bool  IsForecastBuild ;
	float TimeTableFirst ; 
	float TimeTableLast ; 
	float TimeForecastTo ; 
	float MJDTableFirst ;
	float MJDTableLast ;

	// ����������� ������ � ����������� �������� �����.
	VZEOPItem EOP ;
	struct {
		// ��������� ������ � �������� ������������ ������� EOP 
		// �� �������� ��������� � ������� IERS ��� �� ��������� ���������.
		// ���� �������� �� ���� �� ������ ����� �������� ������� ������.
		char source;		// 0 - IERS, 1 - ���������
		long fromMjd;		// MJD ������ ������
		long toMjd;			// MJD ��������� ������
		long CountItems;	// ����������� ����������� �������
		long Duration;		// ������������ �������� � ������������
		int  ExitCode;		// ��� ���������� ��������� ��������, �� �������� 
	} EopLoadReport;		// ������ ������, ���� �� ��, �� ����� 0 

	// �������� ��������� ������� (�������������� ������� ���)
	ZCAlgebraicMdfHolder PxModelHolder;
	ZCAlgebraicMdfHolder PyModelHolder;
	ZCAlgebraicMdfHolder DTModelHolder;

	int    lastFindTableIndex ;
	float  lastFindMJDLeft ;
	float  lastFindMJDRight ;
	double LastFindIAT ;

	// ��� ����� �������� ��������� ������ ��� - ����������� IERS
	string IersFileName;
	// ��� �����-��������� ��� � �������� ���� 
	string StorageFileName;
} ;

//-----------------------------------------------------------------------------
// ���������� ��������� ���������� �������� �����.
// ��������� ������ ���������� ����� ���������� ���������, �����������
// � ������������ ���� ������ �������� FlyCore �������� ������ � ���������� 
// �������� �����. �� ����: 
//		- ��������� ������ ��������� �� ������, 
//		- ������� ��������� ��������������� ������ 
//		  � ����� ������� ������ �������,
//		- ��������� ���������� �������� ��� ��� ��������� ������� �������.
FLYCORE_API extern ZEOPManager EOPMng;

//-----------------------------------------------------------------------------
#endif _ZEOPMANAGER_H