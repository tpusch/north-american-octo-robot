#pragma once
#include "Account.h"
#include "Transaction.h"

class Checking : public Account
{
public:
    //constructor/destructor
    Checking():Account("c"){};
    
    //extraction operator
    friend istream& operator>>(istream&, Checking&);

    void operator=(Account&);

    //prototypes
    void monthlyChores(int);
    void save(ostream&);

private:
    //Member Variables
    double monthlyFee;
};

