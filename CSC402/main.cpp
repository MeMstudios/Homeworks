

#include "Student.h"


using namespace std;

int main() {
    //init one student named Mike
    Student stu (1, "Mike", {60, 60, 70, 80});
    //print out the log of this student
    stu.logStudent(stu);
    //set his name to Dick
    stu.setName("Dick");
    //change his grades
    stu.setMarks({95, 90, 99, 100, 98});
    //see the effects of the changes in the log
    stu.logStudent(stu);
    //create a new student named Sally
    Student stu2 (24, "Sally", {99, 99 ,99 ,99});
    //Try out the operator= and set them the same
    stu = stu2;
    //see stu is now the same as stu2
    stu.logStudent(stu);
    //try the copy constructor
    Student stu3 (stu);
    //now all three of them are Sally
    stu.logStudent(stu3);
    return 0;
}

