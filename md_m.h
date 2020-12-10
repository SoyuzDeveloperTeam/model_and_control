#ifndef _md_m
#define _md_m
#define MODULE_ID 1
static struct {
long  md_dst_Init (long ip);
long  md_dst_Set (long ip);
long  md_dst_Start (long ip);
double a10; //кват. ГЭСК-->ОСКА.
double a11; //кват. ГЭСК-->ОСКА.
double a12; //кват. ГЭСК-->ОСКА.
double a13; //кват. ГЭСК-->ОСКА.
double a20; //кват. ГЭСК-->ОСКП.
double a21; //кват. ГЭСК-->ОСКП.
double a22; //кват. ГЭСК-->ОСКП.
double a23; //кват. ГЭСК-->ОСКП.
double b10; //кват. ГЭСК-->ССКА.
double b11; //кват. ГЭСК-->ССКА.
double b12; //кват. ГЭСК-->ССКА.
double b13; //кват. ГЭСК-->ССКА.
double b20; //кват. ГЭСК-->ССКП.
double b21; //кват. ГЭСК-->ССКП.
double b22; //кват. ГЭСК-->ССКП.
double b23; //кват. ГЭСК-->ССКП.
double c2kr_mas[9]; //Массив/матр ВСК-->КрСКП для ССВП
double cb1; //баллистический коеффициент ТК.
double cb2; //баллистический коеффициент ДОС.
double cm1x; //координата ц.м. ТК в строит. СК ТК.
double cm1y; //координата ц.м. ТК в строит. СК ТК.
double cm1z; //координата ц.м. ТК в строит. СК ТК.
double cm2x; //координата ц.м. ТК в строит. СК ДОС.
double cm2y; //координата ц.м. ТК в строит. СК ДОС.
double cm2z; //координата ц.м. ТК в строит. СК ДОС.
double d; //Расстояние между ц.м. ТК и ДОС.
double d10; //Кватернион ОСКА-->ССКА.
double d11; //Кватернион ОСКА-->ССКА.
double d12; //Кватернион ОСКА-->ССКА.
double d13; //Кватернион ОСКА-->ССКА.
double d_pku; //Расстояние между ц.м. ТК и ДОС для Ф отобр.
char dianu; //диагностический признак НУ.
char docitk; //признак задания НУ орбит. параметрами:0-ДОС; 1-ДОС и ТК.
double dt; //Скорость сближения ц.м. ТК и ДОС.
double dt_pku; //Скорость сближения ц.м. ТК и ДОС для Ф. отобр.
double dtpr; //Интервал прогноза.
double dx22; //Вектор отн. дальности(ц.м.ДОС-->ц.м.ТК) в ОСКП.
double dx22_pku; //Вектор отн. дальности(ц.м.ДОС-->ц.м.ТК) в ОСКП для Ф. отобр.
double dx31; //Вектор дальности строит.ц.ТК-->строит.ц.ДОС в ССКА
double dy22; //Вектор отн. дальности(ц.м.ДОС-->ц.м.ТК) в ОСКП.
double dy22_pku; //Вектор отн. дальности(ц.м.ДОС-->ц.м.ТК) в ОСКП для Ф. отобр.
double dy31; //Вектор дальности строит.ц.ТК-->строит.ц.ДОС в ССКА
double dz22; //Вектор отн. дальности(ц.м.ДОС-->ц.м.ТК) в ОСКП.
double dz22_pku; //Вектор отн. дальности(ц.м.ДОС-->ц.м.ТК) в ОСКП для Ф. отобр.
double dz31; //Вектор дальности строит.ц.ТК-->строит.ц.ДОС в ССКА
double e1; //Эксцентриситет орбиты ТК.
double e1x31; //упр. угловое ускорение ТК в ССКА.
double e1y31; //упр. угловое ускорение ТК в ССКА.
double e1z31; //упр. угловое ускорение ТК в ССКА.
double e2; //Эксцентриситет орбиты ДОС.
double e2x32; //упр. угловое ускорение ДОС в ССКП.
double e2y32; //упр. угловое ускорение ДОС в ССКП.
double e2z32; //упр. угловое ускорение ДОС в ССКП.
double ex1; //вектор на Солнце в ГЭСК.
double ex21; //Орт направления на Солнце в OCKA
double ex31; //Орт направления на Солнце в ССКА
double ey1; //вектор на Солнце в ГЭСК.
double ey21; //Орт направления на Солнце в OCKA
double ey31; //Орт направления на Солнце в ССКА
double ez1; //вектор на Солнце в ГЭСК.
double ez21; //Орт направления на Солнце в OCKA
double ez31; //Орт направления на Солнце в ССКА
double f0; //Кватернион ССКА-->ССКП.
double f1; //Кватернион ССКА-->ССКП.
double f2; //Кватернион ССКА-->ССКП.
double f3; //Кватернион ССКА-->ССКП.
double fi1; //Истинная аномалия ТК.
double fi2; //Истинная аномалия ДОС.
double fkr_mas[9]; //Массив/матр ССКА-->КрСКП для ССВП
double gam11; //Углы ИСК-->ССКА.
double gam12; //Углы ОСКА-->ССКА.
double gam12_pku; //Углы ОСКА-->ССКА для Ф. отобр.
double gam14; //Углы ВСК-->ССКА.
double gam14_pku; //Углы ВСК-->ПССКА для Ф. отобр.
double gam21; //Углы ИСК-->ССКП.
double gam22; //Углы ОСКП-->ССКП.
double gam24; //Углы ВСК-->ССКП.
double gam24_pku; //Углы ВСК-->ССКП/КрСКП для Ф. отобр.
double gam24t; //Углы ДОС по ВТК.
double gam24t_pku; //Углы ДОС по ВТК.
double gam33; //Углы ССКА-->КрСК.
double gam33_pku; //Углы ССКА-->КрСК для Ф. отобр.
double h; //шаг интегрирования уравнений движения.
double h1; //Высота ц.м. ТК над поверхностью Земли.
double h2; //Высота ц.м. ДОС над поверхностью Земли.
double h2_pku; //Высота ц.м. ДОС над поверхностью Земли для Ф. отобр.
double i1; //Наклонение орбиты ТК.
double i2; //Наклонение орбиты ДОС.
double j2_mas[9]; //Массив моментов инерции ДОС
double j_j1_mas[9]; //Массив моментов инерции ТК
char kaspku; //признак касания для обработки ситуации в целях ПКУ.
double kh; //коеффициент масштаба времени.
char ktpku; //признак выхода из тени ДОС для обработки ситуации в целях ПКУ.
double lstx; //коорд. конца штанги СтрСКА
double lsty; //коорд. конца штанги СтрСКА
double lstz; //коорд. конца штанги СтрСКА
double lux[6]; //Массив/коорд. стык. узла в СтрСКП(nsu) для ССВП
double luy[6]; //Массив/коорд. стык. узла в СтрСКП(nsu) для ССВП
double luz[6]; //Массив/коорд. стык. узла в СтрСКП(nsu) для ССВП
double m1; //масса ТК.
double m2; //масса ДОС.
double m_tu_mas[9]; //Массив/матр СтрСКП-->КрСКП для ССВП
double md_otl_doubl1; //Отладочная вещественная модели движения.
double md_otl_doubl2; //Отладочная вещественная модели движения.
double md_otl_doubl3; //Отладочная вещественная модели движения.
double md_otl_doubl4; //Отладочная вещественная модели движения.
double md_otl_doubl5; //Отладочная вещественная модели движения.
char md_otl_int1; //Отладочная целая модели движения.
char md_otl_int2; //Отладочная целая модели движения.
char md_otl_int3; //Отладочная целая модели движения.
double md_otl_mas[9]; //Отладочный массив модели движения.
char md_test1; //Признак включения теста МД 1
char md_test2; //Признак включения теста МД 2
char md_test3; //Признак включения теста МД 3
char md_test4; //Признак включения теста МД 4
char md_test5; //Признак включения теста МД 5
char nro; //N режима ориентации ДОС.
char nsu; //N стык. узла: 0-ПхО; 1-АО.
char nsu_pku; //N стык. узла для Ф. отобр.: 0-ПхО; 1-АО.
char nsus; //N стык. узла старый.
char nsv; //N связки
char ntpku; //признак входа в тень ДОС для обработки ситуации в целях ПКУ.
char nu; //N формата НУ:1- форма 1; 2- оск. эл.
char nudisk; //признак задания НУ с диска.
char nuotn; //п-к использования отн. параметров
char nz; //N зоны набл.:0 +X; 1 -X; 2 +Y; 3 -Y; 4 +Z; 5 -Z
char nz_pku; //N зоны набл. для Ф.отобр,:0 +X; 1 -X; 2 +Y; 3 -Y; 4 +Z; 5 -Z
char nzs; //N зоны набл. Солнца:0 +X; 1 -X; 2 +Y; 3 -Y; 4 +Z; 5 -Z
char nzz; //N зоны набл. Земли:0 +X; 1 -X; 2 +Y; 3 -Y; 4 +Z; 5 -Z
char nzzv; //N зоны набл. звезды:0 +X; 1 -X; 2 +Y; 3 -Y; 4 +Z; 5 -Z
double om; //Модуль угловой скорости ЛВ.
double om1; //Долгота восходящего узла орбиты ТК.
double om1x; //угл. скор. ТК в гл. центр. осях инерции.
double om1x31; //Угловая скорость ТК в ССКА.
double om1x31_pku; //Угловая скорость ТК в ССКА для Ф. отобр.
double om1y; //угл. скор. ТК в гл. центр. осях инерции.
double om1y31; //Угловая скорость ТК в ССКА.
double om1y31_pku; //Угловая скорость ТК в ССКА для Ф. отобр.
double om1z; //угл. скор. ТК в гл. центр. осях инерции.
double om1z31; //Угловая скорость ТК в ССКА.
double om1z31_pku; //Угловая скорость ТК в ССКА для Ф. отобр.
double om2; //Долгота восходящего узла орбиты ДОС.
double om2krx; //Угловая скорость ДОС в ССКП/КрСКП.
double om2krx_pku; //Угловая скорость ДОС в ССКП/КрСКП для Ф. отобр.
double om2kry; //Угловая скорость ДОС в ССКП/КрСКП.
double om2kry_pku; //Угловая скорость ДОС в ССКП/КрСКП для Ф. отобр.
double om2krz; //Угловая скорость ДОС в ССКП/КрСКП.
double om2krz_pku; //Угловая скорость ДОС в ССКП/КрСКП для Ф. отобр.
double om2x; //угл. скор. ДОС в гл. центр. осях инерции.
double om2x32; //Угловая скорость ДОС в ССКП.
double om2y; //угл. скор. ДОС в гл. центр. осях инерции.
double om2y32; //Угловая скорость ДОС в ССКП.
double om2z; //угл. скор. ДОС в гл. центр. осях инерции.
double om2z32; //Угловая скорость ДОС в ССКП.
double om_pku; //Модуль угловой скорости ЛВ для Ф. отобр.
double omr; //Модуль угловой скорости ТК относительно ДОС.
double omrx; //Угловая скорость ТК относительно ДОС в ССКП.
double omry; //Угловая скорость ТК относительно ДОС в ССКП.
double omrz; //Угловая скорость ТК относительно ДОС в ССКП.
double omx4otn_pku; //Угловая скорость ЛВ отн. ССКП в ССКП для Ф. отобр.
double omy4; //Угловая скорость ЛВ в ВСК.
double omy4_pku; //Угловая скорость ЛВ в ВСК для Ф. отобр.
double omy4otn_pku; //Угловая скорость ЛВ отн. ССКП в ССКП для Ф. отобр.
double omz4; //Угловая скорость ЛВ в ВСК.
double omz4_pku; //Угловая скорость ЛВ в ВСК для Ф. отобр.
double omz4otn_pku; //Угловая скорость ЛВ отн. ССКП в ССКП для Ф. отобр.
char otnnu; //признак формы отн. параметров в НУ :0-линейно-угловая; 1-координая.
double p1; //Большая полуось орбиты ТК.
double p2; //Большая полуось орбиты ДОС.
char p_nu; //fffffffffffffffffff
char pkpr; //призак конца прогноза для выдачи команды "стоп".
char prlpku; //признак пролета для обработки ситуации в целях ПКУ.
char prosv1; //признак освещенноти ТК.
char prosv2; //признак освещенноти ДОС.
char prrp; //признак режима прогноза.
char prrp2; //признак режима прогноза доп.
char prsk; //признак СК для Формы1: 0-ГЭСК; 1-ГрСК.
char prsts; //признак состык. сост. по НУ.
double psi; //Углы ОСКП-->ВСК.
double psi11; //Углы ИСК-->ССКА.
double psi12; //Углы ОСКА-->ССКА.
double psi12_pku; //Углы ОСКА-->ССКА для Ф. отобр.
double psi14; //Углы ВСК-->ССКА.
double psi14_pku; //Углы ВСК-->ПССКА для Ф. отобр.
double psi21; //Углы ИСК-->ССКП.
double psi22; //Углы ОСКП-->ССКП.
double psi24; //Углы ВСК-->ССКП.
double psi24_pku; //Углы ВСК-->ССКП/КрСКП для Ф. отобр.
double psi24t; //Углы ДОС по ВТК.
double psi24t_pku; //Углы ДОС по ВТК.
double psi33; //Углы ССКА-->КрСК.
double psi33_pku; //Углы ССКА-->КрСК для Ф. отобр.
double psi_pku; //Углы ОСКП-->ВСК для Ф. отобр.
double r1x1; //Радиус-вектор ТК в ГЭСК.
double r1x5; //Радиус-вектор ц.м. ТК в ГрСК.
double r1y1; //Радиус-вектор ТК в ГЭСК.
double r1y5; //Радиус-вектор ц.м. ТК в ГрСК.
double r1z1; //Радиус-вектор ТК в ГЭСК.
double r1z5; //Радиус-вектор ц.м. ТК в ГрСК.
double r2x1; //Радиус-вектор ДОС в ГЭСК.
double r2x5; //Радиус-вектор ц.м. ДОС в ГрСК.
double r2y1; //Радиус-вектор ДОС в ГЭСК.
double r2y5; //Радиус-вектор ц.м. ДОС в ГрСК.
double r2z1; //Радиус-вектор ДОС в ГЭСК.
double r2z5; //Радиус-вектор ц.м. ДОС в ГрСК.
double rosu; //Расстояние между центрами масс/стык.узлами ТК и ДОС.
double rosu_pku; //Расстояние между центрами масс/стык.узлами ТК и ДОС для Ф отобр.
double rz1; //Текущий радиус Земли для ТК.
double s; //Промах.
double s_pku; //Промах для Ф отобр.
double sig1; //Аргумент широты перигея орбиты ТК.
double sig2; //Аргумент широты перигея орбиты ДОС.
char skdoc; //СК НУ ориентации ДОС: 1-ИСК; 2-ОСК; 3-ВСК
char sktk; //СК НУ ориентации ТК:0-состык.сост.; 1-ИСК; 2-ОСК; 3-ВСК
double storm; //Тормозной путь.
double storm_pku; //Тормозной путь для Ф. отобр.
char swp29; //признак состык. сост.(внутренний).
double sy; //Составляющая промаха по оси КрСКП.
double sy_pku; //Составляющая промаха по оси КрСКП для Ф. отобр.
double sz; //Составляющая промаха по оси КрСКП.
double sz_pku; //Составляющая промаха по оси КрСКП для Ф. отобр.
char td; //число текущее.
char td1; //число ТК (Форма1).
char td2; //число ДОС (Форма1).
double tdkt2; //Время до выхода из тени ДОС.
double tdkt2_pku; //Время до выхода из тени ДОС для Ф. отобр.
double tdnt2; //Время до входа в тень ДОС.
double tdnt2_pku; //Время до входа в тень ДОС для Ф. отобр.
double tet; //Углы ОСКП-->ВСК.
__declspec(dllimport) double tet11; //Углы ИСК-->ССКА.
__declspec(dllimport) double tet12; //Углы ОСКА-->ССКА.
__declspec(dllimport) double tet12_pku; //Углы ОСКА-->ССКА для Ф. отобр.
__declspec(dllimport) double tet14; //Углы ВСК-->ССКА.
__declspec(dllimport) double tet14_pku; //Углы ВСК-->ПССКА для Ф. отобр.
__declspec(dllimport) double tet21; //Углы ИСК-->ССКП.
__declspec(dllimport) double tet22; //Углы ОСКП-->ССКП.
__declspec(dllimport) double tet24; //Углы ВСК-->ССКП.
__declspec(dllimport) double tet24_pku; //Углы ВСК-->ССКП/КрСКП для Ф. отобр.
__declspec(dllimport) double tet24t; //Углы ДОС по ВТК.
__declspec(dllimport) double tet24t_pku; //Углы ДОС по ВТК.
__declspec(dllimport) double tet33; //Углы ССКА-->КрСК.
__declspec(dllimport) double tet33_pku; //Углы ССКА-->КрСК для Ф. отобр.
__declspec(dllimport) double tet_pku; //Углы ОСКП-->ВСК для Ф. отобр.
__declspec(dllimport) double tgy; //Потребное время гашения боковой скорости.
__declspec(dllimport) double tgy_pku; //Потребное время гашения боковой скорости для Ф. отобр.
__declspec(dllimport) double tgz; //Потребное время гашения боковой скорости.
__declspec(dllimport) double tgz_pku; //Потребное время гашения боковой скорости для Ф. отобр.
__declspec(dllimport) char tj; //год текущий.
__declspec(dllimport) char tj1; //год НУ ТК (Форма1).
__declspec(dllimport) char tj2; //год НУ ДОС (Форма1).
__declspec(dllimport) double tkt2t; //Время последнего выхода из тени ДОС.
__declspec(dllimport) double tkt2t_pku; //Время последнего выхода в тень ДОС для Ф. отобр.
__declspec(dllimport) char tmn; //месяц текущий.
__declspec(dllimport) char tmn1; //месяц ТК (Форма1).
__declspec(dllimport) char tmn2; //месяц ДОС (Форма1).
__declspec(dllimport) double tnt2t; //Время последнего входа в тень ДОС.
__declspec(dllimport) double tnt2t_pku; //Время последнего входа в тень ДОС для Ф. отобр.
__declspec(dllimport) double tt; //Текущее модельное время от начала суток в сек.
__declspec(dllimport)  double tt_ot_puska_pku;
__declspec(dllimport) double tt1; //Время НУ ТК для Формы1.
__declspec(dllimport) double tt2; //Время НУ ДОС для Формы1.
__declspec(dllimport) double tt_pku; //Текущее модельное время от начала суток в сек. для Ф. отобр.
__declspec(dllimport) double ttorm; //Время торможения.
__declspec(dllimport) double ttorm_pku; //Время торможения для Ф. отобр.
__declspec(dllimport) double v; //Модуль боковой скорости.
__declspec(dllimport) double v1; //круговая скорость на орбите радиуса p1.
__declspec(dllimport) double v1x1; //Скорость ц.м. ТК в ГЭСК.
__declspec(dllimport) double v1x21; //скорость ц.м. ТК в ОСКА.
__declspec(dllimport) double v1x5; //Скорость ц.м. ТК в ГрСК(локальная производная).
__declspec(dllimport) double v1y1; //Скорость ц.м. ТК в ГЭСК.
__declspec(dllimport) double v1y21; //скорость ц.м. ТК в ОСКА.
__declspec(dllimport) double v1y5; //Скорость ц.м. ТК в ГрСК(локальная производная).
__declspec(dllimport) double v1z1; //Скорость ц.м. ТК в ГЭСК.
__declspec(dllimport) double v1z5; //Скорость ц.м. ТК в ГрСК(локальная производная).
__declspec(dllimport) double v2; //круговая скорость на орбите радиуса p2.
__declspec(dllimport) double v2x1; //Скорость ц.м. ДОС в ГЭСК.
__declspec(dllimport) double v2x22; //скорость ц.м. ДОС в ОСКП.
__declspec(dllimport) double v2x5; //Скорость ц.м. ДОС в ГрСК(локальная производная).
__declspec(dllimport) double v2y1; //Скорость ц.м. ДОС в ГЭСК.
__declspec(dllimport) double v2y22; //скорость ц.м. ДОС в ОСКП.
__declspec(dllimport) double v2y5; //Скорость ц.м. ДОС в ГрСК(локальная производная).
__declspec(dllimport) double v2z1; //Скорость ц.м. ДОС в ГЭСК.
__declspec(dllimport) double v2z5; //Скорость ц.м. ДОС в ГрСК(локальная производная).
__declspec(dllimport) double v_pku; //Модуль боковой скорости для Ф. отобр.
__declspec(dllimport) double vbok; //Боковая составляющая скорости конца штанги отн. стык. узла.
__declspec(dllimport) double vbok_pku; //Боковая составляющая скорости конца штанги отн. стык. узла для Ф отобр.
__declspec(dllimport) double vpr; //Продольная составляющая скорости конца штанги отн. стык. узла.
__declspec(dllimport) double vpr_pku; //Продольная составляющая скорости конца штанги отн. стык. узла для Ф отобр.
__declspec(dllimport) double vrx22; //Относительная скорость(ц.м.ТК относительно ц.м.ДОС) в ОСКП.
__declspec(dllimport) double vrx22_pku; //Относительная скорость(ц.м.ТК относительно ц.м.ДОС) в ОСКП для Ф. отобр.
__declspec(dllimport) double vry22; //Относительная скорость(ц.м.ТК относительно ц.м.ДОС) в ОСКП.
__declspec(dllimport) double vry22_pku; //Относительная скорость(ц.м.ТК относительно ц.м.ДОС) в ОСКП для Ф. отобр.
__declspec(dllimport) double vrz22; //Относительная скорость(ц.м.ТК относительно ц.м.ДОС) в ОСКП.
__declspec(dllimport) double vrz22_pku; //Относительная скорость(ц.м.ТК относительно ц.м.ДОС) в ОСКП для Ф. отобр.
__declspec(dllimport) double vy4; //Боковая скорость в ВСК.
__declspec(dllimport) double vy4_pku; //Боковая скорость в ВСК для Ф. отобр.
__declspec(dllimport) double vz4; //Боковая скорость в ВСК.
__declspec(dllimport) double vz4_pku; //Боковая скорость в ВСК для ПКУ
__declspec(dllimport) double w1x31; //упр. ускорение ТК в ССКА.
__declspec(dllimport) double w1y31; //упр. ускорение ТК в ССКА.
__declspec(dllimport) double w1z31; //упр. ускорение ТК в ССКА.
__declspec(dllimport) double w2x32; //упр. ускорение ДОС в ССКП.
__declspec(dllimport) double w2y32; //упр. ускорение ДОС в ССКП.
__declspec(dllimport) double w2z32; //упр. ускорение ДОС в ССКП.
__declspec(dllimport)  double k_kdymf[6]; //Массив угловых и линейных ускорений КДУ
__declspec(dllimport)  char prks; //признак касания
__declspec(dllimport)  char prot; //признак отвода
__declspec(dllimport)  char prrs; //признак расстыковки
__declspec(dllimport) double p_zapas; //
__declspec(dllimport) long m_tr_time; //Время от пуска
__declspec(dllimport) char nu_ot_time_cek_doteni; //Секунды до тени
__declspec(dllimport) char nu_ot_time_hour_doteni; //Часы до тени
__declspec(dllimport) char nu_ot_time_min_doteni; //Минуты до тени
__declspec(dllimport) char nu_ot_time_cek_vteni; //Секунды до тени
__declspec(dllimport) char nu_ot_time_hour_vteni; //Часы до тени
__declspec(dllimport) char nu_ot_time_min_vteni; //Минуты до тени
__declspec(dllimport) double ttdv; //???
__declspec(dllimport) double t_vteni; //???


//  Данные модели ДК





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

double mj1_mas[9] ; // матрица mj1:ССКА-->гл. ц. оси в виде одномерного массива


//параметры для ДК 06.02.00 Романько
char nsu_for_dk;  // узел стыковки (на который для ДК задана стыковка)
double  Ro_ASF_AKR;//Расст. между АСФ ТК и АКР ДОС (СМ или ФГБ)
double  Ro_ASF_AR;//  Расст. между АСФТК и АРДОС
double  Ro_vt;//Расст. от ц.м. ТК до точки, вынесенной на 300м
                                     // от плоскости стыка по оси +X КрСКП (для узла стыковки) 
double  Ro_t;//Скорость сближения ц.м. ТК и ДОС
double  V_otn;//Модуль относительной скорости ц.м. ТК и ДОС
double  Om_lv_CCKAd_Y, Om_lv_CCKAd_Z;//Проекции угловой скорости ЛВ
                                                            //на оси ССКА(дин)    
double  Lamda[4];//Кватернион: ССКА(дин.) --> КрСКП (для узла стыковки)
double  Psi_ASF1_AKR, Tet_ASF1_AKR;//Углы пеленга направления от АСФ1 ТК
                           // на ближайшую (от АСФ1 ТК) АКР СБ ДОС в осях АСФ1 ТК.
                           // Набор АКР СБ ДОС определяется узлом стыковки 
__declspec(dllimport)  double  Psi_ASF1_AR,Tet_ASF1_AR;//Углы пеленга направления от АСФ1 ТК 
                                                       //на АР узла стыковки в осях АСФ1 ТК.  
__declspec(dllimport)  double  Psi_3AO_ASF2,Tet_3AO_ASF2;//Углы пеленга направления от 3АО ДОС
                                                         // на АСФ2 ТК в осях 3АО ДОС 
  
__declspec(dllimport) long Time; //   время от нач. суток  

__declspec(dllimport)  double  Ro_AKRTK_AKRDOS;//Расстояние от АКР ТК N1 до ближайшей к АКР ТК N1 АКР СБ ДОС
__declspec(dllimport)  double  Psi_AO_AKR, Tet_AO_AKR;//Углы пеленга направления от 2АОТК  к АКР СБ ДОС в осях 2АОТК
__declspec(dllimport)  double  Gam_otn;		//   Угол взаимного крена ССКА относительно КрСКП.

__declspec(dllimport)  int prstop_t1; // признак отработки НУ с некорректными НУ для упр. программы ПО МОБ
// Группа переменных только для хранения НУ

__declspec(dllimport)  char  nsu_NU_DST, nz_NU_DST, nro_tk_NU_DST; 
__declspec(dllimport)  double rosu_NU_DST, dt_NU_DST, tet_NU_DST, psi_NU_DST, omy4_NU_DST, omz4_NU_DST,
          psi14_NU_DST,  tet14_NU_DST,  gam14_NU_DST, 
		  psi24_NU_DST,  tet24_NU_DST,  gam24_NU_DST,
		  om2x32_NU_DST, om2y32_NU_DST, om2z32_NU_DST;

__declspec(dllimport)  double psi_sol,	 tet_sol;// углы направления на Солнце в ОСКП
__declspec(dllimport)  char   pr_sol_osk;        //признак задания в НУ направления на Солнце в ОСКП
__declspec(dllimport)  char   nro_tk;            //номер режима ориентации ТК
__declspec(dllimport)  char   upr_orient_iz_dk;//признак наличия управления ориентацией ТК от ДК
                                               //(для снятия стаб. ТК в ОСК+разв.)
__declspec(dllimport)  char   upr_orient_iz_syd;//признак наличия управления ориентацией ТК от СУДа
                                               //(для снятия стаб. ТК в ОСК+разв.)

__declspec(dllimport)  char forma_otobr_otn_par; //признак формы отображения пар. отн. движ.
                                         //0 - пар. отн. движ. ц.м. в ВСК
                                         //1 - геометрическая форма
__declspec(dllimport)  char nsu_dir_otobr; //номер стык. узла при директивном задании отобр. узла  
                                   //0- автомат;1- ПхО;  2- АО
                                   //3- СМ+X; 4- СМ-Y; 5-ФГБ-Y
__declspec(dllimport)  char prudar;//признак удара ТК и ДОС
__declspec(dllimport)  double Gam_CCKA_OCKA, Tet_CCKA_OCKA;//Углы ССКА-->ОСКА для ДК
 //угловые скорости линии антенна ДОС - антенна ТК в ССКА
__declspec(dllimport)  double  Om_AO_AKR_Y,Om_AO_AKR_Z;   
__declspec(dllimport)  double  Om_ASF1_AR_Y,Om_ASF1_AR_Z;
__declspec(dllimport)  double  Om_ASF1_AKR_Y,Om_ASF1_AKR_Z; 
//###############  13.11.2001 для расчета геом. расстояния между ТК и ДОС  #########
__declspec(dllimport)  double GEOM_DISTANCE;
__declspec(dllimport) char *g_szMin; // строка с названием примитива МКС, до которого расст. от ТК минимально
__declspec(dllimport) int PR_SMENY_TEKSTA_GEOM;//признак изменения строки с параметрами пересчета дистанции
// Данные для "Нептуна"
__declspec(dllimport) int OF_MD_NEPTUN_DATE_DD;// число
__declspec(dllimport) int OF_MD_NEPTUN_DATE_MM;// месяц
__declspec(dllimport) int OF_MD_NEPTUN_DATE_YY;// год
__declspec(dllimport) int OF_MD_NEPTUN_DATE_TIME;// время (сек)
__declspec(dllimport) int OF_MD_SVETOTEN_LOC;// 1-свет, 0-тень
__declspec(dllimport) int OF_MD_SVETOTEN_TIME;// свет/тень (сек)

__declspec(dllimport) int OF_MD_SOYUZ_DOLGOTA_LOC;// 0-зап., 1-вост.
__declspec(dllimport) int OF_MD_SOYUZ_DOLGOTA_GRAD;//долг. градусы 
__declspec(dllimport) int OF_MD_SOYUZ_DOLGOTA_MIN;//долг. мин.
__declspec(dllimport) int OF_MD_SOYUZ_SHIROTA_LOC;// 0-сев., 1-южн.
__declspec(dllimport) int OF_MD_SOYUZ_SHIROTA_GRAD;//шир. градусы 
__declspec(dllimport) int OF_MD_SOYUZ_SHIROTA_MIN;//шир. мин.

__declspec(dllimport) int OF_MD_TRAEKTORIA_NAKLON_ORB;//наклонение орбиты (градусы)
__declspec(dllimport) int OF_MD_TRAEKTORIA_DOL_VOS_UZL;//долг. восх. узла (градусы)
__declspec(dllimport) int OF_MD_TRAEKTORIA_PERIOD;//период (градусы)
__declspec(dllimport) int OF_MD_TEN_NACHALO;//тень-начало (градусы)
__declspec(dllimport) int OF_MD_TEN_KONEC;//тень-конец (градусы)

//###############  21.04.2003 для СИВО стенда #########
__declspec(dllimport)  double X_TK_sivostend,Y_TK_sivostend,Z_TK_sivostend,
		E1_TK_X_sivostend,E1_TK_Y_sivostend,E1_TK_Z_sivostend,
		E2_TK_X_sivostend,E2_TK_Y_sivostend,E2_TK_Z_sivostend;
__declspec(dllimport)  int PRKS_sivostend;
//###############  08.06.2003 для связи двойного ТМА(2ТМА) #########
//Признаки ведущий-ведомый(TRUE-FALSE),одиночный-двойной ТМА(TRUE-FALSE)
__declspec(dllimport)  bool DON_MASTER, DON_DOUBLE;
//  МКС и ТК1
__declspec(dllimport)  double for_2TMA_tt,for_2TMA_om2x,for_2TMA_om2y,for_2TMA_om2z,
          for_2TMA_b20,for_2TMA_b21,for_2TMA_b22,for_2TMA_b23,
		  for_2TMA_v2,for_2TMA_v2x22,for_2TMA_v2y22,
		  for_2TMA_a20,for_2TMA_a21,for_2TMA_a22,for_2TMA_a23,

