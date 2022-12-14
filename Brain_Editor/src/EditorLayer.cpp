#include "EditorLayer.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono>

namespace Brain {

	EditorLayer::EditorLayer()
		: Layer("EditorLayer"), m_CameraController(1280.0f / 720.0f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
	{
	}

	void EditorLayer::OnAttach()
	{
		SB_PROFILE_FUNCTION();

		m_CheckerboardTexture = Brain::Texture2D::Create("assets/textures/Checkerboard2.png");

		Brain::FrameBufferSpecification fbspec;
		fbspec.Width = 1280;
		fbspec.Height = 720;
		m_FrameBuffer = Brain::FrameBuffer::Create(fbspec);
	}

	void EditorLayer::OnDetach()
	{
		SB_PROFILE_FUNCTION();
	}

	void EditorLayer::OnUpdate(Brain::Timestep ts)
	{
		SB_PROFILE_FUNCTION();

		// Update
		m_CameraController.OnUpdate(ts);

		//Render
		Brain::Renderer2D::ResetStats();
		{
			SB_PROFILE_SCOPE("Renderer Prep");
			m_FrameBuffer->Bind();
			Brain::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			Brain::RenderCommand::Clear();
		}

		{
			static float rotation = 0.0f;
			rotation += ts * 50.f;

			SB_PROFILE_SCOPE("Renderer Draw");
			Brain::Renderer2D::BeginScene(m_CameraController.GetCamera());
			Brain::Renderer2D::DrawRotatedQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
			Brain::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
			Brain::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { m_SquareColor });
			// Brain::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture, 10.0f);
			Brain::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f,20.0f }, m_CheckerboardTexture, 10.0f);
			Brain::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f,1.0f }, rotation, m_CheckerboardTexture, 20.0f);
			Brain::Renderer2D::EndScene();

			Brain::Renderer2D::BeginScene(m_CameraController.GetCamera());
			for (float y = -5.0f; y < 5.0f; y += 0.5f)
			{
				for (float x = -5.0f; x < 5.0f; x += 0.5f)
				{
					glm::vec4 color{ (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
					Brain::Renderer2D::DrawQuad({ x,y }, { 0.45f, 0.45f }, color);
				}
			}
			Brain::Renderer2D::EndScene();
			m_FrameBuffer->Unbind();


		}
	}

	void EditorLayer::OnImGuiRender()
	{
		SB_PROFILE_FUNCTION();

		// Note: Switch this to true to enable ImGui dockspace

			static bool dockspaceOpen = true;
			static bool opt_fullscreen_persistant;
			bool opt_fullscreen = opt_fullscreen_persistant;
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
			}

			if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
				window_flags |= ImGuiWindowFlags_NoBackground;

			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
			ImGui::Begin("Dockspace Demo", &dockspaceOpen, window_flags);
			ImGui::PopStyleVar();

			if (opt_fullscreen)
				ImGui::PopStyleVar(2);

			// Dockspace
			ImGuiIO& io = ImGui::GetIO();
			if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
			{
				ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
				ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
			}

			if (ImGui::BeginMenuBar())
			{
				if (ImGui::BeginMenu("File"))
				{
					if (ImGui::MenuItem("Exit")) Brain::Application::Get().Close();
					ImGui::EndMenu();
				}
				ImGui::EndMenuBar();
			}

			ImGui::Begin("Settings");

			auto stats = Brain::Renderer2D::GetStats();
			ImGui::Text("Renderer2D Stats:");
			ImGui::Text("Draw Calls: %d", stats.DrawCalls);
			ImGui::Text("Quads: %d", stats.QuadCount);
			ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
			ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

			ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

			ImGui::End();

			ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{ 0,0 });
			ImGui::Begin("Viewport");
			ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
			if (m_ViewportSize != *((glm::vec2*)&viewportPanelSize))
			{
				m_FrameBuffer->Resize((uint32_t)viewportPanelSize.x, (uint32_t)viewportPanelSize.y);
				m_ViewportSize = { viewportPanelSize.x, viewportPanelSize.y };

				m_CameraController.OnResize(viewportPanelSize.x, viewportPanelSize.y);
			}
			uint32_t textureID = m_FrameBuffer->GetColorAttachmentRendererID();
			ImGui::Image((void*)textureID, ImVec2{ viewportPanelSize.x, viewportPanelSize.y }, ImVec2{0,1}, ImVec2{1,0});
			ImGui::End();
			ImGui::PopStyleVar();


			ImGui::End();
	}

	void EditorLayer::OnEvent(Brain::Event& e)
	{
		m_CameraController.OnEvent(e);
	}
}