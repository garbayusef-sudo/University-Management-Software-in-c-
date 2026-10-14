#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include <iostream>
#include <string>
#include "courseRegistration.h"
#include "PartTimeProfessor.h"
#include "FullTimeProfessor.h"

using namespace std;

class dataManager {
private:
    int totalStudents;
    int totalProfs;
    int totalCourses;
    
    //Arrays of base class pointers
    student *Students[5000];
    professor *Profs[100];
    courseRegistration *Courses[200];

public:
    dataManager();
    
    bool addStudent();
    bool addProf();
    bool expelStudent(int);
    bool newCourse();
    bool removeCourse();
    bool registerStudent(int, const course&);
    bool unregisterStudent(int, const course&);
    bool searchInCourse(int, const course&);
    bool addSupervisor();
    student* searchInUni(int); 

    //File Processing
    bool saveStudent(string studentFile, student* Student);
    void searchStudent(string studentFile, string className, int student_id);

    ~dataManager();    
};

#endif