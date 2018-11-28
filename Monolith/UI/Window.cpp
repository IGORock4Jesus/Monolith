#include "Window.h"

namespace UI {

Window::Window(HINSTANCE hinstance)
	:hinstance{ hinstance }
{
	WNDCLASS wc{ 0 };
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hInstance = hinstance;
	wc.lpfnWndProc = StaticProc;
	wc.lpszClassName = L"MONO WINDOW";
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wc);

	handle = ::CreateWindow(L"MONO WINDOW", L"MONO", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, HWND_DESKTOP, nullptr, hinstance, this);
}


Window::~Window()
{
	//CloseHandle(handle);
}

void Window::Show()
{
	ShowWindow(handle, SW_NORMAL);
}

void Window::Hide()
{
	ShowWindow(handle, SW_HIDE);
}

LRESULT Window::StaticProc(HWND h, UINT m, WPARAM w, LPARAM l)
{
	if (m == WM_NCCREATE) {
		auto create = (LPCREATESTRUCT)l;
		::SetWindowLongPtr(h, GWLP_USERDATA, (LONG_PTR)create->lpCreateParams);
		return TRUE;
	}
	else {
		auto window = (Window*)::GetWindowLongPtr(h, GWLP_USERDATA);
		if (window)
			return window->OnGotMessage(h, m, w, l);
	}
	return LRESULT(0);
}

LRESULT Window::OnGotMessage(HWND h, UINT m, WPARAM w, LPARAM l)
{
	switch (m)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(h, m, w, l);
	}
}
}