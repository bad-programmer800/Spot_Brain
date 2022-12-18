#pragma once
#include "Spot_Brain/Core/Base.h"

#ifdef SB_PLATFORM_WINDOWS

extern Brain::Application* Brain::CreateApplication();

int main(int argc, char** argv)
{
	Brain::Log::Init();

	SB_PROFILE_BEGIN_SESSION("Startup", "BrainProfile-Startup.json");
	auto app = Brain::CreateApplication();
	SB_PROFILE_END_SESSION();

	SB_PROFILE_BEGIN_SESSION("Runtime", "BrainProfile-Runtime.json");
	app->Run();
	SB_PROFILE_END_SESSION();

	SB_PROFILE_BEGIN_SESSION("Shutdown", "BrainProfile-Shutdown.json");
	delete app;
	SB_PROFILE_END_SESSION();
}

#endif // SB_PLATFORM_WINDOWS
