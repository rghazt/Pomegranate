#include "include.h"

int main() {
	Chip8 emu;
	emu.setup();
			SDL_Window* window = SDL_CreateWindow("Pomegranate - Chip 8 emulator", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == nullptr){
			std::cout << "Window creating error!" << SDL_GetError() << std::endl;
			return 1;
			}
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	emu.loadrom("pong.rom");
	bool is_running = true;
	SDL_Event event;
	
	while(is_running) {
		while (SDL_PollEvent(&event)) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
            std::vector<uint32> sdl_pixels(WIDTH * HEIGHT, 0);
            gfx[WIDTH * 0 + 0] = 1;
            gfx[WIDTH * 5 + 5] = 1;
            for (int y = 0, y != WIDTH, y++) {
				for (int x = 0, x != HEIGHT, x++) {
					int index = WIDTH * y + x 
					}
					}
            
            SDL_RenderPresent(renderer);
			if (event.type == SDL_QUIT) {
				is_running = false;}
				}

	}
		SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
	
}
		
