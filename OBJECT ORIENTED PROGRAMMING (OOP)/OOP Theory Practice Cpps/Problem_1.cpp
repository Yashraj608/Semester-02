#include<iostream>
using namespace std;
class StudentICSE;
class StudentCBSE{
private:
string name;
int marks;
public:
StudentCBSE(string name, int  marks):name(name),marks(marks){}
friend bool comparemarks(StudentCBSE, StudentICSE);
};
class StudentICSE{
private:
string name;
int marks;
public:
StudentICSE(string name,int marks){
    this->marks= marks;
    this->name=name;
}
    friend bool comparemarks(StudentCBSE,StudentICSE);

};
bool comparemarks(StudentCBSE c,StudentICSE i){
    bool equal = false;
    if(c.marks == i.marks){
        cout<<"Both marks are equal"<<endl;
        equal = true;
    }else if(c.marks > i.marks){
        cout<<"Highest marks holder is: "<<c.name<<endl;
        equal = false;
    }
    return equal;
}
int main(){

    StudentCBSE s("yash raj",22);
    StudentICSE i("saad",20);
    comparemarks(s,i);
return 0;
}