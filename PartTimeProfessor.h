#ifndef PARTTIMEPROFESSOR_H
#define PARTTIMEPROFESSOR_H

#include "professor.h"
#include "date.h"
#include <string>

class PartTimeProfessor : public professor {
public:

    PartTimeProfessor(std::string name, date dob, int id, date empDate);
    void print(); 
    ~PartTimeProfessor();
};

#endif