//-----------------------------------------------------------------------------
// FlyCore.h
// Файл заголовок. Необходим при подключнии ядра модели движения
//
// А. Николенко 25.03.2019
//-----------------------------------------------------------------------------
// В рамках проекта Fly, исключая заимствованный программный код, и код 
// написанный гораздо раньше нсчтоящего проекта, принята следующая нотация
// именования функций и классов... по первым буквам:
//		ZF	- функция,
//		ZC	- класс,
//		ZS	- структура данных, 
//		ZM	- модель, модель может быть как функцией так и классом.
// С первой буквы Z начинаются все составные части проекта написанные 
// непосредственно при разработке проекта Fly.
//-----------------------------------------------------------------------------

#ifdef FLYCORE_EXPORTS
#define FLYCORE_API __declspec(dllexport)
#else
#define FLYCORE_API __declspec(dllimport)
#endif

#pragma warning(disable : 4996)
#pragma warning(disable : 4251)

// Форматирование данных в строку и обратно
#include <FlyCoreSource\ModType.h>
#include <FlyCoreSource\ModSK.h>
#include <FlyCoreSource\ModGlobal.h>
// Программа управления движением центра масс, диспетчер ПУ
#include <FlyCoreSource\ModPUManager.h>		
// Двигательная установка
#include <FlyCoreSource\ZCDU.h>				
// Вычисление характеристик включения ДУ
#include <FlyCoreSource\ZFDUCalc.h>			
// Расчёт астро-данных
#include <FlyCoreSource\ModAstro.h>		
//#include <FlyCoreSource\ZCAlgebraicMDF.h>
//#include <FlyCoreSource\ZCAlgebraicMdfHolder.h>
//#include <FlyCoreSource\ZEOPManager.h>
#include <FlyCoreSource\ZCEopManager.h>
// Документирование результатов моделирования
#include <FlyCoreSource\ZCPrintManager.h>			
// Документирование результатов моделирования
#include <FlyCoreSource\ZCPrintFormat.h>		
// Модель движения
#include <FlyCoreSource\ZMSpaceCraft.h>		
// Механизм вертикального и горизонтального расширения модели
#include <FlyCoreSource\ZCExternalEquations.h>
// Министек для кэширования многократно рассчитываемых на каждом шаге данных
#include <FlyCoreSource\ZCMiniStackKeeper.h>
// Пересчёт фазовых координат между системами отсчёта
#include <FlyCoreSource\ZSK.h>				
// Преобразование НУ в различные СК
#include <FlyCoreSource\ZSKNU.h>	
// Поресчёт ГСК в HBL и обратно
#include <FlyCoreSource\ZHBL.h>
// Создание, запись и чтение УОФ
#include <FlyCoreSource\ZFUofNU01.h>
#include <FlyCoreSource\ZFUofNU50.h>

//----------------------------------------------------------------------------
// Математические функции, векторно-матричные вычисления, 
// операции над матрицами, преобразование величин в 
// другие размерности, "векторизация" кода (использование
// процессорных инструкций семейства SSE и AVX
#define FLY_LINK_MMATH {\
#pragma message ("    Подключение библиотеки FlyMMath...")\
#pragma comment(lib, "FlyMMath.lib")\
}

// Пакет вычислительных процедур переведённых ранее с языка 
// FORTRAN, содержит реализацию некоторых численных алгоритмов
// интерполяции, апроксимации и так далее. Данные программные
// средства были полностью заимствованы в исходных кодах,
// написанных в С++ стандарта 1998 года.
#define FLY_LINK_SSP {\
#pragma message ("    Подключение библиотеки FlySSP...")\
#pragma comment(lib, "FlySSP.lib")\
}

