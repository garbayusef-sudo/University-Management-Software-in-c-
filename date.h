#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class date{

    private:
        int day;
        int month;
        int year;
    public:
        date();
        date(int, int, int);
        date& setDay(int);
        date& setMonth(int);
        date& setYear(int);

        long int getDate() const;
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        
        void printDate() const;
};

#endif