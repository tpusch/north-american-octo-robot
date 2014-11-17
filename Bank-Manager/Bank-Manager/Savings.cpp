#include "Savings.h"

using namespace std;

Savings::Savings()
{
}


Savings::~Savings()
{
}

void Savings::compoundMonthly()
{
    updateBalance(interestRate);
}