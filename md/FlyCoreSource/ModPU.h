//------------------------------------------------------------------------
// ModPU.h
// А. Николенко 15.08.2018
//------------------------------------------------------------------------
#ifndef ModPU_H
#define ModPU_H

#include <iterator>
class ZPUManager ;

//------------------------------------------------------------------------
// Программа управления
//------------------------------------------------------------------------
class FLYCORE_API ZPU {
public :
	friend ZPUManager ;
	ZPU() ;
	~ZPU() ;

	void Clear() ;
	int  Size() ;
	bool isEmpty() ;

	// Добавить включение в список 
	ZVPU* Add(int* ind=nullptr) ;
	void  Add(ZVPU &I) ;
	void  operator << (const ZVPU &I) ;
	// Задать включение
	int   Set(ZVPU &I, int ind) ;
	// Удалить включение
	int   Del(int ind, int Count=1) ;
	// Доступ к заданному включению
	ZVPU* Get(int ind) ;

	// Время начала включения
	double TS() ;
	// Время конца включения
	double TE() ;
	// сортировка участков по времени
	void   SortItem() ;

	vector<ZVPU> V ;
	int          NumPU ;
	bool		 IsOn ;		// Признак активности данной программы управления
} ;

//------------------------------------------------------------------------
#endif // #ifndef ModPU_H
