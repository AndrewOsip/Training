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
        score = 0;
        pos.w = Singleton<Settings>::instance().board_width;
        pos.h = 150;
        speed = 4;
        pos.x = Singleton<Settings>::instance().board_width/2 + 10;
        pos.y = Singleton<Settings>::instance().SCREEN_HEIGHT/2 - pos.h/2;
    }

    void renderScore(SDL_Renderer *render) override;
};
//___________________________________________________________

void Player::renderScore(SDL_Renderer *render) {
    renderTexture(unitScore, render, Singleton<Settings>::instance().SCREEN_WIDTH/2 - width - 40, 10);
}

#endif // PLAYER_H
