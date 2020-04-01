/*

  Математические операции с КДУ

*/

#ifndef KduMath
#define KduMath

#include <Math.hpp>
#include <math.h>
static int dhb1[51] = {300-350};
static int data_num_t;
static double data_vtek;
static bool work_st;
static double tk_mass;
static double rash;
static double tpl;
static int e_r = 6371;
static double skd_H;

static struct{
double k;
double V;
}math_nad;

//double F;
static double g_tt;
static double fff = 6.67408; // Гравитационная постоянная
static double e_mass = 5.9742; // Масса земли
static double Rz = 6371;
static double attitude;

static double Wx_data[3];

#endif