#pragma once

#include "framework.h"
#include "Interfaces/IScene.h"
#include "DXScene.h"

namespace UltraEngine {
	/*
	 * Application controller alluding to the MVC 
	 */
	class ApplicationController {
	public:
		ApplicationController();
		void run();
	private:
		
		// The "View"
		std::unique_ptr<Core::DXScene> scene;
		
		void mousClicked();
		void keyboardInput();
	};
}