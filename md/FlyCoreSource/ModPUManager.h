//------------------------------------------------------------------------
// ModPUManager.h
// А. Николенко 15.08.2018
//------------------------------------------------------------------------
#ifndef ModPUMANAGER_H
#define ModPUMANAGER_H

#include <iterator>
#include <FlyCoreSource\\ModPUItem.h>
#include <FlyCoreSource\\ModPUSwitchOn.h>
#include <FlyCoreSource\\ModPU.h>

//------------------------------------------------------------------------
// Менеджер программ управления
//------------------------------------------------------------------------
#define MAX_PU_COUNT_MOD 36 

class FLYCORE_API ZPUManager {
public :
	ZPUManager() ;
	~ZPUManager() ;
	void Init() ;

	// Удалить все загруженные программы управления
	void Clear() ;
	// Проверка наличия данных о программах движения
	bool isEmpty() ;
	// Колличество установленных программ управления
	int  Size() ;
	// Добавить программу управления в список 
	int  Add(ZPU &I) ;
	ZPU* Add(int* ind=nullptr) ;
	void operator << (ZPU &I) ;
	// Задать программу управления
	int  Set(ZPU &I, int ind) ;
	// Удалить программу управления
	int  Del(int ind=-1) ;
	// Доступ к заданной программе управления
	ZPU* Get(int ind) ;

	// Загрузить из БД 
	int LoadFromBD(int ka, int pu, ZPU &I) { return 0 ; } 
	// Сохранить в БД 
	int SaveToBD  (int ka, int pu, ZPU &I) { return 0 ; } 

	// Проверка наличия точки разрыва ПЧ СДУ в пределах ближайшего шага интегрирования
	int  TimeCheckForStep(double t, int dir, long* IDDUMSG=nullptr, double* maxstep=nullptr) ; 
	//int  TimeCheckPostStep(double t, int dir, long& IDMSG) ;
	// Сброс всех индексов
	void ClearIndex() ;
	// Построение индексов и определение ближайших точек разрыва ПЧ СДУ
	void Indexing(double t, int dir) ;
	// Ближайшие точки разрыва ПЧ СДУ
	void GetTimePoint(int& Key, double& PrevT, double& NextT, long& PrevIDMSG, long& NextIDMSG) ;
	// Расчёт ускорений для правых частей СДУ
	int  CalcRLN(double t, double m, double* arln, double* pMs) ;

protected :
	// Оперативный массив программ управления
	ZPU PU[MAX_PU_COUNT_MOD] ;
	// Число установленных программ управления 
	int Count ;
	// Массивы индексов
	int    IndexVN[MAX_PU_COUNT_MOD] ;
	int    IndexVP[MAX_PU_COUNT_MOD] ;
	int    IndexV [MAX_PU_COUNT_MOD] ;
	int    IndexU [MAX_PU_COUNT_MOD] ;
	double TIndex ;

	// Момент времени разрыва правых частей СДУ (включение, выключение ДУ или начало, конец очередного участка на включении)
	double NextTimePoint ;
	double PrevTimePoint ;
	int    TimePointKey ;

	long PrevIDMSG ;
	long NextIDMSG ;
	long CurIDMSG ;
} ;

//------------------------------------------------------------------------
#endif // #ifndef ModPUMANAGER_H