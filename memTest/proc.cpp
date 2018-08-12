#include <iostream>
#include "proc.h"


// find proc ID
DWORD getProcID(const wchar_t* pName) {
	DWORD procID = 0;
	HANDLE handleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (handleSnap != 0) {
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(procEntry);

		if (Process32First(handleSnap, &procEntry)) {
			do {
				if (!_wcsicmp(procEntry.szExeFile, pName)) {
					procID = procEntry.th32ProcessID;
					break;
				}
			} while (Process32Next(handleSnap, &procEntry));
		}
	}
}

// get base address of game/process
uintptr_t getModuleBAddress(DWORD, const wchar_t*) {

}

// find the given address in handle
uintptr_t findAddress(HANDLE, uintptr_t, std::vector<unsigned int>) {

}
