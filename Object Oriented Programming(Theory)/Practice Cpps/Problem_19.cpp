#include<iostream>
using namespace std;
class BankCustomer{
    string name;
    int accnum;
    float lastTransactions[5];
public:
BankCustomer(string name, int accnum,float f[]){
    this->accnum = accnum;
    this->name= name;
    for(int i =0;i<5;i++){
        lastTransactions[i] = f[i];
    }
}

void display(){
    cout<<"Name is: "<<name<<endl;
    cout<<"Account Number: "<<accnum<<endl;
    cout<<"Last 5 transactions are: "<<endl;
    for(int i=0;i<5;i++){
        cout<<lastTransactions[i]<<endl;
    }
}
};
int main(){
    float LastTransactions[5]= {22.0,33,21,55,66};
    BankCustomer b("yash raj",222,LastTransactions);
    b.display();
    return 0;
}