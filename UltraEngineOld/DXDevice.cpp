#include "DXDevice.h"

using namespace UltraEngine::Core;
using namespace UltraEngine;

DXDevice::DXDevice(std::shared_ptr<IDXGISwapChain> swapChain) {
	featureLevel = D3D_FEATURE_LEVEL_10_0;
	HRESULT res = DXUTCreateDevice(featureLevel, true, 640, 480);

	device.reset(DXUTGetD3D11Device());
	context.reset(DXUTGetD3D11DeviceContext());
}

std::shared_ptr<ID3D11DeviceContext> DXDevice::getContext() const {
	return context;
}

std::shared_ptr<ID3D11Device> DXDevice::getDevice() const {
	return device;
}

void DXDevice::release() {
	
	device->Release();
}
