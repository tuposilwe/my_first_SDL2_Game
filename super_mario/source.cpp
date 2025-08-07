#include <SDL.h>

int main(int argc, char* argv[])
{
	// sdl creation
	SDL_Init(SDL_INIT_VIDEO);

	// window creation

	SDL_Window* window = SDL_CreateWindow(
		"SDL Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_SHOWN
	);

	// delaying window display
	SDL_Delay(3000);

	SDL_Quit();

	return 0;
}

