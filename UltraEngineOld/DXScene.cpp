#include "DXScene.h"

using namespace UltraEngine::Core;
using namespace UltraEngine;

DXScene::DXScene() :  device(swapChain) {
	// Set device context
	context = DXContext(device.getContext());
}


DXScene::~DXScene() {
	device.release();
	context.release();
}

void DXScene::render() {

}