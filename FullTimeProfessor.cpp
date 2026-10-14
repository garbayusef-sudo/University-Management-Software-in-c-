#include "PartTimeProfessor.h"
#include <iostream>

using namespace std;

PartTimeProfessor::PartTimeProfessor(string name, date dob, int id, date empDate)
    : professor(name, dob, id, empDate) {
}

void PartTimeProfessor::print() {
    professor::print();
    cout << "Status: Part-Time" << endl;
}

PartTimeProfessor::~PartTimeProfessor() {
    cout << "PartTimeProfessor object deleted." << endl;
}