#pragma once

#include <iostream>
#include <cstdlib>
#include "Date.h"

using namespace std;

class Transaction {    
public:
    //constructors/destructor
    Transaction() {};
    virtual ~Transaction(){}
    
    //prototypes
    friend istream& operator>>(istream&, Transaction&);
    friend ostream& operator<<(ostream&, const Transaction&);
    bool operator<(const Transaction&) const;
    
    //simple one line accessors
    Date getDate() { return time; }
    char getType() { return type; }
    string getLocation() { return location; }
    double getAmount() { return amount; }

private:
    char type;
    double amount;
    Date time;
    string location;
    int accountID;
    int customerID;
};