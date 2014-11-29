#pragma once
#include "Account.h"

class Certificate_of_Deposit : public Account
{
public:
	//constructor
	Certificate_of_Deposit(){};

	//prototypes
	virtual void monthlyChores(int);

private:
	double interestRate;
	Date maturityDate;
};

