#pragma once
#include "config.h"

class SDL {
private:
	std::map<SDL_Window*, std::string> windows;
	std::map<SDL_GLContext, std::string> context;

public:
	//constructor will initialize sdl
	SDL(Uint32 flags) {
		if (SDL_Init(flags) < 0) {
			std::cout << "failed to init SDL with flags: " << flags << std::endl;
		}
		else {
			std::cout << "SDL init with flags: " << flags << std::endl;
		}

		//set sdl attributes for openGL
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	}
	SDL(const SDL& copy) {
		this->windows = copy.windows;
	}
	~SDL() {
		//destroy windows
		std::map<SDL_Window*, std::string>::iterator i = windows.begin();
		while (i != windows.end()) {
			SDL_DestroyWindow(i->first);
			i++;
		}
		windows.clear();

		//delete gl context
		std::map<SDL_GLContext, std::string>::iterator j = context.begin();
		while (j != context.end()) {
			SDL_GL_DeleteContext(j->first);
			j++;
		}
		context.clear();
	}
	//getters
	SDL_Window* getWindow(std::string handle);
	SDL_GLContext getContext(std::string handle);

	//setters
	bool removeWindow(std::string handle);

	//create new window
	bool createWindow(std::string handle, std::string title, int xPos, int yPos, 
		int nWidth, int nHeight, Uint32 flags);

	//create gl context
	bool createContext(std::string handle);

};