#include "pigeon.hpp"

Pigeon::Pigeon()
{
    moverRect = {0,0,50,50};
}
void Pigeon::draw()
{

   animate();
    move();
}

void Pigeon::move()
{
    moverRect.x += 10;
    if (moverRect.x>=SCREEN_WIDTH)
    {
        moverRect.x=moverRect.x%SCREEN_WIDTH;
    }

}

void Pigeon::animate()
{
    SDL_RenderCopy(gRenderer, assets, &srcRect[c], &moverRect);
    c++;
    if (c>=3) 
    {
        c = 0;
    }
}