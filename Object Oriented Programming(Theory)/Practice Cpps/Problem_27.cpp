#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main(){
    ofstream myfile("pratice.txt",ios::app);
if(myfile.is_open()){
    cout<<"File opened sucessfully"<<endl;
    cout<<"The position before writing anything is: "<<myfile.tellp()<<endl;
myfile<<"OpenAIisCool"<<endl;
cout<<"The position of pointer is on: "<<myfile.tellp()<<endl;
myfile.seekp(4,ios::beg);
myfile.put('c');
}
else{
    cerr<<"File Filed to open"<<endl;
}
}