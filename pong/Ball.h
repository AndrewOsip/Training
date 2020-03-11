#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>

class Ball
{
public:
    float x;
    float y;
    float vx;
    float vy;
    float speed;

    const float MAX_ANGLE = 3.142 / 5.0; // 72 degrees

    const float BALL_MAXSPEED = 8.0f;
    const float BALL_ACCELERATE = 1.05f;
    const float BALL_INIT_SPEED = 4.0f;
    const int BALL_WIDTH = 10;
    const int BALL_HEIGHT = 10;

    float calc_angle(float y1, float y2, int height) {
        float rely = y1 + height/2 - y2;
        rely /= height/2.0;   // Normalise
        return rely * MAX_ANGLE;
    }

    SDL_Rect b_rect;
};

#endif // BALL_H
