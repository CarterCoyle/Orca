#include <Orca.h>
class sandbox : public Orca::Application
{
public:
	sandbox()
	{

	}
	~sandbox()
	{

	}
};


Orca::Application* Orca::createApplication()
{
	return new sandbox();
}