#include "HUPigeons.hpp"



void HUPigeons::drawObjects(){
    for (int i=0; i<20; i++)
    {
        my_pigeons[i].draw();  // set function name as draw... gRenderer
    }
}