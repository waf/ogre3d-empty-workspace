#include "Application.h"

Application::Application(void)
{
}
Application::~Application(void)
{
}
void Application::createScene(void)
{
}
int main(int argc, char *argv[])
{
	// Create application object
	Application app;

	try {
		app.go();
	} catch( Ogre::Exception& e ) {
		std::cerr << "Exception: " 
			<< e.getFullDescription().c_str() 
			<< std::endl;
	}

	return 0;
}
