#pragma once
#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

typedef double pos[2][3];

// Процедура инициализации Библиотеки
extern "C" MATHLIBRARY_API bool  MM_init(int signature);
extern "C" MATHLIBRARY_API bool  MM_nu(double vec_tk[3],double vel_tk[3],double vec_iss[3], vel_iss[3] );