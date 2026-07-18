#include <Impact.h>

class ExampleLayer : public Impact::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		IMP_INFO("ExampleLayer::Update");
	}

	void OnEvent(Impact::Event& event) override
	{
		IMP_TRACE("{0}", event);
	}

};

class Sandbox : public Impact::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	}

};

Impact::Application* Impact::CreateApplication()
{
	return new Sandbox();
}