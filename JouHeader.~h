#ifndef _JOUHEADER_H_
#define _JOUHEADER_H_
#include "JouLogFrm.h"
#include "main_header.h"
/*
+------------------------------------------+
| Отправка в журнал стандартного сообщения |
+------------------------------------------+
*/
void JPS(int tm, AnsiString Inst,AnsiString Pol,AnsiString Cmd,AnsiString zn){
// Что бы ровно отображался номер
AnsiString zero;
if (JouLogForm->JouLB->Count<10){
zero = "000"; } else
if (JouLogForm->JouLB->Count<100){
zero = "00"; } else
if (JouLogForm->JouLB->Count<1000){
zero = "0"; } else
zero = "";
      JouLogForm->JouLB->Items->AddObject(zero+   // Нули перед номером
                      JouLogForm->JouLB->Count+   // Номер
  "  ["+Now().FormatString("hh.mm.ss.zzz")+"]"+   // Local Time (PC)
                                          "  "+   // Разделитель между Lt и Ot
+"["+OnboardModelTime.FormatString("hh.nn.ss.zzz")+"]"+   // Onboard (model) time from BUM


                                         "   "+   // Разделитель между Ot и Inst
                                          Inst+   // Источник команды

                                           Pol+   // Получатель команды (пункт назначения)
                                        // "   "+   // Разделитель между Pol и Cmd
                                           Cmd+   // Наименование (расшифровка) команды, ее описание или краткое наименование
                                         //"   "+   // Разделитель между Cmd и zn
                                            zn    // Значение команды (булево, integer, double)
                             ,   (TObject*)tm);   // tm - Подсветка команды
JouLogForm->JouLB->Perform(WM_VSCROLL,
                SB_LINEDOWN,0);                   // Что бы всегда была перемотка вниз
}

#endif /* _JOUHEADER_H_ */
