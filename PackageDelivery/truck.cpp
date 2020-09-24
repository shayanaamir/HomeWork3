#include "box.hpp"
#include "truck.hpp"
#include <iostream>
using namespace std;
void Truck::load(int numBox)
{
    for(int i=0; i< 10; i++)
    {
        Box c;
        c.width = 5 + (rand() % 25 + 1);
        c.length = 5 + (rand() % 25 + 1);
        c.height = 5 + (rand() % 25 + 1);
        box[i] = c;
        cout << "Width : " << c.width << " Length : " << c.length << " Height : " << c.height << endl;
    }
}
void Truck::unload()
{
    for(int i=0; i<10; i++)
    {
        cout << box[i].volume() << endl;
        Box c;
        box[i]= c;
    }
}

float Truck::cost()
{
    int topup;
    topup = 50 - petrol;
    return topup*2.73;
}

