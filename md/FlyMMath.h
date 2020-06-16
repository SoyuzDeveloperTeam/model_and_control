// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the FLYMMATH_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// FLYMMATH_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef FLYMMATH_EXPORTS
#define FLYMMATH_API __declspec(dllexport)
#else
#define FLYMMATH_API __declspec(dllimport)
#endif

#pragma warning(disable : 4251)

#include <FlyMMathSource\MMathDef.h>
#ifdef __cplusplus
	#include <FlyMMathSource\MMath.h>		// Элементарные математические функции и операции
											// над векторами и матрицами 
	#include <FlyMMathSource\MBuildSPO.h>	// Проектирование специальных орбит (ОМИВ, ССО, ДУ)
	#include <FlyMMathSource\MQuaternion.h> // Кватеринионы
	#include <FlyMMathSource\CalcFurie.h>	// Разложение в ряд фурье
#endif

