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

    Uint8 upButton = 0;
    Uint8 downButton = 0;

    void playerControl(IPlayer& player);
    SDL_Texture* displayScore(SDL_Renderer *render);
};
//___________________________________________________________

void Player::playerControl(IPlayer& player) {
    if(keystates[SDL_SCANCODE_UP] || upButton) { player.pos.y -= player.speed; }
    if(keystates[SDL_SCANCODE_DOWN] || downButton) { player.pos.y += player.speed; }
}

SDL_Texture* Player::displayScore(SDL_Renderer *render) {
    SDL_Texture *playerScore = renderText(score, "/home/andrew/Sdl2/fonts/sample.ttf", whiteColor, 40, render);
    return playerScore;
}



#endif // PLAYER_H
