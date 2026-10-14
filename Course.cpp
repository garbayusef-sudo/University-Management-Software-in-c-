#include "course.h"
#include <iostream>
using namespace std;

course::course(){
    dept = " "; number = 0; name = " ";
}
course::course(string d, int n, string N){
    dept = d; number = n; name = N;
}
course::course(const course& c){
    dept = c.dept; number = c.number; name = c.name;
}

course& course::setDept(string dept){ this->dept = dept; return *this;}
course& course::setNum(int number){ this->number = number; return *this;}
course& course::setName(string name){ this->name = name; return *this;}

string course::getDept() const{ return dept;}
int course::getNum() const{ return number;}
string course::getName() const{return name;}

void course::print() const{
    cout << dept << " " << number << " : " << name;
}

course::~course(){
    cout << "Course \"";
    print(); cout << "\" is no longer in the system" << endl;
}