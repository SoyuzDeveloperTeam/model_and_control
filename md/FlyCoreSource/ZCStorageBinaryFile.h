//-----------------------------------------------------------------------------
// ZCStorageBinaryFile.h
// �������� ����-��������� ���
//
// �. ��������� 04.05.2019
//-----------------------------------------------------------------------------
#ifndef _ZCEOP_BINARY_FILE_H
#define _ZCEOP_BINARY_FILE_H

//-----------------------------------------------------------------------------
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

//-----------------------------------------------------------------------------
// ��� ������� � �������� �������������� ������ �������� ��������
// ���, ������������ IERS
#define EOP_IERS_EST_ORIGIN_Y			2019
// ��� �����-��������� ��� � �������� ���� 
#define EOP_STORAGE_FILE_NAME			"FlyEopStorage"
// ��� �����-��������� ������ �������������� ��� � �������� ����
#define EOP_PREDICT_FILE_NAME			"FlyEopPredict"
// ��� �����-��������� ������ �������� ��������������� ���
#define EOP_ESTIMATE_FILE_NAME			"FlyEopEstimate"
// ��� �����-��������� ��������� ���-� ������� ���������� UTC1-UTC
#define EOP_UTC1UTC_FILE_NAME			"FlyUtc1UtcLocalMod"
// ��� �����-��������� ��������� ���-� ������� ��������� ������
#define EOP_PXY_FILE_NAME				"FlyPXYLocalMod"

// ����������� ��� �� ������� ����������� ���������� � ���
// � ����� ����� ��������� ��������� ���
#define EOP_STORAGE_FILE_DURATION		10
// ��� ������� � ������� � ��������
// ��������� ��� ����������� ������ � ���.
#define EOP_STORAGE_ORIGIN_Y			1980

//-----------------------------------------------------------------------------
// ��������� ����� ������ ������� ���
struct ZSEopItem {
	float MJD = 0;		// ���������������� ��������� ����
	float Xp = 0;		// ���������� ������ � ������� ������������
	float Yp = 0;		//
	float UT1mUTC = 0;	// UT1-UTC � ������������
	// ������ ��� ����� ��� float � �� double ������ � ��� ���, � �����������
	// ������������� ������� �������� ����� ������, ������ ��������� �����
	// ������������� ��� ����� double ����������� �������� ����
	char  key = 0;		// ������� ������������� ������:
	//		0 - ������ �����������
	//		1 - ������ ��������� �� �������������� ������� ������ IERS
	//		2 - ���������� ��������������� IERS
	//		3 - ���������� ��������������� �� ���������� ������
	// ������ �������� ������� ����
	static int Size;
};

// ������ - ��������� ��� �������� ������������ ������� ���
// ����������� �� ��������� ��� (��������� � �������� ����)
typedef vector<ZSEopItem> VZSEop;

//-----------------------------------------------------------------------------
// ������� (��� ���������) �������������� ������ ������ ��������� � ����
// ��������������� �������� 12-� ������� �� �������. ����� ������������� �
// ��������� ���� �� ���� MJD.
struct ZSLocAlgMod {
	float MJD = 0;			// ���� ������ ������� ������
	float A[13];			// ������������
	char  PredictPoints = 0;// ����� ���������� ����� �������������� ���
	// �������� ������
	// ������ �������� ������� ����
	static int Size;
};

//-----------------------------------------------------------------------------
// ������� (��� ���������) �������������� ������ ���� ��������� ���������� 
// � ���� �������������� ��������� 12-� ������� �� �������. ����� �������������
// � ��������� ���� �� ���� MJD.
struct ZSLocAlg2Mod {
	float MJD = 0;			// 
	float A[13];			// ������������ ������� ��������
	float B[13];			// ������������ ������� ��������
	char  PredictPoints = 0;// 
	// ������ �������� ������� ����
	static int Size;
};

//-----------------------------------------------------------------------------
class ZCStorageBinaryFile {
public:
	ZCStorageBinaryFile();
	~ZCStorageBinaryFile();

	void Close();

	// �������� ������ ����� ��� ������� �������� - ������� ��� ����� 
	// ������ � ��������� ��� ����������
	// Type:
	//		0: ��������� ���
	//		1: ��������� �������������� ���
	//		2: ������ �������� ��������������� ���
	// i -  ����� ����� ���������, ������� �� MJD ������ ���������
	//      ������� ���
	const char* GetBinaryFileName(int i = 0, char Type = 0);

