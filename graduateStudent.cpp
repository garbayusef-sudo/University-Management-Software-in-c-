#include "graduateStudent.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, const graduateStudent& grad){
    out << grad.getName() << " "
        << grad.getDOB().getMonth() << "/" << grad.getDOB().getDay() << "/" << grad.getDOB().getYear() << " "
        << grad.getGradDate().getMonth() << "/" << grad.getGradDate().getDay() << "/" << grad.getGradDate().getYear() << " "
        << grad.getSup();
    return out;
}
graduateStudent::graduateStudent() : student(){
    total_courses = 0;
    for(int i = 0; i < 2; i++){
        courses[i] = nullptr;
    }
}
graduateStudent::graduateStudent(string name, date DOB,date enrol, string sup) : student(name, DOB, enrol){
    total_courses = 0;
    sup = " ";
    for(int i = 0; i < 2; i++){
        courses[i] = nullptr;
    }
}
graduateStudent::graduateStudent(const graduateStudent& U) : student(U){
    total_courses = U.total_courses;
    for(int i = 0; i < 2; i++){
        courses[i] = U.courses[i];
    }
}
void graduateStudent::setSup(string sup){ supervisor = sup;}
string graduateStudent::getSup() const{return supervisor;}
bool graduateStudent::addCourse(const course& C){
    if (total_courses < 2){ 
        courses[total_courses] = new course(C);
        total_courses++;
        return true; 
        }
    cout << "This graduate student already has 2 courses!" << endl;
    return false;
}
bool graduateStudent::dropCourse(const course& C){
    for(int i = 0; i < total_courses; i++){
        if(courses[i] != nullptr && courses[i]->getName() == C.getName()){
            delete courses[i];

            for(int j = i; j < total_courses - 1; j++){
                courses[j] = courses[j+1];
            }
            courses[total_courses - 1] = nullptr;
            total_courses--;
            return true;
        }
    }
    return false;
}
void graduateStudent::print() const{
    student::print();
    cout << "Enrolment Date : "; getEnrolDate().printDate(); cout << endl;
    cout << "This graduate student is enrolled in " << total_courses << " courses :" << endl;
    for(int i = 0; i < total_courses; i++){
        cout << "Course #" << i+1 << " : ";
        courses[i]->print();
        cout << endl;
    }
}
graduateStudent::~graduateStudent(){
    for (int i = 0; i < total_courses; i++) {
        if (courses[i] != nullptr) {
            delete courses[i];
            courses[i] = nullptr;
        }
    }
    cout << "Graduate student " << getID() << " is no longer in the system " << endl;
}