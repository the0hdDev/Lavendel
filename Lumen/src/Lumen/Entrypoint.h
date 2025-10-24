#pragma once
#include <stdio.h>

#ifdef LM_PLATFORM_WINDOWS

extern Lumen::Application* Lumen::CreateApplication();

int main(int argc, char** argv)
{
	printf("Starting Lumen Application...\n");
	auto app = Lumen::CreateApplication();
	app->Run();
	delete app;
}

#endif


#ifdef LM_PLATFORM_LINUX

extern Lumen::Application* Lumen::CreateApplication();

int main(int argc, char** argv)
{
	printf("Starting Lumen Application...\n");
	auto app = Lumen::CreateApplication();
	app->Run();
	delete app;
}

#endif 


#ifdef LM_PLATFORM_OSX
extern Lumen::Application* Lumen::CreateApplication();

int main(int argc, char** argv)
{
	printf("Starting Lumen Application...\n");
	auto app = Lumen::CreateApplication();
	app->Run();
	delete app;
}
#endif 
