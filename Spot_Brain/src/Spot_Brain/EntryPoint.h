#pragma once
#include "Application.h"
#include "Log.h"

#ifdef SB_PLATFORM_WINDOWS

extern Brainspace::Application* Brainspace::CreateApplication();

int main(int argc, char** argv)
{
	Brainspace::Log::Init();
	SB_CORE_WARN("Initialized Log!");
	int a = 5;
	SB_INFO("Hello! Var={0}", a);

	auto app = Brainspace::CreateApplication();
	app->Run();
	delete app;
}

#endif // SB_PLATFORM_WINDOWS
