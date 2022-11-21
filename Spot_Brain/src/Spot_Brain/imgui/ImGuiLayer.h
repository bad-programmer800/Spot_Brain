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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}