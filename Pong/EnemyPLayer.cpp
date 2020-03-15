#include "EnemyPLayer.h"

void EnemyPlayer::renderScore(SDL_Renderer *render) {
    if (render) {
        renderTexture(unitScore, render, Singleton<Settings>::instance().SCREEN_WIDTH/2 + 40, 10);
    }
}
