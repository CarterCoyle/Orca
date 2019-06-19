#pragma once

#ifdef OC_PLATFORM_WINDOWS
	#ifdef OC_BUILD_DLL
		#define	ORCA_API __declspec(dllexport)
	#else
		#define ORCA_API __declspec(dllimport)
	#endif
#endif

