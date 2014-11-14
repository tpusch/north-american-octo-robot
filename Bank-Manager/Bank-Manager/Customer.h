#pragma once
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "Account.h"

using std::list;
using std::string;

class Customer
{
	
public:
	Customer();
	Customer(string);
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

	void listAccounts();
	
	void printCheckingValue();
	void printSavingsValue();
	void printCDValue();

	//returns a pointer to a list of account pointers
//	list<Account*>* getAccounts(){ return accountsPtr; }

	//TODO: overload >> and <<
	friend std::ostream& operator<< (std::ostream&, const Customer&);
	friend std::istream& operator>> (std::istream&, Customer&);


protected:
	int customerID;

	string firstName;
	string lastName;

	string address;
	string ssn;

	//A list of pointers, pointing to accounts
	list<Account*> accounts;
	//A pointer pointing to a list of account pointers
	//This is a single pointer
	list<Account*>* accountsPtr;
};

