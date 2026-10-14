#ifndef UNDERGRADUATESTUDENT_H
#define UNDERGRADUATESTUDENT_H

#include "student.h"
#include "course.h"
#include "date.h"
#include <string>
#include <iostream>

class undergraduateStudent : public student {
public:
    undergraduateStudent(std::string name, date dob, date enrolDate, date expectedGradDate);
    undergraduateStudent(std::string name, date dob, int id, date enrolDate, date expectedGradDate); 

    bool addCourse(const course& selectedCourse);
    bool dropCourse(const course& selectedCourse);

    friend std::ostream& operator<<(std::ostream& os, const undergraduateStudent& ug);
    void print();

    ~undergraduateStudent();

};
#endif