//--------------------------------------------------------------------------------
// EdfDef.h
#ifndef EDFDEF_H
#define EDFDEF_H
//--------------------------------------------------------------------------------
#define EdfString string
#define EdfLenghtString(s)(s.length())
#define EdfPointString(s) ((char*)s.c_str())
/*
#ifdef _MFC_VER
	// Только для компиляции с использованием библиотеки MFC
	#define  EdfString CString
	#define  EdfLenghtString( s ) ( s.GetLength( ) )
	#define  EdfPointString( s ) ( ( char* )( const char* )s )
	#define  WM_USER_ WM_USER 
#else
	#ifdef INC_VCL
		// Только для компиляции с использованием библиотеки VCL
		#define  ASSERT assert
		#define  EdfString String
		#define  EdfLenghtString( s ) ( s.Length( ) )
		#define  EdfPointString( s ) ( s.c_str( ) )
		#define  WM_USER_ WM_USER 
	#else
		// Только для компиляции с использованием библиотеки QT
		#include <QString>
		#include <QEvent>
		#define  ASSERT assert
		#define  EdfString QString
		#define  EdfLenghtString( s ) ( s.length( ) )
		#define  EdfPointString( s ) ( ( char* )( ( s.toAscii( ) ).data( ) ) )
		#define  WM_USER_ QEvent::User 
	#endif
#endif
*/
//--------------------------------------------------------------------------------
// Форматы Данных
//--------------------------------------------------------------------------------
#define EDF_NOTFORMAT  0     // Неформатированное поле (просто строка)
// Дата
#define EDF_DMY        1     // День месяц год
#define EDF_DMYHMS     2     // День месяц год Часы минуты секунды
// Время
#define EDF_HMS        3     // Часы минуты секунды
#define EDF_SSSHMS     4     // Сутки Часы минуты секунды
#define EDF_MILLIS     5     // Милисекунды
#define EDF_SEC        6     // Секунды
#define EDF_MIN        7     // Минуты
#define EDF_HOUR       8     // Часы
#define EDF_SSS        9     // Сутки
// Угловая величина
#define EDF_GMS        10    // Градусы минуты секунды
#define EDF_GRAD       11    // Градусы
#define EDF_RAD        12    // Радианы
#define EDF_VITGMS     13    // Виток + Аргумент широты Градусы минуты секунды
#define EDF_VITGRAD    14    // Виток + Аргумент широты Градусы
#define EDF_VITRAD     15    // Виток + Аргумент широты Радианы
// Число
#define EDF_FLOAT      16    // Деиствительное число в форме с плавающей точкой
#define EDF_FIXED      17    // Деиствительное число в форме с фиксированной точкой
// Целочисленные данные
#define EDF_INTEGER    18    // Целое число
#define EDF_YESNO      19    // Бит да  - нет
#define EDF_INSERT     20    // Бит вкл - выкл
#define EDF_01         21    // Бит 0   - 1
#define EDF_CHECK      22    // Бит          // Только для таблицы
#define EDF_CHECKYN    23    // Бит          // Только для таблицы
#define EDF_CHECKCOLOR 24    // Бит          // Только для таблицы
#define EDF_ALT        25    // Выбор альтернативы
//
#define EDF_KEYNU      26    // Ключ НУ        (Номер, тип, модификатор, БЦ)
#define EDF_KEYNUFULL  27    // Полный ключ НУ (КА, номер, тип, модификатор, БЦ)
#define EDF_CUSTOMKEY  28    // Произвольный набор ключей
//
#define EDF_DEFAULT	   6	 // Используется по умолчанию
//--------------------------------------------------------------------------------
// Типы форматов
//--------------------------------------------------------------------------------
#define EDF_TFNOTFORMAT  0        // Неформатированное поле
#define EDF_TFDATA       1        // дата
#define EDF_TFDATATIME   2        // Дата Время
#define EDF_TFTIME       3        // время
#define EDF_TFANGL       4        // угловая величина
#define EDF_TFVITARG     5        // виток аргумент
#define EDF_TFNUMBER     6        // число (не целое)
#define EDF_TFINT        7        // целое
#define EDF_TFBOOL       8        // двоичный тип (да-нет, 0-1)
#define EDF_TFCHECK      9        // двоичный тип (галочка)
#define EDF_TFKEYNU      10       // ключи НУ
#define EDF_TFKEY        11       // Произвольный набор ключей
#define EDF_TFCURRENT    100      // текущий тип данных
//--------------------------------------------------------------------------------
// Варианты проверки данных
//--------------------------------------------------------------------------------
#define EDF_TESTVALIVAR_NEVE   0  // отменить проверку
#define EDF_TESTVALIVAR_EXIT   1  // проверка при выходе из элемента редактирования
#define EDF_TESTVALIVAR_EDIT   2  // проверка корректности в ходе редактирования (при смене текущего поля)
//--------------------------------------------------------------------------------
// Флаги проверки данных
//--------------------------------------------------------------------------------
#define EDF_FTEST_SETFOCUS     1  // Автофокус текущей ошибки 
#define EDF_FTEST_BEEP         2  // АвтоBeep  при ошибке 
#define EDF_FTEST_KILLLEFTZ    4  // Подавление певых нулей 
#define EDF_FTEST_             8  // 
//--------------------------------------------------------------------------------
// Флаги связывания шаблона формата CFormatEdit с элементом редактирования
//--------------------------------------------------------------------------------
#define EDF_BFE_STDCOLOR           1     // задать цвет элемента редактирования подобно цвету жидкокристалческого дисплея
#define EDF_BFE_NOTCHANGENAME      2     // запрет изменения имени параметра при помощи функции "Формат"
#define EDF_BFE_NOTCHANGEHINT      4     // запрет изменения подсказки при помощи функции "Формат"
#define EDF_BFE_NOTCHANGEDEC       8     // запрет изменения точности представления данных при помощи функции "Формат"
#define EDF_BFE_NOTCHANGEFORMAT    16    // запрет изменения формата представления данных при помощи функции "Формат"
#define EDF_BFE_NOTCHANGEVIEW      32    // запрет изменения внешнего вида представления данных при помощи функции "Формат"
#define EDF_BFE_NOTCHANGEALL       64    //
#define EDF_BFE_NOTEDITFORMAT      128   // запрет использования функции "Формат"
#define EDF_BFE_NOTUSERCALC        256   // запрет использования функции "Калькулятор"
#define EDF_BFE_NOTUSERSELDATA     512   // запрет использования функции "Календарь"
#define EDF_BFE_USERLIST           1024  // Признак запроса у родительского окна пользовательского каталога (WM_USER_EDF_SELECTLIST)
#define EDF_BFE_USERVIEW           2048  // Признак запроса у родительского окна просмотра содержимого элемента редактирования (WM_USER_EDF_VIEWDATA)
#define EDF_BFE_USERVALUETESTING   4096  // Признак запроса у родительского окна проверки корректности значения (WM_USER_EDF_VALUETESTING)
//--------------------------------------------------------------------------------
// Флаги связывания шаблона формата CFormatGrid с таблицей
//--------------------------------------------------------------------------------
#define EDF_BFG_FORMATFROMROW          1          // Форматировать таблицу по строкам (только для Grid)

