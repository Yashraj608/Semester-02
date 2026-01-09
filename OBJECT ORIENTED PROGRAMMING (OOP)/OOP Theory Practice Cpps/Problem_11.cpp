//single inheritance//
#include<iostream>
#include<string>
using namespace std;
class person{
string name;
int age;
public:
person(string name,int age){
    this->age = age;
    this->name = name;
}
virtual void display(){
    cout<<"Name is : "<<name<<endl;
    cout<<"Age is : "<<age<<endl;
}
};
class Employee : public person{
string department;
int empid;
public:
Employee(string name,int age,string department,int empid):person(name,age){
    this->department = department;
    this->empid = empid;
}

void display()override{
   person::display();
}

};
int main(){
    Employee e("Yash raj",22,"Bology",222);
    e.display();
    return 0;
}