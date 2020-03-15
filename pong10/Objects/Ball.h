#ifndef BALL_H
#define BALL_H

#include "GameObject.h"
#include "Singleton.h"
#include "Settings.h"
#include "IBall.h"

namespace {
const float MAX_ANGLE = 3.142 / 5.0; // 72 degrees
const float INIT_SPEED = 6.0f;
}

class Ball : public GameObject, public IBall {
public:
    Ball()
        : mSpeed{ INIT_SPEED }
        , mX{ static_cast<float>(Singleton<Settings>::instance().SCREEN_WIDTH / 2) }
        , mY{ static_cast<float>(Singleton<Settings>::instance().SCREEN_HEIGHT / 2) }
        , mVx{ (rand() % 2 == 0) ? INIT_SPEED : -1 * INIT_SPEED }
        , mVy{ -0.5f }
    {
        mObjectRectangle.w = Singleton<Settings>::instance().BALL_HEIGHT;
        mObjectRectangle.h = Singleton<Settings>::instance().BALL_HEIGHT;
    }
    void setSpeed(float speed) override { mSpeed = speed; }
    void setX(float value) override { mX = value; }
    void setY(float value) override { mY = value; }
    void setVx(float value) override { mVx = value; }
    void setVy(float value) override { mVy = value; }
    float getSpeed() const override { return mSpeed; }
    float getX() const override { return mX; }
    float getY() const override { return mY; }
    float getVx() const override { return mVx; }
    float getVy() const override { return mVy; }
    void createBall(SDL_Texture* squareTexture, SDL_Renderer* renderer, float x, float y);
    static float calc_angle(float y1, float y2, int height);
    void changeObjectPosition();
    SDL_Rect& getBallRectangle() override { return mObjectRectangle; }
private:
    SDL_Rect mObjectRectangle;
    float mSpeed;
    float mX;
    float mY;
    float mVx;
    float mVy;
};

#endif // BALL_H
