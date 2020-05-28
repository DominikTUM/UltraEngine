#pragma once

#include <memory>

#include "Interfaces/IScene.h"
#include "DXContext.h"
#include "DXDevice.h"
#include <dxgi1_3.h>

namespace UltraEngine {
	namespace Core {
		class DXScene {
		public:
			DXScene();
			~DXScene();

			void render();
		private:
			// Not nice -> refactor inheritance
			DXDevice device;
			DXContext context;

			// Swapchain of the scene
			std::shared_ptr<IDXGISwapChain> swapChain;
			// Buffer of the swapchain
			std::shared_ptr<ID3D11Texture2D> backBuffer;
			// Render Target
			std::shared_ptr<ID3D11RenderTargetView> renderTarget;

		};
	}
}