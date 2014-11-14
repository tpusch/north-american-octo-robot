#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Account.h"

using std::list;
using std::string;

class Customer
{
public:
	Customer();
	~Customer();

	int getID(){ return customerID; }
	void setID(const int);

	string getFirstName(){ return firstName; }
	void setFirstName(const string&);

	string getLastName(){ return lastName; }
	void setLastName(const string&);

	string getAddress(){ return address; }
	void setAddress(const string&);

	string getSSN(){ return ssn; }
	void setSSN(const string&);

	void printName(std::ostream&);

	//returns a pointer to a list of account pointers
//	list<Account*>* getAccounts(){ return accountsPtr; }

	//TODO: overload >> and <<

private:
	int customerID;

	string firstName;
	string lastName;

	string address;
	string ssn;

	//A list of pointers, pointing to accounts
//	list<Account*> accounts;
//	//A pointer pointing to a list of account pointers
//	list<Account*>* accountsPtr;
};

