#include<iostream>
using namespace std;
template <typename T>
class shape{
    protected:
    T color;
    public:
    shape(T color){
        this->color = color;
    }
 void showcolor(){
    cout<<"The color is "<<color<<endl;
 }
};
template<typename T>
class Rectangle: public shape<T>{
protected:
int width,height;
public:
Rectangle(T color, int width, int height):shape<T>(color){
    this->height= height;
    this->width = width;
}
void showdetails(){
    this->showcolor();
    cout<<"The height is: "<<height<<endl;
    cout<<"The width is: "<<width<<endl;
}
};
int main(){
Rectangle<string> r("red",2,2);
r.showdetails();
    return 0;
}