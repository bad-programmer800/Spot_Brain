project "yaml-cpp"
	kind "StaticLib"
	language "C++"
	
	
	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")
	
	files { 
		"include/**.h",
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"include"
	}
	
	defines {
		"YAML_CPP_STATIC_DEFINE"
	}
	
	filter "system:windows"
		systemversion "latest"
		cppdialect "C++17"
		staticruntime "on"
			

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
