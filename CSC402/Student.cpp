//
// Created by theniceninja on 9/8/16.
//

#include "Student.h"

using namespace std;

Student::Student(int i, string n, vector<int> m) {
    id = i;
    name = n;
    marks = m;
}
//destructor
Student::~Student() {

}
//copy constructor
Student::Student (const Student & rhs) {
    name = rhs.name;
    marks = rhs.marks;
}
//operator= override
const Student& Student::operator=(const Student & rhs) {
    if (id != rhs.getId()) {
        id = rhs.getId();
        name = rhs.name;
        marks = rhs.marks;
    }
    return *this;
}

int Student::calculateGrade() const{
    int total=0;
    int grade;
    for (int i = 0; i < marks.size(); i++) {
        total += marks.at(i);
    }
    grade = total/marks.size();
    return grade;
}
string Student::calculateLetterGrade(const int grade) const{
    if (grade < 60) {return "F";}
    else if (grade <= 67) {return "D";}
    else if (grade <= 70) {return "D+";}
    else if (grade <= 73) {return "C-";}
    else if (grade <= 77) {return "C";}
    else if (grade <= 80) {return "C+";}
    else if (grade <= 83) {return "B-";}
    else if (grade <= 87) {return "B";}
    else if (grade <= 90) {return "B+";}
    else if (grade <= 93) {return "A-";}
    else if (grade <= 97) {return "A";}
    else return "A+";
}
//setters & getters: id should not be able to be reset.
void Student::setName(string newName)  {
    name = newName;
}
void Student::setMarks(vector<int> newMarks) {
    marks = newMarks;
}
string Student::getName() const {
    return name;
}
vector<int> Student::getMarks() const {
    return marks;
}
int Student::getId() const {
    return id;
}
void Student::logStudent(const Student studentOut) {
    //create the logger pointer
    Logger *studentLogger;
    //get the instance
    studentLogger=&studentLogger->getInstance();
    //make some string variables to construct the string
    int grade = studentOut.calculateGrade();
    string letGrade = studentOut.calculateLetterGrade(grade);
    string name = studentOut.getName();
    //using stringstream to change ints to strings


    ostringstream ss1;
    ss1 << id;
    string idStr = ss1.str();
    ostringstream ss2;
    ss2 << grade;
    string aveGrade = ss2.str();

    studentLogger->log("Student name: " + name + "\nid: " + idStr + "\nAverage grade: " + aveGrade + "\nLetter grade: " + letGrade);
}



