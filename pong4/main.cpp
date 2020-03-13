#include <iostream>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Game.h"
#include "PlayerController.h"
#include "BotMove.h"


int main()
{
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
    SDL_Texture* squareTexture;

    GameWindow gameWindow;
    GameObject GameObject;

    gameWindow.Initialise(&renderer,&window);

    squareTexture = IMG_LoadTexture(renderer, "/home/andrew/Sdl2/img/pong_board.png");
    SDL_QueryTexture(squareTexture, nullptr, nullptr, &gameWindow.board_width, &gameWindow.board_height);

    Ball ball(gameWindow);
    Player player(gameWindow);
    Bot bot(gameWindow);
    Game game(ball, player, bot);
    PlayerController playerController(player);
    BotMove botMove(bot, ball);

    while(!gameWindow.isNeedToCloseWindow()) {
        playerController.playerControl();
        botMove.botMovement();

        game.boundPlayerColision();
        game.boundBotColision();

        ball.changeObjectPosition();

        game.playerColision();
        game.botColision();

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, squareTexture, nullptr, &player.pos);
        SDL_RenderCopy(renderer, squareTexture, nullptr, &bot.pos);

        GameObject.createLine(squareTexture, renderer);
        GameObject.createBall(squareTexture, renderer, ball.x, ball.y);

        player.unitScore = player.displayScore(renderer);
        bot.unitScore = bot.displayScore(renderer);

        player.renderScore(renderer);
        bot.renderScore(renderer);

        SDL_DestroyTexture(player.unitScore);
        SDL_DestroyTexture(bot.unitScore);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(squareTexture);
    game.Cleanup(&renderer, &window);

    return 0;
}