#define EDF_BFG_AUTOROWSIZE            2          // Автоматически подбирать высоту строк в соответствии с текущим шрифтом
#define EDF_BFG_AUTOCOLSIZE            4          // Автоматически подбирать ширину столбцов в соответствии с текущим шрифтом
#define EDF_BFG_AUTOFIXEDUPPSIZE       8          // Автоматически подбирать ширину столбцов по заголовку фиксированных строк в соответствии с текущим шрифтом
#define EDF_BFG_AUTOFIXEDLEFTSIZE      16         // Автоматически подбирать ширину левых фиксированных столбцов по заголовку в соответствии с текущим шрифтом
#define EDF_BFG_AUTOLSCOLSIZE          32         // Автоматически сохранять и восстанавливать ширину столбцов
#define EDF_BFG_AUTOLSFIELDINDEX       64         //
#define EDF_BFG_AUTOSIZEJUSTUS         128        // Подбирать ширину всех столбцов точно по размеру текста

#define EDF_BFG_SIZECOLUMNALLCLIENT    256        // Подбирать ширину столбцов в соответствии с размером окна
#define EDF_BFG_MINSIZECOLUMNFROMHIDER 512        // Подбирать ширину столбцов в соответствии с размером окна

#define EDF_BFG_MOVEDFIELD             1024       //
#define EDF_BFG_MOVEDITEM              2048       //

