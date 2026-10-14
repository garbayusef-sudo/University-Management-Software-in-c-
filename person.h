#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include <iostream>
using namespace std;


class person{

private:
    string name;
    date DOB;

public:
    person();
    person(string, date);
    person(const person&);

    person& setName(string);
    person& setDOB(date);

    string getName() const;
    date getDOB() const;
    void print() const;

    ~person();
    
};

#endif