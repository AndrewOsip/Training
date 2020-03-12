#include <iostream>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "GameWindow.h"
#include "Game.h"
#include "Player.h"
#include "Bot.h"
#include "Ball.h"
#include "IGameObject.h"
#include "IPlayer.h"
#include "PlayerController.h"


int main()
{
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;

    GameWindow gameWindow;
    Game game;
    IGameObject iGameObject;
    IPlayer iPlayer;

    gameWindow.Initialise(&renderer,&window);

    SDL_Texture* squareTexture = IMG_LoadTexture(renderer, "/home/andrew/Sdl2/img/pong_board.png");
    SDL_QueryTexture(squareTexture, nullptr, nullptr, &gameWindow.board_width, &gameWindow.board_height);

    Ball ball(gameWindow);
    Player player(gameWindow);
    Bot bot(gameWindow);
    PlayerController playerController(player);

    while(!gameWindow.isNeedToCloseWindow()) {

        playerController.playerControl();
        bot.botMovement(bot, ball);

        game.boundColision(ball, player, bot);
        ball.changeObjectPosition(); //

        game.playerColision(ball, player, bot);

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, squareTexture, nullptr, &player.pos);
        SDL_RenderCopy(renderer, squareTexture, nullptr, &bot.pos);

        iGameObject.createLine(squareTexture, renderer);

        iGameObject.createBall(squareTexture, renderer, ball.x, ball.y, ball.BALL_WIDTH, ball.BALL_HEIGHT);

        iPlayer.playerScore = player.displayScore(renderer);
        iPlayer.botScore = bot.displayScore(renderer);

        iPlayer.queryText();

        iPlayer.renderScore(renderer);

        SDL_DestroyTexture(iPlayer.playerScore);
        SDL_DestroyTexture(iPlayer.botScore);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(squareTexture);
    game.Cleanup(&renderer, &window);

    return 0;
}

