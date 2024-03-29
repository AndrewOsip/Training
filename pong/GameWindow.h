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

    void Initialise(SDL_Renderer **ren, SDL_Window **win) {
        if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
            sdl_bomb("Failed to Initialise SDL");

        *win = SDL_CreateWindow(
                    "SDL Pong by Michael Aquilina",
                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                    SCREEN_WIDTH, SCREEN_HEIGHT,
                    SDL_WINDOW_SHOWN
                    );
        if(*win == nullptr)
            sdl_bomb("Failed to create SDL Window");

        *ren = SDL_CreateRenderer(*win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(*ren == nullptr)
            sdl_bomb("Failed to create SDL Renderer");

        const int flags = IMG_INIT_PNG | IMG_INIT_JPG;
        if(IMG_Init(flags) !=flags)
            sdl_bomb("Failed to load the Image loading extensions");

        if(TTF_Init() != 0)
            sdl_bomb("Failed to load TTF extension");
    }


    void logSDLError(const std::string &msg, std::ostream &os = std::cerr) {
        os << msg << " error: " << SDL_GetError() << std::endl;
    }

    int sdl_bomb(const std::string &msg) {
        logSDLError(msg);
        exit(-1);
    }

    void Cleanup(SDL_Renderer **ren, SDL_Window **win) {
        SDL_DestroyRenderer(*ren);
        SDL_DestroyWindow(*win);

        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

    SDL_Texture *renderText(const std::string &msg, const std::string &fontPath, SDL_Color color, int fontSize, SDL_Renderer *ren) {
        TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);
        if(font == nullptr) {
            logSDLError("Unable to open font");
            return nullptr;
        }

        SDL_Surface *surface = TTF_RenderText_Blended(font, msg.c_str(), color);
        if(surface == nullptr) {
            TTF_CloseFont(font);
            logSDLError("Unable to render text to a surface");
            return nullptr;
        }

        SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, surface);
        if(tex == nullptr) {
            logSDLError("Unable to render surface to texture");
        }

        SDL_FreeSurface(surface);
        TTF_CloseFont(font);

        return tex;
    }

    void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w=-1, int h=-1) {
        SDL_Rect dest;
        dest.x = x;
        dest.y = y;
        dest.w = w;
        dest.h = h;

        // If no width and height are specified, use the texture's actual width and height
        if(w == -1 || h == -1)
            SDL_QueryTexture(tex, nullptr, nullptr, &dest.w, &dest.h);

        SDL_RenderCopy(ren, tex, nullptr, &dest);
    }
};

#endif // GAMEWINDOW_H
