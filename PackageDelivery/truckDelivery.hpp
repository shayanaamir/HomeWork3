#pragma once
#include "truck.hpp"

class TruckDelivery{
public:
    int num_of_drivers;
    Truck trucks[10];
    void loadTrucks();
    void calculateCost();
    void makeJourney();
    void unloadTrucks();
};
	
