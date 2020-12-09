#include <stdio.h>
#include <SDL2/SDL.h>

typedef struct Mouse {
	int x;
	int y;
	int leftButton;
	int rightButton;
	int middleButton;
} Mouse;

int main(int argc, char** argv) {
	// setbuf(stdout, NULL);
	if (SDL_Init(SDL_INIT_VIDEO)) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	} else {
		printf("SDL initialization was successful!\n");
	}
	
	SDL_Window* window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_ALLOW_HIGHDPI);
	if (!window) {
		printf("Failed to create SDL2 window: %s\n", SDL_GetError());
		return 1;
	}
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		printf("Failed to create SDL2 renderer: %s\n", SDL_GetError());
		return 1;
	}

	/*
	int keys[322];  // 322 is the number of SDLK_DOWN events
	for(int i = 0; i < 322; i++) { // init them all to false
		keys[i] = 0;
	}
	*/
	
	Mouse mouse = { 0, 0, 0, 0, 0 };
	// This variable will contain the states of individual keyboard keys
	const Uint8* keyboard = NULL;
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
				/* why not to use this method: doesn't work with arrow buttons
				case SDL_KEYDOWN: {
					if(e.key.keysym.sym >= 0 && e.key.keysym.sym <= 322)
						// printf("%d\n", e.key.keysym.sym);
						keys[e.key.keysym.sym] = 1;
				} break;
				case SDL_KEYUP: {
					if(e.key.keysym.sym >= 0 && e.key.keysym.sym <= 322)
						// printf("%d\n", e.key.keysym.sym);
						keys[e.key.keysym.sym] = 0;
				} break;
				*/
			}
		}

		// Get the state of the mouse		
		uint32_t mouseState = SDL_GetMouseState(&mouse.x, &mouse.y);
		mouse.leftButton = mouseState & SDL_BUTTON_LMASK;
		mouse.rightButton = mouseState & SDL_BUTTON_RMASK;
		mouse.middleButton = mouseState & SDL_BUTTON_MMASK;

		// Get the state of the keyboard
		keyboard = SDL_GetKeyboardState(NULL);
		
		if(keyboard[SDL_SCANCODE_A]) {
			printf("a");
		}
		if(keyboard[SDL_SCANCODE_D]) {
			printf("d");
		}
		if(keyboard[SDL_SCANCODE_S]) {
			printf("s");
		}
		if(keyboard[SDL_SCANCODE_W]) {
			printf("w");
		}
		fflush(stdout);

		if(mouse.leftButton) {
			printf("x: %d, y: %d\n", mouse.x, mouse.y);
		}
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); 	// Set global color to black
		SDL_RenderClear(renderer); 							// Clear screen 
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);	// Set new color to green
		SDL_RenderDrawLine(renderer, 200, 100, 400, 300);	// Draw line
		
		SDL_RenderPresent(renderer); // View what we drew on the renderer 
	}
	
	// Close and free resources
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
	
	return 0;
}
