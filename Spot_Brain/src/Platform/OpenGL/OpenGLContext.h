#pragma once

#include "Spot_Brain/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Brain {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		GLFWwindow* m_WindowHandle;
	};
}