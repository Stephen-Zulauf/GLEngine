#include "SDL.h"

//getters
SDL_Window* SDL::getWindow(std::string handle) {
	std::map<SDL_Window*, std::string>::iterator i = this->windows.begin();
	while (i != windows.end()) {
		if (i->second == handle) {
			return i->first;
		}
		i++;
	}
	std::cout << "ERR SDL: get window could not find window" << std::endl;
	return nullptr;
}

SDL_GLContext SDL::getContext(std::string handle) {
	std::map<SDL_GLContext, std::string>::iterator i = this->context.begin();
	while (i != context.end()) {
		if (i->second == handle) {
			return i->first;
		}
		i++;
	}
	std::cout << "ERR SDL: get context could not find window" << std::endl;
	return nullptr;
}

//setters
bool SDL::removeWindow(std::string handle) {
	std::map<SDL_Window*, std::string>::iterator i = this->windows.begin();
	while (i != windows.end()) {
		if (i->second == handle) {
			SDL_DestroyWindow(i->first);
			windows.erase(i);
			return true;
		}
		i++;
	}
	std::cout << "ERR SDL: remove window could not find window" << std::endl;
	return false;
}

//create new window
bool SDL::createWindow(std::string handle, std::string title, int xPos, int yPos,
	int nWidth, int nHeight, Uint32 flags) {

	SDL_Window* temp = SDL_CreateWindow(title.c_str(), xPos, yPos, nWidth, nHeight, flags);

	if (!temp) {
		std::cout << "ERR SDL: create Window could not create window" << std::endl;
		return false;
	}
	else {
		this->windows.insert({ temp, handle });
		return true;
	}
}

//create gl context
bool SDL::createContext(std::string handle) {
	SDL_Window* window = nullptr;

	std::map<SDL_Window*, std::string>::iterator i = this->windows.begin();
	while (i != windows.end()) {
		if (i->second == handle) {
			window = i->first;
		}
		i++;
	}

	if (window) {
		SDL_GLContext temp = SDL_GL_CreateContext(window);
		if (!temp) {
			std::cout << "ERR SDL: createContext failed to create context" << std::endl;
			return false;
		}
		else {
			context.insert({ temp, handle });

			if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
				std::cout << "ERR SDL: createContext failed to load glad handles" << std::endl;
				return false;
			}

			return true;
		}
	}
	else {
		std::cout << "ERR SDL: createContext failed to find window" << std::endl;
		return false;
	}

	
	
}