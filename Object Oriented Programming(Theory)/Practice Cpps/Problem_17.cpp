#include<iostream>
#include<string>
using namespace std;
class Distance{
int km;
int meters;
public:
Distance(int km, int meters){
    this->km = km;
    this->meters = meters;
}
Distance operator+(const Distance& other){
    return Distance(km+other.km,meters+other.meters);
}

Distance operator-(const Distance& other){
  return Distance(km - other.km , meters -other.meters);
}

Distance operator*(const Distance& other){
    return Distance(km* other.km, meters*other.meters);
}

bool operator==(const Distance& other){
    return(km ==other.km &&
    meters == other.meters);
}

Distance& operator++(){
    ++km;
    ++meters;
    return *this;
}

Distance operator++(int){
    Distance temp = *this;
    km++;
    meters++;
    return temp;
}


friend ostream& operator<<(ostream& out, const Distance& other){
    out<<"The distance in km is: "<<other.km<<endl;
    out<<"The distance in meters is: "<<other.meters<<endl;
    return out;
}
friend istream& operator>>(istream& in,  Distance &other){
    cout<<"Enter the new distnace"<<endl;
    in>>other.km;
    cout<<"Enter the new distance in meters"<<endl;
    in>>other.meters;
    return in;
}

Distance& operator=(const Distance& other){
    if(this!= &other){
        km = other.km;
        meters = other.meters;

    }
    return *this;
}
};
int main(){
Distance d(1,1);
Distance d1(1,1);
Distance d2 = d +d1;
cout<<d2<<endl;
Distance d3 = d - d1;
cout<<d3<<endl;
Distance d4 = d*d1;
cout<<d4<<endl;

++d;
cout<<d<<endl;
d++;
cout<<d<<endl;

if(d==d1){
    cout<<"equal"<<endl;
}else{
    cout<<"They are not equal"<<endl;
}
};





