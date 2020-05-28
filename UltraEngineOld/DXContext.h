#pragma once

#include "Interfaces/IContext.h"
#include <d3d11.h>
#include <d3dcommon.h>

namespace UltraEngine {
	namespace Core {
		class DXContext : public IContext
		{
		public:
			DXContext() {}
			DXContext(std::shared_ptr<ID3D11DeviceContext> _context);
			DXContext(DXContext& dxcontext) = delete;

			void release();
		private:
			std::shared_ptr<ID3D11DeviceContext> context;
			std::shared_ptr<ID3D11RenderTargetView> backBuffer;
		};

	}
}

