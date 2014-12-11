#pragma once
#include "Account.h"

class Savings : public Account
{
public:
    //constructor
    Savings():Account("s"){ interestRate = 0.04; }
    
    friend istream& operator>>(istream&, Savings&);
    
    //prototypes
    virtual void monthlyChores(int);
    virtual void save(ostream&);

private:
    //Member variables
    double interestRate;
};