//-------------------------------------------------------------------------------
// ZCIntegrator.h
// �. ��������� 03.08.2018
//-------------------------------------------------------------------------------
#ifndef CLASS_ZINTEGRATOR_H
#define CLASS_ZINTEGRATOR_H

//-------------------------------------------------------------------------------
#include <FlyCoreSource\\ZCMemoryKeeper.h>
#include <FlyCoreSource\\ZCExternalEquations.h>

//-------------------------------------------------------------------------------
#define  ID_AILER    1
#define  ID_RUNGE_4  4
#define  ID_RUNGE_8  8
#define  ID_ADAMS_4  104
#define  ID_ADAMS_5  105
#define  ID_ADAMS_6  106
#define  ID_ADAMS_8  108
#define  ID_ADAMS_10 110

//-------------------------------------------------------------------------------
#define  F_RUNA_AUTOSTEP   1
#define  F_RUNA_NOTMAXSTEP 2
#define  F_RUNA_USEBREAK   4
#define  MAX_ADAMS_N	   10

//-------------------------------------------------------------------------------
struct IntegratorCreateStruct {
int    n ;				// ����� ������������� ���������
int    RungeType ;		// ������� ������ �����-�����
int    AdamsType ;		// ������� ������ ������
double step ;			// ��� �������������� ���������, ���
double step_min ;		// ��� �������������� �����������, ���
double step_max ;		// ��� �������������� ������������, ��� 
double step_eps ;		// �������� ��� ������ ���� �������������� (��) 
double fixed_step ;		// �������� �������������� ����, ���, ���� >0, �� ������ ����������� � �������������� ������ � ���������� ����� 
long   flag ;			//
void*  data ;			//
int ( *sph )        ( double*, double*, void* SphData ) ;
int ( *user_break ) ( double*, double* ) ;
int  arg_index ;		// ������ ����������� ���������� � ������� ��������� 
};

//-------------------------------------------------------------------------------
class FLYCORE_API ZCIntegrator : public ZCExternalEquations, public ZCMemoryKeeper {
public:
	ZCIntegrator(IntegratorCreateStruct* cs = nullptr);
	ZCIntegrator(ZCIntegrator&);
	~ZCIntegrator();

	// �������, ������� ���������� � ��������� ������������ ��������
    int   Create   ( IntegratorCreateStruct&, double* v = nullptr ) ;
	void  Delete   ( ) ;
    int   IsOkCreate  (void) ;

	// ������ � ������� ��������� ������� ������� ���������
	// x - [�����, X, Y, Z, Vx, Vy, Vz, m]
	virtual void  GetVector   (double* x);
	// ������ � ������� ��������� ������� ������� ���������
	// x - [X, Y, Z, Vx, Vy, Vz]
    virtual void  GetVector   (double& t, double* x, double* m=nullptr) ;
	// ������ � ������� ��������� �������������� ���������� �������������
	// ����������� ������� ��������� (������������ ���������� ������).
	virtual void  GetVectorExe(double* x);
	// ������ �������� �������� ������� ���������
	virtual int   SetVector   (double* x);
    virtual int   SetVector   (double t, double* x, double m) ;
	// ������ �������� �������������� ����������
	virtual int   SetVectorExe(double* x);

	// ���������� �������� ����������� �������������� ���
	// 1 - �����, -1 - �����
    int   GetDirect   (void) ;
	//  ������ ����������� �������������� ���
    void  SetDirect   (int) ;

	// ���������� ��������� ����������� ��������� "�����������"
	// ������ ������ �� ��������� ���� �������������� ���
    void  SetStart    (double start_step=0) ;
	// ������ ��� �������������� ��� ���������� ����.
	// ���� ������������ ����� �������������� � �������������� 
	// ������� ����, �� ������ ��� � ������������ � ������������ 
	// �������� ������� ������ ���� ����� ����������� ��� �������������.
    void  SetStep     (double) ;
	// ���������� ������� ��� ���������������, ����������� � ������������ 
	// ��� ��� ��������� ��������������� ������ ����
    void  SetStep     (double, double, double) ;
	// ������ �������������� ����� ����
	// autostep - true	- ��� ������������� ����������
	//			  false	- ��� ����������
	void  SetAutoStep (bool autostep=true);

    void  SetEpsd     (double) ;
    void  SetData     (void*) ;
    void  SetType     (int) ;
    void  SetSph      (int(*)(double*, double*, void* SphData)) ;
    void  SetUserBreak(int(*)(double*, double*)) ;

