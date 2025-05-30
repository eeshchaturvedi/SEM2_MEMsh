#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

// Abstract class S
class S {
protected:
    vector<string> X;    // Input elements
    vector<string> Y;    // Output elements
    static string MEMsh; // Shared memory (symbolic)
public:
    S() {  // Constructor
        cout << "System S initialized.\n";
    }

    virtual ~S() {       // Destructor
        cout << "System S destroyed.\n";
    }

    // Rule function (Φ): Check input validity
    virtual void applyRules() {
        for (string &input : X) {
            if (input.empty()) {
                throw invalid_argument("Error: Input X contains empty element.");
            }
        }
    }

    // Member function f1
    virtual void f1() {
        cout << "Executing f1(): Processing Input...\n";
        Y.clear();
        for (auto &input : X) {
            Y.push_back("Processed_" + input);
        }
    }

    // Pure virtual function fv2() => Makes S abstract
    virtual void fv2() = 0;

    void setInput(const vector<string> &inputs) {
        X = inputs;
    }

    void getOutput() const {
        cout << "Output Elements (Y):\n";
        for (const auto &y : Y) {
            cout << y << endl;
        }
    }

    static void accessSharedMemory() {
        cout << "Shared Memory: " << MEMsh << endl;
    }

    static void writeSharedMemory(const string &data) {
        MEMsh = data;
    }
};

// Define static member
string S::MEMsh = "InitialSharedMemory";

// Derived class implementing fv2()
class DerivedS : public S {
public:
    void fv2() override {
        cout << "fv2() called: Implemented in derived class.\n";
    }
};

int main() {
    try {
        S* system = new DerivedS();  // s: Constructor called
        system->setInput({"LoginRequest", "DataFetch"});  // X

        system->applyRules();  // Φ
        system->f1();          // f1()
        system->fv2();         // fv2()
        system->getOutput();   // Y

        // Shared memory usage
        system->writeSharedMemory("SessionToken#123");
        system->accessSharedMemory();

        delete system;  // e: Destructor called
    }
    catch (exception &ex) {
        cerr << "Exception Caught: " << ex.what() << endl;
    }

    return 0;
}
