#include "sbpch.h"
#include "Spot_Brain/Renderer/FrameBuffer.h"

#include "Spot_Brain/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFrameBuffer.h"

namespace Brain {

	Ref<FrameBuffer> FrameBuffer::Create(const FrameBufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:	SB_CORE_ASSERT(false, "RendererAPI::None is not currently supported!"); return nullptr;
		case RendererAPI::API::OpenGL:	return CreateRef<OpenGLFrameBuffer>(spec);
		}

		SB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}