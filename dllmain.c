// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "revorb.h"
#include <stdio.h>
#include <stdlib.h>

BOOL APIENTRY DllMain( HMODULE hModule,
					   DWORD  ul_reason_for_call,
					   LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

#ifdef APP
#ifdef _MSC_VER
#    pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif
#endif 

int main(int argc, char** argv) {
	FILE* inf, * ouf;
	fopen_s(&inf, argv[1], "r+b");
	
	fseek(inf, 0, SEEK_END);
	long size = ftell(inf);
	fseek(inf, 0, SEEK_SET);

	void* inptr = malloc(size);
	fread(inptr, 1, size, inf);
	fclose(inf);

	void* outptr = malloc(1);

	REVORB_FILE inr, our;
	inr.start = inptr;
	inr.cursor = inptr;
	inr.size = size;
	our.start = outptr;
	our.cursor = outptr;
	our.size = 1;

	int result = revorb(&inr, &our);

	fopen_s(&ouf, argv[2], "w+b");
	fwrite(our.start, 1, our.size - 1, ouf);
	fclose(ouf);
}

