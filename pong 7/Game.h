#ifndef GAME_H
#define GAME_H

#include <string>

#include "Ball.h"
#include "Player.h"
#include "BotOrSecondPLayer.h"
#include "GameWindow.h"

class Game : public GameWindow
{
public:
    Game(Ball& ball, Player& player, BotOrSecondPLayer& bot)
        : mBall{ball}
        , mPlayer{player}
        , mBot{bot}
    {
    }

    void Cleanup(SDL_Renderer **render, SDL_Window **window/*, SDL_Surface **screen, SDL_Surface **background*/);

    void boundPlayerColision();
    void boundBotColision();

    void playerColision();
    void botColision();

private:
    Ball& mBall;
    Player& mPlayer;
    BotOrSecondPLayer& mBot;
};

//________________________________________CPP_____________________________________________________

void Game::playerColision() {
    if(SDL_HasIntersection(&mPlayer.pos, &mBall.getRectangle())) {
        mBall.x = mPlayer.pos.x + mPlayer.pos.w;
        mBall.speed = mBall.speed * mBall.BALL_ACCELERATE;

        float angle = Ball::calc_angle(mPlayer.pos.y, mBall.y, mPlayer.pos.h);
        mBall.vx = mBall.speed * cos(angle);
        mBall.vy = ((mBall.vy>0)? -1 : 1) * mBall.speed * sin(angle);
    }
}

void Game::boundPlayerColision() {
    if(mBall.y < 0) {
        mBall.y = 0;
        mBall.vy *= -1;
    }

    if(mBall.x < 0) {
        mBot.increaseScore();
        mBall.x = mPlayer.pos.x + mPlayer.pos.w;
        mBall.y = mPlayer.pos.y + mPlayer.pos.h/2;
        mBall.vx = mBall.BALL_INIT_SPEED;
        mBall.speed = mBall.BALL_INIT_SPEED;
    }

    if(mPlayer.pos.y < 0) { mPlayer.pos.y = 0; }

    if(mPlayer.pos.y + mPlayer.pos.h > Singleton<Settings>::instance().SCREEN_HEIGHT) {
        mPlayer.pos.y = Singleton<Settings>::instance().SCREEN_HEIGHT - mPlayer.pos.h;
    }
}

void Game::botColision() {
    if(SDL_HasIntersection(&mBot.pos, &mBall.getRectangle())) {
        mBall.x = mBot.pos.x - mBall.BALL_WIDTH;
        mBall.speed = mBall.speed * mBall.BALL_ACCELERATE;

        float angle = Ball::calc_angle(mBot.pos.y, mBall.y, mBot.pos.h);
        mBall.vx = -1 * mBall.speed * cos(angle);
        mBall.vy = ((mBall.vy>0)? -1 : 1) * mBall.speed * sin(angle);
    }
}

void Game::boundBotColision(){
    if(mBall.y + mBall.BALL_HEIGHT >= Singleton<Settings>::instance().SCREEN_HEIGHT) {
        mBall.y = Singleton<Settings>::instance().SCREEN_HEIGHT - mBall.BALL_HEIGHT - 1;
        mBall.vy *= -1;
    }

    if(mBall.x + mBall.BALL_WIDTH>= Singleton<Settings>::instance().SCREEN_WIDTH) {
        mPlayer.increaseScore();
        mBall.x = mBot.pos.x - mBall.BALL_WIDTH;
        mBall.y = mBot.pos.y + mBot.pos.h/2;
        mBall.vx = -1 * mBall.BALL_INIT_SPEED;
        mBall.speed = mBall.BALL_INIT_SPEED;
    }

    if(mBot.pos.y < 0) { mBot.pos.y = 0; }

    if(mBot.pos.y + mBot.pos.h > Singleton<Settings>::instance().SCREEN_HEIGHT) {
        mBot.pos.y = Singleton<Settings>::instance().SCREEN_HEIGHT - mBot.pos.h;
    }
}

void Game::Cleanup(SDL_Renderer **render, SDL_Window **window/*, SDL_Surface **screen, SDL_Surface **background*/) {
    SDL_DestroyRenderer(*render);
    SDL_DestroyWindow(*window);
//    SDL_FreeSurface(*background);
//    SDL_FreeSurface(*screen);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

#endif // GAME_H
