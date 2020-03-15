#include "Objects/Unit.h"

void Unit::increaseScore()
{
    setScore(getScore() + 1);
}

void Unit::updateScore(SDL_Renderer* renderer)
{
    if (renderer) {
        unitScore = renderText(getScore(), "../PicturesAndFonts/fonts/sample.ttf",
            mWhiteColor, 40, renderer);
    }
}

SDL_Texture* Unit::renderText(int score,
    const std::string& fontPath,
    const SDL_Color& color,
    int fontSize,
    SDL_Renderer* renderer)
{
    TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (font == nullptr) {
        Singleton<Log>::instance().logSDLError("Unable to open font");
        return nullptr;
    }

    SDL_Surface* surface = TTF_RenderText_Blended(font, std::to_string(score).c_str(), color);
    if (surface == nullptr) {
        TTF_CloseFont(font);
        Singleton<Log>::instance().logSDLError(
            "Unable to render text to a surface");
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr) {
        Singleton<Log>::instance().logSDLError(
            "Unable to render surface to texture");
    }

    SDL_FreeSurface(surface);
    TTF_CloseFont(font);

    return texture;
}
