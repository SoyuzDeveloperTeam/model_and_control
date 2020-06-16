//------------------------------------------------------------------------------
// ModGlobal.h
// �. ��������� 03.08.2018
//------------------------------------------------------------------------------
#ifndef MODGLOBAL_H
#define MODGLOBAL_H
//------------------------------------------------------------------------------

#define RRC if (rc) return rc  

extern FLYCORE_API char DIRFLY[512];
extern FLYCORE_API char DIRFLYINFO[512];
extern FLYCORE_API char DIREGF[512];
extern FLYCORE_API char DIRIERSEOP[512];
extern FLYCORE_API char DIREOPSTORAGE[512];
extern FLYCORE_API char DIRRESULT[512];
extern FLYCORE_API char DIRUOF[512];

FLYCORE_API int FlyGlobalInit();

/*
// ���� 1 ������ 1975 ���� �� ��������� � 1 ������ 2000 ����
extern const double DTPCor1975 ;
extern const double k_sekrad ;
extern const double k_zona ;
extern const double k_mu_kms ; //	
extern const double k_b0 ;     //  �������������� ����������,           [����**3/ccc**2]
extern const double k_c20 ;    //  �����.���������� ���������� �����,   [����**2/ccc**2]
extern const double k_omega ;  //  ������� �������� �������� �����,     [���/ccc]
extern const double k_rcp ;    //  ������� ������ �����,                [����]
extern const double k_a0 ;     //  ������� ������� ��� ,                [����]
extern const double k_alfa0 ;  //  �������� ������ ��� ,
extern const double k_alfak ;  //  �������� ������ �� ,
extern const double k_ak ;     //  ������� ������� �� ,                 [����]
extern const double k_ekb ;    //  ������� ��������������� ��,
extern const double k_gekw ;   //  ��������� ���� ������� �� ��������,  [����/ccc**2]
extern const double k_g0 ;     //  ��������� ���� ������� �� ��������,  [�/c**2]
extern const double k_eps ;	   //	

extern const double k_dx;     //  �������� ������ �� ���.������ ��� ,  [����]
extern const double k_dy ;    //              --
extern const double k_dz ;    //              --
extern const double k_cfak ;  //  �������� ����� �����������,          [����/ccc]
extern const double k_cnom ;  //  �������� ����� �����������,          [����/ccc]
extern const double k_tmt ;   //  ������������ �������� �� ���������� ������� �
extern const double k_tmf ;   //    ��������� � ������ ������������� ����� �����
extern const double k_rekw ;  //  �������������� ������ �����,         [����]
extern const double k_threeh ;//  3 ����,                              [ccc]
extern const double k_pi ;    // +3.14159265358979e+00;   //  ����� ��
extern const double k_polpi ; // +1.57079632679000e+00;   //  ����� ��/2
extern const double k_dwapi ; // +6.28318530717000e+00;   //  ����� ��*2
extern const double k_t2pi ;  // +4.71238897037000e+00;   //  ����� ��*3/2
extern const double k_grarad ;//  �������� � �������,                  [����/���]
extern const double k_sekrad ;//  ������� ������ � �������             [���/���]
extern const double k_cbc ;   //  ������ � ������                      [���]
extern const double k_cbm ;   //  ����� � ������                       [���]
extern const double k_e0 ;    //  ����. ����. ���.�� ���-�� ����� [(�� ����**2)/(m**2 ccc**3]
extern const double k_gs ;    //  ����������������� ������. ����.      [����**3/���**2]
extern const double k_gl ;    //  ������������������ ������. ����.     [����**3/���**2]
extern const double k_qk ;    //  ��������� ����� ����� � ����� ����   [ - ]
extern const double k_qk2 ;   //  ����� ����                           [ - ]
extern const double k_ql ;    //  ���� ������������ ��������� �����    [������]
extern const double k_ae ;    //  ��������������� �������              [����]
extern const double k_rcp_c ; //  ������� ������ ������,               [����]
extern const double k_rcp_l ; //  ������� ������ ����,                 [����]
extern const double k_zona ;  //  ������� ���������� ������� �� �������� [���]
extern const double k_vek;    //  ������� ��� (�������  =  20)
extern const double k_vekcme ;//  ��� �������� ����� ����
extern const double k_dwx ;   //  ����������� ��� X �� ������������ ��� [���]
extern const double k_dwy ;   //  ����������� ��� Y �� ������������ ��� [���]
extern const double k_dwz ;   //  ����������� ��� Z �� ������������ ��� [���]

extern const bool k_Flag_Pril ;    //  ���� ����� �������� � ����������� ��
extern const bool k_Flag_Tekt ;    //  ���� ����� �������� ������������� ���� � ����������� ��
extern const bool k_Flag_Pvz  ;    //  ���� ������� ��� ��� ��������� ���-���
extern const bool k_Flag_Pril_Pvz ;//  ���� ����� ����������� ��������� �������� ���
extern const double k_g_jupiter ;  //  ������. ����. �������  [����**3/���**2]
extern const double k_g_saturn ;   //  ������. ����. �������  [����**3/���**2]
extern const double k_g_uran ;     //  ������. ����. �����    [����**3/���**2]
extern const double k_g_venera ;   //  ������. ����. ������   [����**3/���**2]
extern const double k_g_mars ;     //  ������. ����. �����    [����**3/���**2]
extern const double k_g_neptun ;   //  ������. ����. �������  [����**3/���**2]
extern const double k_g_merkurj ;  //  ������. ����. �������� [����**3/���**2]
extern const double k_g_pluton ;   //  ������. ����. �������  [����**3/���**2]
*/
//extern const long   DELTA_2000 ;

//-----------------------------------------------------------------------
extern double* mJ2000_B1975 ;
extern double* mgrzab ;

extern double  Global_m2000_75[9] ;

struct POLE_AE ;
extern POLE_AE* Wae ;
//---------------------------------------------------------------------------
FLYCORE_API void  ClearErrorsMSG();
FLYCORE_API int   CountErrorsMSG();
FLYCORE_API int   CountWarningsMSG();
FLYCORE_API void  AddErrorMSG(char* Msg);
FLYCORE_API void  AddWarningMSG(char* Msg);
FLYCORE_API const char* GetErrorMsg(int i);
FLYCORE_API const char* GetWarningMsg(int i);
//---------------------------------------------------------------------------
#endif // #ifndef MODGLOBAL_H