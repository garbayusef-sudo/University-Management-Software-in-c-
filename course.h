#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;

class course{

private:
    string dept;
    int number;
    string name;

public:
    course();
    course(string, int ,string);
    course(const course&);

    course& setDept(string);
    course& setNum(int);
    course& setName(string);

    string getDept() const;
    int getNum() const;
    string getName() const;

    void print() const;
    ~course();

};


#endif