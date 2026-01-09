#include<iostream>
#include<string>
using namespace std;
template <typename T>
T findMin(T a, T b){
    if(a<b){
        cout<<a<<"<"<<b<<endl;
    }
}
int main(){
    cout<< findMin<int>(20,30);
    return 0;
}