#pragma once

#include "Core.h"

namespace Brainspace {
	
	class BRAIN_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();

	};

	// To be defined by client.
	Application* CreateApplication();

}

