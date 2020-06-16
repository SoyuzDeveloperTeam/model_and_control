//------------------------------------------------------------------------------
// MMath.h
// А. Николенко 03.08.2018
//------------------------------------------------------------------------------
#ifndef MMATH_H
#define MMATH_H
//
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <direct.h>
#include <FlyMMathSource\\MMathDef.h>
#include <FlyMMathSource\\TSelfRemovPointer.h>

//---------------------------------------------------------------------------
// Ближайший элемент
FLYMMATH_API int   NearestIndex(double x, double* xi, int n);

//---------------------------------------------------------------------------
FLYMMATH_API void  CalcMathZero(double* z = 0);
FLYMMATH_API bool  IsEqMath(double X, double Y);

//---------------------------------------------------------------------------
FLYMMATH_API double NormVector(double* A, double* B, int n);
FLYMMATH_API double ModVector(double* A, int n);
FLYMMATH_API double MScalVector(double* A, double* B, int n);
FLYMMATH_API void   SumVector(double* A, double* B, double* C, int n = 3, 
							double* a = NULL, double* b = NULL);
FLYMMATH_API void   SubtractVector(double* A, double* B, double* C, int n = 3, 
							double* a = NULL, double* b = NULL);
//
FLYMMATH_API int MMatr(double* A, double* B, double* C, int n, int k, int m);
FLYMMATH_API int MVector(double* A, double* B, double* C);
FLYMMATH_API int MMatrVactor(double* A, double* V, double* R, int n, int m);
FLYMMATH_API int MatrRotationAxis(double* M, double* R, double* axis0, 
							double angle, int flag = 0);
FLYMMATH_API int MatrRotation(double* M, double* R, double u1, double u2, 
							double u3, int flag = 0, int* axis = 0);
FLYMMATH_API int MatrRotationX(double* M, double* R, double angle, 
							int flag = 0);
FLYMMATH_API int MatrRotationY(double* M, double* R, double angle, 
							int flag = 0);
FLYMMATH_API int MatrRotationZ(double* M, double* R, double angle, 
							int flag = 0);
FLYMMATH_API int MMatrTransp(double* A, double* T, int n, int m);
FLYMMATH_API int VectorAngl(double* A, double* B, double& U, char dim = 1);

//------------------------------------------------------------------------------
FLYMMATH_API double scal_pr_norm(double* a, double* b, short n);
FLYMMATH_API double scal_pr(double* a, double* b, short n);
FLYMMATH_API void   wek_pr(double* a, double* b, double* d);
FLYMMATH_API void   wek_pr_norm(double* a, double* b, double* d);

FLYMMATH_API void   TRAM  (double* a, double* b, short m, short n);
FLYMMATH_API void   UMN   (double* a, double* b, double* c, 
						   short m, short n, short l);
FLYMMATH_API void   Um_Mat(double* a, double* b, double* c, 
						   short m, short n, short l);
FLYMMATH_API void   umobr (double* m, double* v, double* rez);
FLYMMATH_API void   umpr  (double* m, double* v, double* rez);

FLYMMATH_API void    UMN_MATR_PRM_VECT(double *dMatr, double *dVectIsx, 
						   double *dVectRez);
FLYMMATH_API void    UMN_MATR_TRN_VECT(double *dMatr, double *dVectIsx, 
						   double *dVectRez);
FLYMMATH_API void    UMN_MATR_PRM_VECT_ADD(double *dMatr, double *dVectIsx, 
						   double *dVectRez);
FLYMMATH_API void    UMN_MATR_TRN_VECT_ADD(double *dMatr, double *dVectIsx, 
						   double *dVectRez);
FLYMMATH_API void    UMN_MATR(double *dMatrA, double *dMatrB, double *dMatrC, 
						   short M, short N, short L);
FLYMMATH_API void    UMN_MATR_ADD(double *dMatrA, double *dMatrB, 
						   double *dMatrC, short M, short N, short L);

FLYMMATH_API double dargum(double X, double Y);

FLYMMATH_API double FK(int N);
FLYMMATH_API double FRR(double *v1, double *v2);
FLYMMATH_API double FR(double *k);
FLYMMATH_API double FR2(double *k);
//------------------------------------------------------------------------------
// Коррекция витка и аргумента широты с целью приведения значения аргумента к
// диапазону [0; 360] град. Функция позволяет учитывать возможность 
// сползвния, например в итерационном процессе, аргумента широты 
// на предыдущий или наоборот на следующий виток.
// Выполняется приведение аргумента широты в диапазон [0; 360] град с 
// одновременной, при необходимости, коррекцией витка. 
//
// Функция реализуется в виде шаблона, так как
// виток v, может задаваться целочисленными переменными различного типа.
//
// Конечно меня могут спросить: зачем я это сделал? ... 
// Ответить могу только так: просто попробовал экспортировать шаблонную функцию
// из динамической библиотеки.
template <typename ArgType, typename VitType> 
FLYMMATH_API void SuitabilityTurnArg(ArgType& u, VitType& v, bool fromGrad=true);

