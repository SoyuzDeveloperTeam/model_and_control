#ifndef _md_m
#define _md_m
#define MODULE_ID 1
static struct {
long  md_dst_Init (long ip);
long  md_dst_Set (long ip);
long  md_dst_Start (long ip);
double a10; //����. ����-->����.
double a11; //����. ����-->����.
double a12; //����. ����-->����.
double a13; //����. ����-->����.
double a20; //����. ����-->����.
double a21; //����. ����-->����.
double a22; //����. ����-->����.
double a23; //����. ����-->����.
double b10; //����. ����-->����.
double b11; //����. ����-->����.
double b12; //����. ����-->����.
double b13; //����. ����-->����.
double b20; //����. ����-->����.
double b21; //����. ����-->����.
double b22; //����. ����-->����.
double b23; //����. ����-->����.
double c2kr_mas[9]; //������/���� ���-->����� ��� ����
double cb1; //�������������� ����������� ��.
double cb2; //�������������� ����������� ���.
double cm1x; //���������� �.�. �� � ������. �� ��.
double cm1y; //���������� �.�. �� � ������. �� ��.
double cm1z; //���������� �.�. �� � ������. �� ��.
double cm2x; //���������� �.�. �� � ������. �� ���.
double cm2y; //���������� �.�. �� � ������. �� ���.
double cm2z; //���������� �.�. �� � ������. �� ���.
double d; //���������� ����� �.�. �� � ���.
double d10; //���������� ����-->����.
double d11; //���������� ����-->����.
double d12; //���������� ����-->����.
double d13; //���������� ����-->����.
double d_pku; //���������� ����� �.�. �� � ��� ��� � �����.
char dianu; //��������������� ������� ��.
char docitk; //������� ������� �� �����. �����������:0-���; 1-��� � ��.
double dt; //�������� ��������� �.�. �� � ���.
double dt_pku; //�������� ��������� �.�. �� � ��� ��� �. �����.
double dtpr; //�������� ��������.
double dx22; //������ ���. ���������(�.�.���-->�.�.��) � ����.
double dx22_pku; //������ ���. ���������(�.�.���-->�.�.��) � ���� ��� �. �����.
double dx31; //������ ��������� ������.�.��-->������.�.��� � ����
double dy22; //������ ���. ���������(�.�.���-->�.�.��) � ����.
double dy22_pku; //������ ���. ���������(�.�.���-->�.�.��) � ���� ��� �. �����.
double dy31; //������ ��������� ������.�.��-->������.�.��� � ����
double dz22; //������ ���. ���������(�.�.���-->�.�.��) � ����.
double dz22_pku; //������ ���. ���������(�.�.���-->�.�.��) � ���� ��� �. �����.
double dz31; //������ ��������� ������.�.��-->������.�.��� � ����
double e1; //�������������� ������ ��.
double e1x31; //���. ������� ��������� �� � ����.
double e1y31; //���. ������� ��������� �� � ����.
double e1z31; //���. ������� ��������� �� � ����.
double e2; //�������������� ������ ���.
double e2x32; //���. ������� ��������� ��� � ����.
double e2y32; //���. ������� ��������� ��� � ����.
double e2z32; //���. ������� ��������� ��� � ����.
double ex1; //������ �� ������ � ����.
double ex21; //��� ����������� �� ������ � OCKA
double ex31; //��� ����������� �� ������ � ����
double ey1; //������ �� ������ � ����.
double ey21; //��� ����������� �� ������ � OCKA
double ey31; //��� ����������� �� ������ � ����
double ez1; //������ �� ������ � ����.
double ez21; //��� ����������� �� ������ � OCKA
double ez31; //��� ����������� �� ������ � ����
double f0; //���������� ����-->����.
double f1; //���������� ����-->����.
double f2; //���������� ����-->����.
double f3; //���������� ����-->����.
double fi1; //�������� �������� ��.
double fi2; //�������� �������� ���.
double fkr_mas[9]; //������/���� ����-->����� ��� ����
double gam11; //���� ���-->����.
double gam12; //���� ����-->����.
double gam12_pku; //���� ����-->���� ��� �. �����.
double gam14; //���� ���-->����.
double gam14_pku; //���� ���-->����� ��� �. �����.
double gam21; //���� ���-->����.
double gam22; //���� ����-->����.
double gam24; //���� ���-->����.
double gam24_pku; //���� ���-->����/����� ��� �. �����.
double gam24t; //���� ��� �� ���.
double gam24t_pku; //���� ��� �� ���.
double gam33; //���� ����-->����.
double gam33_pku; //���� ����-->���� ��� �. �����.
double h; //��� �������������� ��������� ��������.
double h1; //������ �.�. �� ��� ������������ �����.
double h2; //������ �.�. ��� ��� ������������ �����.
double h2_pku; //������ �.�. ��� ��� ������������ ����� ��� �. �����.
double i1; //���������� ������ ��.
double i2; //���������� ������ ���.
double j2_mas[9]; //������ �������� ������� ���
double j_j1_mas[9]; //������ �������� ������� ��
char kaspku; //������� ������� ��� ��������� �������� � ����� ���.
double kh; //����������� �������� �������.
char ktpku; //������� ������ �� ���� ��� ��� ��������� �������� � ����� ���.
double lstx; //�����. ����� ������ ������
double lsty; //�����. ����� ������ ������
double lstz; //�����. ����� ������ ������
double lux[6]; //������/�����. ����. ���� � ������(nsu) ��� ����
double luy[6]; //������/�����. ����. ���� � ������(nsu) ��� ����
double luz[6]; //������/�����. ����. ���� � ������(nsu) ��� ����
double m1; //����� ��.
double m2; //����� ���.
double m_tu_mas[9]; //������/���� ������-->����� ��� ����
double md_otl_doubl1; //���������� ������������ ������ ��������.
double md_otl_doubl2; //���������� ������������ ������ ��������.
double md_otl_doubl3; //���������� ������������ ������ ��������.
double md_otl_doubl4; //���������� ������������ ������ ��������.
double md_otl_doubl5; //���������� ������������ ������ ��������.
char md_otl_int1; //���������� ����� ������ ��������.
char md_otl_int2; //���������� ����� ������ ��������.
char md_otl_int3; //���������� ����� ������ ��������.
double md_otl_mas[9]; //���������� ������ ������ ��������.
char md_test1; //������� ��������� ����� �� 1
char md_test2; //������� ��������� ����� �� 2
char md_test3; //������� ��������� ����� �� 3
char md_test4; //������� ��������� ����� �� 4
char md_test5; //������� ��������� ����� �� 5
char nro; //N ������ ���������� ���.
char nsu; //N ����. ����: 0-���; 1-��.
char nsu_pku; //N ����. ���� ��� �. �����.: 0-���; 1-��.
char nsus; //N ����. ���� ������.
char nsv; //N ������
char ntpku; //������� ����� � ���� ��� ��� ��������� �������� � ����� ���.
char nu; //N ������� ��:1- ����� 1; 2- ���. ��.
char nudisk; //������� ������� �� � �����.
char nuotn; //�-� ������������� ���. ����������
char nz; //N ���� ����.:0 +X; 1 -X; 2 +Y; 3 -Y; 4 +Z; 5 -Z
char nz_pku; //N ���� ����. ��� �.�����,:0 +X; 1 -X; 2 +Y; 3 -Y; 4 +Z; 5 -Z
char nzs; //N ���� ����. ������:0 +X; 1 -X; 2 +Y; 3 -Y; 4 +Z; 5 -Z
char nzz; //N ���� ����. �����:0 +X; 1 -X; 2 +Y; 3 -Y; 4 +Z; 5 -Z
char nzzv; //N ���� ����. ������:0 +X; 1 -X; 2 +Y; 3 -Y; 4 +Z; 5 -Z
double om; //������ ������� �������� ��.
double om1; //������� ����������� ���� ������ ��.
double om1x; //���. ����. �� � ��. �����. ���� �������.
double om1x31; //������� �������� �� � ����.
double om1x31_pku; //������� �������� �� � ���� ��� �. �����.
double om1y; //���. ����. �� � ��. �����. ���� �������.
double om1y31; //������� �������� �� � ����.
double om1y31_pku; //������� �������� �� � ���� ��� �. �����.
double om1z; //���. ����. �� � ��. �����. ���� �������.
double om1z31; //������� �������� �� � ����.
double om1z31_pku; //������� �������� �� � ���� ��� �. �����.
double om2; //������� ����������� ���� ������ ���.
double om2krx; //������� �������� ��� � ����/�����.
double om2krx_pku; //������� �������� ��� � ����/����� ��� �. �����.
double om2kry; //������� �������� ��� � ����/�����.
double om2kry_pku; //������� �������� ��� � ����/����� ��� �. �����.
double om2krz; //������� �������� ��� � ����/�����.
double om2krz_pku; //������� �������� ��� � ����/����� ��� �. �����.
double om2x; //���. ����. ��� � ��. �����. ���� �������.
double om2x32; //������� �������� ��� � ����.
double om2y; //���. ����. ��� � ��. �����. ���� �������.
double om2y32; //������� �������� ��� � ����.
double om2z; //���. ����. ��� � ��. �����. ���� �������.
double om2z32; //������� �������� ��� � ����.
double om_pku; //������ ������� �������� �� ��� �. �����.
double omr; //������ ������� �������� �� ������������ ���.
double omrx; //������� �������� �� ������������ ��� � ����.
double omry; //������� �������� �� ������������ ��� � ����.
double omrz; //������� �������� �� ������������ ��� � ����.
double omx4otn_pku; //������� �������� �� ���. ���� � ���� ��� �. �����.
double omy4; //������� �������� �� � ���.
double omy4_pku; //������� �������� �� � ��� ��� �. �����.
double omy4otn_pku; //������� �������� �� ���. ���� � ���� ��� �. �����.
double omz4; //������� �������� �� � ���.
double omz4_pku; //������� �������� �� � ��� ��� �. �����.
double omz4otn_pku; //������� �������� �� ���. ���� � ���� ��� �. �����.
char otnnu; //������� ����� ���. ���������� � �� :0-�������-�������; 1-���������.
double p1; //������� ������� ������ ��.
double p2; //������� ������� ������ ���.
char p_nu; //fffffffffffffffffff
char pkpr; //������ ����� �������� ��� ������ ������� "����".
char prlpku; //������� ������� ��� ��������� �������� � ����� ���.
char prosv1; //������� ����������� ��.
char prosv2; //������� ����������� ���.
char prrp; //������� ������ ��������.
char prrp2; //������� ������ �������� ���.
char prsk; //������� �� ��� �����1: 0-����; 1-����.
char prsts; //������� ������. ����. �� ��.
double psi; //���� ����-->���.
double psi11; //���� ���-->����.
double psi12; //���� ����-->����.
double psi12_pku; //���� ����-->���� ��� �. �����.
double psi14; //���� ���-->����.
double psi14_pku; //���� ���-->����� ��� �. �����.
double psi21; //���� ���-->����.
double psi22; //���� ����-->����.
double psi24; //���� ���-->����.
double psi24_pku; //���� ���-->����/����� ��� �. �����.
double psi24t; //���� ��� �� ���.
double psi24t_pku; //���� ��� �� ���.
double psi33; //���� ����-->����.
double psi33_pku; //���� ����-->���� ��� �. �����.
double psi_pku; //���� ����-->��� ��� �. �����.
double r1x1; //������-������ �� � ����.
double r1x5; //������-������ �.�. �� � ����.
double r1y1; //������-������ �� � ����.
double r1y5; //������-������ �.�. �� � ����.
double r1z1; //������-������ �� � ����.
double r1z5; //������-������ �.�. �� � ����.
double r2x1; //������-������ ��� � ����.
double r2x5; //������-������ �.�. ��� � ����.
double r2y1; //������-������ ��� � ����.
double r2y5; //������-������ �.�. ��� � ����.
double r2z1; //������-������ ��� � ����.
double r2z5; //������-������ �.�. ��� � ����.
double rosu; //���������� ����� �������� ����/����.������ �� � ���.
double rosu_pku; //���������� ����� �������� ����/����.������ �� � ��� ��� � �����.
double rz1; //������� ������ ����� ��� ��.
double s; //������.
double s_pku; //������ ��� � �����.
double sig1; //�������� ������ ������� ������ ��.
double sig2; //�������� ������ ������� ������ ���.
char skdoc; //�� �� ���������� ���: 1-���; 2-���; 3-���
char sktk; //�� �� ���������� ��:0-������.����.; 1-���; 2-���; 3-���
double storm; //��������� ����.
double storm_pku; //��������� ���� ��� �. �����.
char swp29; //������� ������. ����.(����������).
double sy; //������������ ������� �� ��� �����.
double sy_pku; //������������ ������� �� ��� ����� ��� �. �����.
double sz; //������������ ������� �� ��� �����.
double sz_pku; //������������ ������� �� ��� ����� ��� �. �����.
char td; //����� �������.
char td1; //����� �� (�����1).
char td2; //����� ��� (�����1).
double tdkt2; //����� �� ������ �� ���� ���.
double tdkt2_pku; //����� �� ������ �� ���� ��� ��� �. �����.
double tdnt2; //����� �� ����� � ���� ���.
double tdnt2_pku; //����� �� ����� � ���� ��� ��� �. �����.
double tet; //���� ����-->���.
__declspec(dllimport) double tet11; //���� ���-->����.
__declspec(dllimport) double tet12; //���� ����-->����.
__declspec(dllimport) double tet12_pku; //���� ����-->���� ��� �. �����.
__declspec(dllimport) double tet14; //���� ���-->����.
__declspec(dllimport) double tet14_pku; //���� ���-->����� ��� �. �����.
__declspec(dllimport) double tet21; //���� ���-->����.
__declspec(dllimport) double tet22; //���� ����-->����.
__declspec(dllimport) double tet24; //���� ���-->����.
__declspec(dllimport) double tet24_pku; //���� ���-->����/����� ��� �. �����.
__declspec(dllimport) double tet24t; //���� ��� �� ���.
__declspec(dllimport) double tet24t_pku; //���� ��� �� ���.
__declspec(dllimport) double tet33; //���� ����-->����.
__declspec(dllimport) double tet33_pku; //���� ����-->���� ��� �. �����.
__declspec(dllimport) double tet_pku; //���� ����-->��� ��� �. �����.
__declspec(dllimport) double tgy; //��������� ����� ������� ������� ��������.
__declspec(dllimport) double tgy_pku; //��������� ����� ������� ������� �������� ��� �. �����.
__declspec(dllimport) double tgz; //��������� ����� ������� ������� ��������.
__declspec(dllimport) double tgz_pku; //��������� ����� ������� ������� �������� ��� �. �����.
__declspec(dllimport) char tj; //��� �������.
__declspec(dllimport) char tj1; //��� �� �� (�����1).
__declspec(dllimport) char tj2; //��� �� ��� (�����1).
__declspec(dllimport) double tkt2t; //����� ���������� ������ �� ���� ���.
__declspec(dllimport) double tkt2t_pku; //����� ���������� ������ � ���� ��� ��� �. �����.
__declspec(dllimport) char tmn; //����� �������.
__declspec(dllimport) char tmn1; //����� �� (�����1).
__declspec(dllimport) char tmn2; //����� ��� (�����1).
__declspec(dllimport) double tnt2t; //����� ���������� ����� � ���� ���.
__declspec(dllimport) double tnt2t_pku; //����� ���������� ����� � ���� ��� ��� �. �����.
__declspec(dllimport) double tt; //������� ��������� ����� �� ������ ����� � ���.
__declspec(dllimport)  double tt_ot_puska_pku;
__declspec(dllimport) double tt1; //����� �� �� ��� �����1.
__declspec(dllimport) double tt2; //����� �� ��� ��� �����1.
__declspec(dllimport) double tt_pku; //������� ��������� ����� �� ������ ����� � ���. ��� �. �����.
__declspec(dllimport) double ttorm; //����� ����������.
__declspec(dllimport) double ttorm_pku; //����� ���������� ��� �. �����.
__declspec(dllimport) double v; //������ ������� ��������.
__declspec(dllimport) double v1; //�������� �������� �� ������ ������� p1.
__declspec(dllimport) double v1x1; //�������� �.�. �� � ����.
__declspec(dllimport) double v1x21; //�������� �.�. �� � ����.
__declspec(dllimport) double v1x5; //�������� �.�. �� � ����(��������� �����������).
__declspec(dllimport) double v1y1; //�������� �.�. �� � ����.
__declspec(dllimport) double v1y21; //�������� �.�. �� � ����.
__declspec(dllimport) double v1y5; //�������� �.�. �� � ����(��������� �����������).
__declspec(dllimport) double v1z1; //�������� �.�. �� � ����.
__declspec(dllimport) double v1z5; //�������� �.�. �� � ����(��������� �����������).
__declspec(dllimport) double v2; //�������� �������� �� ������ ������� p2.
__declspec(dllimport) double v2x1; //�������� �.�. ��� � ����.
__declspec(dllimport) double v2x22; //�������� �.�. ��� � ����.
__declspec(dllimport) double v2x5; //�������� �.�. ��� � ����(��������� �����������).
__declspec(dllimport) double v2y1; //�������� �.�. ��� � ����.
__declspec(dllimport) double v2y22; //�������� �.�. ��� � ����.
__declspec(dllimport) double v2y5; //�������� �.�. ��� � ����(��������� �����������).
__declspec(dllimport) double v2z1; //�������� �.�. ��� � ����.
__declspec(dllimport) double v2z5; //�������� �.�. ��� � ����(��������� �����������).
__declspec(dllimport) double v_pku; //������ ������� �������� ��� �. �����.
__declspec(dllimport) double vbok; //������� ������������ �������� ����� ������ ���. ����. ����.
__declspec(dllimport) double vbok_pku; //������� ������������ �������� ����� ������ ���. ����. ���� ��� � �����.
__declspec(dllimport) double vpr; //���������� ������������ �������� ����� ������ ���. ����. ����.
__declspec(dllimport) double vpr_pku; //���������� ������������ �������� ����� ������ ���. ����. ���� ��� � �����.
__declspec(dllimport) double vrx22; //������������� ��������(�.�.�� ������������ �.�.���) � ����.
__declspec(dllimport) double vrx22_pku; //������������� ��������(�.�.�� ������������ �.�.���) � ���� ��� �. �����.
__declspec(dllimport) double vry22; //������������� ��������(�.�.�� ������������ �.�.���) � ����.
__declspec(dllimport) double vry22_pku; //������������� ��������(�.�.�� ������������ �.�.���) � ���� ��� �. �����.
__declspec(dllimport) double vrz22; //������������� ��������(�.�.�� ������������ �.�.���) � ����.
__declspec(dllimport) double vrz22_pku; //������������� ��������(�.�.�� ������������ �.�.���) � ���� ��� �. �����.
__declspec(dllimport) double vy4; //������� �������� � ���.
__declspec(dllimport) double vy4_pku; //������� �������� � ��� ��� �. �����.
__declspec(dllimport) double vz4; //������� �������� � ���.
__declspec(dllimport) double vz4_pku; //������� �������� � ��� ��� ���
__declspec(dllimport) double w1x31; //���. ��������� �� � ����.
__declspec(dllimport) double w1y31; //���. ��������� �� � ����.
__declspec(dllimport) double w1z31; //���. ��������� �� � ����.
__declspec(dllimport) double w2x32; //���. ��������� ��� � ����.
__declspec(dllimport) double w2y32; //���. ��������� ��� � ����.
__declspec(dllimport) double w2z32; //���. ��������� ��� � ����.
__declspec(dllimport)  double k_kdymf[6]; //������ ������� � �������� ��������� ���
__declspec(dllimport)  char prks; //������� �������
__declspec(dllimport)  char prot; //������� ������
__declspec(dllimport)  char prrs; //������� �����������
__declspec(dllimport) double p_zapas; //
__declspec(dllimport) long m_tr_time; //����� �� �����
__declspec(dllimport) char nu_ot_time_cek_doteni; //������� �� ����
__declspec(dllimport) char nu_ot_time_hour_doteni; //���� �� ����
__declspec(dllimport) char nu_ot_time_min_doteni; //������ �� ����
__declspec(dllimport) char nu_ot_time_cek_vteni; //������� �� ����
__declspec(dllimport) char nu_ot_time_hour_vteni; //���� �� ����
__declspec(dllimport) char nu_ot_time_min_vteni; //������ �� ����
__declspec(dllimport) double ttdv; //???
__declspec(dllimport) double t_vteni; //???


//  ������ ������ ��





//06.01.00
   __declspec(dllimport) double dx1; 
   __declspec(dllimport) double dy1;
   __declspec(dllimport) double dz1;
   __declspec(dllimport) double vrx1;
   __declspec(dllimport) double vry1;
   __declspec(dllimport) double vrz1;
   __declspec(dllimport) int nu_pzvt;
   __declspec(dllimport) int kl;



double otl_md[15];
int otl_mi[15];

double mj1_mas[9] ; // ������� mj1:����-->��. �. ��� � ���� ����������� �������


//��������� ��� �� 06.02.00 ��������
char nsu_for_dk;  // ���� �������� (�� ������� ��� �� ������ ��������)
double  Ro_ASF_AKR;//�����. ����� ��� �� � ��� ��� (�� ��� ���)
double  Ro_ASF_AR;//  �����. ����� ����� � �����
double  Ro_vt;//�����. �� �.�. �� �� �����, ���������� �� 300�
                                     // �� ��������� ����� �� ��� +X ����� (��� ���� ��������) 
double  Ro_t;//�������� ��������� �.�. �� � ���
double  V_otn;//������ ������������� �������� �.�. �� � ���
double  Om_lv_CCKAd_Y, Om_lv_CCKAd_Z;//�������� ������� �������� ��
                                                            //�� ��� ����(���)    
double  Lamda[4];//����������: ����(���.) --> ����� (��� ���� ��������)
double  Psi_ASF1_AKR, Tet_ASF1_AKR;//���� ������� ����������� �� ���1 ��
                           // �� ��������� (�� ���1 ��) ��� �� ��� � ���� ���1 ��.
                           // ����� ��� �� ��� ������������ ����� �������� 
__declspec(dllimport)  double  Psi_ASF1_AR,Tet_ASF1_AR;//���� ������� ����������� �� ���1 �� 
                                                       //�� �� ���� �������� � ���� ���1 ��.  
__declspec(dllimport)  double  Psi_3AO_ASF2,Tet_3AO_ASF2;//���� ������� ����������� �� 3�� ���
                                                         // �� ���2 �� � ���� 3�� ��� 
  
__declspec(dllimport) long Time; //   ����� �� ���. �����  

__declspec(dllimport)  double  Ro_AKRTK_AKRDOS;//���������� �� ��� �� N1 �� ��������� � ��� �� N1 ��� �� ���
__declspec(dllimport)  double  Psi_AO_AKR, Tet_AO_AKR;//���� ������� ����������� �� 2����  � ��� �� ��� � ���� 2����
__declspec(dllimport)  double  Gam_otn;		//   ���� ��������� ����� ���� ������������ �����.

__declspec(dllimport)  int prstop_t1; // ������� ��������� �� � ������������� �� ��� ���. ��������� �� ���
// ������ ���������� ������ ��� �������� ��

__declspec(dllimport)  char  nsu_NU_DST, nz_NU_DST, nro_tk_NU_DST; 
__declspec(dllimport)  double rosu_NU_DST, dt_NU_DST, tet_NU_DST, psi_NU_DST, omy4_NU_DST, omz4_NU_DST,
          psi14_NU_DST,  tet14_NU_DST,  gam14_NU_DST, 
		  psi24_NU_DST,  tet24_NU_DST,  gam24_NU_DST,
		  om2x32_NU_DST, om2y32_NU_DST, om2z32_NU_DST;

__declspec(dllimport)  double psi_sol,	 tet_sol;// ���� ����������� �� ������ � ����
__declspec(dllimport)  char   pr_sol_osk;        //������� ������� � �� ����������� �� ������ � ����
__declspec(dllimport)  char   nro_tk;            //����� ������ ���������� ��
__declspec(dllimport)  char   upr_orient_iz_dk;//������� ������� ���������� ����������� �� �� ��
                                               //(��� ������ ����. �� � ���+����.)
__declspec(dllimport)  char   upr_orient_iz_syd;//������� ������� ���������� ����������� �� �� ����
                                               //(��� ������ ����. �� � ���+����.)

__declspec(dllimport)  char forma_otobr_otn_par; //������� ����� ����������� ���. ���. ����.
                                         //0 - ���. ���. ����. �.�. � ���
                                         //1 - �������������� �����
__declspec(dllimport)  char nsu_dir_otobr; //����� ����. ���� ��� ����������� ������� �����. ����  
                                   //0- �������;1- ���;  2- ��
                                   //3- ��+X; 4- ��-Y; 5-���-Y
__declspec(dllimport)  char prudar;//������� ����� �� � ���
__declspec(dllimport)  double Gam_CCKA_OCKA, Tet_CCKA_OCKA;//���� ����-->���� ��� ��
 //������� �������� ����� ������� ��� - ������� �� � ����
__declspec(dllimport)  double  Om_AO_AKR_Y,Om_AO_AKR_Z;   
__declspec(dllimport)  double  Om_ASF1_AR_Y,Om_ASF1_AR_Z;
__declspec(dllimport)  double  Om_ASF1_AKR_Y,Om_ASF1_AKR_Z; 
//###############  13.11.2001 ��� ������� ����. ���������� ����� �� � ���  #########
__declspec(dllimport)  double GEOM_DISTANCE;
__declspec(dllimport) char *g_szMin; // ������ � ��������� ��������� ���, �� �������� �����. �� �� ����������
__declspec(dllimport) int PR_SMENY_TEKSTA_GEOM;//������� ��������� ������ � ����������� ��������� ���������
// ������ ��� "�������"
__declspec(dllimport) int OF_MD_NEPTUN_DATE_DD;// �����
__declspec(dllimport) int OF_MD_NEPTUN_DATE_MM;// �����
__declspec(dllimport) int OF_MD_NEPTUN_DATE_YY;// ���
__declspec(dllimport) int OF_MD_NEPTUN_DATE_TIME;// ����� (���)
__declspec(dllimport) int OF_MD_SVETOTEN_LOC;// 1-����, 0-����
__declspec(dllimport) int OF_MD_SVETOTEN_TIME;// ����/���� (���)

__declspec(dllimport) int OF_MD_SOYUZ_DOLGOTA_LOC;// 0-���., 1-����.
__declspec(dllimport) int OF_MD_SOYUZ_DOLGOTA_GRAD;//����. ������� 
__declspec(dllimport) int OF_MD_SOYUZ_DOLGOTA_MIN;//����. ���.
__declspec(dllimport) int OF_MD_SOYUZ_SHIROTA_LOC;// 0-���., 1-���.
__declspec(dllimport) int OF_MD_SOYUZ_SHIROTA_GRAD;//���. ������� 
__declspec(dllimport) int OF_MD_SOYUZ_SHIROTA_MIN;//���. ���.

__declspec(dllimport) int OF_MD_TRAEKTORIA_NAKLON_ORB;//���������� ������ (�������)
__declspec(dllimport) int OF_MD_TRAEKTORIA_DOL_VOS_UZL;//����. ����. ���� (�������)
__declspec(dllimport) int OF_MD_TRAEKTORIA_PERIOD;//������ (�������)
__declspec(dllimport) int OF_MD_TEN_NACHALO;//����-������ (�������)
__declspec(dllimport) int OF_MD_TEN_KONEC;//����-����� (�������)

//###############  21.04.2003 ��� ���� ������ #########
__declspec(dllimport)  double X_TK_sivostend,Y_TK_sivostend,Z_TK_sivostend,
		E1_TK_X_sivostend,E1_TK_Y_sivostend,E1_TK_Z_sivostend,
		E2_TK_X_sivostend,E2_TK_Y_sivostend,E2_TK_Z_sivostend;
__declspec(dllimport)  int PRKS_sivostend;
//###############  08.06.2003 ��� ����� �������� ���(2���) #########
//�������� �������-�������(TRUE-FALSE),���������-������� ���(TRUE-FALSE)
__declspec(dllimport)  bool DON_MASTER, DON_DOUBLE;
//  ��� � ��1
__declspec(dllimport)  double for_2TMA_tt,for_2TMA_om2x,for_2TMA_om2y,for_2TMA_om2z,
          for_2TMA_b20,for_2TMA_b21,for_2TMA_b22,for_2TMA_b23,
		  for_2TMA_v2,for_2TMA_v2x22,for_2TMA_v2y22,
		  for_2TMA_a20,for_2TMA_a21,for_2TMA_a22,for_2TMA_a23,

