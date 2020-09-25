#include "box.hpp"
Box::Box()
{
    length = width = height = 0;
}
int Box::volume()
{
    return length * width * height;
}