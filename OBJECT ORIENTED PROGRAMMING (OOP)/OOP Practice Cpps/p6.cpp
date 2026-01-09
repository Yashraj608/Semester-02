//Deep copy//
#include<iostream>
#include<cstring>
using namespace std;
class Book{
public:
char*title;
char*author;
int pages;
Book(const char*t, const char* a, int pages){
    title = new char[strlen(t)+1];
    strcpy(title,t);
    author = new char[strlen(a)+1];
    strcpy(author,a);
    this->pages = pages;
}

Book(const Book& other){
    title = new char[strlen(other.title)+1];
    strcpy(title, other.title);
    author = new char[strlen(other.author)+1];
    strcpy(author,other.author);
    pages = other.pages;
}

void displayBook(){
    cout<<"Title of book is : "<<title<<" Author name is : "<<author<<" pages are: "<<pages<<endl;
}
};
int main(){
Book b("Crawdads","yashraj",223);
Book b1 = b;
b.displayBook();
b1.displayBook();

    return 0;
}