	//---------------------------------------------------------------------------
	// ��� �������� ������
    int StepAdjusted( double step, double* dq = nullptr ) ;
	// ��� ���������� �������������
    int StepSelf( double* dq = nullptr ) ;
	// �������������� �� ��������� �������� ��������� (�������)
    int GoToArg( double ) ;

	//---------------------------------------------------------------------------
	ZCIntegrator& operator = (double*);
	ZCIntegrator& operator = (ZCIntegrator&);
	// ������ � ����������� �������������� ������� (������� ��������)
	operator double* ( ) { return m_a ; }
	double& operator []( int    i ) ;
	double& operator []( short  i ) ;
	double& operator []( long   i ) ;
	double& operator []( float  i ) ;
	double& operator []( double i ) ;

public:
	// ��������� ���������� ������ ������ ���
	//		x - ������ ������� ��������� t, X, ...Vz, m � ���� ��������������
	//		    ���������� (������������ ���������� ������).
	//		y - ������ ����������� ���� ����������
	//		    y[0] = 1 !!!! ������
	//		    y[1] = Vx
	//			. . . . . . . 
	//		    y[6] = ax
	//		    y[7] = ms
	//		    y[8] = . . . ������� � ����� �������� ����������� ������� 
	//				   ����������	  
    virtual int Sph( double* x, double* y ) { if (m_cs.sph) m_cs.sph( x, y, m_cs.data ) ; return 0 ; } ;
	// ������ ���������������� callback �������, ������� � ��������� ��������� 
	// �������� �������������� ������� ���� ����� 1. 
    virtual int UserBreak( double* x, double* y ) { return ( m_cs.user_break ? m_cs.user_break( x, y ) : 0 ) ; }
	// "��������" �������������� ������� ���������.
	// NU - ������ ��������� ������� ������� ���������� ��� �������� ������� �������.
	virtual void ExternalEquationsOn (double* NU=nullptr) {
		// "��������" ������� ���������
		ZCExternalEquations::ExternalEquationsOn(NU) ;
		// �������� �� ��� ������� ��������� � ����� �������������� �������
		memcpy(&m_a[m_n], NUexe, GetExternalEquationsCount()*sizeof(double)) ;
		// �������� ������� ��������� ����� ��������������
		CountGI = 0 ;
	}
	void LockBreak  ( ) { m_IsLockBreak = 1 ; }
	void UnlockBreak( ) { m_IsLockBreak = 0 ; }

	// ����� ������������� ���������
	// ����� ��������� ������ �� �������� ����������� - 
	// � ����������� "������������� ���������� ������"
	// ���� ������������ ���������� ������ ����������� �� ������������
	// ����� ������� ������������� ���������, �� ���� 8,
	// � ��������� ������ - 8 + ����� ������� (�������������� ���������)
	int NE() { return (m_n+(IsExtEqOn()?GetExternalEquationsCount():0)) ; }
	// ����� ������� ���������.
	// ����� ��������� ������ ����� 8, �� ������� ���� �� ��� ��� ����
	// �� ��������� ���������� �����������.
	// ���������:
	//		0		- ����� (������ ����� ������ ����� 1)
	//		1, 2, 3	- ���������� ���������� X, Y, Z
	//		4, 5, 6	- �������� Vx, Vy, Vz
	//		7		- ��������� ��� �����, �� �������� �������
	//				  ������ ����� ��������� ����� ���������� �������,
	//				  �� ��������� ������� - 0.
	// ���� ������� ������������� � ������� ����������� ��������� ��
	// ��������������, �� ����� � ����� ����� ������� �� �������
	// ������������� ����������. ������ ��� ��������� ���������� ������
	// ������������ ���� �����������
	// !!!! ���� ������ ������� ������ ����� ����� 8 !!!!
	int NM() { return (m_n) ; }

