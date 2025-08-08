#include <SDL.h>
#include<iostream>
#include<SDL_image.h>

using namespace std;

int main(int argc, char* argv[])
{
	// sdl creation
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Initialization failed!";
		return 1;
	}
	int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;

	if (IMG_Init(imgFlags) && imgFlags != imgFlags) {
		cout << "SDL Image could not be initialized";
		SDL_Quit();
		return 1;
	};

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

	SDL_Surface* surface = IMG_Load("enemy.png");

	if (!surface) {
		cout << "Image Loading Failed";
		return 1;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);


	if (!texture) {
		cout << "Texture Creation Failed";
		return 1;
	}

	SDL_SetRenderDrawColor(renderer,255,192,203,255);
	 
	// Clearing out the previous Renderer so that it can display the updated Renderer
	SDL_RenderClear(renderer);

	SDL_Rect dstRect = { 200,300,150,120 };

	SDL_RenderCopy(renderer, texture, NULL, &dstRect); // Blit texture onto the SDL Screen


	/*SDL_SetRenderDrawColor(renderer,255,0,0,255);*/


	/*for (int i = 100; i < 400; i++)
	{
		SDL_RenderDrawPoint(renderer, 100,i);
		SDL_RenderDrawPoint(renderer, 200, i);
	}*/


	/*SDL_RenderDrawLine(renderer,50,50,300,50);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);*/

	//SDL_Rect rect = { 100,100,200,150 };

	//SDL_RenderDrawRect(renderer,&rect);

	// Display the updated Renderer 
	SDL_RenderPresent(renderer);
	 

	// delaying window display 
	SDL_Delay(8000);

	// Cleaning things up

	SDL_DestroyTexture(texture);

	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}

