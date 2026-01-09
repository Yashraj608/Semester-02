#include<iostream>
using namespace std;
template <typename T>
class Person{
protected:
T name;
public:
Person(T name){
    this->name = name;
}

void showname(){
    cout<<"Name is: "<<name<<endl;
}
};

template <typename T>
class student: public Person<T>{
    int rollnum;
    public:
    student(T name,int rollnum):Person<T>(name){
        this->rollnum = rollnum;
    }

    void showstudent(){
        this->showname();
        cout<<"Roll number is: "<<rollnum<<endl;
    }
};
int main(){
    student<string> s("yash raj",102);
    s.showstudent();
}