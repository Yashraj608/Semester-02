#include<iostream>
using namespace std;
class Atm;
class BankAccount{
private:
string holdername;
int accountnum;
float balance;
public:
BankAccount(string holdername, int accountnum,float balance){
    this->accountnum = accountnum;
    this->balance = balance;
    this->holdername = holdername;
}

friend class Atm;
};

class Atm{
public:
void viewBalance(BankAccount b){
    cout<<"Balance is : "<<b.balance<<endl;
}

void withdraw(BankAccount w){
    if (w.balance > 500)
    {
        cout<<"Withdraw can be made"<<endl;
    }
}

void deposit(BankAccount d){
    cout<<"Deposit can be made"<<d.balance<<endl;

}
};
int main(){
BankAccount b1("yash raj",1234,5000);

Atm machine;
machine.viewBalance(b1);
machine.withdraw(b1);
machine.deposit(b1);

    return 0;
}