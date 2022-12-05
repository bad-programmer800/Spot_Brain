#pragma once

#include "Spot_Brain/Core/Core.h"

#include "Spot_Brain/Core/Window.h"
#include "Spot_Brain/Core/LayerStack.h"
#include "Spot_Brain/Events/Event.h"
#include "Spot_Brain/Events/ApplicationEvent.h"

#include "Spot_Brain/Core/Timestep.h"

#include "Spot_Brain/imgui/ImGuiLayer.h"

int main(int argc, char** argv);

namespace Brain {
	
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined by client.
	Application* CreateApplication();

}

