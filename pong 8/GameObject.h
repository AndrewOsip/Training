#ifndef IGAMEOBJECT_H
#define IGAMEOBJECT_H

#include <SDL2/SDL_ttf.h>

class GameObject
{
public:
    void renderTexture(SDL_Texture *texture, SDL_Renderer *render, int x, int y, int w, int h);
};

//_______________________________________CPP_____________________________________________________________

void GameObject::renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w=-1, int h=-1) {
    SDL_Rect dest{x, y, w, h};

    if(w == -1 || h == -1) {
        SDL_QueryTexture(texture, nullptr, nullptr, &dest.w, &dest.h);
    }
    SDL_RenderCopy(renderer, texture, nullptr, &dest);
}

#endif // IGAMEOBJECT_H
