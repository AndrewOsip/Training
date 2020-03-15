#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "Unit.h"
#include "Settings.h"
#include "GameWindow.h"

class Player : public Unit
{
public:
    Player()
    {
        setPositionW(Singleton<Settings>::instance().board_width);
        setPositionH(150);
        setPositionX(Singleton<Settings>::instance().board_width/2 + 10);
        setPositionY(Singleton<Settings>::instance().SCREEN_HEIGHT/2 - getPositionH()/2);
    }
    void renderScore(SDL_Renderer *render) override;
};
//_______________________CPP____________________________________

void Player::renderScore(SDL_Renderer *render) {
    if (render) {
        renderTexture(unitScore, render, Singleton<Settings>::instance().SCREEN_WIDTH/2 - getWidth() - 40, 10);
    }
}

#endif // PLAYER_H
