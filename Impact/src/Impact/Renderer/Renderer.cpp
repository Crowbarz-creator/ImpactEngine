#include "imppch.h"
#include "Renderer.h"

namespace Impact {

	RendererAPI::API Renderer::s_RendererAPI = RendererAPI::API::OpenGL;

	void Renderer::BeginScene()
	{
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray)
	{
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

}