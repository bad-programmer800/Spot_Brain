#include "sbpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Brainspace {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}