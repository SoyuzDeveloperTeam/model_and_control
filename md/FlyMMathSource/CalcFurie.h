//------------------------------------------------------------------------------
#ifndef CalcFurieH
#define CalcFurieH

#ifdef FLYMMATH_EXPORTS
#define FLYMMATH_API __declspec(dllexport)
#else
#define FLYMMATH_API __declspec(dllimport)
#endif

//------------------------------------------------------------------------------
typedef struct {
double A ;
double B ;
double n ;
double fi ;
} FLYMMATH_API FurieItem;

//------------------------------------------------------------------------------
class FLYMMATH_API CFurie {
public :
    CFurie ( ) ;
    ~CFurie( ) ;

    void Clear( ) ;

    void AddPointXY( double x, double y ) ;
    int  Make      ( int N ) ;
    int  Calc      ( double X, double& F ) ;
    int  CalcDif   ( double X, double& dFdX ) ;
    int  CalcInteg ( double X, double& IF ) ;

    double GetA0( ) { return A0 ; }
    double GetA ( int i ) { return I[ i ].A ; }
    double GetB ( int i ) { return I[ i ].B ; }
    double Getn ( int i ) { return I[ i ].n ; }
    double Getfi( int i ) { return I[ i ].fi ; }

protected :
    double NormX( int i ) ;
    double NormValX( double dX ) ;

    int    N ;
    double T ;
    double A0 ;

	vector<FurieItem> I;
	vector<double>    Y;
	vector<double>    X;
} ;
//------------------------------------------------------------------------------
#endif
