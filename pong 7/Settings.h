#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <memory>

#include "Singleton.h"

class Settings {
public:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;
    const int CENTER_WIDTH = 5;
    int board_width;
    int board_height;
};

#endif // PROPERTIES_H
