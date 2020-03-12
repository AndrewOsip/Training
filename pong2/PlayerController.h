#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Player.h"

class PlayerController
{
public:
    PlayerController(Player& player)
        : mUpButton{0}
        , mDownButton{0}
        , mPlayer{player}
        , mKeystates{SDL_GetKeyboardState(nullptr)}
    {}

    void playerControl();

private:
    Uint8 mUpButton;
    Uint8 mDownButton;
    Player& mPlayer;
    const Uint8 *mKeystates;
};
//__________________________________________

void PlayerController::playerControl() {
    if(mKeystates != nullptr) {
        if(mKeystates[SDL_SCANCODE_UP] || mUpButton) { mPlayer.pos.y -= mPlayer.speed; }
        if(mKeystates[SDL_SCANCODE_DOWN] || mDownButton) { mPlayer.pos.y += mPlayer.speed; }
    }
}

#endif // PLAYERCONTROLLER_H
