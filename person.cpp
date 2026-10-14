#include "person.h"
#include <iostream>
using namespace std;

person::person(){
    name = " "; DOB = date();
}
person::person(string N, date dob){
    name = N; DOB = dob;
}
person::person(const person &p){
    name = p.name; DOB = p.DOB;
}

person& person::setName(string name){ this->name = name; return *this;}
person& person::setDOB(date DOB){ this->DOB = DOB; return *this;}

string person::getName() const{ return name;}
date person::getDOB() const{ return DOB;}
void person::print() const{
    cout << "Name : " << getName() << endl;
    cout << "Date of Birth : "; getDOB().printDate(); cout << endl;
}

person::~person(){
    cout << name << " is no longer in the system" << endl;
}