#ifndef BOT_H
#define BOT_H

#include "IPlayer.h"

class Bot : public IPlayer
{
public:
    Bot(const GameWindow& window)
    {
        score = 0;
        pos.w = window.board_width;
        pos.h = 150;
        speed = 2;
        pos.x = window.SCREEN_WIDTH - pos.w- 10 - pos.w/2;
        pos.y = window.SCREEN_HEIGHT/2 - pos.h/2;
    }

    void botMovement(IPlayer& bot, Ball& ball);
    SDL_Texture* displayScore(SDL_Renderer *render) ;
};

//________________________________________________

void Bot::botMovement(IPlayer& bot, Ball& ball) {
    if(ball.y < bot.pos.y + bot.pos.h/2) { bot.pos.y -= bot.speed; }
    if(ball.y > bot.pos.y + bot.pos.h/2) { bot.pos.y += bot.speed; }

    if(ball.vx > ball.BALL_MAXSPEED) { ball.vx = ball.BALL_MAXSPEED; }
    if(ball.vy > ball.BALL_MAXSPEED) { ball.vy = ball.BALL_MAXSPEED; }
}

SDL_Texture* Bot::displayScore(SDL_Renderer *render) {
    SDL_Texture *botScore = renderText(score, "/home/andrew/Sdl2/fonts/sample.ttf", mWhiteColor, 40, render);
    return botScore;
}


#endif // BOT_H
