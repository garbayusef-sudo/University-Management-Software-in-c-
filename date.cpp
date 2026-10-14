#include <iostream>
#include "date.h"
#include <iomanip>
using namespace std;

ostream& operator<<(ostream& out, const date& date){
    out << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
    return out;
}
bool operator>(const date& left, const date& right){
    return left.getDate() > right.getDate();
}

date::date(){
    day = 0;
    month = 0;
    year = 0;
}
date::date(int d, int m, int y){
    day = (d >= 1 && d <= 31) ? d : 0;
    month = (m >= 1 && m <= 12) ? m : 0;
    year = (y >= 0 && y <= 2026) ? y : 0;
}

date& date::setDay(int day){
    this->day = (day >= 1 && day <= 31) ? day : 0;
    return *this;
}
date& date::setMonth(int month){
    this->month = (month >= 1 && month <= 12) ? month : 0;
    return *this;
}
date& date::setYear(int year){
    this ->year = (year >= 0 && year <= 2026) ? year : 0;
    return *this;
}

long int date::getDate() const{
    return (year * 10000) + (month * 100) + day; //returns date in format YYYYMMDD
}

int date::getDay() const{ return day;}
int date::getMonth() const {return month;}
int date::getYear() const{ return year;}

void date::printDate() const{
    cout << year << '/' << month << '/' << day;
}