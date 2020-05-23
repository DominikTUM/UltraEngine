#pragma once

#include "framework.h"

#define LENGTH 100
namespace UltraEngine {
	namespace WindowManagement {

		LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		class Window {
		public:
			HINSTANCE hInstance;
			HWND handle;
			WCHAR title[LENGTH] = TEXT("UltraEngine");
			WCHAR registerClass[LENGTH];

			Window(HINSTANCE instance, HWND windowHandle) : hInstance(instance), handle(windowHandle) { }
	
			ATOM MyRegisterClass(HINSTANCE hInstance)
			{
				WNDCLASSEXW wcex;

				wcex.cbSize = sizeof(WNDCLASSEX);

				wcex.style = CS_HREDRAW | CS_VREDRAW;
				wcex.lpfnWndProc = WndProc;
				wcex.cbClsExtra = 0;
				wcex.cbWndExtra = 0;
				wcex.hInstance = hInstance;
				wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ULTRAENGINE));
				wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
				wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
				wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_ULTRAENGINE);
				wcex.lpszClassName = registerClass;
				wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

				return RegisterClassExW(&wcex);
			}

			BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
			{

				HWND hWnd = CreateWindowW(registerClass, title, WS_OVERLAPPEDWINDOW,
					CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

				if (!hWnd)
				{
					return FALSE;
				}

				ShowWindow(hWnd, nCmdShow);
				UpdateWindow(hWnd);

				return TRUE;
			}

			friend LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			
		};

		LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
		{
			switch (message)
			{
			case WM_COMMAND:
			{
				int wmId = LOWORD(wParam);
				// Menüauswahl analysieren:
				switch (wmId)
				{

				case IDM_EXIT:
					DestroyWindow(hWnd);
					break;
				default:
					return DefWindowProc(hWnd, message, wParam, lParam);
				}
			}
			break;
			case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				// TODO: Zeichencode, der hdc verwendet, hier einfügen...
				EndPaint(hWnd, &ps);
			}
			break;
			case WM_DESTROY:
				PostQuitMessage(0);
				break;
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
			return 0;
		}
	}
}