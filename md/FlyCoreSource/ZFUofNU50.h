//---------------------------------------------------------------------------
// ZFUofNU50.h
// А. Николенко 15.03.2019
//---------------------------------------------------------------------------
#ifndef _Z_UOF_NU50_H
#define _Z_UOF_NU50_H

FLYCORE_API int LoadNU50(char* FileName, FILE* pf, char* Text, ZNU& NU, bool PrintToCout = false);
FLYCORE_API int SaveNU50(ZNU& NU, ZLSF* lhs, char* FileName, FILE* pf = nullptr, char* Text = nullptr);

//---------------------------------------------------------------------------

#endif // #ifndef _Z_UOF_NU50_H