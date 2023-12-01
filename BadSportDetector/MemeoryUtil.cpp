#include "MemoryUtil.h"
#include <Tlhelp32.h>
#include <tchar.h>

MemoryUtil::MemoryUtil()
{
}

HWND MemoryUtil::getWindowHwnd()
{
    return FindWindow(NULL, L"Grand Theft Auto V");
}

HANDLE MemoryUtil::getProcessHandle(DWORD* pid)
{
    HWND hWindow = getWindowHwnd(); // 获取窗口句柄
    GetWindowThreadProcessId(hWindow, pid); // 获取进程id
    return OpenProcess(PROCESS_ALL_ACCESS, FALSE, *pid); // 打开进程
}

HMODULE MemoryUtil::getProcessModuleHandle(DWORD pid, const TCHAR* moduleName)
{
    MODULEENTRY32 moduleEntry;
    HANDLE handle = NULL;
    handle = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid); //  获取进程快照中包含在th32ProcessID中指定的进程的所有的模块。
    if (!handle) {
        CloseHandle(handle);
        return NULL;
    }
    ZeroMemory(&moduleEntry, sizeof(MODULEENTRY32));
    moduleEntry.dwSize = sizeof(MODULEENTRY32);
    if (!Module32First(handle, &moduleEntry)) {
        CloseHandle(handle);
        return NULL;
    }
    do {
        if (_tcscmp(moduleEntry.szModule, moduleName) == 0) {
            return moduleEntry.hModule;
        }
    } while (Module32Next(handle, &moduleEntry));
    CloseHandle(handle);
    return 0;
}
