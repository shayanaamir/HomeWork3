#include "truck.hpp"
#include "truckDelivery.hpp"
#include <fstream>
#include <iostream>

using namespace std;
void TruckDelivery::loadTrucks()
{
    ifstream x("Drivers.txt");
    string line;
    int i=0;
    while(getline(x,line))
    {
        Truck t;
        for (int j=0; j<sizeof(line); j++)
        {
        t.driver[j]=line[j];
        }
        getline(x,line);
        t.petrol = stof(line);

        getline(x,line);
        t.money = stof(line);

        getline(x,line);
        t.emptyMileage = stof(line);

        getline(x,line);
        t.fullMileage = stof(line);
        t.load(10);
        trucks[i] = t;
        i++;
    }
    x.close();
}
void TruckDelivery::calculateCost()
{
    for(int k=0; k<10; k++)
    {
        int onewaydistance = 30;
        Truck t = trucks[k];
        float petrolgoing = onewaydistance/t.fullMileage;
        float petrolcoming = onewaydistance/t.emptyMileage;
        float totalcost = (petrolcoming + petrolgoing)*2.73;
        cout << "Truck " << t.driver << " has milegae " << t.emptyMileage << ", " << t.fullMileage << " has petrol going " << petrolgoing << " has coming " << petrolcoming << " total cost " << totalcost << endl;
    }
}
void TruckDelivery::makeJourney()
{
    for(int k=0; k<10; k++)
    {
        int onewaydistance = 30;
        Truck t = trucks[k];
        int petrolgoing = onewaydistance/t.fullMileage;
        int petrolcoming = onewaydistance/t.emptyMileage;
        int totalcost = petrolcoming*2.73 + petrolgoing*2.73;
        t.petrol = 50 - petrolgoing - petrolcoming;
        t.money = t.money - totalcost;
        trucks[k] = t;
    }
}
void TruckDelivery::unloadTrucks()
{
    ofstream newf("Trip.txt");
    for(int i=0; i<sizeof(trucks); i++)
    {
        newf << trucks[i].driver << endl << 
        trucks[i].petrol << endl << 
        trucks[i].money << endl << 
        trucks[i].emptyMileage << endl << 
        trucks[i].fullMileage << endl;
    }
}