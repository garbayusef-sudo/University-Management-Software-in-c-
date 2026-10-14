#include "courseRegistration.h"
#include "student.h"
#include <iostream>
using namespace std;

courseRegistration::courseRegistration():course(),total_students{0}{
    studentIDs = new int[maxSize];
    for (int i = 0; i < maxSize; i++){
        studentIDs[i] = 0;
    }
}
courseRegistration::courseRegistration(string dept, int number, string name, int totStudents):course(dept, number, name){
    total_students = totStudents;
    studentIDs = new int[maxSize];
    for (int i = 0; i < maxSize; i++){
        studentIDs[i] = 0;
    }
}
courseRegistration::courseRegistration(const courseRegistration& R):course(R){
    total_students = R.total_students; studentIDs = new int[maxSize];
    for (int i = 0; i < maxSize; i++){
        studentIDs[i] = R.studentIDs[i];
    }
}

courseRegistration& courseRegistration::setTotalStudents(int total_students){
    this->total_students = total_students; return *this;
}

int courseRegistration::getMaxSize()const{return maxSize;}
int courseRegistration::getTotalStudents() const{return total_students;}
int courseRegistration::getStudentIDs(int s) const{return studentIDs[s];}

bool courseRegistration::addStudent(int studentID){
    if (total_students < maxSize) {
        for (int i = 0; i < maxSize; i++) {
            if (studentIDs[i] == 0) {
                studentIDs[i] = studentID;
                total_students++;
                return true; 
            }
        }
    }
    return false;
}
bool courseRegistration::removeStudent(int studentID){
for (int i = 0; i < maxSize; i++) {
        if (studentIDs[i] == studentID) {
            studentIDs[i] = 0; 
            total_students--;
            
            for (int j = i; j < maxSize - 1; j++) {
                studentIDs[j] = studentIDs[j + 1];
            }
            studentIDs[maxSize - 1] = 0; 
            
            return true;
        }
    }
    return false;
}

void courseRegistration::print() const{
    cout << "Total students : " << getTotalStudents() << "/" << getMaxSize() << endl;
    if(total_students >= 1){
        for(int i = 0; i < maxSize; i++){
            cout << "Student #" << i << " : " << studentIDs[i] << endl;
        }   
    }
    
}

courseRegistration::~courseRegistration(){
    delete[] studentIDs;
    course::print(); cout << " is no longer available for registration!" << endl;
}