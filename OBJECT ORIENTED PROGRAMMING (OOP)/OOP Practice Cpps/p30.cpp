#include<iostream>
#include<string>
using namespace std;
template <typename T>
class Box{
    private:
    T data;
    public:
    Box(T data){
       this->data= data;
    }

    void showContent(){
        cout<<"content is: "<<data<<endl;
    }
};
int main(){
    Box<int> intBox(123);
    intBox.showContent();

    Box<string> strBox("Hello");
    strBox.showContent();
    return 0;
}