#ifndef GAME_H
#define GAME_H

#include <string>

#include "GameWindow.h"
#include "Ball.h"
#include "Player.h"
#include "Bot.h"


class Game : public GameWindow
{
public:
    void Cleanup(SDL_Renderer **render, SDL_Window **window);
    void boundColision(Ball& ball, Player& player, Bot& bot);
    void playerColision(Ball& ball, Player& player, Bot& bot);
};

//________________________________________CPP_________________________________________________________________________________________________

void Game::playerColision(Ball& ball, Player& player, Bot& bot) {
    if(SDL_HasIntersection(&player.pos, &ball.getRectangle())) {
        ball.x = player.pos.x + player.pos.w;
        ball.speed = ball.speed * ball.BALL_ACCELERATE;

        float angle = Ball::calc_angle(player.pos.y, ball.y, player.pos.h);
        ball.vx = ball.speed * cos(angle);
        ball.vy = ((ball.vy>0)? -1 : 1) * ball.speed * sin(angle);
    }

    if(SDL_HasIntersection(&bot.pos, &ball.getRectangle())) {
        ball.x = bot.pos.x - ball.BALL_WIDTH;
        ball.speed = ball.speed * ball.BALL_ACCELERATE;

        float angle = Ball::calc_angle(bot.pos.y, ball.y, bot.pos.h);
        ball.vx = -1 * ball.speed * cos(angle);
        ball.vy = ((ball.vy>0)? -1 : 1) * ball.speed * sin(angle);
    }
}

void Game::boundColision(Ball& ball, Player& player, Bot& bot) {
    if(ball.y < 0) {
        ball.y = 0;
        ball.vy *= -1;
    }

    if(ball.y + ball.BALL_HEIGHT >= SCREEN_HEIGHT) {
        ball.y = SCREEN_HEIGHT - ball.BALL_HEIGHT - 1;
        ball.vy *= -1;
    }

    if(ball.x < 0) {
        bot.score += 1;
        ball.x = player.pos.x + player.pos.w;
        ball.y = player.pos.y + player.pos.h/2;
        ball.vx = ball.BALL_INIT_SPEED;
        ball.speed = ball.BALL_INIT_SPEED;
    }

    if(ball.x + ball.BALL_WIDTH>= SCREEN_WIDTH) {
        player.score += 1;
        ball.x = bot.pos.x - ball.BALL_WIDTH;
        ball.y = bot.pos.y + bot.pos.h/2;
        ball.vx = -1 * ball.BALL_INIT_SPEED;
        ball.speed = ball.BALL_INIT_SPEED;
    }

    if(player.pos.y < 0) player.pos.y = 0;
    if(player.pos.y + player.pos.h > SCREEN_HEIGHT) player.pos.y = SCREEN_HEIGHT - player.pos.h;
    if(bot.pos.y < 0) bot.pos.y = 0;
    if(bot.pos.y + bot.pos.h > SCREEN_HEIGHT) bot.pos.y = SCREEN_HEIGHT - bot.pos.h;
}

void Game::Cleanup(SDL_Renderer **render, SDL_Window **window) {
    SDL_DestroyRenderer(*render);
    SDL_DestroyWindow(*window);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

#endif // GAME_H