          for_2TMA_om1x,for_2TMA_om1y,for_2TMA_om1z,
          for_2TMA_b10,for_2TMA_b11,for_2TMA_b12,for_2TMA_b13,
		  for_2TMA_v1,for_2TMA_v1x21,for_2TMA_v1y21,
		  for_2TMA_a10,for_2TMA_a11,for_2TMA_a12,for_2TMA_a13;
//  ТК2
__declspec(dllimport)  double from_2TMA_tt,from_2TMA_om1x,from_2TMA_om1y,from_2TMA_om1z,
          from_2TMA_D_d10,from_2TMA_D_d11,from_2TMA_D_d12,from_2TMA_D_d13,
		  from_2TMA_dx22,from_2TMA_dy22,from_2TMA_dz22,
		  from_2TMA_vrx22,from_2TMA_vry22,from_2TMA_vrz22;
///////////////////////////TK2/////////////////////////////////////////////
__declspec(dllimport)  double GEOM_DISTANCE_tk2;		//расстояние
__declspec(dllimport)  double dt_pku_tk2;				//скорость
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

//чужой ТК на индикационные машины
__declspec(dllimport) double ATK_om1x,ATK_om1y,ATK_om1z,	ATK_b10,ATK_b11,ATK_b12,ATK_b13,
ATK_v1,ATK_v1x21,ATK_v1y21, ATK_a10,ATK_a11,ATK_a12,ATK_a13;

__declspec(dllimport) char	FLAG_NU_FOR_SLAVE;

