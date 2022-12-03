#include "sbpch.h"
#include "Spot_Brain/Renderer/RendererAPI.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Brain {

	RendererAPI::API RendererAPI::s_API = RendererAPI::API::OpenGL;

	Scope<RendererAPI> RendererAPI::Create()
	{
		switch (s_API)
		{
		case RendererAPI::API::None:	SB_CORE_ASSERT(false, "RendererAPI::None is not currently supported!"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateScope<OpenGLRendererAPI>();
		}

		SB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}