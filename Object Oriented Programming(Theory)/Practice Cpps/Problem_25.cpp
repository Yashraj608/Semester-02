#include<iostream>
#include<string>
using namespace std;
class JewelaryItem{
public:
string itemCode;
string itemName;
double weightinGrams;
int purity;
virtual void displaydetails(){
    cout<<"Item code is: "<<itemCode<<endl;
    cout<<"Item Name is: "<<itemName<<endl;
    cout<<"Weight in grams: "<<weightinGrams<<endl;
    cout<<"Purity is: "<<purity<<endl;

}

virtual double calculatePrice()=0;
};

class GoldJewelary: public JewelaryItem{
public:
int karat;
void setGoldKarat(int karat){
    cout<<"The gold item is of "<<karat<<" karat gold"<<endl;
}

double calculatePrice()override{
    cout<<"Price is base on the purity and weight"<<endl;
}
};

class DiamondJewelary: public JewelaryItem{
public:
int num;
double carat;
void addDiamonds(int num,double carat){
    cout<<num<<" diamonds of "<<carat<<" carat added to the item"<<endl;
}

double calculatePrice()override{
cout<<"Price is calculated on the basis of weight purity and diamond carat"<<endl;
}
};

class Customer {
public:
string name;
string customerid;
JewelaryItem* purchaseitem[20];
int itemCount ;


void purchaseditem(JewelaryItem* item){
    if(itemCount < 20){
        purchaseitem[itemCount++]=item;
        cout<<"Item purchased successfully"<<endl;
    }
}
};

int main(){
    JewelaryItem* gold = new GoldJewelary();
gold->itemName = "Bangles";
gold->itemCode="21k90";
gold->purity=2;
gold->weightinGrams = 22.0;
gold->displaydetails();



JewelaryItem*Diamond = new DiamondJewelary();
Diamond->itemName="Diamond";
Diamond->itemCode="24k=0737";
Diamond->purity=100;
Diamond->weightinGrams=22.0;
Diamond->displaydetails();


Customer s;
s.purchaseditem(gold);
    return 0;
}