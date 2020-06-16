// FlyZip.h

#ifdef FLYZIP_EXPORTS
#define FLYZIP_API __declspec(dllexport)
#else
#define FLYZIP_API __declspec(dllimport)
#endif

#include <FlyZipSource\Zip.h>
