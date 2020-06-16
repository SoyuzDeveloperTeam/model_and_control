// FlyFormat.h

#ifdef FLYFORMAT_EXPORTS
#define FLYFORMAT_API __declspec(dllexport)
#else
#define FLYFORMAT_API __declspec(dllimport)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iterator>
#include <vector>
#include <string>

#include <FlyFormatSource\EdfType.h>
#include <FlyFormatSource\EdfDef.h>
#include <FlyFormatSource\RMoment.h>
#include <FlyFormatSource\RDate.h>
#include <FlyFormatSource\RGradTime.h>
#include <FlyFormatSource\EdfStr.h>