//------------------------------------------------------------------------------
// Решение линейной системы уравнений
FLYMMATH_API int SolutionLineSystem(int n, double* a, double* b, double* x);

// Интерполяция по Адамсу 4 порядка по 5 точкам
//		points	- массив из 5 точек вдоль траектории
//		e		- Коэффициэнт интерполяции
//		agin	- Массив результатов интерполяции	
FLYMMATH_API int MITA4(double points[5][7], double e, double TVR[7]);
FLYMMATH_API int MITA8(double** Hist, int nx, double e, double *TVR);
FLYMMATH_API int MGSCtoHBL(double TVR[7], double& bge, double& lge, 
						   double& hge);
FLYMMATH_API int MITAfromL(double lz, double l1, double l2, 
						   double points[5][7], double& bge, double* TVR);
FLYMMATH_API int MITAfromB(double bz, double b1, double b2, 
						   double points[5][7], double& lge, double* TVR);
//
FLYMMATH_API void   ReCalcMaxMinAxis(double& MaxV, double& MinV, int Len);
FLYMMATH_API int    MainRank(double x);
FLYMMATH_API double ToRoundOff(double x, int dec, bool isUpp);
FLYMMATH_API double ToRoundOffUpp(double x, int dec);
FLYMMATH_API double ToRoundOffDown(double x, int dec);
FLYMMATH_API double ToRoundLen(double x, int Len, bool isUpp);
FLYMMATH_API double ToRoundLenUpp(double x, int Len);
FLYMMATH_API double ToRoundLenDown(double x, int Len);

//---------------------------------------------------------------------------
// dim = 1 град, = 0 рад
FLYMMATH_API double ValiDA(double dl, char dim = 1);
FLYMMATH_API double ValiA(double dl, char dim = 1);
FLYMMATH_API int    QtrArc(double u, char dim = 1);
FLYMMATH_API double RadA(double u);
FLYMMATH_API double GradA(double u);
FLYMMATH_API double Trigs(double x);
FLYMMATH_API double AcosSS(double c, double ss, char dim = 1);
FLYMMATH_API double AsinSC(double s, double sc, char dim = 1);
FLYMMATH_API double AtanSC(double t, double sc, char dim = 1);
FLYMMATH_API double Cos(double u, char dim = 1);
FLYMMATH_API double Sin(double u, char dim = 1);
FLYMMATH_API double Tan(double u, char dim = 1);
FLYMMATH_API double Asin(double s, char dim = 1);
FLYMMATH_API double Acos(double c, char dim = 1);
FLYMMATH_API double Atan(double t, char dim = 1);
FLYMMATH_API double Atan2(double y, double x, char dim = 1);
FLYMMATH_API double Sinh(double x);
FLYMMATH_API double Cosh(double x);
FLYMMATH_API double Tanh(double x);
FLYMMATH_API double Asinh(double x);
FLYMMATH_API double Acosh(double x);
FLYMMATH_API double Atanh(double x);
FLYMMATH_API double Sqrt(double x);
FLYMMATH_API double Pow(double x, double y);
FLYMMATH_API double Log(double x);

//-------------------------------------------------------------------------------
// Определение наибольшего общего делителя двух целых чисел
FLYMMATH_API int MFindNOD(long A, long B, long& D);

//-------------------------------------------------------------------------------
// Анализ дроби на возможность сокращения делителя и знаменателя
//                              K
// Анализ рационального числа -----
//                              L
//                   KD
// Сокращение её до -----
//                   LD
FLYMMATH_API int IsItCompletelyDivided(int K, int L, int& KD, int& LD);

//-------------------------------------------------------------------------------
// Решение алгебраического уравнения третьей степени по формулам Кардано
// A[0]*x3+A[1]*x2+A[2]*x+A[3] = 0 ; 
// Результат решения в 
//		Xr			-	действительная часть корня
//		Xi			-	мнимая часть корня
//		CountRoot	-	число найденных корней 
// Если Xi[.] = 0, то корень действительный
//-------------------------------------------------------------------------------
FLYMMATH_API int MSolv3DegreeEquation(double* K, double* Xr, double* Xi, 
							 int* CountRoot=nullptr);

//---------------------------------------------------------------------------
FLYMMATH_API int DoubleCode2(double d, char* S, 
							 int sizeNet=255, int MaxBinaryDec=32);
FLYMMATH_API int DoubleDeCode2(char* S, double& d);
FLYMMATH_API int RoundDownBinaryDouble(double d, double& fd, 
							 int MaxBinaryDec=32);
//
#endif // #ifndef MMATH_H
