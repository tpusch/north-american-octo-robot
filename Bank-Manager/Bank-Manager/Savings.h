#pragma once
#include "Account.h"

class Savings : public Account
{
public:
    //constructor
    Savings(){};

    //prototypes
    virtual void monthlyChores(int);

private:
    //Member variables
    double interestRate;
};