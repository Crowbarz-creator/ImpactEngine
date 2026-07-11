#include <Impact.h>

class Sandbox : public Impact::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}

};

Impact::Application* Impact::CreateApplication()
{
	return new Sandbox();
}