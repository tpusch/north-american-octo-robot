#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
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
    Date getDate() const { return time; }
    char getType() const { return type; }
    string getLocation() const { return location; }
    double getAmount() const { return amount; }

private:
    char type;
    double amount;
    Date time;
    string location;
    int accountID;
    int customerID;
};