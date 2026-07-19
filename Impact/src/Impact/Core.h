#pragma once

#ifdef IMP_PLATFORM_WINDOWS
#if IMP_DYNAMIC_LINK
	#ifdef IMP_BUILD_DLL
		#define IMPACT_API __declspec(dllexport)
	#else
		#define IMPACT_API __declspec(dllimport)
	#endif
#else
	#define IMPACT_API
#endif
#else
	#error Impact Engine only supports Windows!
#endif

#ifdef IMP_DEBUG
	#define IMP_ENABLE_ASSERTS
#endif

#ifdef IMP_ENABLE_ASSERTS
	#define IMP_ASSERT(x, ...) { if(!(x)) { IMP_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define IMP_CORE_ASSERT(x, ...) { if(!(x)) { IMP_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define IMP_ASSERT(x, ...)
	#define IMP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))

#define IMP_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)