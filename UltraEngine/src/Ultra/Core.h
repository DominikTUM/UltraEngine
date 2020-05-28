#pragma once

#ifdef _WINDOWS
	#ifdef ULTRAENGINE_EXPORTS
		#define ULTRA_API __declspec(dllexport)
	#else
		#define ULTRA_API __declspec(dllimport)
	#endif
#else
	#error "UltraEngine is only available for windows"
#endif

#pragma message("Still not building a DLL due to win32 -> fix this")
#define ULTRA_API
