#include<iostream>

using namespace std;

class Complex {
 private:
    int real;
    int imaginery;
 public:
    Complex(int real = 0, int imaginery = 0) {
        this->real = real;
        this->imaginery = imaginery;
    }
    Complex operator+(Complex& num) {
        Complex temp;
        real = this->real + num.real;
        imaginery = this->imaginery + num.imaginery;
        return Complex(real, imaginery);
    }
    void display() {
        cout << real << " + " << imaginery << "i" << endl;
    }
    ~Complex() {}
};

int main() {
    Complex n1(4,5), n2(9,1), n3;
    n3 = n1 + n2;
    n3.display();
    return 0;
}