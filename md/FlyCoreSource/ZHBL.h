//---------------------------------------------------------------------------
// ZHBL.h
// А. Николенко 03.08.2018
//---------------------------------------------------------------------------
#ifndef _Z_HBL_H
#define _Z_HBL_H

//---------------------------------------------------------------------------
FLYCORE_API void ZGRtoHBL(double* gk, double* hbl, short pr = 0, short oze = 0, double* nk = nullptr, double* ellipse = nullptr);
FLYCORE_API void ZGSCtoHBLKR(double *gsk, double *hbl, short pr = 0);

//-------------------------------------------------------------------------------
#endif // #ifndef _Z_HBL_H