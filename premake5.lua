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
IncludeDir["GLFW"] = "Impact/vendor/GLFW/include"
IncludeDir["Glad"] = "Impact/vendor/Glad/include"
IncludeDir["ImGui"] = "Impact/vendor/imgui"

include "Impact/vendor/GLFW"
include "Impact/vendor/Glad"
include "Impact/vendor/imgui"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"Impact/vendor/imgui/backends"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"Glad",
		"ImGui",
		"User32.lib",
		"Gdi32.lib",
		"Shell32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"IMP_PLATFORM_WINDOWS",
			"IMP_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox/")
		}

	filter "configurations:Debug"
		defines "IMP_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "IMP_RELEASE"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Dist"
		defines "IMP_DIST"
		buildoptions "/MDd"
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
		buildoptions "/utf-8"

		defines
		{
			"IMP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "IMP_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "IMP_RELEASE"
		buildoptions "/MDd"
		optimize "On"

	filter "configurations:Dist"
		defines "IMP_DIST"
		buildoptions "/MDd"
		optimize "On"

project "ImGui"
	location "ImGui"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}/")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}/")

	files
	{
		"Impact/vendor/imgui/imgui.cpp",
		"Impact/vendor/imgui/imgui_demo.cpp",
		"Impact/vendor/imgui/imgui_draw.cpp",
		"Impact/vendor/imgui/imgui_tables.cpp",
		"Impact/vendor/imgui/imgui_widgets.cpp",
		
		"Impact/vendor/imgui/backends/imgui_impl_glfw.cpp",
		"Impact/vendor/imgui/backends/imgui_impl_opengl3.cpp"
	}

	includedirs
	{
		"Impact/vendor/imgui",
		"Impact/vendor/imgui/backends",
		"Impact/vendor/GLFW/include",
		"Impact/vendor/Glad/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "Off"
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"IMGUI_IMPL_OPENGL_LOADER_GLAD"
		}
