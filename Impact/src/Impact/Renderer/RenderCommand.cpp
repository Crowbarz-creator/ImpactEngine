#include "imppch.h"
#include "Impact/Renderer/RenderCommand.h"

namespace Impact {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}