	// ��������/�������� �����-��������� � ������� NumFile � 
	// ����� Type. ���� ������ ������� ��� - fromMJD. 
	int Open(int   NumFile  = 0, 
			 char  Type     = 0, 
			 float fromMJD  = 0, 
			 int   ItemSize = 17);

	// ������ ������ � ��� �� ���� I.MJD
	// ���� ������ � ��������� ���� � ��� ��������� �� ������������ true,
	// ����� - false.
	bool operator >> (void* const I) ;

	// ������ ��� � ��������� ��� ���� I.MJD
	ZCStorageBinaryFile& operator << (const void* I);

	// ������ ��������� � ������
	unsigned long GetFSize() const;
	// ������ ��������� � ������
	unsigned long GetISize() const;
	// ����������� ������� � ���������
	unsigned long GetCountItems() const;
	// ��� �����-���������
	const char*   GetFileName() const;

	// ������ ����� ������ ���������
	//static unsigned int ZSEopItemSize;

private:
	// ������ countItems ������� �������� � ��� � ����� ����� File
	void  WriteEmptyEopItems(int addCountItems);
	// ���������� ��������� ���� �� ������ ������
	float GetItemMjd(void* I) const;

	fstream File;
	string  FullName;
	char    NumFileInStorage;
	char*	IMemory;
	unsigned long FSize;
	unsigned long CountItems;
	unsigned long Mjd0;
	unsigned long ISize;
};

//-----------------------------------------------------------------------------
class ZCEopIersBinFile : public ZCStorageBinaryFile {
public:
	// ��������/�������� �����-��������� � ������� NumFile. 
	// ���� ������ ������� ��� - fromMJD. 
	int Open(int NumFile = 0, float fromMJD = 0){
		return (ZCStorageBinaryFile::Open(NumFile, 0, fromMJD, ZSEopItem::Size));
	}
	bool operator >> (ZSEopItem& I) {
		return(*((ZCStorageBinaryFile*)this) >> &I);

	}
	ZCEopIersBinFile& operator << (ZSEopItem& I) {
		*((ZCStorageBinaryFile*)this) << &I;
		return *this;
	}
};

//-----------------------------------------------------------------------------
class ZCEopPredictBinFile : public ZCEopIersBinFile {
public:
	// ��������/�������� �����-��������� � ������� NumFile. 
	// ���� ������ ������� ��� - fromMJD. 
	int Open(int NumFile = 0, float fromMJD = 0){
		return (ZCStorageBinaryFile::Open(NumFile, 1, fromMJD, ZSEopItem::Size));
	}
};

//-----------------------------------------------------------------------------
class ZCEopEstimateBinFile : public ZCEopIersBinFile {
public:
	// ��������/�������� �����-��������� � ������� NumFile. 
	// ���� ������ ������� ��� - fromMJD. 
	int Open(int NumFile = 0, float fromMJD = 0){
		return (ZCStorageBinaryFile::Open(NumFile, 2, fromMJD, ZSEopItem::Size));
	}
};

class ZCPxyModBinFile : public ZCStorageBinaryFile {
public:
	// ��������/�������� �����-��������� � ������� NumFile. 
	// ���� ������ ������� ��� - fromMJD. 
	int Open(int NumFile = 0, float fromMJD = 0){
		return (ZCStorageBinaryFile::Open(NumFile, 3, fromMJD, ZSLocAlg2Mod::Size));
	}
	bool operator >> (ZSLocAlg2Mod& I) {
		return(*((ZCStorageBinaryFile*)this) >> &I);

	}
	ZCPxyModBinFile& operator << (ZSLocAlg2Mod& I) {
		*((ZCStorageBinaryFile*)this) << &I;
		return *this;
	}
};

class ZCUtc1ModBinFile : public ZCStorageBinaryFile {
public:
	// ��������/�������� �����-��������� � ������� NumFile. 
	// ���� ������ ������� ��� - fromMJD. 
	int Open(int NumFile = 0, float fromMJD = 0){
		return (ZCStorageBinaryFile::Open(NumFile, 4, fromMJD, ZSLocAlgMod::Size));
	}
	bool operator >> (ZSLocAlgMod& I) {
		return(*((ZCStorageBinaryFile*)this) >> &I);

	}
	ZCUtc1ModBinFile& operator << (ZSLocAlgMod& I) {
		*((ZCStorageBinaryFile*)this) << &I;
		return *this;
	}
};

//-----------------------------------------------------------------------------
#endif // #ifndef _ZCEOP_BINARY_FILE_H

