#include "student.h"
#include "person.h"
#include <iostream>
using namespace std;

student::student():person(){
    ID = 0; enrol = date();
    total_courses = 0;
    for(int i = 0; i < 4; i++){
        courses[i] = course();
    }
}

student::student(string name, date DOB, int id, date E):person(name, DOB){
    ID = id; enrol = E;
    total_courses = 0;
    for(int i = 0; i < 4; i++){
        courses[i] = course();
    }
}

student::student(const student &s):person(s){
    ID = s.ID; enrol = s.enrol; total_courses = s.total_courses;
    for(int i = 0; i < 4; i++){ courses[i] = s.courses[i];}
}

student& student::setID(int ID){ this->ID = ID; return *this;}
student& student::setEnrolDate(date enrol){ this->enrol = enrol; return *this;}

int student::getID() const{ return ID;}
date student::getEnrolDate() const{ return enrol;}
course& student::getCourse(int a) const{ return *courses[a];}


bool student::addCourse(const course& C){
    if (total_courses > 4){ 
        courses[total_courses] = new course(C);
        total_courses++;
        return true; 
        } else {return false;}
}
bool student::dropCourse(const course& C){
    for(int i = 0; i < total_courses; i++){
        if(courses[i] != nullptr && courses[i]->getName() == C.getName()){
            delete courses[i];

            for(int j = i; j < total_courses - 1; j++){
                courses[j] = courses[j+1];
            }
            total_courses--;
            return true;
        }else{return false;}
    }
}
void student::print() const{
    person::print();
    cout << "Enrolment Date : "; getEnrolDate().printDate(); cout << endl;
    cout << getName() << "is enrolled in " << total_courses << " courses :" << endl;
    for(int i = 0; i < total_courses; i++){
        cout << "Course #" << i << " : ";
        courses[i]->print();
        cout << endl;
    }
}
student::~student(){
    for (int i = 0; i < total_courses; i++) {
        if (courses[i] != nullptr) {
            delete courses[i];
            courses[i] = nullptr;
        }
    }
    cout << "Student ID " << ID << " is completely removed from the system." << endl;
}