#include "Transaction.h"

Transaction::Transaction(int id, char t, double a, string loc, Date date){
    accountID = id;
    type = t;
    amount = a;
    location = loc;
    time = date;
}

//overload extraction operator
istream& operator>>(istream& input, Transaction* transaction){
    input >> transaction->accountID >> transaction->type;
    input >> transaction->amount >> transaction->time;
    getline(input, transaction->location);
    return input;
}

//overload insertion operator
ostream& operator<<(ostream& output, const Transaction& transaction){
    output << transaction.time;
    if (transaction.type == 'd' || transaction.type == 'D'){
        output << " Deposit, $" << transaction.amount << " from";
    }
    else if (transaction.type == 'w' || transaction.type == 'W'){
        output << " Withdrawal, $" << transaction.amount << " to";
    }
    else if (transaction.type == 'c' || transaction.type == 'C'){
        output << " Monthly Compound, $" << transaction.amount << " from";
    }
    else if (transaction.type == 'f' || transaction.type == 'F'){
        output << " Monthly Fee, $" << transaction.amount << " to";
    }
    output << transaction.location << ". ";
    return output;
}

//overload less than operator
bool Transaction::operator<(const Transaction& transaction) const
{
    if (time == transaction.time){
        cerr << "time: " << time;
        cerr << "\n transtime: " << transaction.time << endl;
        if (type == 'd' || type == 'D' || type == 'f' || type == 'F'){
            return true;
        }
        else{
            return false;
        }
    }
    return (time < transaction.time);
}

//save to transactions to text file in input format
void Transaction::save(ostream& output){
    output << accountID << " " << type << " " << amount << " " << time << " " << location;
}