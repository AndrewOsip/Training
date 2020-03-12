#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include "GameWindow.h"
//#include "Game.h"
#include "Ball.h"

class IGameObject : public GameWindow
{
public:
    SDL_Texture *renderText(int score, const std::string &fontPath, SDL_Color color, int fontSize, SDL_Renderer *render);
    static void renderTexture(SDL_Texture *texture, SDL_Renderer *render, int x, int y, int w, int h);
    void createLine(SDL_Texture* squareTex, SDL_Renderer *ren);
    void createBall(SDL_Texture* squareTex, SDL_Renderer *ren, float x, float y, const int BALL_WIDTH, const int BALL_HEIGHT);
};


SDL_Texture *IGameObject::renderText(int score, const std::string &fontPath, SDL_Color color, int fontSize, SDL_Renderer *render) {
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

    SDL_Texture *texture = SDL_CreateTextureFromSurface(render, surface);
    if(texture == nullptr) {
        logSDLError("Unable to render surface to texture");
    }

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    return texture;
}

void IGameObject::renderTexture(SDL_Texture *texture, SDL_Renderer *render, int x, int y, int w=-1, int h=-1) {
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;

    // If no width and height are specified, use the texture's actual width and height
    if(w == -1 || h == -1)
        SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);

    SDL_RenderCopy(render, texture, nullptr, &dest);
}

void IGameObject::createLine(SDL_Texture* squareTex, SDL_Renderer *ren) {
    renderTexture(squareTex, ren, SCREEN_WIDTH/2 - CENTER_WIDTH/2, 0, CENTER_WIDTH, SCREEN_HEIGHT);
}

void IGameObject::createBall(SDL_Texture* squareTex, SDL_Renderer *ren, float x, float y, const int BALL_WIDTH, const int BALL_HEIGHT) {
    renderTexture(squareTex, ren, x, y, BALL_WIDTH, BALL_HEIGHT);
}

#endif // IGAMEOBJECT_H
