#pragma once
#include "Spot_Brain/Core/Core.h"

#ifdef SB_PLATFORM_WINDOWS

extern Brain::Application* Brain::CreateApplication();

int main(int argc, char** argv)
{
	Brain::Log::Init();
	SB_CORE_WARN("Initialized Log!");
	int a = 5;
	SB_INFO("Hello! Var={0}", a);

	auto app = Brain::CreateApplication();
	app->Run();
	delete app;
}

#endif // SB_PLATFORM_WINDOWS
