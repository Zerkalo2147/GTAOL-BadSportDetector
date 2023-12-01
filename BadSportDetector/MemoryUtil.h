#ifndef MEMORYUTIL_H
#define MEMORYUTIL_H
#include <windows.h>

class MemoryUtil {
public:
    MemoryUtil();

    static HWND getWindowHwnd();

    static HANDLE getProcessHandle(DWORD* pid);

    static HMODULE getProcessModuleHandle(DWORD pid, CONST TCHAR* moduleName);
};


#endif // MEMORYUTIL_H
