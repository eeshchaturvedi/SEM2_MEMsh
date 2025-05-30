#include<iostream>
using namespace std;

class Rectangle {
 private:
    float width;
    float height;
 public:
    Rectangle() {
        width = 0.0;
        height = 0.0;
    }
    Rectangle(float width, float height) {
        this->width = width;
        this->height = height;
    }
    void area() {
        cout << "Area = " << width*height << " sq.units" << endl;
    }
    ~Rectangle() {}
};

int main() {
    Rectangle r(5.5,6);
    r.area();
    return 0;
}