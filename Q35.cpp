#include <iostream>
using namespace std;

class Demo {
private:
    int a;                  // Non-static member
    static int b;           // Static member

public:
    // Constructor to initialize a and optionally modify b
    Demo(int valA) {
        a = valA;
        b++; // Increment static member for each object
    }

    // Member function to display a and b
    void show() {
        cout << "Non-static a = " << a << ", Static b = " << b << endl;
    }

    // Static member function to display static member only
    static void display() {
        cout << "Static b (from static function) = " << b << endl;
    }
};

// Initialize static member outside the class
int Demo::b = 0;

int main() {
    Demo d1(10);
    d1.show();           // a = 10, b = 1
    Demo::display();     // b = 1

    Demo d2(20);
    d2.show();           // a = 20, b = 2
    Demo::display();     // b = 2

    Demo d3(30);
    d3.show();           // a = 30, b = 3
    d3.display();        // b = 3 (can also be called via object)

    return 0;
}
