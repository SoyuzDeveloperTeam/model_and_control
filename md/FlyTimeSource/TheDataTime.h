//-----------------------------------------------------------------------
// TheDataTime.h
// �. ��������� 03.08.2018
//
// ��������� ����, �����, ����-�����. ����������� ����������� ���� � �����
//-----------------------------------------------------------------------
#ifndef DATATIME_H
#define DATATIME_H

#include <time.h>
#include <math.h>
#include <iostream>
#include <fstream>

//-----------------------------------------------------------------------
// ��������� ��� ������������� ����
//-----------------------------------------------------------------------
struct FLYTIME_API DATE
{
	int  d ;        // ����� (1 - 31)
	int  m ;        // ����� (1 - 12)
	int  g ;        // ���   (1900 - 9999)
	DATE (int D, int M, int G) { d=D; m=M; g=G; }
	DATE () { Clear(); }
	void Clear() { d = m = g = 0; }
};

//-----------------------------------------------------------------------
inline bool operator < (const DATE& d1, const DATE& d2)
{
	return (d1.g<d2.g || (d1.g==d2.g && (d1.m<d2.m || 
	(d1.m==d2.m && d1.d<d2.d))));
}

//-----------------------------------------------------------------------
// ��������� ��� ������������� �������
//-----------------------------------------------------------------------
struct FLYTIME_API TIME {
	short  h;       // ����         (0 - 23)
	short  m;       // ������       (0 - 59)
	short  s;       // �������      (0 - 59)
	double d;       // ���� ������� (  < 1 )
	TIME (short H, short M, short S, double D) { h=H; m=M; s=S; d=D; }
	TIME () { Clear(); }
	void Clear() { h = m = s = 0; d = 0.; }
};

//-----------------------------------------------------------------------
inline bool operator < (const TIME& t1, const TIME& t2)
{
	return (t1.h<t2.h || (t1.h==t2.h && (t1.m<t2.m || 
	(t1.m==t2.m && (t1.s+t1.d)<(t2.s+t2.d)))));
}

//-----------------------------------------------------------------------
class DATETIME ;
//FLYTIME_API void operator << (double& t, DATETIME& DT);
//FLYTIME_API void operator << (DATETIME& DT, double& t);
FLYTIME_API void operator << (DATE& D, DATETIME& DT);
FLYTIME_API void operator << (DATETIME& DT, DATE& D);
FLYTIME_API void operator << (TIME& T, DATETIME& DT);
FLYTIME_API void operator << (DATETIME& DT, TIME& T);
//FLYTIME_API void operator >> (double& t, DATETIME& DT);
//FLYTIME_API void operator >> (DATETIME& DT, double& t);
FLYTIME_API void operator >> (DATE& D, DATETIME& DT);
FLYTIME_API void operator >> (DATETIME& DT, DATE& D);
FLYTIME_API void operator >> (TIME& T, DATETIME& DT);
FLYTIME_API void operator >> (DATETIME& DMB, TIME& T);

class DATETIMEDMB ;
FLYTIME_API void operator << (double& t, DATETIMEDMB& DMB);
FLYTIME_API void operator << (DATETIMEDMB& DMB, double& t);
FLYTIME_API void operator << (DATE& D, DATETIMEDMB& DMB);
FLYTIME_API void operator << (DATETIMEDMB& DMB, DATE& D);
FLYTIME_API void operator << (TIME& T, DATETIMEDMB& DMB);
FLYTIME_API void operator << (DATETIMEDMB& DMB, TIME& T);

FLYTIME_API void operator >> (double& t, DATETIMEDMB& DMB);
FLYTIME_API void operator >> (DATETIMEDMB& DMB, double& t);
FLYTIME_API void operator >> (DATE& D, DATETIMEDMB& DMB);
FLYTIME_API void operator >> (DATETIMEDMB& DMB, DATE& D);
FLYTIME_API void operator >> (TIME& T, DATETIMEDMB& DMB);
FLYTIME_API void operator >> (DATETIMEDMB& DMB, TIME& T);

class DATETIMEUTC ;
FLYTIME_API void operator << (DATETIMEUTC& UTC, double& t);
FLYTIME_API void operator << (double& t, DATETIMEUTC& UTC);
FLYTIME_API void operator << (DATETIMEUTC& UTC, DATE& D);
FLYTIME_API void operator << (DATE& D, DATETIMEUTC& UTC);
FLYTIME_API void operator << (DATETIMEUTC& UTC, TIME& T);
FLYTIME_API void operator << (TIME& T, DATETIMEUTC& UTC);

FLYTIME_API void operator >> (double& t, DATETIMEUTC& UTC);
FLYTIME_API void operator >> (DATETIMEUTC& UTC, double& t);
FLYTIME_API void operator >> (DATE& D, DATETIMEUTC& UTC);
FLYTIME_API void operator >> (DATETIMEUTC& UTC, DATE& D);
FLYTIME_API void operator >> (TIME& T, DATETIMEUTC& UTC);
FLYTIME_API void operator >> (DATETIMEUTC& UTC, TIME& T);

