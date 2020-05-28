#pragma once

// DLL export definiton
#ifdef _WINDOWS
	#ifdef ULTRAENGINE_EXPORTS
		#define ULTRA_API __declspec(dllexport)
	#else
		#define ULTRA_API __declspec(dllimport)
	#endif
#else
	#error "UltraEngine is only available for windows"
#endif

// DLL warning
#pragma message("Still not building a DLL due to win32 -> fix this")
#define ULTRA_API

// Make logging accessible for every file
#include "Logger.h"