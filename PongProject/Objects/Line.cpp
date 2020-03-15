#include "Objects/Line.h"

void Line::createLine(SDL_Texture* squareTexture, SDL_Renderer* renderer)
{
    if (renderer && squareTexture) {
        renderTexture(squareTexture, renderer,
            Singleton<Settings>::instance().SCREEN_WIDTH / 2 - Singleton<Settings>::instance().CENTER_WIDTH / 2, 0,
            Singleton<Settings>::instance().CENTER_WIDTH, Singleton<Settings>::instance().SCREEN_HEIGHT);
    }
}
