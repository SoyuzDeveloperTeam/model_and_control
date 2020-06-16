#ifndef _CModAstro_H
#define _CModAstro_H
//------------------------------------------------------------------------
#define _MERCURY    0
#define _VENUS      1
#define _BARYCENTER 2
#define _MARS       3
#define _JUPITER    4
#define _SATURN     5
#define _URANUS     6
#define _NEPTUNE    7
#define _PLUTO      8
#define _MOON       9
#define _SUN       10

#include <fcntl.h>

//------------------------------------------------------------------------
// ��������� ���� �����������
//------------------------------------------------------------------------
typedef struct ASTRO_DATA
{
	int    Num_AD  = 0;		// ����� �����������
	string Name_AD = 0;		// �������� �����������
	string Note_AD = 0;		// ����������
	int BegDATE_AD = 0;		// ����� ������ � ����� ����� �����������
	int EndDATE_AD = 0;
	// �����������
	ASTRO_DATA() { Clear(); }
	// ������� �������
	void Clear() { 
		Num_AD=BegDATE_AD=EndDATE_AD=0; Name_AD.erase(); Note_AD.erase();
	}
} _ASTRO_DATA;

//------------------------------------------------------------------------
// ������� ���� ���������������� ����������
//------------------------------------------------------------------------
typedef struct POLE_AE
{
  // ���������������� ������ ��������� ��������
  double  dop[14];
  // ������� �������, �� ������� �������� ��������� ��, ��� ���������� ���������
  double    t[14];
  // ������� ����������������� ���������� ��
  double   qso[3],        //  0. ����������  ������
           qlu[3],        //  1.             ����
           qup[3],        //  2.             �������
           qsa[3],        //  3.             �������
           qur[3],        //  4.             �����
           qwe[3],        //  5.             ������   ��� 1975.0
           qma[3],        //  6.             �����
           qne[3],        //  7.             �������
           qme[3],        //  8.             ��������
           qpl[3],        //  9.             �������
           qpr[3],        // 10. ������������ ������� ���������
           pvz[3],        // 11. ��������� �������� �����(Ut,x,y), Ut=UT1-TAI
           qnu[3],        // 12. �������.������� ������� (e0,Nf,Ne)
           qze[3],        // 13. ����������  �����
           qre[2];        // 14. ������������ �������� G,g
  double   *b[14];        // ������ ������� ���������� �� ����������
                          // ����� EMU_MALLOC ���� �����������
                          // �������� ��  (�� �������� ���-�� �����)
  char  metod[14];        // �����, �� �������� ��������
                          // ����������������� ��������� :
                          //  metod[i]=0 - i-� �������� �� ���������� ��
                          //           1 - i-� �������� �� �������������� ��
  // �����������
  POLE_AE() { Clear(); }
  // ������� �������
  void Clear() { memset(this,0,sizeof(*this));
  }
} _POLE_AE;

//------------------------------------------------------------------------
// ���� ���������������� �� ��� ��
//------------------------------------------------------------------------
#define    BTS_EARTH     0  // ������ ���������������� ��
#define    BTS_SS        1  // ��������� ���������������� ��
//-----------------------------------------------------------------------
struct DE405
   {
      double password;          // ����������� �����
      double jd_begin;          // ���� ������ ���������� �� 1.01.2000
      double jd_end;            // ���� ����� ����������  �� 1.01.2000
      short  num_block;         // ���-�� ������
      short  interval;          // ��������, ����������� ������
      short  size_block;        // ������ ����� (���-�� �������������� �����)
      short  structur[13][3];   // ��������� �����
      // ������ ������ ������ �������� ������ (���. ���������� ����. �������):
      // 0 - ��������, 1 - ������, 2 - ��������� �-�, 3 - ����,
      // 4 - ������, 5 - ������, 6 - ����, 7 - ������, 8 - ������,
      // 9 - ���� ���. ���������� �-�, 10 - ������, 11 - �������, 12 - ��������
      // ��� �������� 0-10 �� 3 ������� (�,Y,Z), ��� 11-12 - �� 2 �������
      // ������ ������ ��������:
      // 0 - �������� � �����
      // 1 - ������� ���������� (������� �������� +1)
      // 2 - ���������� ��������� �� ���������
      //     ��������:
      // structur[3][0]=179 ��������, ��� ������ ����������� ���������
      // ��� ������������� ��������� ����� ����� 179 �����
    };
//-----------------------------------------------------------------------
enum AstroObject { Moon = 0, Sun = 1, Mercury = 2, Venus = 3, Mars = 4,
                   Jove = 5, Saturn = 6, Uranus = 7, Neptune = 8, Pluto = 9,
                   //Nutation = 10, Libration = 11, STime = 12, Precess = 13}
                   Nutation = 10, Libration = 11, STime = 13, Precess = 14,
                   Earth = 12};
