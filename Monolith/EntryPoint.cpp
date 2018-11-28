#include "UI/Window.h"


int WINAPI wWinMain(HINSTANCE hinstance, HINSTANCE, LPWSTR, int) {
	
	UI::Window window{ hinstance };
	window.Show();

	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}