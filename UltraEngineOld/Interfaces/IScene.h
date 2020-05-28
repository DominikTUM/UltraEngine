#pragma once

#include "IContext.h"
#include "IDevice.h"

namespace UltraEngine {
	namespace Core {
		class IScene {
		public:
			virtual void render() = 0;

			IDevice& device;
			IContext& context;
		};
	}
}