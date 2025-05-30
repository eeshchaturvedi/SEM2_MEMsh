#include<iostream>

using namespace std;

class Bank {
 public:
    virtual double rate_of_interest() {
        return 5.0;
    }
    void Calculate_interest(double principal, double time) {
        double rate = rate_of_interest();
        double interest = (principal*time*rate)/100;
        cout << "Rate of interest : " << rate << endl;
        cout << "Interest : " << interest << endl;
    }
};

class HDFC:public Bank {
 public:
    double rate_of_interest() override {
        return 7.0;
    }
};

class ICICI:public Bank {
 public: 
    double rate_of_interest() override {
        return 8.5;
    }
};

class SBI:public Bank {
 public: 
    double rate_of_interest() override {
        return 9.0;
    }
};

int main() {
    HDFC hdfc;
    ICICI icici;
    SBI sbi;
    Bank* bank;
    bank = &hdfc;
    bank->Calculate_interest(10000, 2);
    bank = &icici;
    bank->Calculate_interest(10000, 2);
    bank = &sbi;
    bank->Calculate_interest(10000, 2);
    return 0;
}