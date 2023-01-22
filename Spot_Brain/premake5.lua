project "Spot_Brain"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("%{wks.location}/bin/" ..outputdir.. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" ..outputdir.. "/%{prj.name}")
	
	pchheader "sbpch.h"
	pchsource "src/sbpch.cpp"

	files {
		"src/**.h",
		"src/**.cpp",
		"Vendor/glm/glm/**.hpp",
		"Vendor/glm/glm/**.inl",
		"Vendor/stb_image/**.h",
		"Vendor/stb_image/**.cpp",
		"Vendor/ImGuizmo/ImGuizmo.h",
		"Vendor/ImGuizmo/ImGuizmo.cpp"
		
	}
	
	defines {
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE",
		"YAML_CPP_STATIC_DEFINE"
	}

	includedirs {
		"src",
		"Vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}",
		"%{IncludeDir.ImGuizmo}"
	}

	externalincludedirs {"C:/opencv/opencv/build/include"}

	libdirs {"C:/opencv/opencv/build/x64/vc15/lib"}

	links {
		"GLFW", 
		"opengl32.lib", 
		"glad",
		"imgui",
		"yaml-cpp"
	}

	filter "files:Vendor/ImGuizmo/**.cpp"
	flags {"NoPCH"}
	
	filter "system:windows"
		systemversion "latest"

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