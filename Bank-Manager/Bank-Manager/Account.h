#pragma once
#include <iostream>
#include <cstdlib>
#include "Transaction.h"
#include "Customer.h"
#include "Date.h"
#include <vector>

using namespace std;

class Account {
public:
    //constructors/destructor
    Account(){}
    Account(istream& input){ input >> balance; }
    virtual ~Account(){}

    //prototypes
    void addTransaction(const Transaction&);
    void sortTransactions();
    void generateReport(ostream&);
    
    //simple one line accessors
    vector<Transaction*> getTransactions(){ return transactions; }

private:
    double balance;
    int accountID;
    Date dateOpened;
    vector<Transaction*> transactions;
    vector<Customer*> customers;
};