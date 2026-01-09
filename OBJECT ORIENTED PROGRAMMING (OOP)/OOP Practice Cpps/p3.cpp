#include<iostream>
using namespace std;
class RetailShop;
class Customer;
class Warehouse{
    private:
    string itemName;
    int stock;
    float costPrice;

    public:
Warehouse(string itemName, int stock, float costPrice){
    this->costPrice = costPrice;
    this->stock = stock;
    this->itemName = itemName;
}

friend class RetailShop;
friend void processOrder(Warehouse& , RetailShop&, Customer&, int );
friend void viewstock(Warehouse&);
};

class RetailShop{
private:
string shopname;
int inventory;
float sellingPrice;
public:
RetailShop(string shopname, int inventory, float sellingPrice){
    this->shopname = shopname;
    this->inventory = inventory;
    this->sellingPrice = sellingPrice;
}

friend class Cutomer;
friend void ProcessOrder(Warehouse&, RetailShop&, Customer& , int );
friend void DisplayShopSummary(RetailShop&);
};
class Customer{
private:
string Customername;
int itemBought;
float totalBill;
public:
Customer(string Customername, int itemBought, float totalBill){
    this->Customername = Customername;
    this->itemBought = itemBought;
    this->totalBill = totalBill;
}
friend void ProcessOrder(Warehouse&, RetailShop&, Customer&, int);
friend void DisplayCustomerInfo(Customer &);
};

void ProcessOrder(Warehouse w , RetailShop r, Customer c,int quantity){
    
}
int main(){
    return 0;
}