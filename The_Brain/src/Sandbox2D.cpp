#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <chrono>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	SB_PROFILE_FUNCTION();

	m_CheckerboardTexture = Brain::Texture2D::Create("assets/textures/Checkerboard2.png");
}

void Sandbox2D::OnDetach()
{
	SB_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Brain::Timestep ts)
{
	SB_PROFILE_FUNCTION();

	// Update
		m_CameraController.OnUpdate(ts);

	//Render
	{
		SB_PROFILE_SCOPE("Renderer Prep");
		Brain::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Brain::RenderCommand::Clear();
	}
	
	{
		SB_PROFILE_SCOPE("Renderer Draw");
		Brain::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Brain::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Brain::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		Brain::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		Brain::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	SB_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));

	ImGui::End();
}

void Sandbox2D::OnEvent(Brain::Event& e)
{
	m_CameraController.OnEvent(e);
}