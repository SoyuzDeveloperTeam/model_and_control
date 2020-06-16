//-----------------------------------------------------------------------------
// ZCPrintManager.h
// А. Николенко 03.08.2018
// Документирование результатов прогноза
//----------------------------------------------------------------------------- 
#ifndef PrintMSC_H
#define PrintMSC_H

#include <FlyHtmlWriter.h>	// Для документирования в формате Html

#include <FlyCoreSource\\ZMSpaceCraft.h>
#include <FlyCoreSource\\ZCPrintFormat.h>

//----------------------------------------------------------------------------- 
#define MODPR_KA			999
#define MODPR_M				1008
#define MODPRDATE			1
#define MODPRTIME			2
#define MODPRDATETIME		1001
#define MODPR_VIT			3			
#define MODPR_MSSV			4
#define MODPR_Tosk			5			
#define MODPR_H				6
#define MODPR_B				7
#define MODPR_L				8									
#define MODPR_R				9									
#define MODPR_Aosk			10
#define MODPR_eosk			11
#define MODPR_exosk			12
#define MODPR_eyosk			13
						
#define MODPR_V_Tdr			14	
#define MODPR_V_Hsr			15
	
#define MODPR_V_Hmin		16	
#define MODPR_V_HminU		17	
#define MODPR_V_Hmint		18	
#define MODPR_V_HminB		19	
#define MODPR_V_HminL		20
	
#define MODPR_V_Hmax		21	
#define MODPR_V_HmaxU		22	
#define MODPR_V_Hmaxt		23	
#define MODPR_V_HmaxB		24	
#define MODPR_V_HmaxL		25

#define MODPR_V_Rmin		26	
#define MODPR_V_RminU		27	
#define MODPR_V_Rmint		28	
#define MODPR_V_RminB		29	
#define MODPR_V_RminL		30
	
#define MODPR_V_Rmax		31	
#define MODPR_V_RmaxU		32	
#define MODPR_V_Rmaxt		33	
#define MODPR_V_RmaxB		34	
#define MODPR_V_RmaxL		35

#define MODPR_V_VUR			36	
#define MODPR_V_VUH			37	
#define MODPR_V_VUdate		1002	
#define MODPR_V_VUtime		38	
#define MODPR_V_VUdatetime	1003	
#define MODPR_V_VUL			39
#define MODPR_V_VUmssv		1004		

#define MODPR_V_NUR			40	
#define MODPR_V_NUH			41	
#define MODPR_V_NUdate		1005	
#define MODPR_V_NUtime		42	
#define MODPR_V_NUdatetime	1006	
#define MODPR_V_NUL			43	
#define MODPR_V_NUmssv		1007		

#define MODPR_V_DL			44		
#define MODPR_V_DLS			45		
#define MODPR_V_KR			46		

#define MODPR_T_RV75		601	
#define MODPR_T_R75			47	
#define MODPR_T_V75			48	
#define MODPR_T_X75			501
#define MODPR_T_Y75			502
#define MODPR_T_Z75			503
#define MODPR_T_VX75		504
#define MODPR_T_VY75		505
#define MODPR_T_VZ75		506
#define MODPR_T_OSC75		611		
#define MODPR_T_i75			49		
#define MODPR_T_W75			50		
#define MODPR_T_w75			51		
#define MODPR_T_u75			52		

#define MODPR_T_RV00		602	
#define MODPR_T_R00			53		
#define MODPR_T_V00			54		
#define MODPR_T_X00			507
#define MODPR_T_Y00			508
#define MODPR_T_Z00			509
#define MODPR_T_VX00		510
#define MODPR_T_VY00		511
#define MODPR_T_VZ00		512
#define MODPR_T_OSC00		612		
#define MODPR_T_i00			55		
#define MODPR_T_W00			56		
#define MODPR_T_w00			57		
#define MODPR_T_u00			58		

#define MODPR_T_RVTE		603	
#define MODPR_T_RTE			59		
#define MODPR_T_VTE			60		
#define MODPR_T_XTE			513
#define MODPR_T_YTE			514
#define MODPR_T_ZTE			515
#define MODPR_T_VXTE		516
#define MODPR_T_VYTE		517
#define MODPR_T_VZTE		518
#define MODPR_T_OSCTE		613		
#define MODPR_T_iTE			61	
#define MODPR_T_WTE			62		
#define MODPR_T_wTE			63		
#define MODPR_T_uTE			64

