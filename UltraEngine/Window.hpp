#pragma once

#include "framework.h"

#define LENGTH 100

namespace UltraEngine {
	namespace WindowManagement {

		LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		class Window {
		public:
			HINSTANCE hInstance;						// Instance handle
			HWND handle;								// Window handle
			WCHAR title[LENGTH] = TEXT("UltraEngine");  // Window title
			WCHAR registerClass[LENGTH];				// WIndow class

			/*
			 * Set instance handle and window handle
			 */
			Window(HINSTANCE instance, HWND windowHandle) : hInstance(instance), handle(windowHandle) {	}

			/*
			 * Initialize window
			 */
			bool init(int nCmdShow) {
				LoadStringW(hInstance, IDS_APP_TITLE, title, LENGTH);
				LoadStringW(hInstance, IDC_ULTRAENGINE, registerClass, LENGTH);
				myRegisterClass(hInstance);
				
				// Try to hide menu bar, doesnt work...
				SetMenu(handle, GetMenu(handle));

				// Init window
				initInstance(hInstance, nCmdShow);	

				return true;
			}
	
			ATOM myRegisterClass(HINSTANCE hInstance)
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

			BOOL initInstance(HINSTANCE hInstance, int nCmdShow)
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

			/*
			 * Handle window events
			 */
			friend LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			
		};

		
		LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
		{
			switch (message)
			{
			case WM_COMMAND:
			{
				return DefWindowProc(hWnd, message, wParam, lParam);		
			}
			break;
			case WM_PAINT:
			{
				
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