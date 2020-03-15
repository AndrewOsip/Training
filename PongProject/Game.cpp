#include "Game.h"

void Game::playerColision()
{
    if (SDL_HasIntersection(&mPlayer.getPos(), &mBall.getBallRectangle())) {
        mBall.setX(mPlayer.getPositionX() + mPlayer.getPositionW());
        mBall.setSpeed(mBall.getSpeed() * Singleton<Settings>::instance().BALL_ACCELERATE);

        float angle = Ball::calc_angle(mPlayer.getPositionY(), mBall.getY(), mPlayer.getPositionH());
        mBall.setVx(mBall.getSpeed() * cos(angle));
        mBall.setVy(((mBall.getVy() > 0) ? -1 : 1) * mBall.getSpeed() * sin(angle));
    }
}

void Game::boundPlayerColision()
{
    if (mBall.getY() < 0) {
        mBall.setY(0);
        mBall.setVy(mBall.getVy() * -1);
    }

    if (mBall.getX() < 0) {
        mBot.increaseScore();
        mBall.setX(mPlayer.getPositionX() + mPlayer.getPositionW());
        mBall.setY(mPlayer.getPositionY() + mPlayer.getPositionH() / 2);
        mBall.setVx(Singleton<Settings>::instance().BALL_INIT_SPEED);
        mBall.setSpeed(Singleton<Settings>::instance().BALL_INIT_SPEED);
    }

    if (mPlayer.getPositionY() < 0) {
        mPlayer.setPositionY(0);
    }

    if (mPlayer.getPositionY() + mPlayer.getPositionH() > Singleton<Settings>::instance().SCREEN_HEIGHT) {
        mPlayer.setPositionY(Singleton<Settings>::instance().SCREEN_HEIGHT - mPlayer.getPositionH());
    }
}

void Game::botColision()
{
    //_________________________>
    if (SDL_HasIntersection(&mBot.getPos(), &mBall.getBallRectangle())) {
        mBall.setX(mBot.getPositionX() - Singleton<Settings>::instance().BALL_WIDTH);
        mBall.setSpeed(mBall.getSpeed() * Singleton<Settings>::instance().BALL_ACCELERATE);

        float angle = Ball::calc_angle(mBot.getPositionY(), mBall.getY(), mBot.getPositionH());
        mBall.setVx(-1 * mBall.getSpeed() * cos(angle));
        mBall.setVy(((mBall.getVy() > 0) ? -1 : 1) * mBall.getSpeed() * sin(angle));
    }
}

void Game::boundBotColision()
{
    if (mBall.getY() + Singleton<Settings>::instance().BALL_HEIGHT >= Singleton<Settings>::instance().SCREEN_HEIGHT) {
        mBall.setY(Singleton<Settings>::instance().SCREEN_HEIGHT - Singleton<Settings>::instance().BALL_HEIGHT - 1);
        mBall.setVy(mBall.getVy() * -1);
    }

    if (mBall.getX() + Singleton<Settings>::instance().BALL_WIDTH >= Singleton<Settings>::instance().SCREEN_WIDTH) {
        mPlayer.increaseScore();
        mBall.setX(mBot.getPositionX() - Singleton<Settings>::instance().BALL_WIDTH);
        mBall.setY(mBot.getPositionY() + mBot.getPositionH() / 2);
        mBall.setVx(-1 * Singleton<Settings>::instance().BALL_INIT_SPEED);
        mBall.setSpeed(Singleton<Settings>::instance().BALL_INIT_SPEED);
    }

    if (mBot.getPositionY() < 0) {
        mBot.setPositionY(0);
    }

    if (mBot.getPositionY() + mBot.getPositionH() > Singleton<Settings>::instance().SCREEN_HEIGHT) {
        mBot.setPositionY(Singleton<Settings>::instance().SCREEN_HEIGHT - mBot.getPositionH());
    }
}

void Game::Cleanup(SDL_Renderer** render, SDL_Window** window /*, SDL_Surface **screen, SDL_Surface **background*/)
{
    SDL_DestroyRenderer(*render);
    SDL_DestroyWindow(*window);
    //    SDL_FreeSurface(*background);
    //    SDL_FreeSurface(*screen);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
