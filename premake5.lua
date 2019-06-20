workspace "Orca"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Orca"
	location "Orca"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "OrcaPCH.h"
	pchsource "Orca/src/OrcaPCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	libdirs
	{
		"%{prj.name}/3rdParty/glfw/lib"
	}

	links
	{
		"glfw3",
		"opengl32"
	}
	
	includedirs
	{
		"%{prj.name}/3rdParty/spdlog/include",
		"%{prj.name}/3rdParty/glfw/include",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17763.0"

		defines
		{
			"OC_PLATFORM_WINDOWS",
			"OC_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "OC_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "OC_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "OC_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Orca/3rdParty/spdlog/include",
		"Orca/src"
	}

	links
	{
		"Orca"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.17763.0"

		defines
		{
			"OC_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "OC_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "OC_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "OC_DIST"
			optimize "On"
