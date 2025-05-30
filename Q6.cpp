#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Person {
 protected:
    string name;
    int age;
 public:
    Person (int age = 0, string name = "None") {
        this->age = age;
        this->name = name;
    }
};

class Student:public Person {
 private:
    int student_ID;
 public:
    Student(int age = 0, int student_ID = 0, string name = "None") {
        this->age = age;
        this->student_ID = student_ID;
        this->name = name;
    }
    void display() {
        cout << student_ID << " " << name << " | age: " << age << " years" << endl; 
    }
};

int main() {
    Student s(20, 11304, "Smit Bangar");
    s.display();
    return 0;
}