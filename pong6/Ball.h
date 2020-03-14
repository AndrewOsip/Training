#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include "GameObject.h"

namespace {
const float MAX_ANGLE = 3.142 / 5.0; // 72 degrees
const float INIT_SPEED = 6.0f;
}

class Ball : public GameObject
{
public:
    Ball(const GameWindow& window)
        : x{static_cast<float>(window.SCREEN_WIDTH / 2)}
        , y{static_cast<float>(window.SCREEN_HEIGHT / 2)}
        , vx{(rand() % 2 == 0)? INIT_SPEED : -1 * INIT_SPEED}
        , vy{-0.5f}
        , speed{INIT_SPEED}
    {
        mObjectRectangle.w = BALL_HEIGHT;
        mObjectRectangle.h = BALL_HEIGHT;
    }

    float x;
    float y;
    float vx;
    float vy;
    float speed;

public:
    const float MAX_ANGLE = 3.142 / 5.0; // 72 degrees
    const float BALL_MAXSPEED = 8.0f;
    const float BALL_ACCELERATE = 1.05f;
    const float BALL_INIT_SPEED = 6.0f;
    const int BALL_WIDTH = 10;
    const int BALL_HEIGHT = 10;

    static float calc_angle(float y1, float y2, int height);
    void changeObjectPosition();

    SDL_Rect& getRectangle() {return mObjectRectangle;}

private:
    SDL_Rect mObjectRectangle;
};

//_______________________________________________CPP______________

float Ball::calc_angle(float y1, float y2, int height) {
    const float MAX_ANGLE = 3.142 / 5.0; // 72 degrees

    float rely = y1 + height/2 - y2;
    rely /= height/2.0;   // Normalise
    return rely * MAX_ANGLE;
}

void Ball::changeObjectPosition() {
    x += vx;
    y += vy;

    mObjectRectangle.x = static_cast<int>(x);
    mObjectRectangle.y = static_cast<int>(y);
}

#endif // BALL_H
