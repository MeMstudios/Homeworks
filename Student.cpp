//
// Created by theniceninja on 9/8/16.
//

#include "Student.h"
namespace std {
    class Student {
    public:
        string name;
        vector<int> marks;

        Student(int i, string n, vector<int> m) {
            id = i;
            name = n;
            marks = m;
        }
        //destructor
        ~Student() {
            delete name;
            delete marks;
        }
        //copy constructor
        Student (const Student & rhs) {
            id = rhs.getId();
            name = rhs.name;
            marks = rhs.marks;
        }
        //operator= override
        const Student & operator=(const Student & rhs) {
            if (id != rhs.getId()) {
                id = rhs.getId();
                name = rhs.name;
                marks = rhs.marks;
            }
            return *this;
        }

        int calculateGrade() {
            int grade=0;
            for (int i = 0; i < marks.size(); i++) {
                grade += marks.at(i);
            }
            return grade;
        }
        string calculateLetterGrade(const int grade);   //would like to just pass in the result of calculateGrade to get the letter grade
        void setName(string newName)  {//setters & getters: id should not be able to be reset.
            name = newName;
        }
        void setMarks(vector<int> newMarks) {
            marks = newMarks;
        }
        string getName() const {
            return name;
        }
        vector<int> getMarks() const {
            return marks;
        }
        int getId() const {
            return id;
        }
    private:
        int id;

    };
}