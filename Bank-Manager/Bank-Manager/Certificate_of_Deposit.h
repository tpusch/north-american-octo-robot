#pragma once
#include "Account.h"
#include "Date.h"

class Certificate_of_Deposit : public Account
{
public:
    //constructor
    Certificate_of_Deposit();
    
    //prototypes
    void compoundMonthly();

private:
    double interestRate;
    Date maturityDate;
};

