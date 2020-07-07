#ifndef HOOKS_H
#define HOOKS_H

#include <stdexcept>
#include <iostream>
#include "../minhook/minhook.h"

namespace Hooking
{
	bool InitializeHooks();
	void RemoveHooks();
	unsigned long WINAPI Intialize(void* instance);
	unsigned long WINAPI Uninitialize();

	namespace Variables
	{
		static auto ExampleHookTarget = reinterpret_cast<void*>(0xDEADBEEF);
	}

	namespace Hooks
	{
		static auto ExampleHookOriginal = nullptr;
		void ExampleHook();
	}
}

#endif //HOOKS_H
