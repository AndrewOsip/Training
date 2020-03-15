#ifndef BOT_H
#define BOT_H

#include "Unit.h"
#include "Settings.h"

class EnemyPlayer : public Unit
{
public:
    EnemyPlayer()
    {
        setPositionW(Singleton<Settings>::instance().board_width);
        setPositionH(150);
        setPositionX(Singleton<Settings>::instance().SCREEN_WIDTH - getPositionW() - 10 - getPositionW()/2);
        setPositionY(Singleton<Settings>::instance().SCREEN_HEIGHT/2 - getPositionH()/2);
    }
    virtual ~EnemyPlayer() override = default;
    void renderScore(SDL_Renderer *render) override;
};

//______________________CPP_________________________

void EnemyPlayer::renderScore(SDL_Renderer *render) {
    if (render) {
        renderTexture(unitScore, render, Singleton<Settings>::instance().SCREEN_WIDTH/2 + 40, 10);
    }
}

#endif // BOT_H
