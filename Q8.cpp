#include<iostream>
#include<string>

using namespace std;

class Report;

class Student {
 private:
    string name;
    int marks;
    friend class Report;
 public: 
    Student(string name = "None", int marks = 0) {
        this->name = name;
        this->marks = marks;
    }
};

class Report {
 public: 
    void display(Student st) {
        cout << "Name: " << st.name << " | " << "Marks: " << st.marks << endl;
    }
};

int main() {
    Student st("smit Bangar", 100);
    Report st_report;
    st_report.display(st);
    return 0;
}