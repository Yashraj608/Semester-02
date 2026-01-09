// shallow copy constructor//
#include<iostream>
#include<cstring>
using namespace std;
class stringHolder{
public:
char* str;
stringHolder(const char*string){
    this->str = new char[strlen(string)+1];
    strcpy(str,string);
}

stringHolder(const stringHolder& other){
    str = other.str;
}

void displayString(){
    cout<<"The stored string is : "<<str<<endl;
}

void setstr(const char* newstr){
    strcpy(str,newstr);
}

~stringHolder(){
    delete[]str;
}
};
int main(){
stringHolder s("Yash Raj");
s.displayString();
stringHolder s1 = s;
s1.displayString();

s.setstr("Saad");
s.displayString();
    return 0;
}