#include "imppch.h"
#include "Impact/Renderer/Renderer.h"
#include "Impact/Renderer/Renderer2D.h"

namespace Impact {

	Scope<Renderer::SceneData> Renderer::s_SceneData = nullptr;
	RendererAPI::API Renderer::s_RendererAPI = RendererAPI::API::OpenGL;

	void Renderer::Init()
	{
		RenderCommand::Init();
		Renderer2D::Init();
		s_SceneData = CreateScope<Renderer::SceneData>();
	}

	void Renderer::Shutdown()
	{
		Renderer2D::Shutdown();
	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
		RenderCommand::SetViewport(0, 0, width, height);
	}

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		s_SceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform)
	{
		shader->Bind();
		shader->SetMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
		shader->SetMat4("u_Transform", transform);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}

}
