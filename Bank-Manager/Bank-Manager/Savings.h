#pragma once
#include "Account.h"

class Savings : public Account
{
public:
    //constructor/destructor
    Savings();
    ~Savings();
    
    //prototypes
    void compoundMonthly();
        
private:
    double interestRate;
};

