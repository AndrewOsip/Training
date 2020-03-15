#ifndef GAME_H
#define GAME_H

#include <string>

#include "Objects/Ball.h"
#include "Objects/Player.h"
#include "Objects/EnemyPLayer.h"
#include "Objects/IUnit.h"

class Game : public GameWindow {
public:
    Game(IBall& ball, Player& player, EnemyPlayer& bot)
        : mBall{ ball }
        , mPlayer{ player }
        , mBot{ bot }
    {
    }
    void Cleanup(SDL_Renderer** render, SDL_Window** window /*, SDL_Surface **screen, SDL_Surface **background*/);
    void playerColision();
    void boundPlayerColision();
    void botColision();
    void boundBotColision();

private:
    IBall& mBall;
    Player& mPlayer;
    EnemyPlayer& mBot;
};

#endif // GAME_H
