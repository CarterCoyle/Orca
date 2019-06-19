#pragma once
#ifdef OC_PLATFORM_WINDOWS

extern Orca::Application* Orca::createApplication();

int main(int argc, char** argv)
{
	Orca::Log::init();
	std::cout << "Orca\n";
	OC_CORE_WARN("Core Logger Works");
	int a = 69;
	OC_CLIENT_INFO("Client Logger Works Var={0}", a);
	auto app = Orca::createApplication();
	app->run();
	delete app;
}

#endif