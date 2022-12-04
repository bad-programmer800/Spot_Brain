#pragma once

#include "Spotbrain.h"

class ExampleLayer : public Brain::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Brain::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Brain::Event& e) override;
private:
	Brain::ShaderLibrary m_ShaderLibrary;
	Brain::Ref<Brain::Shader> m_Shader;
	Brain::Ref<Brain::VertexArray> m_VertexArray;

	Brain::Ref<Brain::Shader> m_FlatColorShader;
	Brain::Ref<Brain::VertexArray> m_SquareVA;

	Brain::Ref<Brain::Texture2D> m_Texture, m_BrainLogoTexture;

	Brain::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};