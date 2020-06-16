//---------------------------------------------------------------------------
// ZSK.h
// А. Николенко 03.08.2018
//---------------------------------------------------------------------------
#ifndef _Z_SK_H
#define _Z_SK_H

enum SK_TYPE { _SK_ASK1975 = 0, _SK_GSK     = 1, _SK_GSKZ  = 2, _SK_ASKTES = 6, 
			   _SK_ASKTE   = 7, _SK_OSK1975 = 8, _SK_OSKTE = 9, _SK_OSKTES = 10, 
			   _SK_ASK2000 =11, _SK_OSK2000 =12, _SK_RLN   = 101};
/*
#define _SK_1975 0
#define _SK_TES	 6
#define _SK_TE	 7
#define _SK_2000 11 
#define _SK_RLN	 101 
*/
/*
#define _SK_ASK1975	0
#define _SK_GSK		1 
#define _SK_GSKZ	2 
#define _SK_ASKTES	6
#define _SK_ASKTE	7
#define _SK_OSK1975	8
#define _SK_OSKTE	9
#define _SK_OSKTES	10
#define _SK_ASK2000	11 
#define _SK_OSK2000	12
*/
//---------------------------------------------------------------------------
// Перевод координат между АСК-2000, АСК-1975, АСК-ЕЭ и АСК_ТЭС
FLYCORE_API int ZASC_2000to1975(double *dASC_2000, double *dASC_1975, bool Speed);
FLYCORE_API int ZASC_1975to2000(double *dASC_1975, double *dASC_2000, bool Speed);

FLYCORE_API int ZASC_2000toTE(double t, double *dASC_2000, double *dASC_TE, bool Speed);
FLYCORE_API int ZASC_TEto2000(double t, double *dASC_TE, double *dASC_2000, bool Speed);

FLYCORE_API int ZASC_2000toTES(double t, double *dASC_2000, double *dASC_TE, bool Speed);
FLYCORE_API int ZASC_TESto2000(double t, double *dASC_TE, double *dASC_2000, bool Speed);

FLYCORE_API int ZASC_1975toTE(double t, double* dASC_1975, double* dASC_TE, bool Speed);
FLYCORE_API int ZASC_TEto1975(double t, double* dASC_TE, double* dASC_1975, bool Speed);

FLYCORE_API int ZASC_1975toTES(double t, double* dASC_1975, double* dASC_TE, bool Speed);
FLYCORE_API int ZASC_TESto1975(double t, double* dASC_TE, double* dASC_1975, bool Speed);

//---------------------------------------------------------------------------
// Перевод координат в ГСК и обратно из АСК-2000 и АСК-1975
FLYCORE_API int ZASC2000toGSC(double t, double* dASC_2000, double* dGSC, bool Flag_R);
FLYCORE_API int ZGSCtoASC2000(double t, double* dGSC, double* dASC_2000, bool Flag_R);

FLYCORE_API int ZASC1975toGSC(double t, double* dASC_1975, double* dGSC, bool Flag_R);
FLYCORE_API int ZGSCtoASC1975(double t, double* dGSC, double* dASC_1975, bool Flag_R);

//---------------------------------------------------------------------------
// Кеплеровы элементы орбиты
FLYCORE_API void ZASCtoOSC(double *a, double *o);
FLYCORE_API void ZOSCtoASC(double *o, double *a);

FLYCORE_API int  ZCalcKEO(double *A, double *KEO);
FLYCORE_API void ZM_ASCtoOSC(double *ask, double *m);
FLYCORE_API void ZM_OSCtoASC(double *keo, double *m);

//---------------------------------------------------------------------------
FLYCORE_API void anom(double* x, double *y);
FLYCORE_API void kep_rml(double* anom);
FLYCORE_API void ask_nsk(double* ask, double* nsk, short direct, short* delta, short sk, double Mu);
FLYCORE_API void ask_psk(double* ask, double* psk, short direct, short* delta);
FLYCORE_API void psk_nsk(double* psk, double* nsk, short direct, short* delta, short sk, double Mu);

//---------------------------------------------------------------------------
// Преобразование вектора (ASC) из АСК в орбитальную систему координат (RLN), 
// заданную радиусом и скоростью (RV) и обратно
FLYCORE_API void  ZASCtoRLN(double *RV, double *ASC, double *RLN, bool andV = false, bool isInerc = false);
FLYCORE_API void  ZRLNtoASC(double *RV, double *RLN, double *ASC, bool andV = false, bool isInerc = false);
// Вычисление матрицы преобразования вектора из АСК в орбитальную систему координат, 
// заданную радиусом и скоростью (RV) и обратно. 
//		MRV - матрица пересчёта шестёрки (координаты и скорости)
//		MR  - матрица пересчёта координат
//		MV  - матрица пересчёта скоростей
FLYCORE_API void  ZCalcM_ASCtoRLN(double *RV, double *MRV = nullptr, double* MR = nullptr, double* MV = nullptr, int Direct = 0, bool isInerc = false);
// Вычисление прямого восхождения и склонения по декартовым координатам
//		x	- X, Y, Z
//		ad	- прямое восхождение ad[0], склонение ad[1], радиус ad[2]
//		dim - 1 размерность углов градусы, 0 - радианы 
FLYCORE_API void  ZASCtoAscensionDecination(double *x, double *ad, bool dim = 0);

//---------------------------------------------------------------------------

#endif // #ifndef _Z_SK_H