 __declspec(dllimport) double nu_tk2_koor_x_tk; //Координаты ц.м. ТК
 __declspec(dllimport) double nu_tk2_koor_y_tk; //Координаты ц.м. ТК
 __declspec(dllimport) double nu_tk2_koor_z_tk; //Координаты ц.м. ТК
 __declspec(dllimport) double nu_com_koor_x_tk; //Координаты ц.м. ТК
 __declspec(dllimport) double nu_com_koor_y_tk; //Координаты ц.м. ТК
 __declspec(dllimport) double nu_com_koor_z_tk; //Координаты ц.м. ТК

//параметры для визуального представления относительного движения (SN) 27.04.2004 Романько
 
 struct For_SN_ObjTransform
 {
	  double R[3];      //вектор положения объекта в соотв. СК
	  double angle;         //угол поворота
	  double V[3];      //ось вектора конечного поворота объекта отн. соотв. СК
 };

 __declspec(dllimport) For_SN_ObjTransform For_SN_SKS,For_SN_MKS,For_SN_TK1,For_SN_TK2;
 

 struct For_SN_Observer
 {
	 double R[3];       //вектор положения наблюдателя в исходной мировой. СК
	 double Obj[3];     //вектор положения наблюдаемой точки в исходной мировой. СК
	 double PY[3];      //вектор оси +Y наблюдателя в исходной мировой. СК
	 double fov_View;   //поле зрения наблюдателя в градусах
 };
 __declspec(dllimport) struct For_SN_Observer For_SN_OBS;

