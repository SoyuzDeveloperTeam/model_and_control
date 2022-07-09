//---------------------------------------------------------------------------

#ifndef ssvp_moduleH
#define ssvp_moduleH
//---------------------------------------------------------------------------

const double max_speed_pt_w = 0.15; // m/c
const int max_probe = 404;  // мм
static bool shtanga_w; // Признак движения штанги (актив. по запуску дв.)
static int s_pos;      // Положение штанги от нуля

static bool ssvp_otstr; // Признак "Отстрел ССВП"
static bool ssvp_ready; // 

static struct{
bool dk_1[4];     // Депестки
bool dk_2[2];     // На головке штырьки Датчики Касания
bool shrs[4];     // Штепсельный Разъём Стыка
bool dzg[2];      // Датчик Закрытия Головки
bool zachelki[4]; // Защелки головки (0 - закрыты, 1 - открыты)
bool dkr[2];      // Датчик Контроля расстыковки
bool dog[4];      // Датчик Обеспечения Герметичности
bool dzs[4];      // Датчик закрытия стыка
}sensors;

static struct{
double shtanga_kon_p_j2000[3];
}g_pos;

static bool kruki;   // 1 = закрыты, 0 = открты
static bool pru_tol; // Пружинные толкатели (0 втянуты - 1 сработали)

static int xod_shtangi; // Ход штанги
#endif
