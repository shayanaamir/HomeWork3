#include<SDL.h>
#include "pigeon.hpp"
class HUPigeons{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    //Array of pigeons

    Pigeon my_pigeons[20];

    // // pigeonSrc represents pigeon's rectangle in assets file.
	// SDL_Rect srcRect = {0,0,160,133};

	// // pigeonMover represents pigeon's rectangle to be drawn on screen
	// SDL_Rect moverRect = {30, 30, 50, 50};

    public:
    HUPigeons(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst)
    {
        // loop over pigeon list and set asset
        for (int i=0; i<20; i++)
        {
            my_pigeons[i] = Pigeon(renderer, asst);
        }
    }
    void drawObjects(); 
};