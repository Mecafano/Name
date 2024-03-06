#include <iostream>

class Animal {
protected:
    int energy;

public:
    Animal(int initial_energy = 50) : energy(initial_energy) {}

    void sleep() {
        std::cout << "I'm sleeping." << std::endl;
        energy++;
    }

    void eat() {
        std::cout << "I'm eating." << std::endl;
        energy++;
    }

    int getEnergy() const {
        return energy;
    }
};

class Dog : public Animal {
private:
    std::string name;

public:
    Dog(const std::string& dog_name) : name(dog_name) {}

    void bark() {
        std::cout << "Bark!" << std::endl;
        energy--;
    }

    void run() {
        std::cout << "Running!" << std::endl;
        energy -= 3;
    }
};

int main() {
    Dog dog1("Max");

    for (int i = 4; i < 9; i++) {
        dog1.sleep();
        dog1.run();
    }

    dog1.eat();
    dog1.bark();

    std::cout << dog1.getEnergy() << std::endl;

    return 0;
}
