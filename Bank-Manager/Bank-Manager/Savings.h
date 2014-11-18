#pragma once
#include "Account.h"

class Savings : public Account
{
public:
    //constructor
    Savings();
    
    //prototypes
    void compoundMonthly();
        
private:
    double interestRate;
};

