#ifndef COURSEREGISTRATION_H
#define COURSEREGISTRATION_H
#include <iostream>
#include "course.h"
#include "student.h"
using namespace std;

class courseRegistration : public course{
private:
    static const int maxSize = 150;
    int total_students;
    int studentIDs[maxSize];

public:
    courseRegistration();
    courseRegistration(string, int, string, string, int);
    courseRegistration(const courseRegistration&);

    courseRegistration& setTotalStudents(int);
    int getMaxSize() const;
    int getTotalStudents() const;
    int getStudentIDs(int) const;

    bool addStudent(int);
    bool removeStudent(int);

    virtual void print() const override;

    virtual ~courseRegistration() override;
};
#endif