// WindowsProject1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
//#include "WindowsProject1.h"

#include <windows.h>
#include <d2d1.h>
#pragma comment(lib, "d2d1")

#include "basewin.h"
#include "shape/Circle.h"
#include "shape/Rect.h"

#include "shape/zf_log.h"

static void custom_output_callback(const zf_log_message *msg, void *arg)
{
	*msg->p = 0;
	OutputDebugStringA(msg->buf);
}

// zf_log

template <class T> void SafeRelease(T **ppT)
{
	if (*ppT)
	{
		(*ppT)->Release();
		*ppT = NULL;
	}
}

class MainWindow : public BaseWindow<MainWindow>
{
	ID2D1Factory            *pFactory;
	ID2D1HwndRenderTarget   *pRenderTarget;

	HRESULT CreateGraphicsResources();
	void    DiscardGraphicsResources();
	void    OnPaint();
	void    Resize();

public:

	MainWindow() : pFactory(NULL), pRenderTarget(NULL) {
	}

	PCWSTR  ClassName() const { return L"Shape Window"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual void paintWindow();
};

// Recalculate drawing layout when the size of the window changes.

void MainWindow::paintWindow() {
	D2D1_SIZE_F size = pRenderTarget->GetSize();

	const float m = 5;
	const float width = size.width;
	const float height = size.height;
	const float x = width / 2;
	const float y = height / 2;
	const float radius = min(x - 2*m, y - 2*m);

	pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::SkyBlue));

	if (true) {
		Circle circle;
		circle.center.x = x;
		circle.center.y = y;
		circle.radius = radius;

		circle.draw(pRenderTarget);
	}

	if (true) {
		Rect rect;
		rect.center.x = x;
		rect.center.y = y;
		rect.width = size.width / 2;
		rect.height = size.height / 2;

		rect.draw(pRenderTarget);
	} 
}

HRESULT MainWindow::CreateGraphicsResources()
{
	ZF_LOGW("CreateGraphicsResources()");
	HRESULT hr = S_OK;
	if (pRenderTarget == NULL) {
		RECT rc;
		GetClientRect(m_hwnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

		hr = pFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(m_hwnd, size),
			&pRenderTarget);
	}
	return hr;
}

void MainWindow::DiscardGraphicsResources() {
	SafeRelease(&pRenderTarget);
}

void MainWindow::OnPaint() {
	ZF_LOGW("OnPaint");

	HRESULT hr = CreateGraphicsResources();
	if (SUCCEEDED(hr)) {
		PAINTSTRUCT ps;
		BeginPaint(m_hwnd, &ps);

		pRenderTarget->BeginDraw();

		this->paintWindow();

		hr = pRenderTarget->EndDraw();
		if (FAILED(hr) || hr == D2DERR_RECREATE_TARGET) {
			DiscardGraphicsResources();
		}
		EndPaint(m_hwnd, &ps);
	}
}

void MainWindow::Resize() {
	if (pRenderTarget != NULL) {
		RECT rc;
		GetClientRect(m_hwnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

		pRenderTarget->Resize(size);
		InvalidateRect(m_hwnd, NULL, FALSE);
	}
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
	zf_log_set_output_v(ZF_LOG_PUT_STD, 0, custom_output_callback);

	ZF_LOGI("wWinMain");

	MainWindow win;

	DWORD dwExStyle = 0;
	int x = CW_USEDEFAULT;
	int y = CW_USEDEFAULT;
	int w = 500 ;
	int h = 500 ;

	if (!win.Create(L"Shape Drawing Window", WS_OVERLAPPEDWINDOW, dwExStyle, x, y, w, h ))
	{
		return 0;
	}

	ShowWindow(win.Window(), nCmdShow);

	// Run the message loop.

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		if (FAILED(D2D1CreateFactory(
			D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory)))
		{
			return -1;  // Fail CreateWindowEx.
		}
		return 0;

	case WM_DESTROY:
		DiscardGraphicsResources();
		SafeRelease(&pFactory);
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		OnPaint();
		return 0;


	case WM_SIZE:
		Resize();
		return 0;
	}
	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}
