#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class File{
    public:
int size;
string location,modification_date,created_date;
public:
File(int size, string location,string modification_date,string created_date){
    this->created_date = created_date;
    this->location = location;
    this->modification_date = modification_date;
    this->size = size;
}
virtual void open()=0;
virtual void print(){
    cout<<"Size of file is: "<<size<<endl;
    cout<<"Location is :"<<location<<endl;
    cout<<"Create date: "<<created_date<<endl;
    cout<<"Modified Date: "<<modification_date<<endl;
}
};
template <typename T>
bool operator*(const T& obj, const T& obj1){
    return((obj.location==obj1.location)&&(obj.size==obj1.size));
}
class PDF_File: public File{
public:
PDF_File(int size, string location,string modification_date,string created_date):File(size,location,modification_date,created_date){}

void print()override{
    cout<<"Location is : "<<location<<endl;
    cout<<"Size is: "<<size<<endl; 
}

void open()override{
    cout<<"Pdf file opened"<<endl;
}
};

class ps_File: public File{
public:
ps_File(int size,string location, string modification_date,string created_date):File(size,location,modification_date,created_date){}
void print()override{
   cout<<"location is : "<<location<<endl;
}

void open()override{
    cout<<"PS file opened..."<<endl;
}
};
int main(){
    File*f[2];
    f[0]= new PDF_File(2,"c drive","12-09-2000","32-00-0000");
    f[1]= new ps_File(2,"c drive","22-2222-22","23-09-3999");

    for(int i =0;i<2;i++){
        f[i]->open();
        f[i]->print();
    }

    cout<<((*f[0])*(*f[1]) ? "same" : "different");
    for(int i =0;i<2;i++){
        delete f[i];
    }
    return 0;
}