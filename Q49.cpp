#include <iostream>
using namespace std;

// Compile-time Polymorphism using Function Overloading
class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

// Runtime Polymorphism using Virtual Functions
class Animal {
public:
    virtual void makeSound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    // Function Overloading (Compile-time Polymorphism)
    Calculator calc;
    cout << "Add(int, int): " << calc.add(5, 3) << endl;
    cout << "Add(float, float): " << calc.add(2.5f, 3.5f) << endl;
    cout << "Add(int, int, int): " << calc.add(1, 2, 3) << endl;

    cout << "\n--- Runtime Polymorphism ---" << endl;

    // Virtual Function (Runtime Polymorphism)
    Animal* animalPtr;
    Dog d;
    Cat c;

    animalPtr = &d;
    animalPtr->makeSound();  // Dog's version

    animalPtr = &c;
    animalPtr->makeSound();  // Cat's version

    return 0;
}
