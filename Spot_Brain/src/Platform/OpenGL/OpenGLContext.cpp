#include "sbpch.h"

#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Brain {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SB_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		SB_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SB_CORE_ASSERT(status, "Failed to initialize glad!");

		//SB_CORE_INFO("OpenGL Info:");
		//SB_CORE_INFO(" Vendor: {0}", glGetString(GL_VENDOR));
		//SB_CORE_INFO(" Renderer: {0}", glGetString(GL_RENDERER));
		//SB_CORE_INFO(" Version: {0}", glGetString(GL_VERSION));

		SB_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		SB_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}


}