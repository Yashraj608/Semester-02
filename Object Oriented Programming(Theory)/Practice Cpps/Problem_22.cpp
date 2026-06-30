#include<iostream>
using namespace std;

class Employee {
public:
    virtual void Work() {
        cout << "Employee is Working.." << endl;
    }
};

class Manager : public Employee {
public:
    void Work() override {
        cout << "Manager is working..." << endl;
    }

    void HoldMeeting() {
        cout << "Manager is holding the meeting.." << endl;
    }
};

int main() {
    Manager m;
    Employee* e = &m;  // Upcasting

    e->Work();

    Manager*m1 = dynamic_cast<Manager*>(e);
    m1->HoldMeeting();
    // Add your downcasting code here to call HoldMeeting()

    return 0;
}
