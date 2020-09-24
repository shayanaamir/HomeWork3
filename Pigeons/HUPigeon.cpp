#include "HUPigeons.hpp"

void HUPigeons::drawObjects(){
    SDL_RenderCopy(gRenderer, assets, &srcRect, &srcRect);
    pigeonMover.x++;
}