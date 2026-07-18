#pragma once

#include "Logger.h"

#ifdef IMP_PLATFORM_WINDOWS

extern Impact::Application* Impact::CreateApplication();

int main(int argc, char** argv)
{
	Impact::Logger::Init();

	IMP_CORE_WARN("Initialized Logger!");
	int a = 100;
	IMP_INFO("Hello! Var = {0}", a);

	auto app = Impact::CreateApplication();
	app->Run();
	delete app;
}

#endif
