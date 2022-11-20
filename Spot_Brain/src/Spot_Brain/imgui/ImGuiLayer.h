#pragma once

#include "Spot_Brain/Layer.h"

#include "Spot_Brain/Events/ApplicationEvent.h"
#include "Spot_Brain/Events/KeyEvent.h"
#include "Spot_Brain/Events/MouseEvent.h"

namespace Brainspace {

	class BRAIN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);
	private:
		bool OnMouseButtonPressedEvent (MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent (MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent (MouseMovedEvent& e);
		bool OnMouseScrolledEvent (MouseScrolledEvent& e);
		bool OnKeyPressedEvent (KeyPressedEvent& e);
		bool OnKeyTypedEvent (KeyTypedEvent& e);
		bool OnKeyReleasedEvent (KeyReleasedEvent& e);
		bool OnWindowResizeEvent (WindowResizeEvent& e);
	private:
		float m_Time = 0.0f;

	};

}