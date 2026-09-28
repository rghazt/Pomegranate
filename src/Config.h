#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <fstream>
#include <limits>

inline int cpu_speed = 600;
inline uint32_t color_bgr = 0xFF000000;
inline uint32_t color_spr = 0xFFFFFFFF;
inline int note = 440;

inline void loadConfig() {
std::ifstream file("Config.txt");

if  (file.is_open()) {
file >> std::dec >> cpu_speed;
file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

file >> std::hex >> color_bgr;
file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
file >> std::hex >> color_spr;
file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}
}
#endif
