#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char** argv) {
	// setbuf(stdout, NULL);
	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
		printf("SDL initialization was successful!\n");
	} else {
	}
	
	SDL_Window* window = SDL_CreateWindow("SDL2 Window", // window name
										SDL_WINDOWPOS_UNDEFINED, // initial x position
										SDL_WINDOWPOS_UNDEFINED, // initial y position
										640, // window screen width
										480, // window screen height
										SDL_WINDOW_ALLOW_HIGHDPI); // window flags
	if (!window) {
		printf("Failed to create SDL2 window: %s\n", SDL_GetError());
		return 1;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, // window to render to
												-1, // always set to -1 so you select the first rendering driver
												SDL_RENDERER_ACCELERATED); // renderer flags
	if (!renderer) {
		printf("Failed to create SDL2 renderer: %s\n", SDL_GetError());
		return 1;
	}
	
	// Creating a variable that will contain events
	SDL_Event e;
	int alive = 1;
	while (alive) {
		// go through events
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
				// Close program when user wants to close it
				case SDL_QUIT:
					alive = 0;
				break;
			}
		}
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 	// Set global color to black
		SDL_RenderClear(renderer); 							// Clear screen 
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);	// Set new color to green
		SDL_RenderDrawLine(renderer, 200, 100, 400, 300);	// Draw line
		
		SDL_RenderPresent(renderer); // View what we drew on the renderer 
	}
	
	// Close and free resources
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	
	SDL_Quit();
	
	return 0;
}
