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

#ifdef IMP_ENABLE_ASSERTS
	#define IMP_ASSERT(x, ...) { if(!(x)) { IMP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define IMP_CORE_ASSERT(x, ...) { if(!(x)) { IMP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define IMP_ASSERT(x, ...)
	#define IMP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))