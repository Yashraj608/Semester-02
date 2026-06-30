#include<iostream>
using namespace std;
class Device{
string brand;
int warranty;
public:
Device(string brand,int warranty){
    this->brand = brand;
    this->warranty = warranty;
}

virtual void display(){
    cout<<"Device Brand is: "<<brand<<endl;
    cout<<"Warranty period is: "<<warranty<<endl;
}

};

class SmartAppliance: virtual public Device{
float powerUsage;
public:
SmartAppliance(string brand,int warranty,float powerUsage):Device(brand,warranty){
    this->powerUsage = powerUsage;
}
void display()override{
  cout<<"Power usage is: "<<powerUsage<<endl;
}

};

class NetworkDevice :virtual public Device{
string  version;
public:
NetworkDevice(string brand, int warranty,string version):Device(brand,warranty){
    this->version = version;
}
void display()override{
    cout<<"Wifi version is : "<<version<<endl;
}
};

class SmartSpeaker :public SmartAppliance, public NetworkDevice{
    string model;
    public:
    SmartSpeaker(string brand, int warranty,float powerUsage,string version,string model):Device(brand,warranty),SmartAppliance(brand,warranty,powerUsage),NetworkDevice(brand,warranty,version){
        this->model = model;
    }

    void display()override{
        Device::display();
        SmartAppliance::display();
        NetworkDevice::display();
        cout<<"Model is : "<<model<<endl;
    }
};
int main(){
 SmartSpeaker d("Nokia",2,2090.0,"2013","Model");
    d.display();
    return 0;
}