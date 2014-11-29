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
	void save(ostream&);

	//simple one line accessors
	Date getDate() const { return time; }
	char getType() const { return type; }
	string getLocation() const { return location; }
	double getAmount() const { return amount; }

	//simple one line modifiers
	void setDate(const Date& t){ time = t; }
	void setAmount(int a){ amount = a; }
	void setType(char t){ type = t; }
	void setLocation(string l){ location = l; }
	void setAccountID(int a){ accountID = a; }

private:
	char type;
	double amount;
	Date time;
	string location;
	int accountID;
};