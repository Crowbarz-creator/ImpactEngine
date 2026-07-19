#include "imppch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Impact {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}