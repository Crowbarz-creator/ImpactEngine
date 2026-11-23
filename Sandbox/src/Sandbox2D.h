#pragma once

#include "Impact.h"

class Sandbox2D : public Impact::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Impact::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Impact::Event& e) override;
private:
	Impact::OrthographicCameraController m_CameraController;

	// Temp
	Impact::Ref<Impact::VertexArray> m_SquareVA;
	Impact::Ref<Impact::Shader> m_FlatColorShader;

	Impact::Ref<Impact::Texture2D> m_CheckerboardTexture;

	struct ProfileResult
	{
		std::string Name;
		float Time;
	};

	std::vector<ProfileResult> m_ProfileResults;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};