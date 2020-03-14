#ifndef BOT_H
#define BOT_H

#include "Unit.h"
#include "Settings.h"

class BotOrSecondPLayer : public Unit
{
public:
    BotOrSecondPLayer()
    {
        score = 0;
        pos.w = Singleton<Settings>::instance().board_width;
        pos.h = 150;
        speed = 4;
        pos.x = Singleton<Settings>::instance().SCREEN_WIDTH - pos.w- 10 - pos.w/2;
        pos.y = Singleton<Settings>::instance().SCREEN_HEIGHT/2 - pos.h/2;
    }

    virtual ~BotOrSecondPLayer() = default;

    void renderScore(SDL_Renderer *render) override;
};

//_______________________________________________

void BotOrSecondPLayer::renderScore(SDL_Renderer *render) {
    renderTexture(unitScore, render, Singleton<Settings>::instance().SCREEN_WIDTH/2 + 40, 10);
}

#endif // BOT_H
