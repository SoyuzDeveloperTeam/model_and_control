// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "MDHeaderh.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
// Инициализаци библиотеки
bool MM_init(int signature) {
	int curr_sign = 0x16c4a376;            // Current Signature
	if (curr_sign == signature) return 1; else  // Test Signature
		return 0;
}

bool MM_nu(double vec_tk[3], double vel_tk[3], double vec_iss[3], vel_iss[3]) {
//Верефикаия Начальных условий
}

