#include<iostream>
#include<string>
using namespace std;
template <typename T,typename T1, typename T2>
class Student{
protected:
T rollnum;
T1 name;
T2 marks;
public:
Student(T rollnum, T1 name, T2 marks){
   this->rollnum= rollnum;
    this->name= name;
    this->marks = marks;
}

void display(){
    cout<<"Roll Number: "<<rollnum<<endl;
    cout<<"Name is: "<<name;
    cout<<"Marks: "<<marks<<endl;
}
};
int main(){
    Student<int,string,float> s1(2,"Yash raj",200.0);
    s1.display();
    return 0;
}