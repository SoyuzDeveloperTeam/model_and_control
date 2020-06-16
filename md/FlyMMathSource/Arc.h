#ifndef   CLASS_CARC
#define   CLASS_CARC

class FLYMMATH_API CArc {
public:
	CArc (CArc&) ;
	CArc (double a=0, int radian_flag=1) ;

	int    IsRadian     () ;
	void   SetRadian    () ;
	void   SetGradus    () ;
	double ReductionDim (CArc&) ;

	CArc& operator = (CArc&) ;
	CArc& operator = (double) ;
	CArc  operator - () ;
	//  Очень важно - операторы преобразования типа CArc
	operator double() ;
	operator short () ;
	operator int   () ;

	friend CArc operator + (CArc&,   CArc&) ;
	friend CArc operator + (CArc&,   double&) ;
	friend CArc operator + (double&, CArc&) ;
	friend CArc operator - (CArc&,   CArc&) ;
	friend CArc operator - (CArc&,   double&) ;
	friend CArc operator - (double&, CArc&) ;
	friend CArc operator * (CArc&,   CArc&) ;
	friend CArc operator * (CArc&,   double&) ;
	friend CArc operator * (double&, CArc&) ;
	friend CArc operator / (CArc&,   CArc&) ;
	friend CArc operator / (CArc&,   double&) ;
	friend CArc operator / (double&, CArc&) ;

private:
	void   Interval() ;
	void   Int_PP  () ;
	void   Int_02P () ;

public:
	static double CalcSC    (double, double) ;
	static void   ValiArc2PI(double&) ;
	static void   ValiArcPI (double&) ;
	static int    QtrArc    (double ) ;
	static int    PI2_global_flag ;

private :
	double m_a ;
	int    m_rad_flag ;
} ;
//
FLYMMATH_API double Vali2PI(double u, bool FlagPI = 0);
FLYMMATH_API double ValiPI(double u, bool FlagPI = 0);
FLYMMATH_API double ARad(double);
FLYMMATH_API double AGrd(double);
//
#endif