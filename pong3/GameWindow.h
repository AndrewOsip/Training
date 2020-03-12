#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <string>
#include <iostream>

class GameWindow
{
public:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int CENTER_WIDTH = 5;
    int board_width;
    int board_height;

    int sdl_bomb(const std::string &msg);
    void logSDLError(const std::string &msg, std::ostream &os);
    void Initialise(SDL_Renderer **renderer, SDL_Window **window);
    bool isNeedToCloseWindow();

private:
    SDL_Event mEvent;
};

//____________________________CPP_____________________________-

void GameWindow::logSDLError(const std::string &msg, std::ostream &os = std::cerr) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

int GameWindow::sdl_bomb(const std::string &msg) {
    logSDLError(msg);
    exit(-1);
}

void GameWindow::Initialise(SDL_Renderer **renderer, SDL_Window **window) {
    if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
        sdl_bomb("Failed to Initialise SDL");

    *window = SDL_CreateWindow(
                "PONG",
                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH, SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN
                );
    if(*window == nullptr)
        sdl_bomb("Failed to create SDL Window");

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(*renderer == nullptr)
        sdl_bomb("Failed to create SDL Renderer");

    const int flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if(IMG_Init(flags) !=flags)
        sdl_bomb("Failed to load the Image loading extensions");

    if(TTF_Init() != 0)
        sdl_bomb("Failed to load TTF extension");
}

bool GameWindow::isNeedToCloseWindow() {
    bool needToClose{false};

    while(SDL_PollEvent(&mEvent)) {
        needToClose = (mEvent.type == SDL_QUIT)
                   || (mEvent.type == SDL_KEYDOWN
                   && mEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE);
    }
    return needToClose;
}


#endif // GAMEWINDOW_H
