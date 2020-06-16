//-----------------------------------------------------------------------------
// ZCEopManager.h
// ��������� ���������� �������� ����� (Eath orientation parameters - EOP)
//
//-----------------------------------------------------------------------------
// ��������� ��� ������ ������� �������� ������ ������� ������ ������� 
// ���������� ������ ��������. ��� ������� ������ ZMSC ���������� � ������ 
// � ���� �� ������� ZCEopManager.
// ������ ������� ������ ��������, ��� �� ��� � ����� ���������� ��������� 
// �������� ���������� ���������� ZCEopManager CEopMng. 
//
// �. ��������� 01.05.2019
//-----------------------------------------------------------------------------
#ifndef _ZCEOPMANAGER_H
#define _ZCEOPMANAGER_H

// ��� ����� �������� ��������� ������ ��� - ����������� IERS
#define EOP_IERS_FILE_NAME				"IERS_EOP2000A"
// ����������� ������ ��������� ��������� ���
#define EOP_STORAGE_FILE_COUNT			8
//
#define MOD_PX_STORAGE_FILE_NAME		"StoragModelPolusX.bin"
#define MOD_PY_STORAGE_FILE_NAME		"StoragModelPolusY.bin"
#define MOD_UT1UTC_STORAGE_FILE_NAME	"StoragModelUTC1mUTC.bin"

#include <FlyTime.h>	// �� ��� �����

//-----------------------------------------------------------------------------
// ��������� ����� ������ ��������� ������� ������� �������
struct ZSEopModHeaderItem {
	float MJD;		// ���������������� ��������� ����
	int   ShiftMod;	// �������� ������ ������ ������� ������ �� ������ ����� 
	char  State;	// ��������� ������� ������
					//		0 - ������ �����������
					//		1 - ������ ������� �� ������������� ������ 
					//		2 - ������ ������� �� ������������� ������
					//		3 - ������ ����������� ��������
};

// ������ - ��������� ��� �������� ������������ ������� ���
// ����������� �� ��������� ��� (��������� � �������� ����)
typedef vector<ZSEopModHeaderItem> VZSEopModHeader;

//-----------------------------------------------------------------------------
// ��������� �������������� ������
struct ZSAlgLocalMod {
	float MJD;		// ���������������� ��������� ���� ������ ������
	float Days;		// �������� �������������
	float A[13];	// ������������ ������ 
};

struct ZSEopItem;

class FLYCORE_API ZCEopManager {
public:
	ZCEopManager();
	~ZCEopManager();

	void Clear();

	//----------------------------------------------------------------------------
	// �������� ������������� ������ �� ��������� ���������
	// ��� �������������� ������� ���������� ������ �����������
	// IERS (��������� ������ X,Y � ������� ������������ 
	// � �������� UTC1-UTC � ������������)
	int ZCEopManager::LoadFromIersFormat(
		// ��������� ������ IERS �� ����� �����
		char* SpecifiedIersFile,
		// ������������� ������ �������� ����������� ��������
		bool isNeedVaracitiPredictEst,
		// ��������� ����������� ������ � ���� ������������ ���������� �������
		bool isNeedSaveAsShortTxt,
		// ������������� ���������� �� ���������� ������ ������� ���. �������
		bool isNeedBuilModels);

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

	//----------------------------------------------------------------------------
	int  LoadFromBin();
	
	int  PutHeaderItemToStorage(ZSEopModHeaderItem& I);
	int  PutModToStorage(ZSEopModHeaderItem& I, ZSAlgLocalMod& M);

	//----------------------------------------------------------------------------
	// �������������� ����������� ���� � ������������������ ������� UTC
	// � ���������������� ��������� ����.
	static int UtcToMjd(DATETIMEUTC& UTC, float& Mjd);
	static int MjdToUtc(float& Mjd, DATETIMEUTC& UTC);

	//static int ZSEopItemSize;

protected:
	int   DecodeIersString(char* S, ZSEopItem* I);
	char* SkipSpace  (char* s);
	char* SkipToSpace(char* s);

	//----------------------------------------------------------------------------
	// ��� �����-������ � ����������� �������� �����, ����������� ��
	// �������� ���������

	// ���� � ������� IERS - ������� ��� ����� ������ � ��������� ��� ����������
	const char* GetIersFileName(const char* notDefaultFileName = nullptr) {
		if (notDefaultFileName && notDefaultFileName[1] == ':') {
			IersFileName = notDefaultFileName;
		}
		else {
			IersFileName = DIRIERSEOP;
			IersFileName += "\\";
			if (notDefaultFileName) IersFileName += notDefaultFileName;
			else {
				IersFileName += EOP_IERS_FILE_NAME;
				IersFileName += ".txt";
		}	}
		return IersFileName.c_str();
	}

	int GetNumBinFile(double Mjd, int j0=0) {
		int j;
		if (Mjd >= MjdF[j0]) {
			for (j = j0; j < EOP_STORAGE_FILE_COUNT - 1; ++j){
				if (Mjd >= MjdF[j] && Mjd < MjdF[j + 1]) break;
			}
		} else {
			if (!j0) return-1;
			for (j = j0; j > 0; --j){
				if (Mjd >= MjdF[j-1] && Mjd < MjdF[j]) break;
			}
			--j;
		}
		return j;
	}

	// ��� ����� �������� ��������� ������ ��� - ����������� IERS
	// ������ � ��� ����������� IERS ����� ��������� �� ������
	// ftp://ftp.iers.org/products/eop/rapid/standard/finals2000A.all
	// ftp://ftp.iers.org/products/eop/rapid/standard/finals2000A.data
	// ftp://ftp.iers.org/products/eop/rapid/standard/finals.data
	// ftp://ftp.iers.org/products/eop/rapid/standard/finals.all
	// ftp://ftp.iers.org/products/eop/rapid/standard/gpsrapid.out
	// ftp://ftp.iers.org/products/eop/rapid/daily/finals2000A.daily
	// ftp://ftp.iers.org/products/eop/rapid/daily/finals.daily

	string IersFileName;

	// MJD ������ �������� ������ � ���
	// ���� ���� � ��� �������� ������ � ��� �� 10 ���
	float MjdF[EOP_STORAGE_FILE_COUNT];
	// MJD ������ ������ �������� ��������������� ��� IERS
	float MjdEstEopPredict;
};

//-----------------------------------------------------------------------------
// ���������� ��������� ���������� �������� �����.
// ��������� ������ ���������� ����� ���������� ���������, �����������
// � ������������ ���� ������ �������� FlyCore �������� ������ � ���������� 
// �������� �����. �� ����: 
//		- ��������� ������ ��������� �� ������, 
//		- ������� ��������� ��������������� ������ 
//		  � ����� ������� ������ �������,
//		- ��������� ���������� �������� ��� ��� ��������� ������� �������.
FLYCORE_API extern ZCEopManager CEopMng;

//-----------------------------------------------------------------------------
#endif _ZEOPMANAGER_H