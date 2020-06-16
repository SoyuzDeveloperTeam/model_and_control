//------------------------------------------------------------------------
// ModPUSwitchOn.h
// А. Николенко 15.08.2018
//------------------------------------------------------------------------
#ifndef ModPUSWITCHON_H
#define ModPUSWITCHON_H

#include <iterator>
class ZPUManager ;

//------------------------------------------------------------------------
// Включение программы управления
//------------------------------------------------------------------------
class FLYCORE_API ZVPU {
public :
	friend ZPUManager ;
	ZVPU() ;
	~ZVPU() ;

	void Clear() ;
	int  Size() ;
	bool isEmpty() ;

	// Добавить участок в список 
	ZPUItem* Add(int* ind=nullptr) ;
	void     Add(ZPUItem &I) ;
	void     operator << (ZPUItem &I) ;
	// Задать участок
	int      Set(ZPUItem &I, int ind) ;
	// Удалить участок
	int      Del(int ind, int Count=1) ;
	// Доступ к заданному участку
	ZPUItem* Get(int ind) ;

	// Время начала включения
	double TS() ;
	// Время конца включения
	double TE() ;
	// сортировка участков по времени
	void   SortItem() ;

protected:
	vector<ZPUItem> U ;
	int             NumDU ;
} ;

#define I_ZVPU vector<ZVPU>::iterator 
FLYCORE_API bool operator < (ZVPU &U1, ZVPU &U2);

//------------------------------------------------------------------------
#endif // #ifndef ModPUSWITCHON_H