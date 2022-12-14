#include <Spotbrain.h>
#include <Spot_Brain/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Brain {

	class BrainEditor : public Application
	{
	public:
		BrainEditor() 
			: Application("Brain Editor") 
		{
			// PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
		}

		~BrainEditor() {

		}

	};



	Application* CreateApplication()
	{
		return new BrainEditor();
	}
}