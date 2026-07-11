#pragma once

#ifdef IMP_PLATFORM_WINDOWS

extern Impact::Application* Impact::CreateApplication();

int main(int argc, char** argv)
{
	printf("Impact Engine\n");
	auto app = Impact::CreateApplication();
	app->Run();
	delete app;
}

#endif // IMP_PLATFORM_WINDOWS
