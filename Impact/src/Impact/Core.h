#pragma once

#ifdef IMP_PLATFORM_WINDOWS
	#ifdef IMP_BUILD_DLL
		#define IMPACT_API __declspec(dllexport)
	#else
		#define IMPACT_API __declspec(dllimport)
	#endif
#else
	#error Impact Engine only supports Windows!
#endif