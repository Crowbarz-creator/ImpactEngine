workspace "Impact"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Impactvendor/GLFW/include"

include "Impact/vendor/GLFW"

project "Impact"
	location "Impact"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}/")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}/")

	pchheader "imppch.h"
	pchsource "Impact/src/imppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"IMP_PLATFORM_WINDOWS",
			"IMP_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
		}

	filter "configurations:Debug"
		defines "IMP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IMP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IMP_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}/")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}/")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Impact/src",
		"Impact/vendor/spdlog/include"
	}

	links
	{
		"Impact"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"IMP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "IMP_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IMP_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IMP_DIST"
		optimize "On"
