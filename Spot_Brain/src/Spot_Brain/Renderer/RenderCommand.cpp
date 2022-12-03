#include "sbpch.h"
#include "Spot_Brain/Renderer/RenderCommand.h"

namespace Brain {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}