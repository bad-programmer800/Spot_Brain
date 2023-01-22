#pragma once

#include <glm/glm.hpp>

#include "Spot_Brain/Core/KeyCodes.h"
#include "Spot_Brain/Core/MouseCodes.h"

namespace Brain {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);
		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();

	};
}