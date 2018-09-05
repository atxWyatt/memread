// visual studio 2017 used to develop
// this is a memory-reading program that I developed to cheat at videogames (not the bad kind of cheat, just got myself some extra gems in Spyro for fun)
// skills: basic memory-reading with C++, input/output, general oop
// serious use of MSDN here

#include <iostream>
#include <Windows.h>

using namespace std;

int main() {

	int newValue = 2000;
	int readTest = 0;
	HWND hwnd = FindWindowA(NULL, "");
	if (hwnd == NULL) {
		cout << "Cannot find window" << endl;
		Sleep(3000);
		exit(-1);
	}
	else {
		DWORD procID;
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
		if (procID == NULL) {
			cout << "Cannot obtain process" << endl;
			Sleep(3000);
			exit(-1);
		}
		else {
			// write process(handle, (lpvoid)address, &newValue, sizeof(newValue), 0)
			WriteProcessMemory(handle, (LPVOID)0x00ABEA6C, &newValue, sizeof(newValue), 0);

			ReadProcessMemory(handle, (PBYTE*)0x00ABEA6C, &readTest, sizeof(readTest), 0);
			cout << readTest << endl;

		}
	}


	return 0;
}
