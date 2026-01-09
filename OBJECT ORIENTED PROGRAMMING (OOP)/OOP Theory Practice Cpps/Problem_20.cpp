//abstraction//
#include<iostream>
#include<string>
using namespace std;
class Course{
public:
virtual void showContent()=0;
virtual int getDuration()=0;
};
class ProgrammingCourse : public Course{
public:
void showContent()override{
    cout<<"This course includes all the programming fundamentals.."<<endl;
}

int getDuration() override{
    cout<<"Its duration is 4 months.."<<endl;
}
};
class DesignCourse: public Course{
public:
void showContent()override{
    cout<<"Design course is all about the ui/ux"<<endl;
}
int getDuration()override{
    cout<<"Design Course duration is of 5 months"<<endl;
}
};
int main(){
    Course*c[2];
    c[0]= new ProgrammingCourse();
    c[1]= new DesignCourse();

    for(int i =0;i<2;i++){
        c[i]->showContent();
        c[i]->getDuration();
    }

    for ( int i = 0; i <2; i++)
    {
        delete c[i];
    }
    
    return 0;
}