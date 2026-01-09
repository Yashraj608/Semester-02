#include<iostream>
using namespace std;
class Employee{
    public:
    virtual void Work(){
        cout<<"Employee is Working.."<<endl;
    }
};
class Manager: public Employee{
public:
void Work() override{
    cout<<"Manager is working..."<<endl;
}

void HoldMeeting(){
    cout<<"Manager is holding the meeting.."<<endl;
}
};
int main(){
    Manager m;
    Employee* e;
    e = &m;
    e->Work();

    Manager*m1 = dynamic_cast<Manager*>(e);
    if(m1){
        m1->HoldMeeting();
    }
    return 0;
}