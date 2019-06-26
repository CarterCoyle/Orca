workspace "Orca"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	include "Orca/3rdParty/glfw"
	include "Orca/3rdParty/glad"
	include "Orca/3rdParty/imgui"

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
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/3rdParty/glm/glm/**.inl",
		"%{prj.name}/3rdParty/glm/glm/**.hpp"
	}

	links
	{
		"glfw",
		"glad",
		"imgui",
		"opengl32.lib"
	}
	
	includedirs
	{
		"%{prj.name}/3rdParty/spdlog/include",
		"%{prj.name}/3rdParty/glfw/include",
		"%{prj.name}/3rdParty/glad/include",
		"%{prj.name}/3rdParty/imgui",
		"%{prj.name}/3rdParty/glm/glm",
		"%{prj.name}/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"

		defines
		{
			"OC_PLATFORM_WINDOWS",
			"OC_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "OC_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "OC_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "OC_DIST"
			runtime "Release"
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
		"Orca/3rdParty/imgui",
		"Orca/3rdParty/glfw/include",
		"Orca/3rdParty/glad/include",
		"Orca/3rdParty/glm/glm",
		"Orca/src"
	}

	links
	{
		"Orca",
		"imgui"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "10.0.17763.0"

		defines
		{
			"OC_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "OC_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "OC_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "OC_DIST"
			runtime "Release"
			optimize "On"
