#include <SDL.h>
#include<iostream>
#include<SDL_image.h>

using namespace std;

SDL_Event event;
bool quit = false;

void EventHandler() {
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT) {
		quit = true;
	}
}

int main(int argc, char* argv[])
{
	// sdl creation
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Initialization failed!";
		return 1;
	}
	/*int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP;

	if (IMG_Init(imgFlags) && imgFlags != imgFlags) {
		cout << "SDL Image could not be initialized";
		SDL_Quit();
		return 1;
	};*/

	// window creation
	SDL_Window* window = SDL_CreateWindow(
		"SDL Window",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
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

	//SDL_Surface* surface = IMG_Load("enemy.png");

	//SDL_Surface* winsurface = SDL_LoadBMP("win.bmp");

	//if (!winsurface) {
	//	cout << "Image Loading Failed";
	//	return 1;
	//}
	//SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,winsurface);
	//SDL_FreeSurface(winsurface);


	//if (!texture) {
	//	cout << "Texture Creation Failed";
	//	return 1;
	//}

	//SDL_SetRenderDrawColor(renderer,255,192,203,255);
	 
	// Clearing out the previous Renderer so that it can display the updated Renderer
	/*SDL_RenderClear(renderer);

	SDL_Rect dstRect = { 200,300,150,120 };

	SDL_RenderCopy(renderer, texture, NULL, &dstRect);*/ // Blit texture onto the SDL Screen


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

	SDL_Rect ballrect = { 20,30,60,70 };
	SDL_Rect skaterect = { 400,530,100,120 };
	SDL_Rect bkrect = { 0,0,800,600 };

	SDL_Surface* ball = SDL_LoadBMP("ball.bmp");
	SDL_Surface* skate = SDL_LoadBMP("Skater.bmp");
	SDL_Surface* bk = SDL_LoadBMP("bk.bmp");

	SDL_Texture* ballTexture = SDL_CreateTextureFromSurface(renderer, ball);
	SDL_Texture* skateTexture = SDL_CreateTextureFromSurface(renderer, skate);
	SDL_Texture* bkTexture = SDL_CreateTextureFromSurface(renderer, bk);

	SDL_RenderCopy(renderer, bkTexture, NULL, &bkrect);
	SDL_RenderCopy(renderer, ballTexture, NULL, &ballrect);
	SDL_RenderCopy(renderer,skateTexture, NULL, &skaterect);

	// Display the updated Renderer 
	SDL_RenderPresent(renderer);

	while (!quit) {
		EventHandler();
	}
	 

	// delaying window display 
	//SDL_Delay(8000);

	// Cleaning things up

	//SDL_DestroyTexture(texture);

	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}