 __declspec(dllimport) double For_SN_TRACK_TK1[3];//Траектория ТК1
 __declspec(dllimport) double For_SN_TRACK_TK2[3];//Траектория ТК2
 __declspec(dllimport) double For_SN_SCALE;//Коэффициент масштабирования изображения
 __declspec(dllimport) char For_SN_MKS_DockingTK[3]; //масс. признаков пристык. ТК
                                                      //0-СМ+X;1- СО1;2- ФГБ -Y
 __declspec(dllimport) char For_SN_ON_TK2; //признак включения ТК2

//  **************************8
 __declspec(dllimport) double W_SKD; 
 __declspec(dllimport) double DV_SKD; 
 __declspec(dllimport) double Quat_OSKP_LSK_0,
	 Quat_OSKP_LSK_1, Quat_OSKP_LSK_2, Quat_OSKP_LSK_3; 
__declspec(dllimport) double k_kdy27[6]; //Массив угловых и линейных ускорений СКД
__declspec(dllimport) char m_pusk; //Признак пуска
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


__declspec(dllimport) int pr_pau;//    пpизнак общей паузы
__declspec(dllimport) int pr_normal_kas;//    пpизнак нормального касания

__declspec(dllimport)   double om1y21; /*   угловая скорость ОСКА  в      */
__declspec(dllimport)   double om1z21; /* проекциях на оси ОСКА           */
 
//  2006.07.04
__declspec(dllimport) char pdzt;//признак директивного задания тени по НУ
__declspec(dllimport) double d20;//кватернион ОСКП-->ССКП
__declspec(dllimport) double d21;//кватернион ОСКП-->ССКП
__declspec(dllimport) double d22;//кватернион ОСКП-->ССКП
__declspec(dllimport) double d23;//кватернион ОСКП-->ССКП
__declspec(dllimport) double fix;//интеграл угл. скор. ССКП
__declspec(dllimport) double fiy;//интеграл угл. скор. ССКП
__declspec(dllimport) double fiz;//интеграл угл. скор. ССКП
__declspec(dllimport) long osv2s;//признак освещ. МКС - запомн. знач.
__declspec(dllimport) double tt_ot_puska_pku_s;//время от начала режима - запомн. знач.
__declspec(dllimport) double dts;//скорость сближения ц.м. МКС и ТК - запомн. знач.
__declspec(dllimport) double c1_mas[9];//матрица c1:ВСК-->ССКА в форме одномерного массива
__declspec(dllimport) char prRRST; //признак расстыковки в резервных режимах
__declspec(dllimport) double LenSht;//текущ длина штанги

__declspec(dllimport) double lprx[7]; /* коорд-ты прибора наблюдения в строит системе коор-т АО*/
__declspec(dllimport) double lpry[7]; /*1-для первой зоны,2-второй зоны(ВСК),3-третий зоны    */
__declspec(dllimport) double lprz[7]; /*4-четвертой зоны(ВСК),5-пятой зоны(ЛИ) */
                              /* 6-шестой зоны(ПИ),7-коор. ВТК в строит. сист. коор.*/
__declspec(dllimport) double r1,r2;   //текущие модули радиус-векторов ТК и МКС
__declspec(dllimport) bool MOBIL ;
__declspec(dllimport) bool KOSMO ;
__declspec(dllimport) double OmY4rel_pku,OmZ4rel_pku;//угловые скорости ЛВ относительно МКС в ВСК
__declspec(dllimport) char nroSet;    //заданный с формата ПКУ номер режима ориентации МКС

///////////////// ОЦЕНИВАЕМЫЕ ПАРАМЕТРЫ
__declspec(dllimport)  double ForRatContVlong,ForRatContVSide,
                              ForRatContS,ForRatContSY,ForRatContSZ,
							  ForRatContAlpha,ForRatContGamma,
							  ForRatContOmegaGamma,ForRatContOmegaYZ,ForRatContOmegaY,ForRatContOmegaZ;
__declspec(dllimport) double	stab_vsk_om;//скрость угловая приведения ОСК+Р
__declspec(dllimport) double	stab_vsk_eps;//угловое укорение приведения ОСК+Р
__declspec(dllimport) double	stab_vsk_psi;//угол разворота МКС относительно ВСК
__declspec(dllimport) double	stab_vsk_tet;//угол разворота МКС относительно ВСК
__declspec(dllimport) double	stab_vsk_gam;//угол разворота МКС относительно ВСК
__declspec(dllimport) int stab_ock_nu;//режим стабилизации МКС по НУ
double Ro_t_osuzel;//Проекция отн. скорости ц.м. ТК и МКС на ось стыковочного узла ДК
double    rashod_ryd_man;
double    rashod_ryo_man;
double    rashod_man;
double alpha_rot_ferm; // Угол, на который происходит поворот сегментов ферм P4-P6 и S4-S6

char k_l9b1; //Выбраны ДПО-Б1
char k_l9b2; //Выбраны ДПО-Б2

// Массив точек трассы ТК и МКС (пред, тек и  след) в градусах
double Trassa_tk1[2][100], Trassa_tk2[2][100], Trassa_tk3[2][100];
double Trassa_mks1[2][100], Trassa_mks2[2][100], Trassa_mks3[2][100];
// Подспутниковые точки ТК и МКС
double Dolgota_tk, Shirota_tk, Dolgota_mks, Shirota_mks;
char Priz_Trassa_tk;//признак смены витка трассы ТК
char Priz_Trassa_mks;//признак смены витка трассы МКС
char Update_tk;//признак обновления окна ТК
char Update_mks;//признак обновления окна МКС
char RODK;//признак вкл. RODK
char yd_krodk; //Команда РОДК
char HalfTaktRODK;//признак полутакта RODK
double CIFV_WOB_from_MD[3];//угловая скорость ОСК в проекциях на связанные оси ТПК, рад/с
double MIVK_F_DPO_SUB_for_MD[3][16];//средняя тяга на 16 подтактах 200 мс такта от ДПО, [Н]
double MIVK_M_DPO_SUB_for_MD[3][16];//средний момент на 16 подтактах 200 мс такта от ДПО, [Н*м]
bool RKK;
char nu_otor_switch_svjazka; //Переключатель конфигурации орбитального комплекса // Погорелов 281111
double dx22_AKR; //Вектор отн. дальности (ближайшая АКР МКС-->ц.м.ТК) в ОСКП.
double dy22_AKR; //Вектор отн. дальности (ближайшая АКР МКС-->ц.м.ТК) в ОСКП.
double dz22_AKR; //Вектор отн. дальности (ближайшая АКР МКС-->ц.м.ТК) в ОСКП.
double dt_prich_pku;	//Производная по времени модуля вектора из М2ст в М1ст (в соответствии с тех решением)
double dt_prich_kas;	//Производная по времени модуля вектора из М2ст в М1ст для форм касания
char nsu_for_sivo;	// автоматически рассчитываемый номер узла для СИВО
double dt_vsk_pku;	//Производная по времени модуля вектора из P2 в P1 (центр подложечного креста - фокус ВСК)
double psi22_pku;		//углы ориентации ОСКП->ССКП
double tet22_pku;
double gam22_pku;
char osk_tp_var_trans;	//вариант перехода ОСП-ТП 0-штатный, 1-ускоренный
char osk_tp_reg;			//Признак перехода ОСК-ТП 0-нет, 1-есть
double dWx_osk_tp, dWy_osk_tp, dWz_osk_tp;
char osk_tp_n_subreg[3];	// массив номеров веток-подрежимов внутри режимов ТП
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
char nu_otor_stab;			//	режим стабилизации МКС
char nu_otor_switch_styk_dk;	//	№ СУ, к которому выполняется причаливание
char nu_otor_switch_styk;		//	к которому пристыкован ТК
double nu_com_zapas;			//	запас топлива
char RegType;
double sy_pr;           //промах точки зрения ВСК относительно центра подложки текущего узла для формата "причаливание" в КрСКП, (см)
double sz_pr;           //
double dwy_pr;          //разница угловых скоростей МКС и ТПК в ССКА для формата "причаливание" (градус/с)
double dwz_pr;
unsigned long loc_prks, loc_promah; // признаки касания и промаха для блока обработки ситуации касания          //
double alpha_lamp_mks, beta_lamp_mks;//углы направления оси света управляемого светильника МКС
} m_math;
#endif

