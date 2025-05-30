#include<iostream>

using namespace std;


class Complex {
 private:
    float real;
    float imaginery;
 public:
    Complex (float real = 0.0, float imaginery = 0.0)  {
        this->imaginery = imaginery;
        this->real = real;
    }
    inline Complex add(const Complex& c) {
        return Complex(real + c.real, imaginery + c.imaginery);
    }
    inline Complex subtract(const Complex& c) {
        return Complex(real - c.real, imaginery - c.imaginery);
    }
    inline void display() {
        cout << real << " + " << imaginery << "i" << endl;
    }
    ~Complex() {}
};

int main() {
    Complex num1(4.5, 6.2), num2(3.1, 5.5), ans;
    ans = num1.add(num2);
    ans.display();
    ans = num1.subtract(num2);
    ans.display();
    return 0;
}