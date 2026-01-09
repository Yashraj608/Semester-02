#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class user {
protected:
    string name;
    string id;
    string department;
    bool feespaid;
    bool transportactivecard;
    string ans;
    string route;
    string pickup;
    string dropoff;

public:
    user(string name, string id, string department) : name(name), id(id), department(department), feespaid(false), transportactivecard(false) {}

    virtual void registerfortransport() {
        string answer;
        cout << "Do you want to register for transport (Yes/No)" << endl;
        getline(cin, answer);
        if (answer == "yes") {
            checkfees();
        } else {
            cout << "Exiting the program" << endl;
            exit(0);
        }
    }

    virtual void checkfees() {
        cout << name << " have you paid your semester fees?" << endl;
        cin >> ans;
        cin.ignore();
        if (ans == "yes") {
            feespaid = true;
            activatetransportcard();
            booktransport();
        } else {
            cout << "Sorry! " << name << " to book your transport you must pay your semester fees" << endl;
            exit(0);
        }
    }

    virtual void booktransport() {
        cout << "Enter your route:" << endl;
        cout << "1.Clifton" << endl;
        cout << "2.Tariq Road" << endl;
        cout << "3.North Nazimabad" << endl;
        cout << "4.Shahra-e-Faisal" << endl;
        getline(cin, route);
        cout << "Enter your pickup point:" << endl;
        getline(cin, pickup);
        cout << "Enter your drop off point:" << endl;
        getline(cin, dropoff);
        cout << "You have successfully booked your transport for " << route << " route" << endl;
    }

    virtual void activatetransportcard() {
        if (feespaid) {
            transportactivecard = true;
            cout << name << " your transport card has been activated! Book your transport:" << endl;
        }
    }

    virtual void displaydetails() {
        cout << "====User Details====" << endl;
        cout << "Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Department: " << department << endl;
        cout << "Fees paid (Yes/No): " << ans << endl;
        cout << "Route: " << route << endl;
        cout << "Pickup point: " << pickup << endl;
        cout << "Drop off point: " << dropoff << endl;
    }

    string getroute() {
        return route;
    }
    string getname() {
        return name;
    }
    string getid() {
        return id;
    }
    
    bool operator ==(const user &other) const{
    	return route == other.route;
	}
};

class student : public user {
public:
    student(string name, string id, string department) : user(name, id, department) {}

    void registerfortransport() override {
        user::registerfortransport();
    }

    void checkfees() override {
        user::checkfees();
    }

    void booktransport() override {
        user::booktransport();
    }

    void activatetransportcard() override {
        user::activatetransportcard();
    }

    void displaydetails() override {
        cout << "====Student Details====" << endl;
         cout << "Student Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Department: " << department << endl;
        cout << "Fees paid (Yes/No): " << ans << endl;
        cout << "Route: " << route << endl;
        cout << "Pickup point: " << pickup << endl;
        cout << "Drop off point: " << dropoff << endl;
    }
};

class Teacher: public user{
	public:
	    Teacher(string name, string id, string department) : user(name, id, department) {}

    void registerfortransport() override {
        user::registerfortransport();
    }

    void checkfees() override {
          cout << name << " have you paid your monthly fees?" << endl;
        cin >> ans;
        cin.ignore();
        if (ans == "yes") {
            feespaid = true;
            activatetransportcard();
            booktransport();
        } else {
            cout << "Sorry! " << name << " to book your transport you must pay your monthly fees" << endl;
            exit(0);
        }
    }

    void booktransport() override {
        user::booktransport();
    }

    void activatetransportcard() override {
        user::activatetransportcard();
    }

    void displaydetails() override {
        cout << "====Teacher Details====" << endl;
        cout << "Teacher Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Department: " << department << endl;
        cout << "Fees paid (Yes/No): " << ans << endl;
        cout << "Route: " << route << endl;
        cout << "Pickup point: " << pickup << endl;
        cout << "Drop off point: " << dropoff << endl;
    }
};

class staff : public user{
	public:
		    staff(string name, string id, string department) : user(name, id, department) {}

    void registerfortransport() override {
        user::registerfortransport();
    }

    void checkfees() override {
           cout << name << " have you paid your monthly fees?" << endl;
        cin >> ans;
        cin.ignore();
        if (ans == "yes") {
            feespaid = true;
            activatetransportcard();
            booktransport();
        } else {
            cout << "Sorry! " << name << " to book your transport you must pay your monthly fees" << endl;
            exit(0);
        }
    }

    void booktransport() override {
        user::booktransport();
    }

    void activatetransportcard() override {
        user::activatetransportcard();
    }

    void displaydetails() override {
        cout << "====Staff Details====" << endl;
         cout << "Staff Name: " << name << endl;
        cout << "Id: " << id << endl;
        cout << "Department: " << department << endl;
        cout << "Fees paid (Yes/No): " << ans << endl;
        cout << "Route: " << route << endl;
        cout << "Pickup point: " << pickup << endl;
        cout << "Drop off point: " << dropoff << endl;
    }
		
};

int main() {
    cout << "Name: Yash Raj" << endl;
    cout << "Roll Number: 24k-0737" << endl;
    
    
    student s1("Yash Raj", "24k-0737", "cs");
    s1.registerfortransport();
    s1.displaydetails();


Teacher T("sir Rahim","TK-001","physics");
T.registerfortransport();
T.displaydetails();

staff Sf("Akbar","101-99","Gardening");
Sf.registerfortransport();
Sf.displaydetails();


if(s1==T && T==Sf){
	cout<<"All users have same route"<<endl;
}
else{
	cout<<"All users have different routes"<<endl;
}

}
