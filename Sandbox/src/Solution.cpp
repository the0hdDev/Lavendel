#include <Lumen.h>

class Sandbox : public Lumen::Application
{
public: 
		Sandbox() {}
		~Sandbox() {}
};


Lumen::Application* Lumen::CreateApplication()
{
	return new Sandbox();
}