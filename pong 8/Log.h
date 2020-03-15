#ifndef LOG_H
#define LOG_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>

class Log {
public:
    int sdl_bomb(const std::string &msg);
    void logSDLError(const std::string &msg, std::ostream &os);
};

//_____________________________CPP____________________________________

void Log::logSDLError(const std::string &msg, std::ostream &os = std::cerr) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

int Log::sdl_bomb(const std::string &msg) {
    logSDLError(msg);
    exit(-1);
}


#endif // LOG_H
