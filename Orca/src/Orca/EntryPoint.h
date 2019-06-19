#pragma once
#ifdef OC_PLATFORM_WINDOWS

extern Orca::Application* Orca::createApplication();

int main(int argc, char** argv)
{
	std::cout << "Orca";
	auto app = Orca::createApplication();
	app->run();
	delete app;
}

#endif