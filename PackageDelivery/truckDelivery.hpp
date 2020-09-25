#pragma once
#include "truck.hpp"

class TruckDelivery{
public:
    Truck trucks[10];
    void loadTrucks();
    void calculateCost();
    void makeJourney();
    void unloadTrucks();
};
	
