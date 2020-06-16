// FlySofa.h

#ifdef FLYSOFA_EXPORTS
#define FLYSOFA_API __declspec(dllexport)
#else
#define FLYSOFA_API __declspec(dllimport)
#endif

#include <FlySofaSource\Sofa.h>