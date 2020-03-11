#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

class Player
{
public:
    SDL_Rect pos;
    int score;
    int speed;
};

#endif // PLAYER_H
