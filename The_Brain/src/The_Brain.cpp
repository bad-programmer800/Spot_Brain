#include <Spotbrain.h>

class ExampleLayer : public Brainspace::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		SB_INFO("ExampleLayer::Update");
	}

	void OnEvent(Brainspace::Event& event) override
	{
		SB_TRACE("{0}", event);
	}
};


class Homebrain : public Brainspace::Application
{
public:
	Homebrain() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Brainspace::ImGuiLayer());
	}

	~Homebrain() {

	}

};

 

Brainspace::Application* Brainspace::CreateApplication()
{
	return new Homebrain();
}
