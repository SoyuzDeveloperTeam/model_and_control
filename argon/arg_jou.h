#ifndef _ARGJOUHEAD
#define _ARGJOUHEAD
#include "main_header.h"
#include "argon_debug_frm.h"
/*
+------------------------------------------+
| �������� � ������ ������������ ��������� |
+------------------------------------------+
*/
void ArgJou(AnsiString Cmd){
// ��� �� ����� ����������� �����
AnsiString zero;
if (arg_deb->ArgonJou->Count<10){
zero = "000"; } else
if (arg_deb->ArgonJou->Count<100){
zero = "00"; } else
if (arg_deb->ArgonJou->Count<1000){
zero = "0"; } else
zero = "";
      arg_deb->ArgonJou->Items->Add(zero+   // ���� ����� �������
                      arg_deb->ArgonJou->Count+   // �����
  "  ["+Now().FormatString("hh.mm.ss.zzz")+"]"+   // Local Time (PC)
                                          "  "+   // ����������� ����� Lt � Ot
+"["+OnboardModelTime.FormatString("hh.nn.ss.zzz")+"]"+   // Onboard (model) time from BUM
                                         "   "+   // ����������� ����� Ot � Inst
                                            Cmd);   // �������
arg_deb->ArgonJou->Perform(WM_VSCROLL,
                SB_LINEDOWN,0);                   // ��� �� ������ ���� ��������� ����
}

#endif /* _ARGJOUHEAD */
 