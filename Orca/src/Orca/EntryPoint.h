#pragma once
#ifdef OC_PLATFORM_WINDOWS

extern Orca::Application* Orca::createApplication();

int main(int argc, char** argv)
{
	Orca::Log::init();
	auto app = Orca::createApplication();
	app->run();
	delete app;
}


#endif