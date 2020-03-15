#ifndef LINE_H
#define LINE_H

#include "GameObject.h"
#include "Settings.h"
#include "Singleton.h"

class Line : public GameObject
{
public:
    void createLine(SDL_Texture* squareTexture, SDL_Renderer *renderer);
};

//___________________________________CPP_______________________________________________

void Line::createLine(SDL_Texture* squareTexture, SDL_Renderer *renderer) {
    if (renderer && squareTexture) {
        renderTexture(squareTexture, renderer,
                      Singleton<Settings>::instance().SCREEN_WIDTH/2 - Singleton<Settings>::instance().CENTER_WIDTH/2, 0,
                      Singleton<Settings>::instance().CENTER_WIDTH, Singleton<Settings>::instance().SCREEN_HEIGHT);
    }
}

#endif // LINE_H
