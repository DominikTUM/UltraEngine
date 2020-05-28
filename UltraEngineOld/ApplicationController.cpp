#include "ApplicationController.h"

using namespace UltraEngine;

ApplicationController::ApplicationController(){
	#if defined(DEBUG) | defined(_DEBUG)
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	#endif
	
	// Init DirectX
	DXUTInit(true, true, nullptr);
	DXUTSetCursorSettings(true, true);
	DXUTCreateWindow(L"UltraEngine");

	// Generate scene
	scene = std::make_unique<Core::DXScene>();
}

void ApplicationController::run() {
	DXUTMainLoop();
}

void ApplicationController::mousClicked() {

}

void ApplicationController::keyboardInput() {

}