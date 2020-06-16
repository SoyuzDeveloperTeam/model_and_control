//-------------------------------------------------------------------------------
// ZSun.h
// �. ��������� 03.08.2018
//-------------------------------------------------------------------------------
#ifndef _ZSUN_H
#define _ZSUN_H

#define Z_CALCSUN_SIMPLE

typedef struct ZSUN_POINT {
double ta ;			// ������� ����� � ���
double t0 ;			// ����� � ��������� ��������� �� ����� J2000 
double E0 ;			// ������� ������ ��������� � �������� � �������� 
double E0g ;		// ������� ������ ��������� � �������� � �������� 
double Ls, Bs ;		// ������������� ������� � ������ � ��������  
double Lsg, Bsg ;	// ������������� ������� � ������ � �������� 
double alf, dlt ;	// ������ ����������� � ��������� ����������� �� ��������� �������� � ������������� � ��������
double alfg, dltg ;	// ������ ����������� � ��������� ����������� �� ��������� �������� � ������������� � ��������
double R ;			// ���������� �� ����� �� ������
double XTES[3] ;	// ���������� ���������� � ������� �����
double X2000[3] ;	// ���������� ���������� � ����� 2000 ����
} _ZSUN_POINT ;

FLYCORE_API int  ZSunJ2000(double ta, double *Sun, TIMESCALE Scale, 
						   bool notStory = false);
FLYCORE_API int  ZSun(double ta, ZSUN_POINT& SP, TIMESCALE Scale, 
					  bool notStory = false);
FLYCORE_API void ZSunSimple(double ta, TIMESCALE Scale, double *xs, 
							short prizn);

//-------------------------------------------------------------------------------
#endif // #ifndef _ZSUN_H