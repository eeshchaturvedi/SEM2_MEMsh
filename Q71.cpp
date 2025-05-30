#include<iostream>
#include<fstream>

using namespace std;

class Attendance {
    
 private:
    int Student_ID;
    string name;
    int daysPresnt;

 public:
    void input() {
        cout << "Enter ID: ";
        cin >> Student_ID;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter no. of days present: ";
        cin >> daysPresnt;
    }

    void write_to_file(ofstream &out) const {
        out << Student_ID << '\n' << name << '\n' << daysPresnt << '\n';
    }

    void display() {
        cout << "Student ID: " << Student_ID << " | Name : " << name
        << " | Days present: " << daysPresnt << endl;
    }

    void read_from_file(ifstream &in) {
        in >> Student_ID;
        in.ignore();
        getline(in, name);
        in >> daysPresnt;
        if(daysPresnt < 75) {
            display();
        }
    }
};

int main() {
    const string& file_name = "attendance.txt";
    Attendance record[3];
    ofstream file(file_name);
    for (size_t i = 0; i < 3; i++)
    {
        record[i].input();
        record[i].write_to_file(file);
    }

    
    ifstream file_in(file_name);
    if (!file_in) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }
    
    cout << "__________Defaulters record__________" << endl;
    for (size_t i = 0; i < 3; i++)
    {
        record[i].read_from_file(file_in);
    }
    return 0;
}