#ifndef IPLAYER_H
#define IPLAYER_H

#include "GameObject.h"
#include "IUnit.h"

#include "Log.h"
#include "Singleton.h"
#include "Settings.h"

class Unit : public GameObject, public IUnit
{
public:
    Unit()
        : mWidth{20}
        , mWhiteColor{255, 255, 255, 255}
        , mScore{0}
        , mSpeed{4}
    {
    }
    SDL_Rect& getPos() override {return mPos;}
    void setPositionX(int x) override { mPos.x = x; }
    int getPositionX() const override { return mPos.x; }
    void setPositionY(int y) override { mPos.y = y; }
    int getPositionY() const override { return mPos.y; }
    void setPositionW(int w) override { mPos.w = w; }
    int getPositionW() const override { return mPos.w; }
    void setPositionH(int h) override { mPos.h = h; }
    int getPositionH() const override { return mPos.h; }
    void setScore(int score) override { mScore = score; }
    int getScore() const override { return mScore; }
    void setSpeed(int speed) override { mSpeed = speed; }
    int getSpeed() const override { return mSpeed; }
    void setWidth(int width) override { mWidth = width; }
    int getWidth() const override { return mWidth; }
    void updateScore(SDL_Renderer *renderer);
    virtual void renderScore(SDL_Renderer *renderer) = 0;
    void destroyTexture() {SDL_DestroyTexture(unitScore);}
    void increaseScore();
protected:
    SDL_Texture* unitScore;
private:
    SDL_Texture *renderText(int score, const std::string &fontPath, const SDL_Color& color, int fontSize, SDL_Renderer *render);
    int mWidth;
    SDL_Color mWhiteColor;
    SDL_Rect mPos;
    int mScore;
    int mSpeed;
};
//______________________________CPP_________________________________________________

void Unit::increaseScore() {
    setScore(getScore() + 1);
}

void Unit::updateScore(SDL_Renderer *renderer) {
    if (renderer) {
        unitScore = renderText(getScore(), "/home/andrew/Sdl2/fonts/sample.ttf", mWhiteColor, 40, renderer);
    }
}

SDL_Texture *Unit::renderText(int score, const std::string &fontPath, const SDL_Color& color, int fontSize, SDL_Renderer *renderer) {
    TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if(font == nullptr) {
        Singleton<Log>::instance().logSDLError("Unable to open font");
        return nullptr;
    }

    SDL_Surface *surface = TTF_RenderText_Blended(font, std::to_string(score).c_str(), color);
    if(surface == nullptr) {
        TTF_CloseFont(font);
        Singleton<Log>::instance().logSDLError("Unable to render text to a surface");
        return nullptr;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture == nullptr) {
        Singleton<Log>::instance().logSDLError("Unable to render surface to texture");
    }

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    return texture;
}

#endif // IPLAYER_H
