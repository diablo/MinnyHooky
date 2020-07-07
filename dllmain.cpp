#include <Windows.h>
#include <iostream>
#include "Utils/Utils.h"
#include "hooks/Hooks.h"


BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
    switch (ul_reason_for_call)
    {
	case DLL_PROCESS_ATTACH: {
		#ifdef _DEBUG
				Utils::Console::AttachConsole("MinnyHooky Debug Console");
		#endif //_DEBUG

		if (auto handle = CreateThread(nullptr, NULL, Hooking::Intialize, hModule, NULL, nullptr))
			CloseHandle(handle);
		break;
	}

    case DLL_PROCESS_DETACH:
		Hooking::Uninitialize();
        break;
    }
    return TRUE;
}

