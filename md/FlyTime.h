// FlyTime.h

#ifdef FLYTIME_EXPORTS
#define FLYTIME_API __declspec(dllexport)
#else
#define FLYTIME_API __declspec(dllimport)
#endif

#include <time.h>
#include <FlyTimeSource\ModTime.h>
#include <FlyTimeSource\TheDataTime.h>
#include <FlyTimeSource\ZTime.h>
#include <FlyTimeSource\TheTimes.h>
#include <FlyTimeSource\TheJD.h>
#include <FlyTimeSource\LeapSeconds.h>