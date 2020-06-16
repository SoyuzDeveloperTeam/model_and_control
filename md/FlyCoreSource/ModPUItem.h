//------------------------------------------------------------------------
// ModPUItem.h
// А. Николенко 15.08.2018
//------------------------------------------------------------------------
#ifndef ModPUITEM_H
#define ModPUITEM_H

#include <iterator>

//------------------------------------------------------------------------
// Элемент программы управления
//------------------------------------------------------------------------
typedef enum varPUItem{varPU_ppu, varPU_pms, varPU_pums} ZVARPU ;

struct SPUItem {
	ZVARPU var ;
	double t ;       // Время включения в [ссс]
	double dt ;      // Длительность включения в [сек]
	double P ;       // Тяга в [кгс]
	union {
		double Pu ;  // Удельная тяга в [сек]
		double ms ;  // Секундный расход топлива [кг/сек]
	} ;
	double dP ;      // Произмодная от тяги по времени кгс/сек
	union {
		double dPu ; // Производная от удельной тяги бр
		double dms ; // Производная от удельной тяги [кг/сек2]
	} ;
	double a ;       // Ориентация импкльса, рыскание [град]
	double b ;       // тангаж [град]
	double da ;      // Скорость разворота вектора тяги, по рысканию [град/сек]
	double db ;      // тангажу
};

#define ZVarPUpms SPUItem::varPU_pms
#define ZVarPUppu SPUItem::varPU_ppu

//------------------------------------------------------------------------
class FLYCORE_API ZPUItem : public SPUItem {
public :
	ZPUItem() ;
	// Время начала включения
	double TS() ;
	// Время конца включения
	double TE() ;
	// Расчёт ускорений в орбитальной СК
	int CalcARLN (double t, double m, double* Arln, double* pMs=0, double* pP=0, double* pPu=0) ;  
private :
} ;

#define I_ZPUItem vector<ZPUItem>::iterator 

FLYCORE_API bool operator < (const ZPUItem &U1, const ZPUItem &U2);

//------------------------------------------------------------------------
// Трансверсальный положительный участок работы ДУ
class FLYCORE_API ZPUI_tauP : public ZPUItem {
public : 
	ZPUI_tauP(double t_, double dt_):ZPUItem() { t=t_ ; dt=dt_ ; }
} ;
//------------------------------------------------------------------------
// Трансверсальный отрицательный участок работы ДУ
class FLYCORE_API ZPUI_tauN : public ZPUItem {
public : 
	ZPUI_tauN(double t_, double dt_):ZPUItem() { t=t_ ; dt=dt_ ; a=180 ; }
} ;
//------------------------------------------------------------------------
// Нормальный положительный участок работы ДУ
class FLYCORE_API ZPUI_normP : public ZPUItem {
public : 
	ZPUI_normP(double t_, double dt_):ZPUItem() { t=t_ ; dt=dt_ ; a=90 ; }
} ;
//------------------------------------------------------------------------
// Нормальный отрицательный участок работы ДУ
class FLYCORE_API ZPUI_normN : public ZPUItem{
public : 
	ZPUI_normN(double t_, double dt_):ZPUItem() { t=t_ ; dt=dt_ ; a=270 ; }
} ;

//------------------------------------------------------------------------

#endif // #ifndef ModPUITEM_H