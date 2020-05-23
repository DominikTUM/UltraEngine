#pragma once
#include "framework.h"
namespace UltraEngine {
	class ApplicationController {
	public:
		static ApplicationController& getInstance();
		void run();
	private:
		ApplicationController();

		void mousClicked();
		void keyboardInput();
	};
}