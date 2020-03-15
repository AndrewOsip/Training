#ifndef IPLAYER_H
#define IPLAYER_H

#include "GameObject.h"
#include "IUnit.h"

#include "Log.h"
#include "Singleton.h"
#include "Settings.h"

class Unit : public GameObject, public IUnit {
public:
    Unit()
        : mWidth{ 20 }
        , mWhiteColor{ 255, 255, 255, 255 }
        , mScore{ 0 }
        , mSpeed{ 4 }
    {
    }
    SDL_Rect& getPos() override { return mPos; }
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
    void updateScore(SDL_Renderer* renderer);
    virtual void renderScore(SDL_Renderer* renderer) = 0;
    void destroyTexture() { SDL_DestroyTexture(unitScore); }
    void increaseScore();

protected:
    SDL_Texture* unitScore;

private:
    SDL_Texture* renderText(int score, const std::string& fontPath, const SDL_Color& color, int fontSize, SDL_Renderer* render);
    int mWidth;
    SDL_Color mWhiteColor;
    SDL_Rect mPos;
    int mScore;
    int mSpeed;
};

#endif // IPLAYER_H