#define EDF_BFG_NOTSELRANGE            4096       // Запрет на выделение диапазона
#define EDF_BFG_NOTSELCLICKFIELD       8192       // Запрет на выделение поля кликом на заголовке поля
#define EDF_BFG_NOTSELCLICKITEM        16384      // Запрет на выделение записи кликом на заголовке записи

#define EDF_BFG_READONLY               32768      // Таблица доступна только по чтению
#define EDF_BFG_GRAYREADONLY           65536      // Отображать ячейки доступные только по чтению цветом формы

#define EDF_BFG_FLATFIXED              131072     // Фиксированные ячейки отображать плоскими
#define EDF_BFG_ADGECELL               262144     // Значащие ячейки таблицы прорисовывать слегка вдавленными
#define EDF_BFG_INVERTFOCUSRECT        524288     // Рамку фокуса ввода отображать цветом инвертированного фона ячейки
#define EDF_BFG_NOTHIDEFOCUSRECT       1048576    // Отображать рамку фокуса ввода при поиере такового
#define EDF_BFG_NOTHIDESELECT          2097152    // Отображать выделенный фрагмент при потере фокуса ввода
#define EDF_BFG_RIGHTCOLFULLCLIENT     4194304    // Ширина правой колонки подбирается таким образом чтобы заполнить вся клиентскую часть окна

