#include <iostream>
using namespace std;

class Animal {
protected:
    int energy;
public:
    Animal(int e = 50) : energy(e) {}

    void sleep() {
        cout << "I'm sleeping." << endl;
        energy++;
    }

    void eat() {
        cout << "I'm eating." << endl;
        energy++;
    }

    int getEnergy() {
        return energy;
    }
};

class Dog : public Animal {
private:
    string name;
public:
    Dog(string n) : name(n) {}

    void bark() {
        cout << "Bark!" << endl;
        energy--;
    }

    void run() {
        cout << "Running!" << endl;
        energy -= 3;
    }
};

int main() {
    Dog dog1("Max");
    for(int i = 4; i < 9; i++) {
        dog1.sleep();
        dog1.run();
    }
    dog1.eat();
    dog1.bark();
    cout << dog1.getEnergy() << endl;
    return 0;
}