#define MODPR_T_RVTES		604	
#define MODPR_T_RTES		65		
#define MODPR_T_VTES		66	
#define MODPR_T_XTES		519
#define MODPR_T_YTES		520
#define MODPR_T_ZTES		521
#define MODPR_T_VXTES		522
#define MODPR_T_VYTES		523
#define MODPR_T_VZTES		524
#define MODPR_T_OSCTES		614		
#define MODPR_T_iTES		67	
#define MODPR_T_WTES		68		
#define MODPR_T_wTES		69		
#define MODPR_T_uTES		70
		
#define MODPR_T_RVGSC		605	
#define MODPR_T_RGSC		71		
#define MODPR_T_VGSC		72		
#define MODPR_T_XGSC		525
#define MODPR_T_YGSC		526
#define MODPR_T_ZGSC		527
#define MODPR_T_VXGSC		528
#define MODPR_T_VYGSC		529
#define MODPR_T_VZGSC		530

//----------------------------------------------------------------------------- 
enum TypeUPP {UPPint=0, UPPdouble=1, UPPexp=2, UPPTime=3} ;

struct ZSUserPrintParam {
	double  value;
	TypeUPP	type;
	string	name;
	string	namedim;
	string	namehtml;
	string	namedimhtml;
	int		len;
	int		dec;

	ZSUserPrintParam() {
		value= 0.0 ;
		type = UPPint ;
		len  = 0 ;
		dec  = 0 ;
		name = "";
		namedim = "";
		namehtml = "";
		namedimhtml = "";
	}
	ZSUserPrintParam(TypeUPP _type, 
		int _len=6, int _dec=0, 
		char* _name=nullptr, char* _namedim=nullptr,
		char* _namehtml = nullptr, char* _namedimhtml = nullptr) {
		value= 0.0 ;
		type = _type ;
		len  = _len ;
		dec  = _dec ;
		if (_name)		name = _name; 
		else			name = "";
		if (_namedim)	namedim = _namedim; 
		else			namedim = "";
		if (_name)		namehtml = _namehtml;
		else			namehtml = "";
		if (_namedim)	namedimhtml = _namedimhtml;
		else			namedimhtml = "";
	}
};

class FLYCORE_API ZCMPrintKey {
public :
	ZCMPrintKey () { fromVit = true ; isAflat = false ; }
	~ZCMPrintKey() { Clear() ; }

	void FromVitOn () { fromVit = true ; } ;
	void FromVitOff() { fromVit = false ; } ;
	void AflatOn() { isAflat = true ; } 
	void ApeakOn() { isAflat = false ; } 
	bool IsAflat() { return isAflat ; } 

	void Clear  () { P.clear() ; UP.clear() ; }
	void ClearP () { P.clear() ; }
	void ClearUP() { UP.clear() ; }
	int  Size () { return P.size() ; }
	int  SizeU() { return UP.size() ; }
	int  SizeF() { return(UP.size()+P.size()) ; }
	void operator << (int KeyParam) { P.push_back(KeyParam) ; }
	void operator << (ZSUserPrintParam& UserParam) { UP.push_back(UserParam) ; }
	int operator [] (int i)  { return P[i] ; }
	int operator [] (short i){ return P[i] ; }
	int operator [] (long i) { return P[i] ; }
	int operator [] (char i) { return P[i] ; }
	ZSUserPrintParam& UPP(int i) { return UP[i] ; }

	bool fromVit ;
	bool isAflat ;

protected :
	vector<int>	P ;
	vector<ZSUserPrintParam> UP ;
} ;

//----------------------------------------------------------------------------- 
#define MAX_APEAK_COLUMN	8 
#define SIZE_PSB			4 

