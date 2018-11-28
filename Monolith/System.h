#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>

class System
{
	HINSTANCE hinstance;
	HWND hwnd;
	LPCWSTR windowClass;

	Input input;
	Graphics graphics;

	bool Frame();
	void InitializeWindow(int& width, int& height);
	void ShutdownWindow();

	LRESULT CALLBACK MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam);
public:
	System();
	~System();

	bool Initialize(HINSTANCE hinstance);
	void Run();
	void Release();
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static System* ApplicationHandle = 0;
