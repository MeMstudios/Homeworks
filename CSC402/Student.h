//
// Created by theniceninja on 9/8/16.
//

#ifndef SINGLETON_STUDENT_H
#define SINGLETON_STUDENT_H

#include <vector>
#include <string>
#include <sstream>
#include "Logger.h"

using namespace std;
class Student {
public:
    string name;
    vector<int>  marks;

    Student(int i, string n, vector<int> m);
    //destructor
    ~Student() ;
    //copy constructor
    Student (const Student &rhs);
    //operator= override
    const Student & operator=(const Student &rhs);
    int calculateGrade() const;
    string calculateLetterGrade(const int grade) const;
    void setName(string newName);
    void setMarks(vector<int> newMarks);
    string getName() const;
    vector<int> getMarks() const;
    int getId() const ;
    //logger method
    void logStudent(const Student & studentOut);
private:
    int id;

    void littleLog(const string out)const;
};



#endif //SINGLETON_STUDENT_H
