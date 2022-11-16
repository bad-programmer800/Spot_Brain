#include <Spotbrain.h>

class Homebrain : public Brainspace::Application
{
public:
	Homebrain() {

	}

	~Homebrain() {

	}

};



Brainspace::Application* Brainspace::CreateApplication()
{
	return new Homebrain();
}
