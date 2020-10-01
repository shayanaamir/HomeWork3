#include "truck.hpp"
#include "truckDelivery.hpp"
#include <fstream>
#include <iostream>

using namespace std;
int len;
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
    len = i;
}
void TruckDelivery::calculateCost()
{
    for(int k=0; k<len; k++)
    {
        float onewaydistance = 30.0;
        Truck t = trucks[k];
        float petrolgoing = onewaydistance/t.fullMileage;
        float petrolcoming = onewaydistance/t.emptyMileage;
        float totalcost = (petrolcoming + petrolgoing)*2.73;
        cout << "Truck " << t.driver << " has milegae " << t.emptyMileage << ", " << t.fullMileage << " has petrol going " << petrolgoing << " has coming " << petrolcoming << " total cost " << totalcost << endl;
    }
}
void TruckDelivery::makeJourney()
{
    for(int k=0; k<len; k++)
    {
        float onewaydistance = 30.0;
        Truck t = trucks[k];
        float petrolgoing = onewaydistance/t.fullMileage;
        float petrolcoming = onewaydistance/t.emptyMileage;
        float totalcost = (petrolcoming + petrolgoing)*2.73;
        if (t.money - totalcost >=0)
        {
        t.petrol = 50 - petrolgoing - petrolcoming;
        t.money = t.money - totalcost;
        cout << t.driver << " has made the journey." << endl;
        trucks[k] = t;
        }
    }
}
void TruckDelivery::unloadTrucks()
{
    ofstream newf("Trip.txt");
    int j=0;
    Truck k;
    for(int i=0; i<len; i++)
    {
        newf << trucks[i].driver << endl << 
        trucks[i].petrol << endl << 
        trucks[i].money << endl << 
        trucks[i].emptyMileage << endl << 
        trucks[i].fullMileage << endl;
        trucks[i].unload();
    }
}