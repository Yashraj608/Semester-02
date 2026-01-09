//Down Casting//
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Bark!" << endl;
    }

    void fetch() {
        cout << "Dog is fetching the ball." << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }

    void scratch() {
        cout << "Cat is scratching the furniture." << endl;
    }
};

int main() {
    Dog d;
    Animal* a = &d;  // Upcasting

    a->makeSound();

    // Add your downcasting code here to call fetch() on Dog and safely check Cat
Dog* dptr = dynamic_cast<Dog*>(a);
dptr->fetch();

Cat*cptr = dynamic_cast<Cat*>(a);
cptr->scratch();
    return 0;
}
