#include <Spotbrain.h>
#include <Spot_Brain/Core/EntryPoint.h>

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class ExampleLayer : public Brain::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.0f / 720.0f)
	{
		m_VertexArray = Brain::VertexArray::Create();

		float vertices[3 * 7] = {
			-0.5f,	-0.5f,	0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f,	-0.5f,	0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			0.0f,	0.5f,	0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		Brain::Ref<Brain::VertexBuffer> vertexBuffer = Brain::VertexBuffer::Create(vertices, sizeof(vertices));
		Brain::BufferLayout layout = {
			{Brain::ShaderDataType::Float3, "a_Position"},
			{Brain::ShaderDataType::Float4, "a_Color"}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		Brain::Ref<Brain::IndexBuffer> indexBuffer = Brain::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA = Brain::VertexArray::Create();

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f,  0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f,  0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f,  0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f,  0.0f, 0.0f, 1.0f
		};

		Brain::Ref<Brain::VertexBuffer> squareVB = Brain::VertexBuffer::Create(squareVertices, sizeof(squareVertices));
		squareVB->SetLayout({
			{Brain::ShaderDataType::Float3, "a_Position"},
			{Brain::ShaderDataType::Float2, "a_TexCoord"}
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		Brain::Ref<Brain::IndexBuffer> squareIB = Brain::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader = Brain::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

		m_FlatColorShader = Brain::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = Brain::Texture2D::Create("assets/textures/Checkerboard2.png");
		m_BrainLogoTexture = Brain::Texture2D::Create("assets/textures/BrainLogo3.png");

		textureShader->Bind();
		textureShader->SetInt("u_Texture", 0);
	}

	void OnUpdate(Brain::Timestep ts) override
	{
		// Update
		m_CameraController.OnUpdate(ts);

		// Render
		Brain::RenderCommand::SetClearColor({ 1.0f, 0.0f, 1.0f, 1 });
		Brain::RenderCommand::Clear();

		Brain::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		m_FlatColorShader->Bind();
		m_FlatColorShader->SetFloat3("u_Color", m_SquareColor);
		
		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4& transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Brain::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		Brain::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_BrainLogoTexture->Bind();
		Brain::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));


		// Triangle
		// Brain::Renderer::Submit(m_Shader, m_VertexArray);
		
		Brain::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
		ImGui::Begin("OpenCV");
		ImGui::End();
	}

	void OnEvent(Brain::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}
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

class Homebrain : public Brain::Application
{
public:
	Homebrain() {
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	}

	~Homebrain() {

	}

};

 

Brain::Application* Brain::CreateApplication()
{
	return new Homebrain();
}