//----------------------------------------------------------------------------- 
// Диспетчер документирования
// Фактически движёк для создания документов с результатами решения прикладных
// задач. Реализована возможность создания как текстовых документов так и 
// документов в формате Html.
// Документ Html может содержать кроме всего прочего элементы CSS и JavaScript
// Все возможности Html-документирования реализованы компонентом FlyHtmlWriter
// посредством класса ZCHtmlBuilder . . .
//-----------------------------------------------------------------------------
class FLYCORE_API ZCPrintManager {
public:
	//-------------------------------------------------------------------------
	// Перечень параметров движения, подлежащих документированию
	ZCMPrintKey   MPK;
	//-------------------------------------------------------------------------
	// Форматы документирования данных
	ZCPrintFormat MPF;
	// Строка-стикер - общий стикер для всех создаваемых документов.
	// Данная строка будет добавлена в конец имени создаваемого файла перед
	// расширением файла
	static char CommonFileSticker[64];

protected:
	// "Писатель" для создания документа в Html формате.
	ZCHtmlBuilder* HtmlCreator = nullptr;
	// Текстовый документ в который выводятся результаты решения прикладных
	// задач. Переменная инициализируется в методе PrePrint при инициализации 
	// документирования. Далее, если при вызове любого из методов 
	// Print____(..., fp), указатель fp равен nullptr или вообще опускается,
	// вывод текстовой информации осуществляется именно в файл на который 
	// указывает localFp.
	FILE*     localFp = nullptr;
	// Время начала и время конца создания документа. Отображаются
	// в документе для фиксации времени проведения соответствующих расчётов
	time_t    startTIME = 0, endTIME = 0;
	struct tm start_TM;
	// "Наклейка" к имени создаваемого документа, добавляется автоматически
	// к имени создаваемого файла (как текстового так и html)
	// Наклейка определяется прикладной программой 
	// посредством метода SetPrintFileSticker
	// В имени создаваемого файла содержанию строки FileSticker может 
	// предшествовать содержание строки CommonFileSticker - стикера общего
	// для всех создаваемых файлов.
	//
	// Формат имени создаваемых файлов:
	//		UserDefineName_CommonFileSticker_FileSticker.txt 
	//		UserDefineName_CommonFileSticker_FileSticker.html
	char FileSticker[128];

	// Буфер для накапливания параметров движения формируемых на время
	ZSC_SI PSB[MAX_APEAK_COLUMN];
	// Буфер для накапливания интегральных параметров движения 
	// формируемых на витках
	ZSC_VI PVB[MAX_APEAK_COLUMN];

	int countPSB = 0;

	string fullTextFileName;
	string fullHtmlFileName;

public :
	ZCPrintManager();
	~ZCPrintManager();

	// Полное имя созданных файлов - текстового и в формате Html
	const char* GetTextFileName();
	const char* GetHtmlFileName();
	// Просмотр результатов средствами операционной системы
	void ShowTextFile();
	void ShowHtmlFile();

	// Таким образом можно задать перечень документируемых 
	// параметров движения
	void operator << (int KeyParam) { MPK << KeyParam; }
	void operator << (ZSUserPrintParam& UserParam) { MPK << UserParam; }

	//-------------------------------------------------------------------------
	// Определение "стикера" файла-документа. 
	// Смотри поле FileSticker настоящего класса.
	void SetPrintFileSticker(char* FS = nullptr);

	// Инициализация процесса документирпования с созданием файла документа,
	// в заданном каталоге, для заданного КА 
	int PrePrint (ZMSC* pKA, char* 
				  DirMame=nullptr, 
				  char* FileName=nullptr, 
				  FILE** pfp=nullptr, 
				  char* FullName=nullptr) ;

	//-------------------------------------------------------------------------
	// Завершение документирования, при необходимости в файл 
	// записывается число итераций (cointiter) 
	int PostPrint(FILE** pfp = nullptr, int cointiter = -1);
	// Закрытие файла документа с формированием времени окончания 
	// вычислительного или иного процесса.
	int ClosePrint(FILE** pfp = nullptr);

	// Документирование параметров движения, для заланного КА (pKA),
	// Документируются параметры движение на какое-либо время (FS), и/или
	// интегральные параметры движения для какого-либо витка (FV).
	// Файл документа - fp. Если fp=nullptr, то документирование 
	// выполняется в файл this->localFp
	int PrintMSC (ZMSC* pKA, ZSC_SI* FS=nullptr, 
				  ZSC_VI* FV=nullptr, FILE* fp=nullptr) ; 
	// Запись заголовка в файл-документ
	int PrintHeaderDoc(char* hd, FILE* fp=nullptr);
	// Документирование простого текста
	int PrintText(const char* text, char countCR = 0, FILE* fp = nullptr);
	// Документирование НУ
	int PrintNU(ZNU&  NU, char* Title, int VarPrint=3, FILE* fp=nullptr);
	// Документирование лигическоц шкалы сил
	int PrintLSF(ZLSF& LS, int VarPrint=1, FILE* fp=nullptr);

