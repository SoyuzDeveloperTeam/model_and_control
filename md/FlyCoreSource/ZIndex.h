//-------------------------------------------------------------------------------
// ZIndex.h
//---------------------------------------------------------------------------
// 
// 
//
//
//
//
//
//
// �. ��������� 12.03.2019
//-------------------------------------------------------------------------------
#ifndef _ZINDEX_H
#define _ZINDEX_H

class ZIndexes ;

typedef struct ZICluster {
	ZICluster() {
		D1 = D2 = 0 ;
		iFirst =-1 ;
		iLast  =-1 ;
	}
	~ZICluster() {
	}

	double D1;
	double D2;
	int    iFirst;
	int    iLast;
} _ZICluster ;

typedef vector<ZICluster> VCluster;

class FLYCORE_API ZIndex {
public:
	ZIndex() {
		j =-1 ;
	};
	~ZIndex() {
	};

	// ������� ��� ���������� �� ��������������
	void Clear() {
		V1.clear();
		V2.clear();
		V3.clear();
		j =-1 ; 
	} ;
	// �������� ��������� �������� � ����������
	void AddValue(double d) {
	
	} ;
	// ����� �������� ������� �� ����� 
	int  FindFor(double d) {
		return 0;
	} ;

protected:
	VCluster V1, V2, V3;
	// ������ �������� ��������� - �������
	//Clusters I;
	// ������� ������������� - �������� ��������
	//IndexCluster II;

private:
	void PutValueToVector(double d, VCluster& V) {
		int Size = V.size() ;
		j++;
		if (!Size || Size==10) {
			ZICluster C ;
			C.D1 = C.D2 = d;
			C.iFirst = C.iLast = j;
			V.push_back(C) ;
			return ;
		}
		int i = Size-1 ;
		V[i].D2 = d ;
		V[i].iLast = j ;





	} ;

	// ������������ ����� ��������� � ��������
	//static const int IndexesClusterMaxSize = 1000;
	//static const int IndexesClusterMinSize = 10;
	// ����� ��������� � ������ ��������
	//int IndexesClusterSize;
	// ������� ������ �������������� �������
	long j;
	// ������������ � ����������� �������� ���������
	//double ValueMin;
	//double ValueMax;
};






// ������� ��������������
typedef struct IndexCluster {
	IndexCluster() { 
		NextI = nullptr ;
		Clear() ; 
	}
	~IndexCluster() { 
		Clear() ; 
	}
	void Clear() ; 

	double D1 ;
	double D2 ;
	int    iFirst ;
	int    iLast ; 
	// ��������� �������
	void*  NextI ;
} _IndexCluster ;

typedef vector<IndexCluster> Clusters ;


class FLYCORE_API ZIndexes {
public :
	ZIndexes(int ClusterSize=-1) ;
	~ZIndexes() ;

	// ������� ��� ���������� �� ��������������
	void Clear() ;
	// �������� ��������� �������� � ����������
	void AddValue(double d) ; 
	int  FindFor (double d) ;

protected :
	// ������ �������� ��������� - �������
	Clusters I ;
	// ������� ������������� - �������� ��������
	IndexCluster II;

private :
	// ������������ ����� ��������� � ��������
	static const int IndexesClusterMaxSize = 1000 ;
	static const int IndexesClusterMinSize = 10 ;
	// ����� ��������� � ������ ��������
	int IndexesClusterSize ;
	// ������� ������ �������������� �������
	long j ;
	// ������������ � ����������� �������� ���������
	double ValueMin ;
	double ValueMax ;
} ;
//-------------------------------------------------------------------------------
#endif // #ifndef _ZINDEX_H