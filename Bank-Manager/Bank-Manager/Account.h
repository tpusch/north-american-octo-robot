#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Date.h"
#include "Customer.h"
#include "Transaction.h"

using namespace std;

class Account {
public:
    //constructors
    Account(){}
    Account(string t):type(t){};
//    Account(istream& input){ input >> balance; }
    //destructor for all account types
    virtual ~Account(){}

    //prototypes
    friend istream& operator>>(istream&, Account&);
    friend ostream& operator<<(ostream&, const Account&);
    void addTransaction(Transaction*);
    void addCustomer(Customer*);
    void sortTransactions();
    void generateReport(ostream&);
    void generateMonthlyReport(ostream&, int, int);
    double getValue();
    double updateBalance(Transaction*, double);

    //virtual methods
    virtual void monthlyChores(int) = 0;
    virtual void save(ostream&) = 0;

    //simple one line accessors
    vector<Transaction*> getTransactions(){ return transactions; }
    vector<Customer*> getCustomers(){ return customers; }
    Date getDate(){ return dateOpened; }
    int getID(){ return accountID; }
    string getType(){ return type; }
    double getBalance(){ return balance; }

protected:
    //Member variables
    double balance;

	double openingBalance;
	double currentBalance;

    int accountID;
    Date dateOpened;
    string type;
    vector<Transaction*> transactions;
    vector<Customer*> customers;
};