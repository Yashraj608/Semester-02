//Yash Raj//
//24k-0737//
#include <iostream>
#include <string>

using namespace std;

class User {
public:
    string name;
    int age;
    string contact;
    int userid;
    string licensetype;
    User* next;

    User(): name(""), age(0), contact(""), userid(0), licensetype(""), next(nullptr) {}

    void registerUser() {
        cin.ignore();
        cout<<"Enter your name: "<<endl;
        getline(cin, name);

        cout<<"Enter your age: "<<endl;
        cin>>age;
        cin.ignore();

        cout<<"Enter your contact number: "<<endl;
        getline(cin, contact);

        cout<<"Enter your user ID: "<<endl;
        cin>>userid;
        cin.ignore();

        cout<<"Select your license type (Learner / Intermediate / Full): ";
        getline(cin, licensetype);
    }

    void displayDetails() {
        cout<<"User Details: "<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Contact No: "<<contact<<endl;
        cout<<"User ID: "<<userid<<endl;
        cout <<"License Type: "<<licensetype<<endl;
    }
};

class Vehicle {
public:
    string model;
    double rentalPrice;
    string allowedLicense;
    Vehicle* next;

    Vehicle(string m, double price, string license) : model(m), rentalPrice(price), allowedLicense(license), next(nullptr) {}

    void display() {
        cout << "Model: " <<model<<endl;
		cout<<"Rental Price: " <<rentalPrice<<" Rs per day "<<endl;
		cout<<"Required License: " <<allowedLicense<<endl;
    }
};

class RentalSystem {
private:
    User* userHead;
    Vehicle* vehicleHead;

public:
    RentalSystem():userHead(nullptr), vehicleHead(nullptr) {}

    ~RentalSystem() {
        while (userHead) {
            User* temp = userHead;
            userHead = userHead->next;
            delete temp;
        }

        while (vehicleHead) {
            Vehicle* temp = vehicleHead;
            vehicleHead = vehicleHead->next;
            delete temp;
        }
    }

    void addUser() {
        User* newUser = new User();
        newUser->registerUser();
        newUser->next=userHead;
        userHead=newUser;
        cout<<"User registered successfully!"<<endl;
    }

    void displayUsers() {
        if (!userHead) {
            cout<<"No users registered!"<<endl;;
            return;
        }
        User* uPtr = userHead;
        while (uPtr) {
            uPtr->displayDetails();
            uPtr=uPtr->next;
        }
    }

    void addVehicle(string model, double price, string license) {
        Vehicle* newVehicle = new Vehicle(model, price, license);
        newVehicle->next = vehicleHead;
        vehicleHead = newVehicle;
    }

    void displayVehicles() {
        if (!vehicleHead) {
            cout<<"No vehicles available!"<<endl;
            return;
        }
        Vehicle* vPtr = vehicleHead;
        while (vPtr) {
            vPtr->display();
            vPtr = vPtr->next;
        }
    }

    void rentVehicle(int userID, string model) {
        User* uPtr = userHead;
        while (uPtr) {
            if (uPtr->userid == userID) {
                Vehicle* vPtr = vehicleHead;
                while (vPtr) {
                    if (vPtr->model == model) {
                        if (uPtr->licensetype == vPtr->allowedLicense) {
                            cout<<"Vehicle rented successfully!"<<endl;
                        } else {
                            cout<<"User is not eligible to rent this vehicle!"<<endl;
                        }
                        return;
                    }
                    vPtr=vPtr->next;
                }
                cout<<"Vehicle not found!"<<endl;
                return;
            }
            uPtr=uPtr->next;
        }
        cout<<"User not found!"<<endl;
    }
};

int main() {
    RentalSystem rental;

    rental.addVehicle("Honda Civic",50,"Intermediate");
    rental.addVehicle("Toyota Corolla",45,"Full");
    rental.addVehicle("Kia Sportage",30,"Learner");

    int choice;
    cout<<"Name: Yash Raj"<<endl;
    cout<<"Roll Number: 24k-0737"<<endl;
    do {
        cout<<"Enter your choice:"<<endl;
        cout<<"1. Register User"<<endl;
        cout<<"2. Display Users"<<endl;
        cout<<"3. Display Vehicles"<<endl;;
        cout<<"4. Rent a Vehicle"<<endl;
        cout<<"0. Exit"<<endl;
        cin>>choice;

        switch (choice) {
            case 1:
                rental.addUser();
                break;
            case 2:
                rental.displayUsers();
                break;
            case 3:
                rental.displayVehicles();
                break;
            case 4: {
                int userID;
                string vehicleModel;
                cout<<"Enter user ID: "<<endl;
                cin>>userID;
                cout<<"Enter vehicle model: "<<endl;
                cin.ignore();
                getline(cin, vehicleModel);
                rental.rentVehicle(userID, vehicleModel);
                break;
            }
            case 0:
                cout << "Exiting program."<<endl;
                break;
            default:
                cout << "Invalid choice."<<endl;
        }
    } while (choice != 0);

    return 0;
}
