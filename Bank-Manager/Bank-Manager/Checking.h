#pragma once
#include "Account.h"
#include "Transaction.h"

class Checking : public Account
{
public:
	//constructor/destructor
	Checking(){};

	//prototypes
	void monthlyChores(int);

private:
	double monthlyFee;
};

