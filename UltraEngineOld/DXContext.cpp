#include "DXContext.h"

using namespace UltraEngine::Core;

DXContext::DXContext(std::shared_ptr<ID3D11DeviceContext> _context) {
	context = _context;
}

void DXContext::release() {
	context->Release();
}
