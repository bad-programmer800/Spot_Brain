#include <Spotbrain.h>
#include "SegmentationLayer.h"
#include "EditorLayer.h"

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

// Allows access to Dear ImGui tools
#include <imgui/imgui.h>

// OpenGL math library add multiple tools
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Brain {
	
	
	// Constructor for the layer
	SegmentationLayer::SegmentationLayer()
		: Layer("SegmentationLayer") // Preset variables
	{
			
	}
	
	// Initialize variables, sets up the scene
	void SegmentationLayer::OnAttach()
	{
		
	}
	
	void SegmentationLayer::OnDetach()
	{
		/* Currently no action needed, but in the future
		variables may need to be cleared or deleted */
	}
	
	void SegmentationLayer::OnUpdate(Timestep ts)
	{
		// Resize: Check for resize of the window
		// Update: checks if the camera moved?
		// Render: Sets up background color in the viewport (framebuffer)
		// Update Scene: unbinds the frame buffer and updates scene
	}
	
	void SegmentationLayer::OnImGuiRender()
	{
		// Sets up the ImGui settings and dockspace
		// I could also do the layer without docking and have everything // hardcoded
		// Creates a Menu Bar
		// Adds the Panels
		
		static bool dockspaceOpen = false;
		
		// These variables are used for the 1st if statement which takes over the main window.
		static bool opt_fullscreen_persistant = true;
		bool opt_fullscreen = opt_fullscreen_persistant;
		
		// ImGuiDockNodeFlags is an enum that holds several flags for docking (lines 1343-1350 of imgui.h)
		static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
		
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
			
		if (opt_fullscreen)
		{
			ImGuiViewport* viewport = ImGui::GetMainViewport();
			ImGui::SetNextWindowPos(viewport->Pos);
			ImGui::SetNextWindowSize(viewport->Size);
			ImGui::SetNextWindowViewport(viewport->ID);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
			ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
			window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
			window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
			ImGui::PopStyleVar();
			ImGui::PopStyleVar();
			
		}
		
		ImGui::Begin("Main", &dockspaceOpen, window_flags);
		

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Exit")) Brain::Application::Get().Close();
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

		ImGui::BeginChild("Viewer", ImVec2(500.0f, 500.0f), true, 0);
		ImGui::Text("I'm a child window!");
		cv::Mat inputImage;
		std::string inputImagePath = "assets/textures/BrainLogo3.png";
		inputImage = cv::imread(inputImagePath, cv::IMREAD_GRAYSCALE);
		cv::imshow("new", inputImage);
		ImGui::Separator();
		ImGui::Text("Mat Details");
		ImGui::Text("Width (number of columns): %d", inputImage.cols);
		ImGui::Text("Height (number of rows): %d", inputImage.rows);
		ImGui::Text("Dimensions: %d", inputImage.dims);
		
		
		ImGui::EndChild();
		
		ImGui::End();

	}
	
	void SegmentationLayer::OnEvent(Brain::Event& e)
	{
		// Right now is just used for a camera controller
		// ImGui has its own event handling
	}

}