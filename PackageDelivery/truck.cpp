#include "box.hpp"
#include <iostream>
using namespace std;

class Truck
{
    public:
    char driver[32];
    int petrol;
    int money;
    int fullMileage;
    int emptyMileage;
    Box box[10];

    void load(int numBox)
    {
    	for(int i=0; i< 10; i++){
    		Box c;
    		c.width = 5 + (rand() % 25 + 1);
    		c.length = 5 + (rand() % 25 + 1);
    		c.height = 5 + (rand() % 25 + 1);
    		box[i] = c;
            cout << "Width : " << c.width << " Length : " << c.length << " Height : " << c.height << endl;
    	}
    }
    void unload()
    {
    	for(int i=0; i<10; i++)
    	{
    		cout << box[i].volume() << endl;
            Box c;
            box[i]= c;
    	}
    }

    float cost()
    {
        int topup;
        topup = 50 - petrol;
        return topup*2.73;
    }
};

