#include <Spotbrain.h>
#include <Spot_Brain/Core/EntryPoint.h>

#include "Sandbox2D.h"

#include "ExampleLayer.h"

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
