#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char** argv) {
	
	// Initializing SDL, we only need graphics, so we specify the SDL_INIT_VIDEO flag
	if (SDL_Init(SDL_INIT_VIDEO)) {
		// Exit if unable to initialize SDL
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	} else {
		printf("SDL initialization was successful!\n");
	}
	
	// Let SDL clean up after itself after the program is finished
	SDL_Quit();
	
	return 0;
}
