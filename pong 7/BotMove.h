#ifndef BOTCONTROLLER_H
#define BOTCONTROLLER_H

#include "BotOrSecondPLayer.h"
#include "Ball.h"

class BotMove
{
public:
    BotMove(BotOrSecondPLayer& bot, Ball& ball)
        : mBotOrSecondPLayer{bot}
        , mBall{ball}
    {
    }

    void botMovement();
private:
    BotOrSecondPLayer& mBotOrSecondPLayer;
    Ball& mBall;
};

//_________________________________________________________

void BotMove::botMovement() {
    if(mBall.y < mBotOrSecondPLayer.pos.y + mBotOrSecondPLayer.pos.h/2) { mBotOrSecondPLayer.pos.y -= mBotOrSecondPLayer.speed; }
    if(mBall.y > mBotOrSecondPLayer.pos.y + mBotOrSecondPLayer.pos.h/2) { mBotOrSecondPLayer.pos.y += mBotOrSecondPLayer.speed; }

    if(mBall.vx > mBall.BALL_MAXSPEED) { mBall.vx = mBall.BALL_MAXSPEED; }
    if(mBall.vy > mBall.BALL_MAXSPEED) { mBall.vy = mBall.BALL_MAXSPEED; }
}

#endif // BOTCONTROLLER_H
