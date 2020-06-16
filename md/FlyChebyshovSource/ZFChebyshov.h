//-------------------------------------------------------------------------------
// ZFChebyshov.h : 
// Апроксимация полиномами Чебышова
// Исходные коды заимствованны из внешних источников 13.03.2019
//-------------------------------------------------------------------------------
#ifndef Aprox_ChebH
#define Aprox_ChebH

// Максимальная степень полинома 
#define _MAX_STEP_APPROKS_POL  40

#include <FlySSP.h>

//------------------------------------------------------------------------------
// Функция расчета коэфф. Чебышева
// Линейная апроксамация ортогональными функциями
FLYCHEBYSHOV_API void ComputeChebyshevFactor(double* time, double* ism, int n, 
							int Degree, int reg, long double* b, long double* g, 
							long double* c) ;

//------------------------------------------------------------------------------
// Функция пересчета коэфф. Чебышева в коэфф.степенного полинома
FLYCHEBYSHOV_API void ChebyshevFactorToPolinim(long double *b, long double *g, 
							long double *c,	int Degree, double *ApprKft);

//------------------------------------------------------------------------------
// Функция расчета коэфф. Чебышева и их пересчета в коэфф.степенного полинома
//		Size	- Размер массива аргументов функции и массива значений функции.
//		T		- Массив знеачений аргумента функции.
//		F		- Массив значений функции
//		Degree	- Степень полинома.
//		ApprKft	- Искомые коэффициенты полинома ApprKft[0], ApprKft[1], ... , 
//				  ApprKft[Degree]. Всего (Degree+1) штук.
FLYCHEBYSHOV_API void AproxByChebyshevPolinom(double *T, double *F, int Size, 
							 int Degree, double *ApprKft) ;

//------------------------------------------------------------------------------
// Функция расчета коэфф. Чебышева и их пересчета в коэфф.степенного полинома
// Альтернативный вариант основанный на функциях пакета SSP (#include "SSP.h")
FLYCHEBYSHOV_API void AproxMNKByChebyshevPolinom(double *T, double *F, int Size, 
							int Degree, double *ApprKft);

//------------------------------------------------------------------------------
//		Degree	- Степень полинома.
//		ApprKft	- Коэффициенты полинома ApprKft[0], ApprKft[1], ... , 
//				  ApprKft[Degree]. Всего (Degree+1) штук.
//		t		- Аргумент полинома.
// Возвращается значение полинома
//      P = ApprKft[0] + ApprKft[1]*t + ApprKft[2]*t*t + ApprKft[Degree]*t*t...t
FLYCHEBYSHOV_API double ComputeChebyshevPolinom(int Degree, double *ApprKft, double t);

//------------------------------------------------------------------------------
typedef struct cRez_Cheb
{
	cRez_Cheb(bool _bFill = false, long double _Rez = 0) {
		bFill = _bFill; Rez = _Rez;
	}
	void Clear(void) { bFill = false; Rez = 0; }

	bool bFill;
	long double Rez;
} _Rez_Cheb;

//------------------------------------------------------------------------------
typedef struct cCalc_Fj_Cheb
{
	_Rez_Cheb Mas_Rez[_MAX_STEP_APPROKS_POL + 3];
	const long double *b, *g;
	double Arg;
	//int Pow;
	void Clear(void) {
		memset(Mas_Rez, 0, sizeof(Mas_Rez));
	}
	cCalc_Fj_Cheb(double _Arg, const long double *_b, const long double *_g) : b(_b), g(_g) {
		Clear();
		Arg = _Arg;
	}
	long double FUNC_F(int Pow) {
		// "-2",т.к. коэффиценты b,c "подняты" на +2 
		// (в рекурсивной формуле есть "j-2") (Это реальная степень)
		int My_Pow = Pow - 2;
		// "-1", т.к. для реальной 0 - степени Rez_Fj_Epoch=1. 
		// => нет смысла хранить
		// int Num_Pow_Save_Rez_Fj = My_Pow - 1; 
		if (My_Pow<0) return 0.0;
		_Rez_Cheb &Rez_Cheb = Mas_Rez[My_Pow];
		//Уже рассчитано раньше и заново считать не надо
		if (Rez_Cheb.bFill == true) return Rez_Cheb.Rez;
		if (!My_Pow) {
			Rez_Cheb.bFill = true;
			Rez_Cheb.Rez = 1;
			return 1;
		}
		long double fb = 0, fg = 0;
		long double gam = 0;
		long double bet = b[My_Pow];
		long double Rez_Prev = FUNC_F((int)(Pow - 1));
		fb = Rez_Prev*(Arg + bet);
		// Для My_Pow==0, My_Pow==1 => gam = 0
		if (My_Pow>1) {
			gam = g[My_Pow];
			fg = gam*FUNC_F((int)(Pow - 2));
		}
		long double Rez = fb + fg;
		Rez_Cheb.bFill = true;
		Rez_Cheb.Rez = Rez;
		return Rez;
	}
} _Calc_Fj_Cheb;

//------------------------------------------------------------------------------
typedef struct cKoef_Cheb
{
	long double b, g, c;
	void Clear(void) { b = g = c = 0; }
	cKoef_Cheb(long double _b = 0, long double _g = 0, long double _c = 0) {
		Clear();
		b = _b;
		g = _g;
		c = _c;
	}
} _Koef_Cheb;

//------------------------------------------------------------------------------
double ChebyshevFunc(double t, int j, long double *b, long double *g);
void   BetGamForChebyshev(double *time, int n, int j,
						  long double *b, long double *g);
long double Rez_Aprox_Cheb(double Arg, int Pow, const long double *b, 
						   const long double *g, const long double *c) ;
long double Rez_Aprox_Cheb(double Arg, const vector <_Koef_Cheb> &Koef_Cheb) ;

//------------------------------------------------------------------------------
#endif Aprox_ChebH
