// ZCPrintFormat.h
//
// А. Николенко 03.08.2018
// Форматирование результатов прогноза
//------------------------------------------------------------------------------- 
#ifndef PrintMSCF_H
#define PrintMSCF_H

#include <FlyFormat.h>

class ZCPrintManager ;

//------------------------------------------------------------------------------- 
class FLYCORE_API ZCPrintFormat {
public:
	bool FirstLine;

	int vardimarg;
	int vardimBLF;
	int vardimTdr;
	int vardimR;
	int vardimV;

	int ApeakWidth;

	int decM;
	int decR;
	int decV;
	int decTdrSec;
	int decTdrMin;
	int decSec;
	int decMin;
	int decSSS;
	int decGrad;
	int decRad;
	int decASec;
	int decAkm;
	int decE;
	int decHkm;
	int decRkm;
	int decVkm;
	int decRm;
	int decVm;

	int lenKA;
	int lenM;
	int lenVit;
	int lenKR;
	int lenDate;
	int lenTimeHMS;
	int lenTdrSec;
	int lenTdrMin;
	int lenGrad;
	int lenRad;
	int lenGMS;
	int lenAkm;
	int lenE;
	int lenHkm;
	int lenRkm;
	int lenVkm;
	int lenRm;
	int lenVm;

	CFormatString FDataTime;
	CFormatString Ftmss;
	CFormatString FArc;
	CFormatString FArcBL;
	CFormatString FTdr;

public:
	ZCPrintFormat() ;
	~ZCPrintFormat() {}

	void Formated() ;
	void FirstLineOn () { FirstLine = true ; }
	void FirstLineOff() { FirstLine = false ; }
	bool IsFirstLine () { return FirstLine ; }

	void PrintM   (ZCPrintManager* PrintMng, FILE* fp, char* S, double m) ;
	void PrintTdr (ZCPrintManager* PrintMng, FILE* fp, char* S, double T);
	void PrintGrad(ZCPrintManager* PrintMng, FILE* fp, char* S, double a);
	void PrintBLF (ZCPrintManager* PrintMng, FILE* fp, char* S, double a);
	void PrintDateTime(ZCPrintManager* PrintMng, FILE* fp, char* S, double ta, char Key);
	void PrintKA  (ZCPrintManager* PrintMng, FILE* fp, char* S, int KA);
	void PrintVit (ZCPrintManager* PrintMng, FILE* fp, char* S, int Vit);
	void PrintKR  (ZCPrintManager* PrintMng, FILE* fp, char* S, int KR);
	void PrintMSSV(ZCPrintManager* PrintMng, FILE* fp, char* S, double t);
	void PrintHkm (ZCPrintManager* PrintMng, FILE* fp, char* S, double h);
	void PrintRkm (ZCPrintManager* PrintMng, FILE* fp, char* S, double R);
	void PrintAkm (ZCPrintManager* PrintMng, FILE* fp, char* S, double a);
	void PrintE   (ZCPrintManager* PrintMng, FILE* fp, char* S, double e);
	void PrintR   (ZCPrintManager* PrintMng, FILE* fp, char* S, double R);
	void PrintV   (ZCPrintManager* PrintMng, FILE* fp, char* S, double R);

	void PrintLineAflet(FILE* fp, int Len) ;
	int  CalcLineLenght(ZCPrintManager* PrintMng) ;
	int  CalcItemLenght(ZCPrintManager* PrintMng, int ParamIndex) ;
	int  CalcIDLenght  (ZCPrintManager* PrintMng, int ID);
	int  GetItemID     (ZCPrintManager* PrintMng, int ParamIndex) ;

	int GetItemName(ZCPrintManager* PrintMng, string& name,
					int ParamIndex, bool fromHtml=false);
	int GetItemDim (ZCPrintManager* PrintMng, string& name,
					int ParamIndex, bool fromHtml = false);

	int GetIDName  (ZCPrintManager* PrintMng, string& name,
					int ID, bool fromHtml = false);
	int GetIDDim   (ZCPrintManager* PrintMng, string& name,
					int ID, bool fromHtml = false);
} ;

//------------------------------------------------------------------------------- 
#endif // #ifndef PrintMSCF_H
