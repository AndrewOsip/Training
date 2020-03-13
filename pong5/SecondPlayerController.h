#ifndef SECONDPLAYERCONTROLLER_H
#define SECONDPLAYERCONTROLLER_H

#include "BotOrSecondPLayer.h"

class SecondPlayerController
{
public:
    SecondPlayerController(BotOrSecondPLayer& botOrSecondPLayer)
        : mUpButton{0}
        , mDownButton{0}
        , mBotOrSecondPLayer{botOrSecondPLayer}
        , mKeystates{SDL_GetKeyboardState(nullptr)}
    {}

    void secondPlayerControl();

private:
    Uint8 mUpButton;
    Uint8 mDownButton;
    BotOrSecondPLayer& mBotOrSecondPLayer;
    const Uint8 *mKeystates;
};
//__________________________________________

void SecondPlayerController::secondPlayerControl() {
    if(mKeystates != nullptr) {
        if(mKeystates[SDL_SCANCODE_UP] || mUpButton) { mBotOrSecondPLayer.pos.y -= mBotOrSecondPLayer.speed; }
        if(mKeystates[SDL_SCANCODE_DOWN] || mDownButton) { mBotOrSecondPLayer.pos.y += mBotOrSecondPLayer.speed; }
    }
}

#endif // SECONDPLAYERCONTROLLER_H
