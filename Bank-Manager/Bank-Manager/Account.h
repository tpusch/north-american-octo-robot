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
	//constructors/destructor
	Account(){}
	Account(istream& input){ input >> balance; }
	virtual ~Account(){}

	//prototypes
	friend istream& operator>>(istream&, Account&);
        friend ostream& operator<<(ostream&, const Account&);
	void addTransaction(Transaction);
	void sortTransactions();
	void generateReport(ostream&);
        void generateMonthlyReport(ostream&, int, int);
	void save(ostream&);
        double getValue();
        double updateBalance(Transaction&, double);
        
        //virtual methods
        virtual void monthlyChores(int){cerr << "this one" << endl;};
        
	//simple one line accessors
	vector<Transaction> getTransactions(){ return transactions; }
	vector<Customer*> getCustomers(){ return customers; }
	Date getDate(){	return dateOpened;}
	int getID(){ return accountID; }
        string getType(){ return type; }
        double getBalance(){ return balance; }

protected:
	double balance;
	int accountID;
	Date dateOpened;
	string type;
	vector<Transaction> transactions;
	vector<Customer*> customers;
	};