#include "professor.h"
#include <iostream>

using namespace std;

professor::professor(string name, date dob, int id, date empDate) 
    : person(name, dob), id(id), empDate(empDate) {
}

int professor::getID() const {
    return id;
}

date professor::getEmpDate() const {
    return empDate;
}

void professor::print() {
    person::print(); 
    cout << "Professor ID: " << id << endl;
}

professor::~professor() {
    cout << "Professor object deleted." << endl;
}