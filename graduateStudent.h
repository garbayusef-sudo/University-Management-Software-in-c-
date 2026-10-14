#include "graduateStudent.h"
#include <iostream>

using namespace std;

graduateStudent::graduateStudent(string name, date dob, date enrolDate, date expectedGradDate, string sup)
    : student(name, dob, enrolDate, expectedGradDate), supervisor(sup) {
}

string graduateStudent::getSup() const {
    return supervisor;
}

void graduateStudent::setSup(string sup) {
    supervisor = sup;
}

bool graduateStudent::addCourse(const course& selectedCourse) {
    if (courseCount < 2) { 
        registeredCourses[courseCount] = selectedCourse;
        courseCount++;
        return true;
    }
    
    cout << "Registration Failed: Maximum course limit reached for this student." << endl;
    return false;
}

bool graduateStudent::dropCourse(const course& selectedCourse) {
    for (int i = 0; i < courseCount; i++) {
        if (registeredCourses[i].getCourseNumber() == selectedCourse.getCourseNumber()) {
            
            for (int j = i; j < courseCount - 1; j++) {
                registeredCourses[j] = registeredCourses[j + 1];
            }
            
            courseCount--;
            return true;
        }
    }
    
    cout << "Drop Failed: Course not found in the student's schedule." << endl;
    return false;
}

void graduateStudent::print() {
    student::print();     
    cout << "Status: Graduate Student | Supervisor: " << supervisor << endl;
}


graduateStudent::~graduateStudent() {
    cout << "GraduateStudent object deleted." << endl;
}

ostream& operator<<(ostream& os, const graduateStudent& gs) {
    os << gs.getID() << " " 
       << gs.getDOB().getMonth() << "/" << gs.getDOB().getDay() << "/" << gs.getDOB().getYear() << " "
       << gs.getEnrolDate().getMonth() << "/" << gs.getEnrolDate().getDay() << "/" << gs.getEnrolDate().getYear() << " "
       << gs.getExpectedGradDate().getMonth() << "/" << gs.getExpectedGradDate().getDay() << "/" << gs.getExpectedGradDate().getYear() << " "
       << gs.supervisor;
       
    return os;
}