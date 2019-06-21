#pragma once

#ifdef OC_PLATFORM_WINDOWS
	#ifdef OC_BUILD_DLL
		#define	ORCA_API __declspec(dllexport)
	#else
		#define ORCA_API __declspec(dllimport)
	#endif
#endif

#ifdef OC_ENABLE_ASSERTS
	#define OC_ASSERT(x, ...) { if(!(x)) { OC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define OC_ASSERT(x, ...);
#endif  OC_ENABLE_ASSERTS
