#ifndef BOTCONTROLLER_H
#define BOTCONTROLLER_H

#include "Ball.h"
#include "IPlayerMovement.h"
#include "Unit.h"

class BotController : public IPlayerMovement {
public:
    BotController(Unit& bot, Ball& ball)
        : mBotOrSecondPLayer{ bot }
        , mBall{ ball }
    {
    }
    void changePosition() override;

private:
    Unit& mBotOrSecondPLayer;
    Ball& mBall;
};

#endif // BOTCONTROLLER_H
