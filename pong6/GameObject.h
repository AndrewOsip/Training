#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include "GameWindow.h"

namespace {
const int BALL_WIDTH = 10;
const int BALL_HEIGHT = 10;
}

class GameObject : public GameWindow
{
public:
    SDL_Texture *renderText(int score, const std::string &fontPath, SDL_Color color, int fontSize, SDL_Renderer *render);
    static void renderTexture(SDL_Texture *texture, SDL_Renderer *render, int x, int y, int w, int h);
    void createLine(SDL_Texture* squareTexture, SDL_Renderer *renderer);
    void createBall(SDL_Texture* squareTexture, SDL_Renderer *renderer, float x, float y);
};

//_______________________________________________________________________________________________________

SDL_Texture *GameObject::renderText(int score, const std::string &fontPath, SDL_Color color, int fontSize, SDL_Renderer *renderer) {
    TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if(font == nullptr) {
        logSDLError("Unable to open font");
        return nullptr;
    }

    SDL_Surface *surface = TTF_RenderText_Blended(font, std::to_string(score).c_str(), color);
    if(surface == nullptr) {
        TTF_CloseFont(font);
        logSDLError("Unable to render text to a surface");
        return nullptr;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture == nullptr) {
        logSDLError("Unable to render surface to texture");
    }

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    return texture;
}

void GameObject::renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w=-1, int h=-1) {
    SDL_Rect dest{x, y, w, h};

    if(w == -1 || h == -1) {
        SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
    }
    SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

void GameObject::createLine(SDL_Texture* squareTexture, SDL_Renderer *renderer) {
    renderTexture(squareTexture, renderer, SCREEN_WIDTH/2 - CENTER_WIDTH/2, 0, CENTER_WIDTH, SCREEN_HEIGHT);
}

void GameObject::createBall(SDL_Texture* squareTexture, SDL_Renderer *renderer, float x, float y) {
    renderTexture(squareTexture, renderer, x, y, BALL_WIDTH, BALL_HEIGHT);
}

#endif // IGAMEOBJECT_H
