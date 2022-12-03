#include "sbpch.h"
#include "Spot_Brain/Renderer/GraphicsContext.h"

#include "Spot_Brain/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Brain {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:	SB_CORE_ASSERT(false, "RendererAPI::None is not currently supported!"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}
		SB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


}