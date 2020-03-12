#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include "IPlayer.h"
#include "Game.h"

class Player : public IPlayer
{
public:
    Player(const GameWindow& window)
    {
        score = 0;
        pos.w = window.board_width;
        pos.h = 150;
        speed = 10;
        pos.x = window.board_width/2 + 10;
        pos.y = window.SCREEN_HEIGHT/2 - pos.h/2;
    }

    SDL_Texture* displayScore(SDL_Renderer *render);
};
//___________________________________________________________

SDL_Texture* Player::displayScore(SDL_Renderer *render) {
    SDL_Texture *playerScore = renderText(score, "/home/andrew/Sdl2/fonts/sample.ttf", mWhiteColor, 40, render);
    return playerScore;
}

#endif // PLAYER_H
