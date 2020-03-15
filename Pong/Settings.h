#ifndef PROPERTIES_H
#define PROPERTIES_H

class Settings {
public:
    //screen properties
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int CENTER_WIDTH = 5;

    //board properies
    int board_width;
    int board_height;

    // ball properties
    const float BALL_MAXSPEED = 8.0f;
    const float BALL_ACCELERATE = 1.05f;
    const float BALL_INIT_SPEED = 6.0f;
    const int BALL_WIDTH = 10;
    const int BALL_HEIGHT = 10;
};

#endif // PROPERTIES_H
