#include "Log.h"

void Log::logSDLError(const std::string& msg, std::ostream& os)
{
    os << msg << " error: " << SDL_GetError() << std::endl;
}

int Log::sdl_bomb(const std::string& msg)
{
    logSDLError(msg);
    exit(-1);
}
