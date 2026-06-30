#include <iostream>
#include <cstring>
using namespace std;

class Employee {
public:
    char* name;
    int id;
    float salary;

    // Constructor
    Employee(const char* empName, int empId, float empSalary) {
        name = new char[strlen(empName) + 1];
        strcpy(name, empName);
        id = empId;
        salary = empSalary;
    }

    // Shallow Copy Constructor
    Employee(const Employee& other) {
        name = other.name;  // Shallow copy: pointer copied, no new memory allocated
        id = other.id;
        salary = other.salary;
    }

    // Set new name (will affect both objects in shallow copy!)
    void setname(const char* newname) {
        strcpy(name, newname);
    }

    void display() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
    }

    // Destructor
    ~Employee() {
        delete[] name;
    }
};

int main() {
    Employee e("Yash Raj", 222, 22000);
    Employee e1 = e;  // Shallow copy constructor called

    cout << "Before modifying e1:\n";
    e.display();
    e1.display();

    e1.setname("Shahnawaz");  // This modifies name in both e and e1

    cout << "\nAfter modifying e1:\n";
    e.display();   // Name will be changed here too! (due to shallow copy)
    e1.display();

    return 0;
}
