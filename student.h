#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "person.h"
#include "date.h"
#include "course.h"
using namespace std;

class student : public person{
private:
    int ID;
    date enrol;
    int total_courses {0};
    course *courses[4] = {nullptr, nullptr, nullptr, nullptr}; 

public:
    student();
    student(string, date, int, date);
    student(const student&);
    student& setID(int);
    student& setEnrolDate(date);

    int getID() const;
    date getEnrolDate() const;
    course& getCourse(int) const;

    void print() const;
    bool addCourse(const course&);
    bool dropCourse(const course&);

    ~student();

};
#endif