#ifndef FLY_MODEL
#define FLY_MODEL
//---------------------------------------------------------------------------

#pragma hdrstop

#include "fly_model.h"
#include "math.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

int TaskTimePrediction();		// ������� � �������� ����� �� �������

//int chek_nu(ZNU NU){
  // �������� �� �� ����������� ���� ������ - ��������� - 0
  // ������ �� ����� 500 �� � �.�. ����� ���������� ������������ ���������� ��������� ����.
//}

double ikv_TwoAlpha(double H){
 // H - ������ ������ ��
 // hr - ������ ��-�������� 15 ��
 // Rz - ������ �����
 double hr = 15, Rz = 6371;
 double A2;
 A2 = asin(Rz+hr/Rz+H);
 return A2;
}

#endif
