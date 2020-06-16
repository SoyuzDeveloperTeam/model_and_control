//---------------------------------------------------------------------------
// ModSK.h
// А. Николенко 03.08.2018
//---------------------------------------------------------------------------
#ifndef MOD_SK_H
#define MOD_SK_H

#include <FlyCoreSource\\ZSK.h>
//---------------------------------------------------------------------------
//void Calc_Matr_Prec( double *Prec, double *Matr ) ;
//---------------------------------------------------------------------------
//void    ask1_ask2 ( double* ask1, double* ask2, short direct, double* pr ) ;
//void    asks_t    ( double* asks, double* askt, short direct, double* red ) ;
//short   ASK_NSSK  ( short  pr, double* ack, double* nssk, double t_st, double* X ) ;
//---------------------------------------------------------------------------
//HRESULT AB_GR (short pr, double* cina, double* cing, double* mtrAsk_Gsk = nullptr ) ;
//HRESULT AB_GR2(short pr, double* cina, double* cing, double* mtrAsk_Gsk = nullptr ) ;
//short   AB_GRZ(short pr, double* kina, double* king, double tzam ) ;
//HRESULT Convert_GSC_ASC1975( double* dGSC, double* dASC_1975, bool Flag_R ) ;
//HRESULT Convert_ASC1975_GSC( double* dASC_1975, double* dGSC, bool Flag_R ) ;
//HRESULT ASC1975_GSC( bool Flag_GSC, double *dASC_1975, double *dGSC, bool Flag_R = false, double* Out_mtAsk1975_Gsk = nullptr);
//HRESULT ASC2000_GSC( double *dASC_2000, double *dGSC, bool Flag_R = false, double* Out_mtAsk2000_Gsk = nullptr);
//HRESULT GSC_ASC2000(double *dGSC, double *dASC_2000, bool Flag_R, double* Out_mtAsk2000_Gsk) ;
//HRESULT ASCT_GSC(double *dASCT, double *dGSC, bool Flag_R, double* Out_mtAskT_Gsk) ;
//HRESULT GSC_ASCT(double *dGSC, double *dASCT, bool Flag_R, double* Out_mtAskT_Gsk) ;

//void    GR_HBL(short pr, short oze, short need_nk, double* gk, double* hbl, double* nk, double* ellipse ) ;
FLYCORE_API int		Convert_PZ90_ITRF(double* Cin_PZ90, double* Cin_ITRF, bool Flag_ITRF);
FLYCORE_API void    GR_KRAS(short pr, double* gr, double *kras, double* dr, double* om);
FLYCORE_API void    GSK_HBLKR(short pr, double* gsk, double *hbl);
//---------------------------------------------------------------------------
//void    Convert_ASC_E1_ASC_E2  ( double *AskT1, double *AskT2, double *Preces, bool Direct, bool Speed = false ) ;
//HRESULT Convert_ASC_E1_ASC_E2  ( double dTimeE1, double *dASC_E1, double dTimeE2, double *dASC_E2, bool Speed = false ) ;
//---------------------------------------------------------------------------

#endif // #ifndef MOD_SK_H