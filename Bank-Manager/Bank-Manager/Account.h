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
	void addTransaction(Transaction);
	void sortTransactions();
	void generateReport(ostream&);
	void save(ostream&);
	virtual void monthlyChores(int){};

	//simple one line accessors
	vector<Transaction> getTransactions(){ return transactions; }
	vector<Customer*> getCustomers(){ return customers; }
	double getBalance(){ return balance; }
	void updateBalance(double rate){ balance += balance * rate; }
	Date getDate(){	return dateOpened;}
	int getID(){ return accountID; }

protected:
	double balance;
	int accountID;
	Date dateOpened;
	string type;
	vector<Transaction> transactions;
	vector<Customer*> customers;
	};