#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include "Date.h"

using namespace std;

class Transaction {
public:
    //constructors/destructor
    Transaction(){};
    Transaction(int,char,double,string,Date);
    virtual ~Transaction(){}

    //prototypes
    friend istream& operator>>(istream&, Transaction*);
    friend ostream& operator<<(ostream&, const Transaction&);
    bool operator<(const Transaction&) const;
    void save(ostream&);

    //simple one line accessors
    Date getDate() const { return time; }
    char getType() const { return type; }
    string getLocation() const { return location; }
    double getAmount() const { return amount; }
    int getAccountID() const { return accountID; }

    //simple one line modifiers
    void setDate(const Date& t){ time = t; }
    void setAmount(double a){ amount = a; }
    void setType(char t){ type = t; }
    void setLocation(string l){ location = l; }
    void setAccountID(int a){ accountID = a; }

private:
    //Member variables
    char type;
    double amount;
    Date time;
    string location;
    int accountID;
};

bool compare(Transaction*, Transaction*);