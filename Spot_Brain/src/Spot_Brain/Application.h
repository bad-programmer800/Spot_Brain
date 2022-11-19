#pragma once

#include "Core.h"

#include "Window.h"
#include "LayerStack.h"
#include "Spot_Brain/Events/Event.h"
#include "Spot_Brain/Events/ApplicationEvent.h"


namespace Brainspace {
	
	class BRAIN_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

	};

	// To be defined by client.
	Application* CreateApplication();

}

