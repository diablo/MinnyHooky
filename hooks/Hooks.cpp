#include "Hooks.h"

void Hooking::Hooks::ExampleHook()
{
	std::cout << "[Hooking] Example hook called" << std::endl;
}

bool Hooking::InitializeHooks()
{
	if (MH_Initialize() != MH_OK) {
		std::cout << "[Hooking] Failed to initialize MH_Initialize." << std::endl;
		return false;
	}

	if (MH_CreateHook(Hooking::Variables::ExampleHookTarget, &Hooking::Hooks::ExampleHook, Hooking::Hooks::ExampleHookOriginal) != MH_OK)
	{
		std::cout << "[Hooking] Failed to initialize example hook";
		return false;
	}

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
		std::cout << "[Hooking] Failed to enable hooks." << std::endl;
		return false;
	}

	std::cout << "[Hooking] Hooks initialized!" << std::endl;
	return true;
}

void Hooking::RemoveHooks()
{
	MH_Uninitialize();
	MH_DisableHook(MH_ALL_HOOKS);
}

unsigned long WINAPI Hooking::Intialize(void* instance)
{
	Hooking::InitializeHooks();
	return true;
}

unsigned long WINAPI Hooking::Uninitialize()
{
	Hooking::RemoveHooks();
	return true;
}