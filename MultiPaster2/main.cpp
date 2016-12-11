
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <Windows.h>

using std::string;

int main(int argc, char* argv[])
{
	int index = 1;

	while (index < argc)
	{
		if ((GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(0x56)) || index == 1)
		{
			char* output = argv[index];
			std::cout << output << "\n";
			const size_t len = strlen(output) + 1;
			HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
			memcpy(GlobalLock(hMem), output, len);
			GlobalUnlock(hMem);
			OpenClipboard(0);
			EmptyClipboard();
			SetClipboardData(CF_TEXT, hMem);
			CloseClipboard();

			index++;
			Sleep(500);
		}
	}
	return 0;
}
