#include<iostream>
#include<string>
using namespace std;
class BankAccount{
int accountnum;
static int totalAccounts;
public:

BankAccount(int accountnum){
    this->accountnum = accountnum;
    totalAccounts++;
}

static void showTotalAcounts();
};

int BankAccount::totalAccounts = 0;

void BankAccount ::showTotalAcounts(){
    cout<<"Total bank accounts are: "<<totalAccounts<<endl;
}

int main(){
    BankAccount b(222);
    b.showTotalAcounts();
 BankAccount b1(222);
  b1.showTotalAcounts();
    return 0;
}