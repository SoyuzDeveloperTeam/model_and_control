//---------------------------------------------------------------------------
// ZMForceOceanTide.h
// �. ��������� 03.08.2018
// ������� ������� �������� ������������� GPZ �� ���� ������������ ��������
//---------------------------------------------------------------------------

#ifndef MOD_FORCE_OCEAN_TIDE
#define MOD_FORCE_OCEAN_TIDE

//---------------------------------------------------------------------------
struct LEGENDRE
{
    int    n,m;       // ������� � �������
    double cst;       // ��������
    double snt;       // ���. ��������
    double fval;      // �������� ������� (m,m)
    double bval;      // �������� ������� (n-1,m)
    double val;       // �������� ������� (n,m)
};

struct SOLID_TIDE
{
    struct LEGENDRE l;
    double lon;
    double r0[3];
};

struct MAIN_MRD
{
    double r [4];    // ��� �� ������-�������
    double i1[4];    // ��� �� �����1
    double x2[3];    // ��� �� ����������� 2
    double x3[3];    // ��� �� ����������� 3
    double v [4];    // ��� �� ��������
    double Th;       // ���
    double csTh;     // ������� ���
    double snTh;     //
    double IS;       // ��������� ������ � ��������� ������
    double csIS;     // �������
    double snIS;     // �����
    double csG;      // ������� �������� �������� ������� �����
    double snG;
    double Tf;       // �������� ������� �������
    double S;        // ����������� �������� ������� 1-�������� �� � ������, -1 - �� ������
    double arg;
};

//---------------------------------------------------------------------------
#endif // #ifndef MOD_FORCE_OCEAN_TIDE

//---------------------------------------------------------------------------
void         gpzC20  (double r, double* Gri, double* Usk, struct _GPZ* gpt);
int          PassToTime (long ka, double t, double* Param);
int          d_lbd           (double *x, double *y, unsigned opt);
void         abs_lbd         (double *x, double *y);
int          InitModel       (void);
int          Step            (void);
int          Determine       (int Direct);
double       GetB0           (void);
struct _GPZ* GetGPZ          (void);
int          ControlIntPar   (void);
void         StepControl     (double Tf);
int          InitModelField  (void);

//---------------------------------------------------------------------------
// ������� ������� ����������� ���������
void         gpz         (double r, double* Gri, double* Usk, struct _GPZ* gpt);
int          GravPlanet  (double* Ask, double *Usk);
int          svd_kappa   (double *Ask, double *Usk);
int          svd_mrd3    (double *Ask, double *Usk);
int          ManagerMRD_ (double* Ask, struct MAIN_MRD* Ptr);
int          RelativDisterbance (double* Ask, double r, double* Usk);

//---------------------------------------------------------------------------
double       sh         (double d, double r, int Planet);
void         _j_ikr     (double, struct MAIN_MRD* F, double*);
void         _j_refl    (struct MAIN_MRD* F, double *j);
void         LegendreInit    (struct LEGENDRE* Leg, double value);
void         LegendreNextRow (struct LEGENDRE* Leg);
void         LegendreNext    (struct LEGENDRE* Leg);

//---------------------------------------------------------------------------
