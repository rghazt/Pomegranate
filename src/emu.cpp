#include "CHIP8.h"
#include <vector>
#include <iostream>
uint8_t key_state[16] = {0};
Chip8 emu;
	SDL_AudioSpec spec {
		.format = SDL_AUDIO_U8,
		.channels = 1,
		.freq = 44800
};

int main() {
	emu.setup();
			SDL_Window* window = SDL_CreateWindow("Pomegranate - Chip 8 emulator", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
		if (window == nullptr){
			std::cout << "Window creating error!" << SDL_GetError() << std::endl;
			return 1;
			}
			bool draw = false;
			SDL_AudioStream* stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, NULL, NULL);
			SDL_ResumeAudioStreamDevice(stream);
			SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
			SDL_SetRenderVSync(renderer, 1);
	        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
            SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
            std::vector<Uint32> sdl_pixels(WIDTH * HEIGHT, 0);
	bool is_running = true;
	SDL_Event event;
	int x;
	int y;
	while(is_running) {
		while (SDL_PollEvent(&event)) {
	         switch (event.type) {
				 case SDL_EVENT_QUIT:
			     is_running = false;
	             break;
	             case SDL_EVENT_DROP_FILE: {
	             const char* dropped_file_path = event.drop.data;
				 memset(emu.gfx, 0, sizeof(emu.gfx));				
				 emu.setup();
				 emu.loadrom(dropped_file_path);
                 break;
			 }
                 case SDL_EVENT_KEY_DOWN:
                 switch(event.key.key) {
					 case SDLK_1:
					 key_state[1] = 1;
					 break;
					 case SDLK_2:
					 key_state[2] = 1;
					 break;
					 case SDLK_3:
					 key_state[3] = 1;
					 break;
					 case SDLK_4:
					 key_state[12] = 1;
					 break;
					 case SDLK_Q:
					 key_state[4] = 1;
					 break;
					 case SDLK_W:
					 key_state[5] = 1;
					 break;
					 case SDLK_E:
					 key_state[6] = 1;
					 break;
					 case SDLK_R:
					 key_state[13] = 1;
					 break;
					 case SDLK_A:
					 key_state[7] = 1;
					 break;
					 case SDLK_S:
					 key_state[8] = 1;
					 break;
					 case SDLK_D:
					 key_state[9] = 1;
					 break;
					 case SDLK_F:
					 key_state[14] = 1;
					 break;
					 case SDLK_Z:
					 key_state[10] = 1;
					 break;
					 case SDLK_X:
					 key_state[0] = 1;
					 break;
					 case SDLK_C:
					 key_state[11] = 1;
					 break;
					 case SDLK_V:
					 key_state[15] = 1;
					 break;
					  }
					  break;
					  case SDL_EVENT_KEY_UP:
                 switch(event.key.key) {
										 case SDLK_1:
					 key_state[1] = 0;
					 break;
					 case SDLK_2:
					 key_state[2] = 0;
					 break;
					 case SDLK_3:
					 key_state[3] = 0;
					 break;
					 case SDLK_4:
					 key_state[12] = 0;
					 break;
					 case SDLK_Q:
					 key_state[4] = 0;
					 break;
					 case SDLK_W:
					 key_state[5] = 0;
					 break;
					 case SDLK_E:
					 key_state[6] = 0;
					 break;
					 case SDLK_R:
					 key_state[13] = 0;
					 break;
					 case SDLK_A:
					 key_state[7] = 0;
					 break;
					 case SDLK_S:
					 key_state[8] = 0;
					 break;
					 case SDLK_D:
					 key_state[9] = 0;
					 break;
					 case SDLK_F:
					 key_state[14] = 0;
					 break;
					 case SDLK_Z:
					 key_state[10] = 0;
					 break;
					 case SDLK_X:
					 key_state[0] = 0;
					 break;
					 case SDLK_C:
					 key_state[11] = 0;
					 break;
					 case SDLK_V:
					 key_state[15] = 0;
					 break;
					  }
			}
				}
		if (draw == true) {
            for (int y = 0; y < HEIGHT; y++) {
				for (int x = 0; x != WIDTH; x++) {
					int index = WIDTH * y + x;
					if (emu.gfx[index] == 1) {
						sdl_pixels[index] = 0xFFFFFFFF;
						} else {
							sdl_pixels[index] = 0xFF000000;
							}
					}
				}
				draw = false;
			}
			for (int i = 0; i < BUFFER_SIZE; i++) {
				buffer[i] = sin(2.0f * M_PI * SAMPLE_RATE * freq * sndtime) * 3;
				sndtime += timestep;
				}

	SDL_UpdateTexture(texture, nullptr, sdl_pixels.data(), (int)(WIDTH * sizeof(Uint32)));
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, nullptr, nullptr);
	SDL_RenderPresent(renderer);
	


	for (int cycle = 0; cycle < 10; cycle++) { 
		    bool keyPressed;
        uint16_t opcode = (emu.RAM[emu.PC] << 8) | emu.RAM[emu.PC + 1];	
		uint8_t regx = (opcode >> 8) & 0x000F;
		uint8_t regy = (opcode >> 4) & 0x000F;
		uint8_t n   = opcode & 0x000F;
        uint8_t nn  = opcode & 0x00FF;
        uint16_t nnn = opcode & 0x0FFF;
        uint16_t result;
        std::cout << "PC: 0x" << std::hex << emu.PC << " | OP: 0x" << opcode << std::dec << std::endl;
        fprintf(stderr, "PC: 0x%03X | OP: 0x%04X\n", emu.PC, opcode);
        
		switch(opcode & 0xF000) 
		{
			case 0x0000:
			switch(opcode & 0x00FF) {
				case 0x00E0:
				memset(emu.gfx, 0,sizeof(emu.gfx));
				draw = true;
				break;
				case 0x00EE:
				--emu.SP;
				emu.PC = emu.STACK[emu.SP] - 2;
				break;
				}
				break;
			case 0x1000:
			emu.PC = nnn - 2;
			break;
			case 0x2000:
			emu.STACK[emu.SP] = emu.PC + 2;
			emu.SP++;
			emu.PC = nnn - 2;
			break;
			case 0x3000:
			 if (emu.V[regx] == nn) {
				 emu.PC += 2;
				 }
			break;
			case 0x4000:
			if (emu.V[regx] != nn) {
				emu.PC += 2;
				}
			break;
			case 0x5000:
			if (emu.V[regx] == emu.V[regy]) {
				emu.PC += 2;
				}
			break;
			case 0x6000:
			emu.V[regx] = nn;
			break;
			case 0x7000:
			emu.V[regx] = emu.V[regx] + nn;
			break;
			case 0x8000:
			switch(opcode & 0x000F) {
				case 0x0000:
				emu.V[regx] = emu.V[regy];
				break;
				case 0x0001:
				emu.V[regx] = emu.V[regx] | emu.V[regy];
				emu.V[15] = 0;
				break;
				case 0x0002:
				emu.V[regx] = emu.V[regx] & emu.V[regy];
				emu.V[15] = 0;
				break;
				case 0x0003:
				emu.V[regx] = emu.V[regx] ^ emu.V[regy];
				emu.V[15] = 0;
				break;
				case 0x0004: {
				result = emu.V[regx] + emu.V[regy];
				emu.V[regx] = result;
				uint8_t carry;
				if (result > 255) {
					carry = 1; 
					} else {
						carry = 0;
						}
						emu.V[regx] = result;
						emu.V[15] = carry;
				break;
			}
				case 0x0005: {
				uint8_t tempregx = emu.V[regx];
				uint8_t tempregy = emu.V[regy];
				uint8_t nb;
				result = tempregx - tempregy;
				if (tempregx >= tempregy) {
					 nb = 1;
					} else {
						nb = 0;
						}
				emu.V[regx] = result;
				emu.V[15] = nb;
				break;
			}
				case 0x0006: {
				uint8_t vts = emu.V[regy];
				uint8_t flag = emu.V[regx] & 0x01;
				emu.V[regx] = vts >> 1;
				emu.V[15] = flag;
				break;
			}
				case 0x0007: {
				uint8_t tempregx = emu.V[regx];
				uint8_t tempregy = emu.V[regy];
				uint8_t nb;
				result = tempregy - tempregx;
				if (tempregy >= tempregx) {
					 nb = 1;
					} else {
						nb = 0;
						}
				emu.V[regx] = result;
				emu.V[15] = nb;
				break;
			}
				case 0x000E: {
				uint8_t regval = emu.V[regy];
				uint8_t flag = (emu.V[regy] & 0x80) >> 7;
				emu.V[regx] = regval;
				emu.V[regx] = emu.V[regx] << 1;
				emu.V[15] = flag;
				break;
			}
				
				
			}
			break;
			case 0x9000:
			if (emu.V[regx] != emu.V[regy]) {
				emu.PC += 2;
				}
			break;
			case 0xA000:
			emu.I = nnn;
			break;
			case 0xB000:
			emu.PC = nnn + emu.V[0];
			emu.PC -= 2;
			break;
			case 0xC000:
            emu.V[regx] = (rand() % 256) & nn;
            break;

			break;
			case 0xD000:
			x = emu.V[regx] % WIDTH;
			y = emu.V[regy] % HEIGHT;
			emu.V[15] = 0;
			for(uint8_t row = 0; row < n; row++) {
				if ((y + row) >= HEIGHT) {
					continue;
					}
					uint8_t sprite_byte = emu.RAM[emu.I + row];
					for (uint8_t col = 0; col < 8; col++) {
						if ((x + col) >= WIDTH) {
							continue;
							}
							if(((sprite_byte >> (7 - col)) & 0x01) != 0) {
								uint16_t sprite_index = (y + row) * WIDTH + (x + col);
								if (emu.gfx[sprite_index] == 1) {
									emu.V[15] = 1;
									}
								emu.gfx[sprite_index] ^= 1;
							 
					}
				}
			}
			draw = true;
				break;
				case 0xE000:
				switch (opcode & 0x00FF) {
					case 0x009E:
					if (key_state[emu.V[regx]] == 1) {
						emu.PC += 2;
						}
					break;
					case 0x00A1:
					if (key_state[emu.V[regx]] != 1) {
						emu.PC += 2;
					}
					break;
				}
			break;
			     case 0xF000:
			    switch(opcode & 0x00FF) {
					case 0x0007:
					emu.V[regx] = emu.DT;
					break;
					case 0x000A: {
					keyPressed = false;
					for (int i = 0; i < 16; ++i) {
						if (key_state[i] == 1) {
							emu.V[regx] = i;
							keyPressed = true;
							break;
						}
					}
						if (!keyPressed) {
							emu.PC -= 2;
						}
						break;
				}
					break;
					case 0x0015:
					emu.DT = emu.V[regx];
					break;
					case 0x0018:
					emu.ST = emu.V[regx];
					break;
					case 0x001E:
					emu.I = emu.I + emu.V[regx];
					break;
					case 0x0029:
                    emu.I = emu.V[regx] * 5;
                    break;
                    case 0x0033:
                    emu.RAM[emu.I] = emu.V[regx] / 100;
                    emu.RAM[emu.I + 1] = (emu.V[regx] / 10) % 10;
                    emu.RAM[emu.I + 2] = emu.V[regx] % 10;
                    break;
                    case 0x0055:
                    for (int i = 0; i <= regx; ++i) { 
				         emu.RAM[emu.I + i] = emu.V[i]; 
				    }
                    break;
                    case 0x0065:
                    for (int i = 0; i <= regx; ++i) { 
						emu.V[i] = emu.RAM[emu.I + i]; 
						}
                      break;


					}
					break;
					}
emu.PC += 2;



		}
		if (emu.DT > 0) {
	emu.DT--;
	}
if (emu.ST > 0) {
    emu.ST--;
    SDL_PutAudioStreamData(stream, buffer, 1024);
} 
}



	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}

	

	
