//-----------------------------------------------------------------------------
// ZCAlgebraicMdfHolder.h
// �. ��������� 01.04.2019
//
// �������� ��������� ��������� �������������� ������� 
// ��������������� ��������� �������, �������� ������� �������� ��������� 
// � ����� �������.
//-----------------------------------------------------------------------------
#ifndef ZC_ALGEBRAIC_MDF_MANAGER_H
#define ZC_ALGEBRAIC_MDF_MANAGER_H

class ZCAlgebraicModDF;

typedef struct ZSStorageEOPHeaderItem {
	double			MJD;
	unsigned long	shiftData;
} _ZSStorageEOPHeaderItem ;

class FLYCORE_API ZCAlgebraicMdfHolder {
public:
	ZCAlgebraicMdfHolder() {
		CI = -1;
		ItVM = VM.end();
		TimeFrame = 93;
		TimeFrameType = 1;
		TimeFrameMargin = 2;
		StorageName = "AprMod.bin";
	}

	~ZCAlgebraicMdfHolder() {
		VM.clear();
	}

	//-------------------------------------------------------------------------
	// ����� ����� ����������� ������ ���������� ��� ������� ������� t 
	int FindMod(double t, ZCAlgebraicMDF* MS, ZCAlgebraicMDF* MC = nullptr);
	// ����� � ��������� ������� (� ����������� ������� ��������� �������)
	int FindModInCollection(double t, ZCAlgebraicMDF* MC=nullptr);
	// ����� � ���������� (������������ ������ ��������� ������� - ���� ��� ��)
	//		MS - ������ ��������� � ���������
	//		MC - ������ ��������� � ���������
	int FindModInStorage(double t, ZCAlgebraicMDF* MS);

	//-------------------------------------------------------------------------
	// �������� ����� �������������� ������ �� ��������� ���������� �������
	// �������� ���������� ������� ���������� ����������� ������
	// LoadDFfromTime
	//int NewMod(double t);
	// ���������������� ��������� ��������������� ������ - 
	// ���������� ������������� �������� ��������
	int BuildNewMod(double* T, double* Y, int N);

	//-------------------------------------------------------------------------
	// ���������� �������� ������� �������������� ������
	int Calc(double t, double& F);
	int Calc(double t, float& F);

	//-------------------------------------------------------------------------
	// ������ �������� �������� ���������� �������
	//-------------------------------------------------------------------------
	//virtual int LoadDFfromTime(double fromTime, double toTime,
	//						   double** T, double** Y, int& N);

	//-------------------------------------------------------------------------
	// ������ ������ ��������������� �������� � ���������� �������
	//-------------------------------------------------------------------------

	// ��������� � ��������� ��� ��������� ��� ����������� ����� 
	// ��������� ������
	int SaveToStorage(vector<ZCAlgebraicMDF>* LVM=nullptr);

	// �������� ��������� ������� ������ ���������������� ��������.
	// ������, ������� ������� isGenerated ������ true ����� �������� �
	// ��������� ��������� �������.
	int UpdateStorage(vector<ZCAlgebraicMDF>* LVM = nullptr, 
					  bool LikeMove=false);

	// ��������� �� ��������� ��� ��������� ��� �������������� ������
	int LoadFromStorage(vector<ZCAlgebraicMDF>* LVM = nullptr);

	// ��������� �� ��������� �������������� ������ ���������� 
	// ��� ������� fromTime 
	int LoadFromStorage(double fromTime);

	// ��������� �� ��������� ���� ��� ��������� ��������������  
	// ������� ���������� ��� ��������� ������� 
	// �� fromTime �� toTime.
	int LoadFromStorage(double fromTime, double toTime);

	// ��� �����-���������
	void SetStorageName(const char* Name) { StorageName = Name; }
	const char* GetStorageName() { return StorageName.c_str(); }
	const char* GetFileStorageName() { 
		StorageFileName = DIRINFO;
		StorageFileName+= "\\";
		StorageFileName+= StorageName;
		return StorageFileName.c_str();
	}

	// ������ ����-������ - ������� ����������� ����������� ���������
	// �������������� �������.
	void SetTimeFrameType(char TFT) { 
		TimeFrameType = TFT; 
		switch (TFT) {
		case 0: TimeFrame = 32; break;
		case 1: TimeFrame = 93; break;
		case 2: TimeFrame = 186; break;
		case 3: TimeFrame = 367; break;
		default: assert(0);
		}
	}
	char GetTimeFrameType() { return TimeFrameType; }
	long GetTimeFrame() { return TimeFrame; }

	// ���������� ������� ������ ���� ������ ����������� ������ ������� t,
	// �������� ���������������� ��������� �����, ���� fromMjd=true, ���
	// ������� �������� ���� fromMjd=false. 
	double FindTimeFrameBeg(double t, bool fromMjd = false);

protected:
	// ������� ������ ��������� �������������� ������
	int CI;
	// ������ �������������� �������
	vector<ZCAlgebraicMDF> VM;
	// �������� ������� �������������� ������
	vector<ZCAlgebraicMDF>::iterator ItVM;

	// ������������ ���������� ������ �� ������� ����� ���������� ������
	// �������������� ������.
	long TimeFrame;
	char TimeFrameType;
	// ���� ���� ������ ��� ���������� ������������ �� ����� ������.
	long TimeFrameMargin;
	// ��� �����-��������� ��� � �������� ���� 
	string StorageName;
	string StorageFileName;
};

//-----------------------------------------------------------------------------
#endif // #ifndef ZC_ALGEBRAIC_MDF_MANAGER_H