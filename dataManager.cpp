#include "dataManager.h"
#include "undergraduateStudent.h"
#include "graduateStudent.h"
#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

dataManager::dataManager() : totalStudents{0}, totalProfs{0}{
    for(int i = 0; i < 5000; i++){Students[i] = nullptr;}
    for(int j = 0; j < 100; j++){Profs[j] = nullptr;}
    for(int k = 0; k < 200; k++){Courses[k] = nullptr;} 
}
bool dataManager::addStudent(){
    if(totalStudents >= 5000){return false;}
    string name;
    int DOByear, DOBmonth, DOBday, tdyYear, tdyMonth, tdyDay;
    date DOB, tdy;
    cout << "Enter the Student's information (name, date of birth, enrolment date [today] ) : ";
    cin >> name >> DOByear >> DOBmonth >> DOBday >> tdyYear >> tdyMonth >> tdyDay;
    cout << endl;
    
    char choice;
    cout << "Do you wish to add an Undergraduate student or a Graduate student (U/G) :";
    cin >> choice;
    if(choice == 'U' || choice || 'u'){
        Students[totalStudents] = new undergraduateStudent(name, DOB.setYear(DOByear).setMonth(DOBmonth).setDay(DOBday), 0, tdy.setYear(tdyYear).setMonth(tdyMonth).setDay(tdyDay), date());
        totalStudents++;
        cout << "You have successfully added an undergraduate student to the system!" << endl;
        return true;
    }else if(choice == 'G' || choice == 'g'){
        Students[totalStudents] = new graduateStudent(name, DOB.setYear(DOByear).setMonth(DOBmonth).setDay(DOBday), tdy.setYear(tdyYear).setMonth(tdyMonth).setDay(tdyDay), date(), " ");
        totalStudents++;
        cout << "You have sucessfully added a graduate student to the system! " << endl;
        return true;
    }else{
        cout << "Invalid choice, please try again!" << endl;
        return false;
    }
   
}
bool dataManager::addProf(){
    if(totalProfs >= 100){
        cout << "There are already 100 professors in the system!" << endl;
        return false;}
    string name;
    int DOByear, DOBmonth, DOBday, ID, tdyYear, tdyMonth, tdyDay;
    date DOB, tdy;
    cout << "Enter the professor's information (name, date of birth (YYYY/MM/DD), ID number, employment date (YYYY/MM/DD)) : ";
    cin >> name >> DOByear >> DOBmonth >> DOBday >> ID >> tdyYear >> tdyMonth >> tdyDay;
    cout << endl;

    char choice;
    cout << "Do you wish to add a Part-Time professor or a Full-Time professor (P/F) :";
    cin >> choice;
    if(choice == 'P' || choice == 'p'){
        Profs[totalProfs] = new PartTimeProfessor(name, DOB.setYear(DOByear).setMonth(DOBmonth).setDay(DOBday), ID, tdy.setYear(tdyYear).setMonth(tdyMonth).setDay(tdyDay));
        totalProfs++;
        cout << "You have successfully added a Part time professor to the system! "  << endl;
        return true;
    }else if(choice == 'F' || choice == 'f'){
        Profs[totalProfs] = new FullTimeProfessor(name, DOB.setYear(DOByear).setMonth(DOBmonth).setDay(DOBday), ID, tdy.setYear(tdyYear).setMonth(tdyMonth).setDay(tdyDay));
        totalProfs++;
        cout << "You have successfully added a Full time professor to the system!" << endl;
        return true;
    }
}
bool dataManager::expelStudent(int ID){
    for(int t = 0; t < totalStudents; t++){
        if(Students[t]->getID() == ID){
            delete Students[t];

            for(int y = t; y < totalStudents - 1; y++){
                Students[y] = Students[y+1];
            }
            Students[totalStudents - 1] = nullptr;
            totalStudents--;
            cout << "Student " << ID << " has been successfully expelled from the univerity" << endl;
            return true;
        }
    }
    return false;
}
bool dataManager::newCourse(){
    if(totalCourses >= 200){
        cout << "This university already has 200 courses!" << endl;
        return false;
    }
    string dept, name, profName;
    int number;
    bool validProf {false};
    cout << "Enter the details of the course you would like to add (deoartment, number, name, professor's name)";
    cin >> dept >> number >> name >> profName;
    cout << endl;

    for(int i = 0; i < 100; i++){
        if(profName == Profs[i]->getName()){
            validProf = true;
        }
    }

    if(!validProf){
        cout << "Please enter a valid Professor name" << endl; 
        return false;
    }

    Courses[totalCourses] = new courseRegistration(dept, number, name, profName, 0);
    totalCourses++;
    cout << dept << " " << number << " has been successfully added to the university" << endl;
    return true;
}
bool dataManager::removeCourse(){
    string dept;
    int number;

    cout << "Enter the department and number of the course you wish to remove (ex.: COEN 244)";
    cin >> dept >> number;
    cout << endl;

    for(int k = 0; k < totalCourses; k++){
        if(dept == Courses[k]->getDept() && number == Courses[k]->getNum()){
            delete Courses[k];

            for(int t = k; t < totalCourses - 1; t++){
                Courses[t] = Courses[t+1];
            }
            Courses[totalCourses] = nullptr;
            totalCourses--; 
            cout << "The course has been sucessfully removed!" << endl;
            return true;
        }
    }
    return false;
}
bool dataManager::registerStudent(int ID, const course& selectedCourse){
    for(int s = 0; s < totalStudents; s++){
        if(ID == Students[s]->getID()){
            for(int c = 0; c < totalCourses; c++){
                if(selectedCourse.getDept() == Courses[c]->getDept() && selectedCourse.getNum() == Courses[c]->getNum() && selectedCourse.getName() == Courses[c]->getName() && selectedCourse.getProfName() == Courses[c]->getProfName()){
                    undergraduateStudent *undergrad = dynamic_cast<undergraduateStudent*>(Students[s]);
                    graduateStudent *grad = dynamic_cast<graduateStudent*>(Students[s]);

                    if( undergrad->addCourse(*(Courses[c]))){
                        Courses[c]->addStudent(Students[s]->getID());
                        cout << "You have successfully added " << Courses[c]->getDept() << " " << Courses[c]->getNum() << " to Undergraduate Student #" <<ID <<endl; 
                        return true;
                    }else if(grad->addCourse(*(Courses[c]))){
                        Courses[c]->addStudent(Students[s]->getID());
                        cout << "You have successfully added " << Courses[c]->getDept() << " " << Courses[c]->getNum() << " to Graduate Student #" <<ID <<endl; 
                        return true;
                    }                                            
                
                }
            }
        }
    }
    return false;
}
bool dataManager::unregisterStudent(int ID, const course& selectedCourse){
    for(int s = 0; s < totalStudents; s++){
        if(ID == Students[s]->getID()){
            for(int c = 0; c < totalCourses; c++){
                if(selectedCourse.getDept() == Courses[c]->getDept() && selectedCourse.getNum() == Courses[c]->getNum() && selectedCourse.getName() == Courses[c]->getName() && selectedCourse.getProfName() == Courses[c]->getProfName()){
                    undergraduateStudent *undergrad = dynamic_cast<undergraduateStudent*>(Students[s]);
                    graduateStudent *grad = dynamic_cast<graduateStudent*>(Students[s]);

                    if( undergrad->dropCourse(*(Courses[c])) || grad->dropCourse(*(Courses[c])) ){
                        Courses[c]->removeStudent(Students[s]->getID());
                        return true;
                    }
                }
            }
        }
    }
    return false;
    
}
bool dataManager::searchInCourse(int ID, const course& selectedCourse){
    for(int i = 0; i < totalCourses; i++){
        if(selectedCourse.getDept() == Courses[i]->getDept() && selectedCourse.getNum() == Courses[i]->getNum() && selectedCourse.getName() == Courses[i]->getName() && selectedCourse.getProfName() == Courses[i]->getProfName()){
            for(int j = 0; j < Courses[i]->getMaxSize(); j++){
                if(Courses[i]->getStudentIDs(j) == ID){
                    return true;
                }
            }
        }
    }
    return false;
}
bool dataManager::searchInUni(int ID){
    for(int i = 0; i < 5000; i++){
        if(ID == Students[i]->getID()){
            return true;
        }
    }
    return false;
}
bool dataManager::addSupervisor(){
    int studentID, profID;
    cout << "Enter the graduate student's ID :";
    cin >> studentID;
    cout << endl;
    
    cout <<"Now enter the ID of the full time professor you wish to assign to the student";
    cin >> profID;

    for(int s = 0; s < totalStudents; s++){
        if(studentID == Students[s]->getID()){
            for(int p = 0; p < totalProfs; p++){
                if(profID == Profs[p]->getID()){
                    graduateStudent *grad = dynamic_cast<graduateStudent*>(Students[s]);
                    FullTimeProfessor *FTprof = dynamic_cast<FullTimeProfessor*>(Profs[p]);

                    if(grad == nullptr){
                        cout << "This student is not a Graduate Student!" << endl;
                        return false;
                    }else if(FTprof == nullptr){
                        cout << "This professor is not a Full Time Professor!" << endl;
                        return false;
                    }else if( grad != nullptr && FTprof != nullptr){
                        FTprof->addStudent(*grad);
                        return true;
                    }                

                }
            }
            cout << "Invalid professor ID" << endl;
            return false;
        }
    }
    cout << "Invalid student ID " << endl; 
    return false;
}
bool dataManager::saveStudent(string studentFile, student* Student){
    ofstream outStudentFile(studentFile, ios::app);
        if(!outStudentFile){
            throw runtime_error("File could not be opened");
        }   
    
        undergraduateStudent *undergrad = dynamic_cast<undergraduateStudent*>(Student);
        graduateStudent *grad = dynamic_cast<graduateStudent*>(Student);

        if(undergrad != nullptr){
            outStudentFile << "undergraduate " << *undergrad << endl;
        }else if(grad != nullptr){
            outStudentFile << "graduate " << *grad << endl;
        }else{return false;}

    outStudentFile.close();
    return true;
}
void dataManager::searchStudent(string studentFile, string className, int studentID){
    cout << "Searching for a " << className << " student #" << studentID << " ... " << endl;

    ifstream inStudentFile(studentFile);
        if(!inStudentFile){throw runtime_error("File could not be opened");}

    string studentType, name, sup;
    int ID, DOBm, DOBd, DOBy, ENm, ENd, ENy, GRm, GRd, GRy;
    char slash;
    while(inStudentFile >> studentType >> ID
        >> DOBm >> slash >> DOBd >> slash >> DOBy
        >> ENm >> slash >> ENd >> slash >> ENy
        >> GRm >> slash >> GRd >> slash >> GRy){
            if(studentType == "graduate"){inStudentFile >> sup;}

            if(studentType == className && studentID == ID){
                student* foundStudent = nullptr;
                foundStudent->setID(ID);

                    date DOB = date(DOBd,DOBm,DOBy);
                    date enrol = date(ENd,ENm,ENy);
                    date grad = date(GRd,GRm,GRy);
                    date expectedGrad = enrol;

                if(studentType == "graduate"){
                    foundStudent = new graduateStudent(name, DOB, enrol, grad, sup);
                    foundStudent->getEnrolDate().setYear(enrol.getYear() + 4);
                }else{
                    foundStudent = new undergraduateStudent(name, DOB, enrol, grad);
                    foundStudent->getEnrolDate().setYear(enrol.getYear() + 2);
                }
                
                cout << "Student Found ! :" << endl;
                foundStudent->print();

                if(grad > expectedGrad){
                    cout << "This student has not graduated on time!" << endl;
                }else{
                    cout << "This student has graduated on time!" << endl;
                }


            }
        }
    

}
dataManager::~dataManager(){
    for(int i = 0; i < 5000; i++){delete Students[i]; Students[i] = nullptr;}
    for(int j = 0; j < 100; j++){delete Profs[j]; Profs[j] = nullptr;}
    for(int k = 0; k < 200; k++){delete Courses[k]; Courses[k] = nullptr;}
    cout << "Thank you for using this software system ! :)" << endl;
}