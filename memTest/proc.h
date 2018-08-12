#pragma once
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>

// find proc ID
DWORD getProcID(const wchar_t* );

// get base address of game/process
uintptr_t getModuleBAddress( DWORD, const wchar_t* );

// find the given address in handle
uintptr_t findAddress( HANDLE, uintptr_t, std::vector<unsigned int> );