          for_2TMA_om1x,for_2TMA_om1y,for_2TMA_om1z,
          for_2TMA_b10,for_2TMA_b11,for_2TMA_b12,for_2TMA_b13,
		  for_2TMA_v1,for_2TMA_v1x21,for_2TMA_v1y21,
		  for_2TMA_a10,for_2TMA_a11,for_2TMA_a12,for_2TMA_a13;
//  ��2
__declspec(dllimport)  double from_2TMA_tt,from_2TMA_om1x,from_2TMA_om1y,from_2TMA_om1z,
          from_2TMA_D_d10,from_2TMA_D_d11,from_2TMA_D_d12,from_2TMA_D_d13,
		  from_2TMA_dx22,from_2TMA_dy22,from_2TMA_dz22,
		  from_2TMA_vrx22,from_2TMA_vry22,from_2TMA_vrz22;
///////////////////////////TK2/////////////////////////////////////////////
__declspec(dllimport)  double GEOM_DISTANCE_tk2;		//����������
__declspec(dllimport)  double dt_pku_tk2;				//��������
__declspec(dllimport)  double omy4_pku_tk2;
__declspec(dllimport)  double omz4_pku_tk2;
__declspec(dllimport)  double om_pku_tk2;
__declspec(dllimport)  double vz4_pku_tk2;
__declspec(dllimport)  double vy4_pku_tk2;
__declspec(dllimport)  double v_pku_tk2;
__declspec(dllimport)  double psi14_pku_tk2;
__declspec(dllimport)  double tet14_pku_tk2;
__declspec(dllimport)  double psi24_pku_tk2;
__declspec(dllimport)  double tet24_pku_tk2;
__declspec(dllimport)  double gam24_pku_tk2;
__declspec(dllimport)  char nz_pku_tk2;

//����� �� �� ������������� ������
__declspec(dllimport) double ATK_om1x,ATK_om1y,ATK_om1z,	ATK_b10,ATK_b11,ATK_b12,ATK_b13,
ATK_v1,ATK_v1x21,ATK_v1y21, ATK_a10,ATK_a11,ATK_a12,ATK_a13;

__declspec(dllimport) char	FLAG_NU_FOR_SLAVE;

