#include "sbpch.h"
#include "Spot_Brain/Core/Application.h"
#include "Spot_Brain/Core/Log.h"


#include "Spot_Brain/Renderer/Renderer.h"

#include "Spot_Brain/Core/Input.h"

#include <GLFW/glfw3.h>

namespace Brain {

Application* Application::s_Instance = nullptr;

	Application::Application() 
	{
		SB_PROFILE_FUNCTION();

		SB_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = Window::Create();
		m_Window->SetEventCallback(SB_BIND_EVENT_FN(Application::OnEvent));

		Renderer::Init();

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
		SB_PROFILE_FUNCTION();

		Renderer::Shutdown();
	}

	void Application::PushLayer(Layer* layer)
	{
		SB_PROFILE_FUNCTION();

		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		SB_PROFILE_FUNCTION();

		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		SB_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(SB_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(SB_BIND_EVENT_FN(Application::OnWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it )
		{
			(*it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::Run() 
	{
		SB_PROFILE_FUNCTION();

		while (m_Running)
		{
			SB_PROFILE_SCOPE("RunLoop");

			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				SB_PROFILE_SCOPE("LayerStack OnUpdate");

				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(timestep);
			
				m_ImGuiLayer->Begin();
				{
					SB_PROFILE_SCOPE("LayerStack OnImGuiRender");

					for (Layer* layer : m_LayerStack)
						layer->OnImGuiRender();
				}
				m_ImGuiLayer->End();
			}
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		SB_PROFILE_FUNCTION();

		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}


}