#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Date.h"
#include "Customer.h"
#include "Transaction.h"

using namespace std;

class Account {
public:
    //constructors/destructor
    Account(){}
    Account(istream& input){ input >> balance; }
    virtual ~Account(){}

    //prototypes
    void addTransaction(const Transaction*);
    void sortTransactions();
    void generateReport(ostream&);
    
	void save(ostream&);

    //simple one line accessors
    vector<const Transaction*> getTransactions(){ return transactions; }
    vector<Customer*> getCustomers(){ return customers; }
    double getBalance(){ return balance; }
    void updateBalance(double rate){ balance += balance * rate; }

private:
    double balance;
    int accountID;
    Date dateOpened;
    vector<const Transaction*> transactions;
    vector<Customer*> customers;
};