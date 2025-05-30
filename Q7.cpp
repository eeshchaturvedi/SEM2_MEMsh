#include<iostream>
#include<vector>

using namespace std;

class Student {
 protected:
    int roll_no;
 public:
    Student(int roll_no = 0) {
        this->roll_no = roll_no;
    }
    int get_roll_no() const {
        return roll_no;
    }
    void put_roll_no() {
        cout << "Enter roll no. : ";
        cin >> roll_no;
    }
};

class Test:public virtual Student {
 protected:
    vector<int> Test_marks;
 public:
    Test(int Test1_marks = 0, int Test2_marks = 0) {
        Test_marks = vector<int>(2);
        this->Test_marks[0] = Test1_marks;
        this->Test_marks[1] = Test2_marks;
    }
    vector<int> get_marks() const {
        return Test_marks;
    }
    void put_marks() {
        cout << "Enter marks for Test1: " ;
        cin >> Test_marks[0];
        cout << "Enter marks for Test2: " ;
        cin >> Test_marks[1];
    }
};

class Sports:public virtual Student {
 protected:
    int score;
 public:
    Sports(int score = 0){
        this->score = score;
    }
    int get_score() const {
        return score;
    }
    void put_score() {
        cout << "Enter score: ";
        cin >> score;
    }
};

class Result:public Test, public Sports {
 public: 
    void put_details() {
        put_marks();
        put_score();
    }
    void Display() {
        int total = 0;
        vector<int> marks = get_marks();
        for(int i = 0; i < marks.size(); i++) {
            total += marks[i];
        }
        total += get_score();
         
        cout << "Roll no.: " << roll_no << " | " << "Result: " << total << endl;
    }

};

int main() {
    Result stu;
    stu.put_roll_no();
    stu.put_marks();
    stu.put_score();
    stu.Display();
    return 0;
}