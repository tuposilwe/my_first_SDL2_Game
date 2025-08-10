#include <SDL.h>
#include<iostream>
#include<SDL_image.h>

using namespace std;

SDL_Event event;
bool quit = false;

int brickw = 80;
int brickh = 35;

SDL_Surface* brick;
SDL_Texture* bricktexture;
const int numRows = 3;
const int numCols = 8;

SDL_Rect brickrect[numRows][numCols];

void InitializeBrick() {
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0;j < numCols;j++) {
			brickrect[i][j] = { 50 + j * (brickw + 10),50 + i * (brickh + 10),brickw,brickh }; 
		}
	}
}



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

	// Create a renderer
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

	SDL_Rect ballrect = { 20,30,50,50 };
	SDL_Rect skaterect = { 400,530,100,120 };
	SDL_Rect bkrect = { 0,0,800,600 };

	SDL_Surface* ball = SDL_LoadBMP("ball.bmp");
	SDL_Surface* skate = SDL_LoadBMP("Skater.bmp");
	SDL_Surface* bk = SDL_LoadBMP("bk.bmp");
	brick = SDL_LoadBMP("brick.bmp");

	//SDL_Texture* ballTexture = SDL_CreateTextureFromSurface(renderer, ball);
	SDL_Texture* skateTexture = SDL_CreateTextureFromSurface(renderer, skate);
	SDL_Texture* bkTexture = SDL_CreateTextureFromSurface(renderer, bk);
	bricktexture= SDL_CreateTextureFromSurface(renderer, brick);

	//SDL_RenderCopy(renderer, bkTexture, NULL, &bkrect);
	//SDL_RenderCopy(renderer, ballTexture, NULL, &ballrect);
	//SDL_RenderCopy(renderer,skateTexture, NULL, &skaterect);

	//InitializeBrick();

	//for (int i = 0; i < numRows; i++)
	//{
	//	for (int j = 0; j < numCols; j++) {
	//		SDL_RenderCopy(renderer, bricktexture, NULL, &brickrect[i][j]);
	//	}
	//}

	//// Display the updated Renderer 
	//SDL_RenderPresent(renderer);

	/*while (!quit) {
		EventHandler();
	}*/
	 

	// delaying window display 
	//SDL_Delay(8000);


	//SDL_DestroyTexture(texture);

	SDL_Rect rect = {350,250,80,50};
	int rectSpeed = 2; // Speed of the rectangle movement
	int moveDistance = 300; // total distance that the rectangle needs to cover

	int movedDistance = 0; // Keep track of the distance covered by rect
	bool moveRight = true;

	// Game Loop
	//while (!quit) {
	//	EventHandler();

	//	//Clear the screen
	//	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	//	SDL_RenderClear(renderer);

	//	if (moveRight) {
	//		rect.x += rectSpeed;
	//		movedDistance += rectSpeed;

	//		if (movedDistance >= moveDistance) {
	//			moveRight = false;
	//		}
	//	}
	//	else
	//	{
	//		rect.x -= rectSpeed;
	//		movedDistance -= rectSpeed;

	//		if (movedDistance <= 0) {
	//			moveRight = true;
	//		}
	//	}

	//	// Draw Rectangle
	//	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	//	SDL_RenderFillRect(renderer, &rect);

	//	//Present the updated Renderer
	//	SDL_RenderPresent(renderer);

	//	// Delaying the frame rate control
	//	SDL_Delay(16);
	//}


	// Load ball image as texture
	SDL_Surface* ballSurface = SDL_LoadBMP("ball.bmp");
	if (!ballSurface) {
		cerr << "Failed to load ball image: " << SDL_GetError() << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 1;
	}
	SDL_Texture* ballTexture = SDL_CreateTextureFromSurface(renderer, ballSurface);
	SDL_FreeSurface(ballSurface);

	SDL_Rect ballRect = {400,500,50,50};
	int speed = 2;
	int distanceCovered = 0;

	enum Direction
	{
		UP,RIGHT,DOWN,LEFT
	}direction = UP;


	// Main game Loop
	while (!quit) {
		// Event Handling
		EventHandler();
		switch (direction)
		{
		case UP:
			ballRect.y -= speed;
			break;
		case RIGHT:
			ballRect.x += speed;
			break;
		case DOWN:
			ballRect.y += speed;
			break;
		case LEFT:
			ballRect.x -= speed;
			break;
		default:
			break;
		}

		distanceCovered += speed;
		if (distanceCovered >= 250) {
			direction = static_cast<Direction>((direction + 1) % 4);
			distanceCovered = 0;
		}

		// Clear the Screen
		SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, ballTexture, NULL, &ballRect);

		SDL_RenderPresent(renderer);

		SDL_Delay(16); // 60 Frames Per Second


	}

	// Cleaning resources
	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);
	IMG_Quit(); 
	SDL_Quit();

	return 0;
}

