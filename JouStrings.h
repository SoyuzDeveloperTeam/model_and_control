#ifndef JOUSTRINGS
#define JOUSTRINGS
// Strings For Journal
extern "C++" {
// Источики и получатели
static AnsiString is_operator = "Оператор           ";
static AnsiString is_instruct = "Инструктор         ";
static AnsiString is_inpu1    = "ИнПУ 1             ";
static AnsiString is_inpu2    = "ИнПУ 2             ";
static AnsiString is_neptun   = "ОВК               ";
static AnsiString is_sudn     = "СУБК               ";
static AnsiString is_miu      = "МиУ               ";
static AnsiString is_ksp      = "КСП               ";
static AnsiString tj_error    = "Ошибка             ";
static AnsiString is_pu_bps   = "ПУ БПС            ";
static AnsiString is_iss      = "МКС                ";
static AnsiString is_brvi     = "БРВИ              ";
static AnsiString is_irvi     = "ИРВИ              ";
static AnsiString is_prvi     = "ПРВИ              ";
static AnsiString is_brus     = "БРУС              ";
static AnsiString is_argon    = "Аргон              ";
static AnsiString is_kdu      = "КДУ               ";
static AnsiString is_mcc      = "ЦУП-М              ";
static AnsiString is_rud      = "РУД               ";
static AnsiString is_ruo      = "РУО               ";

// Команды
static AnsiString cmd_LoadToArgon = "Загрузка уставок на борт   ";
static AnsiString cmd_DynStart    = "\"Пуск\" Динамики            ";
static AnsiString cmd_DynStop     = "\"Стоп\" Динамики            ";
static AnsiString cmd_loadmiu     = "Загрузка МиУ               ";
static AnsiString cmd_readcmdb    = "Команда с сервера          ";
  // Команды БРВИ
static AnsiString cmd_brvi_error  = "ОШИБКА! БРВИ Выключен!     ";
static AnsiString arg_addr_error  = "Неверный адрес Аргона!";
  // Команды с ПУ БПС
static AnsiString cmd_201 = "Сеть                       \"ВКЛ\"";
static AnsiString cmd_202 = "Сеть                       \"ОТКЛ\"";
static AnsiString cmd_203 = "Переход на резерв          \"ПРМ\"";
static AnsiString cmd_204 = "Переход на резерв          \"ПРД\"";
static AnsiString cmd_205 = "ОДР";
static AnsiString cmd_206 = "Выдача команд              \"ОТКЛ\"";
static AnsiString cmd_207 = "Ручное управление          \"ВКЛ\"";
static AnsiString cmd_208 = "Ручное управление          \"ОТКЛ\"";
static AnsiString cmd_209 = "ПУ БПС                     \"ИСХ\"";
static AnsiString cmd_20A = "БПС                        \"ИСХ\"";
static AnsiString cmd_20B = "Крюки                      \"ОТКР\"";
static AnsiString cmd_20C = "Защелки                    \"ВЫДВ\"";
static AnsiString cmd_20D = "АО ВКА                     \"ОТКР\"";
static AnsiString cmd_20E = "АО ВКА                     \"ЗАКР\"";
static AnsiString cmd_20F = "ДПО                        \"К1\"";
static AnsiString cmd_210 = "ДПО                        \"К2\"";
static AnsiString cmd_211 = "ДПО                        \"К1 2\"";
static AnsiString cmd_212 = "БДУС                       \"1\"";
static AnsiString cmd_213 = "БДУС                       \"2\"";
static AnsiString cmd_214 = "ПРД                        \"ОСН\"";
static AnsiString cmd_215 = "ПРД                        \"РЕЗ\"";
static AnsiString cmd_216 = "ТВ                         \"ВКЛ\"";
static AnsiString cmd_217 = "ТВ                         \"ТВ К СТЫК\"";
static AnsiString cmd_218 = "ТВ                         \"ДИСП\"";
static AnsiString cmd_219 = "ТВ                         \"ТВ ДИСП\"";
static AnsiString cmd_21A = "ТВ                         \"Ф44\"";
static AnsiString cmd_21B = "ТВ                         \"ОТКЛ\"";
static AnsiString cmd_21C = "ТВ Выбор                   \"УУ\"";
static AnsiString cmd_21D = "ТВ Выбор                   \"ШУ\"";
static AnsiString cmd_21E = "ТВ ПЕРЕСВЕТКА              \"ВКЛ\"";
static AnsiString cmd_21F = "ТВ ПЕРЕСВЕТКА              \"ОТКЛ\"";
static AnsiString cmd_220 = "ТВ ФАРА                    \"ВКЛ\"";
static AnsiString cmd_221 = "ТВ ФАРА                    \"ОТКЛ\"";
static AnsiString cmd_222 = "СТЫК МЕХ ПИТАНИЕ           \"ВКЛ\"";
static AnsiString cmd_223 = "СТЫК МЕХ ПИТАНИЕ           \"ОТКЛ\"";
static AnsiString cmd_224 = "СТЫК МЕХ ГОТОВН            \"ВЫДВ\"";
static AnsiString cmd_225 = "СТЫК МЕХ ПИТ ДК            \"ВКЛ\"";
static AnsiString cmd_226 = "ЛПР Питание                \"ВКЛ\"";
static AnsiString cmd_227 = "ЛПР Питание                \"ОТКЛ\"";
static AnsiString cmd_228 = "ЛПР Увод разрешен          \"ВКЛ\"";
static AnsiString cmd_229 = "ЛПР РАЗРЕШ                 \"ОТКЛ\"";
static AnsiString cmd_22A = "ОТВОД +Х                   \"ВКЛ\"";
static AnsiString cmd_22B = "\"Работа\"                   ";
static AnsiString cmd_22C = "Ручки Питание   \"РЕЗ\"      ";
static AnsiString cmd_22D = "Ручки Импульсный Режим \"РУД\"";
static AnsiString cmd_22E = "Ручки Импульсный Режим \"РУО\"";
static AnsiString cmd_22F = "Шифратор        \"РЕЗ\"      ";
static AnsiString cmd_230 = "Тангента        \"ВКЛ\"      ";
  // Команды от Нептуна
static AnsiString cmd_280 = "ВКЛ ВСК ПРИЧАЛ";
static AnsiString cmd_281 = "РО ДК";
static AnsiString cmd_282 = "РО АК";
static AnsiString cmd_283 = "РУД";
static AnsiString cmd_284 = "РУД ИМП";
static AnsiString cmd_285 = "РУО ИМП";
static AnsiString cmd_286 = "Выбор ДПО Б1+Б2";
static AnsiString cmd_287 = "Выбор ДПО-К2";
static AnsiString cmd_288 = "Выбор ДПО-К1";
static AnsiString cmd_289 = "Выбор ДПО К1+К2";
static AnsiString cmd_28A = "ОТБОЙ АПВУ12";
static AnsiString cmd_28B = "СТАБИЛИЗАЦИЯ ОСК";
static AnsiString cmd_28C = "ПОДВОД";
static AnsiString cmd_28D = "ОТВОД";
static AnsiString cmd_28E = "СКД";
static AnsiString cmd_28F = "БДУС 1-1";
static AnsiString cmd_290 = "БДУС 1-2";
static AnsiString cmd_291 = "БДУС 1-3";
static AnsiString cmd_292 = "ВЫБОР БДУС1-1";
static AnsiString cmd_293 = "ВЫБОР БДУС1-2";
static AnsiString cmd_294 = "ВЫБОР БДУС1-3";
static AnsiString cmd_295 = "АО-ВКА";
static AnsiString cmd_296 = "ДИСПЛЕЙ";
static AnsiString cmd_297 = "ДИСПЛЕЙ ТВ";
static AnsiString cmd_298 = "ТВ СТЫК";
static AnsiString cmd_299 = "ШИРОК ОБЪЕКТ УЗК";
static AnsiString cmd_29A = "ПЕРЕСВЕТКА";
static AnsiString cmd_29B = "ФАРА";
static AnsiString cmd_29C = "ПСК ЗАПОМН";
static AnsiString cmd_29D = "ПРИЧАЛ";
static AnsiString cmd_29E = "ПИТ СУДН";
static AnsiString cmd_29F = "ВЫБОР АК";
static AnsiString cmd_2A0 = "ПУСК СУДН";
static AnsiString cmd_2A1 = "ОДР";
static AnsiString cmd_2A2 = "Запрет динам реж";
static AnsiString cmd_2A3 = "ССВП";
static AnsiString cmd_2A4 = "РЕЗЕРВ ССВП";
static AnsiString cmd_2A5 = "Штанга СМ";
static AnsiString cmd_2A6 = "Защёлки";
static AnsiString cmd_2A7 = "Крюки";
static AnsiString cmd_2A8 = "Крышка СКД";
static AnsiString cmd_2A9 = "Курс 1";
static AnsiString cmd_2AA = "Курс 2";
static AnsiString cmd_2AB = "Выкл Курс";
static AnsiString cmd_2AC = "Объедин питание";
static AnsiString cmd_2AD = "Подгот резерв расстык";
static AnsiString cmd_2AE = "Акселерометр";
static AnsiString cmd_2AF = "ПИТ РПВУ";
static AnsiString cmd_2B0 = "ИКВ";
static AnsiString cmd_2B1 = "ВЫБОР ИКВ2";
static AnsiString cmd_2B2 = "ТАНГАЖ – РАЗГОН";
static AnsiString cmd_2B3 = "ТАНГАЖ – ТОРМОЖ";
static AnsiString cmd_2B4 = "ПРОГР3";
static AnsiString cmd_2B5 = "ПРОГР9";
static AnsiString cmd_2B6 = "БЦВК А";
static AnsiString cmd_2B7 = "БЦВК Б";
static AnsiString cmd_2B8 = "БЦВК В";
static AnsiString cmd_2B9 = "БЦВК АБВ";
static AnsiString cmd_2BA = "ЗАПРЕТ РАБОТЫ ПО ПРИЗН";
static AnsiString cmd_2BB = "РАЗВОРОТ";
static AnsiString cmd_2BC = "ТЕКУЩЕЕ ПОЛОЖЕН";
static AnsiString cmd_2BD = "ПОДГОТ РЕЖИМА СТАБИЛ";
static AnsiString cmd_2BE = "Команда КСП";

// Значения
static AnsiString j_ok    = "OK";
static AnsiString j_comp  = "Удачно";
static AnsiString j_no    = "НЕТ";
static AnsiString j_nag   = "Нажата";
static AnsiString j_otg   = "Отжата";

static AnsiString j_ksp   = "КСП    ";

/*
+------------------------+
|    СРОЧНЫЕ АВАРИИ      |
+------------------------+
*/

static AnsiString CA_EMER[16] = {"Отказ ДЗУ III, IV","Отсутствие квитанции СД","Отсутствие резерва","Перерасход","Нарушение режима стабилизации",
"Непрохождение ГК","Индикаторный режим при работе СКД","ЗРП при работе СКД","Отказ ШИ","Переполнение","Повтор РРП при СБЛ / Нет ГСО при вкл КДУ",
"Отказ ПНК","Откл ЧАЙКИ-3 после сцепки","Конец временного цикла","Конец закрутки","Вход в тень"};

/*
+------------------------+
|    ТЕКУЩИЕ АВАРИИ      |
+------------------------+
*/
static AnsiString str_TA_07[16] = {"","Отсутствие СДК по Х", "Отсутствие СДК по Y", "Отсутствие СДК по Z",
"Невкл двиг по Х", "Невкл двиг по Y", "Невкл двиг по Z", "Неоткл двиг по Х", "Неоткл двиг по Y", "Неоткл двиг по Z",
"Непереключение","Залипание СДК по X","Залипание СДК по Y","Залипание СДК по Z","Отказ координатных ДПО","Предполагаемая авария"};
static AnsiString str_TA_08[16] = {"", "Отказ основного ПКНФ-2", "Отказ основного ПКНФ-3", "Длительное отсут ГСО при вкл ДУ",
"Невключение ДУ в ГЦ", "Нештатное выключение ДУ", "Нерасчётное ускорение", "Отказ резерва ПКНФ", "Отказ автоматики СУБК",
"Авария СКД из СУБК", "Невключение ДУ в ЖЦ", "Нарушение режима стабилизации"};
static AnsiString str_TA_09 = "Отказ ДУ";
static AnsiString str_TA_10 = "Авария акселерометра 1";
static AnsiString str_TA_11[16] = {"", "Отказ КУРС", "Нет связи на малой дальности","", "Нет сходимости фильтра", "Отказ АО (уточнить)",
 "Динам неуправл по углам ПК (>5°)","", "Отказ ДПО +X", "Отказ ДПО -X", "Отказ ДПО +Y", "Отказ ДПО -Y", "Отказ ДПО +Z", "Отказ ДПО -Z",
"Недостаточный состав измерений", "Неверные уставки"};


/*
+---------------------+
|    КОМАНДЫ МКС      |
+---------------------+
*/
// Команды ССВП СМ
// Процедуры с формата ССВП +Х
static AnsiString F13_OUG4_3    = "Открытие упоров гнезда СТА \"+Х\"";
static AnsiString F13_ZUG4_7    = "Закрытие  упоров гнезда СТА \"+Х\"";
static AnsiString F13_OKR4_11   = "Открытие крюков  СТА \"+Х\"";
static AnsiString F13_ZKR4_15   = "Закрытие крюков  СТА \"+Х\"";
static AnsiString F13_OPL4_16   = "Открытие переходного люка СТА \"+Х\"";
static AnsiString F13_ZPL4_17   = "Закрытие переходного люка СТА \"+Х\"";

static AnsiString N_ONPSSVP2    = "Включение питания автоматики СС ПрК";
static AnsiString N_OFPSSVP     = "Выключение питания СС ПхО, ПрК.";
static AnsiString N_OPKR        = "Включение ПГС на открытие стыка.";
static AnsiString N_CLKR        = "Включение ПГС на закрытие стыка.";
static AnsiString N_OPUG        = "Включение ПГ на открытие гнезда.";
static AnsiString N_CLUG        = "Включение ПГ на закрытие гнезда.";
static AnsiString D_SSTAUPX     = "Выбор СТА\"+Х\"";
static AnsiString D_OFSSTA      = "Отбой выбора СтА";
static AnsiString N_OPPL        = "Открытие переходного люка СТА \"+Х\"";
static AnsiString N_CLPL        = "Закрытие переходного люка СТА \"+Х\"";

static AnsiString F13_OUG1_0    = "Открытие упоров гнезда СТА \"-Х\"";
static AnsiString F13_ZUG1_4    = "Закрытие  упоров гнезда СТА \"-Х\"";
static AnsiString F13_OKR1_8    = "Открытие крюков  СТА \"-Х\"";
static AnsiString F13_ZKR1_12   = "Закрытие крюков  СТА \"-Х\"";
static AnsiString F13_18        = "Признак \"Приемный конус снят\"";
static AnsiString F13_19        = "Признак установленного на  СТА \"-Х\"  приемного конуса";

static AnsiString N_ONPSSVP1  = "Включение питания автоматики СС ПхО.";
static AnsiString N_OFPSSVPs  = "Выключение питания СС ПхО, ПрК.";
static AnsiString N_OPKRs  = "Включение ПГС на открытие стыка.";
static AnsiString N_CLKRs  = "Включение ПГС на закрытие стыка.";
static AnsiString N_OPUGs  = "Включение ПГ на открытие гнезда.";
static AnsiString N_CLUGs  = "Включение ПГ на закрытие гнезда.";
static AnsiString D_SSTADWX  = "Выбор СТА \"-Х\"";
static AnsiString D_OFSSTAs  = "Отбой выбора СтА";

static AnsiString F13_OUG1_1  = "Открытие упоров гнезда СТА \"-Y\"";
static AnsiString F13_ZUG1_5  = "Закрытие  упоров гнезда СТА \"-Y\"";
static AnsiString F13_OKR1_9  = "Открытие крюков  СТА \"-Y\"";
static AnsiString F13_ZKR1_13  = "Закрытие крюков  СТА \"-Y\"";
static AnsiString F13_18s  = "Признак \"Приемный конус снят\"";
static AnsiString F13_20  = "Признак установленного на  СТА \"-Y\"  приемного конуса";

// Аварии и инструкции для Нептуна
// СРОЧНЫЕ АВАРИИ
static AnsiString nept_sa00 = "отказ ДЗУ III,IV";
static AnsiString nept_sa01 = "отсутствие квитанции СД";
static AnsiString nept_sa02 = "отсутствие резерва";
static AnsiString nept_sa03 = "перерасход";
static AnsiString nept_sa04 = "нарушение режима стабилизации\Неверные уставки для спуска"; // ZUR {25-10-2002}
static AnsiString nept_sa05 = "непрохождение ГК";
static AnsiString nept_sa06 = "индикаторный режим при работе СКД";
static AnsiString nept_sa07 = "ЗРП при работе СКД";
static AnsiString nept_sa08 = "отказ ШИ";
static AnsiString nept_sa09 = "переполнение";
static AnsiString nept_sa10 = "повтор РРП при СБЛ\Нет ГСО при включении КДУ"; // ZUR {31-05-2002} {25-10-2002}
static AnsiString nept_sa11 = "отказ ПНК";
static AnsiString nept_sa12 = "откл \"ЧАЙКИ-3\" после сцепки";
static AnsiString nept_sa13 = "конец временного цикла";
static AnsiString nept_sa14 = "конец закрутки";
static AnsiString nept_sa15 = "вход в тень";

}
#endif
