#include "Utils.h"

void Utils::Console::AttachConsole(std::string ConsoleName)
{
	AllocConsole();
	freopen_s(reinterpret_cast<FILE**>stdout, "conout$", "w", stdout);
	freopen_s(reinterpret_cast<FILE**>stdin, "conin$", "w", stdin);

	SetConsoleTitleA(ConsoleName.c_str());
}