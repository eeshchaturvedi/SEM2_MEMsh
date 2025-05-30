#include<iostream>

using namespace std;

class A {
  protected:
    int a;
 public:
    A(int a = 0) {
        this->a = a;
    }
    void display() {
        cout << "a = " << a << endl;
    }
    ~A() {}
};

class B {
 protected:
    int b;
 public:
    B(int b = 0) {
        this->b = b;
    }
    void print() {
        cout << "b = " << b << endl;
    }
    ~B() {}
};

class C {
 public:
    int c;
    C(int c = 0) { this->c = c; }
    void show() {
        cout << "c = " << c << endl;
    }
    ~C() {}
};

int main() {
    A a(4);
    B b(5);
    C c(6);
    a.display();
    b.print();
    c.show();
    return 0;
}