	// �������������� ���������� ������� ��������������
	void Restart() { CountGI = 0 ; } ;
	bool IsRestart () { return(CountGI>0?false:true) ; } 
	bool IsStarting() { 
		if (m_cs.AdamsType>0) return(CountGI<AdmN?true:false) ; 
		else return false ; 
	} 

private:
	// ��� ����������� �������
    int   CreateRK  ( ) ;
    int   IsOkData  (IntegratorCreateStruct& ) ;
	// �������� ������������ ���� ��������������, �������� �� ������������ 
	// ������������� � ������������ ����
    void  ValiStep  (double&) ;
	// ���� ��� ����������� ������� ������ 
    void  Step1     (double*, double*) ;
	// ���� ��� ����������� ������� �����-����� 4-�� �������
    void  StepRK4   (double*, double*, double step=0, bool SkipStepSelectiom=false) ;
	// ���� ��� ����������� ������� �����-����� 8-�� �������
    void  StepRK8   (double*, double*, double step=0, bool SkipStepSelectiom=false)  ;
	// ���������� ������ ���� � ������ �����-����� 8-�� ������� � ������
	// �������������� � ���������� �����
    void  NewStepRK8(double*, double*, double*, double&, double, double&);
	// ��� ������ ������
    int  CreateAdm  ( ) ;
public:
	// ���������� ������������� ������ �������������� ��� ������ ���������
	// ������� (N)
	//		Kpredict - ������������ ����������,
	//		Kcorrect - ������������ ����������,
	// �� ��� ������������ � ������������� ���� ��� ������.
	void CalcAdamsI (int n, double* k, double& I) ;
	void CalcAdamsKf(int N, double* Kpredict, double* Kcorrect) ;
	// ���� ��� ������ ������, ���� ����������� ������ ����� ������ 8-�� �������
	// �� ����������� �� ������������� 5-��, 10-�� ��� 12-�� ������� ���.
	// ������������ ������ ������� ����������� ��� ������ ������� CalcAdamsKf
	void StepAdams  (double* dq) ;

	// ������ �����
	int SphExe( double* x, double* y ) { 
		// ������ ������ ������ �� ������ ��������
		int rc = Sph(x, y) ; if (rc) return rc ; 	
		//-----------------------------------------------------------------------
		// ������ �� �������������� "����������������" ��
		if (!rc && IsExtEqOn()) {
			Xexe = &x[m_n] ; Yexe = &y[m_n] ;
			// ���������� �������������� "�������" ���������������� ���������
			// ���� � ������ ����������� �� ������ �������� ����������� ������ �������
			// �� ��� ����� �������, ��� ���� ����������� �������� ������ ������ "�������" �� 
			rc = ExternalSph(x[0], &x[1], Xexe, Yexe) ; if (rc) return rc ; 	
			// ���������� ������������� "�������" ����������� ��������
			// ���� � ������ ����������� �� ������ �������� ����������� ������ �������
			// �� ��� ����� �������, ��� ���� ����������� ����� "�������" ����������� �������� 
			// ��������������� �������� � ����������� ���������� �������� ����������� (+=)
			// � ������ y.
			int N = NE() ;
			rc = ExternalForces(x[0], &x[1], &y[1], N-1) ; if (rc) return rc ; 	 
		} else { Xexe = Yexe = nullptr ; } 
		return rc ;   
	}   

public:
    IntegratorCreateStruct m_cs ;
	int      m_n ;			// ����� ������������� ���������
	int      m_N ;			// ����� ������������� ��������� ������ � ���������������
	double*  m_a ;			// ������������� ������ 
    double   m_step ;		// ������� ��� ��������������	 
    int      m_ok_nu ;		//
	int      m_IsLockBreak ;//
    double   m_up ;			//

private:
	// ������� � ���������� ������ ��
    double   m_eps  ;	// ��������� �������� ��� ��������������� ������
    double   m_eps2 ;	// ���� � ������ ��8
    double*  m_x ;		// ������������� ������� ��� ��
    double** m_d ;		// ������������� �� ��� ��
    int      m_ns ;		// ������ ������ m_d ��� ������������� ������ ����� � ����������� �������

	// ������� � ���������� ������ ������
	double AdmStep ;	// ������� ��� ������ ������
	double AdmStepMax ;	// ������������ ��� ������ ������	
	double AdmStepMin ;	// ����������� ��� ������ ������ - �� �� ��� �������
	double AdmEps1 ;	// ���������� �������� ��� �������� ������� �� �������� ��� ������� ����  
	double AdmEps2 ;
	int    AdmN ;		// ������������ ����� � ������ ������
	int	   CountGI ;	// ����������� ������������ �� - ����� ��������������

	double  Kpredict[MAX_ADAMS_N] ;	// ������������ ����������  
	double  Kcorrect[MAX_ADAMS_N] ;	// ������������ ����������

protected: 
	bool    m_IsWasStepCutDown ;
	double* GI[2*MAX_ADAMS_N+1] ;	// ������ ��������������
} ;

//-------------------------------------------------------------------------------
#endif
