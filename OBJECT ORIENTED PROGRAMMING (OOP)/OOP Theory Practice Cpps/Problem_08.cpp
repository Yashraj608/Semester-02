#include<iostream>
#include<string>
using namespace std;

class University{
public:
string name,location;
University(string name, string location){
    this->location = location;
    this->name = name;
}
};
class Student{
public:
string name;
int rollnum;
University* u;
Student(string name, int rollnum, University*u){
    this->name = name;
    this->rollnum= rollnum;
    this->u = u;
}
void display(){
    cout<<"Name is : "<<name<<endl;
    cout<<"Roll number is :"<<rollnum<<endl;
    cout<<"university location: "<<u->location<<endl;
    cout<<"University name: "<<u->name<<endl;
}
};
int main(){
    University u("shah latif town","fast");
    Student s("Yash raj",222,&u);
    s.display();
       return 0;
}