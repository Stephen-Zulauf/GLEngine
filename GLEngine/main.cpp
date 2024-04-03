
#include "config.h"
#include "SDL.h"

int main(int argc, char** args) {

	/*initProgrum();

	vertexSpecification();

	createGraphicsPipeline();

	mainLoop();

	cleanUp();*/
	SDL test(SDL_INIT_VIDEO);
	test.createWindow("main", "test", 30, 30, 640, 480, SDL_WINDOW_OPENGL);
	test.createContext("main");

	//query opengl context (testing info)
	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Shading language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

	
	return 0;
}