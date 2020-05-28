#pragma once

#include "Interfaces/IDevice.h"
#include <d3d11.h>
#include <memory>
#include "../DXUT/Core/DXUT.h"

namespace UltraEngine {
	namespace Core {
		class DXDevice : public IDevice {
		public:
			DXDevice(std::shared_ptr<IDXGISwapChain> swapChain);
			DXDevice(DXDevice& device) = delete;

			std::shared_ptr<ID3D11Device> getDevice() const;
			std::shared_ptr<ID3D11DeviceContext> getContext() const;

			void release();
		private:
			const D3D_FEATURE_LEVEL levels[4] = {
				D3D_FEATURE_LEVEL_11_0,
				D3D_FEATURE_LEVEL_11_1,
				D3D_FEATURE_LEVEL_12_0,
				D3D_FEATURE_LEVEL_12_1
			};

			D3D_FEATURE_LEVEL featureLevel;

			std::shared_ptr<ID3D11Device> device;
			std::shared_ptr<ID3D11DeviceContext> context;
		};
	}
}