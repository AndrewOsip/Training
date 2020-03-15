#include "GameWindow.h"

void GameWindow::Initialise(SDL_Renderer** renderer, SDL_Window** window /*, SDL_Surface **screen*/)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        Singleton<Log>::instance().sdl_bomb("Failed to Initialise SDL");

    *window = SDL_CreateWindow(
        "PONG",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        Singleton<Settings>::instance().SCREEN_WIDTH, Singleton<Settings>::instance().SCREEN_HEIGHT,
        SDL_WINDOW_SHOWN);

    if (*window == nullptr)
        Singleton<Log>::instance().sdl_bomb("Failed to create SDL Window");

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (*renderer == nullptr)
        Singleton<Log>::instance().sdl_bomb("Failed to create SDL Renderer");

    const int flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (IMG_Init(flags) != flags)
        Singleton<Log>::instance().sdl_bomb("Failed to load the Image loading extensions");

    if (TTF_Init() != 0)
        Singleton<Log>::instance().sdl_bomb("Failed to load TTF extension");

    //     *screen = SDL_GetWindowSurface(*window);
}

bool GameWindow::isNeedToCloseWindow()
{
    bool needToClose{ false };

    while (SDL_PollEvent(&mEvent)) {
        needToClose = (mEvent.type == SDL_QUIT)
            || (mEvent.type == SDL_KEYDOWN
                          && mEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE);
    }
    return needToClose;
}
