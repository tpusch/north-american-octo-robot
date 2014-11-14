#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

class Date {
public:
    //constructors/destructor
    Date() {}
    virtual ~Date(){}
    
    //prototypes
    friend istream& operator>>(istream&, Date&);
    friend ostream& operator<<(ostream&, const Date&);
    bool operator<(const Date&) const;
    bool operator==(const Date&) const;
    
    //simple one line accessors
    int getMonth() { return month; }
    int getDay() { return day; }
    int getYear() { return year; }
    char getSeparator1() { return separator1; }
    char getSeparator2() { return separator2; }
    
private:
    int month, day, year;
    char separator1, separator2;
};