#pragma once

#include "Spotbrain.h"

class Sandbox2D : public Brain::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Brain::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Brain::Event& e) override;
private:
	Brain::OrthographicCameraController m_CameraController;

	// Temp
	Brain::Ref<Brain::VertexArray> m_SquareVA;
	Brain::Ref<Brain::Shader> m_FlatColorShader;

	Brain::Ref<Brain::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};