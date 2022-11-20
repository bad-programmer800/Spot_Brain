workspace "Spot_Brain"
	architecture "x64"
	startproject "The_Brain"
	
	
	configurations {
		"Debug",
		"Release",
		"Dist"
	}
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "Spot_Brain/Vendor/GLFW/include"
	IncludeDir["glad"] = "Spot_Brain/Vendor/glad/include"
	IncludeDir["imgui"] = "Spot_Brain/Vendor/imgui"

	include "Spot_Brain/Vendor/GLFW/"
	include "Spot_Brain/Vendor/glad/"
	include "Spot_Brain/Vendor/imgui"

	project "Spot_Brain"
		location "Spot_Brain"
		kind "SharedLib"
		language "C++"
		
		targetdir ("bin/" ..outputdir.. "/%{prj.name}")
		objdir ("bin-int/" ..outputdir.. "/%{prj.name}")
		
		pchheader "sbpch.h"
		pchsource "Spot_Brain/src/sbpch.cpp"

		files {
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}
		
		includedirs {
			"%{prj.name}/src",
			"%{prj.name}/Vendor/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.glad}",
			"%{IncludeDir.imgui}"
		}

		links {
			"GLFW", 
			"opengl32.lib", 
			"glad",
			"imgui"
		}
		
		filter "system:windows"
			cppdialect "C++17"
			systemversion "latest"
			staticruntime "off"
			
			defines {
				"SB_PLATFORM_WINDOWS",
				"SB_BUILD_DLL",
				"GLFW_INCLUDE_NONE"
			}
			
		postbuildcommands {
			("{COPYFILE} %{cfg.buildtarget.abspath} ../bin/" .. outputdir .. "/The_Brain")
		}

			
		filter "configurations:Debug"
			defines "SB_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "SB_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "SB_DIST"
			runtime "Release"
			optimize "On"
	
	
	
	project "The_Brain"
		location "The_Brain"
		kind "ConsoleApp"
		language "C++"

		targetdir ("bin/" ..outputdir.. "/%{prj.name}")
		objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

		files {
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs {
			"Spot_Brain/Vendor/spdlog/include",
			"Spot_Brain/src"
		}

		links {"Spot_Brain"}

		filter "system:windows"
			cppdialect "C++17"
			staticruntime "off"
			systemversion "latest"

		defines {"SB_PLATFORM_WINDOWS"}

		filter "configurations:Debug"
			defines "SB_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "SB_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "SB_DIST"
			runtime "Release"
			optimize "On"