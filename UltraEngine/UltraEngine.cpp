
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

    // Initalize window
	UltraEngine::WindowManagement::Window window(hInstance, nullptr);
	if (!window.init(nCmdShow)) {
		return FALSE;
	}
    
	// Initialize application
	UltraEngine::ApplicationController app = UltraEngine::ApplicationController::getInstance();

	// Run application
	app.run();

	return TRUE;
}



