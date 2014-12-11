#pragma once
#include "Account.h"

class Certificate_of_Deposit : public Account
{
public:
    //constructor
    Certificate_of_Deposit():Account("cd"){ interestRate = 0.08; }
    
    //overloads
    friend istream& operator>>(istream&, Certificate_of_Deposit&);
    
    //setter
    void setMaturityDate(Date d){ maturityDate = d; }

    //prototypes
    virtual void monthlyChores(int);
    virtual void save(ostream&);

private:
    //Member variables
    double interestRate;
    Date maturityDate;
};