 __declspec(dllimport) double nu_tk2_koor_x_tk; //���������� �.�. ��
 __declspec(dllimport) double nu_tk2_koor_y_tk; //���������� �.�. ��
 __declspec(dllimport) double nu_tk2_koor_z_tk; //���������� �.�. ��
 __declspec(dllimport) double nu_com_koor_x_tk; //���������� �.�. ��
 __declspec(dllimport) double nu_com_koor_y_tk; //���������� �.�. ��
 __declspec(dllimport) double nu_com_koor_z_tk; //���������� �.�. ��

//��������� ��� ����������� ������������� �������������� �������� (SN) 27.04.2004 ��������
 
 struct For_SN_ObjTransform
 {
	  double R[3];      //������ ��������� ������� � �����. ��
	  double angle;         //���� ��������
	  double V[3];      //��� ������� ��������� �������� ������� ���. �����. ��
 };

 __declspec(dllimport) For_SN_ObjTransform For_SN_SKS,For_SN_MKS,For_SN_TK1,For_SN_TK2;
 

 struct For_SN_Observer
 {
	 double R[3];       //������ ��������� ����������� � �������� �������. ��
	 double Obj[3];     //������ ��������� ����������� ����� � �������� �������. ��
	 double PY[3];      //������ ��� +Y ����������� � �������� �������. ��
	 double fov_View;   //���� ������ ����������� � ��������
 };
 __declspec(dllimport) struct For_SN_Observer For_SN_OBS;

