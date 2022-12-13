workspace "Spot_Brain"
	architecture "x86_64"
	startproject "The_Brain"
	
	
	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	flags {
		"MultiProcessorCompile"
	}
	
	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
	-- Include directories relative to root folder (solution directory)
	IncludeDir = {}
	IncludeDir["GLFW"] = "Spot_Brain/Vendor/GLFW/include"
	IncludeDir["glad"] = "Spot_Brain/Vendor/glad/include"
	IncludeDir["imgui"] = "Spot_Brain/Vendor/imgui"
	IncludeDir["glm"] = "Spot_Brain/Vendor/glm"
	IncludeDir["stb_image"] = "Spot_Brain/Vendor/stb_image"


	group "Dependencies"
		include "Spot_Brain/Vendor/GLFW/"
		include "Spot_Brain/Vendor/glad/"
		include "Spot_Brain/Vendor/imgui/"

	group ""

	project "Spot_Brain"
		location "Spot_Brain"
		kind "StaticLib"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"
		
		targetdir ("bin/" ..outputdir.. "/%{prj.name}")
		objdir ("bin-int/" ..outputdir.. "/%{prj.name}")
		
		pchheader "sbpch.h"
		pchsource "Spot_Brain/src/sbpch.cpp"

		files {
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp",
			"%{prj.name}/Vendor/glm/glm/**.hpp",
			"%{prj.name}/Vendor/glm/glm/**.inl",
			"%{prj.name}/Vendor/stb_image/**.h",
			"%{prj.name}/Vendor/stb_image/**.cpp"
		}
		
		defines {
			"SB_PLATFORM_WINDOWS",	
			"_CRT_SECURE_NO_WARNINGS",
			"GLFW_INCLUDE_NONE"
		}

		includedirs {
			"%{prj.name}/src",
			"%{prj.name}/Vendor/spdlog/include",
			"%{IncludeDir.GLFW}",
			"%{IncludeDir.glad}",
			"%{IncludeDir.imgui}",
			"%{IncludeDir.glm}",
			"%{IncludeDir.stb_image}"
		}

		links {
			"GLFW", 
			"opengl32.lib", 
			"glad",
			"imgui"
		}
		
		filter "system:windows"
			systemversion "latest"
			
			defines {
				"SB_PLATFORM_WINDOWS"
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
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("bin/" ..outputdir.. "/%{prj.name}")
		objdir ("bin-int/" ..outputdir.. "/%{prj.name}")

		files {
			"%{prj.name}/src/**.h",
			"%{prj.name}/src/**.cpp"
		}

		includedirs {
			"Spot_Brain/Vendor/spdlog/include",
			"Spot_Brain/src",
			"Spot_Brain/Vendor",
			"%{IncludeDir.glm}"
		}

		links {"Spot_Brain"}

		filter "system:windows"
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