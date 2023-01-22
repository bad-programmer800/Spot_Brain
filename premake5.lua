workspace "Spot_Brain"
	architecture "x86_64"
	startproject "Brain_Editor"
	
	
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
	IncludeDir["GLFW"] = "%{wks.location}/Spot_Brain/Vendor/GLFW/include"
	IncludeDir["glad"] = "%{wks.location}/Spot_Brain/Vendor/glad/include"
	IncludeDir["imgui"] = "%{wks.location}/Spot_Brain/Vendor/imgui"
	IncludeDir["glm"] = "%{wks.location}/Spot_Brain/Vendor/glm"
	IncludeDir["stb_image"] = "%{wks.location}/Spot_Brain/Vendor/stb_image"
	IncludeDir["entt"] = "%{wks.location}/Spot_Brain/Vendor/entt/include"
	IncludeDir["yaml_cpp"] = "%{wks.location}/Spot_Brain/Vendor/yaml-cpp/include"
	IncludeDir["ImGuizmo"] = "%{wks.location}/Spot_Brain/Vendor/ImGuizmo"


	group "Dependencies"
		include "vendor/premake"
		include "Spot_Brain/Vendor/GLFW"
		include "Spot_Brain/Vendor/glad"
		include "Spot_Brain/Vendor/imgui"
		include "Spot_Brain/Vendor/yaml-cpp"

	group ""
	
	include "Spot_Brain"
	include "The_Brain"
	include "Brain_Editor"