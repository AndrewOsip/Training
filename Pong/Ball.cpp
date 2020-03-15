#include "Ball.h"

void Ball::createBall(SDL_Texture* squareTexture, SDL_Renderer *renderer, float x, float y) {
    if (renderer && squareTexture) {
        renderTexture(squareTexture, renderer, x, y, Singleton<Settings>::instance().BALL_WIDTH, Singleton<Settings>::instance().BALL_HEIGHT);
    }
}

float Ball::calc_angle(float y1, float y2, int height) {
    const float MAX_ANGLE = 3.142 / 5.0; // 72 degrees

    float rely = y1 + height/2 - y2;
    rely /= height/2.0;   // Normalise
    return rely * MAX_ANGLE;
}

void Ball::changeObjectPosition() {
    mX += mVx;
    mY += mVy;

    mObjectRectangle.x = static_cast<int>(mX);
    mObjectRectangle.y = static_cast<int>(mY);
}
