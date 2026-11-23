#pragma once

#include "Impact/Renderer/RenderCommand.h"
#include "Impact/Renderer/OrthographicCamera.h"
#include "Impact/Renderer/Shader.h"
#include "Impact/Core.h" 

namespace Impact {

	class Renderer
	{
	public:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static void Init();
		static void Shutdown();
		static void OnWindowResize(uint32_t width, uint32_t height);

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		inline static RendererAPI::API GetAPI() { return s_RendererAPI; }

	private:
		static Scope<SceneData> s_SceneData;
		static RendererAPI::API s_RendererAPI;
	};

}
