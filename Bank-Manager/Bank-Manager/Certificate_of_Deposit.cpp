#include "Certificate_of_Deposit.h"

using namespace std;

Certificate_of_Deposit::Certificate_of_Deposit()
{
}

void Certificate_of_Deposit::compoundMonthly()
{
    updateBalance(interestRate);
}