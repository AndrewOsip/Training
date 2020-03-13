#ifndef IPLAYER_H
#define IPLAYER_H

#include "GameObject.h"

#include <SDL2/SDL_ttf.h>

class Unit : public GameObject
{
public:
    Unit()
        :mWhiteColor{255, 255, 255, 255}
    {
    }
    SDL_Rect pos;
    int score;
    int speed;
    int width{20};
    SDL_Texture* unitScore;

    //void queryText();
    virtual void renderScore(SDL_Renderer *renderer) = 0;
    SDL_Texture* displayScore(SDL_Renderer *renderer);
    void increaseScore();
private:
    SDL_Color mWhiteColor;

};
//_______________________________________________________________________________

//void Unit::queryText() {
   // SDL_QueryTexture(playerScore, nullptr, nullptr, &width, nullptr);
  //  SDL_QueryTexture(botScore, nullptr, nullptr, &width, nullptr);
//}

void Unit::increaseScore() {
    score += 1;
}

SDL_Texture* Unit::displayScore(SDL_Renderer *renderer) {
    SDL_Texture *playerScore = renderText(score, "/home/andrew/Sdl2/fonts/sample.ttf", mWhiteColor, 40, renderer);
    return playerScore;
}

#endif // IPLAYER_H
