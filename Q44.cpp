#include<iostream>

using namespace std;

class Instrument {
 public: 
    virtual void MakeSound() {

    }
};

class Guitar:public Instrument {
 public:
    void MakeSound() override {
        cout << "Playing guitar.. " << endl;
    }
};

class Violin:public Instrument {
 public:
    void MakeSound() override {
        cout << "Playing violin.. " << endl;
    }
};

class Flute:public Instrument {
 public:
    void MakeSound() override {
        cout << "Playing flute.. " << endl;
    }
};

int main() {
    Guitar guitar;
    Violin violin;
    Flute flute;

    Instrument* ptr;
    ptr = &guitar;

    ptr->MakeSound();
    ptr = &violin;
    ptr->MakeSound();
    ptr = &flute;
    ptr->MakeSound();

    return 0;
}