#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Employee {
 private:
    int id;
    string name;
    float salary;

 public:
    void input() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore(); // clear newline from buffer
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: $" << salary << endl;
    }

    // Write employee data to file
    void write_to_file(ofstream &out) const {
        out << id << '\n' << name << '\n' << salary << '\n';
    }

    // Read employee data from file
    void read_from_file(ifstream &in) {
        in >> id;
        in.ignore(); // ignore newline before reading name
        getline(in, name);
        in >> salary;
    }
};

int main() {
    const string filename = "employees.txt";
    const int num = 3;  // Number of employees

    Employee emp[num];

    // ----------- Writing to File ------------
    ofstream fout(filename);
    if (!fout) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    cout << "Enter details of " << num << " employees:\n";
    for (int i = 0; i < num; ++i) {
        cout << "\nEmployee " << i + 1 << ":\n";
        emp[i].input();
        emp[i].write_to_file(fout);
    }
    fout.close();

    // ----------- Reading from File ------------
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }

    cout << "\nEmployee data read from file:\n";
    for (int i = 0; i < num; ++i) {
        emp[i].read_from_file(fin);
        emp[i].display();
    }
    fin.close();

    return 0;
}
