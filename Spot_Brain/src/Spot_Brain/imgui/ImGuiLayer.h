#pragma once

#include "Spot_Brain/Core/Layer.h"

#include "Spot_Brain/Events/ApplicationEvent.h"
#include "Spot_Brain/Events/KeyEvent.h"
#include "Spot_Brain/Events/MouseEvent.h"

namespace Brain {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}