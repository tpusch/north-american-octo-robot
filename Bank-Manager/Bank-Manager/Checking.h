#pragma once
#include "Account.h"
#include "Transaction.h"

class Checking : public Account
{
public:
    //constructor/destructor
    Checking(){};
    void operator=(Account&);

    //prototypes
    void monthlyChores(int);

private:
    //Member Variables
    double monthlyFee;
};

