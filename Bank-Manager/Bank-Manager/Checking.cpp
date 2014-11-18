#include "Checking.h"

using namespace std;

Checking::Checking()
{
}

void Checking::checkOverdraft(const Transaction& tran)
{
    if (tran.getAmount() > getBalance())
    {
        updateBalance(25);
    }
}