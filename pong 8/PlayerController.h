#ifndef SECONDPLAYERCONTROLLER_H
#define SECONDPLAYERCONTROLLER_H

#include "Unit.h"
#include "IPlayerMovement.h"

class PlayerController : public IPlayerMovement
{
public:
    PlayerController(Unit& unit, Uint8 upBtn, Uint8 downBtn)
        : mUnit{unit}
        , mKeystates{SDL_GetKeyboardState(nullptr)}
        , mUpBtnCode{upBtn}
        , mDownBtnCode{downBtn}
    {}
    void changePosition() override;
private:
    Unit& mUnit;
    const Uint8 *mKeystates;
    Uint8 mUpBtnCode;
    Uint8 mDownBtnCode;
};

//____________________CPP______________________

void PlayerController::changePosition() {
    if(mKeystates) {
        if(mKeystates[mUpBtnCode]) { mUnit.setPositionY(mUnit.getPositionY() - mUnit.getSpeed()); }
        if(mKeystates[mDownBtnCode]) { mUnit.setPositionY(mUnit.getPositionY() + mUnit.getSpeed()); }
    }
}

#endif // SECONDPLAYERCONTROLLER_H
