#include <iostream>
#include <string>
#include <exception>
#include "dataManager.h"
#include "course.h"
#include "undergraduateStudent.h"
#include "graduateStudent.h"
using namespace std;

int main() {
    dataManager* manager = new dataManager();
    int choice = 0;
    cout << "Welcome to our univerity management system\nThis university holds a maximum of 5 000 students, 100 professors and 200 courses\nHow would you like to get started ?" << endl;
    do {
        cout << " MENU " << endl;
        cout << "1. Admit a new Student (Undergraduate / Graduate)" << endl;
        cout << "2. Onboard a new Faculty Member (Full-Time / Part-Time)" << endl;
        cout << "3. Expel an active Student" << endl;
        cout << "4. Add a new Course to the University catalog" << endl;
        cout << "5. Remove a Course from the University catalog" << endl;
        cout << "6. Register a Student for a specific Course" << endl;
        cout << "7. Unregister a Student from a specific Course" << endl;
        cout << "8. Search for a Student within a Course roster" << endl;
        cout << "9. Search if a Student is active in the University" << endl;
        cout << "10. Assign a Faculty Supervisor to a Graduate Student" << endl;

        cout << "11. Save students to a text file" << endl;
        cout << "12. Search for students in a text file" << endl;
        
        cout << "13. Exit System" << endl;
        cout << "Enter your choice (1-13): ";
        
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                manager->addStudent();
                break;
                
            case 2:
                manager->addProf();
                break;
                
            case 3: {
                int id;
                cout << "Enter the ID of the student to expel: ";
                cin >> id;
                manager->expelStudent(id);
                break;
            }
            
            case 4:
                manager->newCourse();
                break;
                
            case 5:
                manager->removeCourse();
                break;
                
            case 6: {
                int id, cNum;
                string cDept;
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Course Department and Number (e.g., COEN 244): ";
                cin >> cDept >> cNum;

                course tempCourse(cDept, cNum, "", ""); 
                manager->registerStudent(id, tempCourse);
                break;
            }
            
            case 7: {
                int id, cNum;
                string cDept;
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Course Department and Number (e.g., COEN 244): ";
                cin >> cDept >> cNum;

                course tempCourse(cDept, cNum, "", ""); 
                manager->unregisterStudent(id, tempCourse);
                break;
            }
            
            case 8: {
                int id, cNum;
                string cDept;
                cout << "Enter Student ID to check: ";
                cin >> id;
                cout << "Enter Course Department and Number (e.g., COEN 244): ";
                cin >> cDept >> cNum;

                course tempCourse(cDept, cNum, "", ""); 
                if (manager->searchInCourse(id, tempCourse)) {
                    cout << "--> VERIFIED: Student #" << id << " IS enrolled in " << cDept << " " << cNum << "." << endl;
                } else {
                    cout << "--> NOT FOUND: Student #" << id << " is NOT enrolled in " << cDept << " " << cNum << "." << endl;
                }
                break;
            }
            
            case 9: {
                int id;
                cout << "Enter Student ID to search: ";
                cin >> id;
                if (manager->searchInUni(id) != nullptr) {
                    cout << "Student Found!" << endl;
                } else {
                    cout << "Student NOT Found !" << endl;
                }
                break;
            }
            
            case 10:
                manager->addSupervisor();
                break;
                
            case 11: {
                int ID;
                string name;
                cout << "Enter the ID of the existing student you wish to add to the file :";
                cin >> ID;
                cout << endl;

                if(manager->searchInUni(ID) != nullptr){
                    string studentFile;
                    cout << "Enter the text file to write into (ex.: 'students.txt') :";
                    cin >> studentFile;
                    cout << endl;

                    try{
                        manager->saveStudent(studentFile, manager->searchInUni(ID));
                    }
                    catch(const exception& e){
                        if(e.what() == "File could not be opened"){
                            cerr << "Terminating system ..." << endl;
                            delete manager;
                            return 1;
                        }
                    }
                    
                }              
                break;
            }
            case 12: {
                string studentFile, className;
                int studentID;
                cout << "Enter the text file searching through";
                cin >> studentFile; cout << endl;
                cout << "Enter the student type (undergraduate/graduate) and ID of the student that you are looking for ";
                cin >> className >> studentID; cout << endl;

                try{
                    manager->searchStudent(studentFile, className, studentID);
                }catch(const exception& e){
                    if(e.what() == "File could not be opened"){
                        cerr << "Terminating system ..." << endl;
                        delete manager;
                        return 1;
                    }
                }
                break;
            }

            case 13:
                cout << "Exiting system ..." << endl;
                break;
                
            default:
                cout << "Invalid selection! Please input a valid option number (1-11)." << endl;
                break;
        }

    } while (choice != 13);

    delete manager; 
    
    return 0;
}