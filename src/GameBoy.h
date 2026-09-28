#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <SDL3/SDL.h>
#include <vector>
#include <chrono>
#include <math.h>

#define DMG_WIDTH 160
#define DMG_HEIGHT 144
#define SCALER 3 
#define WIDTH DMG_WIDTH * SCALER
#define HEIGHT DMG_HEIGHT * SCALER

struct GameBoy {
	struct {
		union {
			struct {
				union {
				uint8_t F;
				struct {
					uint8_t UNUSED : 4;
					uint8_t FC : 1;
					uint8_t FH : 1;
					uint8_t FN : 1;
					uint8_t FZ : 1;
					};
				};
				uint8_t A;
				};
			uint16_t AF;
			};
		};

	struct {
		union {
			struct {
				uint8_t C;
				uint8_t B;
				};
				uint16_t BC;
			};
		};

	struct {
		union {
			struct {
				uint8_t E;
				uint8_t D;
				};
				uint16_t DE;
			};
		};

	struct {
		union {
			struct {
				uint8_t L;
				uint8_t H;
				};
				uint16_t HL;
			};
		};
		
	uint16_t PC;
	uint16_t SP;
	uint8_t RAM[65536] = {0};
};


  
