#include<iostream>
using namespace std;
class Person{
string name;
int age;
public:

Person(string name,int age){
    this->age = age;
    this->name = name;
}
 void showPersonInfo(){
    cout<<"Name is: "<<name<<endl;
    cout<<"Age is: "<<age<<endl;
}
};
class DeviceUser:virtual public Person{
public:
string deviceName;
int usageHours;
DeviceUser(string name,int age,string deviceName,int usageHours):Person(name,age){
    this->deviceName = deviceName;
    this->usageHours = usageHours;
}

void showDeviceUsage(){
    cout<<"Device Name: "<<deviceName<<endl;
    cout<<"Hours Usage: "<<usageHours<<endl;
}
};

class Teacher: virtual public Person{
string subject;
float salary;
public:
Teacher(string name,int age,string subject, float salary):Person(name,age){
    this->salary = salary;
    this->subject = subject;
}

void showTeacherInfo(){
    cout<<"Subject :"<<subject<<endl;
    cout<<"Salary is: "<<salary<<endl;
}
};

class SmartTeacher: public DeviceUser, public Teacher{
int skillLevel;
public:
SmartTeacher(string name,int age,string subject, float salary, string deviceName, int usageHours,int skillLevel):Person(name,age),DeviceUser(name,age,deviceName,usageHours),Teacher(name,age,subject,salary){
    this->skillLevel = skillLevel;
}
void showAllInfo(){
showPersonInfo();
showDeviceUsage();
showTeacherInfo();
}
};
int main(){
    SmartTeacher s("Yash raj",22,"Biology",23.00,"Tablet",2,5);
    s.showAllInfo();
    return 0;
}