#include <iostream>
#include "Student.h"
//#include "Logger.h"

namespace std {
    int main() {
        Student mike (1, string("Mike"), {85, 90, 99, 80});
        int numGrade = mike.calculateGrade();
        string letGrade = mike.calculateLetterGrade(numGrade);
        cout<<letGrade<<endl;
        /*
         * Logger *studentLogger;
        studentLogger=studentLogger->getInstance();
        studentLogger->log(letGrade);
         */
    return 0;
    }
}
