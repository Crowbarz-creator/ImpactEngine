workspace "Impact"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Impact/vendor/GLFW/include"
IncludeDir["Glad"] = "Impact/vendor/Glad/include"
IncludeDir["ImGui"] = "Impact/vendor/imgui"
IncludeDir["glm"] = "Impact/vendor/glm"
IncludeDir["stb_image"] = "Impact/vendor/stb_image"

group "Dependencies"
	include "Impact/vendor/GLFW"
	include "Impact/vendor/Glad"
	include "Impact/vendor/imgui"

group ""

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

project "Impact"
	location "Impact"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}/")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}/")

	pchheader "imppch.h"
	pchsource "Impact/src/imppch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
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
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"IMP_PLATFORM_WINDOWS",
			"IMP_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "IMP_DEBUG"
		runtime "Debug"
		symbols "Off"

	filter "configurations:Release"
		defines "IMP_RELEASE"
		runtime "Release"
		optimize "Off"

	filter "configurations:Dist"
		defines "IMP_DIST"
		runtime "Release"
		optimize "Off"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "Off"

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
		"Impact/vendor/spdlog/include",
		"Impact/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"Impact",
		"ImGui"
	}

	filter "system:windows"
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"IMP_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "IMP_DEBUG"
		runtime "Debug"
		symbols "Off"

	filter "configurations:Release"
		defines "IMP_RELEASE"
		runtime "Release"
		optimize "Off"

	filter "configurations:Dist"
		defines "IMP_DIST"
		runtime "Release"
		optimize "Off"
