#include "sbpch.h"
#include "Spot_Brain/Renderer/VertexArray.h"

#include "Spot_Brain/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Brain {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:		SB_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:		return CreateRef<OpenGLVertexArray>();
		}

		SB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}