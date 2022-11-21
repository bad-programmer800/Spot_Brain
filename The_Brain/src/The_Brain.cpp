#include <Spotbrain.h>
#include "imgui/imgui.h"

class ExampleLayer : public Brainspace::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{
		if (Brainspace::Input::IsKeyPressed(SB_KEY_TAB))
			SB_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("HelloWorld");
		ImGui::End();
	}

	void OnEvent(Brainspace::Event& event) override
	{
		if (event.GetEventType() == Brainspace::EventType::KeyPressed)
		{
			Brainspace::KeyPressedEvent& e = (Brainspace::KeyPressedEvent&)event;
			if (e.GetKeyCode() == SB_KEY_TAB)
				SB_TRACE("Tab key is pressed (event)!");
			SB_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};


class Homebrain : public Brainspace::Application
{
public:
	Homebrain() {
		PushLayer(new ExampleLayer());
		
	}

	~Homebrain() {

	}

};

 

Brainspace::Application* Brainspace::CreateApplication()
{
	return new Homebrain();
}
