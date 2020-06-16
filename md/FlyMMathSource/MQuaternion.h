#ifndef MQuaternion_H
#define MQuaternion_H

FLYMMATH_API int QuaternionToMatrix(double W, double X, double Y, double Z, double* M, bool dim4);
FLYMMATH_API int QuaternionToMatrix33(double W, double X, double Y, double Z, double* M);
FLYMMATH_API int QuaternionToMatrix44(double W, double X, double Y, double Z, double* M);

#endif //#define MQuaternion_H
 