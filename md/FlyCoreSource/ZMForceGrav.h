//--------------------------------------------------------------------------
// ZMForceGrav.h
// �. ��������� 03.08.2018
// �������� ������ ZMForceGrav - "������ ��������������� ���� �����"
// !!!! ������ �������� ����� ���� ������������ ����������� ������������ �������� !!!! 
//--------------------------------------------------------------------------
#ifndef _ZMForceGrav_H
#define _ZMForceGrav_H

#include <FlyCoreSource\\ZMForceOceanTide.h>
#include <FlyCoreSource\\ZFGPZLoad.h>
//------------------------------------------------------------------------
// �������� ������ ��������������� ����
//------------------------------------------------------------------------
typedef struct GRAV_FIELD {
	// ������� �������� ��� 
	long   VariantGPZ	; 
	// ������������ ������� ����������� �������������
	short  Nmax;
	// ������������ ������� �������������, ���������� � ��
	short  Nmax_BD;
	// �������������� ���������� �������������� ����
	double B0;
	// �������������� ���������� �������������� ���� � ��3.���2
	double B0km;
	// ������ ��������� ���������
	double J2;
	// �������������� ������ �������������� ����
	double AE;
	// ������ ������������� ������ ��
	double* Garm ; 
	// �����������
	GRAV_FIELD () { Garm = nullptr ; Clear(); }
	// ������� �������
	void Clear() {
		Nmax=0; 
		VariantGPZ=0;
		AE = 0.6378136; 
		B0 = 2975.5363;
		J2 = 0.0010826274; 
		//vGarm.clear();
		if (Garm) { delete[] Garm ; Garm = nullptr ; }
	}
} _GRAV_FIELD ;

//------------------------------------------------------------------------
// �������� ������ - ������ ��������������� ����
//--------------------------------------------------------------------------
class ZMForceGrav
{
public:
    GRAV_FIELD GravPole ;	// ���
    double* GarmNorm ;		// ������ ����������� ��� ���������� �������������
    bool    InDimen ;		// ������� ���������� � ���������� ����������� 
    bool    IndGarmNorm ;	// (true-������������, ���������������, ����/���)

	//------------------------------------------------------------------------
    // ������������ �����������
    HRESULT MakeFactorial();
	//------------------------------------------------------------------------
    HRESULT GeopotenzialCorrector (double dTime, double* Gri) ;
    HRESULT CalcCDnm (double dTime, int n, int m, double* CDnm, VersionTide VPriliv) ;
    HRESULT CalcCD21 (double dTime, double J2, double* CD21) ;

public:
		//------------------------------------------------------------------------
    // ������������
	ZMForceGrav();
	ZMForceGrav(long VariantGPZ);

	//------------------------------------------------------------------------
    // ����������
	~ZMForceGrav();
	//------------------------------------------------------------------------
    //������������� �������
	HRESULT Init_ZMForceGrav(long VariantGPZ, long SizeGPZ);
	//------------------------------------------------------------------------
    // ���������� ������ ���
    HRESULT Model_Grav_Pole_Center(double *Coord_Point, double *Acsel_GP);
    HRESULT Model_Grav_Pole_Normal(double *Coord_Point, double *Acsel_GP, long Var_Priliv = 0);
    HRESULT Model_Grav_Pole_Anomal(double dTime, short N, short M, long ScaleAddGarm, double *Coord_Point, double *Acsel_GP, VersionTide VPriliv = TIDENULL) ; 
	//------------------------------------------------------------------------
    // ���� ������������ �������� � ���
    HRESULT Calc_OceanTide(double Time, double *Coord_Point, short N, short M, VersionTide VPriliv, double *Acsel_GP);
	//------------------------------------------------------------------------
    // ������������ "�������� ����"
    HRESULT Make_nullptrPole(short N, short M,  long ScaleAddGarm);
	//------------------------------------------------------------------------
    // ���������� � ���������� ����������� (� �������)
    HRESULT Change_Dimen(short Param);

private:
  	double R, B0_R1, B0_R2, B0_R3, Comp_Ed_R[3], Ae_R, Log_Ae_R;
    double dParJ2, dSQRT_53, dSQRT_3;
    double *Kft_C, *Kft_D, GpzAdd[48], Darg[7];
} ;

//----------------------------------------------------------------------------
void O_Tide_GPZ (double *DARG, double *dCD, char n, char m );
void Doodson_arg(double  Time_tide, double *DARG);
void Step2_GP   (double *DARG, double *CD, int n, int m);

//----------------------------------------------------------------------------
#endif _ZMForceGrav_H
