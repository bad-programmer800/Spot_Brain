#include "sbpch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Brain {

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:	SB_CORE_ASSERT(false, "RendererAPI::None is not currently supported!");
		case RendererAPI::API::OpenGL:	return CreateRef<OpenGLTexture2D>(width, height);
		}

		SB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}


	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:	SB_CORE_ASSERT(false, "RendererAPI::None is not currently supported!");
			case RendererAPI::API::OpenGL:	return CreateRef<OpenGLTexture2D>(path);
		}

		SB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}
}