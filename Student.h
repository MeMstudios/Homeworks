//
// Created by theniceninja on 9/8/16.
//

#ifndef SINGLETON_STUDENT_H
#define SINGLETON_STUDENT_H

#include <vector>
#include <string>
namespace std {
    class Student {
    public:
        string * name;
        vector<int>  marks;

        Student(int i, string n, vector<int> m);
        //destructor
        ~Student() ;
        //copy constructor
        Student (const Student & rhs);
        //operator= override
        const Student & operator=(const Student & rhs);

        int calculateGrade();
        string calculateLetterGrade(const int grade);
        void setName(string *newName);
        void setMarks(vector<int> newMarks);
        string* getName() const;
        vector<int> getMarks() const;
        int getId() const ;
    private:
        int id;

    };
}


#endif //SINGLETON_STUDENT_H
