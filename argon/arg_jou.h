#ifndef _ARGJOUHEAD
#define _ARGJOUHEAD
#include "main_header.h"
#include "argon_debug_frm.h"
/*
+------------------------------------------+
| Отправка в журнал стандартного сообщения |
+------------------------------------------+
*/
void ArgJou(AnsiString Cmd){
// Что бы ровно отображался номер
AnsiString zero;
if (arg_deb->ArgonJou->Count<10){
zero = "000"; } else
if (arg_deb->ArgonJou->Count<100){
zero = "00"; } else
if (arg_deb->ArgonJou->Count<1000){
zero = "0"; } else
zero = "";
      arg_deb->ArgonJou->Items->Add(zero+   // Нули перед номером
                      arg_deb->ArgonJou->Count+   // Номер
  "  ["+Now().FormatString("hh.mm.ss.zzz")+"]"+   // Local Time (PC)
                                          "  "+   // Разделитель между Lt и Ot
+"["+OnboardModelTime.FormatString("hh.nn.ss.zzz")+"]"+   // Onboard (model) time from BUM
                                         "   "+   // Разделитель между Ot и Inst
                                            Cmd);   // Команда
arg_deb->ArgonJou->Perform(WM_VSCROLL,
                SB_LINEDOWN,0);                   // Что бы всегда была перемотка вниз
}

#endif /* _ARGJOUHEAD */
 