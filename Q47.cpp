#include<iostream>

using namespace std;

class MyBaseClassBirds {
 private:
 public:
    static int MyBirdsHungryCnt;
    MyBaseClassBirds() {
        MyBirdsHungryCnt++;
        cout << "MyBirdsHungryCnt= " << MyBirdsHungryCnt << endl;
    }
    ~MyBaseClassBirds() {}
};

int MyBaseClassBirds::MyBirdsHungryCnt = 0; // MEMsh

int main() {
    MyBaseClassBirds ObjectMyBaseClassBirds, ObjectMyBaseClassBirds1, ObjectMyBaseClassBirds2;
    return 0;
}