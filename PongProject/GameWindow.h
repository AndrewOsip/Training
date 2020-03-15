#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Utils/Settings.h"
#include "Utils/Singleton.h"
#include "Utils/Log.h"

class GameWindow {
public:
    void Initialise(SDL_Renderer** renderer, SDL_Window** window /*, SDL_Surface **screen*/);
    bool isNeedToCloseWindow();

private:
    SDL_Event mEvent;
};

#endif // GAMEWINDOW_H
