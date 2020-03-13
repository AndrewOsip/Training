#include <iostream>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Game.h"
#include "FirstPlayerController.h"
#include "SecondPlayerController.h"
#include "BotMove.h"

int main()
{
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
    SDL_Texture* squareTexture;

    //___________________________________________________________________________________________
        std::cout << "Main menu\n" << "Play with Bot(press b)\n"
                                   << "Play with another Player(press p)" << std::endl;
        std::string modeSwitcher;
        getline(std::cin, modeSwitcher);
    //____________________________________________________________________________________________

    GameWindow gameWindow;
    GameObject GameObject;

    gameWindow.Initialise(&renderer,&window);

    squareTexture = IMG_LoadTexture(renderer, "/home/andrew/Sdl2/img/pong_board.png");
    SDL_QueryTexture(squareTexture, nullptr, nullptr, &gameWindow.board_width, &gameWindow.board_height);

    Ball ball(gameWindow);
    Player player(gameWindow);
    BotOrSecondPLayer botOrSecondPLayer(gameWindow);
    Game game(ball, player, botOrSecondPLayer);
    FirstPlayerController firstPlayerController(player);

    BotMove botMove(botOrSecondPLayer, ball);
    SecondPlayerController secondPlayerController(botOrSecondPLayer);

    while(!gameWindow.isNeedToCloseWindow()) {
        firstPlayerController.playerControl();

        if (modeSwitcher == "b") {
            botMove.botMovement();
        }
        else if (modeSwitcher == "p") {
            secondPlayerController.secondPlayerControl();
        }
        else { return 0; }

        game.boundPlayerColision();
        game.boundBotColision();

        ball.changeObjectPosition();

        game.playerColision();
        game.botColision();

        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer, squareTexture, nullptr, &player.pos);
        SDL_RenderCopy(renderer, squareTexture, nullptr, &botOrSecondPLayer.pos);

        GameObject.createLine(squareTexture, renderer);
        GameObject.createBall(squareTexture, renderer, ball.x, ball.y);

        player.unitScore = player.displayScore(renderer);
        botOrSecondPLayer.unitScore = botOrSecondPLayer.displayScore(renderer);

        player.renderScore(renderer);
        botOrSecondPLayer.renderScore(renderer);

        SDL_DestroyTexture(player.unitScore);
        SDL_DestroyTexture(botOrSecondPLayer.unitScore);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(squareTexture);
    game.Cleanup(&renderer, &window);

    return 0;
}

