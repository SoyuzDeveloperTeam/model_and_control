//---------------------------------------------------------------------------


#pragma hdrstop

#include "setlangmodule.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

AnsiString __fastcall GetWVersion()
{
  AnsiString temp;
  VS_FIXEDFILEINFO VerValue;
  DWORD size, n;
  n = GetFileVersionInfoSize(Application->ExeName.c_str(), &size);
  if (n > 0)
  {
    char *pBuf = new char[n];
    GetFileVersionInfo(Application->ExeName.c_str(), 0, n, pBuf);
    LPVOID pValue;
    UINT Len;
    if (VerQueryValue(pBuf, "\\", &pValue, &Len))
    {
      memmove(&VerValue, pValue, Len);
      temp = IntToStr(VerValue.dwProductVersionMS >> 16);
      temp += "." + IntToStr(VerValue.dwProductVersionMS & 0xFFFF);
      temp += "." + IntToStr(VerValue.dwProductVersionLS >> 16);
      temp += "." + IntToStr(VerValue.dwProductVersionLS & 0xFF);
    }
    delete pBuf;
  }
  return temp;
}

void SetLang(int lang_num){

}