 __declspec(dllimport) double For_SN_TRACK_TK1[3];//���������� ��1
 __declspec(dllimport) double For_SN_TRACK_TK2[3];//���������� ��2
 __declspec(dllimport) double For_SN_SCALE;//����������� ��������������� �����������
 __declspec(dllimport) char For_SN_MKS_DockingTK[3]; //����. ��������� �������. ��
                                                      //0-��+X;1- ��1;2- ��� -Y
 __declspec(dllimport) char For_SN_ON_TK2; //������� ��������� ��2

//  **************************8
 __declspec(dllimport) double W_SKD; 
 __declspec(dllimport) double DV_SKD; 
 __declspec(dllimport) double Quat_OSKP_LSK_0,
	 Quat_OSKP_LSK_1, Quat_OSKP_LSK_2, Quat_OSKP_LSK_3; 
__declspec(dllimport) double k_kdy27[6]; //������ ������� � �������� ��������� ���
__declspec(dllimport) char m_pusk; //������� �����
__declspec(dllimport) double	dt_kas;
__declspec(dllimport) double	omy4_kas;
__declspec(dllimport) double	omz4_kas;
__declspec(dllimport) double	om_kas;
__declspec(dllimport) double	vz4_kas;
__declspec(dllimport) double	vy4_kas;
__declspec(dllimport) double	v_kas;
__declspec(dllimport) double	tet14_kas;
__declspec(dllimport) double	psi14_kas;
__declspec(dllimport) double	gam14_kas;
__declspec(dllimport) double	tet24_kas;
__declspec(dllimport) double	psi24_kas;
__declspec(dllimport) double	gam24_kas;
__declspec(dllimport) double	tet33_kas;
__declspec(dllimport) double	psi33_kas;
__declspec(dllimport) double	gam33_kas;
__declspec(dllimport) double	tet24t_kas;
__declspec(dllimport) double	psi24t_kas;
__declspec(dllimport) double	gam24t_kas;
__declspec(dllimport) double	om1x31_kas;
__declspec(dllimport) double	om1y31_kas;
__declspec(dllimport) double	om1z31_kas;
__declspec(dllimport) double	om2krx_kas;
__declspec(dllimport) double	om2kry_kas;
__declspec(dllimport) double	om2krz_kas;
__declspec(dllimport) double	sy_kas;
__declspec(dllimport) double	sz_kas;
__declspec(dllimport) double	s_kas;
__declspec(dllimport) double	tdnt2_kas;
__declspec(dllimport) double	tt_kas;
__declspec(dllimport) long	m_tr_time_kas;
__declspec(dllimport) double	d_kas;
__declspec(dllimport) double	p_zapas_kas;
__declspec(dllimport) double	ostatok_kas;
__declspec(dllimport) double	rashod_skd_kas;
__declspec(dllimport) double	rashod_ryo_kas;
__declspec(dllimport) double	rashod_ryd_kas;
__declspec(dllimport) char 	num_skd_kas;
__declspec(dllimport) double	vpr_kas;
__declspec(dllimport) double	vbok_kas;

__declspec(dllimport) double    ostatok;
__declspec(dllimport) double    rashod_skd;
__declspec(dllimport) double    rashod_ryo;
__declspec(dllimport) double    rashod_ryd;
__declspec(dllimport) char      num_skd;


__declspec(dllimport) int pr_pau;//    �p����� ����� �����
__declspec(dllimport) int pr_normal_kas;//    �p����� ����������� �������

__declspec(dllimport)   double om1y21; /*   ������� �������� ����  �      */
__declspec(dllimport)   double om1z21; /* ��������� �� ��� ����           */
 
//  2006.07.04
__declspec(dllimport) char pdzt;//������� ������������ ������� ���� �� ��
__declspec(dllimport) double d20;//���������� ����-->����
__declspec(dllimport) double d21;//���������� ����-->����
__declspec(dllimport) double d22;//���������� ����-->����
__declspec(dllimport) double d23;//���������� ����-->����
__declspec(dllimport) double fix;//�������� ���. ����. ����
__declspec(dllimport) double fiy;//�������� ���. ����. ����
__declspec(dllimport) double fiz;//�������� ���. ����. ����
__declspec(dllimport) long osv2s;//������� �����. ��� - ������. ����.
__declspec(dllimport) double tt_ot_puska_pku_s;//����� �� ������ ������ - ������. ����.
__declspec(dllimport) double dts;//�������� ��������� �.�. ��� � �� - ������. ����.
__declspec(dllimport) double c1_mas[9];//������� c1:���-->���� � ����� ����������� �������
__declspec(dllimport) char prRRST; //������� ����������� � ��������� �������
__declspec(dllimport) double LenSht;//����� ����� ������

__declspec(dllimport) double lprx[7]; /* �����-�� ������� ���������� � ������ ������� ����-� ��*/
__declspec(dllimport) double lpry[7]; /*1-��� ������ ����,2-������ ����(���),3-������ ����    */
__declspec(dllimport) double lprz[7]; /*4-��������� ����(���),5-����� ����(��) */
                              /* 6-������ ����(��),7-����. ��� � ������. ����. ����.*/
__declspec(dllimport) double r1,r2;   //������� ������ ������-�������� �� � ���
__declspec(dllimport) bool MOBIL ;
__declspec(dllimport) bool KOSMO ;
__declspec(dllimport) double OmY4rel_pku,OmZ4rel_pku;//������� �������� �� ������������ ��� � ���
__declspec(dllimport) char nroSet;    //�������� � ������� ��� ����� ������ ���������� ���

///////////////// ����������� ���������
__declspec(dllimport)  double ForRatContVlong,ForRatContVSide,
                              ForRatContS,ForRatContSY,ForRatContSZ,
							  ForRatContAlpha,ForRatContGamma,
							  ForRatContOmegaGamma,ForRatContOmegaYZ,ForRatContOmegaY,ForRatContOmegaZ;
__declspec(dllimport) double	stab_vsk_om;//������� ������� ���������� ���+�
__declspec(dllimport) double	stab_vsk_eps;//������� �������� ���������� ���+�
__declspec(dllimport) double	stab_vsk_psi;//���� ��������� ��� ������������ ���
__declspec(dllimport) double	stab_vsk_tet;//���� ��������� ��� ������������ ���
__declspec(dllimport) double	stab_vsk_gam;//���� ��������� ��� ������������ ���
__declspec(dllimport) int stab_ock_nu;//����� ������������ ��� �� ��
double Ro_t_osuzel;//�������� ���. �������� �.�. �� � ��� �� ��� ������������ ���� ��
double    rashod_ryd_man;
double    rashod_ryo_man;
double    rashod_man;
double alpha_rot_ferm; // ����, �� ������� ���������� ������� ��������� ���� P4-P6 � S4-S6

char k_l9b1; //������� ���-�1
char k_l9b2; //������� ���-�2

// ������ ����� ������ �� � ��� (����, ��� �  ����) � ��������
double Trassa_tk1[2][100], Trassa_tk2[2][100], Trassa_tk3[2][100];
double Trassa_mks1[2][100], Trassa_mks2[2][100], Trassa_mks3[2][100];
// �������������� ����� �� � ���
double Dolgota_tk, Shirota_tk, Dolgota_mks, Shirota_mks;
char Priz_Trassa_tk;//������� ����� ����� ������ ��
char Priz_Trassa_mks;//������� ����� ����� ������ ���
char Update_tk;//������� ���������� ���� ��
char Update_mks;//������� ���������� ���� ���
char RODK;//������� ���. RODK
char yd_krodk; //������� ����
char HalfTaktRODK;//������� ��������� RODK
double CIFV_WOB_from_MD[3];//������� �������� ��� � ��������� �� ��������� ��� ���, ���/�
double MIVK_F_DPO_SUB_for_MD[3][16];//������� ���� �� 16 ��������� 200 �� ����� �� ���, [�]
double MIVK_M_DPO_SUB_for_MD[3][16];//������� ������ �� 16 ��������� 200 �� ����� �� ���, [�*�]
bool RKK;
char nu_otor_switch_svjazka; //������������� ������������ ������������ ��������� // ��������� 281111
double dx22_AKR; //������ ���. ��������� (��������� ��� ���-->�.�.��) � ����.
double dy22_AKR; //������ ���. ��������� (��������� ��� ���-->�.�.��) � ����.
double dz22_AKR; //������ ���. ��������� (��������� ��� ���-->�.�.��) � ����.
double dt_prich_pku;	//����������� �� ������� ������ ������� �� �2�� � �1�� (� ������������ � ��� ��������)
double dt_prich_kas;	//����������� �� ������� ������ ������� �� �2�� � �1�� ��� ���� �������
char nsu_for_sivo;	// ������������� �������������� ����� ���� ��� ����
double dt_vsk_pku;	//����������� �� ������� ������ ������� �� P2 � P1 (����� ������������ ������ - ����� ���)
double psi22_pku;		//���� ���������� ����->����
double tet22_pku;
double gam22_pku;
char osk_tp_var_trans;	//������� �������� ���-�� 0-�������, 1-����������
char osk_tp_reg;			//������� �������� ���-�� 0-���, 1-����
double dWx_osk_tp, dWy_osk_tp, dWz_osk_tp;
char osk_tp_n_subreg[3];	// ������ ������� �����-���������� ������ ������� ��
double nu_com_koor_x_dos;
double nu_com_koor_y_dos;
double nu_com_koor_z_dos;
double nu_com_massa_dos;
double nu_com_jxx_dos;
double nu_com_jxy_dos;
double nu_com_jzx_dos;
double nu_com_jyy_dos;
double nu_com_jyz_dos;
double nu_com_jzz_dos;
double nu_com_massa_tk;
double nu_com_jxx_tk;
double nu_com_jxy_tk;
double nu_com_jzx_tk;
double nu_com_jyy_tk;
double nu_com_jyz_tk;
double nu_com_jzz_tk;
char nu_otor_stab;			//	����� ������������ ���
char nu_otor_switch_styk_dk;	//	� ��, � �������� ����������� ������������
char nu_otor_switch_styk;		//	� �������� ����������� ��
double nu_com_zapas;			//	����� �������
char RegType;
double sy_pr;           //������ ����� ������ ��� ������������ ������ �������� �������� ���� ��� ������� "������������" � �����, (��)
double sz_pr;           //
double dwy_pr;          //������� ������� ��������� ��� � ��� � ���� ��� ������� "������������" (������/�)
double dwz_pr;
unsigned long loc_prks, loc_promah; // �������� ������� � ������� ��� ����� ��������� �������� �������          //
double alpha_lamp_mks, beta_lamp_mks;//���� ����������� ��� ����� ������������ ����������� ���
} m_math;
#endif

