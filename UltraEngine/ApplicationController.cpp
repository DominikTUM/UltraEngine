#include "ApplicationController.h"

using namespace UltraEngine;

ApplicationController::ApplicationController() { }

ApplicationController& ApplicationController::getInstance() {

	static ApplicationController controller;

	return controller;
}

void ApplicationController::run() {
	// Messaging Queue
	bool bGotMsg;
	MSG  msg;
	msg.message = WM_NULL;
	PeekMessage(&msg, NULL, 0U, 0U, PM_NOREMOVE);

	while (WM_QUIT != msg.message)
	{
		// Process window events.
		// Use PeekMessage() so we can use idle time to render the scene. 
		bGotMsg = (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE) != 0);

		if (bGotMsg)
		{
			// Translate and dispatch the message
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{

		}
	}
}

void ApplicationController::mousClicked() {

}

void ApplicationController::keyboardInput() {

}