FLYTIME_API ostream& operator << (ostream& out, DATETIMEUTC& D);
FLYTIME_API ostream& operator << (ostream& out, DATETIMEDMB& D);

FLYTIME_API ostream& operator << (ostream& out, DATE& D);
FLYTIME_API ostream& operator << (ostream& out, TIME& T);


class FLYTIME_API DATETIME
{
public :
	int    D; // ����� (1 - 31)
	int    M; // ����� (1 - 12)
	int    G; // ���   (1900 - 9999)
	int    h; // ����         (0 - 23)
	int    m; // ������       (0 - 59)
	int    s; // �������      (0 - 59)
	double d; // ���� ������� (  < 1 )
	// ����������� ������ ����� ������� � �������� ��� ���������������
	// DATETIME, DATETIMEUTC, DATETIMEDMB � ��������� ������
	static int strdec ;

	DATETIME() { Clear(); }
	DATETIME(short _D, short _M, short _G, short _h=0, short _m=0, short _s=0, double _d=0) { 
		Set(_D, _M, _G, _h, _m, _s, _d);
	}
	void Set(short _D, short _M, short _G, short _h=0, short _m=0, short _s=0, double _d=0) {
		h = _h; m = _m; s = _s; d = _d; D = _D; M = _M; G = _G;
	}
	void Clear() { D=M=G=h=m=s=0 ; d=0.0 ; }
} ;

class FLYTIME_API DATETIMEUTC : public DATETIME
{
public :
	DATETIMEUTC() { Clear(); }
	DATETIMEUTC(short _D, short _M, short _G, short _h=0, short _m=0, short _s=0, double _d=0) : 
	DATETIME(_D, _M, _G, _h, _m, _s, _d) { } ; 
	// ��. DATETIMEDMB::FromSSS
	void FromSSS(double t, int dec=-1) {
		*this << t ;
		if (dec>=0) {
			double l = pow(10.0, dec) ; 
			double ld= floor(d*l+0.5) ;
			if (ld==l) { t+= 0.5/l/86400.0 ; *this << t ; } 
			else d = ld/l ; 
	}	}
	// ������� ����������
	void operator = (double& t) { *this<<t ; }
} ;

class FLYTIME_API DATETIMEDMB : public DATETIME
{
public :
	DATETIMEDMB() { Clear(); }
	DATETIMEDMB(short _D, short _M, short _G, short _h=0, short _m=0, short _s=0, double _d=0) : 
	DATETIME(_D, _M, _G, _h, _m, _s, _d) { } ; 
	// ������������ ����������� ���� � ������� �� ������� ��������� � ���
	// � ��������� ����� ������������ ������ ����� ������� � ������� �����
	// ������. ���� �������� dec=-1 (�� ���������), �� �������� ������� �� 
	// �����������.
	// ����� ���� ��������� ���������� ����������, � ���������� dec ������ 
	// ����� ������� � ��������, ���������� �� �� ������� (int)(...+0.5),
	// � ������� ������������� ������ ������� � (dec+1)-�� ����� �������.
	// �������������� ���������� �������� ������, �����, �����, ... ��� 
	// ���������� (� ������� �������) �� ����� �������.
	void FromSSS(double t, int dec=-1) {
		// �������������� �� ��� � ���� � �����
		*this << t ;
		// ���� ����������� ������ ����� ������� � ��������,
		// ���� ����������� �������� ������� �������
		if (dec>=0) {
			// ��������� ��� �������� ������� ����� ������ ����� �������
			// � "�����" ����� (0.56789 ==> 567.89 ��������) 
			double l = pow(10.0, dec) ; 
			// ��������� ������ ����� ������
			double ld= floor(d*l+0.5) ;
			// ���� ���������� ������������� ��������� ����� �������
			// � ���������� ���������� (1s + 0.9999999d ==> 2s + 0.0d)
			if (ld==l) { 
				t+= 0.5/l/86400.0 ; 
				*this << t ; 
			} 
			// ���� ������ ������������ �������� ������ ����� �������
			else d = ld/l ; 
	}	}
	// ������� ����������
	void operator = (double& t) { *this<<t ; }
} ;

//-----------------------------------------------------------------------
FLYTIME_API inline bool operator < (const DATETIMEDMB& d1, const DATETIMEDMB& d2);
FLYTIME_API inline bool operator < (const DATETIMEUTC& d1, const DATETIMEUTC& d2);
FLYTIME_API inline bool operator < (const DATETIME& d1, const DATETIME& d2);

FLYTIME_API inline void operator << (char* S, DATETIMEDMB& DMB);
FLYTIME_API inline void operator << (char* S, DATETIMEUTC& UTC);
FLYTIME_API inline void operator << (char* S, DATETIME& D);
FLYTIME_API inline void operator << (FILE* pf, DATETIMEDMB& DMB);
FLYTIME_API inline void operator << (FILE* pf, DATETIMEUTC& UTC);
FLYTIME_API inline void operator << (FILE* pf, DATETIME& D);
FLYTIME_API inline void operator << (ofstream& F, DATETIMEDMB& DMB);

//-----------------------------------------------------------------------
#endif // #ifndef DATATIME_H

