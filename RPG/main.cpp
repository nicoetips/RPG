#include "global.h"

using namespace std;

int main(int argc, char* args[])
{
	atexit(SDL_Quit);

	bool quit = false;


	// SDL init

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "couldn't start SDL: %s\n" << SDL_GetError();
		exit(1);
	}


	// creating main window

	SDL_Window *window = NULL;

	window = SDL_CreateWindow("RPG",
		100,
		100,
		800, 600,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (window == NULL)
	{
		cout << "window couldn't be created\n";
		exit(1);
	}


	// renderer statement

	SDL_Renderer *renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	// event statement

	SDL_Event *mainEvent = new SDL_Event();


	// main loop

	while (!quit && mainEvent->type != SDL_QUIT)
	{
		SDL_PollEvent(mainEvent);

		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}


	// destruction of objects

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;


	SDL_Quit();

	return 0;
}