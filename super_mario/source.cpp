#include <SDL.h>
#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	// sdl creation
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Initialization failed!";
		return 1;
	}

	// window creation

	SDL_Window* window = SDL_CreateWindow(
		"SDL Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		640,
		480,
		SDL_WINDOW_RESIZABLE
	);

	// delaying window display
	//SDL_Delay(3000);
	//SDL_ShowWindow(window);

	if (!window) {
		cout << "failed to create the window";
		SDL_Quit();

		return 1;
	}

	cout << "Window created Successfully"<< "\n";

	SDL_Renderer* renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED);

	if (!renderer) {
		cout << "Failed to create the renderer";
		SDL_DestroyWindow(window);
		SDL_Quit();

		return 1;
	}
	else {
		cout << "Successfully Created the renderer";
	}

	SDL_SetRenderDrawColor(renderer,255,0,0,255);


	// delaying window display
	SDL_Delay(3000);

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}

