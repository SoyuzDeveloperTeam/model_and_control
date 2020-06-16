//---------------------------------------------------------------------------
// ZCalc.h
// �. ��������� 03.08.2018
// ��������� �������������� ��������� ������� ����������
//---------------------------------------------------------------------------
#ifndef _Z_CALC_H
#define _Z_CALC_H

// ����������� ������� �������
enum DIMANGL {DimAnglRad=0, DimAnglGrad=1, DimAnglSSS=2, DimAnglH=3, DimAnglMin=4, DimAnglSec=5} ;

//------------------------------------------------------------------------------
// �������������� ������� �������� � ���� ����������� (����������� ������������ ����� DIMANGL)
//		a         - ������� �������� � �������� ����������� fromdim
//		��������� - ������� � ��������� ����������� todim 
FLYCORE_API double AngleDimConv(double a, DIMANGL fromdim, DIMANGL todim);

//------------------------------------------------------------------------------
// ������������������� ������� ��������
// ���� ������� � ��� ��� ������ � ��������� �������� � �����������,
// ������� ����� ����������� ��� ���������� �������������� ��������
// � ���������� ��������� ����.
// ���� ����������� ���������� � ������������� ���������� "+", "-", "*", "/",
// � ����� � ��������� ����������
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
// ���������� �������� �������� ���������� ������� tmss 
// �� ������� L �� �������� AtomicTime, ������������ �� J1975 
//		AtomicTime - ������� ����� �� ����� J1975
//		L          - ������������ ������� � ��������
//		tmss       - ������� ������� ��������� �����
//		dim        - ����������� tmis:
//		             0 - � ��������
//                   1 - � ��������
//                   2 - � ���
//                   3 - � �����
//------------------------------------------------------------------------------
FLYCORE_API int ZCalcMSSV(double AtomicTime, double L, double& tmss, DIMANGL dim = DimAnglSSS);
//------------------------------------------------------------------------------
// ���������� �������� ��������� ���������� ������� tmss 
// �� ������� L �� �������� ta, ������������ �� J1975 
//		AtomicTime - ������� ����� �� ����� J1975
//		L          - ������������ ������� � ��������
//		tmis       - ������� �������� ��������� �����
//		dim        - ����������� tmis:
//		             0 - � ��������
//                   1 - � ��������
//                   2 - � ���
//                   3 - � �����
//------------------------------------------------------------------------------
FLYCORE_API int ZCalcMISV(double AtomicTime, double L, double& tmis, DIMANGL dim = DimAnglRad);
//---------------------------------------------------------------------------
//    ������ ������ ������� ��� ��� (��� �� ���� fromEK=true) 
//    � ����������� �� �������.
//---------------------------------------------------------------------------
//   ��������: void ZHightDif (double *w, double *hht);
//   ������� ���������:
//         w - ���������� � ��� (x,y,z,Vx,Vy,Vz).
//   �������� ���������:
//         hht[0] - ������ ��� ���,
//         hht[1] - ������,
//         hht[2] - ����������� ������ �� �������,
//         hht[3] - ����������� ������� �� �������.
//   ������������ ��������: ���.
//---------------------------------------------------------------------------
FLYCORE_API void ZCalcHightDif(double *Xgsc, double *ht, bool fromEK = false);

//---------------------------------------------------------------------------
#endif // #ifndef _Z_CALC_H