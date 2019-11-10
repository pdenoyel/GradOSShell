#include <iostream>

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
		cout << "\nLaunching Windows Shell\n";
		system("C:\\Users\\pdeno\\source\\repos\\WindowsShell\\Debug\\WindowsShell.exe");
	}
	else if (PLATFORM_NAME == "unix") {
		cout << "\nLaunching Unix Shell\n";
		system("./LinuxShell");
	}
	system("pause");

	return 0;
}