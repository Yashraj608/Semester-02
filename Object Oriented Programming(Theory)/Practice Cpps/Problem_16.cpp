#include<iostream>
#include<string>
using namespace std;
class Money{
int rupees,paise;
public:
Money(int rupees,int paise):rupees(rupees),paise(paise){}

Money operator+(const Money&other){
    return Money(rupees+other.rupees, paise+other.paise);
}

Money operator-(const Money& other){
    return Money(rupees-other.rupees, paise- other.paise);
}

bool operator==(const Money& other){
    return (rupees == other.rupees,paise == other.paise);
}

Money operator=(const Money& other){
    if(this!= &other){
   rupees = other.rupees;
paise = other.paise;
return *this;
    }
}

friend ostream& operator<<(ostream& out, Money& other){
    out<<"Rupees: "<<other.rupees<<endl;
    out<<"Paise: "<<other.paise<<endl;
   return out;
}

friend istream& operator >>(istream& in, Money& other){
    cout<<"Enter the rupees: "<<endl;
    in >> other.rupees;
    cout<<"Enter the paise: "<<endl;
    in >> other.paise;
    return in; 
}

Money& operator++(){
    ++rupees;
    ++paise;
    return*this;
}

Money operator++(int){
    Money temp = *this;
    ++rupees;
    ++paise;
    return temp;
}


};
int main(){
    Money m(12,32);
    Money m1(22,34);
   Money m3 = m+m1;
   Money m4 = m1 - m;

   cout<<m3<<endl;
   cout<<m4<<endl;

   if(m==m1){
    cout<<"Equal"<<endl;
   }
   else{
    cout<<"not equal"<<endl;
   }

   ++m;

   m++;

   cin>> m;
   cin>>m1;
   
   if(m==m1){
    cout<<"Equal"<<endl;
   }
   else{
    cout<<"not equal"<<endl;
   }
    return 0;
}