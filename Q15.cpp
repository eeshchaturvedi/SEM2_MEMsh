#include<iostream>
#include<vector>
#include<string>

using namespace std;

class S3;

class S1 {
 private: // P3 visibility
    vector<string> X;
    vector<string> Y;
    static string MEMsh;
    void f1() { //P3: Private visibility
        cout << "Hello, World" << endl;
    }
    
 protected: // P2 visibility
    virtual void fv2() {
        cout << "fv2() of S1 executed" << endl;
    }
    void apply_rules() // Φ - rules and behaviors
    {
        if(X.empty()) {
            cout << "Rule violation: Input is empty" << endl;
        }
    }

 public: // P1 visibility
    S1() {
        cout << "S1 initialized" << endl;
    }
    ~S1() {
        cout << "S1 destroyed" << endl;
    }
    void setInput(const vector<string> & input) {
        X = input;
    }
    void showOutput() {
        for (auto& y: Y) {
            cout << "Output : " << y << endl;
        }
    }
    static void sharedResources() {
        cout << "Shared memory data : " << MEMsh << endl;
    }

    // controlled access to private f1()
    friend class S3;
};

string S1::MEMsh = "Shared memory";

class S3 {
 public: 
    void usef1() { // uses f1() of P3 visiblity from S1
        S1 obj;
        obj.f1();
        obj.sharedResources();
    }

};

int main() {
    S3 system3;
    system3.usef1(); // S3 using S1's f1()
    return 0;
}