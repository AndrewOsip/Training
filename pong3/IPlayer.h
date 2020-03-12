#ifndef IPLAYER_H
#define IPLAYER_H

#include "IGameObject.h"
#include "Game.h"
#include <SDL2/SDL_ttf.h>

class IPlayer : public IGameObject
{
public:
    IPlayer()
        :mWhiteColor{255, 255, 255, 255}
    {}
    SDL_Rect pos;
    int score;
    int speed;
    int width;
    SDL_Texture* playerScore;
    SDL_Texture* botScore;

    void queryText();
    void renderScore(SDL_Renderer *render);
protected:
    SDL_Color mWhiteColor;
};
//_______________________________________________________________________________


void IPlayer::queryText() {
    SDL_QueryTexture(playerScore, nullptr, nullptr, &width, nullptr);
    SDL_QueryTexture(botScore, nullptr, nullptr, &width, nullptr);
}

void IPlayer::renderScore(SDL_Renderer *render) {
    renderTexture(playerScore, render, SCREEN_WIDTH/2 - width - 10, 10);
    renderTexture(botScore, render, SCREEN_WIDTH/2 + 10, 10);
}


#endif // IPLAYER_H
