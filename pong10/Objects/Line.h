#ifndef LINE_H
#define LINE_H

#include "GameObject.h"
#include "Settings.h"
#include "Singleton.h"

class Line : public GameObject {
public:
    void createLine(SDL_Texture* squareTexture, SDL_Renderer* renderer);
};

#endif // LINE_H
