#ifndef LOG_H
#define LOG_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>

class Log {
public:
    int sdl_bomb(const std::string &msg);
    void logSDLError(const std::string &msg, std::ostream &os = std::cerr);
};

#endif // LOG_H
