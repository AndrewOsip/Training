#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Game.h"
#include "PlayerController.h"
#include "BotMove.h"
#include "Line.h"

#include <memory>

#include "IPlayerMovement.h"

int main()
{
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
//    SDL_Surface *screen = nullptr;
//    SDL_Surface *background = nullptr;
//    SDL_Surface* screen_surface = nullptr;
    SDL_Texture* squareTexture;

    //__________________________MENU___________________________________________________________
        std::cout << "Main menu\n" << "Play with Bot(press b)\n"
                                   << "Play with another Player(press p)" << std::endl;
        std::string modeSwitcher;
        getline(std::cin, modeSwitcher);
    //__________________________END_______________________________________________________________

    GameWindow gameWindow;
    Line line;

    gameWindow.Initialise(&renderer, &window/*, &screen*/);

    squareTexture = IMG_LoadTexture(renderer, "/home/andrew/Sdl2/img/pong_board.png");
    SDL_QueryTexture(squareTexture, nullptr, nullptr, &Singleton<Settings>::instance().board_width,
                                                      &Singleton<Settings>::instance().board_height);

    //_____________________________BACKGROUND_______________________________________

//        background = IMG_Load("/home/andrew/Sdl2/img/background.png");
//            if (background == nullptr) {
//                std::cout << "Can't load: " << IMG_GetError() << std::endl;
//            }

//        SDL_Rect bg_background;
//        bg_background.w = gameWindow.SCREEN_WIDTH;
//        bg_background.h = gameWindow.SCREEN_HEIGHT;
//        bg_background.x = 0;
//        bg_background.y = 0;

//        SDL_BlitScaled(background, nullptr, screen, &bg_background);

//        SDL_UpdateWindowSurface(window);
    //_____________________________END____________________________________________
//    screen_surface = SDL_GetWindowSurface(window);
//    SDL_FillRect(screen_surface, nullptr, SDL_MapRGB(screen_surface->format, 100, 150, 100));

    SDL_RenderPresent(renderer);

    Ball ball;
    Player player;
    EnemyPlayer enemy;
    Game game(ball, player, enemy);
    PlayerController playerPositionChanger(player, SDL_SCANCODE_W, SDL_SCANCODE_S);

    std::unique_ptr<IPlayerMovement> enemyPositionChanger = nullptr;
    if (modeSwitcher == "b") {
        enemyPositionChanger.reset(new BotMove(enemy, ball));
    }
    else if (modeSwitcher == "p") {
        enemyPositionChanger.reset(new PlayerController(enemy, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN));
    }

    while(!gameWindow.isNeedToCloseWindow() && enemyPositionChanger != nullptr) {
        playerPositionChanger.changePosition();
        enemyPositionChanger->changePosition();

        game.boundPlayerColision();
        game.boundBotColision();

        ball.changeObjectPosition();

        game.playerColision();
        game.botColision();

        SDL_RenderClear(renderer);

//_______________________________________________________________

//        SDL_UpdateWindowSurface(window);
//_______________________________________________________________
//_______________________________________________________________>>
        SDL_RenderCopy(renderer, squareTexture, nullptr, &player.getPos());
        SDL_RenderCopy(renderer, squareTexture, nullptr, &enemy.getPos());

        line.createLine(squareTexture, renderer);
        ball.createBall(squareTexture, renderer, ball.getX(), ball.getY());


        player.updateScore(renderer);
        enemy.updateScore(renderer);

        player.renderScore(renderer);
        enemy.renderScore(renderer);

        player.destroyTexture();
        enemy.destroyTexture();

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(squareTexture);
    game.Cleanup(&renderer, &window/*, &screen, &background*/);

    return 0;
}

