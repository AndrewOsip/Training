#ifndef BOT_H
#define BOT_H

#include "Unit.h"

class BotOrSecondPLayer : public Unit
{
public:
    BotOrSecondPLayer(const GameWindow& window)
    {
        score = 0;
        pos.w = window.board_width;
        pos.h = 150;
        speed = 4;
        pos.x = window.SCREEN_WIDTH - pos.w- 10 - pos.w/2;
        pos.y = window.SCREEN_HEIGHT/2 - pos.h/2;
    }

    void renderScore(SDL_Renderer *render) override;
};

//_______________________________________________

void BotOrSecondPLayer::renderScore(SDL_Renderer *render) {
    renderTexture(unitScore, render, SCREEN_WIDTH/2 + 10, 10);
}

#endif // BOT_H
