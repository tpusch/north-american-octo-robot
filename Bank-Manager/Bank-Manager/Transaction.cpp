#include "Transaction.h"
#include "Date.h"

//overload extraction operator
istream& operator>>(istream& input, Transaction& transaction)
{
    input >> transaction.customerID >> transaction.accountID >> transaction.type;
    input >> transaction.amount >> transaction.time;
    getline(input, transaction.location);
    return input;
}

//overload insertion operator
ostream& operator<<(ostream& output, const Transaction& transaction)
{
    output << transaction.time;
    if (transaction.type == 'd' || transaction.type == 'D')
    {
        output << " Deposit, $" << transaction.amount << " from";
    }
    else if (transaction.type == 'w' || transaction.type == 'W')
    {
        output << " Withdrawal, $" << transaction.amount << " to";
    }
    output << transaction.location << ". ";
    return output;
}

//overload less than operator
bool Transaction::operator<(const Transaction& transaction) const
{
    if (time == transaction.time)
    {
        if (type == 'd' || type == 'D')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return (time < transaction.time);
}