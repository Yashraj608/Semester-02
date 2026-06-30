#include<iostream>
#include<string>
using namespace std;

class Course{
public:
string courseName;
Course(string courseName){
    this->courseName = courseName;
}
};
class Teacher{
public:
Course*courses;
string name, qualification;
Teacher(string name, string qualification,Course*C){
    this->name = name;
    this->qualification = qualification;
    this->courses = C;

}
void display(){
    cout<<"Teacher name is : "<<name<<endl;
    cout<<"Teacher qualification: "<<qualification<<endl;
    cout<<"Course assigned to teacher is: "<<courses->courseName<<endl;

}

};
int main(){
    Course c("Biology");
    Teacher T("Yash raj","undergraduate",&c);
    T.display();
    return 0;
}