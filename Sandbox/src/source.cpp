#include <Orca.h>

class sandboxLayer : public Orca::layer
{
public:
	sandboxLayer(const std::string& name )
		: Orca::layer(name) {}
	
	void onUpdate() override
	{

	}

	void onEvent(Orca::Event& e) override
	{
	}
};

class sandbox : public Orca::Application
{
public:
	sandbox()
	{
		pushLayer(new sandboxLayer("sandboxLayer"));
	}
	~sandbox()
	{

	}
};


Orca::Application* Orca::createApplication()
{
	return new sandbox();
}