	//-------------------------------------------------------------------------
	// "Горизонтальное", то есть в строку, документирование параметров движения
	//		pKA - модель движения (КА) для которой выполняется документирование,
	//		FS  - параметры движения на текущий момент времени,
	//		FV  - параметры движения на текущий виток
	//		fp  - текстовый файл в который выдаются результаты.
	int PrintAflatMSC(ZMSC* pKA, 
					  ZSC_SI* FS=nullptr, ZSC_VI* FV=nullptr,
					  FILE* fp=nullptr);
	// "Вертикальное", то есть в столбик, документирование параметров движения
	int PrintApeakMSC(ZMSC* pKA, 
					  ZSC_SI* FS=nullptr, ZSC_VI* FV=nullptr,
					  FILE* fp=nullptr);

	//-------------------------------------------------------------------------
	// Формирование в документе горизонтальной черты, отделяющей 
	// некоторую группу параметров движения.
	int  PrintLineMSC(FILE* fp=nullptr); 
	// Формирование в документе горизонтальной черты, отделяющей 
	// некоторую группу параметров движения, документирумых горизонтально.
	void PrintAflatLineMSC(FILE* fp=nullptr); 
	// Формирование в документе горизонтальной черты, отделяющей 
	// некоторую группу параметров движения, документируемых вертикально
	void PrintApeakLineMSC(FILE* fp=nullptr); 
	// Документирование горизонтальной линии.
	void PrintLine(FILE* fp=nullptr);

	//-------------------------------------------------------------------------
	// Документирование интегральных параметров (характеристик) витка
	void PrintVitPoint(FILE* fp, ZSC_VP& VP) ;

	//-------------------------------------------------------------------------
	// Доступ к созданным файлам.
	// Позволяет прикладной пограмме напрямуб записывать информацию в данные
	// файлы, минуя интерфейс диспетчера документирования.
	//-------------------------------------------------------------------------
	// Доступ к указателю на созданный текстовый файл документа
	FILE* TextFile() { return localFp; }
	// Доступ к указателю на "писатель" Html-файла
	ZCHtmlBuilder* HtmlFile() { return HtmlCreator; }

protected:
	//-------------------------------------------------------------------------
	// Создание имени файла документа, в заданном каталоге, для заданного КА
	void GetPrintLongName(ZMSC* pKA,
		char* DirMame  = nullptr,
		char* FileName = nullptr,
		char* LNF  = nullptr,
		char* LNF2 = nullptr,
		char* LNF3 = nullptr,
		char* LND  = nullptr);
	// Создание и открытие файла документа, в заданном каталоге, 
	// для заданного КА 
	int OpenPrintLongName(ZMSC* pKA,
		char* DirMame  = nullptr,
		char* FileName = nullptr,
		FILE** pfp     = nullptr,
		char* FullName = nullptr);


	void PrintAflatLineMSChtml();
	void PrintAflatLineMSCtext(FILE* fp = nullptr);
	int PrintApeakMSChtml(ZMSC* pKA, ZSC_SI* FS, ZSC_VI* FV);
	int PrintApeakMSCtext(ZMSC* pKA, ZSC_SI* FS, ZSC_VI* FV, FILE* fp=nullptr);
	int PrintAflatMSChtml(ZMSC* pKA, ZSC_SI* FS, ZSC_VI* FV);
	int PrintAflatMSCtext(ZMSC* pKA, ZSC_SI* FS, ZSC_VI* FV, FILE* fp = nullptr);

	void TablApeakHtmlGroupHeader(ZСHtmlItem& I, const int j,
								 const char* caption, const int countPSB);
	void TablApeakHtmlGroupHBLRH(ZСHtmlItem& I, const int  j,
								 const bool forH, const bool forMax, 
								 const int  countPSB);
	void TablApeakHtmlGroupCoord(ZСHtmlItem& I, const int  j, const int  k,
								 const int  countPSB);
} ;

//-----------------------------------------------------------------------------
#define PZCPrintManager ZTSelfRemovPointer<ZCPrintManager>

FLYCORE_API void SmartPrintfI(FILE*pf, char* sf, int I, bool isTwoDest=false);
FLYCORE_API void SmartPrintfL(FILE*pf, char* sf, long L, bool isTwoDest = false);
FLYCORE_API void SmartPrintfD(FILE*pf, char* sf, double D, bool isTwoDest = false);
FLYCORE_API void SmartPrintfS(FILE*pf, char* sf, char* S, bool isTwoDest = false);
FLYCORE_API void SmartPrintfS(FILE*pf, char* S, bool isTwoDest = false);

//------------------------------------------------------------------------------- 
#endif // #ifndef PrintMSC_H
