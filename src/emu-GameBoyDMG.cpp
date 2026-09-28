#include "GameBoy.h"

GameBoy emu;

int main() {
	SDL_Window* window = SDL_CreateWindow("Pomegranate - GameBoy emulator", WIDTH, HEIGHT, 0);
		if (window == nullptr){
			std::cout << "Window creating error!" << SDL_GetError() << std::endl;
			return 1;
			}
			SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
			SDL_SetRenderVSync(renderer, 1);
	        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, DMG_WIDTH, DMG_HEIGHT);
            SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
            std::vector<Uint32> sdl_pixels(WIDTH * HEIGHT, 0);
			bool is_running = true;
			while(is_running) {
				emu.PC++;
				}
	return 0;
	}
