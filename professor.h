#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "person.h"
#include "date.h"
#include <string>

class professor : public person {
private:
    int id;
    date empDate;

public:

    professor(std::string name, date dob, int id, date empDate);
    
    int getID() const;
    date getEmpDate() const;
    
    virtual void print(); 
    
    virtual ~professor();
};

#endif