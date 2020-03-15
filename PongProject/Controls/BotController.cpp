#include "Controls/BotController.h"

void BotController::changePosition()
{
    if (mBall.getY() < mBotOrSecondPLayer.getPositionY() + mBotOrSecondPLayer.getPositionH() / 2) {
        mBotOrSecondPLayer.setPositionY(mBotOrSecondPLayer.getPositionY() - mBotOrSecondPLayer.getSpeed());
    }
    if (mBall.getY() > mBotOrSecondPLayer.getPositionY() + mBotOrSecondPLayer.getPositionH() / 2) {
        mBotOrSecondPLayer.setPositionY(mBotOrSecondPLayer.getPositionY() + mBotOrSecondPLayer.getSpeed());
    }

    if (mBall.getVx() > Singleton<Settings>::instance().BALL_MAXSPEED) {
        mBall.setVx(Singleton<Settings>::instance().BALL_MAXSPEED);
    }
    if (mBall.getVy() > Singleton<Settings>::instance().BALL_MAXSPEED) {
        mBall.setVy(Singleton<Settings>::instance().BALL_MAXSPEED);
    }
}