#define EDF_BFG_VIEWZOOM               8388608    // Изменение масштаба представления данных
#define EDF_BFG_EMPTYZEROSTRING        16777216   // Отображать нулевые данные в виде пустой строки
#define EDF_BFG_STRETCHBMP             33554432   // Масштабирование графических образов
#define EDF_BFG_LIKEFIXEDASFIXED       67108864   // Отображать ячейки со свойствой LikeFixed ка фиксированные ячейки
#define EDF_BFG_LIGHTFOCUSCOLROW       134217728  // Подсветка строки и колонки которые находятся в фокусе ввода
#define EDF_BFG_LIGHTMOUSECOLROW       268435456  // Подсветка строки и колонки под мышью
#define EDF_BFG_ITEMFULLSELECT         536870912  // Выделение Записи целиком (несовместим с EDF_BFG_FIELDFULLSELECT)
#define EDF_BFG_FIELDFULLSELECT        1073741824 // Выделение Поля целиком   (несовместим с EDF_BFG_ITEMFULLSELECT)
#define EDF_BFG_CHECKSELECT            2147483648 // Выделение нескольких записей или полей
//--------------------------------------------------------------------------------
// Признаки наличия свойств
//--------------------------------------------------------------------------------
#define ON     1  // Включено 
#define OFF    0  // Выключено
//--------------------------------------------------------------------------------
// Стили шрифта для таблицы              
//--------------------------------------------------------------------------------
#define EDF_GFONTSTYLE_BOLD     1
#define EDF_GFONTSTYLE_ITALIC   2
#define EDF_GFONTSTYLE_UNDERL   4
#define EDF_GFONTSTYLE_STRIKE   8
//
#define EDF_FONT_BOLD               1     // Жирный 
#define EDF_FONT_ITALIC             2     // Наклонный
#define EDF_FONT_UNDER_LINE         4     // Подчёркнутый
#define EDF_FONT_STRIKE             8     // Зачёркнутый
#define EDF_FONT_BOLD_NOTSET        128   // Жирный        (не задан)
#define EDF_FONT_ITALIC_NOTSET      256   // Наклонный     (не задан) 
#define EDF_FONT_UNDER_LINE_NOTSET  512   // Подчёркнутый  (не задан)
#define EDF_FONT_STRIKE_NOTSET      1024  // Зачёркнутый   (не задан)
//
#define EDF_FONT_SIZE_ADDIN         16    // Размер шрифта имеет смысл поправки к текущему разиеру
//--------------------------------------------------------------------------------
// Выравнивание столбцов
//--------------------------------------------------------------------------------
#define EDF_GCOLALIGN_DEFAULT   0    //
#define EDF_GCOLALIGN_LEFT      0    //
#define EDF_GCOLALIGN_RIGHT     1    //
#define EDF_GCOLALIGN_CENTER    2    //
#define EDF_GCOLALIGN_NOTSET    127  //
//--------------------------------------------------------------------------------
#define EDF_PROPERTY_NOTSET     127  //
#define EDF_COLOR_NOTSET        0x80000000 //
//--------------------------------------------------------------------------------
// Уровень доступа для редактирования
//--------------------------------------------------------------------------------
#define EDF_GEDIT_ENABLE        0    //
#define EDF_GEDIT_DISABLE       1    //
#define EDF_GEDIT_READONLY      1    //
//--------------------------------------------------------------------------------
// Возможность выбора ячейки
//--------------------------------------------------------------------------------
#define EDF_GNOTCANSEL_DISABLE  0    //
#define EDF_GNOTCANSEL_ENABLE   1    //
#define EDF_GNOTCANSEL_NOTSET   2    //
//--------------------------------------------------------------------------------
// Создание ячеек подобных фиксированным
//--------------------------------------------------------------------------------
#define EDF_GFIXEDLIKE_ON       0    //
#define EDF_GFIXEDLIKE_OFF      1    //
#define EDF_GFIXEDLIKE_NOTSET   2    //
//--------------------------------------------------------------------------------
// Вид рамки
//--------------------------------------------------------------------------------
#define EDF_GADGE_NORMAL        0    //
#define EDF_GADGE_UPP           1    //
#define EDF_GADGE_DOWN          2    //
#define EDF_GADGE_LOW_UPP       3    //
#define EDF_GADGE_LOW_DOWN      4    //
#define EDF_GADGE_NOTSET        127  //
//--------------------------------------------------------------------------------
// Use this as the classname when inserting this control as a custom control
// in the MSVC++ dialog editor
//--------------------------------------------------------------------------------
#define EDF_EDIT_VCCTRL_CLASSNAME    _T("CFormatEdit")    // Window class name
#define EDF_GRID_VCCTRL_CLASSNAME    _T("CFormatGrid")    // Window class name
#define EDF_GRIDEX_VCCTRL_CLASSNAME  _T("CFormatGridEx")  // Window class name
#define EDF_LIST_VCCTRL_CLASSNAME    _T("CFormatList")    // Window class name
#define EDF_CUST_VCCTRL_CLASSNAME    _T("CFormatCustom")  // Window class name
#define IDC_INPLACE_EDIT             99                   // ID of inplace edit controls
#define IDC_INPLACE_COMBO            100                  // ID of inplace combobox controls
//--------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------
#define EDF_GRID_COL_W_DEF      72     // Стандартная щирина столбца в пункиах
#define EDF_GRID_ROW_H_DEF      12     // Стандартная высота строки в пункиах
#define EDF_GRID_W_INDENT_PIXEL 2      // Стандартный отступ от границы ячейки
#define EDF_GRID_H_INDENT_PIXEL 1      // Стандартный отступ 
//--------------------------------------------------------------------------------
// Стиль рамки окна таблицы
//--------------------------------------------------------------------------------
#define EDF_GRID_BS_CLIENT      1
#define EDF_GRID_BS_STATIC      2
#define EDF_GRID_BS_MODAL       4
//--------------------------------------------------------------------------------
// Флаги смещение записей и полей по таблице на заданное число едениц
// используются при вызове TravelItems, TravelFields, RemoveItems,
// RemoveFields, InsertItems, InsertFields
//--------------------------------------------------------------------------------
#define EDF_TRAVEL_FREESETEMPTY       1    // заполнение освободившися записей пустыми строками
#define EDF_TRAVEL_FREESETZERO        2    // заполнение освободившися записей нулевыми значениями
#define EDF_TRAVEL_WITHFIXED          4    // сдвиг вместе с фиксированными ячейками
#define EDF_TRAVEL_FREESETENPTYFIXED  8    // заполнение освободившися фиксированных ячеек пустыми строками
#define EDF_TRAVEL_WITHATRIBUTS       16   // сдвиг вместе со свойствами записей и ячеек
#define EDF_TRAVEL_FREEATRIBUTSREMOVE 32   // удаление всех свойств у освободившихся записей
#define EDF_TRAVEL_FREEFORMATREMOVE   64   // удаление формата у освободившихся полей (поле становится строковым)
#define EDF_TRAVEL_WITHWIDTH          256  // перемещать столбцы с сохранением их ширины
#define EDF_TRAVEL_ONLIINRANGE        512  // Перестановки только внутри указанного диапазона
#define EDF_TRAVEL_STDFROMITEMS       1 | 4 | 8 | 16 | 32 | 256
#define EDF_TRAVEL_STDFROMFIELDS      1 | 4 | 8 | 16 | 32 | 64 | 256
//--------------------------------------------------------------------------------
// Флаги задания свойств формата чарез CGridFieldProperty
//--------------------------------------------------------------------------------
#define EDF_GFP_Interval            1    // Установить свойство Interval
#define EDF_GFP_Sign                2    // Установить свойство Sign
#define EDF_GFP_NotShowSign         4    // Установить свойство NotShowSign
#define EDF_GFP_FixedFields         8    // Установить свойство FixedFields
#define EDF_GFP_FixedFirstField     16   // Установить свойство FixedFirstField
#define EDF_GFP_FixedLastField      32   // Установить свойство FixedLastField
#define EDF_GFP_NotInterval         64   // Удалить свойство    Interval
#define EDF_GFP_NotSign             128  // Удалить свойство    Sign
#define EDF_GFP_NotNotShowSign      256  // Удалить свойство    NotShowSign
#define EDF_GFP_NotFixedFields      512  // Удалить свойство    FixedFields
#define EDF_GFP_NotFixedFirstField  1024 // Удалить свойство    FixedFirstField
#define EDF_GFP_NotFixedLastField   2048 // Удалить свойство    FixedLastField
//--------------------------------------------------------------------------------
// Текстовый идентификатор формата буфера обмена
//--------------------------------------------------------------------------------
#define EDF_CLIPBOARD_EDIT_KEY  "Format EditBox  for Clipboard"
#define EDF_CLIPBOARD_GRID_KEY  "Format GridLine for Clipboard"
//--------------------------------------------------------------------------------
// Идентификаторы сообщений
//--------------------------------------------------------------------------------
// Для CFormatEdit
#define WM_USER_EDF_FIRST             ( WM_USER_ + 500 )
// Посылается в родительское окно при необходимости выбора из каталога (нажата F5)
#define WM_USER_EDF_SELECTLIST        WM_USER_EDF_FIRST
// Посылается в родительское окно при необходимости подробного просмотра данных (нажата F4)
#define WM_USER_EDF_VIEWDATA          ( WM_USER_EDF_FIRST + 1 )
// Посылается в родительское окно при необходимости обновления команд в Popup меню
#define WM_USER_EDF_UPDATE_SELECTLIST ( WM_USER_EDF_FIRST + 2 )
#define WM_USER_EDF_UPDATE_VIEWDATA   ( WM_USER_EDF_FIRST + 3 )
// Посылается при изменении числового значания в элементе редактирования
#define WM_USER_EDF_CHANGEVALUE       ( WM_USER_EDF_FIRST + 4 )
//
#define WM_USER_EDF_VALUETESTING      ( WM_USER_EDF_FIRST + 5 )
#define WM_USER_EDF_GRID_UPDATE_CW    ( WM_USER_EDF_FIRST + 6 )   // Только для CB
//--------------------------------------------------------------------------------
// Для CFormatGrid, CFormatList
//--------------------------------------------------------------------------------
// WPARAM WParam = MAKEWPARAM( Field, Item )  
// LPARAM LParam =( LPARAM )IDD_xxx 
// Посылается при изменении числового значания в ячеейки таьлицы
#define WM_USER_EDF_GRID_CHANGEVALUE  ( WM_USER_EDF_FIRST + 10 )
#define WM_USER_EDF_CELLCHANGEVALUE   WM_USER_EDF_GRID_CHANGEVALUE
// Посылается при начале редактирования ячейки
#define WM_USER_EDF_GRID_EDITSTART    ( WM_USER_EDF_FIRST + 11 )
#define WM_USER_EDF_CELLEDITSTART     WM_USER_EDF_GRID_EDITSTART
// Посылается при завершении редактирования ячейки
#define WM_USER_EDF_GRID_EDITEND      ( WM_USER_EDF_FIRST + 12 )
#define WM_USER_EDF_CELLEDITEND       WM_USER_EDF_GRID_EDITEND
// Посылается при изменени текущей ячейки
#define WM_USER_EDF_GRID_SELCHANGE    ( WM_USER_EDF_FIRST + 13 )
#define WM_USER_EDF_CELLCHANGESEL     WM_USER_EDF_GRID_SELCHANGE
// Посылается при поступлении сообщения от мыши
// WPARAM WParam = &EdfMessage
// LPARAM LParam =( LPARAM )IDD_xxx
#define WM_USER_EDF_GRID_MOUSE        ( WM_USER_EDF_FIRST + 14 )
// Посылается при поступлении сообщения от клавиатуры
#define WM_USER_EDF_GRID_KEYS         ( WM_USER_EDF_FIRST + 15 )
// Посылается при прорисовки ячейки
#define WM_USER_EDF_GRID_PAINT        ( WM_USER_EDF_FIRST + 16 )
// Посылается при click-е на ячейке если она является кнопкой
#define WM_USER_EDF_GRID_BTN_CLICK    ( WM_USER_EDF_FIRST + 17 )
// Была отмечена запись в списке (CheckSelect-Type)
//  EdfMessage* M = ( EdfMessage )WParam ;
//	M->Message = WM_USER_EDF_GRID_CHECKITEM ;
//	M->wParam  = isCheck ;
//	M->lParam  = ( LPARAM )A->m_ID ;
//	M->Field   = 0 ;
//	M->Item    = Item ;
#define WM_USER_EDF_GRID_CHECKITEM    ( WM_USER_EDF_FIRST + 18 )
//--------------------------------------------------------------------------------
// Дополнительные комманды всплывающего меню
#define WM_USER_EDF_COMMAND1          ( WM_USER_EDF_FIRST + 20 )
#define WM_USER_EDF_COMMAND2          ( WM_USER_EDF_FIRST + 21 )
#define WM_USER_EDF_COMMAND3          ( WM_USER_EDF_FIRST + 22 )
#define WM_USER_EDF_COMMAND4          ( WM_USER_EDF_FIRST + 23 )
#define WM_USER_EDF_COMMAND5          ( WM_USER_EDF_FIRST + 24 )
#define WM_USER_EDF_COMMAND6          ( WM_USER_EDF_FIRST + 25 )
#define WM_USER_EDF_COMMAND7          ( WM_USER_EDF_FIRST + 26 )
#define WM_USER_EDF_COMMAND8          ( WM_USER_EDF_FIRST + 27 )
#define WM_USER_EDF_COMMAND9          ( WM_USER_EDF_FIRST + 28 )
#define WM_USER_EDF_COMMAND10         ( WM_USER_EDF_FIRST + 29 )
#define WM_USER_EDF_COMMAND11         ( WM_USER_EDF_FIRST + 30 )
#define WM_USER_EDF_COMMAND12         ( WM_USER_EDF_FIRST + 31 )
#define WM_USER_EDF_COMMAND13         ( WM_USER_EDF_FIRST + 32 )
#define WM_USER_EDF_COMMAND14         ( WM_USER_EDF_FIRST + 33 )
#define WM_USER_EDF_COMMAND15         ( WM_USER_EDF_FIRST + 34 )
#define WM_USER_EDF_COMMAND16         ( WM_USER_EDF_FIRST + 35 )
#define WM_USER_EDF_COMMAND17         ( WM_USER_EDF_FIRST + 36 )
#define WM_USER_EDF_COMMAND18         ( WM_USER_EDF_FIRST + 37 )
#define WM_USER_EDF_COMMAND19         ( WM_USER_EDF_FIRST + 38 )
#define WM_USER_EDF_COMMAND20         ( WM_USER_EDF_FIRST + 39 )
#define WM_USER_EDF_COMMAND21         ( WM_USER_EDF_FIRST + 40 )
#define WM_USER_EDF_COMMAND22         ( WM_USER_EDF_FIRST + 41 )
#define WM_USER_EDF_COMMAND23         ( WM_USER_EDF_FIRST + 42 )
#define WM_USER_EDF_COMMAND24         ( WM_USER_EDF_FIRST + 43 )
#define WM_USER_EDF_COMMAND25         ( WM_USER_EDF_FIRST + 44 )
#define WM_USER_EDF_COMMAND26         ( WM_USER_EDF_FIRST + 45 )
#define WM_USER_EDF_COMMAND27         ( WM_USER_EDF_FIRST + 46 )
#define WM_USER_EDF_COMMAND28         ( WM_USER_EDF_FIRST + 47 )
#define WM_USER_EDF_COMMAND29         ( WM_USER_EDF_FIRST + 48 )
#define WM_USER_EDF_COMMAND30         ( WM_USER_EDF_FIRST + 49 )
//--------------------------------------------------------------------------------
// Update для Дополнительных комманд всплывающего меню
#define WM_USER_EDF_UPDATE_COMMAND1   ( WM_USER_EDF_FIRST + 50 )
#define WM_USER_EDF_UPDATE_COMMAND2   ( WM_USER_EDF_FIRST + 51 )
#define WM_USER_EDF_UPDATE_COMMAND3   ( WM_USER_EDF_FIRST + 52 )
#define WM_USER_EDF_UPDATE_COMMAND4   ( WM_USER_EDF_FIRST + 53 )
#define WM_USER_EDF_UPDATE_COMMAND5   ( WM_USER_EDF_FIRST + 54 )
#define WM_USER_EDF_UPDATE_COMMAND6   ( WM_USER_EDF_FIRST + 55 )
#define WM_USER_EDF_UPDATE_COMMAND7   ( WM_USER_EDF_FIRST + 56 )
#define WM_USER_EDF_UPDATE_COMMAND8   ( WM_USER_EDF_FIRST + 57 )
#define WM_USER_EDF_UPDATE_COMMAND9   ( WM_USER_EDF_FIRST + 58 )
#define WM_USER_EDF_UPDATE_COMMAND10  ( WM_USER_EDF_FIRST + 59 )
#define WM_USER_EDF_UPDATE_COMMAND11  ( WM_USER_EDF_FIRST + 60 )
#define WM_USER_EDF_UPDATE_COMMAND12  ( WM_USER_EDF_FIRST + 61 )
#define WM_USER_EDF_UPDATE_COMMAND13  ( WM_USER_EDF_FIRST + 62 )
#define WM_USER_EDF_UPDATE_COMMAND14  ( WM_USER_EDF_FIRST + 63 )
#define WM_USER_EDF_UPDATE_COMMAND15  ( WM_USER_EDF_FIRST + 64 )
#define WM_USER_EDF_UPDATE_COMMAND16  ( WM_USER_EDF_FIRST + 65 )
#define WM_USER_EDF_UPDATE_COMMAND17  ( WM_USER_EDF_FIRST + 66 )
#define WM_USER_EDF_UPDATE_COMMAND18  ( WM_USER_EDF_FIRST + 67 )
#define WM_USER_EDF_UPDATE_COMMAND19  ( WM_USER_EDF_FIRST + 68 )
#define WM_USER_EDF_UPDATE_COMMAND20  ( WM_USER_EDF_FIRST + 69 )
#define WM_USER_EDF_UPDATE_COMMAND21  ( WM_USER_EDF_FIRST + 70 )
#define WM_USER_EDF_UPDATE_COMMAND22  ( WM_USER_EDF_FIRST + 71 )
#define WM_USER_EDF_UPDATE_COMMAND23  ( WM_USER_EDF_FIRST + 72 )
#define WM_USER_EDF_UPDATE_COMMAND24  ( WM_USER_EDF_FIRST + 73 )
#define WM_USER_EDF_UPDATE_COMMAND25  ( WM_USER_EDF_FIRST + 74 )
#define WM_USER_EDF_UPDATE_COMMAND26  ( WM_USER_EDF_FIRST + 75 )
#define WM_USER_EDF_UPDATE_COMMAND27  ( WM_USER_EDF_FIRST + 76 )
#define WM_USER_EDF_UPDATE_COMMAND28  ( WM_USER_EDF_FIRST + 77 )
#define WM_USER_EDF_UPDATE_COMMAND29  ( WM_USER_EDF_FIRST + 78 )
#define WM_USER_EDF_UPDATE_COMMAND30  ( WM_USER_EDF_FIRST + 79 )
//--------------------------------------------------------------------------------
// Base Popup menu
#define WM_EDF_GRID_FULL_SCREEN       ( WM_USER_EDF_FIRST + 80 )
#define WM_EDF_GRID_COPY              ( WM_USER_EDF_FIRST + 81 )
#define WM_EDF_GRID_CUT               ( WM_USER_EDF_FIRST + 82 )
#define WM_EDF_GRID_PASTE             ( WM_USER_EDF_FIRST + 83 )
#define WM_EDF_GRID_DELETE            ( WM_USER_EDF_FIRST + 84 )
//
#define WM_EDF_GRID_COPY_STR          ( WM_USER_EDF_FIRST + 85 )
#define WM_EDF_GRID_PASTE_STR         ( WM_USER_EDF_FIRST + 86 )
//
#define WM_EDF_GRID_LINE_CUT          ( WM_USER_EDF_FIRST + 87 )
#define WM_EDF_GRID_LINE_PASTE        ( WM_USER_EDF_FIRST + 88 )
#define WM_EDF_GRID_LINE_DELETE       ( WM_USER_EDF_FIRST + 89 )
//--------------------------------------------------------------------------------
#define WM_USER_EDF_GRID_FIRST        WM_USER_EDF_GRID_CHANGEVALUE
#define WM_USER_EDF_GRID_LAST         WM_EDF_GRID_LINE_DELETE     
#define WM_USER_EDF_LAST              WM_USER_EDF_GRID_LAST
//--------------------------------------------------------------------------------
#endif // NEFORMATDEF_H      AnsiString

