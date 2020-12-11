#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char** argv) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	
	// We will create a window and a renderer, it should be self explanatory by the names what they are for
	SDL_Window* window;
	SDL_Renderer* renderer;
	
	window = SDL_CreateWindow("SDL2 Window", 			// window name
							SDL_WINDOWPOS_UNDEFINED, 	// initial x position
							SDL_WINDOWPOS_UNDEFINED, 	// initial y position
							640, 						// window screen width
							480, 						// window screen height
							SDL_WINDOW_ALLOW_HIGHDPI); 	// window flags 
	if (!window) {
		printf("Failed to create SDL2 window: %s\n", SDL_GetError());
		return 1;
	}
	renderer = SDL_CreateRenderer(window, 					// window to render to
								-1, 						// always set to -1 so you select the first rendering driver
								SDL_RENDERER_ACCELERATED); 	// renderer flags
	if (!renderer) {
		printf("Failed to create SDL2 renderer: %s\n", SDL_GetError());
		return 1;
	}
	
	SDL_Event e; 	// Creating a variable that will contain events
	int alive = 1; 	// This variable basically says if our program should run or not
	while (alive) {
		// Poll events (go through each event that has been raised)
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
	// NOTE: delete in the reverse order you created, 
	// that means if you created your window first and your renderer second,
	// you have to delete your renderer first and window second, you have to do it this way
	// because the internals of the renderer rely on the window!
	SDL_DestroyRenderer(renderer); // Free renderer first
	SDL_DestroyWindow(window); // Free window second
	
	SDL_Quit();
	
	return 0;
}
