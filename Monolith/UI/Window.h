#pragma once

#include <Windows.h>


namespace UI {

class Window
{
	const HINSTANCE hinstance;
	HWND handle;

	static LRESULT CALLBACK StaticProc(HWND h, UINT m, WPARAM w, LPARAM l);

	virtual LRESULT OnGotMessage(HWND h, UINT m, WPARAM w, LPARAM l);

public:
	Window(HINSTANCE hinstance);
	~Window();

	HWND GetHandle() const { return handle; }
	void Show();
	void Hide();
};

}