#include<iostream>
#include<string>
using namespace std;
class person{
string name;
int age;
public:

person(string name,int age){
    this->name = name;
    this->age = age;

}
virtual void display(){
    cout<<"Name is : "<<name<<endl;
    cout<<"Age is: "<<age<<endl;
}
};

class Employee : public person{
int empid;
string designation;
public:
Employee(string name,int age, int empid,string designation):person(name,age){
    this->designation = designation;
    this->empid = empid;

}
void display()override{
    person::display();
    cout<<"Designation is : "<<designation<<endl;
    cout<<"Employee id : "<<empid<<endl;
}
};
class Manager : public Employee{
string department;
int teamsize;
public:
Manager(string name,int age, int empid,string designation,string department,int teamsize):Employee(name,age,empid,designation){
    this->department = department;
    this->teamsize = teamsize;

}
void display()override{
    Employee::display();
    cout<<"Department is : "<<department<<endl;
}
};
int main(){
    Employee e("yash raj",22,222,"Regional Manager");
    e.display();

    Manager m("Akshay",22,222,"Hr","Biology",23);
    m.display();
    return 0;
}