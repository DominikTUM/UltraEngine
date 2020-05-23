// UltraEngine.cpp : Definiert den Einstiegspunkt für die Anwendung.
//

#include "UltraEngine.h"

#define MAX_LOADSTRING 100

// Globale Variablen:
HINSTANCE hInst;                                // Aktuelle Instanz
WCHAR szTitle[MAX_LOADSTRING];                  // Titelleistentext
WCHAR szWindowClass[MAX_LOADSTRING];            // Der Klassenname des Hauptfensters.


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Wrap window information into object
	UltraEngine::WindowManagement::Window window(hInstance, nullptr);

    // Globale Zeichenfolgen initialisieren
    LoadStringW(hInstance, IDS_APP_TITLE, window.title, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_ULTRAENGINE, window.registerClass, MAX_LOADSTRING);
    window.MyRegisterClass(hInstance);

    // Anwendungsinitialisierung ausführen:
    if (!window.InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

	UltraEngine::ApplicationController app = UltraEngine::ApplicationController::getInstance();
	app.run();

	return TRUE;
}



