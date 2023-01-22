#include <Spotbrain.h>
#include <Spot_Brain/Core/EntryPoint.h>

#include "EditorLayer.h"
#include "SegmentationLayer.h"

namespace Brain {

	class BrainEditor : public Application
	{
	public:
		BrainEditor() 
			: Application("Brain Editor") 
		{
			// PushLayer(new ExampleLayer());
			PushLayer(new EditorLayer());
			// PushLayer(new SegmentationLayer());
		}

		~BrainEditor() {

		}

	};



	Application* CreateApplication()
	{
		return new BrainEditor();
	}
}