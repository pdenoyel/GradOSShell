#include <iostream>
#include <windows.h>

using namespace std;

#if defined(_WIN32)
#define PLATFORM_NAME "windows" // Windows
#elif defined(_WIN64)
#define PLATFORM_NAME "windows" // Windows
#else
#define PLATFORM_NAME "unix"
#endif

int main() {
	cout << "Driver Program\n";
	cout << PLATFORM_NAME;
	if (PLATFORM_NAME == "windows") {
		ShellExecute(NULL, "open", "C:\\WindowsShell.exe", NULL, NULL, SW_SHOWDEFAULT);
	}
	else if (PLATFORM_NAME == "unix") {
		ShellExecute(NULL, "open", "C:\\LinuxShell.exe", NULL, NULL, SW_SHOWDEFAULT);
	}

	return 0;
}