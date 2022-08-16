#include <windows.h>
#include <stdio.h>
#include <cstdint>
#include <time.h>

int main()
{
	auto rwx_module = reinterpret_cast<std::uint64_t>(LoadLibraryA("testdll.dll"));
	printf("Loaded Module: 0x%llX\n", rwx_module);

	system("pause");

	PIMAGE_NT_HEADERS ntheader = PIMAGE_NT_HEADERS(rwx_module + PIMAGE_DOS_HEADER(rwx_module)->e_lfanew);
	printf("NTHeaders -> 0x%p\n\n", ntheader);

	printf("Timestamp -> 0x%lX\n", ntheader->FileHeader.TimeDateStamp);

	system("pause");
}
