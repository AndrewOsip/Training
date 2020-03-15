#include "Objects/Player.h"

void Player::renderScore(SDL_Renderer* render)
{
    if (render) {
        renderTexture(unitScore, render, Singleton<Settings>::instance().SCREEN_WIDTH / 2 - getWidth() - 40, 10);
    }
}
