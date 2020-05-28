#pragma once

#include "Core.h"

#include <functional>
/*
 * Class represents the entry point of the program
 * and acts as the controller.
 */
namespace Ultra {
	class ULTRA_API Application
	{
	private:
	public:
		Application();
		~Application();

		virtual void run() = 0;
	};
}

