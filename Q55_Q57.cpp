#include<iostream>
#include<fstream>

using namespace std;

class S1 {
 private:
    int MyCnt11;
 public:
    static int MyCount12;

    S1() {
        MyCnt11 = 0;
        cout << "MyCnt11 initialised to 0" << endl;
    }

    void input() {
        cout << "Enter non-negative value of MyCount12: ";
        int temp;
        cin >> temp;

        // Φ: Rule check
        if (temp < 0) {
            cout << "ERROR: Value must be non-negative." << endl;
        } else {
            MyCount12 = temp;
        }
    }

    void writeToFile() {
        ofstream file_out("D:\\CPP and OOP\\QB Solutions\\MyTextFile1.txt");
        if (file_out.is_open()) {
            file_out << MyCount12;
            file_out.close();
            cout << "Value " << MyCount12 << " written to file" << endl;
        } else {
            cout << "Unable to open file for writing" << endl;
        }
    }
    
    void readFromFile() {
        ifstream file_in("D:\\CPP and OOP\\QB Solutions\\MyTextFile1.txt");
        if(file_in.is_open()) {
            int value;
            file_in >> value;
            cout << "Value read from file : " << value << endl;
            file_in.close();
        } else {
            cout << "Unable to open file for reading" << endl;
        }
    }

    ~S1() {
        cout << "Destructor called. Releasing resources if any." << endl;
    }
};

int S1::MyCount12 = 0;

int main() {
    S1 obj;
    obj.input();
    obj.writeToFile();
    obj.readFromFile();
    return 0;
}