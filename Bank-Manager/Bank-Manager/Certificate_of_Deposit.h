#pragma once
#include "Account.h"

class Certificate_of_Deposit : public Account
{
public:
    //constructor
    Certificate_of_Deposit():Account("cd"){};
    
    friend istream& operator>>(istream&, Certificate_of_Deposit&);

    //prototypes
    virtual void monthlyChores(int);
    virtual void save(ostream&);

private:
    //Member variables
    double interestRate;
    Date maturityDate;
};

