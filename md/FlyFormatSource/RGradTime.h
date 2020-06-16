// RGradTime.h: interface for the CRGradTime class.
//
//////////////////////////////////////////////////////////////////////
#ifndef GRADTIME_CLASS_H
#define GRADTIME_CLASS_H
//
/*
#define SCALE_MILLIS	14
#define SCALE_SECOND	2
#define SCALE_MINUTE	3
#define SCALE_HOUR		4
#define SCALE_SSS		5
#define SCALE_DEGREE	9
#define SCALE_RADIAN	10
#define SCALE_CENTURE	6
#define SCALE_DEFAULT	2 //Используется по умолчанию
*/
class FLYFORMAT_API CRGradTime {
	friend class CRMoment;
public:
	CRGradTime ( const double Value=0,	const int measure = EDF_DEFAULT ) ;
   ~CRGradTime( ) ;
    //
    operator double();
	//
	void   fromDouble(const double Value, const int measure = EDF_DEFAULT ) ;
	double toDouble  (const int measure = EDF_DEFAULT) const;
	bool   fromString(const char* stroka);
	bool   toString  ( char* stroka ) const;
	bool   SetFields (const int h=0,const int m=0,	const int s=0,const double millis=0);
	bool   GetFields (int* h,int* m,int*s,double* millis = 0 ) const;
protected:
	double m_Value;
};

#endif // #ifndef GRADTIME_CLASS_H 
