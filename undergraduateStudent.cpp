#include "undergraduateStudent.h"
#include <iostream>
using namespace std;

undergraduateStudent::undergraduateStudent():student(){
    courses = new course[4];
}
undergraduateStudent::undergraduateStudent(string name, date DOB, int total_courses, date enrol):student(name, DOB, total_courses, enrol){
    courses = new course[4];
}
undergraduateStudent::undergraduateStudent(const undergraduateStudent& U)
    : student(U)
{
    courses = new course[4];
    for(int i = 0; i < 4; i++){
        courses[i] = U.courses[i];
    }
}