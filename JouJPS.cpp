//---------------------------------------------------------------------------


#pragma hdrstop

#include "JouJPS.h"
#include "JouLogFrm.h"

// NO WORK  !!!!!!!!!!!
// NO USE  !!!!!!!!!!!

/*
+------------------------------------------+
| �������� � ������ ������������ ��������� |
+------------------------------------------+
*/
void JPS(int tm, AnsiString Inst,AnsiString Pol,AnsiString Cmd,AnsiString zn){
// ��� �� ����� ����������� �����
AnsiString zero;
if (JouLogForm->JouLB->Count<10){
zero = "000"; } else
if (JouLogForm->JouLB->Count<100){
zero = "00"; } else
if (JouLogForm->JouLB->Count<1000){
zero = "0"; } else
zero = "";
      JouLogForm->JouLB->Items->AddObject(zero+   // ���� ����� �������
                      JouLogForm->JouLB->Count+   // �����
  "  ["+Now().FormatString("hh.mm.ss.zzz")+"]"+   // Local Time (PC)
                                          "  "+   // ����������� ����� Lt � Ot
                              "[00:00:00.000]"+   // Onboard (model) time from BUM
                                         "   "+   // ����������� ����� Ot � Inst
                                          Inst+   // �������� �������

                                           Pol+   // ���������� ������� (����� ����������)
                                        // "   "+   // ����������� ����� Pol � Cmd
                                           Cmd+   // ������������ (�����������) �������, �� �������� ��� ������� ������������
                                         //"   "+   // ����������� ����� Cmd � zn
                                            zn    // �������� ������� (������, integer, double)
                             ,   (TObject*)tm);   // tm - ���������� �������
JouLogForm->JouLB->Perform(WM_VSCROLL,
                SB_LINEDOWN,0);                   // ��� �� ������ ���� ��������� ����
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
 