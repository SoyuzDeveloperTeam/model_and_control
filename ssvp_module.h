//---------------------------------------------------------------------------

#ifndef ssvp_moduleH
#define ssvp_moduleH
//---------------------------------------------------------------------------

const double max_speed_pt_w = 0.15; // m/c
const int max_probe = 404;  // ��
static bool shtanga_w; // ������� �������� ������ (�����. �� ������� ��.)
static int s_pos;      // ��������� ������ �� ����

static bool ssvp_otstr; // ������� "������� ����"
static bool ssvp_ready; // 

static struct{
bool dk_1[4];     // ��������
bool dk_2[2];     // �� ������� ������� ������� �������
bool shrs[4];     // ����������� ������ �����
bool dzg[2];      // ������ �������� �������
bool zachelki[4]; // ������� ������� (0 - �������, 1 - �������)
bool dkr[2];      // ������ �������� �����������
bool dog[4];      // ������ ����������� �������������
bool dzs[4];      // ������ �������� �����
}sensors;

static struct{
double shtanga_kon_p_j2000[3];
}g_pos;

static bool kruki;   // 1 = �������, 0 = ������
static bool pru_tol; // ��������� ��������� (0 ������� - 1 ���������)

static int xod_shtangi; // ��� ������
#endif
