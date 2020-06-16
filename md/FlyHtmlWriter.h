// FlyHtmlWriter.h
//-----------------------------------------------------------------------------

#ifdef FLY_HTML_WRITER_EXPORTS
#define FLY_HTML_WRITER_API __declspec(dllexport)
#else
#define FLY_HTML_WRITER_API __declspec(dllimport)
#endif

// Воизбежание глупых предупреждений ... хотя спорно ...
// глупых предупреждений не бывает
#pragma warning(disable : 4251)

#include <FlyHtmlWriterSource\\ZSHtmlAtribute.h>
#include <FlyHtmlWriterSource\\ZСHtmlTeg.h>
#include <FlyHtmlWriterSource\\ZСHtmlItem.h>
#include <FlyHtmlWriterSource\\ZСHtmlCssStyles.h>
#include <FlyHtmlWriterSource\\ZCHtmlBuilder.h>

//-----------------------------------------------------------------------------
// Для подключения библиотеки FlyHtmlWriter.dll к проекту
// прикладной программы необходимо перед включением данного заголовка
// прописать:
//		#define  IMPORT_FLY_HTML_WRITER
//		#include <FlyHtmlWriter.h>
// Сделать нужно это только один раз, только в одном модуле программы.
// Во всех остальных модулях программы писать #includ ... без данного
// #define ...
#ifdef IMPORT_FLY_HTML_WRITER
	//-------------------------------------------------------------------------
	// Математические функции, векторно-матричные вычисления, 
	// операции над матрицами, преобразование величин в 
	// другие размерности, "векторизация" кода (использование
	// процессорных инструкций семейства SSE и AVX
	#pragma message ("    Подключение библиотеки FlyMMath...")
	#pragma comment(lib, "FlyHtmlWriter.lib")
#endif 