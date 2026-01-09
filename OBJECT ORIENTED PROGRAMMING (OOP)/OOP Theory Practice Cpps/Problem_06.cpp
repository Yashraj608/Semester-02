#include<iostream>
#include<string>
using namespace std;
class Book{
public:
string title,author,ISBN;
Book(string title, string author, string ISBN){
    this->author = author;
    this->title = title;
    this->ISBN = ISBN;

}
};
class Library{
public:
Book B;
string name;
Library(string name, string title, string author, string ISBN):B(title,author,ISBN){
    this->name = name;
}

void display(){
    cout<<"Title is : "<<B.title<<endl;
    cout<<"Author is : "<<B.author<<endl;
    cout<<"ISBN is: "<<B.ISBN<<endl;
}

};

int main(){
Library l("British","crawdads","Yash raj","2222");
l.display();
}