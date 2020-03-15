#ifndef BOTCONTROLLER_H
#define BOTCONTROLLER_H

#include "EnemyPlayer.h"
#include "Ball.h"
#include "IPlayerMovement.h"

class BotMove : public IPlayerMovement
{
public:
    BotMove(Unit& bot, Ball& ball)
        : mBotOrSecondPLayer{bot}
        , mBall{ball}
    {
    }
    void changePosition() override;
private:
    Unit& mBotOrSecondPLayer;
    Ball& mBall;
};

//____________________________CPP___________________________

void BotMove::changePosition() {
    if(mBall.getY() < mBotOrSecondPLayer.getPositionY() + mBotOrSecondPLayer.getPositionH()/2)
        { mBotOrSecondPLayer.setPositionY(mBotOrSecondPLayer.getPositionY() - mBotOrSecondPLayer.getSpeed()); }
    if(mBall.getY() > mBotOrSecondPLayer.getPositionY() + mBotOrSecondPLayer.getPositionH()/2)
        { mBotOrSecondPLayer.setPositionY(mBotOrSecondPLayer.getPositionY() + mBotOrSecondPLayer.getSpeed()); }

    if(mBall.getVx() > Singleton<Settings>::instance().BALL_MAXSPEED) { mBall.setVx(Singleton<Settings>::instance().BALL_MAXSPEED); }
    if(mBall.getVy() > Singleton<Settings>::instance().BALL_MAXSPEED) { mBall.setVy(Singleton<Settings>::instance().BALL_MAXSPEED); }
}

#endif // BOTCONTROLLER_H
