//---------------------------------------------------------------------------
// ZMForceOceanTide.h
// А. Николенко 03.08.2018
// Функция расчета вариаций коэффициентов GPZ за счет океанических приливов
//---------------------------------------------------------------------------

#ifndef MOD_FORCE_OCEAN_TIDE
#define MOD_FORCE_OCEAN_TIDE

//---------------------------------------------------------------------------
struct LEGENDRE
{
    int    n,m;       // степень и порядок
    double cst;       // аргумент
    double snt;       // доп. аргумент
    double fval;      // значение функции (m,m)
    double bval;      // значение функции (n-1,m)
    double val;       // значение функции (n,m)
};

struct SOLID_TIDE
{
    struct LEGENDRE l;
    double lon;
    double r0[3];
};

struct MAIN_MRD
{
    double r [4];    // орт по радиус-вектору
    double i1[4];    // орт по каппе1
    double x2[3];    // орт по направлению 2
    double x3[3];    // орт по направлению 3
    double v [4];    // орт по скорости
    double Th;       // СОЗ
    double csTh;     // косинус СОЗ
    double snTh;     //
    double IS;       // склонение Солнца к плоскости орбиты
    double csIS;     // косинус
    double snIS;     // синус
    double csG;      // косинус видимого углового радиуса Земли
    double snG;
    double Tf;       // значение теневой функции
    double S;        // направление движения объекта 1-движение КА к Солнцу, -1 - от Солнца
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
// функции расчета возмущающих ускорений
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
