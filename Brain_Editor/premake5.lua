project "Brain_Editor"
		kind "ConsoleApp"
		language "C++"
		cppdialect "C++17"
		staticruntime "on"

		targetdir ("%{wks.location}/bin/" ..outputdir.. "/%{prj.name}")
		objdir ("%{wks.location}/bin-int/" ..outputdir.. "/%{prj.name}")

		files {
			"src/**.h",
			"src/**.cpp"
		}

		includedirs {
			"%{wks.location}/Spot_Brain/Vendor/spdlog/include",
			"%{wks.location}/Spot_Brain/src",
			"%{wks.location}/Spot_Brain/Vendor",
			"%{IncludeDir.glm}",
			"%{IncludeDir.entt}",
			"%{IncludeDir.ImGuizmo}"
		}

		externalincludedirs {"C:/opencv/opencv/build/include"}

		libdirs {"C:/opencv/opencv/build/x64/vc15/lib"}

		links {
			"Spot_Brain",
			"opencv_world460d.lib"
		}

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