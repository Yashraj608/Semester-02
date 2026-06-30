#include<iostream>
#include<string>
using namespace std;
class FuelVehicle{
int fuelcapacity;
public:
FuelVehicle(int fuelcapacity){
    this->fuelcapacity = fuelcapacity;
}
void displayFuelInfo(){
    cout<<"Fuel capacity is: "<<fuelcapacity<<endl;
}
};
class ElectricVehicle{
int batteryCapacity;
public:
ElectricVehicle(int batteryCapacity){
    this->batteryCapacity = batteryCapacity;
}

void showBatteryInfo(){
    cout<<"Battery capacity is: "<<batteryCapacity<<endl;
}

};

class HybridVehicle: public FuelVehicle, public ElectricVehicle{
string model;
int range;
public:
HybridVehicle(int fuelcapacity,int batteryCapacity,string model,int range):FuelVehicle(fuelcapacity),ElectricVehicle(batteryCapacity){
this->model= model;
this->range = range;
}

void displayAllInfo(){
    FuelVehicle::displayFuelInfo();
    ElectricVehicle::showBatteryInfo();
    cout<<"Model is: "<<model<<endl;
    cout<<"Range is: "<<range<<endl;
}
};
int main(){
    HybridVehicle h(22,2,"Nokia",23);
    h.displayAllInfo();
    return 0;
}