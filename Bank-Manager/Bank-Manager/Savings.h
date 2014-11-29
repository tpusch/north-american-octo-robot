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
	double interestRate;
};

