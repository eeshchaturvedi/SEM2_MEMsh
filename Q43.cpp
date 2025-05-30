#include<iostream>

using namespace std;

class Complex {
 private:
    int real;
    int imaginery;
 public:
    Complex (int real = 0, int imaginery = 0)  {
        this->imaginery = imaginery;
        this->real = real;
    }
    Complex operator++() {
        return(++(this->real), ++(this->imaginery));
    }
    Complex operator++(int) {
        Complex temp;
        temp.real = real++;
        temp.imaginery = imaginery++;
        return temp;
    }
    void display() {
        cout << real << " + " << imaginery << "i" << endl;
    }
    ~Complex() {}
};

int main() {
    Complex c(2,3);
    cout << "Initial number: ";
    c.display();
    ++c;
    cout << "Pre-increment number: ";
    c.display();
    cout << "Post-increment number: ";
    c++.display();
    c.display();
    return 0;
}