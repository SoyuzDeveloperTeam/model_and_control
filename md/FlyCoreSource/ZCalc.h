//---------------------------------------------------------------------------
// ZCalc.h
// А. Николенко 03.08.2018
// Некоторые вычислительные процедуры общщего назначения
//---------------------------------------------------------------------------
#ifndef _Z_CALC_H
#define _Z_CALC_H

// Размерности угловых величин
enum DIMANGL {DimAnglRad=0, DimAnglGrad=1, DimAnglSSS=2, DimAnglH=3, DimAnglMin=4, DimAnglSec=5} ;

//------------------------------------------------------------------------------
// Преобразование угловой величины в иную размерность (размерность определяется типом DIMANGL)
//		a         - угловая величина в исходной размерности fromdim
//		результат - угловая в требуемой размерности todim 
FLYCORE_API double AngleDimConv(double a, DIMANGL fromdim, DIMANGL todim);

//------------------------------------------------------------------------------
// Размернонезависимая угловая величина
// Суть состоит в том что вместе с величиной хранится её размерность,
// которая может учитываться при выполнении арифметических операций
// с величинами подобного типа.
// Учет размерности реализован в перегруженных операторах "+", "-", "*", "/",
// а также в операторе присвоения
class FLYCORE_API ZANGL {
public:
	ZANGL(double an=0, DIMANGL dim=DimAnglRad) { a=an ; d=dim ; }
	ZANGL(const ZANGL& Z) { a=Z.a ; d=Z.d ; }
	double  a ;
	DIMANGL d ;
	operator double () { return a ; }
	operator float  () { return (float)a ; }
	operator short  () { return (short)a ; }
	operator long   () { return (long)a ; }
	operator int    () { return (int)a ; }
	ZANGL& operator = (double an) { a=an ; d=DimAnglRad ; return *this ; }
	ZANGL& operator = (ZANGL& Z ) { a=Z.a ; d=Z.d ; return *this ; }
	double operator () (DIMANGL dim=DimAnglRad) { return AngleDimConv(a, d, dim) ; } ;

	friend ZANGL operator + (ZANGL&, ZANGL&) ;
	friend ZANGL operator - (ZANGL& A1, ZANGL& A2) ;
	friend ZANGL operator * (ZANGL& A1, ZANGL& A2) ;
	friend ZANGL operator / (ZANGL& A1, ZANGL& A2) ;
	friend ZANGL operator + (ZANGL& A1, double& A2) ;
	friend ZANGL operator - (ZANGL& A1, double& A2) ;
	friend ZANGL operator * (ZANGL& A1, double& A2) ;
	friend ZANGL operator / (ZANGL& A1, double& A2) ;
	friend ZANGL operator + (double& A1, ZANGL& A2) ;
	friend ZANGL operator - (double& A1, ZANGL& A2) ;
	friend ZANGL operator * (double& A1, ZANGL& A2) ;
	friend ZANGL operator / (double& A1, ZANGL& A2) ;
} ;

inline ZANGL operator + (ZANGL& A1, ZANGL& A2)  { ZANGL A(A1) ; A.a+= AngleDimConv(A2.a, A2.d, A1.d) ; return A ; }   
inline ZANGL operator - (ZANGL& A1, ZANGL& A2)  { ZANGL A(A1) ; A.a-= AngleDimConv(A2.a, A2.d, A1.d) ; return A ; }   
inline ZANGL operator * (ZANGL& A1, ZANGL& A2)  { ZANGL A(A1) ; A.a*= AngleDimConv(A2.a, A2.d, A1.d) ; return A ; }   
inline ZANGL operator / (ZANGL& A1, ZANGL& A2)  { ZANGL A(A1) ; A.a/= AngleDimConv(A2.a, A2.d, A1.d) ; return A ; }   
inline ZANGL operator + (ZANGL& A1, double& A2) { ZANGL A(A1) ; A.a+= A2 ; return A ; }   
inline ZANGL operator - (ZANGL& A1, double& A2) { ZANGL A(A1) ; A.a-= A2 ; return A ; }   
inline ZANGL operator * (ZANGL& A1, double& A2) { ZANGL A(A1) ; A.a*= A2 ; return A ; }   
inline ZANGL operator / (ZANGL& A1, double& A2) { ZANGL A(A1) ; A.a/= A2 ; return A ; }   
inline ZANGL operator + (double& A1, ZANGL& A2) { ZANGL A(A1, A2.d) ; A.a+= A2.a ; return A ; }   
inline ZANGL operator - (double& A1, ZANGL& A2) { ZANGL A(A1, A2.d) ; A.a-= A2.a ; return A ; }   
inline ZANGL operator * (double& A1, ZANGL& A2) { ZANGL A(A1, A2.d) ; A.a*= A2.a ; return A ; }   
inline ZANGL operator / (double& A1, ZANGL& A2) { ZANGL A(A1, A2.d) ; A.a/= A2.a ; return A ; }   

//------------------------------------------------------------------------------
// Вычисление местного СРЕДНЕГО солнечного времени tmss 
// на долготе L по атомному AtomicTime, отсчитанному от J1975 
//		AtomicTime - атомное время от эпохи J1975
//		L          - гринвическая долгота в градусах
//		tmss       - искомое среднее солнечное время
//		dim        - размерность tmis:
//		             0 - в радианах
//                   1 - в градусах
//                   2 - в ссс
//                   3 - в часах
//------------------------------------------------------------------------------
FLYCORE_API int ZCalcMSSV(double AtomicTime, double L, double& tmss, DIMANGL dim = DimAnglSSS);
//------------------------------------------------------------------------------
// Вычисление местного ИСТИННОГО солнечного времени tmss 
// на долготе L по атомному ta, отсчитанному от J1975 
//		AtomicTime - атомное время от эпохи J1975
//		L          - гринвическая долгота в градусах
//		tmis       - искомое истинное солнечное время
//		dim        - размерность tmis:
//		             0 - в радианах
//                   1 - в градусах
//                   2 - в ссс
//                   3 - в часах
//------------------------------------------------------------------------------
FLYCORE_API int ZCalcMISV(double AtomicTime, double L, double& tmis, DIMANGL dim = DimAnglRad);
//---------------------------------------------------------------------------
//    Расчет высоты объекта над ОЗЭ (или ЭК если fromEK=true) 
//    и производной по времени.
//---------------------------------------------------------------------------
//   Прототип: void ZHightDif (double *w, double *hht);
//   Входные параметры:
//         w - координаты в ГСК (x,y,z,Vx,Vy,Vz).
//   Выходные параметры:
//         hht[0] - высота над ОЗЭ,
//         hht[1] - радиус,
//         hht[2] - производная высоты по времени,
//         hht[3] - производная радиуса по времени.
//   Возвращаемое значение: нет.
//---------------------------------------------------------------------------
FLYCORE_API void ZCalcHightDif(double *Xgsc, double *ht, bool fromEK = false);

//---------------------------------------------------------------------------
#endif // #ifndef _Z_CALC_H