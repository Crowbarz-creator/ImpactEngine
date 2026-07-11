#pragma once

#include "Core.h"

namespace Impact {
	class IMPACT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
