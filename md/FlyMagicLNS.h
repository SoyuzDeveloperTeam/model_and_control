// FlyMagicLNS.h

#ifdef FLYMAGICLNS_EXPORTS
	#define FLYMAGICLNS_API __declspec(dllexport)
#else
	#define FLYMAGICLNS_API __declspec(dllimport)
#endif

//---------------------------------------------------------------------------
// Компоненты Fly
#include <FlyMMath.h>		// Математические функции
#include <FlyCore.h>		// Ядро модели движения

#include <FlyMagicLNSSource\MagicLNS.h>
#include <FlyMagicLNSSource\MagicSolution.h>