// Библиотека вычислительных процедур, реализующих алгоритмы
// рекомендованные Международным астрономическим союзом и
// отражённых в IERS Convention 2000-2010 г. 
// Вычисление характеристик прецессии, нутации, звёздного
// времени, наклона эклиптики к экватору, учёт секунд
// координации пр расчёте атомного времени и UTC, 
// Преобразования между системами отсчёта ITRF (земная) 
// ICRS (небесная), а также пересчёт в классическую
// систему отсчёта основанную на равноденствии 
// заданной эпохи.
// Исходные коды заимствованы на интернет ресурсе Международной
// службы вращения Земли (IERS), версия от 30.01.2018, и
// собраны без каких бы то ни было изменений.
// Исходные коды написаны в стандарте С++ 1998 года.
#define FLY_LINK_SOFA {\
#pragma message ("    Подключение библиотеки FlySofa...")\
#pragma comment(lib, "FlySofa.lib")\
}

// Простой, краткий и эффективный набор функций для апроксимации
// дискретно заданной вункции алгебраическими полиномами по
// Чебышёву. Тексты процедур были заимствованы и переработаны.
#define FLY_LINK_CHEBYSHOV {\
#pragma message ("    Подключение библиотеки FlyChebyshov...")\
#pragma comment(lib, "FlyChebyshov.lib")\
}

// Набор функций для проектирования орбит.
// ОМИВ, ДУО, ССО, ОСВ
#define FLY_LINK_ORBITDESIGN {\
#pragma message ("    Подключение библиотеки FlyOrbitDesign...")\
#pragma comment(lib, "FlyOrbitDesign.lib")\
}

// Старый волшебник.
// Алгоритмы, реализующие расчёт управления движением центра масс
// при маневрировании на околокруговой орбите, по методу
// узловых точек.
#define FLY_LINK_MAGICLNS {\
#pragma message ("    Подключение библиотеки FlyMagicLNS...")\
#pragma comment(lib, "FlyMagicLNS.lib")\
}

// Ядро модели движения, включающее: интегратор уравнений движения;
// численные модели возмущающих факторов, в том числе, аномалий ГПЗ,
// сопротивления атмосферы, гравитационных возмущений (Луна, Солнце, 
// планеты), световое давление и т.д; механизм документирования 
// результатов прогноза параметров движения;...
#define FLY_LINK_CORE {\
#pragma message ("    Подключение библиотеки FlyCore...")\
#pragma comment(lib, "FlyCore.lib")\
}

// Всё что касается времени:
//		- атомное,
//		- календарное,
//		- UTC, UTC1,
//		- поправка UTC-IAT,
//		- отклонение UTC от UTC1
//		- Дикретное московское
//		- Земное динамическое
#define FLY_LINK_TIME {\
#pragma message ("    Подключение библиотеки FlyTime...")\
#pragma comment(lib, "FlyTime.lib")\
}

// Форматированный вывод данных в строку:
//		- дата
//		- время
//		- дата+время
//		- угловые величины
//		- угловая величина в град+мин+сек
//		- число с плавающей точкой
//		- число с фиксированной точкой
#define FLY_LINK_FORMAT {\
#pragma message ("    Подключение библиотеки FlyFormat...")\
#pragma comment(lib, "FlyFormat.lib")\
}

// Создание ZIP-архивов 
#define FLY_LINK_ZIP {\
#pragma message ("    Подключение библиотеки FlyZip...")\
#pragma comment(lib, "FlyZip.lib")\
}

#define FLY_LINK_ALL {\
FLY_LINK_SSP\
FLY_LINK_SOFA\
FLY_LINK_CHEBYSHOV\
FLY_LINK_ORBITDESIGN\
FLY_LINK_MAGICLNS\
FLY_LINK_CORE\
FLY_LINK_TIME\
FLY_LINK_FORMAT\
FLY_LINK_ZIP\
}

#pragma comment(user, "Copiled on" __DATE__ "at"  __TIME__)
#pragma comment(user, "Автор А. Николенко")
#pragma comment(compiler)


//-----------------------------------------------------------------------------
