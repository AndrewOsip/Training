#ifndef BOTCONTROLLER_H
#define BOTCONTROLLER_H

#include "Bot.h"
#include "Ball.h"

class BotMove
{
public:
    BotMove(Bot& bot, Ball& ball)
        : mBot{bot}
        , mBall{ball}
    {
    }

    void botMovement();
private:
    Bot& mBot;
    Ball& mBall;
};

//_________________________________________________________

void BotMove::botMovement() {
    if(mBall.y < mBot.pos.y + mBot.pos.h/2) { mBot.pos.y -= mBot.speed; }
    if(mBall.y > mBot.pos.y + mBot.pos.h/2) { mBot.pos.y += mBot.speed; }

    if(mBall.vx > mBall.BALL_MAXSPEED) { mBall.vx = mBall.BALL_MAXSPEED; }
    if(mBall.vy > mBall.BALL_MAXSPEED) { mBall.vy = mBall.BALL_MAXSPEED; }
}

#endif // BOTCONTROLLER_H
