#include<iostream>
#include<stdexcept>
using namespace std;
class Atm{
    protected:
string accholder;
float balance;
public:
Atm(string accholder,float balance){
    this->accholder = accholder;
    this->balance= balance;
}
void deposit(double amount){
    try{
        if(amount < 0){
            throw invalid_argument("Insufficient Balance");
        }else {
            cout<<"You can deposit the money"<<endl;
        }
    }catch(const exception& e){
        cout<<"msg is: "<<e.what()<<endl;
    }
}

void withdraw(double amount){
    try{
        if(amount<=0){
            throw runtime_error("Runtime Error");
        }
    }catch(const exception& e){
        cout<<"Message is: "<<e.what()<<endl;
    }
}
};
int main(){
    Atm a("Yash raj",1000);
a.deposit(-1);

    return 0;
}