// ���� ������
// �������� ������ ���� ������ ������ ���� ������ ������
// ������� �������� ��������� �������� �����
//    ��� ���������� ����� �������� �������� ������������� ��������
//const MaxAstroObjectNum = 14; // 13+1(�������)
const int MaxAstroObjectNum = 15; // 14+1(�������)
//-----------------------------------------------------------------------
// ��������� ���������� �����������
typedef struct LastCalc
{
	double        dTA;                // �����
	long          NumSysCoord;        // ����� ���������???
	double        Params[3];          // ��������
	LastCalc() { Clear(); }
	void Clear() {
	    memset(this,0,sizeof(*this));
		dTA = - 1.e10;
		NumSysCoord = -1;
	}
} _LastCalc;
//-----------------------------------------------------------------------
class FLYCORE_API CModAstro
{
private:
  // ������ ������ ������ �������� ������ (���. ���������� ����. �������):
  // 0 - ��������, 1 - ������, 2 - ��������� �-�, 3 - ����,
  // 4 - ������, 5 - ������, 6 - ����, 7 - ������, 8 - ������,
  // 9 - ���� ���. ���������� �-�, 10 - ������, 11 - �������, 12 - ��������
  // ��� �������� 0-10 �� 3 ������� (�,Y,Z), ��� 11-12 - �� 2 �������
  int      Epoc;          // ����� : 0 - 2000 �.
                          //         1 - 1975 �.
  int      RazmD;         // ����������� 0 - ����
                          //             1 - ��
                          //             2 - �
  int      RazmU;         // ����������� 0 - ���
                          //             1 - ����
                          //             2 - ���
  int      TimeSh;        // �����  0 - ���������
                          //        1 - ����������
  double   EpsilonNoCalc; // �������� ������� ��� ������������ ������� ������ �������������
                          // �� �����, � ����� �������� �������
  int      ModeBTS;       // ����� ������� 0 - ��������� �,   1 - �� ��
						  // ������ ��������� ������������ ��������!
  _LastCalc  LastCalcMass[MaxAstroObjectNum];      
						  // ������� ��������
  void __fastcall AsOutMode(double * massiv);              

public:
  int     NumADC;		// ����� ���������� ��� �������������� �������������!
  string  Note;			// �����������

  CModAstro(void);
  CModAstro(int mode);	// ����������� � ���������� ������ ����������
 ~CModAstro(void);
  // ������� ������� �� ���������
  HRESULT Calc_Precesion(double dTA, AstroObject NumTypeData, double *dResult);
  // ������� ������� � ��������� ����������� ��������� ����
  HRESULT Calc_AstroData(const double dTA, AstroObject NumTypeData, long NumSysCoord, double *dResult);
  /* dTA � ��� �� 01.01.1975 �.   rezult - 3 ��������� */
  /*      NumSysCoord   -1 �� ������������       */
  // ������� ������� ��������� �������
  HRESULT Calc_AstroData_Startime(double dTA, double *dResult);
  // ������� ������� ���������
  HRESULT Calc_AstroData_precess(double dTA, double *dResult);
  short AstroSetFromFile(double *Begin_from2000, double *Interval, char *PathStruct, char *PathFile);
  void AstroRazmSet(int Epockha, int RazmerD, int TimeShkala);
  void AstroRazmGet(int *Epockha, int *RazmerD, int *TimeShkala);
  void AstroRazmSet(int Epockha, int RazmerD, int RazmerU, int TimeShkala);
  void AstroRazmGet(int *Epockha, int *RazmerD, int *RazmerU, int *TimeShkala);
};
//------------------------------------------------------------------------------
//void    preces_IERS(double Tau,double tau,double *u) ;
FLYCORE_API void    CalcNutation(double JD2000, double *x);
FLYCORE_API void    NutationSmooth(double JD2000, double *x);
FLYCORE_API double  SR_E0(double Tae, bool FlagTDT = true);
FLYCORE_API double  sr_E0_IERS(double tau2000);
//void  Calc_Prec_Par(double dIAT_E1, double dIAT_E2, double *dPreces);
//void  Calc_Matr_Prec(double *dPrec, double *dMatrPrec);
//long  Calc_Dif_Matr_Prec(double dIAT_E1, double dIAT_E2, double *dPrec, double *AMatr, double *DMatr = nullptr);
//------------------------------------------------------------------------------
FLYCORE_API long    Calc_Nuta_Par(double dIAT, double *dNutPar);
FLYCORE_API void    Calc_Matr_Nuta(double *dNuta, double *dMatrNuta);
FLYCORE_API long    Calc_Dif_Matr_Nuta(double dIAT, double *dNuta, double *AMatr, double *DMatr = nullptr);
//------------------------------------------------------------------------------
FLYCORE_API long    Calc_StarTime(double dIAT, double *StarTime);
//double  Calc_AverageStarTime(double UT2000);
FLYCORE_API short   FZW(double t, double *zw);
//long    Precess_J2000(double dIAT_D1975, double *u);
//void	preces(double Tau, double tau, double *Precess);
//void	Calc_Matr_Preces_B1975_J2000( double *Matr_B1975_J2000 ) ;
FLYCORE_API long    Calc_Matr_StarTime(double dStarTime, double *AMatr, double *DMatr = nullptr);
//------------------------------------------------------------------------------
FLYCORE_API long    Calc_Matr_PVZ(double dIAT, double *dPVZ, double *AMatr, double *DMatr = nullptr);
FLYCORE_API long    Calc_Matr_PVZ(double *dPVZ, double *AMatr, double *DMatr = nullptr);
//------------------------------------------------------------------------------
//long    Precess_J2000(double dIAT_D1975, double *u);
//------------------------------------------------------------------------------
FLYCORE_API short  AEJG(double t, short N, short mode = 0);
FLYCORE_API short  ANAL_AE(double Tae, short N);
//void   PRECES(double Tae);
FLYCORE_API short  Model_PVZ(double Time_PVZ, double *Xp, double *Yp, double *UT);
//---------------------------------------------------------------------------
FLYCORE_API void fargTIME(double t, double *u, char FlagCalc = 0);
//---------------------------------------------------------------------------
FLYCORE_API int _CalcAstroKoord(double t, int NP);

#endif _CModAstro_H

