//---------------------------------------------------------------------------

#ifndef rdc_draphH
#define rdc_draphH
//---------------------------------------------------------------------------
// ������ ��� ����������� ���������� �� ���� //
// 1. �� �������� �������� �������� �� //
double rdc_sm_dsm[16]; // ������� �� (4,2 �)
double rdc_sm_dsu[16]; // ������� �� (1,3 �)
double rdc_sm_hm[16];  // ������ ������ (0,4 �)

// 2. �� �������� �������� �������� ���1
double rdc_mim1_dmim1[16];
double rdc_mim1_dsu[16];
double rdc_mim1_hmm[16];
double rdc_mim1_dsm[16];

// 3. �� �������� �������� �������� ��1 � ���2
double rdc_somim_dso1[16];
double rdc_somim_dsu[16];
double rdc_somim_hmm[16];
double rdc_somim_dsm[16];
#endif
