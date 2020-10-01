#include<SDL.h>
#include <ctime>

class Pigeon{
    SDL_Renderer *gRenderer;
    SDL_Texture *assets;
    // Write your code for Pigeon here.
    SDL_Rect srcRect[3] = {{0,0,160,133},{0,133,160,133},{0,266,160,133}};
    int SCREEN_WIDTH = 800;
    int SCREEN_HEIGHT = 600;

    // mover rect
    int c=0;
    SDL_Rect moverRect;
    public:
    Pigeon();
    Pigeon(SDL_Renderer *renderer, SDL_Texture *asst):gRenderer(renderer), assets(asst)
    {
        int x = rand() % (SCREEN_WIDTH-50);
        int y = rand() % (SCREEN_HEIGHT-50);
        moverRect = {x,y,50,50};
    }
    void animate();
    void draw();
    void move();
};
