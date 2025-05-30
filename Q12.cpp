#include <iostream>
using namespace std;

class B; // Forward declaration

class A {
private:
    int a;
    friend class B;  // B can access A's private member
public:
    A(int a = 0) {
        this->a = a;
    }
    void display() const {
        cout << "a = " << a << endl;
    }
};

class B {
private:
    int b;
public:
    B(int b = 0) {
        this->b = b;
    }

    void display() const {
        cout << "b = " << b << endl;
    }

    void swap_values(A& obj) {
        int temp = obj.a;
        obj.a = b;
        b = temp;
    }
};

int main() {
    A aa(5);
    B bb(10);

    cout << "Before swapping:" << endl;
    aa.display();  // a = 5
    bb.display();  // b = 10

    bb.swap_values(aa);  // B swaps its value with A's

    cout << "After swapping:" << endl;
    aa.display();  // a = 10
    bb.display();  // b = 5

    return 0;
}
