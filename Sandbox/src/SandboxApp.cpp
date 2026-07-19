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
		if (Impact::Input::IsKeyPressed(IMP_KEY_TAB))
			IMP_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Impact::Event& event) override
	{
		if (event.GetEventType() == Impact::EventType::KeyPressed)
		{
			Impact::KeyPressedEvent& e = (Impact::KeyPressedEvent&)event;
			if (e.GetKeyCode() == IMP_KEY_TAB)
				IMP_TRACE("Tab key is pressed (event)!");
			IMP_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Impact::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		//PushOverlay(new Impact::ImGuiLayer());
	}

	~Sandbox()
	{
	}

};

Impact::Application* Impact::CreateApplication()
{
	return new Sandbox();
}