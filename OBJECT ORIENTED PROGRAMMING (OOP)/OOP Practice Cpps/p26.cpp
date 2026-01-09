#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cstring>
using namespace std;
class Student{
public:
int id;
char name[30];
float marks;


void input(){
    cout<<"Enter the name of student"<<endl;
    cin.getline(name,20);
    cout<<"Enter the id of student"<<endl;
    cin>>id;
    cout<<"Enter the marks of students"<<endl;
    cin>>marks;

}
};

void writeToFile(){
    ofstream myfile("student.dat",ios::binary);
Student s;
s.input();
    if(myfile.is_open()){

cout<<"File opened successfully"<<endl;
  myfile.write(reinterpret_cast<char*>(&s),sizeof(s));
    myfile.close();
}else{
        cerr<<"File Failed to open"<<endl;
    }
}

void readFromFile(){
    Student s;
    ifstream yourfile("student.dat",ios::in);
    if(yourfile.is_open()){
        cout<<"File opened sucessfully"<<endl;    
    while(yourfile.read(reinterpret_cast<char*>(&s),sizeof(s))){
cout<<"Name is : "<<s.name<<endl;
cout<<"Id is :"<<s.id<<endl;
cout<<"Marks are: "<<s.marks<<endl;
    
}
yourfile.close();
    }else{
        cerr<<"File failed to open"<<endl;
    }
}


void searchById(){
    Student s;
    bool found = false;
    int searchid;
    cout<<"Enter the id you want to search"<<endl;
    cin>>searchid;
    
    ifstream idfile("student.dat",ios::in);
    if(idfile){
cout<<"File opened"<<endl;
while(idfile.read(reinterpret_cast<char*>(&s),sizeof(s))){
    if(s.id==searchid){
        cout<<"Record with id: "<<s.name<<" found"<<endl;
        found= true;
    }
}
idfile.close();
    }else{
        cerr<<"File Failed to open"<<endl;
    }
}

void extractMarksfromstring(){
    string line= "ID=12, Name=Ali, Marks=89.56";
    stringstream ss(line);
    string id,word;

    getline(ss,id,',');
    getline(ss,word,',');

    if(id.find("ID=")!=string::npos){
        string num = word.substr(3);
        id = stoi(num);
   
    }
     cout<<"The id is equals to: "<<id<<endl;
}

int main(){
    writeToFile();
    readFromFile();
    searchById();
    extractMarksfromstring();
}