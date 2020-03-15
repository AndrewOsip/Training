#ifndef LINE_H
#define LINE_H

#include "Objects/GameObject.h"
#include "Utils/Settings.h"
#include "Utils/Singleton.h"

class Line : public GameObject {
public:
    void createLine(SDL_Texture* squareTexture, SDL_Renderer* renderer);
};

#endif // LINE_H
