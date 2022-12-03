#include "sbpch.h"
#include "Spot_Brain/Renderer/Buffer.h"

#include "Spot_Brain/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Brain {

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:		SB_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:		return CreateRef<OpenGLVertexBuffer>(vertices, size);
		}

		SB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:		SB_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:		return CreateRef<OpenGLIndexBuffer>(indices, size);
		}

		SB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


}