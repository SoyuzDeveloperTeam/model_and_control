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
// А. Николенко 12.03.2019
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

	// Удалить всю информацию об индексировании
	void Clear() {
		V1.clear();
		V2.clear();
		V3.clear();
		j =-1 ; 
	} ;
	// Добавить следующие значение в индексацию
	void AddValue(double d) {
	
	} ;
	// Найти значение индекса по ключу 
	int  FindFor(double d) {
		return 0;
	} ;

protected:
	VCluster V1, V2, V3;
	// Массив описаний кластеров - индексы
	//Clusters I;
	// Элемент индекирования - описание кластера
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

	// Максимальное число элементов в кластере
	//static const int IndexesClusterMaxSize = 1000;
	//static const int IndexesClusterMinSize = 10;
	// Число элементов в данном кластере
	//int IndexesClusterSize;
	// Текущий индекс индексируемого массива
	long j;
	// Максимальное и минимальные значения параметра
	//double ValueMin;
	//double ValueMax;
};






// Элемент индексирования
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
	// Вложенные индексы
	void*  NextI ;
} _IndexCluster ;

typedef vector<IndexCluster> Clusters ;


class FLYCORE_API ZIndexes {
public :
	ZIndexes(int ClusterSize=-1) ;
	~ZIndexes() ;

	// Удалить всю информацию об индексировании
	void Clear() ;
	// Добавить следующие значение в индексацию
	void AddValue(double d) ; 
	int  FindFor (double d) ;

protected :
	// Массив описаний кластеров - индексы
	Clusters I ;
	// Элемент индекирования - описание кластера
	IndexCluster II;

private :
	// Максимальное число элементов в кластере
	static const int IndexesClusterMaxSize = 1000 ;
	static const int IndexesClusterMinSize = 10 ;
	// Число элементов в данном кластере
	int IndexesClusterSize ;
	// Текущий индекс индексируемого массива
	long j ;
	// Максимальное и минимальные значения параметра
	double ValueMin ;
	double ValueMax ;
} ;
//-------------------------------------------------------------------------------
#endif // #ifndef _ZINDEX_H