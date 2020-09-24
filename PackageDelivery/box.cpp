#include "box.hpp"
struct Box
{
    int length;
    int width;
    int height;

    Box()
    {
        length = width = height = 0;
    }


    int volume()
    {
        return length*width*height;
    }
};