#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "Unit.h"

class Player : public Unit
{
public:
    Player(const GameWindow& window)
    {
        score = 0;
        pos.w = window.board_width;
        pos.h = 150;
        speed = 4;
        pos.x = window.board_width/2 + 10;
        pos.y = window.SCREEN_HEIGHT/2 - pos.h/2;
    }

    void renderScore(SDL_Renderer *render) override;
};
//___________________________________________________________

void Player::renderScore(SDL_Renderer *render) {
    renderTexture(unitScore, render, SCREEN_WIDTH/2 - width - 10, 10);
}

#endif // PLAYER_H
