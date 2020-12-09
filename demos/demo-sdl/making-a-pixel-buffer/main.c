#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	const int TEXTURE_WIDTH = WINDOW_WIDTH;
	const int TEXTURE_HEIGHT = WINDOW_HEIGHT;
	
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
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ABGR32, SDL_TEXTUREACCESS_STREAMING, 640, 480);
	if(!texture) {
		printf("Failed to create SDL2 texture: %s\n", SDL_GetError());
		return 1;
	}
	
	uint32_t* pixels = (uint32_t*)malloc(TEXTURE_WIDTH * TEXTURE_HEIGHT * sizeof(uint32_t));
	memset(pixels, 0, TEXTURE_WIDTH * TEXTURE_HEIGHT * sizeof(uint32_t));
	
	Mouse mouse = { 0, 0, 0, 0, 0 };
	const Uint8* keyboard = NULL;
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
		uint32_t mouseState = SDL_GetMouseState(&(mouse.x), &(mouse.y));
		mouse.leftButton = mouseState & SDL_BUTTON_LMASK;
		mouse.rightButton = mouseState & SDL_BUTTON_RMASK;
		mouse.middleButton = mouseState & SDL_BUTTON_MMASK;

		keyboard = SDL_GetKeyboardState(NULL);
		
		// memset(pixels, 0, TEXTURE_WIDTH * TEXTURE_HEIGHT * sizeof(uint32_t));
		
		// if (mouse.leftButton) 
		// 	pixels[mouse.x + mouse.y * TEXTURE_WIDTH] = 0x00ff00ff;
		
		// for (int i = 0; i < TEXTURE_WIDTH; i++) {
		// 	for (int j = 0; j < TEXTURE_HEIGHT; j++) {
		// 		pixels[i + j * TEXTURE_WIDTH] = (rand() % 0xffffff) * 0xff + 0xff;
		// 	}
		// }
		
		pixels[(rand() % TEXTURE_WIDTH) + (rand() % TEXTURE_HEIGHT) * TEXTURE_WIDTH] = (rand() % 0xffffff) * 0xff + 0xff;
		
		
		SDL_UpdateTexture(texture, NULL, pixels, TEXTURE_WIDTH * sizeof(uint32_t));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}
	
	// Close and free resources
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	
	SDL_Quit();
	
	return 0;
}
