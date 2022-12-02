#include "sbpch.h"
#include "Texture.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Brain {

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:	SB_CORE_ASSERT(false, "RendererAPI::None is not currently supported!");
			case RendererAPI::API::OpenGL:	return std::make_shared<OpenGLTexture2D>(path);
		}

		SB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;

	}




}